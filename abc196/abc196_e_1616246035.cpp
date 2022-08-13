//@Author: KeinYukiyoshi

// clang-format off
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
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
const int INF    = (int)1e18;
const int INF2    = 10000000000007; // 1e13 + 7
const int INF3    = LLONG_MAX; // 9.2e18
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
template <class T> int Upper_bound(vector<T> &A, T key) { //keyより大きい最小のindex, 存在しない場合-1を返す。
  int ind = distance(begin(A), upper_bound(ALL(A), key));
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}
template <class T> int Upper_bound_reverse(vector<T> &A, T key) { //keyより小さい最大のindex, 存在しない場合-1を返す。
  int ind = distance(begin(A), lower_bound(ALL(A), key)) - 1;
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}

class EFilters {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N, Q;
    cin >> N;
    V<int> a(N);
    V<int> t(N);
    rep(i, N) cin >> a[i] >> t[i];
    cin >> Q;
    V<int> x(Q);
    rep(i, Q) cin >> x[i];
    V<int> X = x;
    V<int> a_sum(N + 1);
    rep(i, N) if (t[i] == 1) a_sum[i + 1] = a[i];
    rep(i, N) a_sum[i + 1] += a_sum[i];
    V<int> max(N, -INF);
    V<int> min(N, INF);
    rep(i, N) {
      if (t[i] == 2) {
        max[i] = a[i] - a_sum[i];
      } else if (t[i] == 3) {
        min[i] = a[i] - a_sum[i];
      }
    }
    rep(i, N - 1) {
      chmax(max[i + 1], max[i]);
      chmin(min[i + 1], min[i]);
    }
    rep(i, N) {
      if (max[i] == -INF) max[i] == INF;
      if (min[i] == INF) max[i] == -INF;
    }
    map<int, int> ans;
    reverse(ALL(min));
    rep(i, Q) {
      V<int> temp;
      while (1) {
        if (ans.count(x[i])) {
          cout << ans[x[i]] << endl;
          break;
        }
        temp.emplace_back(x[i]);
        int maxi = Upper_bound(max, x[i]);
        int mini = Upper_bound_reverse(min, x[i]);
        if (maxi == -1 or max[maxi] == INF) maxi = INF;
        if (mini == -1 or min[mini] == INF) {
          mini = INF;
        } else {
          mini = N - mini - 1;
        }
        if (maxi == INF and mini == INF) {
          cout << x[i] + a_sum[N] << endl;
          FOR(k, temp) {
            ans[k] = x[i] + a_sum[N];
          }
          break;
        } else if (maxi < mini) {
          x[i] = a[maxi] - a_sum[maxi];
        } else {
          x[i] = a[mini] - a_sum[mini];
        }
      }
    }
  }
};


signed main() {
  EFilters solver;
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
					<td class="text-center"><time class='fixtime fixtime-second'>2021-03-20 22:13:55+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc196/tasks/abc196_e">E - Filters</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc196/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (GCC 9.2.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">0</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">5627 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Time Limit Exceeded">TLE</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">2238 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">1053588 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In static member function ‘static void EFilters::solve(std::istream&, std::ostream&)’:
./Main.cpp:95:34: warning: value computed is not used [-Wunused-value]
   95 |       if (max[i] == -INF) max[i] == INF;
./Main.cpp:96:33: warning: value computed is not used [-Wunused-value]
   96 |       if (min[i] == INF) max[i] == -INF;
./Main.cpp: In instantiation of ‘long long int Upper_bound(std::vector<_Tp>&, T) [with T = long long int]’:
./Main.cpp:108:41:   required from here
./Main.cpp:53:24: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int, std::allocator<long long int> >::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   53 |   if (0 <= ind and ind < A.size()) return ind;
./Main.cpp: In instantiation of ‘long long int Upper_bound_reverse(std::vector<_Tp>&, T) [with T = long long int]’:
./Main.cpp:109:49:   required from here
./Main.cpp:58:24: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int, std::allocator<long long int> >::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   58 |   if (0 <= ind and ind < A.size()) return ind;