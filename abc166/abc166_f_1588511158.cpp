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
  for (unsigned int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) ans = ans * x % MOD;
    x = x * x % MOD;
  }
  return ans;
}
template <class T>
void cumulative_sum(T &container) {
  for (int i = 0; i < container.size() - 1; i++) container[i + 1] += container[i];
}

class FThreeVariablesGame {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> abc = {A, B, C};
    string abc2     = "ABC";
    vector<string> S(N);
    vector<char> ans(N);
    int zero = 0;
    if (A == 0) zero++;
    if (B == 0) zero++;
    if (C == 0) zero++;
    if (zero == 2 and A + B + C >= 2) {
      rep(i, N) {
        string temp;
        cin >> temp;
        int first  = temp[0] - 'A';
        int second = temp[1] - 'A';
        if (abc[first] and abc[second] == 0) {
          abc[second]++;
          abc[first]--;
          ans[i] = abc2[second];
        } else if (abc[first] == 0 and abc[second]) {
          abc[second]--;
          abc[first]++;
          ans[i] = abc2[first];
        } else {
          cout << "No" << endl;
          return;
        }
      }
    } else if (A + B + C >= 2) {
      cout << "Yes" << endl;
      rep(i, N) {
        string temp;
        cin >> temp;
        int first  = temp[0] - 'A';
        int second = temp[1] - 'A';
        if (abc[first] == 1 and abc[second] == 0) {
          abc[second] = 1;
          abc[first]  = 0;
          cout << abc2[second] << endl;
        } else if (abc[first] == 0 and abc[second] == 1) {
          abc[second] = 0;
          abc[first]  = 1;
          cout << abc2[first] << endl;
        } else {
          abc[second]++;
          abc[first]--;
          cout << abc2[second] << endl;
        }
      }
      return;
    } else if (A + B + C == 0) {
      cout << "No" << endl;
    } else {
      rep(i, N) {
        string temp;
        cin >> temp;
        int first  = temp[0] - 'A';
        int second = temp[1] - 'A';
        if (abc[first] == 1 and abc[second] == 0) {
          abc[second] = 1;
          abc[first]  = 0;
          ans[i]      = abc2[second];
        } else if (abc[first] == 0 and abc[second] == 1) {
          abc[second] = 0;
          abc[first]  = 1;
          ans[i]      = abc2[first];
        } else {
          cout << "No" << endl;
          return;
        }
      }
      cout << "Yes" << endl;
      rep(i, N) {
        cout << ans[i] << endl;
      }
    }
  }
};


signed main() {
  FThreeVariablesGame solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
