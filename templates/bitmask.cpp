
/*
    Once You Stop Learning You Start Dying
    BIT MANIPULATION TEMPLATE
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;

/*========================================
    1. NUMBER REPRESENTATION
========================================*/

// Convert a non-negative number to any base >= 2.
// Example: Representation(13, 2) -> {1, 1, 0, 1}
vector<int> Representation(ll n, int base) {
    vector<int> ans;

    if (n == 0) return {0};

    while (n > 0) {
        ans.push_back(n % base);
        n /= base;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

/*========================================
    2. XOR FROM 0 TO N
========================================*/

// XOR of all numbers from 0 to n.
ll XOR_0_to_n(ll n) {
    if (n < 0) return 0;

    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

// XOR of all numbers from 1 to n.
ll XOR_1_to_n(ll n) {
    return XOR_0_to_n(n);
}

// XOR of all numbers in [l, r].
ll XOR_Range(ll l, ll r) {
    if (l > r) return 0;
    if (l == 0) return XOR_0_to_n(r);

    return XOR_0_to_n(r) ^ XOR_0_to_n(l - 1);
}

/*========================================
    3. PREFIX XOR
========================================*/

// pref[i] = XOR of a[1 ... n] 1 index.
void Prefix_XOR(vector<ll>& pref) {
    
    for (int i = 1; i <= pref.size(); i++) {
          pref[i]^=pref[i-1];
    }
   //ans for each q = pref[r] ^ pref[l-1];
}



/*========================================
    4. BASIC BIT OPERATIONS
========================================*/

// Check whether bit i is set.
bool CheckBit(ll n, int i) {
    return (n & (1LL << i)) != 0;
}

// Get bit i: returns 0 or 1.
int GetBit(ll n, int i) {
    return (n >> i) & 1LL;
}

// Toggle bit i: 0 -> 1, 1 -> 0.
ll ToggleBit(ll n, int i) {
    return n ^ (1LL << i);
}

// Set bit i to 1.
ll SetBit(ll n, int i) {
    return n | (1LL << i);
}

// Clear bit i: set it to 0.
ll ClearBit(ll n, int i) {
    return n & ~(1LL << i);
}

// Update bit i to a specific value (0 or 1).
ll UpdateBit(ll n, int i, int value) {
    if (value == 1) return SetBit(n, i);
    return ClearBit(n, i);
}

/*========================================
    5. POWER OF TWO
========================================*/

// A positive number is a power of two
// if it contains exactly one set bit.
bool IsPowerOfTwo(ll n) {
    return n > 0 && (n & (n - 1)) == 0;
}

/*========================================
    6. COUNT SET BITS
========================================*/

// Count the number of 1s in the binary representation.
int CountSetBits(unsigned long long n) {
    return __builtin_popcountll(n);
}
// Counts the number of 0s before the first set bit (1),
int CountTralingZeros(unsigned long long n){
    // starting from the least significant bit (rightmost bit).
    // or also return index for rightmost set bit (1)
    return __builtin_ctzll(n);//01100 ans is 2 0s
}
// starting from the most significant bit (leftmost bit).
int CountLeadingZeros(unsigned long long n){
    return __builtin_clzll(n);//00010 ans is 3 0s
}
int index_leftmostsetbit(int n){
    return 63-CountLeadingZeros(n);
}
// Change all trailing zeros in the binary representation to ones.
int SetTrailingZerosToOnes(int n) {
    //ex : 0110100  -> 0110111
    return n | (n - 1);
}
// Clear all trailing ones in the binary representation.
int ClearTrailingOnes(int n) {
    //ex : 01110111  -> 01110000
    return n & (n + 1);
}
/*========================================
    7. LOWEST SET BIT
========================================*/

// Return the value of the lowest set bit.
// Example: 12 = 1100 -> 4 = 0100.
ll LowestSetBit(ll n) {
    return n & -n;
}

// Remove the lowest set bit.
ll RemoveLowestSetBit(ll n) {
    return n & (n - 1);
}

/*========================================
    8. PRINT SET BIT POSITIONS
========================================*/

// Positions are zero-based.
void PrintSetBitPositions(unsigned long long n) {
    for (int bit = 0; bit < 64; bit++) {
        if ((n >> bit) & 1ULL) {
            cout << bit << ' ';
        }
    }

    cout << '\n';
}

/*========================================
    9. PREFIX BIT COUNTS
========================================*/

// pref[bit][i] = number of set bits at position
// bit among the first i elements.
//
// Supports non-negative signed long long values.
// Bits 0 through 62 are considered.
vector<vector<int>>pref;
void PrefixBits() {
    int n;cin>>n;
    vector<int>a(n+1);
    pref.resize(32,vector<int>(n+1,0));
    for(int bit=0;bit < 32;bit++){
        for(int idx{1};idx <= n;idx++){
            pref[bit][idx]=pref[bit][idx-1]+((a[idx]>>bit)&1);
        }
    }
}

// Bitwise OR of inclusive zero-based range [l, r].
int Range_OR( int l, int r) {
    int ans{};
    for(int bit=0;bit < 32;bit++){
        int cnt=pref[bit][r]-pref[bit][l-1];

        if(cnt > 0)
          ans|=(1<<bit);
    }

    return ans;
}

// Bitwise AND of inclusive zero-based range [l, r].
int Range_AND( int l, int r) {
    int ans = 0;
    int len = r - l + 1;

    for (int bit = 0; bit < 32; bit++) {
        int cnt=pref[bit][r]-pref[bit][l-1];

        if (cnt == len) {
            ans |= (1LL << bit);
        }
    }

    return ans;
}

/*========================================
    10. IMPORTANT BIT PROPERTIES
========================================*/

/* 

2- if 'A' is a one bit number
   [A & 1 = A]
   [A | 0 = A]
   [A ^ 0 = A]
   [A ^ 1 = 1-A]

 3- [A ^ A = 0] for any number
   

    XOR:
    A ^ A = 0
    A ^ 0 = A
    A ^ B = B ^ A
    (A ^ B) ^ C = A ^ (B ^ C)

    If A ^ B = C:
        A ^ C = B
        B ^ C = A

    Check bit:
        n & (1LL << bit)

    Set bit:
        n | (1LL << bit)

    Toggle bit:
        n ^ (1LL << bit)

    Clear bit:
        n & ~(1LL << bit)

    Remove lowest set bit:
        n & (n - 1)

    Extract lowest set bit:
        n & -n

    Power of two:
        n > 0 && (n & (n - 1)) == 0

    XOR of range [l, r]:
        XOR_0_to_n(r) ^ XOR_0_to_n(l - 1)

    Prefix XOR of array range [l, r]:
        pref[r + 1] ^ pref[l]

    Range OR:
        A bit appears in at least one element.

    Range AND:
        A bit appears in every element.
*/

/*========================================
    MAIN
========================================*/

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
