#include "stdafx.h"
#include "Mathematics.h"
#include "TestManager.h"
#include "Utilities.h"
#include "Matrix.h"

#include "sTestManager.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>

Mathematics::Mathematics()
{
}


Mathematics::~Mathematics()
{
}

void Mathematics::FindThePoint()
{
	sTestManager* tm = new sTestManager();
	tm->GetInput();
	int numTests;

	stringstream ss;
	ss.str(tm->GetLine());
	ss >> numTests;

	for (int tc = 1; tc <= numTests; ++tc)
	{
		int x1, y1, x2, y2;
		stringstream ss(tm->GetLine());
		ss >> x1 >> y1 >> x2 >> y2;

		int diffX = x2 - x1;
		int diffY = y2 - y1;

		int newX = x2 + diffX;
		int newY = y2 + diffY;

		cout << newX << " " << newY << endl;
	}
}

void Mathematics::MaximumDraws()
{
	sTestManager* tm = new sTestManager();
	tm->GetInput();
	int numTests;

	stringstream ss;
	ss.str(tm->GetLine());
	ss >> numTests;

	for (int tc = 1; tc <= numTests; ++tc)
	{
		stringstream ss(tm->GetLine());

		int numPairsInDrawer;

		ss >> numPairsInDrawer;

		int picks = 0;

		while (picks <= numPairsInDrawer)
		{
			++picks;
		}

		cout << picks << endl;
	}
}

void Mathematics::Handshakes()
{
	sTestManager* tm = new sTestManager();
	tm->GetInput();
	int numTests;

	stringstream ss;
	ss.str(tm->GetLine());
	ss >> numTests;


	for (int tc = 1; tc <= numTests; ++tc)
	{
		stringstream ss(tm->GetLine());
		int numPeopleInRoom;

		ss >> numPeopleInRoom;

		cout << numPeopleInRoom * (numPeopleInRoom - 1) / 2 << endl;
	}
}

void Mathematics::MinimumHeightTriangle()
{
	sTestManager* tm = new sTestManager();
	tm->GetInput();
	int numTests;

	stringstream ss;
	ss.str(tm->GetLine());
	ss >> numTests;

	for (int tc = 1; tc <= numTests; ++tc)
	{
		stringstream ss(tm->GetLine());
		int area, base, h;
		ss >> base >> area;

		// area = 1/2 b * h so....
		// h = 2 * a / b
		h = 0;
		int calc;
		while (1)
		{
			calc = 2 * h / base;

			cout << h << " " << base << " " << area << " " << calc << endl;
			if (.5 * base * h >= area)
			{
				cout << h; 
				break;
			}
			++h;
		}
	}
}

void Mathematics::ArmyGame()
{
	sTestManager* tm = new sTestManager();
	tm->GetInput();

	int numTests;

	stringstream ss;
	ss.str(tm->GetLine());
	ss >> numTests;

	for (int tc = 1; tc <= numTests; ++tc)
	{
		stringstream ss(tm->GetLine());
		int n, m;
		ss >> n >> m;

		cout << n << " " << m << endl;

		if (n % 2 == 0)
		{
			if (m % 2 == 0)
			{
				cout << n / 2 * m / 2 << endl;
			}
			else
			{
				cout << n / 2 * (m / 2 + 1) << endl;
			}
		}
		else
		{
			if (m % 2 == 0)
			{
				cout << (n / 2 + 1) * m / 2 << endl;
			}
			else
			{
				cout << (n / 2 + 1) * (m / 2 + 1) << endl;
			}

		}
	}
}

