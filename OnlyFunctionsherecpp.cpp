
//deleteRowOfMAtrix
void coppyArrays(int* array1, int* array2, int m)
{
	for (int i = 0; i < m; i++)
	{
		array1[i] = array2[i];
	}
}

void deleteRowOfMatrix(int** matrix, int n, int m, int k)
{
	for (int i = k; i < n - 1; i++) {
		coppyArrays(matrix[i], matrix[i + 1], m);
	}
}

//deleteColumnOfMatrix
void deleteElement(int*& arrayOld, int m, int k)
{
	int* newarray = new int[m - 1];
	for (int i = 0; i < k; i++) {
		newarray[i] = arrayOld[i];
	}

	for (int i = k; i < m - 1; i++) {
		newarray[i] = arrayOld[i + 1];
	}
	delete[] newarray;
}

void deleteColumn(int** matrix, int n, int m, int k)
{
	for (int i = 0; i < n; i++) {
		deleteElement(matrix[i], m, k);
	}
	m--;
}