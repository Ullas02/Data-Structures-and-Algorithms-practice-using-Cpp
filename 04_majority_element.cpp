#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int majorityElementBruteForce(vector<int> &vec)
{
    int size = vec.size();

    for (int i = 0; i < size; i++)
    {
        int freq = 0;
        for (int j = i; j < size; j++)
        {
            if (vec[i] == vec[j])
            {
                freq++;
            }
        }
        if (freq > (size / 2))
        {
            return vec[i];
        }
    }

    return -1;
}

int sortingApproach(vector<int> &vec)
{
    int size = vec.size();
    int ans = vec[0];
    int freq02 = 1;

    sort(vec.begin(), vec.end());

    for (int i = 1; i < size; i++)
    {
        if (vec[i] == vec[i - 1])
        {
            freq02++;
        }
        else
        {
            freq02 = 1;
            ans = vec[i];
        }

        if (freq02 > (size / 2))
        {
            return ans;
        }
    }
}

int MooreVotingAlgoApproach(vector<int> &vec)
{
    int size = vec.size();
    int freq03 = 0;
    int ans = 0;

    for (int i = 0; i < size; i++)
    {
        if (freq03 == 0)
        {
            ans = vec[i];
        }
        if (vec[i] == ans)
        {
            freq03++;
        }
        else
        {
            freq03--;
        }
    }
    return ans;
}

int main()
{
    vector<int> myVec = {2, 2, 1, 1, 1, 2, 2};

    int res = majorityElementBruteForce(myVec);
    int res02 = sortingApproach(myVec);
    int res03 = MooreVotingAlgoApproach(myVec);

    cout << "Majority Element is (Brute Force): " << res << endl;
    cout << "Majority Element is (Sorting Approach): " << res02 << endl;
    cout << "Majority Element is (Moore algo Approach): " << res03 << endl;

    return 0;
}