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
#define LOWER_BOUND(A, key) distance(begin(A), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(begin(A), upper_bound(ALL(A), key))

const int MOD   = 1000000007;
// const int MOD    = 998244353;
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-14;
const double PI  = 3.14159265358979;
template <class T> using V = vector<T>;
template <class T> using VV = vector<vector<T>>;
template <class T> using VVV = vector<vector<vector<T>>>;
template <class T, class S>  using P = pair<T, S>;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return true;}return false;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return true;}return false;}
int _ceil(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
int _mod(int &a) {a = a >= 0 ? a % MOD : a - (MOD * _ceil(a, MOD));return a;}
int _pow(int a, int b) {int res = 1;for (a %= MOD; b; a = a * a % MOD, b >>= 1)if (b & 1) res = res * a % MOD;return res;}
// clang-format on

bool cross(int x1, int y1, int x2, int y2, int X1, int Y1, int X2, int Y2) {
  int a = (x1 - x2) * (Y1 - y1) - (y1 - y2) * (X1 - x1);
  int b = (x1 - x2) * (Y2 - y1) - (y1 - y2) * (X2 - x1);
  if (a * b <= 0) return true;
  return false;
}

class D {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Ax, Ay, Bx, By;
    cin >> Ax >> Ay >> Bx >> By;
    int N;
    cin >> N;
    V<int> X(N);
    V<int> Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    X.emplace_back(X[0]);
    Y.emplace_back(Y[0]);
    int ans = 0;
    rep(i, N) {
      if (cross(Ax, Ay, Bx, By, X[i], Y[i], X[i + 1], Y[i + 1])) ans++;
    }
    ans /= 2;
    cout << ans + 1 << endl;
  }
};


signed main() {
  D solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
