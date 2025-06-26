#include <iostream>
#include <vector>

using namespace std;

int maxAreaBruteForce(vector<int> &height)
{
    int n = height.size();
    int weight = 0, currHeight = 0;
    int maxWater = 0;
    int currWater = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            weight = j - i;
            currHeight = min(height[i], height[j]);
            currWater = weight * currHeight;
            maxWater = max(maxWater, currWater);
        }
    }

    return maxWater;
}

int maxArea_2_PointerApproach(vector<int> &height)
{
    int n = height.size();
    int weight = 0, currHeight = 0;
    int maxWater = 0;
    int currWater = 0;

    int lp = 0, rp = n - 1;

    while (lp < rp)
    {
        weight = rp - lp;
        currHeight = min(height[lp], height[rp]);
        currWater = weight * currHeight;

        maxWater = max(maxWater, currWater);

        height[lp] < height[rp] ? lp++ : rp--;
    }

    return maxWater;
}

int main()
{
    vector<int> water = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int ans1 = maxAreaBruteForce(water);
    cout << ans1 << endl;

    cout << "----------------------------------------\n";

    int ans2 = maxArea_2_PointerApproach(water);
    cout << ans2 << endl;

    return 0;
}