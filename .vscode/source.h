#include<iostream>
using namespace std;
//-------------------------------Q1A------------------------------------
template<typename array>
class ArrayBasics
{
	public:
	static array findMax(array A[], int i, int j)
	{
		array highest = A[i];
		for (int max = i + 1; max <= j; max++)
		{
			if (A[max] > highest)
			{
				highest = A[max];
			}
		}
		return highest;
	}
	static array findMaxPos(array A[], int i, int j)
	{
		array highest = A[i];
		int hIndex = i;
		for (int max = i + 1; max <= j; max++)
		{
			if (A[max] > highest)
			{
				highest = A[max];
				hIndex = max;
			}
		}
		return hIndex;
	}
	static array findMin(array A[], int i, int j)
	{
		array lowest = A[i];
		for (int min = i + 1; min <= j; min++)
		{
			if (A[min] < lowest)
			{
				lowest = A[min];
			}
		}
		return lowest;
	}
	static array findMinPos(array A[], int i, int j)
	{
		array lowest = A[i];
		int lIndex = i;
		for (int min = i + 1; min <= j; min++)
		{
			if (A[min] < lowest)
			{
				lowest = A[min];
				lIndex = min;
			}
		}
		return lIndex;
	}
	static void swap(array A[], int i, int j)
	{
		array temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
	static void shiftRight(int A[], int i, int j)
	{
		for (int sRight = j; sRight > i; sRight--)
		{
			A[sRight] = A[sRight - 1];
		}
	}
	static void shiftLeft(int A[], int i, int j)
	{
		for (int sLeft = i; sLeft < j; sLeft++)
		{
			A[sLeft] = A[sLeft + 1];
		}
	}
	static array* createRandomArray(int size, int min, int max)
	{
		srand(time(0));
		array* RandArray = new array[size];
		for (int gen = 0; gen < size; gen++)
		{
			RandArray[gen] = min + (rand() % (max - min));
		}
		return RandArray;
	}
	static array** createRandomMatrix(int rows, int cols, int min, int max)
	{
		srand(time(0));
		array** RandMatrix = new array*[rows];
		for (int r = 0; r < rows; r++)
		{
			RandMatrix[r] = new array[cols];
		}
		for (int genR = 0; genR < rows; genR++)
		{
			for (int genC = 0; genC < cols; genC++)
			{
				RandMatrix[genR][genC] = min + (rand() % (max - min));
			}
		}
		return RandMatrix;
	}
	static array* copyArray(array A[], int size)
	{
		array* copyArray = new array[size];
		for (int copy = 0; copy < size; copy++)
		{
			copyArray[copy] = A[copy];
		}
		return copyArray;
	}
	static array** copyMatrix(array** A, int rows, int cols)
	{
		array** copyMat = new array*[rows];
		for (int r = 0; r < rows; r++)
		{
			copyMat[r] = new array[cols];
		}
		for (int copyR = 0; copyR < rows; copyR++)
		{
			for (int copyC = 0; copyC < cols; copyC++)
			{
				copyMat[copyR][copyC] = A[copyR][copyC];
			}
		}
		return copyMat;
	}
	static array findInArray(array A[], int q, int size)
	{
		for (int find = 0; find < size; find++)
		{
			if (A[find] == q)
			{
				return find;
			}
		}
		return -1;
	}
	static array findInSortedArray(array A[], int q, int size)
	{
		int start = 0, end = size - 1;
		while (start < end)
		{
			int middle = (start + end) / 2;
			int temp = A[middle];
			if (temp < q)
			{
				start = middle + 1;
			}
			else if (temp > q)
			{
				end = middle - 1;
			}
			else if (temp == q)
			{
				return middle;
			}
		}
		return -1;
	}
	static array findFirstInSortedArray(array A[], int q, int size)
	{
		int start = 0, end = size - 1;
		while (start < end)
		{
			int middle = (start + end) / 2;
			int temp = A[middle];
			if (temp < q)
			{
				start = middle + 1;
			}
			else if (temp > q)
			{
				end = middle - 1;
			}
			else if (temp == q)
			{
				while (A[middle - 1] == q)
				{
					middle--;
				}
				return middle;
			}
		}
		return -1;
	}
};

//-------------------------------Q1B------------------------------------
//The shift right function has O(n) time complexity while the swap function has O(1) time complexity.
//So the function maxSortWithSwap is faster
template<typename array>
class ArrayUtility
{
	public:
		static void maxSortWithShiftRight(array A[], int size)
		{
			array highest;
			int hIndex;
			for (int lIndex = 0; lIndex < size; lIndex++)
			{
				hIndex = lIndex;
				highest = A[hIndex];
				for (int findMax = lIndex + 1; findMax < size; findMax++)
				{
					if (A[findMax] > highest)
					{
						highest = A[findMax];
						hIndex = findMax;
					}
				}
				ArrayBasics<array>::shiftRight(A, lIndex, hIndex);
				A[lIndex] = highest;
			}
		}
		static void maxSortWithSwap(array A[], int size)
		{
			array highest;
			int hIndex;
			for (int lIndex = 0; lIndex < size; lIndex++)
			{
				hIndex = lIndex;
				highest = A[hIndex];
				for (int findMax = lIndex + 1; findMax < size; findMax++)
				{
					if (A[findMax] > highest)
					{
						highest = A[findMax];
						hIndex = findMax;
					}
				}
				ArrayBasics<array>::swap(A, lIndex, hIndex);
			}
		}
};

//-------------------------------Q2-------------------------------------
template<typename warehouse>
class WarehouseAlgorithm 
{
	public:
		static bool hasClosePair(warehouse array[], int size, int value)
		{
			int space = size / 10;
			warehouse* tempArray = new warehouse[value - 1];
			int* timeAdded = new int[value - 1];
			for (int find = 0; find < size; find++)
			{
				if (array[find] < value)
				{
					if (tempArray[value - array[find]] == value - array[find] && find - timeAdded[value - array[find]] <= space)
					{
						delete[] tempArray;
						delete[] timeAdded;
						return true;
					}
					else
					{
						tempArray[array[find]] = array[find];
						timeAdded[array[find]] = find;
					}
				}
			}
			return false;
		}
};

//-------------------------------Q3-------------------------------------
template<typename profit>
profit maximizeProfit(int m, int n, int a[], profit p[], int s)
{
	int skipIndex = -1;
	bool skip2 = false;
	int** combinations = new int*[m];
	int** indexes = new int* [m];
	int* totalBarrels = new int [m];
	profit* totalProfit = new int [m];
	profit maxProfit = 0;
	for (int init = 0; init < m; init++)
	{
		combinations[init] = new int[n];
		indexes[init] = new int[n];
		totalBarrels[init] = 0;
		totalProfit[init] = 0;
	}
	for (int find = 0; find < m; find++)
	{
		for (int locate = 0; locate < n; locate++)
		{
			if (find != 0 && locate == skipIndex)
			{
				continue;
			}
			if (skip2)
			{
				if (find != 0 && locate == skipIndex + 1)
				{
					continue;
				}
			}
			if (totalBarrels[find] + a[locate] <= m)
			{
				combinations[find][locate] = a[locate];
				indexes[find][locate] = locate;
				totalBarrels[find] += a[locate];
				totalProfit[find] += p[locate];
			}
		}
		skipIndex++;
		if (skipIndex >= n)
		{
			skipIndex = 0;
			if (skip2)
			{
				break;
			}
			skip2 = true;
		}
	}
	for (int max = 0; max < m; max++)
	{
		if (totalProfit[max] - ((m - totalBarrels[max]) * s) > maxProfit)
		{
			maxProfit = totalProfit[max] - ((m - totalBarrels[max]) * s);
		}
	}
	for (int del = 0; del < m; del++)
	{
		delete[] combinations[del];
		delete[] indexes[del];
	}
	delete[] combinations;
	delete[] indexes;
	delete[] totalBarrels;
	delete[] totalProfit;
	return maxProfit;
}

//-------------------------------Q4A------------------------------------
template <typename booking>
void mergeBookingSchedules(booking R1[][2], int n1, booking R2[][2], int n2, int mergedSchedule[][3], int& m)
{
	m = 0;
	booking* timings = new booking[50];
	int doubleBook[50][2], doubleBook2[50][2];
	for (int init = 0; init < 50; init++)
	{
		timings[init] = 0;
		doubleBook[init][0] = 0;
		doubleBook[init][1] = 0;
		doubleBook2[init][0] = 0;
		doubleBook2[init][1] = 0;
	}
	int totalN = n1 + n2;
	for (int check = 0; check < totalN; check++)
	{
		if (check < n1)
		{
			for (int set = R1[check][0]; set < R1[check][1]; set++)
			{
				timings[set]++;
			}
			if (doubleBook[R1[check][0]][0] == 0)
			{
				doubleBook[R1[check][0]][0] = R1[check][0];
			}
			if (doubleBook[R1[check][1]][0] != 0)
			{
				doubleBook[R1[check][1]][1] = 1;
			}
			if (doubleBook2[R1[check][1]][0] == 0)
			{
				doubleBook2[R1[check][1]][0] = R1[check][1];
			}
			if (doubleBook2[R1[check][0]][0] != 0)
			{
				doubleBook2[R1[check][0]][1] = 1;
			}
		}
		else
		{
			for (int set = R2[check - n1][0]; set < R2[check - n1][1]; set++)
			{
				timings[set]++;
			}
			if (doubleBook[R2[check - n1][0]][0] == 0)
			{
				doubleBook[R2[check - n1][0]][0] = R2[check - n1][0];
			}
			if (doubleBook[R2[check - n1][1]][0] != 0)
			{
				doubleBook[R2[check - n1][1]][1] = 1;
			}
			if (doubleBook2[R2[check - n1][1]][0] == 0)
			{
				doubleBook2[R2[check - n1][1]][0] = R2[check - n1][1];
			}
			if (doubleBook2[R2[check - n1][0]][0] != 0)
			{
				doubleBook2[R2[check - n1][0]][1] = 1;
			}
		}
	}
	bool once = false;
	for (int sep = 0; sep < 49; sep++)
	{
		if (timings[sep] != 0)
		{
			if (timings[sep] == timings[sep + 1] && doubleBook[sep + 1][1] != 1 && doubleBook2[sep + 1][1] != 1)
			{
				mergedSchedule[m][0] = timings[sep];
				if (!once)
				{
					mergedSchedule[m][1] = sep;
					once = true;
				}
			}
			else if (once)
			{
				mergedSchedule[m][2] = sep + 1;
				m++;
				once = false;
			}
			else
			{
				mergedSchedule[m][1] = sep;
				mergedSchedule[m][2] = sep + 1;
				mergedSchedule[m][0] = timings[sep];
				m++;
			}
		}
	}
	delete[] timings;
}

//-------------------------------Q4B------------------------------------
template <typename booking>
void makeBookingSchedules(booking R[][2], int n1, int Schedule[50][3], int &m)
{
	m = 0;
	booking* timings = new booking[50];
	int doubleBook[50][2], doubleBook2[50][2];
	booking* make = new booking[n1];
	for (int init = 0; init < 50; init++)
	{
		timings[init] = 0;
		doubleBook[init][0] = 0;
		doubleBook[init][1] = 0;
		doubleBook2[init][0] = 0;
		doubleBook2[init][1] = 0;
	}
	for (int check = 0; check < n1; check++)
	{
		for (int set = R[check][0]; set < R[check][1]; set++)
		{
			timings[set]++;
		}
		for (int log = 1; log < n1; log *= 2)
		{
			make[log] = timings[R[check][0]] + timings[R[check][1]];
		}
		if (doubleBook[R[check][0]][0] == 0)
		{
			doubleBook[R[check][0]][0] = R[check][0];
		}
		if (doubleBook[R[check][1]][0] != 0)
		{
			doubleBook[R[check][1]][1] = 1;
		}
		if (doubleBook2[R[check][1]][0] == 0)
		{
			doubleBook2[R[check][1]][0] = R[check][1];
		}
		if (doubleBook2[R[check][0]][0] != 0)
		{
			doubleBook2[R[check][0]][1] = 1;
		}
	}
	bool once = false;
	for (int sep = 0; sep < 49; sep++)
	{
		if (timings[sep] != 0)
		{
			if (timings[sep] == timings[sep + 1] && doubleBook[sep + 1][1] != 1 && doubleBook2[sep + 1][1] != 1)
			{
				Schedule[m][0] = timings[sep];
				if (!once)
				{
					Schedule[m][1] = sep;
					once = true;
				}
			}
			else if (once)
			{
				Schedule[m][2] = sep + 1;
				m++;
				once = false;
			}
			else
			{
				Schedule[m][1] = sep;
				Schedule[m][2] = sep + 1;
				Schedule[m][0] = timings[sep];
				m++;
			}
		}
	}
	delete[] timings;
	delete[] make;
}