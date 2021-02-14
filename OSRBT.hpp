//
//  order-static-red-black-tree.hpp
//  gjg
//
//  Created by Okan Sarp Kaya on 10.02.2021.
//

#ifndef OBST
#define OBST


#include <iostream>
#include <string>

class Node{
public:
    bool isRed;
    int key, size;
    int ordinal;
    std::string nation;
    std::string name;
    Node *parent;
    Node *left;
    Node *right;
    Node(int key, int ordinal, std::string nat, std::string name) {
        this->key = key;
        this->ordinal = ordinal;
        this->nation = nat;
        this->name = name;
        this->size = 1;
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
        this->isRed = false;
    }
};



class RBTree{
public:
    Node *root;
    // Necessary nodes for delete fix(So we have no memory leak)
    Node *replacingNode;
    Node *siblingNode;
    void RotateLeft(Node *node);
    void RotateRight(Node *node);
    Node* Insert(Node *node);
    void InsertFix(Node *node);
    void Transplant(Node *oldNode, Node *newNode);
    void Delete(Node *node);
    void DeleteFix(Node *node, bool rep);
    void InOrderWalk(Node *node);
    Node *Select(Node *begin, int i);
    Node* TreeMinimum(Node *begin);
    RBTree();
};

#endif /* order_static_red_black_tree_hpp */
