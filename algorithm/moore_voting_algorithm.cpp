#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Moore's Voting Algorithm
int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;
    
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        
        if (num == candidate) {
            count++;
        } else {
            count--;
        }
        if (count > nums.size() / 2) {
            return candidate;
        }
    }
    
    return candidate;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    vector<int> v = {1, 1, 1, 2, 3, 3, 3, 3, 3};
    cout << majorityElement(v);
}