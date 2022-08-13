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
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define Endl                endl

using namespace std;
const int MOD   = (int)(1e9 + 7);
const int INF   = (int)(1e13 + 7);
const double PI = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int bpm(int x, int y) {                                                             //return x^y in order(log(y))
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
struct trio {
  T first{};
  T second{};
  T third{};
};
template <class T>
void cumulative_sum(T &container) {
  for (int i = 0; i < container.size() - 1; i++) container[i + 1] += container[i];
}
int factorial(int n) {
  int ret = 1;
  for (int i = 2; i <= n; i++) ret *= i;
  return ret;
}

class DXorSum2 {
public:
  static void solve(istream &cin, ostream &cout) {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> ans(N, 0);
    int now = A[0];
    int R   = 0;
    int L   = 0;
    while (!(R == N - 1 and L == N - 1)) {
      ans[L] = max(ans[L], R);
      if (R == N - 1) {
        break;
      }
      rep(i, 20) {
        if ((now >> i) & (A[R + 1] >> i)) {
          if (R == L) {
            R++;
            L++;
            now = A[R];
            break;
          } else {
            rep(j, 20) {
              if ((now >> j) & 1 and (A[L] >> j) & 1) {
                now -= bpm(2, j);
              }
            }
            L++;
            break;
          }
        } else if (i == 19) {
          R++;
          rep(j, 20) {
            if ((A[R] >> j) & 1 == 1) {
              now += bpm(2, j);
            }
          }
          break;
        }
      }
    }
    int sum = 0;
    int k   = ans[0];
    rep(i, N) {
      k = max(k, i);
      k = max(k, ans[i]);
      sum += (k - i + 1);
    }
    cout << sum << endl;
  }
};


signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  DXorSum2 solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
