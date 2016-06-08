//Coded by Emmett Casey

#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

void matrixInput(std::vector<std::vector<double> > &, std::vector<std::vector<double> > &);
void matrixInputAddRow(std::vector<std::vector<double> > &, const int, const int, std::string);
void matrixOutput(const std::vector<std::vector<double> >);
std::vector<std::vector<double> > matrixStrassens(const std::vector<std::vector<double> >, const std::vector<std::vector<double> >);
std::vector<std::vector<double> > matrixQuadrant(const std::vector<std::vector<double> >, const int, const int);
std::vector<std::vector<double> > matrixAdd(const std::vector<std::vector<double> >, const std::vector<std::vector<double> >);
std::vector<std::vector<double> > matrixSubtract(const std::vector<std::vector<double> >, const std::vector<std::vector<double> >);
std::vector<std::vector<double> > matrixMultiply(const std::vector<std::vector<double> >, const std::vector<std::vector<double> >);

int main()
{
	std::vector<std::vector<double> > mA, mB;
	matrixInput(mA, mB);
	matrixOutput(matrixStrassens(mA, mB));
	return 0;
}

void matrixInput(std::vector<std::vector<double> > &mA, std::vector<std::vector<double> > &mB)
{
	std::string input = "";
	std::ifstream inFile("input.txt");
	getline(inFile, input);
	int n = atoi(input.c_str());
	for (int i = 0; i < n; i++)
	{
		getline(inFile, input);
		if (input.empty())
		{
			i--;
			continue;
		}
		matrixInputAddRow(mA, n, i, input);
	}
	for (int i = 0; i < n; i++)
	{
		getline(inFile, input);
		if (input.empty())
		{
			i--;
			continue;
		}
		matrixInputAddRow(mB, n, i, input);
	}
	inFile.close();
}

void matrixInputAddRow(std::vector<std::vector<double> > &matrix, const int n, const int row, std::string input)
{
	std::vector<double> temp;
	for (int i = 0; i < n; i++)
	{
		size_t op = input.find_first_of(" ");
		temp.push_back(atof(input.substr(0, op).c_str()));
		input = input.substr(op + 1, std::string::npos);
	}
	matrix.push_back(temp);
}

void matrixOutput(const std::vector<std::vector<double> > matrix)
{
	std::ofstream outFile("output.txt");
	int n = (int) matrix.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			outFile << matrix[i][j];
			if (j != n - 1)
				outFile << " ";
		}
		if (i != n - 1)
			outFile << std::endl;
	}
	outFile.close();
}

std::vector<std::vector<double> > matrixStrassens(const std::vector<std::vector<double> > mA, const std::vector<std::vector<double> > mB)
{
	int n = (int) mA.size();
	if (n <= 64)
		return matrixMultiply(mA, mB);
	
	int N = n / 2;
	std::vector<std::vector<double> > answer;
	std::vector<std::vector<double> > column0;
	std::vector<std::vector<double> > column1;

	std::vector<std::vector<double> > a = matrixQuadrant(mA, 0, 0);
	std::vector<std::vector<double> > b = matrixQuadrant(mA, 0, N);
	std::vector<std::vector<double> > c = matrixQuadrant(mA, N, 0);
	std::vector<std::vector<double> > d = matrixQuadrant(mA, N, N);
	std::vector<std::vector<double> > e = matrixQuadrant(mB, 0, 0);
	std::vector<std::vector<double> > f = matrixQuadrant(mB, 0, N);
	std::vector<std::vector<double> > g = matrixQuadrant(mB, N, 0);
	std::vector<std::vector<double> > h = matrixQuadrant(mB, N, N);

	std::vector<std::vector<double> > p1 = matrixStrassens(a, matrixSubtract(f, h));
	std::vector<std::vector<double> > p2 = matrixStrassens(matrixAdd(a, b), h);
	std::vector<std::vector<double> > p3 = matrixStrassens(matrixAdd(c, d), e);
	std::vector<std::vector<double> > p4 = matrixStrassens(d, matrixSubtract(g, e));
	std::vector<std::vector<double> > p5 = matrixStrassens(matrixAdd(a, d), matrixAdd(e, h));
	std::vector<std::vector<double> > p6 = matrixStrassens(matrixSubtract(b, d), matrixAdd(g, h));
	std::vector<std::vector<double> > p7 = matrixStrassens(matrixSubtract(a, c), matrixAdd(e, f));

	column0 = matrixAdd(matrixSubtract(matrixAdd(p5, p4), p2), p6);
	column1 = matrixAdd(p1, p2);
	for (int i = 0; i < N; i++)
	{
		std::vector<double> temp;
		for (int j = 0; j < N; j++)
			temp.push_back(column0[i][j]);
		for (int j = 0; j < N; j++)
			temp.push_back(column1[i][j]);
		answer.push_back(temp);
	}
	column0 = matrixAdd(p3, p4);
	column1 = matrixSubtract(matrixSubtract(matrixAdd(p1, p5), p3), p7);
	for (int i = 0; i < N; i++)
	{
		std::vector<double> temp;
		for (int j = 0; j < N; j++)
			temp.push_back(column0[i][j]);
		for (int j = 0; j < N; j++)
			temp.push_back(column1[i][j]);
		answer.push_back(temp);
	}

	return answer;
}

std::vector<std::vector<double> > matrixQuadrant(const std::vector<std::vector<double> > matrix, const int rowBeginning, const int columnBeginning)
{
	std::vector<std::vector<double> > answer;
	int N = matrix.size() / 2;
	for (int i = 0; i < N; i++)
	{
		std::vector<double> temp;
		for (int j = 0; j < N; j++)
			temp.push_back(matrix[i + rowBeginning][j + columnBeginning]);
		answer.push_back(temp);
	}
	return answer;
}

std::vector<std::vector<double> > matrixAdd(const std::vector<std::vector<double> > mA, const std::vector<std::vector<double> > mB)
{
	std::vector<std::vector<double> > answer;
	int n = (int) mA.size();
	for (int i = 0; i < n; i++)
	{
		std::vector<double> temp;
		for (int j = 0; j < n; j++)
			temp.push_back(mA[i][j] + mB[i][j]);
		answer.push_back(temp);
	}
	return answer;
}

std::vector<std::vector<double> > matrixSubtract(const std::vector<std::vector<double> > mA, const std::vector<std::vector<double> > mB)
{
	std::vector<std::vector<double> > answer;
	int n = (int) mA.size();
	for (int i = 0; i < n; i++)
	{
		std::vector<double> temp;
		for (int j = 0; j < n; j++)
			temp.push_back(mA[i][j] - mB[i][j]);
		answer.push_back(temp);
	}
	return answer;
}

std::vector<std::vector<double> > matrixMultiply(const std::vector<std::vector<double> > mA, const std::vector<std::vector<double> > mB)
{
	std::vector<std::vector<double> > answer;
	int n = (int) mA.size();
	for (int i = 0; i < n; i++)
	{
		std::vector<double> temp;
		for (int j = 0; j < n; j++)
		{
			long double element = 0;
			for (int k = 0; k < n; k++)
				element += mA[i][k] * mB[k][j];
			temp.push_back((double) element);
		}
		answer.push_back(temp);
	}
	return answer;
}