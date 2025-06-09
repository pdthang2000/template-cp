// https://leetcode.com/problems/unique-paths-iii/description
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
vector<vector<int>> matrix;
// vector<vector<int>> used(21, vector<int> (21, 0));
int used[21][21];
int res = 0, zeros = 0;
int n, m;
int x[4] = {1, 0, 0, -1};
int y[4] = {0, 1, -1, 0};
bool isValid(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < m;
}

void dfs(int row, int col, int z) {
    for (int i = 0; i < 4; ++i) {
        int next_x = row + x[i];
        int next_y = col + y[i];
        if (!isValid(next_x, next_y)) {
            continue;
        }
        if (matrix[next_x][next_y] == 2) {
            if (z == zeros) {
                res++;
            }
            continue;
        }
        if (matrix[next_x][next_y] == -1) {
            continue;
        }
        if (!used[next_x][next_y]) {
            used[next_x][next_y] = 1;
            dfs(next_x, next_y, z + 1);
            used[next_x][next_y] = 0;
        }
    }
}

int uniquePaths(vector<vector<int>>& grid) {
    matrix = grid;
    n = grid.size();
    m = grid[0].size();
    int start_row, start_col;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1) {
                start_row = i;
                start_col = j;
                used[i][j] = 1;
            }
            zeros += (grid[i][j] == 0);
        }
    }
    dfs(start_row, start_col, 0);
    return res;
}

void solve() {
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 2,-1}
    };

    cout << "Unique path of matrix: " << uniquePaths(grid);
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