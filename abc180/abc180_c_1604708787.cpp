#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)             // [0, b)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)  // [a, b)
#define rep3(i, a, b) for (int i = (int)(a); i >= (int)(b); i--) // reversed [b, a] so [a, a-1, a-2, ..., b]
#define FOR(i, a) for (auto &i: a)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define SUM(x) accumulate(ALL(x), 0LL)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
const int MOD    = 998244353;
const int MOD2   = 1000000007;
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-14;
const double PI  = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int pow_mod(int a, int b) {                                                         //return x^y in order(log(y))
  int res = 1;
  for (a %= MOD; b; a = a * a % MOD, b >>= 1)
    if (b & 1) res = res * a % MOD;
  return res;
}

namespace FastPrimeFactorization {

template<typename word, typename dword, typename sword>
struct UnsafeMod {
  UnsafeMod(): x(0) {}

  UnsafeMod(word _x): x(init(_x)) {}

  bool operator==(const UnsafeMod &rhs) const {
    return x == rhs.x;
  }

  bool operator!=(const UnsafeMod &rhs) const {
    return x != rhs.x;
  }

  UnsafeMod &operator+=(const UnsafeMod &rhs) {
    if ((x += rhs.x) >= mod) x -= mod;
    return *this;
  }

  UnsafeMod &operator-=(const UnsafeMod &rhs) {
    if (sword(x -= rhs.x) < 0) x += mod;
    return *this;
  }

  UnsafeMod &operator*=(const UnsafeMod &rhs) {
    x = reduce(dword(x) * rhs.x);
    return *this;
  }

  UnsafeMod operator+(const UnsafeMod &rhs) const {
    return UnsafeMod(*this) += rhs;
  }

  UnsafeMod operator-(const UnsafeMod &rhs) const {
    return UnsafeMod(*this) -= rhs;
  }

  UnsafeMod operator*(const UnsafeMod &rhs) const {
    return UnsafeMod(*this) *= rhs;
  }

  UnsafeMod pow(uint64_t e) const {
    UnsafeMod ret(1);
    for (UnsafeMod base = *this; e; e >>= 1, base *= base) {
      if (e & 1) ret *= base;
    }
    return ret;
  }

  word get() const {
    return reduce(x);
  }

  static constexpr int word_bits = sizeof(word) * 8;

  static word modulus() {
    return mod;
  }

  static word init(word w) {
    return reduce(dword(w) * r2);
  }

  static void set_mod(word m) {
    mod = m;
    inv = mul_inv(mod);
    r2  = -dword(mod) % mod;
  }

  static word reduce(dword x) {
    word y = word(x >> word_bits) - word((dword(word(x) * inv) * mod) >> word_bits);
    return sword(y) < 0 ? y + mod : y;
  }

  static word mul_inv(word n, int e = 6, word x = 1) {
    return !e ? x : mul_inv(n, e - 1, x * (2 - x * n));
  }

  static word mod, inv, r2;

