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
#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; i++)
#define rep2(i, a, b) for (int i = (int)(a), i##_len=(b); i < i##_len; i++)
#define rep3(i, a, b) for (int i = (int)(a), i##_len=(b); i >= i##_len; i--)
#define FOR(i, a) for (auto &i: a)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define SUM(x) accumulate(ALL(x), 0LL)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

const int MOD    = 998244353;
const int MOD2   = 1000000007;
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-14;
const double PI  = 3.14159265358979;
template <class T> using V = vector<T>;
template <class T> using VV = vector<vector<T>>;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return true;}return false;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return true;}return false;}
int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
int mod(int &a) {a = a >= 0 ? a % MOD : a - (MOD * CEIL(a, MOD));return a;}
int POW(int a, int b) {int res = 1;for (a %= MOD; b; a = a * a % MOD, b >>= 1)if (b & 1) res = res * a % MOD;return res;}
// clang-format on

template <class T> inline int Lower_bound_reverse(vector<T> A, T key) { //key以下の最大のindex, 存在しない場合-1を返す。
  int ind = UPPER_BOUND(A, key) - 1;
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}

class FProgrammingContest {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N, T;
    cin >> N >> T;
    if (N == 1) {
      int A;
      cin >> A;
      if (A <= T) {
        cout << A << endl;
      } else {
        cout << 0 << endl;
      }
      return;
    }
    V<int> A(N / 2);
    V<int> B(CEIL(N, 2));
    rep(i, N / 2) cin >> A[i];
    rep(i, CEIL(N, 2)) cin >> B[i];
    vector<int> a = {0};
    vector<int> b = {0};
    FOR(i, A) {
      vector<int> temp;
      FOR(j, a)
      if (i + j <= T)
        temp.emplace_back(i + j);
      FOR(j, temp)
      a.emplace_back(j);
    }
    FOR(i, B) {
      vector<int> temp;
      FOR(j, b)
      if (i + j <= T)
        temp.emplace_back(i + j);
      FOR(j, temp)
      b.emplace_back(j);
    }
    sort(ALL(a));
    sort(ALL(b));
    int ans = 0;
    FOR(i, a) {
      int ind = Lower_bound_reverse(b, T - i);
      if (ind != -1) chmax(ans, i + b[ind]);
    }
    cout << ans << endl;
  }
};


signed main() {
  FProgrammingContest solver;
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
					<td class="text-center"><time class='fixtime fixtime-second'>2020-11-23 08:38:41+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc184/tasks/abc184_f">F - Programming Contest</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc184/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
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
					<td class="text-center">3151 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Time Limit Exceeded">TLE</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">2206 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">35900 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In instantiation of ‘long long int Lower_bound_reverse(std::vector<_Tp>, T) [with T = long long int]’:
./Main.cpp:90:45:   required from here
./Main.cpp:41:24: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int, std::allocator<long long int> >::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   41 |   if (0 <= ind and ind < A.size()) return ind;
