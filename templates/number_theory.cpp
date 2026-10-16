//Once You Stop Learning You start dying
#include <bits/stdc++.h>
using i128 = __int128_t;
#define ll long long
using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;


// ==================== GCD / LCM ====================

ll gcd(ll x, ll y) {
    if (x == 0) return abs(y);
    if (y == 0) return abs(x);
    return gcd(y, x % y);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}


// ==================== PRIME CHECK ====================

bool isprime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}


// ==================== SIEVE ====================

bool prime[15000105];

void sieve(int n) {
    fill(prime, prime + n + 1, true);
    __primes_generated__=true;

    prime[0] = prime[1] = false;

    for (ll p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}


// ==================== PRIME LIST ====================

vector<ll> primelist;
bool __primes_generated__ = false;

void genprimes(int n) {

    sieve(n);

    if (__primes_generated__)
        return;

    for (ll i = 2; i <= n; i++) {
        if (prime[i])
            primelist.push_back(i);
    }
}


// ==================== PRIME FACTORIZATION ====================

// returns:
// n = p1^e1 * p2^e2 * ...

vector<pair<ll,ll>> factorize(ll n) {
    vector<pair<ll,ll>> fac;

    for (ll p : primelist) {

        if (p * p > n)
            break;

        if (n % p == 0) {

            ll cnt = 0;

            while (n % p == 0) {
                n /= p;
                cnt++;
            }

            fac.push_back({p, cnt});
        }
    }

    if (n > 1)
        fac.push_back({n, 1});

    return fac;
}


// ==================== FACTORIZATION WITHOUT SIEVE ====================

vector<pair<ll,ll>> factorize_sqrt(ll n) {
    vector<pair<ll,ll>> fac;

    for (ll p = 2; p * p <= n; p++) {

        if (n % p == 0) {

            ll cnt = 0;

            while (n % p == 0) {
                n /= p;
                cnt++;
            }

            fac.push_back({p, cnt});
        }
    }

    if (n > 1)
        fac.push_back({n, 1});

    return fac;
}


// ==================== DIVISORS ====================

vector<ll> getdivs(ll n) {

    vector<ll> divs;

    for (ll i = 1; i * i <= n; i++) {

        if (n % i == 0) {

            divs.push_back(i);

            if (i * i != n)
                divs.push_back(n / i);
        }
    }

    return divs;
}


// sorted divisors
vector<ll> getdivs_sorted(ll n) {

    vector<ll> divs = getdivs(n);

    sort(divs.begin(), divs.end());

    return divs;
}


// ==================== NUMBER OF DIVISORS ====================

ll divisor_count(ll n) {

    ll ans = 1;

    for (ll p = 2; p * p <= n; p++) {

        if (n % p == 0) {

            ll cnt = 0;

            while (n % p == 0) {
                n /= p;
                cnt++;
            }

            ans *= (cnt + 1);
        }
    }

    if (n > 1)
        ans *= 2;

    return ans;
}


// ==================== SUM OF DIVISORS ====================

// n = p1^e1 * p2^e2 ...
// sum = (1+p+...+p^e)

ll sum_divisors(ll n) {

    ll ans = 1;

    for (ll p = 2; p * p <= n; p++) {

        if (n % p == 0) {

            ll pw = 1;
            ll sum = 1;

            while (n % p == 0) {

                n /= p;

                pw *= p;
                sum += pw;
            }

            ans *= sum;
        }
    }

    if (n > 1)
        ans *= (n + 1);

    return ans;
}


// ==================== MODULAR ARITHMETIC ====================

ll madd(ll a, ll b) {
    return (a + b) % mod;
}

ll msub(ll a, ll b) {
    return ((a - b) % mod + mod) % mod;
}

ll mmul(ll a, ll b) {
    return (a % mod) * (b % mod) % mod;
}


// ==================== FAST POWER ====================

ll mpow(ll base, ll exp) {

    ll res = 1;

    base %= mod;

    while (exp) {

        if (exp & 1)
            res = res * base % mod;

        base = base * base % mod;

        exp >>= 1;
    }

    return res;
}


// ==================== MODULAR INVERSE ====================

// works when mod is prime
// a^(-1) = a^(mod-2)

ll minv(ll base) {
    return mpow(base, mod - 2);
}


// ==================== MODULAR DIVISION ====================

ll mdiv(ll a, ll b) {
    return mmul(a, minv(b));
}


// ==================== PHI / EULER TOTIENT ====================

// count numbers from 1..n coprime with n

ll phi(ll n) {

    ll ans = n;

    for (ll p = 2; p * p <= n; p++) {

        if (n % p == 0) {

            while (n % p == 0)
                n /= p;

            ans -= ans / p;
        }
    }

    if (n > 1)
        ans -= ans / n;

    return ans;
}


// ==================== SPF ====================

vector<int> spf;

void build_spf(int n) {

    spf.resize(n + 1);

    for (int i = 0; i <= n; i++)
        spf[i] = i;

    for (ll i = 2; i * i <= n; i++) {

        if (spf[i] == i) {

            for (ll j = i * i; j <= n; j += i) {

                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}


// factorization using SPF
vector<pair<ll,ll>> factorize_spf(int n) {

    vector<pair<ll,ll>> fac;

    while (n > 1) {

        int p = spf[n];
        int cnt = 0;

        while (n % p == 0) {
            n /= p;
            cnt++;
        }

        fac.push_back({p, cnt});
    }

    return fac;
}


// ==================== NCR ====================

// for small n

ll nCr(ll n, ll r) {

    if (r < 0 || r > n)
        return 0;

    r = min(r, n - r);

    ll ans = 1;

    for (ll i = 1; i <= r; i++) {
        ans = ans * (n - r + i) / i;
    }

    return ans;
}


// ==================== NCR MOD ====================

ll fact[N];
ll invfact[N];

void init_comb() {

    fact[0] = 1;

    for (int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i % mod;

    invfact[N - 1] = minv(fact[N - 1]);

    for (int i = N - 2; i >= 0; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % mod;
}

ll nCr_mod(ll n, ll r) {

    if (r < 0 || r > n)
        return 0;

    return fact[n] * invfact[r] % mod
         * invfact[n - r] % mod;
}


// ==================== LEGENDRE ====================

// exponent of prime p in n!

ll exponent_in_factorial(ll n, ll p) {

    ll ans = 0;

    while (n) {
        n /= p;
        ans += n;
    }

    return ans;
}


// ==================== PRIME FACTORS COUNT ====================

// number of distinct prime factors

ll distinct_prime_factors(ll n) {

    ll cnt = 0;

    for (ll p = 2; p * p <= n; p++) {

        if (n % p == 0) {

            cnt++;

            while (n % p == 0)
                n /= p;
        }
    }

    if (n > 1)
        cnt++;

    return cnt;
}


// total prime factors WITH repetition

ll total_prime_factors(ll n) {

    ll cnt = 0;

    for (ll p = 2; p * p <= n; p++) {

        while (n % p == 0) {

            n /= p;
            cnt++;
        }
    }

    if (n > 1)
        cnt++;

    return cnt;
}


// ==================== CHECK PERFECT SQUARE ====================

bool isPerfectSquare(ll n) {

    if (n < 0)
        return false;

    ll x = sqrtl(n);

    while (x * x < n)
        x++;

    while (x * x > n)
        x--;

    return x * x == n;
}


// ==================== CHECK POWER OF TWO ====================
//0111
//0110
bool isPowerOfTwo(ll n) {

    return n > 0 && (n & (n - 1)) == 0;
}


// ==================== MOD FOR NEGATIVE ====================

ll norm_mod(ll x, ll m) {

    return ((x % m) + m) % m;
}


// ==================== EXTENDED GCD ====================

ll extgcd(ll a, ll b, ll &x, ll &y) {

    if (b == 0) {

        x = 1;
        y = 0;

        return a;
    }

    ll x1, y1;

    ll g = extgcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}


// ==================== MODULAR INVERSE EXTGCD ====================

ll modInverse(ll a, ll m) {

    ll x, y;

    ll g = extgcd(a, m, x, y);

    if (g != 1)
        return -1;

    return norm_mod(x, m);
}


// ==================== MULTIPLICATION MOD ====================

// useful when a,b can be close to 1e18

ll mul_mod(ll a, ll b, ll m) {

    return (i128)a * b % m;
}


// ==================== POWER MOD ANY MOD ====================

ll power_mod(ll a, ll b, ll m) {

    ll ans = 1;

    a %= m;

    while (b) {

        if (b & 1)
            ans = mul_mod(ans, a, m);

        a = mul_mod(a, a, m);

        b >>= 1;
    }

    return ans;
}


// ==================== MAIN ====================

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}