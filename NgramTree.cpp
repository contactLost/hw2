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
    if( ngram.length() == 4) // If given number is a ngram
        searchTree->searchTreeInsert(ngram);
    else {                  //If not ngram 

        if (ngram.length() >= Ngram) { //check the word length for ngram

            for (int i = 0; i + Ngram <= ngram.length(); i++) //Divide words into n char strings
            {
                addNgram(ngram.substr(i, Ngram));
            }
        }

    }
}

int NgramTree::getTotalNgramCount()
{
    return searchTree->postOrderNgram();
}
//Todo
bool NgramTree::isComplete()
{
	return false;
}
//Todo
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
