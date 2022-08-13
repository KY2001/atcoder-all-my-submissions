/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

#include <bits/stdc++.h>
#define int long long
#define rep(i, n)           for (int i = 0; i < (int)(n); i++)         // [0, b)
#define rep2(i, a, b)       for (int i = (int)(a); i < (int)(b); i++)  // [a, b)
#define rep3(i, a, b)       for (int i = (int)(a); i >= (int)(b); i--) // reversed [b, a] so [a, a-1, a-2, ..., b]
#define FOR(i, a)           for (auto &i : a)
#define ALL(obj)            begin(obj), end(obj)
#define MAX(x)              *max_element(ALL(x))
#define MIN(x)              *min_element(ALL(x))
#define SUM(x)              accumulate(ALL(x), 0LL)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
const int MOD    = 998244353;
const int MOD2   = 1000000007;
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-14;
const double PI  = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int pow_mod(int a, int b) {                                                         //return x^y in order(log(y))
  int res = 1;
  for (a %= MOD; b; a = a * a % MOD, b >>= 1)
    if (b & 1) res = res * a % MOD;
  return res;
}

class EAkari {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int H, W, N, M;
    cin >> H >> W >> N >> M;

    vector<vector<int>> row(H, vector<int>(0));
    vector<vector<int>> row2(H, vector<int>(0));
    vector<vector<int>> column(W, vector<int>(0));
    vector<vector<int>> column2(W, vector<int>(0));
    vector<vector<int>> grid(H, vector<int>(W, 0));
    rep(i, H) {
      sort(ALL(row[i]));
      sort(ALL(row2[i]));
    }
    rep(i, W) {
      sort(ALL(column[i]));
      sort(ALL(column2[i]));
    }
    rep(i, N) {
      int A, B;
      cin >> A >> B;
      row[A - 1].emplace_back(B - 1);
      column[B - 1].emplace_back(A - 1);
      grid[A - 1][B - 1]++;
    }
    rep(i, M) {
      int A, B;
      cin >> A >> B;
      row2[A - 1].emplace_back(B - 1);
      column2[B - 1].emplace_back(A - 1);
      grid[A - 1][B - 1]--;
    }
    int ans = 0;
    rep(i, H) {
      rep(j, W) {
        if (grid[i][j] == 1) {
          ans++;
        } else if (grid[i][j] == 0) {
          int right  = LOWER_BOUND(row[i], j);
          int right2 = LOWER_BOUND(row2[i], j);
          int left   = right - 1;
          int left2  = right2 - 1;
          int down   = LOWER_BOUND(column[j], i);
          int down2  = LOWER_BOUND(column2[j], i);
          int up     = down - 1;
          int up2    = down2 - 1;
          if ((0 <= right and right < row[i].size() and 0 <= right2 and right2 < row2[i].size())) {
            if (row[i][right] < row2[i][right2]) {
              ans++;
              continue;
            }
          } else if ((0 <= right and right < row[i].size())) {
            ans++;
            continue;
          }
          if ((0 <= left and left < row[i].size() and 0 <= left2 and left2 < row2[i].size())) {
            if (row[i][left] > row2[i][left2]) {
              ans++;
              continue;
            }
          } else if ((0 <= left and left < row[i].size())) {
            ans++;
            continue;
          }
          if (0 <= up and up < column[j].size() and 0 <= up2 and up2 < column2[j].size()) {
            if (column[j][up] > column2[j][up2]) {
              ans++;
              continue;
            }
          } else if (0 <= up and up < column[j].size()) {
            ans++;
            continue;
          }
          if (0 <= down and down < column[j].size() and 0 <= down2 and down2 < column2[j].size()) {
            if (column[j][down] < column2[j][down2]) {
              ans++;
              continue;
            }
          } else if (0 <= down and down < column[j].size()) {
            ans++;
            continue;
          }
        }
      }
    }
    cout << ans << endl;
  }
};


signed main() {
  EAkari solver;
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
					<td class="text-center"><time class='fixtime fixtime-second'>2020-11-09 09:04:31+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc182/tasks/abc182_e">E - Akari</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc182/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
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
					<td class="text-center">4517 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Wrong Answer">WA</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">384 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">36480 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In static member function ‘static void EAkari::solve(std::istream&, std::ostream&)’:
./Main.cpp:87:37: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   87 |           if ((0 <= right and right < row[i].size() and 0 <= right2 and right2 < row2[i].size())) {
      |                               ~~~~~~^~~~~~~~~~~~~~~
./Main.cpp:87:80: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   87 |           if ((0 <= right and right < row[i].size() and 0 <= right2 and right2 < row2[i].size())) {
      |                                                                         ~~~~~~~^~~~~~~~~~~~~~~~
./Main.cpp:92:44: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   92 |           } else if ((0 <= right and right < row[i].size())) {
      |                                      ~~~~~~^~~~~~~~~~~~~~~
./Main.cpp:96:35: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   96 |           if ((0 <= left and left < row[i].size() and 0 <= left2 and left2 < row2[i].size())) {
      |                              ~~~~~^~~~~~~~~~~~~~~
./Main.cpp:96:76: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   96 |           if ((0 <= left and left < row[i].size() and 0 <= left2 and left2 < row2[i].size())) {
      |                                                                      ~~~~~~^~~~~~~~~~~~~~~~
./Main.cpp:101:42: warning: comparison of integer expressi...