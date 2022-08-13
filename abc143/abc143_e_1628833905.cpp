// clang-format off
#include <bits/stdc++.h>
#pragma GCC optimize ("-Ofast")
#pragma GCC optimize ("unroll-loops")
//#define double __float80
using namespace std;
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
const int INF    = 1e9;
// const int INF    = 1e13 + 7;
// const int INF    = LLONG_MAX; // 9.2e18
const double EPS = 1e-20;
const double PI  = 3.14159265358979;
template <class T> using V = vector<T>;
template <class T> using VV = vector<vector<T>>;
template <class T> using VVV = vector<vector<vector<T>>>;
template <class T, class S>  using P = pair<T, S>;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return true;}return false;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return true;}return false;}
int _ceil(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
template<class T> T chmod(T &a, T mod=MOD) {a =  a >= 0 ? a % mod : a - (mod * _ceil(a, mod)); return a;};
int _mod(int a, int mod=MOD) {return a >= 0 ? a % mod : a - (mod * _ceil(a, mod));}
int _pow(int a, int b, int mod=MOD) {int res = 1;for (a %= mod; b; a = a * a % mod, b >>= 1)if (b & 1) res = res * a % mod;return res;}
struct mint {long long x;mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) { (x *= a.x) %= MOD;return *this; }mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; } mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long t) const {if (!t) return 1;mint a = pow(t >> 1);a *= a;if (t & 1) a *= *this;return a;}mint inv() const { return pow(MOD - 2); }mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }};istream &operator>>(istream &is, mint &a) { return is >> a.x; }ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
// clang-format on

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int N, M, L, A, B, C, Q, s, t;
  cin >> N >> M >> L;
  VV<int> ans(N, V<int>(N));
  VVV<int> graph(N);
  rep(i, M) {
    cin >> A >> B >> C;
    graph[A - 1].push_back({B - 1, C});
    graph[B - 1].push_back({A - 1, C});
  }
  cin >> Q;
  rep(i, N) {
    s = i;
    VV<int> shortest(N);
    V<bool> already(N);
    rep(j, N) shortest[j] = {INF, 0};
    priority_queue<V<int>, VV<int>, greater<>> pos;
    pos.push({0, -L, s});
    shortest[s] = {0, -L};
    while (pos.size()) {
      int dis = pos.top()[0], remain = -pos.top()[1], now = pos.top()[2];
      if (already[now]) continue;
      already[now] = true;
      pos.pop();
      FOR(j, graph[now]) {
        if (j[1] > L) continue;
        if (j[1] > remain) {
          V<int> comp = {dis + 1, -(L - j[1])};
          if (shortest[j[0]] > comp) {
            shortest[j[0]] = comp;
            pos.push({dis + 1, -(L - j[1]), j[0]});
          }
        } else {
          V<int> comp = {dis, -(remain - j[1])};
          if (shortest[j[0]] > comp) {
            shortest[j[0]] = comp;
            pos.push({dis, -(remain - j[1]), j[0]});
          }
        }
      }
    }
    rep(j, N) ans[i][j] = shortest[j][0];
  }
  rep(i, Q) {
    cin >> s >> t;
    if (ans[s - 1][t - 1] == INF) {
      cout << -1 << endl;
    } else {
      cout << ans[s - 1][t - 1] << endl;
    }
  }
}