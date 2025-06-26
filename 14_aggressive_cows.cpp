#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(vector<int> &vec, int cows, int N, int minAllowedDistance)
{

    int myCows = 1, lastPosition = vec[0];
    for (int i = 1; i < N; i++)
    {
        if ((vec[i] - lastPosition) >= minAllowedDistance)
        {
            myCows++;
            lastPosition = vec[i];
        }

        if (myCows == cows)
        {
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &vec, int cows, int N)
{

    sort(vec.begin(), vec.end());
    int start = 1, end = vec[N - 1] - vec[0], ans = vec[0];

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isValid(vec, cows, N, mid))
        { // search for possible max distance, i.e. go right
            ans = mid;
            start = mid + 1;
        }
        else
        { // else search left
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> vec = {1, 2, 8, 4, 9};
    int cows = 3;
    int N = vec.size();

    cout << aggressiveCows(vec, cows, N) << endl;

    return 0;
}