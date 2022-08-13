/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

#include "bits/stdc++.h"
#define int long long
#define rep(i, n)           for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b)        for (int i = (int)(a); i < (int)(b); i++)
#define inv(i, a, b)        for (int i = (int)(a); i >= (int)(b); i--)
#define ALL(obj)            begin(obj), end(obj)
#define MAX(x)              *max_element(ALL(x))
#define MIN(x)              *min_element(ALL(x))
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define Endl                endl

using namespace std;
const int MOD   = (int)(1e9 + 7);
const int INF   = (int)(1e13 + 7);
const double PI = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int bpm(int x, unsigned int y) {                                                    //return x^y in order(log(y))
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

class CHonestOrUnkind2 {
public:
  static void solve(istream &cin, ostream &cout) {
    int N;
    cin >> N;
    int ans = 0;
    vector<vector<pair<int, int>>> xy(N);
    rep(i, N) {
      int A;
      cin >> A;
      rep(j, A) {
        int x, y;
        cin >> x >> y;
        xy[i].emplace_back(x, y);
      }
    }
    rep(i, bpm(2, 15)) {
      vector<int> check(N + 1);
      rep(j, N) {
        if ((i >> j) & 1) {
          check[j + 1] = 1;
        } else {
          check[j + 1] = 0;
        }
      }
      int temp = 0;
      rep(j, N) {
        if ((i >> j) & 1) {
          temp++;
          for (auto &k : xy[j]) {
            if (check[k.first] != k.second) {
              goto label;
            }
          }
        }
      }
      ans = max(ans, temp);
    label:;
    }
    cout << ans << endl;
  }
};


signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  CHonestOrUnkind2 solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
