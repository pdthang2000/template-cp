// #include <bits/stdc++.h>
#include "stdc++.h"
using namespace std;
#define ll long long
pair<int, int> slopePair(int x1, int y1, int x2, int y2) {
    int dy = y2 - y1;
    int dx = x2 - x1;

    if (dx == 0) return {1, 0};   // vertical
    if (dy == 0) return {0, 1};   // horizontal

    int g = gcd(dy, dx);
    dy /= g;
    dx /= g;

    if (dx < 0) { dy = -dy; dx = -dx; }
	
    return {dy, dx};
}
ll slopePairToSlopeLL(pair<int, int> p) {
	ll slope = ((ll)p.first << 32) | p.second;
	return slope;
}

int main() {
	ios_base::sync_with_stdio(0);
	auto p = slopePair(2, 3, 6, 11);
	
    cout << "Reduced slope = (" << p.first << ", " << p.second << ")" << endl;
}