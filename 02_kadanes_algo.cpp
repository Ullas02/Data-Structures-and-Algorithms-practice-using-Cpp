#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    int size = vec.size();

    cout << "Printing sub-arrays:\n";

    for (int start = 0; start < size; start++)
    {
        for (int end = start; end < size; end++)
        {
            for (int i = start; i <= end; i++)
            {
                cout << vec[i];
            }
            cout << " ";
        }
        cout << "\n";
    }

    cout << endl;

    cout << "Brute force approach for max subarray:\n";
    int maxSum = 0;

    for (int start = 0; start < size; start++)
    {
        int currSum = 0;
        for (int end = start; end < size; end++)
        {
            currSum += vec[end];
            maxSum = max(maxSum, currSum);
        }
    }

    cout << "(Brute force)Max sum is : " << maxSum << endl;

    cout << endl;

    cout << "Optimized approach (Kadane's algorithm):\n";

    int maxSum02 = 0;
    int curSum02 = 0;

    for (int value : vec)
    {
        curSum02 += value;
        maxSum02 = max(maxSum02, curSum02);

        if (maxSum02 < 0)
        {
            curSum02 = 0;
        }
    }

    cout << "(Kadane's algorithm) Max sum is : " << maxSum02 << endl;

    return 0;
}