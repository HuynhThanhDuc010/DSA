#include <bits/stdc++.h>
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Có thể dùng Two Pointer
using namespace std;
int Binary(vector<int> &numbers, int x, int next)
{
    int left = 0;
    int right = numbers.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (numbers[mid] == x && mid != next)
        {
            return mid;
        }
        else if (numbers[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size;
    cin >> size;
    vector<int> numbers(size);
    for (int i = 0; i < size; i++)
    {
        cin >> numbers[i];
    }
    int target;
    cin >> target;
    int n = numbers.size();
    bool check = true;
    int i = 0;
    int j = 0;
    while (check && i < n)
    {
        int x = target - numbers[i];
        int kq = Binary(numbers, x, i);
        if (kq != -1)
        {
            j = kq;
            check = false;
        }
        i++;
    }
    cout << i << " " << j + 1;
    return 0;
}