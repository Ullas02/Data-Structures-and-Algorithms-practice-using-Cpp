#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 3, 1};
    int size = vec.size();
    int sum = 0;

    for (int ele : vec)
    {
        sum ^= ele;
    }

    cout << "Single number in the given array is : " << sum << endl;
    return 0;
}