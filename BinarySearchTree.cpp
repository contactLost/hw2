
/**
* Title: Trees
* Author: Tuna Dalbeler
* ID: 21802539
* Assignment: 2
* Description: A binary search tree implementation primaryly written by Aynur Dayanýk.
* Modified and made additions to work with NgramTree classes by Tuna Dalbeler.
*/

#include <iostream>
#include "BinarySearchTree.h"

typedef string ItemType;
using namespace std;

// coonstructors,
BinarySearchTree::BinarySearchTree() {
    // TODO
    root = NULL;
}

BinarySearchTree::BinarySearchTree(const ItemType rootItem) {
    // TODO
    root = new TreeNode(rootItem);
}

// by attaching given left and right subtrees
BinarySearchTree::BinarySearchTree(const ItemType rootItem, const BinarySearchTree& leftTree, const BinarySearchTree& rightTree) {
    // TODO
    root = new TreeNode(rootItem, leftTree.root, rightTree.root);
}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree& other) {
    cout << "in copy constructor..." << endl;
    // TODO
    copyTree(other.root, root);
}

// private helper to copy a tree recursively
void BinarySearchTree::copyTree(TreeNode* rootPtr, TreeNode*& newRootPtr) const {
    if (rootPtr != NULL) {
        newRootPtr = new TreeNode(rootPtr->item, NULL, NULL);
        copyTree(rootPtr->left, newRootPtr->left);
        copyTree(rootPtr->right, newRootPtr->right);
    }
}

// destructor
BinarySearchTree::~BinarySearchTree() {
    cout << "in destructor..." << endl;
    destroyTree(root);
}

// private helper to destroy a tree recursively
void BinarySearchTree::destroyTree(TreeNode* rootPtr) {
 
    if (rootPtr != NULL) {
        destroyTree(rootPtr->left);
        destroyTree(rootPtr->right);
        delete rootPtr;
    }
}

// private
ostream& BinarySearchTree::print(ostream& out) const {
    
    return printHelper(out, root);
}

void BinarySearchTree::searchTreeInsert(const ItemType newItem) {
    // TODO
    searchTreeInsert(root, newItem);
}

// private recursive helper
void BinarySearchTree::searchTreeInsert(TreeNode*& rootPtr, const ItemType newItem) {
    // TODO
    if (rootPtr == NULL)  // empty tree
        rootPtr = new TreeNode(newItem, NULL, NULL);
    else if ((rootPtr->item).compare(newItem) == 0)
        rootPtr->ngramCount++;
    else if ((rootPtr->item).compare( newItem) == -1)
        searchTreeInsert(rootPtr->right, newItem);
    else if ((rootPtr->item).compare(newItem) == 1)
        searchTreeInsert(rootPtr->left, newItem);
    // else   rootPtr->item == newItem
    // 	   it is duplicate, don't add it
}

void BinarySearchTree::printSideways() const {
    // TODO
    printSidewaysHelper(root, "");
}

void BinarySearchTree::printSidewaysHelper(TreeNode* rootPtr, string indent) const {
    // TODO
    // right subtree, then root data, then left subtree
    if (rootPtr != NULL) {
        printSidewaysHelper(rootPtr->right, indent + "    ");
        cout << indent << rootPtr->item << endl;
        printSidewaysHelper(rootPtr->left, indent + "    ");
    }

}

void BinarySearchTree::postOrder() const {
    postOrderHelper(root);
}

// private helper function  --- postorder traversal 
void BinarySearchTree::postOrderHelper(TreeNode* rootPtr) const {
    // TODO
    if (rootPtr != NULL) {
        postOrderHelper(rootPtr->left);
        postOrderHelper(rootPtr->right);
        cout << rootPtr->item << ", ";
    }
}

// counts all ngram amount in post order
int BinarySearchTree::postOrderNgram()
{
    int ngramCount = 0;
    postOrderNgramHelper(root, ngramCount);
    return ngramCount;
}

// private helper function  --- postorder traversal for ngram counting
void BinarySearchTree::postOrderNgramHelper(TreeNode* rootPtr, int& ngramCount) const {

    if (rootPtr != NULL) {
        postOrderNgramHelper(rootPtr->left, ngramCount);
        postOrderNgramHelper(rootPtr->right, ngramCount);
        ngramCount++;
    }
}

//Prints all keys and ngram counts in the tree
void BinarySearchTree::printTreeInfo()
{
    printTreeInfoHelper(root);
}

//Recursive private helper function for print tree info
void BinarySearchTree::printTreeInfoHelper(TreeNode* rootPtr)
{
    if (rootPtr != NULL) {
        cout << "\"" << rootPtr->item << "\" appears " << rootPtr->ngramCount << " time(s)" << endl;
        printTreeInfoHelper(rootPtr->left );
        printTreeInfoHelper(rootPtr->right );
    }
}

ostream& operator<<(ostream& out, const BinarySearchTree& tree) {
    // TODO
    return tree.print(out);

}

// private helper function  --- inorder traversal (prints in sorted order)
ostream& BinarySearchTree::printHelper(ostream& out, TreeNode* rootPtr) const {

    if (rootPtr != NULL) {
        printHelper(out, rootPtr->left);
        out << rootPtr->item << endl;
        printHelper(out, rootPtr->right);
    }
    return out;
}