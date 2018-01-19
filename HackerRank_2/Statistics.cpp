#include "stdafx.h"
#include "Statistics.h"
#include "TestManager.h"
#include "Utilities.h"
#include "dataWrapper.h"

#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <math.h>

Statistics::Statistics()
{
}

Statistics::~Statistics()
{
}


//---------------------------------------------------//
float Statistics::mean(vector<int>& v)
{
	float theResult = 0.0;
	float theNum = v.size();

	for (int i = 0; i < theNum; ++i)
	{
		theResult += v[i];
	}

	theResult = theResult / theNum;

	return theResult;
}

//---------------------------------------------------//
float Statistics::median(vector<int>& v)
{
	float theResult = 0.0;
	int theNum = v.size();

	Utilities::sort(v);

	if (theNum % 2 == 0)
	{
		int theIdx = theNum / 2;
		theResult = (float)(v[theIdx - 1] + v[theIdx]) / 2;
	}
	else
	{
		int theIdx = theNum / 2;
		theResult = (float)v[theIdx];
	}

	return theResult;
}

//---------------------------------------------------//
float Statistics::mode(vector<int>& v)
{
	dataWrapper theMode(-1);

	int theIdx = 0;
	vector<dataWrapper*>temp;

	for (unsigned i = 0; i < v.size(); ++i)
	{
		theIdx = Utilities::isElementOf(temp, v[i]);
		if (theIdx == -1)
		{
			dataWrapper* dw = new dataWrapper(v[i]);
			temp.push_back(dw);
		}
		else
		{
			++temp[theIdx]->myCount;
			if (temp[theIdx]->myCount > theMode.myCount)
			{
				theMode.myData = v[i];
				++theMode.myCount;
			}
		}
	}

	if (theMode.myData == -1)
	{
		return v[0];
	}

	return theMode.myData;
}

//---------------------------------------------------//
float Statistics::weighted_mean(vector<int>& theData, vector<int>& theWeights)
{
	float theResult = 0.0;
	float theNum = theData.size();
	float theDenom = 0.0;

	for (int i = 0; i < theNum; ++i)
	{
		theResult += theData[i] * theWeights[i];
	}

	for (int j = 0; j < theWeights.size(); ++j)
	{
		theDenom += theWeights[j];
	}

	theResult = theResult / theDenom;

	return theResult;
}

//---------------------------------------------------//
float Statistics::standard_dev(vector<int>& theData)
{
	float theResult = 0.0;
	float theNum = theData.size();

	float N = mean(theData);

	for (int i = 0; i < theData.size(); ++i)
	{
		theResult += pow((theData[i] - N), 2);
	}

	theResult = sqrt(theResult/theNum);

	return theResult;
}

//---------------------------------------------------//
float Statistics::poisson(float lambda, int k)
{
	float e = 2.71828;
	return pow(lambda, k) * exp(-1 * lambda) / Utilities::factorial(k);
}

//------------------------------------------------//
void Statistics::MeanMedianMode()
{
	TestManager* tm = new TestManager();

	int theNum = atoi(tm->GetLine().c_str());

	vector<int> theData(theNum);

	stringstream ss(tm->GetLine());

	for (int i = 0; i < theNum; ++i)
	{
		ss.clear();
		ss >> theData[i];
	}

	cout << fixed;
	cout << setprecision(1);
	cout << mean(theData) << endl;
	cout << median(theData) << endl;
	cout << setprecision(0);
	cout << mode(theData) << endl;

}

//------------------------------------------------//
void Statistics::WeightedMean()
{
	TestManager* tm = new TestManager();

	int theNum = atoi(tm->GetLine().c_str());

	vector<int> theData(theNum);

	stringstream ss(tm->GetLine());

	for (int i = 0; i < theNum; ++i)
	{
		ss.clear();
		ss >> theData[i];
	}

	vector<int> theWeights(theNum);

	stringstream ss2(tm->GetLine());

	for (int i = 0; i < theNum; ++i)
	{
		ss2.clear();
		ss2 >> theWeights[i];
	}

	cout << fixed;
	cout << setprecision(1);
	cout << weighted_mean(theData,theWeights) << endl;
}

