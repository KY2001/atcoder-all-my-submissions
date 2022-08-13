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
#define sum(x)              accumulate(ALL(x), 0LL)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
const int MOD    = (int)(1e9 + 7);
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-14;
const double PI  = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int bpm(int a, int b) {                                                             //return x^y in order(log(y))
  int res = 1;
  for (a %= MOD; b; a = a * a % MOD, b >>= 1)
    if (b & 1) res = res * a % MOD;
  return res;
}

class N {
public:
  static void solve(istream &cin, ostream &cout) {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    rep(i, N) a[i] = i + 1;
    map<int, int> check;
    rep(i, Q) {
      int t, x, y;
      cin >> t >> x >> y;
      if (t == 1) {
        check[x - 1]++;
        check[x]++;
        swap(a[x - 1], a[x]);
      } else {
        auto L = check.lower_bound(x - 1);
        auto R = check.lower_bound(y - 1);
        vector<int> del;
        for (auto j = L; true; j = next(j, 1)) {
          if (j->first >= x - 1 and j->first <= y - 1) del.emplace_back(j->first);
          if (j == R) break;
        }
        int p = 1;
        while (p) {
          p = 0;
          for (auto j = L; true; j = next(j, 1)) {
            int tmp = j->first;
            if (a[tmp - 1] > a[tmp] and tmp >= x and tmp <= y - 1) {
              swap(a[tmp - 1], a[tmp]);
              p++;
            }
            if (a[tmp] > a[tmp + 1] and tmp >= x - 1 and tmp + 1 <= y - 1) {
              swap(a[tmp], a[tmp + 1]);
              p++;
            }
            if (j == R) break;
          }
        }
        FOR(j, del) {
          check.erase(j);
        }
      }
    }
    FOR(i, a) {
      cout << i << " ";
    }
    cout << endl;
  }
};


signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
  N solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
