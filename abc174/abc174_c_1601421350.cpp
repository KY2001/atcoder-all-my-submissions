/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

#include "bits/stdc++.h"
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define FOR(i, a) for (auto &i : a)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define SUM(x) accumulate(ALL(x), 0LL)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
const int MOD   = (int)(1e9 + 7);
const int INF   = (int)(1e13 + 7);
const double EPS = 1e-14;
const double PI = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int bpm(int a, int b) {                                                             //return x^y in order(log(y))
  int res = 1;
  for (a %= MOD; b; a = a * a % MOD, b >>= 1)
    if (b & 1) res = res * a % MOD;
  return res;
}

class CRepsept {
public:
  static void solve(istream &cin, ostream &cout) {
    int K;
    cin>>K;
    int val = 0;
    int now = 1;
    rep(i, bpm(10, 7)){
      val += now*7;
      now *= 10;
      val = mod(val, K);
      now = mod(now, K);
      if (not val){
        cout<<i+1<<endl;
        return;
      }
    }
    cout<<-1<<endl;
  }
};


signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
  CRepsept solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}