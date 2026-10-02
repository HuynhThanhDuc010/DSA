#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/description/?envType=daily-question&envId=2026-08-08
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string word1, word2;
    cin >> word1 >> word2;

    int n = word1.size(), m = word2.size();
    // Dùng Suffix để tìm dò vị trí cuối cùng của phần tử i của word2 trong word1
    vector<int> suf(m + 1);
    suf[m] = n;
    for (int i = m - 1; i >= 0; i--)
    {
        suf[i] = suf[i + 1] - 1;
        // Dò xem nếu kí tự suf[i] của word1 chưa bằng kí tự word2 thì lùi tiếp tục để tìm
        while (suf[i] >= 0 && word1[suf[i]] != word2[i])
            suf[i]--;
    }
    vector<int> ans;
    int i = 0;
    int j = 0;
    bool check = false;
    while (i < n && j < m)
    {
        if (word1[i] == word2[j])
        {
            ans.push_back(i);
            i++;
            j++;
        }
        // Nếu chưa vị trí nào đc sửa và vị trí muốn nhất có thể cập nhật của kí tự tiếp theo lớn hơn hoặc bằng i+1(là vị trí tiếp theo dài về cuối)
        // Nói cách khác khoản cách hiện tại đủ án toàn để cập nhật nếu vị trí cập nhật của giá trị tiếp theo nằm ở trên vị trí cạp nhật cảu giá trị hiện tại
        else if (!check && suf[j + 1] >= i + 1)
        {
            ans.push_back(i);
            check = true;
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    // Nếu không chạy hết word2 mà while đã dừng thì kh thể cập nhật thỏa yêu cầu
    if (j < m)
    {
        cout << "[]";
        return 0;
    }
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}