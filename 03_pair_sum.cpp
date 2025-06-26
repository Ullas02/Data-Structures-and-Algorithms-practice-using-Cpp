#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    int size = vec.size();
    int target = 7;

    vector<int> res;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++) // Ensure i < j to avoid duplicate pairs
        {
            if (vec[i] + vec[j] == target)
            {
                cout << "Target matched at index : " << i << " and " << j << endl;
                res.push_back(i);
                res.push_back(j);
            }
        }
    }

    cout << "Target matched at indices : \n";
    for (int index : res)
    {
        cout << index << " ";
    }
    cout << endl;

    cout << "\nOptimized Approach for Pair Sum (using 2 pointers method):\n";

    int i = 0, j = size - 1;

    while (i < j)
    {
        int sum = vec[i] + vec[j];

        if (sum == target)
        {
            cout << "Matched index are : " << i << ", " << j << endl;
            i++;
            j--;
        }
        if (sum < target)
        {
            i++;
        }
        else if (sum > target)
        {
            j--;
        }
    }

    return 0;
}