//------------------------------------------------//
void Statistics::Quartiles()
{
	TestManager* tm = new TestManager();

	int theNum = atoi(tm->GetLine().c_str());

	vector<int> theData(theNum);

	stringstream ss(tm->GetLine());

	for (int i = 0; i < theNum; ++i)
	{
		ss.clear();
		ss >> theData[i];
	}

	Utilities::sort(theData);

	vector<int>theLowerHalf;
	vector<int>theUpperHalf;

	if (theData.size() % 2 == 0)
	{
		for (int i = 0; i < theData.size() / 2; ++i)
		{
			theLowerHalf.push_back(theData[i]);
		}

		for (int i = theData.size() / 2; i < theData.size(); ++i)
		{
			theUpperHalf.push_back(theData[i]);
		}
	}

	else
	{
		for (int i = 0; i < theData.size() / 2; ++i)
		{
			theLowerHalf.push_back(theData[i]);
		}

		for (int i = theData.size() / 2 + 1; i < theData.size(); ++i)
		{
			theUpperHalf.push_back(theData[i]);
		}
	}

	int firstQuartile  = median(theLowerHalf);
	int secondQuartile = median(theData);
	int thirdQuartile  = median(theUpperHalf);

	cout << firstQuartile << endl;
	cout << secondQuartile << endl;
	cout << thirdQuartile << endl;
}

//------------------------------------------------//
void Statistics::InterQuartileRange()
{
	float theResult = 0.0;

	TestManager* tm = new TestManager();

	int theNum = atoi(tm->GetLine().c_str());

	vector<int> theDataPoints(theNum);

	stringstream ss(tm->GetLine());

	for (int i = 0; i < theNum; ++i)
	{
		ss.clear();
		ss >> theDataPoints[i];
	}

	vector<int> theFreq(theNum);
	stringstream ss1(tm->GetLine());

	for (int i = 0; i < theNum; ++i)
	{
		ss1.clear();
		ss1 >> theFreq[i];
	}

	vector<int> theData;

	for (int i = 0; i < theNum; ++i)
	{
		for (int f = 0; f < theFreq[i]; ++f)
		{
			theData.push_back(theDataPoints[i]);
		}
	}

	Utilities::sort(theData);

	vector<int>theLowerHalf;
	vector<int>theUpperHalf;

	if (theData.size() % 2 == 0)
	{
		for (int i = 0; i < theData.size() / 2; ++i)
		{
			theLowerHalf.push_back(theData[i]);
		}

		for (int i = theData.size() / 2; i < theData.size(); ++i)
		{
			theUpperHalf.push_back(theData[i]);
		}
	}

	else
	{
		for (int i = 0; i < theData.size() / 2; ++i)
		{
			theLowerHalf.push_back(theData[i]);
		}

		for (int i = theData.size() / 2 + 1; i < theData.size(); ++i)
		{
			theUpperHalf.push_back(theData[i]);
		}
	}

	float firstQuartile = median(theLowerHalf);
	float secondQuartile = median(theData);
	float thirdQuartile = median(theUpperHalf);

	theResult = thirdQuartile - firstQuartile;
	cout << fixed;
	cout << setprecision(1);
	cout << theResult << endl;

}

//------------------------------------------------//
void Statistics::StandardDeviation()
{
	float theResult = 0.0;

	TestManager* tm = new TestManager();

	int theNum = atoi(tm->GetLine().c_str());

	vector<int> theDataPoints(theNum);

	stringstream ss(tm->GetLine());

	for (int i = 0; i < theNum; ++i)
	{
		ss.clear();
		ss >> theDataPoints[i];
	}

	theResult = standard_dev(theDataPoints);

	cout << fixed;
	cout << setprecision(1);
	cout << theResult;
}

