//Coded by Emmett Casey

#include <iostream>
#include <string>
#include <algorithm>

int solve(std::string input)
{
	size_t op = input.find_first_of("+-*/");
	int n0 = atoi(input.substr(0, op).c_str());
	int n1 = atoi(input.substr(op + 1, std::string::npos).c_str());
	switch (input[op])
	{
		case '+': return n0 + n1;
		case '-': return n0 - n1;
		case '*': return n0 * n1;
		case '/': return n0 / n1;	
	}
	return 0;
}

int main()
{
	std::cout << solve("21*2");
	return 0 ;
}