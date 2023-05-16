#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Sorting
{
private: 

	static void printArray(int a[], int n);
	static void count_sort_exp(int arr[], int n, int exp);
	static int getMax(int arr[], int n);
	static int partition(int arr[], int low, int high);

	/// <summary>
	/// best Omega()
	/// average Theta()
	/// worst Omicron()
	/// space complexity Omicron(1)
	/// </summary>
	static void heapify(int arr[], int n, int i);

public:
//topological sort
//scc search

	/// <summary>
	/// best Omega(n)
	/// average Theta(n^2)
	/// worst Omicron(n^2)
	/// space complexity Omicron(1)
	/// </summary>
	static void bubble_sort(int arr[], int n);

	/// <summary>
	/// best Omega(n)
	/// average Theta(n^2)
	/// worst Omicron(n^2)
	/// space complexity Omicron(1)
	/// </summary>
	static void insertion_sort(int arr[], int n);

	/// <summary>
	/// best Omega()
	/// average Theta()
	/// worst Omicron()
	/// space complexity Omicron()
	/// </summary>
	static void cocktail_sort_bubble(int arr[], int n);

	/// <summary>
	/// best Omega(n^2)
	/// average Theta(n^2)
	/// worst Omicron(n^2)
	/// space complexity Omicron(1)
	/// </summary>
	static void selection_sort(int arr[], int n);
	
	/// <summary>
	/// best Omega()
	/// average Theta()
	/// worst Omicron()
	/// space complexity Omicron()
	/// </summary>
	static void cocktail_sort_selection(int arr[], int n);
	
	/// <summary>
	/// best Omega()
	/// average Theta()
	/// worst Omicron()
	/// space complexity Omicron()
	/// </summary>
	static void gnome_sort(int arr[], int n);
	
	/// <summary>
	/// best Omega()
	/// average Theta()
	/// worst Omicron()
	/// space complexity Omicron(1)
	/// </summary>
	static void merge(int a[], int b[], int n, int m);

	static void merge_arr(int arr[], int l, int m, int r);

	/// <summary>
	/// best Omega(nlog(n))
	/// average Theta(nlog(n))
	/// worst Omicron(nlog(n))
	/// space complexity Omicron(n)
	/// </summary>
	static void merge_sort(int arr[], int l, int r);

	/// <summary>
	///marks natural sorted sequences
	/// best Omega()
	/// average Theta()
	/// worst Omicron(n)
	/// space complexity Omicron()
	/// </summary>
	static void natural_merge_sort(int arr[], int n);

	/// <summary>
	/// best Omega(n + k)
	/// average Theta(n + k)
	/// worst Omicron(n + k)
	/// space complexity Omicron(n + k)
	/// </summary>
	static void count_sort(int arr[], int n);

	/// <summary>
	/// best Omega(nk)
	/// average Theta(nk)
	/// worst Omicron(nk), k - number of bits needed per data
	/// space complexity Omicron(n + k)
	/// </summary>
	static void radix_sort(int arr[], int n);

	/// <summary>
	/// best Omega(nlog(n))
	/// average Theta(nlog(n))
	/// worst Omicron(nlog(n))
	/// space complexity Omicron(1)
	/// </summary>
	static void heap_sort(int arr[], int n);

	/// <summary>
	/// best Omega(log(n))
	/// average Theta(log(n))
	/// worst Omicron(log(n))
	/// space complexity Omicron(1)
	/// </summary>
	static int binary_search(int arr[], int low, int high, int v);

	/// <summary>
	/// best Omega()
	/// average Theta()
	/// worst Omicron()
	/// space complexity Omicron()
	/// </summary>
	static void binary_insertion_sort(int arr[], int n);

	/// <summary>
	/// best Omega()
	/// average Theta()
	/// worst Omicron()
	/// space complexity Omicron()
	/// </summary>
	static void intro_sort(int arr[], int n);

	/// <summary>
	/// best Omega(nlog(n))
	/// average Theta(nlog(n))
	/// worst Omicron(n^2)
	/// space complexity Omicron(n)
	/// </summary>
	static void quick_sort(int arr[], int low, int high);

	/// <summary>
	/// best Omega(n + k)
	/// average Theta(n + k)
	/// worst Omicron(n^2)
	/// space complexity Omicron(n*k). k - buckets
	/// </summary>
	static void bucket_sort(int arr[], int n);

	//not correct place, but eh.. the archi is trash anyways
	void MMult(int a[10][15], int b[15][7], int c[10][7]);
};
