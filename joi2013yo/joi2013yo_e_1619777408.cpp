//@Author: KeinYukiyoshi

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
// const int INF    = (int)1e18;
// const int INF    = 10000000000007; // 1e13 + 7
// const int INF    = LLONG_MAX; // 9.2e18
const double EPS = 1e-8;
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

template <class T> int Lower_bound(vector<T> &A, T key) { //key以上の最小のindex, 存在しない場合-1を返す。
  int ind = distance(begin(A), lower_bound(ALL(A), key));
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}

template <class T> int Lower_bound_reverse(vector<T> &A, T key) { //key以下の最大のindex, 存在しない場合-1を返す。
  int ind = distance(begin(A), upper_bound(ALL(A), key)) - 1;
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}

class EFish {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N, K;
    cin >> N >> K;
    V<int> x1(N);
    V<int> x2(N);
    V<int> y1(N);
    V<int> y2(N);
    V<int> d1(N);
    V<int> d2(N);
    V<int> x;
    V<int> y;
    V<int> d;
    rep(i, N) {
      cin >> x1[i] >> y1[i] >> d1[i] >> x2[i] >> y2[i] >> d2[i];
      x.emplace_back(x1[i]);
      x.emplace_back(x2[i]);
      y.emplace_back(y1[i]);
      y.emplace_back(y2[i]);
      d.emplace_back(d1[i]);
      d.emplace_back(d2[i]);
    }
    sort(ALL(x));
    sort(ALL(y));
    sort(ALL(d));
    VVV<int> cnt(2 * N, VV<int>(2 * N, V<int>(2 * N)));
    rep(i, N) {
      rep2(j, Lower_bound_reverse(x, x1[i]), Lower_bound(x, x2[i]))
          rep2(k, Lower_bound_reverse(y, y1[i]), Lower_bound(y, y2[i]))
              rep2(l, Lower_bound_reverse(d, d1[i]), Lower_bound(d, d2[i]))
                  cnt[j][k][l]++;
    }
    int ans = 0;
    rep(i, 2 * N - 1) rep(j, 2 * N - 1) rep(k, 2 * N - 1) {
      if (cnt[i][j][k] >= K) ans += (x[i + 1] - x[i]) * (y[j + 1] - y[j]) * (d[k + 1] - d[k]);
    }
    cout << ans << endl;
  }
};


signed main() {
  EFish solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}

</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2021-04-30 19:10:08+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/joi2013yo/tasks/joi2013yo_e">E - 魚の生息範囲 (Fish)</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/joi2013yo/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (GCC 9.2.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">100</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">4596 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">19 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">11648 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In instantiation of ‘long long int Lower_bound_reverse(std::vector<_Tp>&, T) [with T = long long int]’:
./Main.cpp:85:7:   required from here
./Main.cpp:49:24: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int, std::allocator<long long int> >::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   49 |   if (0 <= ind and ind < A.size()) return ind;
./Main.cpp: In instantiation of ‘long long int Lower_bound(std::vector<_Tp>&, T) [with T = long long int]’:
./Main.cpp:85:7:   required from here
./Main.cpp:43:24: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int, std::allocator<long long int> >::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   43 |   if (0 <= ind and ind < A.size()) return ind;
