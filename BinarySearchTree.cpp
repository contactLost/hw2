#include "BinarySearchTree.h"
typedef string ItemType;
/**
 * A partial implementation of Binary Search Tree ADT from the L3 slides with additional
 * private recursive helper functions & operator overloading.
 *
 * Exercises - TODO
 *
 * @author Aynur
 * @date July 14, 2020
 */

#include <iostream>
using namespace std;

#include "BinarySearchTree.h"

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
    // TODO
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

// private helper function  --- inorder traversal (prints in sorted order)
ostream& BinarySearchTree::printHelper(ostream& out, TreeNode* rootPtr) const {
    
    if (rootPtr != NULL) {
        printHelper(out, rootPtr->left);
        out << rootPtr->item << endl;
        printHelper(out, rootPtr->right);
    }
    return out;
}

ostream& operator<<(ostream& out, const BinarySearchTree& tree) {
    // TODO
    return tree.print(out);

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



/* prints the tree rooted at rootPtr in a sideway indented format,
   with right nodes above left nodes, with each level 4 spaces indented than
   the one above it

   Example

           4
      /  \
        1     7
         \   /  \
         3  6   8
        /
       2

output for this tree would be

        8
    7
        6
4
        3
            2
    1
*/

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
