#include <bits/stdc++.h>
// #include "stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

int main() {
    gp_hash_table<int, int> mp;

    mp[10] = 5;
    mp[3] = 7;

    cout << mp[10] << "\n";  // 5

    if (mp.find(3) != mp.end()) {
        cout << "Key 3 exists, value = " << mp[3] << "\n";
    }
}
