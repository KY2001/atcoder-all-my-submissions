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

void func(int y, int x, int dis, V<string> &S, deque<V<int>> &pos, VV<int> &shortest) {
  if (S[y][x] == '.' and shortest[y][x] > dis) {
    shortest[y][x] = dis;
    pos.push_back({y, x, dis});
    func(y + 1, x, dis, S, pos, shortest);
    func(y - 1, x, dis, S, pos, shortest);
    func(y, x + 1, dis, S, pos, shortest);
    func(y, x - 1, dis, S, pos, shortest);
  }
}
class DWizardInMaze {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int H, W;
    cin >> H >> W;
    P<int, int> C;
    P<int, int> D;
    cin >> C.fi >> C.se;
    cin >> D.fi >> D.se;
    C.fi++, C.se++;
    D.fi++, D.se++;
    V<string> S(H + 4);
    S[0]     = string(W + 4, '#');
    S[1]     = string(W + 4, '#');
    S[H + 3] = string(W + 4, '#');
    S[H + 2] = string(W + 4, '#');
    rep(i, H) {
      cin >> S[i + 2];
      S[i + 2] = "##" + S[i + 2] + "##";
    }
    VV<int> shortest(H + 4, V<int>(W + 4, INF));
    deque<V<int>> pos    = {{C.fi, C.se, 0}};
    shortest[C.fi][C.se] = 0;
    while (pos.size()) {
      int y = pos[0][0], x = pos[0][1], num = pos[0][2];
      pos.pop_front();
      func(y + 1, x, num, S, pos, shortest);
      func(y - 1, x, num, S, pos, shortest);
      func(y, x + 1, num, S, pos, shortest);
      func(y, x - 1, num, S, pos, shortest);
      rep2(i, y - 2, y + 3) {
        rep2(j, x - 2, x + 3) {
          if (shortest[i][j] > num + 1 and S[i][j] == '.') {
            shortest[i][j] = num + 1;
            pos.push_back({i, j, num + 1});
          }
        }
      }
    }
    if (shortest[D.fi][D.se] == INF) {
      cout << -1 << endl;
    } else {
      cout << shortest[D.fi][D.se] << endl;
    }
  }
};


signed main() {
  DWizardInMaze solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
