#include "bits/stdc++.h"
#define int long long
#define rep(i, n)           for (int i = 0; i < (int)(n); i++)
#define REP(i, a, b)        for (int i = (int)(a); i < (int)(b); i++)
#define FOR(i, a)           for (auto &i : a)
#define ALL(obj)            begin(obj), end(obj)
#define MAX(x)              *max_element(ALL(x))
#define MIN(x)              *min_element(ALL(x))
#define SUM(x)              accumulate(ALL(x), 0LL)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
const int MOD    = (int)(1e9 + 7);
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-14;
const double PI  = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int bpm(int a, int b) {                                                             //return x^y in order(log(y))
  int res = 1;
  for (a %= MOD; b; a = a * a % MOD, b >>= 1)
    if (b & 1) res = res * a % MOD;
  return res;
}

class EPickingGoods {
public:
  static void solve(istream &cin, ostream &cout) {
    int R, C, K;
    cin >> R >> C >> K;
    int ans = 0;
    vector<vector<int>> items(R + 2, vector<int>(C + 2, 0));
    rep(i, R + 2) {
      items[i][0]     = -1;
      items[i][C + 1] = -1;
    }
    rep(i, C + 2) {
      items[0][i]     = -1;
      items[R + 1][i] = -1;
    }
    rep(i, K) {
      int r, c, v;
      cin >> r >> c >> v;
      items[r][c] = v;
    }
    vector<vector<vector<int>>> scores(R + 2, vector<vector<int>>(C + 2, {-INF, -INF, -INF, -INF}));
    deque<vector<int>> pos = {{1, 1, 0, 0}, {1, 1, items[1][1], 1}};
    while (pos.size()) {
      int y     = pos[0][0];
      int x     = pos[0][1];
      int score = pos[0][2];
      int num   = pos[0][3];
      pos.pop_front();
      if (items[y][x + 1] != -1) {
        if (scores[y][x + 1][num] < score) {
          pos.push_back({y, x + 1, score, num});
          scores[y][x + 1][num] = score;
          ans                   = max(ans, score);
        }
        if (num <= 2) {
          if (scores[y][x + 1][num + 1] < score + items[y][x + 1]) {
            pos.push_back({y, x + 1, score + items[y][x + 1], num + 1});
            scores[y][x + 1][num + 1] = score + items[y][x + 1];
            ans                       = max(ans, score + items[y][x + 1]);
          }
        }
      }
      if (items[y + 1][x] != -1) {
        if (scores[y + 1][x][1] < score + items[y + 1][x]) {
          pos.push_back({y + 1, x, score + items[y + 1][x], 1});
          scores[y + 1][x][1] = score + items[y + 1][x];
          ans                 = max(ans, score + items[y + 1][x]);
        }
        if (scores[y + 1][x][0] < score) {
          pos.push_back({y + 1, x, score, 0});
          scores[y + 1][x][0] = score;
          ans                 = max(ans, score);
        }
      }
    }
    cout << ans << endl;
  }
};
</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2020-08-15 22:52:47+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc175/tasks/abc175_e">E - Picking Goods</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc175/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
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
					<td class="text-center">3133 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Compilation Error">CE</span></td>
				</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>/usr/lib/gcc/x86_64-linux-gnu/9/../../../x86_64-linux-gnu/Scrt1.o: In function `_start':
(.text+0x20): undefined reference to `main'
collect2: error: ld returned 1 exit status
