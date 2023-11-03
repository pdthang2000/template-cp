#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define qq cout << '\n';

struct Matrix {
    ll n; // row length
    ll m; // col length
    vector<vector<ll>> val_matrix;
    vector<vector<ll>> ps_matrix; // prefix sum matrix
    
    Matrix(ll row_length, ll col_length, vector<vector<ll>> val_matrix) {
        this->n = row_length;
        this->m = col_length;
        this->val_matrix = val_matrix;
    }
    
    void cal_prefix_sum() {
        ps_matrix.resize(n, vector<ll> (m));
        for (ll i = 0; i < n; ++i) {
            ps_matrix[i][0] = val_matrix[i][0];
            for (ll j = 1; j < m; ++j) {
                ps_matrix[i][j] = val_matrix[i][j] + ps_matrix[i][j - 1];
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ps_matrix[i][j] += ps_matrix[i - 1][j];
            }
        }
    }

    void print_ps_matrix() {
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < m; ++j) {
                cout << ps_matrix[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    void print_val_matrix() {
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < m; ++j) {
                cout << val_matrix[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    ll get_sum_in_range(ll r1, ll c1, ll r2, ll c2) {
        ll sum_top_left = (r1 - 1 >= 0 && c1 - 1 >= 0) ? ps_matrix[r1 - 1][c1 - 1] : 0;

        ll sum_top_right = r1 - 1 >= 0 ? ps_matrix[r1 - 1][c2] : 0;
        
        ll sum_bot_left = c1 - 1 >= 0 ? ps_matrix[r2][c1 - 1] : 0;

        ll sum_bot_right = ps_matrix[r2][c2];
        
        return sum_bot_right - sum_bot_left - sum_top_right + sum_top_left;
    }
};


void pdthang2000() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll> (m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }

    Matrix matrix(n, m, v);
    matrix.cal_prefix_sum();
    matrix.print_ps_matrix();
    cout << matrix.get_sum_in_range(1, 1, 2, 2);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    pdthang2000();
}