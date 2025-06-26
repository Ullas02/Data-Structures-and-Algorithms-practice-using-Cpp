#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(vector<int> &vec, int p, int N, int maxAllowed)
{
    int paintersUsed = 1, currentLoad = 0;
    for (int i = 0; i < N; i++)
    {
        if (vec[i] > maxAllowed)
        {
            return false;
        }

        if (currentLoad + vec[i] <= maxAllowed)
        {
            currentLoad += vec[i];
        }
        else
        {
            paintersUsed++;
            currentLoad = vec[i];
        }
    }
    return paintersUsed > p ? false : true;
}

int paintersProblem(vector<int> &vec, int painters, int N)
{
    if (N < painters)
    {
        return -1;
    }

    int sum = 0, maxVal = 0;
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        sum += vec[i];
        maxVal = max(vec[i], maxVal);
    }

    int start = maxVal, end = sum;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isValid(vec, painters, N, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> vec = {40, 30, 10, 20};
    int painters = 2;
    int numberOfBoards = vec.size();

    cout << paintersProblem(vec, painters, numberOfBoards) << endl;

    return 0;
}