#include <iostream>

using namespace std;

int compute_x_power_n(int x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    if (x == -1 && (n % 2 == 0))
        return 1;
    if (x == -1 && (n % 2 != 0))
        return -1;

    int binaryForm = n;
    int ans = 1;

    if (n < 0)
    {
        x = (1 / x);
        binaryForm = -binaryForm;
    }

    while (binaryForm > 0)
    {
        if (binaryForm % 2 == 1)
        {
            ans *= x;
        }
        x *= x;
        binaryForm /= 2;
    }
    return ans;
}

int main()
{
    int x = 3, n = 5;
    int res = compute_x_power_n(x, n);
    cout << "Result = " << res << endl;
    return 0;
}