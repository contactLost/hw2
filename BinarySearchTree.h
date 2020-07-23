#pragma once
#ifndef _BINARY_TREE_INTERFACE
#define _BINARY_TREE_INTERFACE
#include <iostream>
#include <string>
using namespace std;
typedef string ItemType;

/**
 * Binary Search Tree ADT from the L3 slides with additional
 * private recursive helper functions & operator overloading.
 *
 * @author Aynur
 * @date July 14, 2020
 */

class TreeNode {
private:
    TreeNode() { left = NULL; right = NULL; };
    TreeNode(const ItemType nodeItem, TreeNode* leftPtr = NULL, TreeNode*rightPtr = NULL) : item(nodeItem), left(leftPtr), right(rightPtr), ngramCount(0) {};
    ItemType item;  //  key is the int data itself
    TreeNode* left;
    TreeNode* right;
    int ngramCount;
    friend class BinarySearchTree;
};

class BinarySearchTree {
public:
    BinarySearchTree();
    BinarySearchTree(const ItemType data);
    BinarySearchTree(const ItemType data, const BinarySearchTree&, const BinarySearchTree&);
    BinarySearchTree(const BinarySearchTree&);
    ~BinarySearchTree();

    // public member functions
    void searchTreeInsert(const ItemType newItem);
    void searchTreeDelete(const ItemType item);
    bool searchTreeRetrieve(const ItemType item);

    void printSideways() const;
    void postOrder() const;

private:
    TreeNode* root;
    // TODO -- add private helper funcitons
    void copyTree(TreeNode* rootPtr, TreeNode*& newRootPtr) const;
    void destroyTree(TreeNode* rootPtr);
    ostream& printHelper(ostream&, TreeNode*) const;
    ostream& print(ostream& out) const;

    void printSidewaysHelper(TreeNode* rootPtr, string indent) const;

    void postOrderHelper(TreeNode* rootPtr) const;

    void searchTreeInsert(TreeNode*& rootPtr, const int newItem);

    // TODO -- overload << operator
    friend ostream& operator<<(ostream&, const BinarySearchTree&);
};


#endif