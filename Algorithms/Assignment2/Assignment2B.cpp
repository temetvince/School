// Name: Emmett Casey

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Assignment2B
{
public:
	int numPalindrome(string input)
	{
		string space = " ";
		string expanded = space;
		int sizeInput = input.size();
		int sizeExpanded = sizeInput * 2 + 1;
		int * palindrome = new int[sizeExpanded];
		for (int i = 0; i < sizeInput; i++)
			expanded += input[i] + space;
		for (int i = 0; i < sizeExpanded; i++)
		{
			int j = 1;
			int dismissed = 0;
			while (i - j >= 0 && i + j < sizeExpanded && expanded[i + j] == expanded[i - j])
			{
				if ((i - j) % 2 && palindrome[i - j])
					dismissed++;
				j++;
			}
			palindrome[i] = j - 1 - dismissed;
		}
		int count = 0;
		for (int i = 0; i < sizeExpanded; i++)
			count += palindrome[i];
		delete [] palindrome;
		palindrome = NULL;
		return count;
	}
};