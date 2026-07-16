#include <bits/stdc++.h>
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
using namespace std;
// Hàm check xem với với khối lượng mid đó thì sẽ vẩn chuyển hết hàng trong bao nhiu ngày
// Nếu số ngày vận chuyện xong "bé hơn" số ngày đề cho thì giảm khối lượng ( hi = mid - 1 ) để tìm xem có thể vận chuyển dài ngày hơn dc kh
// Nếu số ngày vận chuyển xong "lớn hơn" số ngày đề cho thì tăng khối lượng( lo = mid + 1 )
bool check(int days, int mid, vector<int> &weights)
{
    int sum = 0;
    int dayTmp = 1;
    for (int i = 0; i < weights.size(); i++)
    {
        if (sum + weights[i] <= mid)
        {
            sum += weights[i];
        }
        else
        {
            sum = weights[i];
            dayTmp++;
        }
    }
    return dayTmp <= days;
}

int binarySearch(vector<int> &weights, int days, int sum, int maxWei)
{
    int lo = maxWei;
    int hi = sum;
    int ans = sum;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(days, mid, weights))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size, day;
    cin >> size >> day;
    vector<int> weights(size);
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> weights[i];
        sum += weights[i];
    }
    int maxWei = *max_element(weights.begin(), weights.end());

    cout << binarySearch(weights, day, sum, maxWei);

    return 0;
}