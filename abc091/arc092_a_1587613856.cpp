/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author KY2001
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

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

int bpm(int x, int y) {
  if (x == 0)
    return 0;
  else if (y == 0) {
    return 1;
  }
  int ans = 1;
  x %= MOD;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  for (int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) {
      ans *= x;
      ans %= MOD;
    }
    x = x * x;
    x %= MOD;
  }
  return ans;
}

class C2DPlane2NPoints {
public:
  int solve(std::istream &cin, std::ostream &cout) {
    int N;
    cin >> N;
    vector<pair<int, int>> a(N);
    vector<pair<int, int>> b(N);
    vector<vector<int>> a_grid(2 * N + 1, vector<int>(2 * N + 1, 0));
    vector<vector<int>> b_grid(2 * N + 1, vector<int>(2 * N + 1, 0));
    rep(i, N) {
      cin >> a[i].first >> a[i].second;
      a_grid[a[i].first][a[i].second] = 1;
    }
    rep(i, N) {
      cin >> b[i].first >> b[i].second;
      b_grid[b[i].first][b[i].second] = 1;
    }
    int ans = 0;
    rep(i, 2 * N + 1) {
      rep(j, 2 * N + 1) {
        if (b_grid[i][j]) {
          rep(x, i) {
            rep(y, j) {
              if (a_grid[x][j - y - 1]) {
                ans += 1;
                a_grid[x][j - y - 1] = 0;
                goto out;
              }
            }
          }
        }
      }
    out:;
    }
    cout << ans << endl;
  }
};


signed main() {
	C2DPlane2NPoints solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}