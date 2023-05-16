#include "Sorting.h"

void Sorting::printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << ("%d ", a[i]) << " ";
	std::cout << ("\n");
}

void Sorting::count_sort_exp(int arr[], int n, int exp)
{
	int* sorted = new int[n];
	int* count = new int[10] {0};
	for (int i = 0; i < n; i++)
	{
		count[(arr[i] / exp) % 10]++;
	}
	for (int i = 1; i < 10; i++)
	{
		//store last occurence of elem i
		count[i] += count[i - 1];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		sorted[count[(arr[i] / exp) % 10] - 1] = arr[i];
		--count[(arr[i] / exp) % 10];
	}

	for (int i = 0; i < n; i++)
		arr[i] = sorted[i];
}

int Sorting::getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

int Sorting::partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int idx = low - 1;
	for (int i = low; i <= high - 1; i++)
	{
		if (arr[i] < pivot)
		{
			idx++;
			std::swap(arr[idx], arr[i]);
		}
	}

	std::swap(arr[idx + 1], arr[high]);
	return idx + 1;
}

void Sorting::heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		int tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;

		heapify(arr, n, largest);
	}
}

void Sorting::bubble_sort(int arr[], int n)
{
	printArray(arr, n);
	bool swapped = false;
	int tmp;
	for (int i = n - 2; i >= 0; i--)
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

void Sorting::insertion_sort(int arr[], int n)
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

void Sorting::cocktail_sort_bubble(int arr[], int n)
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

void Sorting::selection_sort(int arr[], int n)
{
	printArray(arr, n);
	int iMin, tmp;
	for (int i = 0; i < n - 1; i++)
	{
		iMin = i;
		for (int j = i + 1; j < n; j++)
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

void Sorting::cocktail_sort_selection(int arr[], int n)
{
	printArray(arr, n);
	int jMin, jMax, size = n;

	for (int i = 0; i < size / 2 + 1 ; i++)
	{
		jMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[jMin])
			{
				jMin = j;
			}
		}

		if (i != jMin)
		{
			std::swap(arr[i], arr[jMin]);
		}

		jMax = n - 1;
		for (int j = 0; j < n; j++)
		{
			if (arr[j] > arr[jMax])
			{
				jMax = j;
			}
		}

		if (n - 1 != jMax)
		{
			std::swap(arr[n - 1], arr[jMax]);
		}
		n--;
	}
	printArray(arr, size);
}

void Sorting::gnome_sort(int arr[], int n)
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

void Sorting::merge(int a[], int b[], int n, int m) {
	int* c = new int[n + m];
	int indexA = 0, indexB = 0;
	for (int i = 0; i < n + m; i++) {
		if (indexA == n) c[i] = b[indexB++];
		else if (indexB == m) c[i] = a[indexA++];
		else if (a[indexA] < b[indexB]) c[i] = a[indexA++];
		else c[i] = b[indexB++];
	}
	printArray(c, n + m);
}

void Sorting::merge_arr(int arr[], int l, int m, int r) {
	int i, j, k;
	int sz1 = m - l + 1;
	int sz2 = r - m;
	int *L = new int[sz1],
		*R = new int[sz2];

	for (i = 0; i < sz1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < sz2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; j = 0; k = l; // why l?
	while (i < sz1 && j < sz2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i++];
		}
		else {
			arr[k] = R[j++];
		}
		k++;
	}

	while (i < sz1) {
		arr[k++] = L[i++];
	}

	while (j < sz2) {
		arr[k++] = R[j++];
	}
}

void Sorting::merge_sort(int arr[], int l, int r) {
	if (l < r) {
		int mid = l + (r - l) / 2;
		merge_sort(arr, l, mid);
		merge_sort(arr, mid + 1, r);

		merge_arr(arr, l, mid, r);
	}

	if (l == 0)
		printArray(arr, r + 1);
}

void Sorting::natural_merge_sort(int arr[], int n) {
	int *starts = new int[n + 1];
	int runCnt = 0;
	starts[0] = 0;
	
	for (int i = 1; i <= n; i++) {
		if (i == n || arr[i] < arr[i - 1])
			starts[++runCnt] = i;
	}

	while (runCnt > 1) {
		int newRunCnt = 0;

		for (int i = 0; i < runCnt - 1; i += 2) {
			merge_arr(arr, starts[i], starts[i + 1] - 1, starts[i + 2] - 1);
			starts[newRunCnt++] = starts[i];
		}

		if (runCnt % 2 == 1) {
			starts[newRunCnt++] = starts[runCnt - 1];
		}

		starts[newRunCnt] = n;
		runCnt = newRunCnt;
	}

	printArray(arr, n);
}

void Sorting::count_sort(int arr[], int n) {
	printArray(arr, n);
	
	int range = getMax(arr, n);
	int* sorted = new int[n];
	int* count = new int[range + 1] {0};
	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}
	for (int i = 1; i <= range; i++) {
		//store last occurence of elem i
		count[i] += count[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		sorted[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}
	
	printArray(sorted, n);
}

void Sorting::radix_sort(int arr[], int n) {
	printArray(arr, n);
	int mx = getMax(arr, n);

	for (int exp = 1; mx / exp > 0; exp *= 10) {
		count_sort_exp(arr, n, exp);
	}
	printArray(arr, n);
}

void Sorting::heap_sort(int arr[], int n) {
	printArray(arr, n);
	//start from non-leaf
	for (int i = n/2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	for (int i = n - 1; i >= 0; i--) {
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;

		heapify(arr, i, 0);
	}
	printArray(arr, n);
}

int Sorting::binary_search(int arr[], int low, int high, int v) {
	if (high <= low)
		return (v > arr[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (v = arr[mid])
		return mid + 1;

	if (v > arr[mid])
		return binary_search(arr, mid + 1, high, v);

	return binary_search(arr, low, mid - 1, v);
	/*while (low <= high)
	{
		int mid = low + (high - 1) / 2;

		if (arr[mid] == v)
			return mid;

		if (arr[mid] < v)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return -1;*/
}

void Sorting::binary_insertion_sort(int arr[], int n) {
	int loc, j, k, selected;
	for (int i = 1; i < n; ++i) {
		j = i - 1;
		selected = arr[i];
		loc = binary_search(arr, 0, j, selected);

		while (j >= loc) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = selected;
	}
	printArray(arr, n);
}

void Sorting::intro_sort(int arr[], int n)
{

}

void Sorting::quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pIdx = partition(arr, low, high);

		quick_sort(arr, low, pIdx - 1);
		quick_sort(arr, pIdx + 1, high);
	}
	printArray(arr, high + 1);
}

void Sorting::bucket_sort(int arr[], int n)
{
	printArray(arr, n);
	std::vector<int>* buckets = new std::vector<int>[n];
	int max = getMax(arr, n);

	for (int i = 0; i < n; i++)
	{
		int idx = (n * arr[i])/( max + 1);
		buckets[idx].push_back(arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		std::sort(buckets[i].begin(), buckets[i].end());
	}

	int index = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < buckets[i].size(); j++)
		{
			arr[index++] = buckets[i][j];
		}
	}
	printArray(arr, n);
}