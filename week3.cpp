/*Author Pooja Srivastava
  10000 integers are entered as input given in quicksort.txt
  Three functions are made PivotLast,PivotFirst,PivotMedian to change pivots
*/
#include<bits/stdc++.h>
using namespace std;
	static long long int a[10000];
	 static long long int comparisonsCount = 0;


	 // Returns first element as pivot

	long long int PivotFirst(long long int a[],long long int start,long long int end) {
		return start;
	}

	// * Returns the last element as pivot

	long long int PivotLast(long long int a[],long long int start,long long  int end) {

		// Move pivot to start index.

		long long int temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		return start;
	}

	// * Returns the median of start, end and mid as pivot

	long long int PivotMedian(long long int a[],long long int start, long long int end) {

		long long int pivotIndex = -1;

		long long int mid = ((end - start) / 2) + start;
		long long int b[3];
		b[0] = a[start];
		b[1] = a[mid];
		b[2] = a[end];

		sort(b,b+3);
		if (b[1] == a[start]) {
			pivotIndex = start;
		}else if(b[1] == a[mid]) {
			pivotIndex = mid;
		}else {
			pivotIndex = end;
		}

		// Move pivot to start index.
		int temp = a[start];
		a[start] = a[pivotIndex];
		a[pivotIndex] = temp;

		return start;
	}


	 //* Partitions the array about the pivot
	  long long int partition(long long int a[],long long int start, long long int end, long long int pivotIndex) {

		// Update comparisonsCount
		comparisonsCount += (long long int)end - start;

		// Partition
		long long int i = start;
		long long int pivot = a[pivotIndex];

		for (long long int j = start; j <= end; j++) {
			if (a[j] < pivot) {
				i++;
				long long int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}

		long long int temp = a[i];
		a[i] = pivot;
		a[pivotIndex] = temp;

		return i;
	}

	// * Quick sort
	   void sort(long long int start, long long int end,long long int a[]) {
		if (end - start == 1) {
			// Base case, no recursive calls. 2 Element, just sort them.
			if (a[start] > a[end]) {
			long long int temp = a[start];
				a[start] = a[end];
				a[end] = temp;
			}

			// Increment comparisons count by 1 as there is 1 comparison happening here.
			comparisonsCount ++;
		}else if(end <= start) {

		}
		else {
			long long int pivotIndex = PivotMedian(a,start, end);
			long long int partitionIndex = partition(a,start, end, pivotIndex);
			sort(start, partitionIndex - 1,a);
			sort(partitionIndex + 1, end,a);
		}
	}

	int main()
{
	long long int a[10000]; //= {10, 7, 8, 9, 1, 5};
	for(long long int i=0;i<10000;i++)cin>>a[i];
	long long int n = sizeof(a)/sizeof(a[0]);
	sort(0, n-1,a);

	//printArray(a, n);
	cout<<"TotalComparisons"<<" ";
	cout<<comparisonsCount<<"\n";
	printf("Sorted array: \n");
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	    return 0;
}

