#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[10][10], row[10][10], col[10][10], box[10][10];
ll total_z, cur_box;
bool stt = false;
map<pair<ll, ll>, ll> mpp;

bool isValid(vector<vector<char>>& board, int i, int j, char value){
	int boxRow = i / 3 * 3;
	int boxCol = j / 3 * 3;
	for (int k = 0; k < 9; k++) {
		if (board[i][k] == value) return false;
		if (board[k][j] == value) return false;
		if (board[k / 3 + boxRow][k % 3 + boxCol] == value) return false;
	}
	return true;
}
bool isValidSudoku(vector<vector<char>>& board) {
	for (int i=0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == '.') continue;

			char value = board[i][j];
			
			board[i][j] = '.';
			if (!isValid(board, i, j, value)) return false;
			board[i][j] = value;
		}
	}
	return true;
}

void init() {
    ll cnt = 1;
    for (ll i = 1; i <= 3; ++i) {
		for (ll j = 1; j <= 3; ++j) {
			mpp[{i, j}] = cnt;
			cnt++;
		}
	}
}

void show() {
    for (ll i = 1; i <= 9; ++i) {
        for (ll j = 1; j <= 9; ++j) {
            cout << a[i][j] << ' ';
        }
		cout << '\n';
    }
}

ll find_box(ll x, ll y) {
    ll p1, p2;

    if(x <= 3) p1 = 1;
    else if(x >= 7) p1 = 3;
    else p1 = 2;

    if(y <= 3) p2 = 1;
    else if(y >= 7) p2 = 3;
    else p2 = 2;

    return mpp[{p1, p2}];
}

void start() {
    for (ll i = 1; i <= 9; ++i) {
		for (ll j = 1; j <= 9; ++j) {
			ll t = a[i][j];
			if (t != 0) {
				row[i][t] = 1;
				col[j][t] = 1;
				cur_box = find_box(i, j);
				box[cur_box][t] = 1;
			}
		}
	}
}

void fill(ll cnt_z) {
    if (cnt_z == total_z) {
        stt = true;
		show();
		return;
    }
    for (ll r = 1; r <= 9; ++r) {
		for (ll c = 1; c <= 9; ++c) {
			if (a[r][c] != 0) {
				continue;
			}
			for (ll k = 1; k <= 9; ++k) {
				ll b = find_box(r, c);
				if (row[r][k] == 0 && col[c][k] == 0 && box[b][k] == 0) {
					a[r][c] = k;

					row[r][k] = 1;
					col[c][k] = 1;
					box[b][k] = 1;

					fill(cnt_z + 1);

					row[r][k] = 0;
					col[c][k] = 0;
					box[b][k] = 0;

					if (stt) {
						return;
					}
				}
			}
			a[r][c] = 0;
			return;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    for (ll i = 1; i <= 9; ++i) {
    	for (ll j = 1; j <= 9; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 0) total_z++;
		}
	}
    init();
    start();
    fill(0);
}

/*
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

1 5 4 8 7 3 2 9 6
3 8 6 5 9 2 7 1 4
7 2 9 6 4 1 8 3 5
8 6 3 7 2 5 1 4 9
9 7 5 3 1 4 6 2 8
4 1 2 9 6 8 3 5 7
6 3 1 4 5 7 9 8 2
5 9 8 2 3 6 4 7 1
2 4 7 1 8 9 5 6 3

*/
    