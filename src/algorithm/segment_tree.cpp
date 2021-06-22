//
// Created by Shinyoung Kim on 2021/06/23.
//

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100000
int N, M;
int arr[MAX_N];
int tree[2][MAX_N * 4];
int treeSize;

class SegmentTree {
    int *tree[3];
    int treeSize;
    int originalDataSize;

public:
    void update(int index, int value) {
        update(index, value, 0, 0, originalDataSize - 1);
    }

    int queryMax(int left, int right) {
        return queryMax(left, right, 0, 0, originalDataSize - 1);
    }

    int queryMin(int left, int right) {
        return queryMin(left, right, 0, 0, originalDataSize - 1);
    }

    int querySum(int left, int right) {
        return querySum(left, right, 0, 0, originalDataSize - 1);
    }

    SegmentTree(int size) : originalDataSize(size){
        for (treeSize = 1; treeSize < size; treeSize <<= 1);
        treeSize = treeSize * 2 - 1;

        tree[0] = (int*) calloc(treeSize, sizeof(int));
        tree[1] = (int*) calloc(treeSize, sizeof(int));
        tree[2] = (int*) calloc(treeSize, sizeof(int));

    }

private:
    void update(int index, int value, int node, int nodeLeft, int nodeRight) {
        if (index < nodeLeft || nodeRight < index) {
            return;
        }

        if (nodeLeft == nodeRight) {
            tree[0][node] = value;
            tree[1][node] = value;
            tree[2][node] = value;
            return;
        }

        int leftNode = node * 2 + 1;
        int rightNode = leftNode + 1;
        int nodeMid = (nodeLeft + nodeRight) / 2;

        update(index, value, leftNode, nodeLeft, nodeMid);
        update(index, value, rightNode, nodeMid + 1, nodeRight);

        tree[0][node] = max(tree[0][leftNode], tree[0][rightNode]);
        tree[1][node] = min(tree[1][leftNode], tree[1][rightNode]);
        tree[2][node] = tree[2][leftNode] + tree[2][rightNode];
    }

    int queryMax(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (right < nodeLeft || nodeRight < left) {
            return INT32_MIN;
        }

        if (left <= nodeLeft && nodeRight <= right) {
            return tree[0][node];
        }

        int leftNode = node * 2 + 1;
        int rightNode = leftNode + 1;
        int nodeMid = (nodeLeft + nodeRight) / 2;

        return max(queryMax(left, right, leftNode, nodeLeft, nodeMid), queryMax(left, right, rightNode, nodeMid + 1, nodeRight));
    }

    int queryMin(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (right < nodeLeft || nodeRight < left) {
            return INT32_MAX;
        }

        if (left <= nodeLeft && nodeRight <= right) {
            return tree[1][node];
        }

        int leftNode = node * 2 + 1;
        int rightNode = leftNode + 1;
        int nodeMid = (nodeLeft + nodeRight) / 2;

        return min(queryMin(left, right, leftNode, nodeLeft, nodeMid), queryMin(left, right, rightNode, nodeMid + 1, nodeRight));
    }

    int querySum(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (right < nodeLeft || nodeRight < left) {
            return 0;
        }

        if (left <= nodeLeft && nodeRight <= right) {
            return tree[2][node];
        }

        int leftNode = node * 2 + 1;
        int rightNode = leftNode + 1;
        int nodeMid = (nodeLeft + nodeRight) / 2;

        return querySum(left, right, leftNode, nodeLeft, nodeMid) + querySum(left, right, rightNode, nodeMid + 1, nodeRight);
    }
};