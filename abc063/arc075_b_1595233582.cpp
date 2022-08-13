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
#define SUM(x)              accumulate(ALL(x), 0LL)
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
int N, A, B;
vector<int> h;
vector<int> temp;
bool judge(int mid) {
  temp      = h;
  int temp2 = 0;
  rep(i, N) {
    if (temp[i] - B * mid > 0) {
      temp2 += CEIL((temp[i] - B * mid), A);
    }
  }
  return temp2 <= mid;
}

int bisect(int L, int R) {
  int mid = (L + R) / 2;
  bool a, b;
  a = judge(mid - 1);
  b = judge(mid);
  if (not a and b) {
    return mid;
  } else if (a and b) {
    return bisect(L, mid);
  } else {
    return bisect(mid, R);
  }
}

class DWidespread {
public:
  static void solve(istream &cin, ostream &cout) {
    cin >> N >> A >> B;
    A = A - B;
    h.assign(N, 0);
    rep(i, N) cin >> h[i];
    cout << bisect(2, bpm(10, 9)) << endl;
  }
};


signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
  DWidespread solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
