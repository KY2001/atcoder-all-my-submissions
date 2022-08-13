/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 * 解説AC
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

int get_num(string &a) {
  int ret = 0;
  for (auto &i : a)
    if (i == '(') ret++;
  return ret;
}

class FBracketSequencing {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    vector<vector<int>> a(N, vector<int>(3, -INF));
    rep(i, N) {
      a[i][2] = i;
      int L = 0, R = 0;
      rep(j, S[i].size()) {
        if (S[i][j] == '(') {
          L++;
        } else {
          R++;
        }
        a[i][0] = max(a[i][0], R - L);
      }
      a[i][1] = -(L - R);
    }
    vector<vector<int>> first;
    vector<vector<int>> second;
    vector<vector<int>> third;
    rep(i, N) {
      if (a[i][0] <= 0 and -a[i][1] >= 0) {
        first.emplace_back(a[i]);
      } else if (a[i][0] > 0 and -a[i][1] >= 0) {
        second.emplace_back(a[i]);
      } else {
        a[i][0] = a[i][1];
        third.emplace_back(a[i]);
      }
    }
    string ans{};
    rep(i, first.size()) ans += S[first[i][2]];
    sort(ALL(second));
    sort(ALL(third));
    rep(i, second.size()) ans += S[second[i][2]];
    rep(i, third.size()) ans += S[third[i][2]];
    int L = 0;
    int R = 0;
    rep(i, ans.size()) {
      if (ans[i] == '(') {
        L++;
      } else {
        R++;
      }
      if (R > L) {
        cout << "No" << endl;
        return;
      }
    }
    if (L == R) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
};


signed main() {
  FBracketSequencing solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}