  word x;
};

using uint128_t = __uint128_t;

using Mod64                    = UnsafeMod<uint64_t, uint128_t, int64_t>;
template<> uint64_t Mod64::mod = 0;
template<> uint64_t Mod64::inv = 0;
template<> uint64_t Mod64::r2  = 0;

using Mod32                    = UnsafeMod<uint32_t, uint64_t, int32_t>;
template<> uint32_t Mod32::mod = 0;
template<> uint32_t Mod32::inv = 0;
template<> uint32_t Mod32::r2  = 0;

bool miller_rabin_primality_test_uint64(uint64_t n) {
  Mod64::set_mod(n);
  uint64_t d = n - 1;
  while (d % 2 == 0) d /= 2;
  Mod64 e{1}, rev{n - 1};
  // http://miller-rabin.appspot.com/  < 2^64
  for (uint64_t a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
    if (n <= a) break;
    uint64_t t = d;
    Mod64 y    = Mod64(a).pow(t);
    while (t != n - 1 && y != e && y != rev) {
      y *= y;
      t *= 2;
    }
    if (y != rev && t % 2 == 0) return false;
  }
  return true;
}

bool miller_rabin_primality_test_uint32(uint32_t n) {
  Mod32::set_mod(n);
  uint32_t d = n - 1;
  while (d % 2 == 0) d /= 2;
  Mod32 e{1}, rev{n - 1};
  for (uint32_t a: {2, 7, 61}) {
    if (n <= a) break;
    uint32_t t = d;
    Mod32 y    = Mod32(a).pow(t);
    while (t != n - 1 && y != e && y != rev) {
      y *= y;
      t *= 2;
    }
    if (y != rev && t % 2 == 0) return false;
  }
  return true;
}

bool is_prime(uint64_t n) {
  if (n == 2) return true;
  if (n == 1 || n % 2 == 0) return false;
  if (n < uint64_t(1) << 31) return miller_rabin_primality_test_uint32(n);
  return miller_rabin_primality_test_uint64(n);
}

uint64_t pollard_rho(uint64_t n) {
  if (is_prime(n)) return n;
  if (n % 2 == 0) return 2;
  Mod64::set_mod(n);
  uint64_t d;
  Mod64 one{1};
  for (Mod64 c{one};; c += one) {
    Mod64 x{2}, y{2};
    do {
      x = x * x + c;
      y = y * y + c;
      y = y * y + c;
      d = __gcd((x - y).get(), n);
    } while (d == 1);
    if (d < n) return d;
  }
  assert(0);
}

vector<uint64_t> prime_factor(uint64_t n) {
  if (n <= 1) return {};
  uint64_t p = pollard_rho(n);
  if (p == n) return {p};
  auto l = prime_factor(p);
  auto r = prime_factor(n / p);
  copy(begin(r), end(r), back_inserter(l));
  return l;
}
}; // namespace FastPrimeFactorization

vector<int> divisor;
void product(vector<int> &change, vector<int> &a, vector<int> &b, vector<vector<int>> &ab, int now = 0) {
  int a_size = a.size();
  if (now == a_size) {
    int ret = 1;
    rep(i, a_size) ret *= ab[i][change[i]];
    divisor.emplace_back(ret);
  } else {
    product(change, a, b, ab, now + 1);
    rep(i, b[now]) {
      change[now] = i + 1;
      product(change, a, b, ab, now + 1);
      change[now] = 0;
    }
  }
}
void enumerate_divisor(int n) {
  divisor           = {};
  auto prime_factor = FastPrimeFactorization::prime_factor(n);
  sort(ALL(prime_factor));
  vector<int> a; //a^b
  vector<int> b;
  vector<vector<int>> ab; //ab[i][j] = a[i]^j
  rep(i, prime_factor.size()) {
    if (a.empty()) {
      a.emplace_back(prime_factor[i]);
      b.emplace_back(1);
    } else if (a[a.size() - 1] != prime_factor[i]) {
      a.emplace_back(prime_factor[i]);
      b.emplace_back(1);
    } else {
      b[b.size() - 1]++;
    }
  }
  ab.assign(a.size(), {1});
  rep(i, a.size()) {
    rep(j, b[i]) {
      ab[i].emplace_back(ab[i][ab[i].size() - 1] * a[i]);
    }
  }
  vector<int> change(a.size(), 0);
  product(change, a, b, ab);
  sort(ALL(divisor));
}

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int N;
  cin >> N;
  enumerate_divisor(N);
  FOR(i, divisor)
  cout << i << endl;
}</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2020-11-07 09:26:27+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc180/tasks/abc180_c">C - Cream puff</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc180/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (GCC 9.2.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">300</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">6836 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">18 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">3692 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In function ‘void enumerate_divisor(long long int)’:
./Main.cpp:228:32: warning: comparison of integer expressions of different signedness: ‘__gnu_cxx::__alloc_traits<std::allocator<long long int>, long long int>::value_type’ {aka ‘long long int’} and ‘__gnu_cxx::__alloc_traits<std::allocator<long unsigned int>, long unsigned int>::value_type’ {aka ‘long unsigned int’} [-Wsign-compare]
  228 |     } else if (a[a.size() - 1] != prime_factor[i]) {