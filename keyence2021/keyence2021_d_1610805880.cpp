/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

// clang-format off
#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#define int long long
using namespace std;
#define stoi stoll
#define fi first
#define se second
#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; i++)
#define rep2(i, a, b) for (int i = (int)(a), i##_len=(b); i < i##_len; i++)
#define rep3(i, a, b) for (int i = (int)(a), i##_len=(b); i >= i##_len; i--)
#define FOR(i, a) for (auto &i: a)
#define ALL(obj) begin(obj), end(obj)
#define _max(x) *max_element(ALL(x))
#define _min(x) *min_element(ALL(x))
#define _sum(x) accumulate(ALL(x), 0LL)

const int MOD   = 1000000007;
// const int MOD    = 998244353;
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-8;
const double PI  = 3.14159265358979;
template <class T> using V = vector<T>;
template <class T> using VV = vector<vector<T>>;
template <class T> using VVV = vector<vector<vector<T>>>;
template <class T, class S>  using P = pair<T, S>;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return true;}return false;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return true;}return false;}
int _ceil(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
int _mod(int a) {return a >= 0 ? a % MOD : a - (MOD * _ceil(a, MOD));}
int _pow(int a, int b) {int res = 1;for (a %= MOD; b; a = a * a % MOD, b >>= 1)if (b & 1) res = res * a % MOD;return res;}
struct mint {long long x;mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) { (x *= a.x) %= MOD;return *this; }mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; } mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long t) const {if (!t) return 1;mint a = pow(t >> 1);a *= a;if (t & 1) a *= *this;return a;}mint inv() const { return pow(MOD - 2); }mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }};istream &operator>>(istream &is, mint &a) { return is >> a.x; }ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
// clang-format on

class DChoosingUpSides {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N;
    cin >> N;
    if (N == 1) {
      cout << 1 << endl;
      cout << "AB" << endl;
      return;
    }
    VV<char> now(3, V<char>(4));
    now[0][0]                                     = 'A';
    now[1][0]                                     = 'A';
    now[2][0]                                     = 'A';
    now[0][1]                                     = 'A';
    now[1][3]                                     = 'A';
    now[2][2]                                     = 'A';
    rep(i, 3) rep(j, 4) if (!now[i][j]) now[i][j] = 'B';
    rep(i, N - 2) {
      int right = (1 << (i + 3));
      int left  = now.size() * 3;
      VV<char> temp(left, V<char>(right));
      V<int> A_y = {0, 0, 0, right / 4, right / 4 * 2, right / 4 * 3};
      V<int> A_x = {0, left / 3, left / 3 * 2, 0, left / 3 * 2, left / 3};
      rep(j, A_y.size()) {
        int x = A_y[j], y = A_x[j];
        rep(k, left / 3) rep(l, right / 4) {
          temp[y + k][x + l] = now[k][l];
        }
      }
      rep(m, left) rep(n, right) if (!temp[m][n]) {
        int y = m, x = n;
        rep(k, left / 3) rep(l, right / 4) {
          temp[y + k][x + l] = now[k][right / 4 + l];
        }
      }
      now = temp;
    }
    rep(i, now.size()) {
      rep(j, now[i].size()) cout << now[i][j];
      cout << endl;
    }
  }
};


signed main() {
  DChoosingUpSides solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
