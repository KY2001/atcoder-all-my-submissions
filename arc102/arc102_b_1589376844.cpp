/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

#include "bits/stdc++.h"
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define inv(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define Endl endl

using namespace std;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }
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

class DAllYourPathsAreDifferentLengths {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    int L;
    cin >> L;
    int N = 20;
    map<int, vector<pair<int, int>>> edge;
    rep(i, N - 1) edge[0].emplace_back(i + 1, i + 2);
    int k = 0;
    rep(i, 19) {
      if (bpm(2, i + 1) - 1 > L) {
        k = i - 1;
        break;
      } else if (i == 18) {
        k = i - 1;
      }
    }
    L -= bpm(2, k + 1) - 1;
    rep(i, k + 1) {
      edge[bpm(2, i)].emplace_back(N - (i + 1), N - i);
    }
    int now = 2;
    while (L) {
      rep(i, 19) {
        if (bpm(2, i + 1) - 1 > L) {
          k = i - 1;
          break;
        } else if (i == 18) {
          k = i - 1;
        }
      }
      rep(i, k + 1) {
        edge[bpm(2, i) * now].emplace_back(N - (i + 1), N - i);
      }
      L -= bpm(2, k + 1) - 1;
      now++;
    }
    cout << N << " " << edge.size() << endl;
    for (auto &i : edge) {
      rep(j, i.second.size()) {
        cout << i.second[j].first << " " << i.second[j].second << " " << i.first << endl;
      }
    }
  }
};


signed main() {
  DAllYourPathsAreDifferentLengths solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
