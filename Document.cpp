#include <iostream>
#include <fstream>
#include <cmath>
#include <mutex>
#include "Document.h"

//a mutex variable to lock std::cin
mutex g_cin_lock;

Document::Document()
{
	fullPath = "";
	nSumOfSquares = 0;
}

Document::~Document()
{
	fullPath = "";
	nSumOfSquares = 0;
	frequencyMap.clear();
}

/*
void Document::operator()()
{
	inputPath();
	countFrequency();
	calculateSumOfSquares();
}
*/

void Document::inputPath()
{
	g_cin_lock.lock();
	string path;
	cout << "Fullpath of the first document: ";
	cin >> path;
	cout << endl;
	fullPath = path;
	g_cin_lock.unlock();
}

void Document::countFrequency()
{
	ifstream doc;
	string word;
	doc.open(fullPath, ios::in);

	if (doc.fail()) {
		cout << "Cannot open file " << fullPath << endl;
		cout << "Please check the path again, or make sure that the path does not contain quotation marks" << endl;
		exit(404);
	}

	while (doc >> word) {
		//if the word does not exist in unordered_map, create new key
		if (frequencyMap.find(word) == frequencyMap.end()) {
			frequencyMap[word] = 1;
		}
		//if it exist, increase frequency by 1
		else {
			frequencyMap[word]++;
		}
	}
	doc.close();
}

//calculate sum of squares of frequency of words
void Document::calculateSumOfSquares()
{
	if (!frequencyMap.empty())
	{
		for (auto x : frequencyMap) {
			nSumOfSquares += pow(x.second, 2);
		}
	}
}

unsigned int Document::copySumOfSquares()
{
	return nSumOfSquares;
}

unordered_map<string, int> Document::copyFrequencyMap()
{
	return frequencyMap;
}