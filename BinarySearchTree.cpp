
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

// constructors
BinarySearchTree::BinarySearchTree() {
    nodeCount = 0;
    root = NULL;
}

BinarySearchTree::BinarySearchTree(const ItemType rootItem) {
    nodeCount = 0;
    root = new TreeNode(rootItem);
}

// by attaching given left and right subtrees
BinarySearchTree::BinarySearchTree(const ItemType rootItem, const BinarySearchTree& leftTree, const BinarySearchTree& rightTree) {
    nodeCount = 0;
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


void BinarySearchTree::searchTreeInsert(const ItemType newItem) {
    // TODO
    searchTreeInsert(root, newItem);
}

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


//Deprecated - do not use 
void BinarySearchTree::printSideways() const {
    // TODO
    printSidewaysHelper(root, "");
}
//Deprecated - do not use 
void BinarySearchTree::printSidewaysHelper(TreeNode* rootPtr, string indent) const {
    // TODO
    // right subtree, then root data, then left subtree
    if (rootPtr != NULL) {
        printSidewaysHelper(rootPtr->right, indent + "    ");
        cout << indent << rootPtr->item << endl;
        printSidewaysHelper(rootPtr->left, indent + "    ");
    }

}

//********************************print tree (inorder)*************************************

//This operator will not be used by end user. For debug purposes. Real << overload is in the NgramTree clas
ostream& operator<<(ostream& out, const BinarySearchTree& tree) {

    return tree.print(out);
}

ostream& BinarySearchTree::print(ostream& out) const {

    return printHelper(out, root);
}

ostream& BinarySearchTree::printHelper(ostream& out, TreeNode* rootPtr) const {

    if (rootPtr != NULL) {
        printHelper(out, rootPtr->left);
        out << rootPtr->item << endl;
        printHelper(out, rootPtr->right);
    }
    return out;
}

//********************************print tree (post order)*************************************

void BinarySearchTree::postOrder() const {
    postOrderHelper(root);
}

void BinarySearchTree::postOrderHelper(TreeNode* rootPtr) const {
    // TODO
    if (rootPtr != NULL) {
        postOrderHelper(rootPtr->left);
        postOrderHelper(rootPtr->right);
        cout << rootPtr->item << ", ";
    }
}

//**********************print tree (assignment - inorder - alphabetical)*************************

//Prints all keys and ngram counts in the tree
void BinarySearchTree::printTreeInfo()
{
    printTreeInfoHelper(root);
}

//Recursive private helper function for print tree info
void BinarySearchTree::printTreeInfoHelper(TreeNode* rootPtr)
{
    if (rootPtr != NULL) {
        
        printTreeInfoHelper(rootPtr->left );
        cout << "\"" << rootPtr->item << "\" appears " << rootPtr->ngramCount << " time(s)" << endl;
        printTreeInfoHelper(rootPtr->right );
    }
}

//********************************get total ngram count***********************************

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

//********************************is full***********************************

//Finds if the tree is a full tree or not
bool BinarySearchTree::isFull()
{
    return isFullHelper(root);
}

//Recursive private helper function
bool BinarySearchTree::isFullHelper(TreeNode* rootPtr)
{
    if ((rootPtr->left == NULL) && (rootPtr->right == NULL)) { //Is a leaf?
        return true;
    }
    else if ((rootPtr->left == NULL) xor (rootPtr->right == NULL)) //One of them is filled and other is not
    {
        return false;
    }
    else //Has both left and right children
    {
        return isFullHelper(rootPtr->left) && isFullHelper(rootPtr->right);
    }
}

//********************************is complete***********************************

//Checks if the tree is a complete tree
bool BinarySearchTree::isComplete()
{
    countNodes(root, nodeCount);
    return isCompleteHelper(root, 0);
}

//Recursive method for isComplete
bool BinarySearchTree::isCompleteHelper(TreeNode* node, int index) 
{
    if (node == NULL)
        return true;

    else if (index >= nodeCount)
        return false;

    else 
        return (isCompleteHelper(node->left, 2 * index + 1) && isCompleteHelper(node->right, 2 * index + 2));
}

//Counts all the nodes is the tree
void BinarySearchTree::countNodes(TreeNode* rootPtr, int& nodeCount) {
  
    if (rootPtr != NULL) {
        countNodes(rootPtr->left, nodeCount);
        countNodes(rootPtr->right, nodeCount);
        nodeCount++;
    }
}


