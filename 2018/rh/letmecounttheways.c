#include <stdlib.h>
#include <stdio.h>


typedef long long LL;
typedef unsigned long long uLL;

#define mod 1000000007
#define maxn 200007
 
int t, n, m;
LL A[maxn], invv[maxn];
 
LL Mod_Pow(LL x, int n) {
   LL res = 1;
    while(n) {
       if(n & 1) res = res * x % mod;
       x = x * x % mod;
       n >>= 1;
    }
    return res;
}



void init() {
    A[0] = 1;
    for(int i = 1; i < maxn; i++) A[i] = (A[i-1] * i) % mod;
    invv[maxn-1] = Mod_Pow(A[maxn-1], mod - 2);
    for(int i = maxn - 2; i >= 0; i--) {
        invv[i] = invv[i+1] * (i + 1) % mod;
    }
}

int Com(int n, int m) {
     if(n < 0 || m < 0 || m > n) return 0;
    if(m == 0 || m == n) return 1;
     return ((A[n] * invv[n-m] % mod) * invv[m]) % mod;
 }
 

 int main() {
    init();
    int icase = 0;
    scanf("%d", &t);
    while(t--) {
         scanf("%d%d", &n, &m);
         LL sum = 0;
         for(int i = 0; i <= m; i++) {
             if(i % 2 == 0) {
                 sum = (sum + ((Com(m, i) * Mod_Pow(2, i) % mod) * A[2 * n - i]) % mod) % mod;
            } else {
                 sum = (sum - ((Com(m, i) * Mod_Pow(2, i) % mod) * A[2 * n - i]) % mod + mod) % mod;
             }
         }
         printf("Case #%d: %lld\n", ++icase, sum % mod);
     }
     return 0;
}