#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define qq cout << '\n';

template <typename T>
vector<vector<T>> rotate_clockwise_90(vector<vector<T>> matrix, ll n) {
    for (ll i = 0; i < n / 2; i++) {
        for (ll j = i; j < n - i - 1; j++) {
            T temp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = temp;
        }
    }
    return matrix;
}

template <typename T>
vector<vector<T>> rotate_180(vector<vector<T>> matrix, ll n) {
    for (ll i = 0; i < n / 2; i++) {
        for (ll j = 0; j < n; j++) {
            swap(matrix[i][j], matrix[n - i - 1][n - j - 1]);
        }
    }

    if (n % 2 != 0) {
        ll i = n / 2;
        for (ll j = 0; j < n / 2; j++) {
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }

    return matrix;
}

template <typename T>
void print_matrix(vector<vector<T>> matrix) {
    for (auto i: matrix) {
        for (auto j: i) {
            cout << j << ' ';
        } qq;
    }
}

template <typename T>
vector<vector<T>> rotate_counterclockwise_90(vector<vector<T>> matrix, ll n) {
    for (ll i = 0; i < n / 2; i++) {
        for (ll j = i; j < n - i - 1; j++) {
            T temp = matrix[i][j];
            matrix[i][j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = temp;
        }
    }
    return matrix;
}

template <typename T>
vector<vector<T>> rotate_main_diagonal(vector<vector<T>> matrix, ll n) {
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    return matrix;
}

template <typename T>
vector<vector<T>> rotate_anti_diagonal(vector<vector<T>> matrix, ll n) {
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n - i; j++) {
            swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
        }
    }
    return matrix;
}

template <typename T>
vector<vector<T>> rotate_vertical_line(vector<vector<T>> matrix, ll n) {
    ll mid = n / 2;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < mid; j++) {
            swap(matrix[i][j], matrix[i][n - 1 - j]);
        }
    }
    return matrix;
}

template <typename T>
vector<vector<T>> rotate_horizontal_line(vector<vector<T>> matrix, ll n) {
    ll mid = n / 2;
    for (ll i = 0; i < mid; i++) {
        for (ll j = 0; j < n; j++) {
            swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }
    return matrix;
}

void pdthang2000() {
    ll n;
    cin >> n;

    vector<vector<char>> a(n, vector<char> (n));

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    
    cout << "90 Degrees Clockwise:" << endl;
    vector<vector<char>> rotated90 = rotate_clockwise_90(a, n);
    print_matrix(rotated90);
    qq;

    cout << "180 Degrees:" << endl;
    vector<vector<char>> rotated180 = rotate_180(a, n);
    print_matrix(rotated180);
    qq;

    cout << "90 Degrees Counter-Clockwise:" << endl;
    vector<vector<char>> rotatedCounter90 = rotate_counterclockwise_90(a, n);
    print_matrix(rotatedCounter90);

    cout << "Main Diagonal Rotation:" << endl;
    auto e = rotate_main_diagonal(a, n);
    print_matrix(e); qq;

    cout << "Anti Diagonal Rotation:" << endl;
    auto f = rotate_anti_diagonal(a, n);
    print_matrix(f); qq;

    cout << "Vertical Line Rotation:" << endl;
    auto g = rotate_vertical_line(a, n);
    print_matrix(g); qq;

    cout << "Horizontal Line Rotation:" << endl;
    auto h = rotate_horizontal_line(a, n);
    print_matrix(h); qq;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    pdthang2000();
}