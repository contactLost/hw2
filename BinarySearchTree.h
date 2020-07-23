/**
* Title: Trees
* Author: Tuna Dalbeler
* ID: 21802539
* Assignment: 2
* Description: A binary search tree implementation first written by Aynur Dayanýk.
* Modified and made additions to work with NgramTree classes by Tuna Dalbeler.
*/


#pragma once
#ifndef _BINARY_TREE_INTERFACE
#define _BINARY_TREE_INTERFACE
#include <iostream>
#include <string>
using namespace std;
typedef string ItemType;


class TreeNode {
private:
    TreeNode() { left = NULL; right = NULL; ngramCount = 1; };
    TreeNode(const ItemType nodeItem, TreeNode* leftPtr = NULL, TreeNode*rightPtr = NULL) : item(nodeItem), left(leftPtr), right(rightPtr), ngramCount(1) {};
    ItemType item;  //  key
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
    //void searchTreeDelete(const ItemType item);
    //bool searchTreeRetrieve(const ItemType item);

    void printSideways() const;
    void postOrder() const;
    int postOrderNgram();
    void printTreeInfo();
    bool isFull();
    bool isComplete();

    void countNodes(TreeNode* rootPtr, int& nodeCount);

private:
    TreeNode* root;
    int nodeCount;//Used by countNodes
    void copyTree(TreeNode* rootPtr, TreeNode*& newRootPtr) const;
    void destroyTree(TreeNode* rootPtr);
    ostream& printHelper(ostream&, TreeNode*) const;
    ostream& print(ostream& out) const;

    void printSidewaysHelper(TreeNode* rootPtr, string indent) const;

    void postOrderHelper(TreeNode* rootPtr) const;

    void postOrderNgramHelper(TreeNode* rootPtr, int& ngramCount) const;

    void searchTreeInsert(TreeNode*& rootPtr, const ItemType newItem);

    bool isCompleteHelper(TreeNode* node, int index);

    void printTreeInfoHelper(TreeNode* rootPtr);

    bool isFullHelper(TreeNode* rootPtr);

    friend ostream& operator<<(ostream&, const BinarySearchTree&);

};


#endif