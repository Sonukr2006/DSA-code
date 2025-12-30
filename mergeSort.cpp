#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int s, int e)
{

    int mid = (s + e) / 2;

    // leftSubArray length
    int len1 = mid - s + 1;
    // rightSubArray length
    int len2 = e - mid;

    // create Araay like subearray

    int *first = new int[len1];
    int *second = new int[len2];

    // copy All ele of array
    int mainArrayIdx = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIdx++];
    }
    mainArrayIdx = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIdx++];
    }

    // merge 2 sorted array
    int idx1 = 0;
    int idx2 = 0;
    mainArrayIdx = s;

    while (idx1 < len1 && idx2 < len2)
    {
        if (first[idx1] < second[idx2])
        {
            arr[mainArrayIdx++] = first[idx1++];
        }
        else
        {
            arr[mainArrayIdx++] = second[idx2++];
        }
    }

    /* if any one left or rignt part id greatest so */
    while (idx1 < len1)
    {
        arr[mainArrayIdx++] = first[idx1++];
    }

    // other part
    while (idx2 < len2)
    {
        arr[mainArrayIdx++] = second[idx2++];
    }

    /* heap memory realise */
    delete[] first;
    delete[] second;
}

void mergeSort(vector<int> &arr, int s, int e)
{
    // Base case of Recursion
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;

    // Left part Sorting
    mergeSort(arr, s, mid);

    // Right part Sorting
    mergeSort(arr, mid + 1, e);

    // merge of all it value in arr
    merge(arr, s, e);
}

int main()
{

    vector<int> arr = {2, 33, 4, 56, 75, 34, 76, 90, 456, 75};

    mergeSort(arr, 0, arr.size() - 1);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}