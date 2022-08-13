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

const int MOD   = 1000000007;
// const int MOD    = 998244353;
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-8;
const double PI  = 3.14159265358979;
template <class T> using V = vector<T>;
template <class T> using VV = vector<vector<T>>;
template <class T> using VVV = vector<vector<vector<T>>>;
template <class T, class S>  using P = pair<T, S>;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return true;}return false;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return true;}return false;}
int _ceil(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
int _mod(int a) {return a >= 0 ? a % MOD : a - (MOD * _ceil(a, MOD));}
int _pow(int a, int b) {int res = 1;for (a %= MOD; b; a = a * a % MOD, b >>= 1)if (b & 1) res = res * a % MOD;return res;}
struct mint {long long x;mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) { (x *= a.x) %= MOD;return *this; }mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; } mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long t) const {if (!t) return 1;mint a = pow(t >> 1);a *= a;if (t & 1) a *= *this;return a;}mint inv() const { return pow(MOD - 2); }mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }};istream &operator>>(istream &is, mint &a) { return is >> a.x; }ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
// clang-format on

void func(V<string> &S, V<P<int, int>> &ans, int k, VV<bool> &already) {
  if (ans.size() == k) {
    FOR(i, ans)
    cout << i.fi << " " << i.se << endl;
    exit(0);
  }
  int y = ans[ans.size() - 1].fi, x = ans[ans.size() - 1].se;
  if (S[y + 1][x] == '#' and !already[y + 1][x]) {
    ans.emplace_back(y + 1, x);
    already[y + 1][x] = true;
    func(S, ans, k, already);
    ans.pop_back();
    already[y + 1][x] = false;
  }
  if (S[y - 1][x] == '#' and !already[y - 1][x]) {
    ans.emplace_back(y - 1, x);
    already[y - 1][x] = true;
    func(S, ans, k, already);
    ans.pop_back();
    already[y - 1][x] = false;
  }
  if (S[y][x + 1] == '#' and !already[y][x + 1]) {
    ans.emplace_back(y, x + 1);
    already[y][x + 1] = true;
    func(S, ans, k, already);
    ans.pop_back();
    already[y][x + 1] = false;
  }
  if (S[y][x - 1] == '#' and !already[y][x - 1]) {
    ans.emplace_back(y, x - 1);
    already[y][x - 1] = true;
    func(S, ans, k, already);
    ans.pop_back();
    already[y][x - 1] = false;
  }
}

class G {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int H, W;
    cin >> H >> W;
    V<string> S(H + 2);
    S[0]     = string(W + 2, '.');
    S[H + 1] = string(W + 2, '.');
    rep(i, H) {
      cin >> S[i + 1];
      S[i + 1] = '.' + S[i + 1] + '.';
    }
    int k = 0;
    rep(i, H + 2) rep(j, W + 2) if (S[i][j] == '#') k++;
    cout << k << endl;
    rep2(i, 1, H + 1) rep2(j, 1, W + 1) {
      if (S[i][j] != '#') continue;
      VV<bool> already(H + 2, V<bool>(W + 2));
      V<P<int, int>> ans = {{i, j}};
      already[i][j]      = true;
      func(S, ans, k, already);
    }
  }
};


signed main() {
  G solver;
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
					<td class="text-center"><time class='fixtime fixtime-second'>2021-01-02 04:06:07+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/past202012-open/tasks/past202012_g">G - Snake</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/past202012-open/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (GCC 9.2.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">6</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">4553 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">9 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">3644 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In function ‘void func(V<std::__cxx11::basic_string<char> >&, V<std::pair<long long int, long long int> >&, long long int, VV<bool>&)’:
./Main.cpp:45:18: warning: comparison of integer expressions of different signedness: ‘std::vector<std::pair<long long int, long long int>, std::allocator<std::pair<long long int, long long int> > >::size_type’ {aka ‘long unsigned int’} and ‘long long int’ [-Wsign-compare]
   45 |   if (ans.size() == k) {
      |       ~~~~~~~~~~~^~~~
