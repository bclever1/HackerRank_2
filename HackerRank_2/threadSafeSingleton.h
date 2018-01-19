#pragma once
#include "stdafx.h"

#include <mutex>
#include <iostream>
#include <ostream>
#include <vector>
#include <string>

std::once_flag flag1;

static std::mutex my_mutex;

class threadSafeSingleton
{
    public:

		static threadSafeSingleton* GetInst()
		{
			std::call_once(flag1, []() {new threadSafeSingleton(); });
			return threadSafeSingleton::myInstance;
		}

		static void print(std::string& theStr) 
		{
			std::lock_guard<std::mutex> guard(my_mutex);
			std::cout << theStr << std::endl; 
		}

		static void print(int theStr)
		{
			std::lock_guard<std::mutex> guard(my_mutex);
			std::cout << theStr << std::endl << std::flush;
		}

		static int getInt()
		{
			std::lock_guard<std::mutex> guard(my_mutex);

			int theResult;
			cin >> theResult;
			return theResult;
		}

	private:
				
		threadSafeSingleton() { myInstance = this; }
		static threadSafeSingleton* myInstance;
};


threadSafeSingleton* threadSafeSingleton::myInstance = NULL;
