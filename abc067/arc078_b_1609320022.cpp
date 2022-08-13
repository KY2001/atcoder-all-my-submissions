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

void search(int now, V<int> &path, VV<int> &graph, int N, bool &ok) {
  if (ok) return;
  if (path.empty()) {
    FOR(i, graph[now]) {
      if (i == N - 1) {
        path.emplace_back(now);
        path.emplace_back(N - 1);
        ok = true;
        return;
      }
      path.emplace_back(now);
      search(i, path, graph, N, ok);
      if (ok) return;
      path.pop_back();
    }
  } else {
    int prev = path[path.size() - 1];
    FOR(i, graph[now]) {
      if (i == N - 1) {
        path.emplace_back(now);
        path.emplace_back(N - 1);
        ok = true;
        return;
      }
      if (i != prev) {
        path.emplace_back(now);
        search(i, path, graph, N, ok);
        if (ok) return;
        path.pop_back();
      }
    }
  }
}

class DFennecVSSnuke {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N;
    cin >> N;
    VV<int> graph(N);
    int a, b;
    rep(i, N - 1) {
      cin >> a >> b;
      graph[a - 1].emplace_back(b - 1);
      graph[b - 1].emplace_back(a - 1);
    }
    V<int> path;
    bool ok;
    search(0, path, graph, N, ok);
    V<bool> already(N);
    deque<int> pos;
    if (path.size() % 2) {
      pos.emplace_back(path[(path.size() + 1) / 2]);
      already[path[path.size() / 2]] = true;
    } else {
      pos.emplace_back(path[path.size() / 2]);
      already[path[path.size() / 2 - 1]] = true;
    }
    int snuke = 0;
    while (pos.size()) {
      snuke++;
      int now      = pos[0];
      already[now] = true;
      pos.pop_front();
      FOR(i, graph[now]) {
        if (!already[i]) {
          pos.emplace_back(i);
        }
      }
    }
    int fennec = N - snuke - 1;
    snuke--;
    if (snuke >= fennec) {
      cout << "Snuke" << endl;
    } else {
      cout << "Fennec" << endl;
    }
  }
};


signed main() {
  DFennecVSSnuke solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
