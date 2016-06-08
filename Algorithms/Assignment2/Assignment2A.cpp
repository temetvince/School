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

class Assignment2A
{
public:
	string makePalindrome(string input)
	{
		string inputReverse = string(input.rbegin(), input.rend());
		string t = input;
		string tReverse = inputReverse;
		while (t != tReverse)
		{
			t = (t.substr(1, string::npos));
			tReverse = string(t.rbegin(), t.rend());
		}
		return input + inputReverse.substr(t.size(), string::npos);
	}
};