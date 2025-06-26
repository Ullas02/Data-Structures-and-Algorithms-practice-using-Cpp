#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> vec, int M, int N, int allowedPages)
{
    int students = 1, pages = 0;
    for (int i = 0; i < N; i++)
    {
        if (vec[i] > allowedPages)
        {
            return false;
        }

        if (vec[i] + pages <= allowedPages)
        {
            pages += vec[i];
        }
        else
        {
            students++;
            pages = vec[i];
        }
    }
    return students > M ? false : true;
}

int bookAlocationProblem(vector<int> vec, int M, int N)
{

    if (M > N)
    { // if students is greater than maxBooks(shortage of books)
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += vec[i];
    }

    int start = 0, end = sum, ans = -1;

    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (isValid(vec, M, N, mid))
        { // move left to check even smaller value
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
    vector<int> vec = {2, 1, 3, 4};
    int M = 2;
    int N = vec.size();

    cout << bookAlocationProblem(vec, M, N) << endl;

    return 0;
}