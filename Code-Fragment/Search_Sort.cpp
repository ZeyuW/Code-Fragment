/*
 * Simple seach/sort algorithms from EECS 281
 */


#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;


void swap(double &a, double &b)
{
    double temp;
    temp = a;
    a = b;
    b = temp;
}



int BinarySearch(double a[], int val, int num)
// num is the number of elements in array
// Time complexity: O(logn)
{
    if (a == NULL)
        return -1;
    int right = num - 1;
    int left = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        
        
        if (val == a[mid])
            return mid;
        
        if (val < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}



void BubbleSort(double a[], int num)
// non-adaptive version: about n^2/2 comparisons. i.e. (n + (n-1) + ... + 1)
//      and about n^2/2 swaps worst/best/average case
// adaptive version: about n^2/2 comparisons.
//      about n swaps (as few as 0) in best case
// adaptive version may finish quickly if input array is almost sorted O(n)
// Time complexity: O(n^2)
{
    int left = 0;
    int right = num;
    // bool swapped = false;
    for (int i = left; i < right; i++)
    {
        for (int j = right - 1; j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                // swapped = true;
                swap(a[j - 1], a[j]);
            }
        }
        // if (!swapped)
           // break;
    }
}


void SelectionSort(double a[], int num)
// ** advantage: minimal copying of items ** disadvantage: theta(n^2) time
// non-adaptive version: about n^2/2 comparisons,
//      and n - 1 swaps in best, average, worst cases
// adaptive version: n - 1 in worst case, 0 swaps best case
{
    int right = num;
    
    for (int i = 0; i < right; i++)
    {
        int min = i;
        for (int j = i + 1; j < right; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        // if (min != i)
        {
            swap(a[i], a[min]);
        }
    }
}




void InsertionSort(double a[], int num)
// n^2/2 comparisons; n^2/2 swaps worst case; n^2/4 swaps average
{
    for (int i = 1; i < num; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
            }
        }
    }
}


void InsertionSortNew(double a[], int num)
// ** Disadvantge: O(n^2)
// adaptive: n^2/2 comparisons worst case; n^2/4 comparisons avg case;
//      n^2/4 swaps avg case; n^2/2 swaps worst case
{
    double v;
    for (int i = num - 1; i > 0; i--)
    {
        if (a[i - 1] > a[i])
        {
            swap(a[i - 1], a[i]);
        }
    }
    
    for (int i = 2; i < num; i++)
    {
        v = a[i]; int j = i;
        while (v < a[j - 1])
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = v;
    }
}



/************* Heap Sort **************/
// k = 0, 1, 2, ..., heapSize-1 for heap[k] indicates changing index
// num = heapSize (absolute value)
// modified version of original heapsort


void fixUp(double heap[], int k)
// complexity: ??? O(...)
{
    while(k > 0 && heap[k] > heap[(k - 1) / 2])
    {
        swap(heap[k], heap[(k - 1) / 2]);
        k = (k - 1) / 2;
    }
}

void fixDown(double heap[], int heapSize, int k)
{
    while (2 * (k + 1) <= heapSize)
    {
        int j = 2 * k + 1;
        if (j < heapSize && heap[j] < heap[j + 1])
            j++;
        if (heap[k] >= heap[j])
            break;
        swap(heap[k], heap[j]);
        k = j;
    }
}

// pQ 利用 heap 执行insert and delete:
/*
void insert(double newItem)
{
    N += 1;
    heap[N] = newItem;
    fixUp(heap, N);
}
 
void getMax()
{
    swap(heap[1], heap[N]);
    fixDown(heap, N - 1, 1);
    return heap[N--];
}
 
*/

void buildHeap(double heap[], int num)
{
    int start = num / 2 - 1;
    
    while (start >= 0)
    {
        fixDown(heap, num, start);
        start--;
    }
}


void heapSort(double heap[], int num)
{
    buildHeap(heap, num);
    for (int i = num - 1; i >= 1; --i)
    {
        swap(heap[i], heap[0]);
        fixDown(heap, i - 1, 0);
    }
}



/********* Merge Sort **********/

/* 
 * Algorithm MergeSort(array)  - O(n log n)
 *     MergeSort(left half)
 *     MergeSort(right half)
 *     merge(left half, right half)
 *
 */

/*
 * Merge:
 * Builds c[] by:
 *   – appending smallest remaining item from a[] or b[] onto c[]
 *   – until all items from both a[] and b[] are in c[]
 * O(size_a + size_b) assuming a[] and b[] are sorted
 */
void mergeAB(Item c[], Item a[], int size_a, Item b[], int size_b) {
    for (int i = 0, j = 0, k = 0; k < size_a + size_b; k++){
        if (i == size_a) c[k] = b[j++];
        else if (j == size_b) c[k] == a[i++];
        else{
            c[k] = (b[j] <= a[i]) ? b[j++] : a[i++];
        }
    } // end for
}

void merge(Item a[], int left, int mid, int right) {
    int size = right - left + 1;
    vector<Item> c(size);
    
    for (int i = left, j = mid + 1, k = 0; k < size; k++){
        if (i > mid) c[k] = a[j++];
        else if (j > right) c[k] = a[i++];
        else c[k] = (a[i] <= a[j]) ? a[i++] : a[j++];
    }
    
    // copy c back into a[]
    copy(c.begin(), c.end(), &a[left]);
}

// Merge Sort
void mergesort(Item a[], int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergesort(a, left, mid);
    mergesort(a, mid + 1, right);
    merge(a, left, mid, right);
}



/*
int main()
{
    double array[] = {1, 4, 2, 10, 5, 66, 100, 0};
    
    //sort(array, array + 8);
    // This sort is included in <algorithm>
    
    //BubbleSort(array, 8);
    
    //SelectionSort(array, 8);
    
    // InsertionSortNew(array, 8);
    
    
    heapSort(array, 8);
    
    // print the sorted array
    for (int i = 0; i < 8; i++)
    {
        cout<<array[i]<<"  ";
    }
    cout<<endl;
    
    cout<<BinarySearch(array, 5, 8)<<endl;
    
    return 0;
}
*/