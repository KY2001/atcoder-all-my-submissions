/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

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

class DSimpleKnapsack {
public:
  static void solve(istream &cin, ostream &cout) {
    int N, W;
    cin >> N >> W;
    vector<pair<int, int>> wv(N);
    rep(i, N) cin >> wv[i].first >> wv[i].second;
    rep(i, N - 1) wv[i + 1].first -= wv[0].first;
    int temp    = wv[0].first;
    wv[0].first = 0;
    vector<vector<vector<int>>> dp(N + 10, vector<vector<int>>(3 * N + 10, vector<int>(N + 10, -INF)));
    dp[0][0][1] = wv[0].second;
    dp[0][0][0] = 0;
    rep(i, N - 1) {
      rep(j, 3 * N + 1) {
        rep(k, N) {
          dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
          if (j + wv[i + 1].first + (k + 1) * temp <= W) {
            dp[i + 1][j + wv[i + 1].first][k + 1] = max(dp[i + 1][j + wv[i + 1].first][k + 1], dp[i][j][k] + wv[i + 1].second);
          }
        }
      }
    }
    int ans = -INF;
    FOR(i, dp[N - 1]) {
      FOR(j, i) {
        ans = max(ans, j);
      }
    }
    if (temp > W){
      cout<<0<<endl;
      return;
    }
    cout << ans << endl;
  }
};


signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
  DSimpleKnapsack solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}