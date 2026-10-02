#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;
//https://leetcode.com/problems/count-numbers-with-unique-digits/description/
//Ý tưởng: Tạo vector bool để đánh dấu số nào đã dùng rồi, và dựa vào để xây dựng
// hàm backtrack.
// Nếu check[i] đã dùng rồi thì bỏ qua,
// Nếu check[i] chưa dùng thì thêm vào s vad tiếp yuc quay để check độ dài
// Nếu s(chuỗi hiện tại có độ dài == n) thì quay lui (pop_back) 
// và gỡ check (true) cho giá trị cuối để thêm giá trị tiếp theo ở vòng đó
string s = "";
int Count = 1;
vector<bool> check(10, false);

void Try(int n, int lenghtCur)
{
    if (lenghtCur > 0)
    {
        Count++;
    }
    if (lenghtCur == n)
        return;
    for (int i = 0; i <= 9; i++)
    {
        if (check[i])
            continue;
        if (lenghtCur == 0 && i == 0)
            continue;
        s.push_back('0' + i);
        check[i] = true;

        Try(n, lenghtCur + 1);
        s.pop_back();
        check[i] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    Try(n, 0);
    cout << Count;
    return 0;
}