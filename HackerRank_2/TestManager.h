#ifndef TEST_MANAGER_H
#define TEST_MANAGER_H
#include <string>
#include <vector>

using namespace::std;

const int MAX_FILE_SIZE = 1000000;

class TestManager
{
public:
	TestManager(string theFileName);
	TestManager();
	~TestManager();

	void populateResults(string theFileName);
	bool compareResult(unsigned int theTestNum, string theResult);
	string GetLine();

private:

	string myFileName;
	vector<string> myExpectedResults;
	int myNumCases;
	string myInputArray[MAX_FILE_SIZE];
	int myCurrentLinePtr;
};

#endif