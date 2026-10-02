#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;
// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/?envType=daily-question&envId=2026-09-17
int main()
{ // Ý tưởng: Dùng một vector<int> best để lưu đoạn có độ dài nhỏ nhất theo mỗi
  // gặp đoạn có tổng là target

    // Declare variable:
    // 'left' để giữ vị trí đầu mỗi mảng con khi kiểm tra (để lấy độ dài left -right +1)
    // 'minlenght' để luôn cập nhật và gán độ dài của đoạn con bé nhất cho best[i]
    // 'ans = INT_MAX' vì đề bài là tìm bé nhất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // Lưu Best (độ dài đoạn bé nhất bằng target)
    // từ i đến left -1
    vector<int> best(n, INT_MAX);
    int left = 0, sum = 0, minlenght = INT_MAX;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        // Xử lí nếu sum > target thì trừ phần từ cuối ở đoán đó
        // và tăng left lên theo mỗi giá trị đc trừ đi cho đến khi
        // sum <=left;
        while (sum > target)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == target)
        {
            int curlenght = i - left + 1;
            // Check xem trước đó đã có đoạn nào bằng target kh để ghép cặp
            if (left > 0 && best[left - 1] != INT_MAX)
            {
                // Ghép cộng độ dài 2 đoạn
                ans = min(ans, curlenght + best[left - 1]);
            }
            // Giữ Best nhỏ nhất ( Đoạn nhỏ nhất bằng target)

            minlenght = min(minlenght, curlenght);
        }
        // Assign a segment để khi gặp đoạn mới vẫn ghép với
        // độ dài đoạn nhỏ nhất
        best[i] = minlenght;
    }
    cout << (ans == INT_MAX ? -1 : ans);

    return 0;
}