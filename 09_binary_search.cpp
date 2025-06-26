#include <iostream>
#include <vector>

using namespace std;

int binarySearch_normal(vector<int> arr, int target)
{
    int n = arr.size();
    int ans = -1;

    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (target == arr[mid])
        {
            ans = mid;
            break;
        }

        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
    }
    return ans;
}

int binarySearch_recurssive(vector<int> arr, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target == arr[mid])
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            return binarySearch_recurssive(arr, target, mid + 1, end);
        }
        else if (target < arr[mid])
        {
            return binarySearch_recurssive(arr, target, start, mid - 1);
        }
    }
    return -1;
}

int main()
{
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // odd
    int target1 = 12;

    int ans1 = binarySearch_normal(arr1, target1);
    cout << ans1 << endl;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // even
    int target2 = 3;

    int ans2 = binarySearch_normal(arr2, target2);
    cout << ans2 << endl;

    cout << endl;

    int ans3 = binarySearch_recurssive(arr2, 123, 0, arr2.size() - 1);
    cout << ans3 << endl;

    return 0;
}