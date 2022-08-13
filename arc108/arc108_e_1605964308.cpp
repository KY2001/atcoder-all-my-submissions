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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (b); i++)
#define rep3(i, a, b) for (int i = (int)(a); i >= (b); i--)
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
template <class T> using VV = vector<vector<T>>;
template <class T> using VVV = vector<vector<vector<T>>>;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return true;}return false;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return true;}return false;}
int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
int mod(int &a) {a = a >= 0 ? a % MOD : a - (MOD * CEIL(a, MOD));return a;}
int pow_mod(int a, int b) {int res = 1;for (a %= MOD; b; a = a * a % MOD, b >>= 1)if (b & 1) res = res * a % MOD;return res;}
// clang-format on

class BAbbreviateFox {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N;
    cin >> N;
    string S;
    cin >> S;
    map<int, char> check;
    rep(i, N) check[i] = S[i];
    int ans            = 0;
    int L;
    int R;
    rep(i, N - 2) {
      if (check[i] == 'f' and check[i + 1] == 'o' and check[i + 2] == 'x') {
        L = i;
        R = i + 2;
        ans++;
        auto LL = check.find(i);
        auto RR = check.find(i + 2);
        if (LL == check.begin() or RR == check.end()) continue;
        LL = prev(LL, 1);
        RR = next(RR, 1);
        check.erase(i);
        check.erase(i + 1);
        check.erase(i + 2);
        i = i + 2;
        while (1) {
          if (LL != check.begin()) {
            auto LLL = prev(LL, 1);
            if (LLL->second == 'f' and LL->second == 'o' and RR->second == 'x') {
              ans++;
              i = RR->first;
              if (LL == begin(check) or RR == end(check)) {
                check.erase(LLL);
                check.erase(LL);
                check.erase(RR);
                break;
              }
              LL = prev(LLL, 1);
              RR = next(RR, 1);
              check.erase(LLL);
              check.erase(LL);
              check.erase(RR);
              continue;
            }
          }
          if (RR != end(check)) {
            auto RRR = next(RR, 1);
            if (LL->second == 'f' and RR->second == 'o' and RRR->second == 'x') {
              ans++;
              i = RRR->first;
              if (LL == begin(check) or RR == end(check)) {
                check.erase(LL);
                check.erase(RR);
                check.erase(RRR);
                break;
              }
              LL = prev(LL, 1);
              RR = next(RRR, 1);
              check.erase(LL);
              check.erase(RR);
              check.erase(RRR);
              continue;
            }
          }
          break;
        }
      }
    }
    cout << N - 3 * ans << endl;
  }
};


signed main() {
  BAbbreviateFox solver;
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
					<td class="text-center"><time class='fixtime fixtime-second'>2020-11-21 22:11:48+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/arc108/tasks/arc108_e">E - Random IS</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/arc108/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
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
					<td class="text-center">3930 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Wrong Answer">WA</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">5 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">3780 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In static member function ‘static void BAbbreviateFox::solve(std::istream&, std::ostream&)’:
./Main.cpp:53:9: warning: variable ‘L’ set but not used [-Wunused-but-set-variable]
   53 |     int L;
      |         ^
./Main.cpp:54:9: warning: variable ‘R’ set but not used [-Wunused-but-set-variable]
   54 |     int R;
      |         ^
