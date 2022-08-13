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

int ceil_(int a, int b) { return (a + (b - 1)) / b; }
int positive_surplus(int &a) { return (a + MOD) % MOD; }
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

class B {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> b;
    vector<string> ans;
    rep(i, N) {
      string temp;
      cin >> temp;
      vector<int> temp2(M);
      rep(j, M) temp2[j] = temp[j] - '0';
      b.emplace_back(temp2);
    }
    ans.emplace_back(string(M, '0'));
    FOR(i, 1, N - 1) {
      string temp_ans = "0";
      FOR(j, 1, M - 1) {
        int a_i = min(b[i][j - 1], min(b[i][j + 1], min(b[i + 1][j], b[i - 1][j])));
        temp_ans += to_string(a_i);
        b[i][j - 1] -= a_i;
        b[i][j + 1] -= a_i;
        b[i - 1][j] -= a_i;
        b[i + 1][j] -= a_i;
      }
      temp_ans += "0";
      ans.emplace_back(temp_ans);
    }
    ans.emplace_back(string(M, '0'));
    rep(i, N) cout << ans[i] << endl;
  }
};


signed main() {
  B solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
