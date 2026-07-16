#include <bits/stdc++.h>
using namespace std;
// Prefix Sum 1D (Không biết là cút)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Khởi tạo vector lưu phần tử cộng dồn (Prefix Sum)

    vector<int> Prefix(n + 1, 0);

    // Đọc và cộng dồn lần lượt
    for (int i = 0; i < n; i++)
    {
        Prefix[i + 1] = Prefix[i] + nums[i];
        // Đọc Code : Tổng cộng dồn (0 -> i+1)  bằngtổng cộng dồn trước nó cộng cho phần tử nums hiện tại
    }

    // Truy xuất tổng cộng dồn khoảng [l,r]
    int l, r;
    cin >> l >> r;
    int sum = Prefix[r + 1] - Prefix[l];

    // Vì sao r+ 1 ? => Vì Prefix[i] = tổng của i phần tử đầu tiên = a[0] + a[1] + .. + a[i-1]

    // Tức là Prefix[i] chưa cộng tới a[i], mới chỉ cộng tới a[i-1]. Nên muốn tổng đoạn [l, r] có bao gồm a[r],
    // ta phải lấy Prefix[r+1] (là tổng đã cộng tới a[r]), chứx không phải Prefix[r] (mới chỉ cộng tới a[r-1],
    // thiếu mất a[r]).

    // VD: nums=[1, 3, 6, 8 ,9] ;  Prefix=[0, 1, 4, 10, 18, 27] l=1 r=3;
    // l=1,r=3 => 3 + 6 + 8 = 17
    // Suy ra : Prefix[r+1] - Prefix[l] = 18 - 1 =17 ( tương ứng với kết quả cần tìm)

    return 0;
}