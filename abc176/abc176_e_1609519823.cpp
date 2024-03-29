/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

// clang-format off
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;
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
// 最大値のquery
template <class T>
struct SegmentTree {
private:
  int n    = 1;
  int init = -INF;
  vector<T> data;

public:
  SegmentTree(vector<T> &v) {
    while (n < v.size()) n *= 2;
    data.assign(2 * n - 1, init);
    for (int i = 0; i < v.size(); i++) data[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--) data[i] = max(data[2 * i + 1], data[2 * i + 2]);
  }
  void update(int ind, T val) {
    ind += n - 1;
    data[ind] = val;
    while (ind > 0) {
      ind       = (ind - 1) / 2;
      data[ind] = max(data[2 * ind + 1], data[2 * ind + 2]);
    }
  }
  T at(int ind) { return data[n - 1 + ind]; }
  T operator[](int ind) { return data[n - 1 + ind]; }
  T get_max(int L, int R, int k = 0, int l = 0, int r = -1) { // [L, R
    if (r < 0) r = n;
    if (r <= L || R <= l) return init;
    if (L <= l and r <= R) return data[k];
    return max(get_max(L, R, 2 * k + 1, l, (l + r) / 2), get_max(L, R, 2 * k + 2, (l + r) / 2, r));
  }
};

class EBomber {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int H, W, M;
    cin >> H >> W >> M;
    VV<int> hw(H);
    VV<int> wh(W);
    rep(i, M) {
      int h, w;
      cin >> h >> w;
      hw[h - 1].emplace_back(w - 1);
      wh[w - 1].emplace_back(h - 1);
    }
    V<int> temp(W);
    SegmentTree<int> seg(temp);
    rep(i, W) seg.update(i, wh[i].size());
    int ans = 0;
    rep(i, H) {
      FOR(j, hw[i]) {
        seg.update(j, wh[j].size() - 1);
      }
      chmax(ans, (int)hw[i].size() + seg.get_max(0, W));
      FOR(j, hw[i]) {
        seg.update(j, wh[j].size());
      }
    }
    cout << ans << endl;
  }
};


signed main() {
  EBomber solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
