#include <iostream>
#include <vector>

using namespace std;

vector<int> A = {1, 2, 3, 0, 0, 0};
vector<int> B = {2, 5, 6};
// Final output should be A : {1,2,2,3,5,6}

int m = A.size() - B.size();
int n = B.size();

void merge_of_two_sorted_array()
{
    int i = m - 1, j = n - 1, index = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (A[i] >= B[j])
        {
            A[index] = A[i];
            i--, index--;
        }
        else
        {
            A[index] = B[j];
            j--, index--;
        }
    }

    // important
    while (j >= 0)
    {
        A[index--] = B[j--];
    }
}

void print_array()
{
    for (int i : A)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Result : \n";
    merge_of_two_sorted_array();
    print_array();
    return 0;
}