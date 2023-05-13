#pragma once
#include <iostream>

class Sorting
{
private: 

	static void printArray(int a[], int n)
	{
		for (int i = 0; i < n; i++)
			std::cout<<("%d ", a[i]) << " ";
		std::cout<<("\n");
	}
public:
//BFS breadth-first search
//DFS depth-first search
//topological sort
//scc search
//dijkstra
//floyd


	static void bubble_sort(int arr[], int n)
	{
		printArray(arr, n);
		bool swapped = false;
		int tmp;
		for (int i =  n - 2; i >= 0; i--)
		{
			swapped = false;
			for (int j = 0; j <= i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swapped = true;
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
			if (!swapped) break;
		}
		printArray(arr, n);
	}

	static void insertion_sort(int arr[], int n)
	{
		printArray(arr, n);
		int j, current_value;
		for (int i = 1; i < n; i++)
		{
			current_value = arr[i];
			j = i - 1;
			while (j >= 0 && current_value < arr[j])
			{
				arr[j + 1] = arr[j];
				j--;
			}

			arr[j + 1] = current_value;
		}
		printArray(arr, n);
	}

	static void cocktail_sort_bubble(int arr[], int n)
	{
		printArray(arr, n);
		bool swapped = true;
		int tmp, start = 0, end = n - 1;
		
		while (swapped)
		{
			swapped = false;

			for (int i = start; i < end; i++)
			{
				if (arr[i] > arr[i + 1])
				{
					tmp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = tmp;
					swapped = true;
				}
			}

			if (!swapped) break;
			swapped = false;
			--end;

			for (int i = end - 1; i >= start; i--)
			{
				if (arr[i] > arr[i + 1])
				{
					tmp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = tmp;
					swapped = true;
				}
			}

			if (!swapped) break;
			++start;
		}
		printArray(arr, n);
	}

	static void selection_sort(int arr[], int n)
	{
		printArray(arr, n);
		int iMin, tmp;
		for (int i = 0; i < n - 1; i++)
		{
			iMin = i;
			for (int j =  i + 1; j < n; j++)
			{
				if (arr[iMin] > arr[j])
				{
					iMin = j;
				}
			}

			if (i != iMin)
			{
				tmp = arr[i];
				arr[i] = arr[iMin];
				arr[iMin] = tmp;
			}
		}
		printArray(arr, n);
	}

	static void cocktail_sort_selection(int arr[], int n)
	{
		printArray(arr, n);
		int tmp, iMin, iMax, start = 0, size = n;

		for (int i = start; i < size / 2 + 1; i++)
		{
			iMin = i;
			iMax = i;
			for (int j = i; j < n; j++)
			{
				if (arr[j] < arr[iMin])
				{
					iMin = j;
				}

				if (arr[j] > arr[iMax])
				{
					iMax = j;
				}
			}
			
			if (i != iMin)
			{
				tmp = arr[i];
				arr[i] = arr[iMin];
				arr[iMin] = tmp;
			}

			if (n - 1 != iMax)
			{
				tmp = arr[n - 1];
				arr[n - 1] = arr[iMax];
				arr[iMax] = tmp;
			}
			n--;
		}
		printArray(arr, size);
	}

	static void gnome_sort(int arr[], int n)
	{
		printArray(arr, n);
		int temp, index = 0;
		while (index < n)
		{
			if (index == 0) index++;
			if (arr[index] >= arr[index - 1]) index++;
			else 
			{
				index--;
				temp = arr[index];
				arr[index] = arr[index + 1];
				arr[index + 1] = temp;
			}

		}
		printArray(arr, n);
	}

	static void merge(int a[], int b[], int n, int m)
	{
		int* c = new int[n+m];
		int indexA = 0, indexB = 0;
		for (int i = 0; i < n + m; i++)
		{
			if (indexA == n) c[i] = b[indexB++];
			else if (indexB == m) c[i] = a[indexA++];
			else if (a[indexA] < b[indexB]) c[i] = a[indexA++];
			else c[i] = b[indexB++];
		}
		printArray(c, n+m);
	}

	static void merge_sort(int arr[], int n)
	{
		if (n <= 1) return;

		int j = 0, mid = n / 2, left = mid, right = n - mid;
		int* a = new int[left];
		int* b = new int[right];
		for (int i = 0; i < n; i++)
		{
			if (i < mid)
			{
				a[i] = arr[i];
			}
			else
			{
				b[j] = arr[i];
				j++;
			}
		}
		merge_sort(a, left);
		merge_sort(b, right);
		merge(a, b, left, right);
	}

	//mark natural sorted sequences
	static void natural_merge_sort(int arr[], int n)
	{


	}

	static void counting_sort(int arr[], int n)
	{

	}

	static void radix_sort(int arr[], int n)
	{

	}

	static void heapify(int arr[], int n, int i)
	{

	}

	static void heap_sort(int arr[], int n)
	{

	}

	static void binary_search(int arr[], int n)
	{

	}

	static void binary_insertion_sort(int arr[], int n)
	{

	}

	static void intro_sort(int arr[], int n)
	{

	}

	static void quick_sort(int arr[], int n)
	{

	}

	static void bucket_sort(int arr[], int n)
	{

	}
};
