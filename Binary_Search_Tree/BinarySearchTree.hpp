//
//  BinarySearchTree.hpp
//  C++
//
//  Created by 李天培 on 16/5/10.
//  Copyright © 2016年 lee. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <vector>
#include <queue>

class BinarySearchTree {
public:
    struct Node {
        int val;
        Node* left;
        Node* right;
        Node(int v, Node* l = NULL, Node* r = NULL):
        val(v), left(l), right(r) {
        }
    };

    BinarySearchTree();
    BinarySearchTree(const std::vector<int>&);
    ~BinarySearchTree();

    bool insertNode(int);
    bool searchNode(int);
    bool deleteNode(int);
    void clear();

    Node* getRoot() const;

private:
    Node* root;
};

#endif /* BinarySearchTree_hpp */

