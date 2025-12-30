#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            cout << "i : " << i << " j : "<< j << endl;
            nums1[k++] = nums1[i++];
        }
        else
        {
            if(nums2[j] < nums1[i]){
                nums1[k++] = nums2[j++];
            }
        }
    }
    cout << endl;
    while (i < m)
    {
        nums1[k++] = nums1[i++];
    }
    while (j < n)
    {
        nums1[k++] = nums2[j++];
    }
    for (int &val : nums1)
    {
        cout << val << " ";
    }
    cout << endl;
    
}

int main()
{
    int m = 3, n = 3;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

     merge(nums1, m, nums2, n);

    return 0;
}