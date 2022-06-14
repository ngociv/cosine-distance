#ifndef DOCUMENTS_H_
#define DOCUMENTS_H_

#include <string>
#include <unordered_map>

using namespace std;

class Document {

private:
	string fullPath;
	unordered_map <string, int> frequencyMap;  //map that stores frequency of words
	unsigned int nSumOfSquares;		//sum of squares of frequency of words

public:
	Document();

	~Document();

	//void operator()();

	void inputPath();

	void countFrequency();

	void calculateSumOfSquares();

	unsigned int copySumOfSquares();

	unordered_map<string, int> copyFrequencyMap();
};


#endif // !DOCUMENTS_H_