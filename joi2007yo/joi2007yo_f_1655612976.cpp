// clang-format off
#include <bits/stdc++.h>
#pragma GCC target("avx,avx2")
#pragma GCC optimize ("-Ofast")
#pragma GCC optimize ("unroll-loops")
#define endl '\n'
using namespace std;
#define fi first
#define se second
#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; i++)
#define rep2(i, a, b) for (int i = (int)(a), i##_len=(b); i < i##_len; i++)
#define rep3(i, a, b) for (int i = (int)(a), i##_len=(b); i >= i##_len; i--)
#define rfor(i, a) for (auto &i: a)
#define all(obj) begin(obj), end(obj)
#define _max(x) *max_element(all(x))
#define _min(x) *min_element(all(x))
#define _sum(x) accumulate(all(x), 0LL)

const int MOD   = 1000000007;
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
double _mod(double a, int mod = MOD) { return fmod(a, mod) >= 0 ? fmod(a, mod) : fmod(a, mod) + mod; }
int _pow(int a, int b, int mod=MOD) {int res = 1;for (a %= mod; b; a = a * a % mod, b >>= 1)if (b & 1) res = res * a % mod;return res;}
vector<int> iota(int n){vector<int> ret(n); iota(begin(ret), end(ret), 0); return ret;}
struct mint {long long x;mint(long long x = 0): x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) {(x *= a.x) %= MOD;return *this;}mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; }mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long n) const {mint ret(1), mul(x);while (n > 0) {if (n & 1) ret *= mul;mul *= mul;n >>= 1;}return ret;}mint inv() const {int a = x, b = MOD, u = 1, v = 0, t;while (b > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);}return mint(u);}mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }bool operator==(const mint a) const { return x == a.x; }bool operator!=(const mint a) const { return x != a.x; }friend istream &operator>>(istream &is, mint &a) { return is >> a.x; }friend ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }};
// clang-format on

int a, b;
set<P<int, int>> check;

//計算量nCr*k
void dfs(int _n, int _w, vector<int> &comb, int &ans) {
    if (comb.empty()) {
        rep2(i, 0, _n - _w + comb.size() + 1) {
            comb.emplace_back(i);
            dfs(_n, _w, comb, ans);
            comb.pop_back();
        }
        return;
    }
    if (comb.back() + (_w - comb.size()) > _n - 1) return;
    if (comb.size() == _w) {
        ans++;
        int X = 1, Y = 1;
        int now = 0;
        rep(j, a + b - 2) {
            if (check.count({X, Y})) {
                ans--;
                break;
            }
            if (j == comb[now]) {
                X++;
                if (now < _w - 1) now++;
            } else {
                Y++;
            }
        }
        return;
    }
    rep2(i, comb.back() + 1, _n - _w + comb.size() + 1) {
        comb.emplace_back(i);
        dfs(_n, _w, comb, ans);
        comb.pop_back();
    }
}

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int n, x, y;
    cin >> a >> b;
    cin >> n;
    check.clear();
    rep(i, n) {
        cin >> x >> y;
        check.insert({x, y});
    }
    V<int> comb;
    int ans = 0;
    dfs(a + b - 2, a - 1, comb, ans);
    cout << ans << endl;
}</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2022-06-19 13:29:36+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/joi2007yo/tasks/joi2007yo_f">F - 通学経路</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/joi2007yo/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
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
					<td class="text-center">4287 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">8288 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">3620 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In function ‘void dfs(int, int, std::vector<int>&, int&)’:
./Main.cpp:50:42: warning: comparison of integer expressions of different signedness: ‘std::vector<int>::size_type’ {aka ‘long unsigned int’} and ‘int’ [-Wsign-compare]
   50 |     if (comb.back() + (_w - comb.size()) > _n - 1) return;
      |         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~
./Main.cpp:51:21: warning: comparison of integer expressions of different signedness: ‘std::vector<int>::size_type’ {aka ‘long unsigned int’} and ‘int’ [-Wsign-compare]
   51 |     if (comb.size() == _w) {
      |         ~~~~~~~~~~~~^~~~~
