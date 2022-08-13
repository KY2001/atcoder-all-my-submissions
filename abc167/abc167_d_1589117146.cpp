/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define Endl endl

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

int ceil_(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * ceil_(a, b)); }
int bpm(int x, unsigned int y) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  int ans   = 1;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  x %= MOD;
  for (int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) ans = ans * x % MOD;
    x = x * x % MOD;
  }
  return ans;
}
template <class T>
void cumulative_sum(T &container) {
  for (int i = 0; i < container.size() - 1; i++) container[i + 1] += container[i];
}

class DTeleporter {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int first;
    int now = 1;
    int num;
    vector<int> temp{};
    map<int, int> where{};
    FOR(i, 1, 10000000) {
      temp.emplace_back(now);
      if (where[now]) {
        num   = i - where[now];
        first = where[now] - 1;
        break;
      }
      where[now] = i;
      now        = A[now - 1];
    }
    if (K >= first){
      cout << temp[(K - first) % num + first] << endl;
    }else{
      cout<<temp[K]<<endl;
    }
  }
};


signed main() {
  DTeleporter solver;
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
					<td class="text-center"><time class='fixtime fixtime-second'>2020-05-10 22:25:46+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc167/tasks/abc167_d">D - Teleporter</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc167/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (GCC 9.2.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">400</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">2115 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">171 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">18476 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In static member function ‘static void DTeleporter::solve(std::istream&, std::ostream&)’:
./Main.cpp:65:32: warning: ‘num’ may be used uninitialized in this function [-Wmaybe-uninitialized]
   65 |       cout << temp[(K - first) % num + first] << endl;
      |                    ~~~~~~~~~~~~^~~~~
./Main.cpp:65:23: warning: ‘first’ may be used uninitialized in this function [-Wmaybe-uninitialized]
   65 |       cout << temp[(K - first) % num + first] << endl;
      |                    ~~~^~~~~~~~