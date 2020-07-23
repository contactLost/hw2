#include "NgramTree.h"

NgramTree::NgramTree()
{
    searchTree = new BinarySearchTree();
}

NgramTree::~NgramTree()
{
    delete searchTree;
}

//Adds ngram to the tree
void NgramTree::addNgram(string ngram)
{
    if( ngram.length() == Ngram) // If given number is a ngram
        searchTree->searchTreeInsert(ngram);
    else {                  //If not ngram  //Redundent check but whatever

        if (ngram.length() >= Ngram) { //check the word length for ngram

            for (int i = 0; i + Ngram <= ngram.length(); i++) //Divide words into n char strings
            {
                addNgram(ngram.substr(i, Ngram));
            }
        }

    }
}

//Counts total ngrams
int NgramTree::getTotalNgramCount()
{
    return searchTree->postOrderNgram();
}

//computes and returns whether or not the current tree is a complete tree
// complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible. 
bool NgramTree::isComplete()
{
    return searchTree->isComplete();
}

//A full binary tree (sometimes proper binary tree or 2-tree) is a tree in which every node other than the leaves has two children. 
bool NgramTree::isFull()
{
    return searchTree->isFull();
}

//Generates a binary search tree and fills it with the content of the file.
void NgramTree::generateTree(string fileName, int n)
{
	Ngram = n;
    ifstream theFile;
    string str;
    theFile.open(fileName);
    
    //Abort program if unable to open file
    if (!theFile) {
        cout << "Unable to open file";
        exit(1);
    }

    //Take word from file and change it to ngram
    while (theFile >> str) {

        if (str.length() >= n) { //check the word length for ngram

            for (int i = 0; i + n <= str.length(); i++) //Divide words into n char strings
            {
                addNgram(str.substr(i, n));
            }
        }
    }

    theFile.close();
}

ostream& operator<<(ostream& out, const NgramTree& tree)
{
    tree.searchTree->printTreeInfo();

    return out;
}
