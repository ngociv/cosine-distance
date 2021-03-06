//program to calculate cosine distance of two documents
//time complexity : O(n)

#include <thread>
#include <iostream>
#include "Document.h"

Document* pDocument_1 = new Document;
Document* pDocument_2 = new Document;

float calculateCosineDistance();

void thread_main(Document* pDoc)
{
	pDoc->inputPath();
	pDoc->countFrequency();
	pDoc->calculateSumOfSquares();
}

int main()
{
	thread thread_1(thread_main, pDocument_1);
	thread thread_2(thread_main, pDocument_2);

	if (thread_1.joinable())
	{
		thread_1.join();
	}
	if (thread_2.joinable())
	{
		thread_2.join();
	}

	cout << "The cosine distance of two documents is " << calculateCosineDistance() << " radian" << endl;
	return 0;
}

float calculateCosineDistance()
{
	unordered_map<string, int> map1 = pDocument_1->copyFrequencyMap();
	unordered_map<string, int> map2 = pDocument_2->copyFrequencyMap();
	if (map1.empty() || map2.empty())
	{
		cout << "There are document that do not contain any words" << endl;
		exit(1);
	}
	unsigned int sum1 = pDocument_1->copySumOfSquares();
	unsigned int sum2 = pDocument_2->copySumOfSquares();

	unsigned int numerator = 0;
	for (auto x : map1) {
		if (map2.find(x.first) != map2.end()) {
			numerator += x.second * map2.find(x.first)->second;
		}
	}

	map1.clear();
	map2.clear();
	delete pDocument_1;
	delete pDocument_2;

	float cos = (numerator * 1.00) / (sqrt(sum1 * sum2));
	return acos(cos);
}