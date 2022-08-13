// clang-format off
#include <bits/stdc++.h>
//#pragma GCC optimize ("-Ofast")
//#pragma GCC optimize ("unroll-loops")
#define int long long
//#define double __float80
using namespace std;
#define fi first
#define se second
#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; i++)
#define rep2(i, a, b) for (int i = (int)(a), i##_len=(b); i < i##_len; i++)
#define rep3(i, a, b) for (int i = (int)(a), i##_len=(b); i >= i##_len; i--)
#define rfor(i, a) for (auto &i: a)
#define all(obj) begin(obj), end(obj)
#define _max(x) *max_element(all(x))
#define _min(x) *min_element(all(x))
#define _sum(x) accumulate(all(x), 0LL)

const int MOD   = 1000000007;
// const int MOD    = 998244353;
// const int INF    = 1e18;
// const int INF    = 1e13 + 7;
// const int INF    = LLONG_MAX; // 9.2e18
const double EPS = 1e-20;
const double PI  = 3.14159265358979;
template <class T> using V = vector<T>;
template <class T> using VV = vector<vector<T>>;
template <class T> using VVV = vector<vector<vector<T>>>;
template <class T, class S>  using P = pair<T, S>;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return true;}return false;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return true;}return false;}
int _ceil(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
template<class T> T chmod(T &a, T mod=MOD) {a =  a >= 0 ? a % mod : a - (mod * _ceil(a, mod)); return a;};
int _mod(int a, int mod=MOD) {return a >= 0 ? a % mod : a - (mod * _ceil(a, mod));}
double _mod(double a, int mod = MOD) { return fmod(a, mod) >= 0 ? fmod(a, mod) : fmod(a, mod) + mod; }
int _pow(int a, int b, int mod=MOD) {int res = 1;for (a %= mod; b; a = a * a % mod, b >>= 1)if (b & 1) res = res * a % mod;return res;}
vector<int> iota(int n){vector<int> ret(n); iota(begin(ret), end(ret), 0); return ret;}
struct mint {long long x;mint(long long x = 0): x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) {(x *= a.x) %= MOD;return *this;}mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; }mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long n) const {mint ret(1), mul(x);while (n > 0) {if (n & 1) ret *= mul;mul *= mul;n >>= 1;}return ret;}mint inv() const {int a = x, b = MOD, u = 1, v = 0, t;while (b > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);}return mint(u);}mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }bool operator==(const mint a) const { return x == a.x; }bool operator!=(const mint a) const { return x != a.x; }friend istream &operator>>(istream &is, mint &a) { return is >> a.x; }friend ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }};
// clang-format on

class UnionFind {
  public:
    vector<int> _par;
    vector<int> _size;
    UnionFind(int sz_): _par(sz_), _size(sz_, 1LL) {
        for (int i = 0; i < sz_; i++) _par[i] += i;
    }
    void init(int sz_) {
        _par.resize(sz_);
        _size.assign(sz_, 1LL);
        for (int i = 0; i < sz_; i++) _par[i] = i;
    }
    int root(int x) {
        while (_par[x] != x) {
            x = _par[x] = _par[_par[x]];
        }
        return x;
    }
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (_size[x] < _size[y]) swap(x, y);
        _size[x] += _size[y];
        _par[y] = x;
        return true;
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int size(int x) {
        return _size[root(x)];
    }
};
struct edge {
    int u, v, cost, num;
};
edge es2[1995];
edge es[1995];
V<bool> use;
bool comp(const edge &e1, const edge &e2) { return e1.cost < e2.cost; }
int kruskal() {
    use.assign(1995, false);
    rep(i, 1995) es[i] = es2[i];
    sort(es, es + 1995, comp);
    UnionFind uf(400);
    int res = 0;
    for (int i = 0; i < 1995; i++) {
        edge e = es[i];
        if (!uf.same(e.u, e.v)) {
            uf.unite(e.u, e.v);
            res += e.cost;
            use[e.num] = true;
        }
    }
    return res;
}

random_device rnd;
mt19937 mt(rnd());
uniform_int_distribution<> rand1000(0, 1000);
double start = clock();
int N        = 400;
int M        = 1995;
int cost;
V<int> x(N), y(N), u(M), v(M);
V<bool> already(N);

void in() {
    rep(i, N) cin >> x[i] >> y[i];
    rep(i, M) cin >> u[i] >> v[i];
}

int dis(int a, int b) { return (int)round(sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]))); }

void calc1() {
    rep(i, M) es2[i] = {u[i], v[i], 2 * dis(u[i], v[i]), i};
    rep(i, M) {
        cin >> cost;
        es2[i].cost = cost;
        kruskal();
        if (use[i]) {
            cout << 1 << endl;
            es2[i].cost = -INT_MAX;
        } else {
            cout << 0 << endl;
            es2[i].cost = INT_MAX;
        }
    }
}

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    in();
    calc1();
    // cout << (clock() - start) / CLOCKS_PER_SEC << endl;
}