void Mathematics::PrimeFactors()
{

	sTestManager* tm = new sTestManager();
	tm->GetInput();

	//TestManager* tm = new TestManager("D:\\TestCases\\prime_factors_tc_11.txt");
	//tm->populateResults("D:\\TestCases\\prime_factors_tc_11_results.txt");

	

	int numTests;

	stringstream ss;
	ss.str(tm->GetLine());
	ss >> numTests;

	for (int tc = 1; tc <= numTests; ++tc)
	{
		stringstream ss(tm->GetLine());

		long long theProd = 1;
		int factorCount = 0;
		long long n = 0;
		ss >> n;

		for (int i = 0; i < NUM_PRIMES; ++i)
		{
			theProd *= Utilities::primes[i];
			if (theProd > 0 && theProd <= n)
			{
				++factorCount;
			}
			else if (theProd > n)
			{
				break;
			}
		}

		cout << factorCount << endl;
		//stringstream result;
		//result << factorCount;
		//tm->compareResult(tc-1, result.str());
	}
}



void Mathematics::ConnectingTowns()
{
	//sTestManager* tm = new sTestManager();
	//tm->GetInput();

	TestManager* tm = new TestManager("D:\\TestCases\\connecting_towns_tc_0.txt");
	tm->populateResults("D:\\TestCases\\connecting_towns_tc_0_results.txt");

	int numTests;

	stringstream ss;
	ss.str(tm->GetLine());
	ss >> numTests;

	for (int tc = 1; tc <= numTests; ++tc)
	{
		stringstream ss[2];
		ss[0].str(tm->GetLine());
		int numTowns;	
		ss[0] >> numTowns;

		vector<int> routes(numTowns - 1);
		ss[1].str(tm->GetLine());

		for (int i = 0; i < numTowns - 1; ++i)
		{
			ss[1].clear();
			ss[1] >> routes[i];
		}

		long long totalRoutes = 1;

		for (int t = 0; t < numTowns - 1; ++t)
		{
			totalRoutes *= routes[t];
			totalRoutes = totalRoutes % 1234567;
		}

		cout << totalRoutes << endl;
	}

}

void Mathematics::CuttingPaperSquares()
{
	sTestManager* tm = new sTestManager();
	tm->GetInput();

	//TestManager* tm = new TestManager("D:\\TestCases\\connecting_towns_tc_0.txt");
	//tm->populateResults("D:\\TestCases\\connecting_towns_tc_0_results.txt");

#if 0
	int numTests;

	stringstream ss;
	ss.str(tm->GetLine());
	ss >> numTests;
#endif

	//for (int tc = 1; tc <= numTests; ++tc)
//	{
		stringstream ss1[1];
		
		ss1[0].str(tm->GetLine());
		long long n, m;

		ss1[0] >> n >> m;

		long long totalCuts = 0;
		
		totalCuts = (n - 1) + n * (m - 1);
		cout << totalCuts << endl;
	//}
}

void Mathematics::SummingTheNSeries()
{
	sTestManager* tm = new sTestManager();
	tm->GetInput();

	//TestManager* tm = new TestManager("D:\\TestCases\\connecting_towns_tc_0.txt");
	//tm->populateResults("D:\\TestCases\\connecting_towns_tc_0_results.txt");

	int numTests;

	stringstream ss;
	ss.str(tm->GetLine());
	ss >> numTests;

	for (int tc = 1; tc <= numTests; ++tc)
	{
		long long theN;
		stringstream ss1;
		ss1.str(tm->GetLine());
		ss1 >> theN;

		long long tenToThe9 = 1000000007;

		if (theN % 2 == 0)
		{
			cout << ((theN % tenToThe9) * (theN % tenToThe9)) % tenToThe9 << endl;

		}
		else
		{
			long long intermediate = (((theN - 1) % tenToThe9) * ((theN - 1 ) % tenToThe9)) % tenToThe9;
			cout << (intermediate + 2 * theN - 1) % tenToThe9 << endl;
		}
	}
}

