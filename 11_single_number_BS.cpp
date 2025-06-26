#include <iostream>
#include <vector>

using namespace std;

int singleNumberUsing_BS(vector<int> &nums)
{
    int size = nums.size();
    int start = 0, end = size - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        // for edge cases
        if (mid == 0 && nums[0] != nums[1])
        {
            return mid;
        }
        if (mid == (size - 1) && nums[size - 1] && nums[size + 1])
        {
            return mid;
        }

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }

        if (mid % 2 == 0)
        { // even L&R
            if (nums[mid] == nums[mid - 1])
            { // search left
                end = mid - 1;
            }
            else
            { // search right
                start = mid + 1;
            }
        }

        else
        { // odd L&R
            if (nums[mid] == nums[mid - 1])
            { // search right
                start = mid + 1;
            }
            else
            { // search left
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> vec = {1, 1, 2, 2, 3, 3, 4, 4, 8};
    int ans = singleNumberUsing_BS(vec);
    cout << ans << endl;
    return 0;
}