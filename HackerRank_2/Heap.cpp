#include "stdafx.h"

#include <sstream>
#include <deque>
#include <iostream>

#include "Utilities.h"
#include "Heap.h"
#include "TestManager.h"

Heap::Heap()
{
}

Heap::~Heap()
{
}

int Heap::JessieAndCookies()
{
	TestManager* s = new TestManager("D:\\TestCases\\cookies_8.txt");

	//s->GetInput();

	stringstream ss1(s->GetLine());

	int numCookies, sweetness;

	ss1 >> numCookies >> sweetness;

	stringstream ss2(s->GetLine());
	
	deque<int> cookies;

	int theCookie;

	for (int i = 0; i < numCookies; ++i)
	{
		ss2.clear();
		ss2 >> theCookie;

		Utilities::orderedInsertAt(cookies, 0, cookies.size(), theCookie);
	}

	int numOps = 0;
	int new_cookie = 0;

	while (cookies[0] <= sweetness)
	{
#if 1
		std::cout << "Before op" << endl;
		Utilities::display(cookies);
		std::cout << endl;
#endif

		if (cookies.size() == 1)
		{
			numOps = -1;
			break;
		}

		new_cookie = cookies[0] + 2 * cookies[1];

		
		Utilities::orderedInsertAt(cookies, 0, cookies.size(), new_cookie);

		cookies.pop_front();
		cookies.pop_front();

		++numOps;

#if 1
		std::cout << "After op" << endl;
		Utilities::display(cookies);
		std::cout << endl;
#endif

	}
	
	std::cout << numOps << endl;

	//for (int i = 0; i < cookies.size(); ++i)
	//{
	//	std::cout << cookies[i] << " ";
	//}

	return 0;
}