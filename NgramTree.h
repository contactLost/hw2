#pragma once
/**
* Title: Trees
* Author: Tuna Dalbeler
* ID: 21802539
* Assignment: 2
* Description: Header file for NgramTree.
*/
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "BinarySearchTree.h"
using namespace std;
class NgramTree {
public:
	NgramTree();
	~NgramTree();
	void addNgram(string ngram);
	int getTotalNgramCount();
	bool isComplete();
	bool isFull();
	void generateTree(string fileName, int n);
private:

	int Ngram = 0;
	BinarySearchTree* searchTree;
	friend ostream& operator <<(ostream& out, const NgramTree& tree);
};