void Mathematics::nCrTable()
{
	sTestManager* tm = new sTestManager();
	tm->GetInput();

	//TestManager* tm = new TestManager("D:\\TestCases\\connecting_towns_tc_0.txt");
	//tm->populateResults("D:\\TestCases\\connecting_towns_tc_0_results.txt");

	int numTests;

	stringstream ss;
	ss.str(tm->GetLine());
	ss >> numTests;

	for (int tc = 1; tc <= numTests; ++tc)
	{
		int N;
		long long tenToThe9 = 1000000000;

		stringstream ss1;
		ss1.str(tm->GetLine());
		ss1 >> N;

		N = N + 1;
		const int M = N;

		long long array[100][100];

		for (int line = 0; line < N; line++)
		{
			for (int i = 0; i <= line; i++)
			{
				if (line == i || i == 0)
				{
					array[line][i] = 1;
				}
				else
				{
					array[line][i] = array[line - 1][i - 1] + array[line - 1][i];
				}
				if (array[line][i] > 1000000000)
				{
					array[line][i] = array[line][i] % 1000000000;
				}
				if (line == N - 1)
				{
					cout << array[line][i] << " ";
				}
			}
			cout << endl;

		}
	}
}

void Mathematics::BestDivisor()
{
	int n;
	cin >> n;
	int theDivisor;

	vector<int>theDivisors;

	int theUpperBound = sqrt(n);

	for (int p = 1; p <= theUpperBound; ++p)
	{
		if (n % p == 0)
		{
			theDivisors.push_back(p);
			theDivisors.push_back(n / p);
		}
	}

	Utilities::sort(theDivisors);

	int theMax = -1;
	int theBestDivisor = 0;

	for (int div = 0; div < theDivisors.size(); ++div)
	{
		//cout << theDivisors[div] << endl;
		vector<int> theDigits = Utilities::GetDigits(theDivisors[div]);

		int theSum = 0;
		for (int j = 0; j < theDigits.size(); ++j)
		{
			theSum += theDigits[j];
		}

		if (theSum > theMax)
		{
			theMax = theSum;
			theBestDivisor = theDivisors[div];
		}
	}

	cout << theBestDivisor << endl;
}

void Mathematics::Restaurant()
{
	int numTests;
	cin >> numTests;

	int tc = 1;
	while (tc <= numTests)
	{
		int a, b;
		cin >> a;
		cin >> b;

		if (a == b)
		{
			cout << 1 << endl;
		}

		else
		{
			int theGcd = Utilities::GCD(a, b);

			cout << (a / theGcd) * (b / theGcd) << endl;
		}
	}
}

int Mathematics::SherlockAndMovingTiles()
{

	const double PI = 4.0*atan(1.0);

	sTestManager* s = new sTestManager();
	s->GetInput();

	float L, S1, S2;
	stringstream ss(s->GetLine());
	ss >> L >> S1 >> S2;

	int numTests = atoi(s->GetLine().c_str());

	int tc = 1;

	while (tc <= numTests)
	{
		//float x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		double area = atof(s->GetLine().c_str());

		double t = ((sqrt(area) / cos(PI / 4)) - sqrt(2) * L) / (S1 - S2);

		cout << fixed;

		if (t >= 0)
		{
			cout << t << endl;
		}
		else
		{
			cout << -1 * t << endl;
		}
		++tc;

	}
	return 0;
}

int Mathematics::SherlockAndDivisors()
{
	int numTests;
	cin >> numTests;

	int tc = 1;
	while (tc <= numTests)
	{
		int theValue;
		cin >> theValue;

		vector<int> theDivisors;

		for (int i = 2; i <= sqrt(theValue); ++i)
		{
			if (theValue % i == 0)
			{
				if (i % 2 == 0)
				{
					theDivisors.push_back(i);
				}

				if (theValue / i % 2 == 0)
				{
					theDivisors.push_back(theValue / i);
				}
			}
		}

		if (theValue % 2 == 0)
		{
			theDivisors.push_back(theValue);
		}

		std::vector<int>::iterator it;
		it = unique(theDivisors.begin(), theDivisors.end());          
		theDivisors.resize(std::distance(theDivisors.begin(), it));

		cout << theDivisors.size() << endl;
	}

	return 0;
}

