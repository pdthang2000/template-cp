#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    map<int, int> mp;
    mp[1]++; mp[2]++; mp[4]++;
    for (auto i : mp) { cout << i.first << ' ' << i.second << '\n'; }
    // 1 1
    // 2 1
    // 4 1
    cout << mp.size() << '\n'; // => 3
    // Chỉ cần truy xuất vào 1 phần tử của map thì nếu trước đó chưa có key đó tồn tại thì 
    // map sẽ tự động tạo ra key đó với giá trị mặc định.
    cout << mp[3] << '\n';     // => 0
    for (auto i : mp) { cout << i.first << ' ' << i.second << '\n'; }
    // 1 1
    // 2 1
    // 3 0
    // 4 1
    cout << mp.size() << '\n'; // 4
    // Cách để check key trong map có tồn tại hay không thì ta dùng hàm count
    // hoặc hàm find để có thể kiểm tra mà không tạo ra thừa key
    cout << mp.count(3) << '\n'; // => 1
    cout << mp.count(5) << '\n'; // => 0
}
