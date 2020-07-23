#include "NgramTree.h"

NgramTree::NgramTree()
{
    searchTree = new BinarySearchTree();
}

NgramTree::~NgramTree()
{
    delete searchTree;
}

void NgramTree::addNgram(string ngram)
{
    cout << "Add ngram: " << ngram << endl;

}

int NgramTree::getTotalNgramCount()
{
	return 0;
}

bool NgramTree::isComplete()
{
	return false;
}

bool NgramTree::isFull()
{
	return false;
}

void NgramTree::generateTree(string fileName, int n)
{
	Ngram = n;
    ifstream theFile;
    string str;
    theFile.open(fileName);

    if (!theFile) {
        cout << "Unable to open file";
        exit(1);
    }

    //do the work here
    while (theFile >> str) {
        addNgram(str);
    }

    theFile.close();
}
