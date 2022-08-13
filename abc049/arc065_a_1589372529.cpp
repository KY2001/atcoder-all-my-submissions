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

class C {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    string S;
    cin >> S;
    string T{};
    while (T.size() != S.size()) {
      if (S[T.size()] == 'd') {
        if (S[T.size() + 5] == 'e') {
          if (S[T.size() + 7] == 'a') {
            T += "dream";
          } else {
            T += "dreamer";
          }
        } else {
          T += "dream";
        }
      } else if (S[T.size()] == 'e') {
        if (S[T.size() + 5] != 'r') {
          T += "erase";
        } else {
          T += "eraser";
        }
      } else {
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
  }
};


signed main() {
  C solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