int Mathematics::DiwaliLights()
{
	int numTests;
	cin >> numTests;

	int tc = 1;

	while (tc <= numTests)
	{
		int numLights;
		cin >> numLights;

		long long numCombos = 0;

		for (int i = 1; i <= numLights; ++i)
		{
			numCombos += Utilities::N_Choose_M(numLights, i) % 10;
			numCombos = numCombos % 10;
		}

		cout << numCombos << endl;

		++tc;
	}
	return 0;
}

int Mathematics::LinearAlgebraFoundations_1()
{
	Matrix A(3, 3);
	A.myValues[0][0] = 1; A.myValues[0][1] = 2; A.myValues[0][2] = 3;
	A.myValues[1][0] = 2; A.myValues[1][1] = 3; A.myValues[1][2] = 4;
	A.myValues[2][0] = 1; A.myValues[2][1] = 1; A.myValues[2][2] = 1;

	Matrix B(3, 3);
	B.myValues[0][0] = 4; B.myValues[0][1] = 5; B.myValues[0][2] = 6;
	B.myValues[1][0] = 7; B.myValues[1][1] = 8; B.myValues[1][2] = 9;
	B.myValues[2][0] = 4; B.myValues[2][1] = 5; B.myValues[2][2] = 7;

	Matrix M = MatrixOps::Add(A, B);

	for (int i = 0; i < M.my_N; ++i)
	{
		for (int j = 0; j < M.my_M; ++j)
		{
			cout << M.myValues[i][j] << endl;
		}
	}

	return 0;
}

int Mathematics::LinearAlgebraFoundations_2()
{
	Matrix A(3, 3);
	A.myValues[0][0] = 1; A.myValues[0][1] = 2; A.myValues[0][2] = 3;
	A.myValues[1][0] = 2; A.myValues[1][1] = 3; A.myValues[1][2] = 4;
	A.myValues[2][0] = 1; A.myValues[2][1] = 1; A.myValues[2][2] = 1;

	Matrix B(3, 3);
	B.myValues[0][0] = 4; B.myValues[0][1] = 5; B.myValues[0][2] = 6;
	B.myValues[1][0] = 7; B.myValues[1][1] = 8; B.myValues[1][2] = 9;
	B.myValues[2][0] = 4; B.myValues[2][1] = 5; B.myValues[2][2] = 0;

	//Matrix M = MatrixOps::scalar(B, -1);
	Matrix M2 = MatrixOps::Add(A, MatrixOps::scalar(B, -1));

	for (int i = 0; i < M2.my_N; ++i)
	{
		for (int j = 0; j < M2.my_M; ++j)
		{
			cout << M2.myValues[i][j] << endl;
		}
	}

	return 0;
}

int Mathematics::LinearAlgebraFoundations_3()
{
	Matrix A(2, 2);
	A.myValues[0][0] = 1; A.myValues[0][1] = 2; //A.myValues[0][2] = 3;
	A.myValues[1][0] = 2; A.myValues[1][1] = 3; //A.myValues[1][2] = 4;
	//A.myValues[2][0] = 1; A.myValues[2][1] = 1; A.myValues[2][2] = 1;

	Matrix B(2, 2);
	B.myValues[0][0] = 4; B.myValues[0][1] = 5; //B.myValues[0][2] = 6;
	B.myValues[1][0] = 7; B.myValues[1][1] = 8; //B.myValues[1][2] = 9;
	//B.myValues[2][0] = 4; B.myValues[2][1] = 5; B.myValues[2][2] = 0;

	Matrix M2 = MatrixOps::Multiply(A, B);

	for (int i = 0; i < M2.my_N; ++i)
	{
		for (int j = 0; j < M2.my_M; ++j)
		{
			cout << M2.myValues[i][j] << endl;
		}
	}

	return 0;
}

