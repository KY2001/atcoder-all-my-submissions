#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define sqr(x) (x) * (x)
#define cube(x) (z) * (z) * (x)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define itn int

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

template <class T = int>
int in() {
  T x;
  cin >> x;
  return x;
}
unordered_map<int, int> element_num; //change type if you need
template <class T>
void counter(T container) {
  for (int i = 0; i < container.size(); i++) {
    element_num[container[i]] += 1;
  }
}
signed main() {
  int N = in();
  vector<int> A(N - 1);
  rep(i, N - 1) {
    cin >> A[i];
  }
  counter(A);
  rep(i, N) {
    cout << element_num[i + 1] << endl;
  }
}
