// Leetcode: https://leetcode.com/problems/number-of-islands
// #include <bits/stdc++.h>
#include "../../../others/stdc++.h"
using namespace std;
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define qq cout << '\n';
#define cer(x) cerr << #x << " = " << x << ' ';
#define cern(x) cerr << #x << " = " << x << '\n';
#define cc cerr << '\n';

const bool MULTIPLE_QUERY = 0;
const ll MAX_N = 200'005;
const ll MOD = 1e9 + 7;
const int WAYS = 4;

vector<vector<bool>> used;
vector<vector<char>> matrix;

int n, m;
int row_dir[WAYS] = {1, -1, 0, 0};
int col_dir[WAYS] = {0, 0, 1, -1};

bool isValid(int row, int col) {
    return (row >= 0 && row < n && col >= 0 && col < m);
}

int bfs(int row, int col) {
    int area = 0;
    queue<pair<int, int>> q;
    q.push({row, col});
    int r, c, new_r, new_c;
    used[row][col] = true;

    while (q.size()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        area++;
        for (int i = 0; i < WAYS; ++i) {
            new_r = r + row_dir[i];
            new_c = c + col_dir[i];
            if (isValid(new_r, new_c) == false) {
                continue;
            }
            if (used[new_r][new_c] == false && matrix[new_r][new_c] == '1') {
                used[new_r][new_c] = true;
                q.push({new_r, new_c});
            }
        }
    }
    return area;
}

int numIslands(vector<vector<char>>& grid) {
    n = grid.size();
    m = grid[0].size();
    matrix = grid;
    int res = 0;
    used = vector<vector<bool>> (n, vector<bool> (m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == '0') {
                used[i][j] = 1;
            }
        }
    }
    int max_area = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (used[i][j] == false && matrix[i][j] == '1') {
                max_area = max(max_area, bfs(i, j));
                res++;
            }
        }
    }
    cout << "Max area of islands: " << max_area << '\n';
    return res;
}

void solve() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << "Number of islands: " <<  numIslands(grid); qq;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (MULTIPLE_QUERY) {
		ll Q;
		cin >> Q;
		while (Q--) {
			solve(); qq;
		}
	} else {
		solve();
	}
}