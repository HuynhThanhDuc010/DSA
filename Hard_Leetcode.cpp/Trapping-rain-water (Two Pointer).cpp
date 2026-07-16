#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/trapping-rain-water/description/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int height_size;
    cin >> height_size;
    vector<int> height(height_size);
    for (int i = 0; i < height_size; i++)
    {
        cin >> height[i];
    }
    int left = 0;
    int right = height_size - 1;
    int Max_left = 0;
    int Max_right = 0;
    long long tong = 0;

    while (left < right)
    {
        if (height[left] < height[right])
        {
            if (height[left] >= Max_left)
            {
                Max_left = height[left];
            }
            else
            {
                tong += Max_left - height[left];
            }
            left++;
        }
        else
        {
            if (height[right] >= Max_right)
            {
                Max_right = height[right];
            }
            else
            {
                tong += Max_right - height[right];
            }
            right--;
        }
    }
    cout << tong;
    return 0;
}