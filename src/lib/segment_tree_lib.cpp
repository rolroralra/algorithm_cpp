//
// Created by Shinyoung Kim on 2021/06/28.
//

class SegmentTree {
private:
    int* tree;
    int originalDataSize;
    int baseIndex;
    int treeSize;
    static const int ROOT_INDEX = 0;

    bool checkBaseIndex(int index) {
        return index >= 0 && index < originalDataSize;
    }
    void refresh(int node) {
        if (node >= baseIndex) {
            return;
        }

        int leftNode = node * 2 + 1;
        int rightNode = leftNode + 1;
        tree[node] = min(tree[leftNode], tree[rightNode]);
    }
public:
    SegmentTree(int *arr, int size) : SegmentTree(size) {
        for (int i = 0; i < size; i++) {
            update(i, arr[i]);
        }
    }

    SegmentTree(int size) : originalDataSize(size) {
        for (baseIndex = 1; baseIndex < N; baseIndex<<=1);
        treeSize = baseIndex * 2 - 1;
        baseIndex--;

        tree = (int*) calloc(treeSize, sizeof(int));
    }

    void update(int index, int value) {
        if (!checkBaseIndex(index))
            return;

        int node = baseIndex + index;

        tree[node] = value;

        while (node > ROOT_INDEX) {
            node = (node - 1) / 2;
            refresh(node);
        }
    }

    int query(int left, int right) {
        if (!checkBaseIndex(left) || !checkBaseIndex(right)) {
            return INT32_MAX;
        }

        int leftNode = baseIndex + left;
        int rightNode = baseIndex + right;

        int result = INT32_MAX;
        while(leftNode < rightNode) {
            if (leftNode % 2 == 0) {
                result = min(result, tree[leftNode++]);
            }

            if (rightNode % 2 == 1) {
                result = min(result, tree[rightNode--]);
            }

            leftNode = (leftNode - 1) / 2;
            rightNode = (rightNode - 1) / 2;
        }

        if (leftNode == rightNode) {
            result = min(result, tree[leftNode]);
        }

        return result;
    }
};
