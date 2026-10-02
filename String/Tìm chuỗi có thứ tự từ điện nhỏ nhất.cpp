#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;
// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/submissions/2073119023/?envType=daily-question&envId=2026-07-19
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    // Tạo mảng để đếm sô lần xuất hiện của kí tự đó (có thể dùng unordered_map để lưu)
    int cnt[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i] - 'a']++;
    }
    stack<char> st;
    unordered_set<char> check;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        cnt[s[i] - 'a']--;
        if (check.count(c))

            continue;
        // Đọc code => nếu stack kh trống và giá trị top lớn hơn giá trị trước nó
        // trong chuỗi gốc và số lần xuất hiện còn lại của nó phải lớn hơn 0 thì vào ưhile

        while (!st.empty() && st.top() > c && cnt[st.top() - 'a'] > 0)
        { // Test case: cbacdcbc
            // cnt[st.top() - 'a'] > 0 => có tác dụng ở chỗ
            // khi stack đã là "acd" phân từ kế là "b" đáng lẻ
            // d > b thì phải xóa "d" nhưng "d" chỉ có 1 lân xuất hiện và đã dùng hết
            // nếu xóa đi sẽ làm mất kí tự đó ( vì đề yêu cầu phải có đủ kí tự trong chuỗi)

            check.erase(st.top());
            st.pop();
        }

        st.push(c);
        check.insert(c);
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    // Đảo lại vì stack vào sau ra trước
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}