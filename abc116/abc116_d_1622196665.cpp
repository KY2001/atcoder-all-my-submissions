//@Author: KeinYukiyoshi

// clang-format off
#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#define int long long
//#define double __float80
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
// const int INF    = 1e18;
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
int _pow(int a, int b) {int res = 1;for (a %= MOD; b; a = a * a % MOD, b >>= 1)if (b & 1) res = res * a % MOD;return res;}
struct mint {long long x;mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) { (x *= a.x) %= MOD;return *this; }mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; } mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long t) const {if (!t) return 1;mint a = pow(t >> 1);a *= a;if (t & 1) a *= *this;return a;}mint inv() const { return pow(MOD - 2); }mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }};istream &operator>>(istream &is, mint &a) { return is >> a.x; }ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
// clang-format on

class DVariousSushi {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N, K;
    cin >> N >> K;
    V<int> t(N);
    V<int> d(N);
    rep(i, N) cin >> t[i] >> d[i];
    V<V<int>> dt(N, V<int>(2));
    rep(i, N) dt[i][0] = d[i], dt[i][1] = t[i];
    sort(ALL(dt), greater{});
    V<int> already(N + 1);
    int ans = 0;
    deque<V<int>> num;
    rep(i, K) ans += dt[i][0], already[dt[i][1]]++, num.push_back(dt[i]);
    int cnt = 0;
    rep(i, N + 1) if (already[i]) cnt++;
    ans += cnt * cnt;
    map<int, int> unused;
    rep(i, N) if (!already[t[i]]) chmax(unused[t[i]], d[i]);
    deque<int> unused2;
    FOR(i, unused)
    unused2.emplace_back(i.se);
    sort(ALL(unused2), greater{});
    sort(ALL(num));
    int ret = ans;
    while (1) {
      if (num.empty() or unused2.empty()) break;
      if (already[num[0][1]] == 1) {
        num.pop_front();
        continue;
      }
      ret = ret - (cnt * cnt) + (cnt + 1) * (cnt + 1) - num[0][0] + unused2[0];
      cnt++;
      num.pop_front();
      unused2.pop_front();
      chmax(ans, ret);
    }
    cout << ans << endl;
  }
};


signed main() {
  DVariousSushi solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}

