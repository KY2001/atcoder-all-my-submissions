/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

// clang-format off
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define stoi stoll
#define Endl endl
#define itn int
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

V<string> rotation(V<string> &S) {
  int h = S.size(), w = S[0].size();
  V<string> s(w);
  rep(i, w) s[i] = string(h, '#');
  rep(i, w) rep(j, h) {
    s[i][j] = S[h - 1 - j][i];
  }
  return s;
}

class E {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int H, W;
    cin >> H >> W;
    V<string> S(H + 40);
    V<string> T(H);
    rep(i, H) cin >> S[i + 20];
    rep(i, H) cin >> T[i];
    rep(i, 40 + H) {
      if (S[i].empty()) {
        S[i] = string(W + 40, '.');
      } else {
        S[i] = string(20, '.') + S[i] + string(20, '.');
      }
    }
    rep(i, W + 40 - T.size() + 1) rep(j, H + 40 - T[0].size() + 1) {
      rep(k, H) rep(l, W) {
        if (T[k][l] == '#' and !(20 <= i + k and i + k <= W + 19 and 20 <= j + l and j + l <= H + 19)) {
          goto label;
        }
      }
      rep(k, H) rep(l, W) {
        if (S[i + k][j + l] == '#' and T[k][l] == '#') {
          goto label;
        } else if (k == H - 1 and l == W - 1) {
          cout << "Yes" << endl;
          return;
        }
      }
    label:;
    }
    T = rotation(T);
    rep(i, W + 40 - T.size() + 1) rep(j, H + 40 - T[0].size() + 1) {
      rep(k, H) rep(l, W) {
        if (T[k][l] == '#' and !(20 <= i + k and i + k <= W + 19 and 20 <= j + l and j + l <= H + 19)) {
          goto label2;
        }
      }
      rep(k, H) rep(l, W) {
        if (S[i + k][j + l] == '#' and T[k][l] == '#') {
          goto label2;
        } else if (k == H - 1 and l == W - 1) {
          cout << "Yes" << endl;
          return;
        }
      }
    label2:;
    }
    T = rotation(T);
    rep(i, W + 40 - T.size() + 1) rep(j, H + 40 - T[0].size() + 1) {
      rep(k, H) rep(l, W) {
        if (T[k][l] == '#' and !(20 <= i + k and i + k <= W + 19 and 20 <= j + l and j + l <= H + 19)) {
          goto label3;
        }
      }
      rep(k, H) rep(l, W) {
        if (S[i + k][j + l] == '#' and T[k][l] == '#') {
          goto label3;
        } else if (k == H - 1 and l == W - 1) {
          cout << "Yes" << endl;
          return;
        }
      }
    label3:;
    }
    T = rotation(T);
    rep(i, W + 40 - T.size() + 1) rep(j, H + 40 - T[0].size() + 1) {
      rep(k, H) rep(l, W) {
        if (T[k][l] == '#' and !(20 <= i + k and i + k <= W + 19 and 20 <= j + l and j + l <= H + 19)) {
          goto label4;
        }
      }
      rep(k, H) rep(l, W) {
        if (S[i + k][j + l] == '#' and T[k][l] == '#') {
          goto label4;
        } else if (k == H - 1 and l == W - 1) {
          cout << "Yes" << endl;
          return;
        }
      }
    label4:;
    }
    cout << "No" << endl;
  }
};


signed main() {
  E solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
