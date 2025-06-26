#include <iostream>
#include <vector>

using namespace std;

void bruteForceMethod(vector<int> &vec)
{
    int n = vec.size();

    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (vec[i] == 0)
        {
            count_0++;
        }

        else if (vec[i] == 1)
        {
            count_1++;
        }

        else if (vec[i] == 2)
        {
            count_2++;
        }
    }

    int myCounter = 0;

    for (int i = 0; i < count_0; i++)
    {
        vec[myCounter] = 0;
        myCounter++;
    }

    for (int i = 0; i < count_1; i++)
    {
        vec[myCounter] = 1;
        myCounter++;
    }

    for (int i = 0; i < count_2; i++)
    {
        vec[myCounter] = 2;
        myCounter++;
    }
}

void DNF_method(vector<int> &nums)
{
    int n = nums.size();

    int l = 0, m = 0, h = n - 1;
    while (m <= h)
    {
        if (nums[m] == 0)
        {
            swap(nums[l], nums[m]);
            l++, m++;
        }
        else if (nums[m] == 1)
        {
            m++;
        }
        else
        {
            swap(nums[m], nums[h]);
            h--;
        }
    }
}

void printElements(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec = {2, 0, 2, 1, 1, 0};

    printElements(vec);

    // bruteForceMethod(vec);
    DNF_method(vec);

    printElements(vec);

    return 0;
}