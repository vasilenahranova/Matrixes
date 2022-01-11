#include<iostream>
using namespace std;

void Input(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
}

void Output(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout<< matrix[i][j]<<" ";
		}
		cout << endl;
	}
}

//checking if 1 is one of the digits of a number
bool checkIf1Contained(int number)
{
	while (number > 0)
	{
		if (number % 10 == 1)
			return true;
		number /= 10;
	}

	return false;
}
//main diagonal structure is shown(above: i<j; under& i>j)
//not-main diagonal structure: j==n-1-i; above and under-analogical;
int productionOfSprecificNumbers(int** matrix, int n, int m)
{
	int Production = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j ==i) {
				if (checkIf1Contained(matrix[i][j]))
					Production *= matrix[i][j];
			}
		}
	}
	return Production;
}
//finding the row with largest sum(analogically for a column)
int biggestRow(int** matrix, int n, int m)
{
	int SumRow1 = 0, SumRow2 = 0, biggestRow=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			SumRow1 += matrix[i][j];
		}
		if (SumRow1 > SumRow2) {
			SumRow2 = SumRow1;
			biggestRow = i;
		}
		SumRow1 = 0;
	}
	return biggestRow;
}

int main()
{
	int n, m;
	cout << "n= "; cin >> n;
	cout << "m= "; cin >> m;
	//validation
	while (n < 1 || n>30 || m < 1 || m>30)
	{
		cout << "Invalid n or m! Try again!" << endl;
		cout << "n= "; cin >> n;
		cout << "m= "; cin >> m;
	}

	//declare the dynamic matrix
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
	}

	//call the functions
	Input(matrix, n, m);
	Output(matrix, n, m);
	cout << "Production= " << productionOfSprecificNumbers(matrix, n, m) << endl;
	cout << "The biggest row is " << biggestRow(matrix, n, m) << endl;

	//delete the dynamic matrix
	for (int i = 0; i < n; i++){
		delete[]matrix[i];
	}
	delete[] matrix;
}