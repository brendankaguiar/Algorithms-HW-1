#include <iostream>
using namespace std;
#include <string>
#define SIZE 6
//Question 1
void load_array(int target[]);
void print_array(int target[]);
bool is_set(int target[]);

//Not part of homework, but relavant to course material
void rand_quick_sort(int target [], int p, int r);
int rand_partition(int target[], int p, int r);
int partition(int target[], int p, int r);
void exchange(int& a, int& b);
void find_min_max(int target[], int& min, int& max);
int main()
{
	//Question 1
	int intArr[SIZE];
	bool enigmaBool = false;
	load_array(intArr);
	enigmaBool = is_set(intArr);
	if (enigmaBool)
	{
		// cout << "Set : ";
		//print_array(intArr);
	}
	else
	{
		cout << "List : ";
		print_array(intArr);
	}
	//Question 2
	int min, max;
	int testArr[] = { 1, 4, 9, 3, 4, 9, 5, 6, 9, 3, 7 };
	print_array(testArr);
	find_min_max(testArr, min, max);
	cout << "Minimum Value : " << min << endl;
	cout << "Maximum Value : " << max << endl;
	//Quick Sort Tests
	//rand_quick_sort(intArr, 0, SIZE - 1);
	//cout << "Sorted : ";
	//print_array(intArr);

	return 0;
}

//Question 1
bool is_set(int target[])
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (target[i] == target[j])
				return false;
		}
	}
	return true;
}
void load_array(int target[])
{
	std::cout << "Loading Array" << std::endl;
	for (int i = 0; i < SIZE; i++)
		target[i] = rand() % 20 + 1;     // range 1 to 20
	std::cout << "Array loaded successfully." << std::endl;
} 

void print_array(int target[])
{
	for (int i = 0; i < SIZE; i++)
		cout << target[i] << " ";
	cout << endl;
}

void find_min_max(int target[], int& min, int& max)
{
	if (SIZE % 2 == 0)
	{
		if (target[0] < target[1])
		{
			min = target[0];
			max = target[1];
		}
		else
		{
			min = target[1];
			max = target[0];
		}
		for (int i = 2; i < SIZE; i++)
		{
			if (target[i] < target[i + 1])
			{
				if (target[i] < min)
					min = target[i];
				if (target[i + 1] > max)
					max = target[i + 1];
			}	
			else
			{
				if (target[i + 1] < min)
					min = target[i + 1];
				if (target[i] > max)
					max = target[i];
			}
			i++;
		}
	}
	else
	{

	}
}


// randomization increases odds of a better pivot
void rand_quick_sort(int target[], int p, int r)
{
	if (p < r)
	{
		int q = rand_partition(target, p, r);
		rand_quick_sort(target, p, q);
		rand_quick_sort(target, q + 1, r);
	}
}
//Exchanges first element with element from a random index
int rand_partition(int target[], int p, int r)
{
	int i = rand() % (r - p) + p;
	exchange(target[p], target[i]);
	return partition(target, p, r);
}
int partition(int target[], int p, int r)
{
	int x = target[p];
	int i = p;
	int j = r;
	while (true)
	{
		while (target[j] > x)
			j--;
		while (target[i] < x)
			i++;
		if (i < j)
			exchange(target[i], target[j]);
		else
			return j;
	}
}
void exchange(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