int Mathematics::LinearAlgebraFoundations_4()
{
	Matrix A(3, 3);
	A.myValues[0][0] = 1; A.myValues[0][1] = 2; A.myValues[0][2] = 3;
	A.myValues[1][0] = 2; A.myValues[1][1] = 3; A.myValues[1][2] = 4;
    A.myValues[2][0] = 1; A.myValues[2][1] = 1; A.myValues[2][2] = 1;

	Matrix B(3, 3);
	B.myValues[0][0] = 4; B.myValues[0][1] = 5; B.myValues[0][2] = 6;
	B.myValues[1][0] = 7; B.myValues[1][1] = 8; B.myValues[1][2] = 9;
	B.myValues[2][0] = 4; B.myValues[2][1] = 5; B.myValues[2][2] = 7;

	Matrix M2 = MatrixOps::Multiply(A, B);

	for (int i = 0; i < M2.my_N; ++i)
	{
		for (int j = 0; j < M2.my_M; ++j)
		{
			cout << M2.myValues[i][j] << endl;
		}
	}

	return 0;
}

int Mathematics::LinearAlgebraFoundations_5()
{
	Matrix A(3, 3);
	A.myValues[0][0] = 1; A.myValues[0][1] = 1; A.myValues[0][2] = 0;
	A.myValues[1][0] = 0; A.myValues[1][1] = 1; A.myValues[1][2] = 0;
	A.myValues[2][0] = 0; A.myValues[2][1] = 0; A.myValues[2][2] = 1;


	Matrix M2(3,3);
	M2.myValues[0][0] = 1; M2.myValues[0][1] = 1; M2.myValues[0][2] = 0;
	M2.myValues[1][0] = 0; M2.myValues[1][1] = 1; M2.myValues[1][2] = 0;
	M2.myValues[2][0] = 0; M2.myValues[2][1] = 0; M2.myValues[2][2] = 1;

	for (int i = 1; i <= 99; ++i)
	{
		M2 = MatrixOps::Multiply(M2, A);
	}

	for (int i = 0; i < M2.my_N; ++i)
	{
		for (int j = 0; j < M2.my_M; ++j)
		{
			cout << M2.myValues[i][j] << endl;
		}
	}

	return 0;
}

int Mathematics::LinearAlgebraFoundations_7()
{
	Matrix A(2, 2);
	A.myValues[0][0] = -2; A.myValues[0][1] = -9;// A.myValues[0][2] = 0;
	A.myValues[1][0] = 1; A.myValues[1][1] = 4; //A.myValues[1][2] = 0;
	//A.myValues[2][0] = 0; A.myValues[2][1] = 0; A.myValues[2][2] = 1;


	Matrix M2(2, 2);
	M2.myValues[0][0] = -2; M2.myValues[0][1] = -9; //M2.myValues[0][2] = 0;
	M2.myValues[1][0] = 1; M2.myValues[1][1] = 4; //M2.myValues[1][2] = 0;
	//M2.myValues[2][0] = 0; M2.myValues[2][1] = 0; M2.myValues[2][2] = 1;

	for (int i = 1; i <= 999; ++i)
	{
		M2 = MatrixOps::Multiply(M2, A);
	}

	for (int i = 0; i < M2.my_N; ++i)
	{
		for (int j = 0; j < M2.my_M; ++j)
		{
			cout << M2.myValues[i][j] << endl;
		}
	}

	return 0;
}

int Mathematics::ShashankAndList()
{
	sTestManager* sm = new sTestManager();
	sm->GetInput();

	int numValues = atoi(sm->GetLine().c_str());

	vector<int> theValues(numValues);

	stringstream ss(sm->GetLine());

	for (int i = 0; i < numValues; ++i)
	{
		ss.clear();

		ss >> theValues[i];
	}


}