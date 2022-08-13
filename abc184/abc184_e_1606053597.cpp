// clang-format off
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
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
int pow_mod(int a, int b) {int res = 1;for (a %= MOD; b; a = a * a % MOD, b >>= 1)if (b & 1) res = res * a % MOD;return res;}
// clang-format on
deque<pair<int, int>> pos;
void BFS(V<string> &grid, VV<int> &bfs, int x, int y, int X, int Y) {
  if (grid[x][y] == '#') return;
  if (bfs[x][y] > bfs[X][Y]) {
    bfs[x][y] = bfs[X][Y] + 1;
    pos.emplace_back(x, y);
  }
}
class EThirdAvenue {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int H, W;
    cin >> H >> W;
    VV<int> bfs(H + 2, V<int>(W + 2, INF));
    V<string> grid(H + 2);
    grid[0]     = string(W + 2, '#');
    grid[H + 1] = string(W + 2, '#');
    rep(i, H) {
      cin >> grid[i + 1];
      grid[i + 1] = '#' + grid[i + 1] + '#';
    }
    int X, Y;
    VV<pair<int, int>> alpha(200);
    rep(i, H) rep(j, W) alpha[grid[i + 1][j + 1]].emplace_back(i + 1, j + 1);
    rep(i, H) rep(j, W) if (grid[i + 1][j + 1] == 'S') {
      bfs[i + 1][j + 1] = 0;
      pos.emplace_back(i + 1, j + 1);
    }
    else if (grid[i + 1][j + 1] == 'G') {
      X = i + 1, Y = j + 1;
    }
    while (pos.size()) {
      int x = pos[0].first, y = pos[0].second;
      pos.pop_front();
      BFS(grid, bfs, x + 1, y, x, y);
      BFS(grid, bfs, x, y + 1, x, y);
      BFS(grid, bfs, x - 1, y, x, y);
      BFS(grid, bfs, x, y - 1, x, y);
      if ('a' <= grid[x][y] and grid[x][y] <= 'z') {
        FOR(i, alpha[grid[x][y]]) {
          BFS(grid, bfs, i.first, i.second, x, y);
        }
      }
    }
    if (bfs[X][Y] == INF) {
      cout << -1 << endl;
    } else {
      cout << bfs[X][Y] << endl;
    }
  }
};
</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2020-11-22 22:59:57+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc184/tasks/abc184_e">E - Third Avenue</a></td>
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
					<td class="text-center">3090 Byte</td>
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
