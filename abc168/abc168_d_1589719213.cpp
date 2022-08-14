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
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

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

class DDoubleDots {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    int N, M;
    cin >> N >> M;
    vector<int> ans(N, 0);
    deque<int> pos = {0};
    vector<vector<int>> road(N);
    rep(i, M) {
      int A, B;
      cin >> A >> B;
      road[A - 1].emplace_back(B - 1);
      road[B - 1].emplace_back(A - 1);
    }
    while (pos.size()) {
      int k = pos[0];
      pos.pop_front();
      rep(i, road[k].size()) {
        if (ans[road[k][i]] == 0) {
          ans[road[k][i]] = k + 1;
          pos.emplace_back(road[k][i]);
        }
      }
    }
    cout << "Yes" << Endl;
    rep(i, ans.size() - 1) {
      cout << ans[i + 1] << endl;
    }
  }
};
