#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>

// https://www.geeksforgeeks.org/policy-based-data-structures-g/

/* 
A vjp pr0 set that can use these 2 advanced operations: 
    order_of_key (k) : Number of items strictly smaller than k .
    find_by_order(k) : K-th element in a set (counting from zero).
        If you call find_by_order(k) with a value of k that is greater than or equal to the size of the ordered_set, 
        it will return an iterator to the end of the set, which is not a valid element. 
        Attempting to dereference this iterator will result in undefined behavior. 
        It is important to always check that k is within the bounds of the set before calling find_by_order(k)
*/ 
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define qq cout << '\n';

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    
    ordered_set s;
    
    for (ll i = 1; i < 10; ++i) {
        ll temp = rand() % 50;
        cout << temp << ' '; 
        s.insert(temp);
    } qq;

    for (auto i : s) { cout << i << ' '; } qq;

    for (ll i = 0; i <= 30; i += 5) {
        cout << " Number of items strictly smaller than " << i << " : ";
        cout << s.order_of_key(i) << '\n';
    }    

    for (ll i = 0; i < s.size(); ++i) {
        cout << *s.find_by_order(i) << '\n';
    }
}