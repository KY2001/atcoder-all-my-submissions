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
vector<char> non_duplication; //change if you need
template <class T>
void without_duplication(T a) {
  non_duplication.emplace_back(a[0]);
  for (int i = 1; i < a.size(); i++)
    if (a[i] != a[i - 1]) non_duplication.push_back(a[i]);
}
class AShrinking {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    string s;
    cin >> s;
    int N   = s.size();
    int ans = INF;
    non_duplication = {};
    without_duplication(s);
    if (non_duplication.size() == 1) {
      cout << 0 << endl;
      return;
    }
    rep(i, N) {
      char temp2 = s[i];
      string temp{};
      rep(j, N) temp += s[j];
      int time = 0;
      while (true) {
        rep(j, N - 1) {
          if (temp[j] != temp2 and temp[j + 1] == temp2) {
            temp[j] = temp2;
          }
        }
        temp.pop_back();
        time++;
        non_duplication = {};
        without_duplication(temp);
        if (non_duplication.size() == 1) {
          ans = min(ans, time);
          break;
        }
      }
    }
    cout << ans << endl;
  }
};


signed main() {
  AShrinking solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