//------------------------------------------------//
void Statistics::BinomialDistributionI()
{
	// Ratio of 1.09 to 1 means 0.545 prob each chile is a boy.

	float prob = 0.0;
	float pBoy = 1.09 / (1.09 + 1);
	float pGirl = 1 - pBoy;

	for (int i = 3; i <= 6; ++i)
	{
		prob += Utilities::N_Choose_M(6, i) * pow(pBoy, i) * pow(pGirl, 6 - i);
	}

	cout << fixed;
	cout << setprecision(3);
	cout << prob << endl;;

}

//------------------------------------------------//
void Statistics::BinomialDistributionII()
{
	

	// Ratio of 1.09 to 1 means 0.545 prob each chile is a boy.

	float prob = 0.0;
	float pFail = .12;
	float pGood = 1 - pFail;

	// Probably no more than 2 fail
	for (int i = 0; i <= 2; ++i)
	{
		prob += Utilities::N_Choose_M(10, i) * pow(pFail, i) * pow(pGood, 10 - i);
	}

	cout << fixed;
	cout << setprecision(3);
	cout << prob << endl;;

	prob = 0.0;

	// At least 2 fail
	for (int i = 2; i <= 10; ++i)
	{
		prob += Utilities::N_Choose_M(10, i) * pow(pFail, i) * pow(pGood, 10 - i);
	}

	cout << fixed;
	cout << setprecision(3);
	cout << prob << endl;;

}

//------------------------------------------------//
void Statistics::GeometricDistributionI()
{
	// g(n,p) = q^(n-1) * p
	float probDefect = 0.33;

	float prob = pow(1 - probDefect, 4) * probDefect;

	cout << fixed;
	cout << setprecision(3);
	cout << prob << endl;;
}

//------------------------------------------------//
void Statistics::GeometricDistributionII()
{
	// g(n,p) = q^(n-1) * p
	float probDefect = 0.33333333;

	float prob = 0.0;
	
	for (int i = 1; i <= 5; ++i)
	{
		prob += pow(1 - probDefect, i - 1) * probDefect;
	}

	cout << fixed;
	cout << setprecision(3);
	cout << prob << endl;;
}

//------------------------------------------------//
void Statistics::PoissonDistributionI()
{
	float lambda = 2.5;
	int k = 5;

	float e = 2.71828;
	cout << pow(lambda, k) * exp(-1 * lambda) / Utilities::factorial(k);
}


//------------------------------------------------//
void Statistics::PoissonDistributionII()
{
	float lambdaA = 0.88;
	float lambdaB = 1.55;

	float cA = 160 + 40 * ((lambdaA + lambdaA * lambdaA));
	float cB = 128 + 40 * ((lambdaB + lambdaB * lambdaB));

	cout << cA << endl;
	cout << cB << endl;
}

//------------------------------------------------//
void Statistics::NormalDistributionI()
{
	double e = 2.71828;
	double mean = 20;
	double stdev = 2;
	double x[3] = { 19.5, 22, 20 };
	double pi = 3.14159;
	double variance = stdev * stdev;

	double theResult1 = cumulativeProb(mean, stdev, x[0]);

	double theResult2 = cumulativeProb(mean, stdev, x[1]) - \
		                cumulativeProb(mean, stdev, x[2]);

	cout << fixed;
	cout << setprecision(3);
	cout << theResult1 << endl;
	cout << theResult2 << endl;

}


//------------------------------------------------//
void Statistics::NormalDistributionII()
{
	double mean = 70;
	double stdev = 10;

	cout << fixed;
	cout << setprecision(2);
	
	cout << 100 * (1 - cumulativeProb(mean, stdev, 80)) << endl;
	cout << 100 * (1 - cumulativeProb(mean, stdev, 60)) << endl;
	cout << 100 * (cumulativeProb(mean, stdev, 60)) << endl;
}

double Statistics::cumulativeProb(double mean, double stdev, double theValue)
{
	return 0.5 *  (1 + erf((theValue - mean) / (stdev * sqrt(2))));
}