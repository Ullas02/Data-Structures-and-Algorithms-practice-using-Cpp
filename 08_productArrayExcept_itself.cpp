#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf_bruteForce(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);
    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                product *= nums[j];
            }
        }
        ans[i] = product;
    }
    return ans;
}

vector<int> productExceptSelf_prefixSuffix_moreSpace(vector<int> &nums)
{
    int n = nums.size();

    vector<int> ans(n, 1);
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);

    // for prefix
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // for suffix
    for (int j = n - 2; j >= 0; j--)
    {
        suffix[j] = suffix[j + 1] * nums[j + 1];
    }

    for (int i = 0; i < n; i++)
    {
        ans[i] = prefix[i] * suffix[i];
    }
    return ans;
}

vector<int> productExceptSelf_prefixSuffix_lessSpace(vector<int> &nums)
{
    int n = nums.size();

    vector<int> ans(n, 1);

    // for prefix
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    // for suffix
    int suffix = 1;
    for (int j = n - 2; j >= 0; j--)
    {
        suffix *= nums[j + 1];
        ans[j] *= suffix;
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};

    vector<int> myAns1 = productExceptSelf_bruteForce(nums);
    vector<int> myAns2 = productExceptSelf_prefixSuffix_moreSpace(nums);
    vector<int> myAns3 = productExceptSelf_prefixSuffix_lessSpace(nums);

    for (int i : myAns1)
    {
        cout << i << " ";
    }

    cout << "\n";

    for (int i : myAns2)
    {
        cout << i << " ";
    }

    cout << "\n";

    for (int i : myAns3)
    {
        cout << i << " ";
    }

    return 0;
}