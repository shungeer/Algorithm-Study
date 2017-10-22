#include "demo.h"
// 分治法实现的例子

// 求和
int sum(int a[], int n)
{
	if (n == 0) return 0;
	if (n == 1) return a[0];
	int mid = n / 2;
	return sum(a, mid) + sum(a + mid, n - mid);
}

// 求最大数
int maxnumber(int a[], int n)
{
	if (n == 1) return a[0];
	if (n == 2) return a[0] > a[1] ? a[0] : a[1];
	int mid = n / 2;
	int leftmax = maxnumber(a, mid);
	int rightmax = maxnumber(a + mid, n - mid);
	return leftmax > rightmax ? leftmax : rightmax;
}

// 二分查找
bool bsearchinstance(int a[], int start, int end, int key)
{
	if (start > end) return false;
	if (start == end) return a[start] == key;
	int mid = (start + end) / 2;
	if (a[mid] > key) return bsearchinstance(a, start, mid - 1, key);
	else if (a[mid] < key) return bsearchinstance(a, mid + 1, end, key);
	return true;
}

bool bsearch(int a[], int n, int key)
{
	return bsearchinstance(a, 0, n - 1, key);
}