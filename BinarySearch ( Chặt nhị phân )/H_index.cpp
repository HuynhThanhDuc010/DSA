#include <bits/stdc++.h>
// #include "lib/debug.cpp"
// https://leetcode.com/problems/h-index-ii/
using namespace std;
// Ý tưởng: Đặt left = 1 và right = giá trị max trong mảng.
// Nạp mid vào Check() để lấy được vị trị index của phần từ đầu tiên
// lớn hơn hoặc bằng mid (k).

// Vì yêu cầu đề gồm : Chỉ số tối đa của h
// nhưng phải có ít nhất h quyển
// và số lượt trích dẫn của mỗi quyển phải ít nhất h lượt

// Điều kiện: Nếu số quyển có trích dẫn ít nhất là mid >= mid
// Thì thu left = mid + 1 để tìm h_index lớn hơn (nếu thoải dk)
// Ngược lại thu right

int Check(vector<int> &citations, int k)
{
    auto x = lower_bound(citations.begin(), citations.end(), k);
    int idx = distance(citations.begin(), x);
    return idx;
}
int Binary(vector<int> &citations)
{

    int ans = 0;
    int lo = 1;
    int hi = citations[citations.size() - 1];
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if ((citations.size() - Check(citations, mid)) >= mid)
        {

            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> citations(n);
    for (int i = 0; i < n; i++)
    {
        cin >> citations[i];
    }
    cout << Binary(citations);

    return 0;
}