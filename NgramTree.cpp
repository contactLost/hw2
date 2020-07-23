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
    searchTree->searchTreeInsert(ngram);
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

    //do the work here n-character proccesser here or in addNgram ?
    while (theFile >> str) {

        if (str.length() >= n) {

            for (int i = 0; i + n <= str.length(); i++)
            {
                addNgram(str.substr(i, n));
            }
        }
    }

    theFile.close();
}

ostream& operator<<(ostream& out, const NgramTree& tree)
{
    tree.searchTree->postOrder();


    return out;
}
