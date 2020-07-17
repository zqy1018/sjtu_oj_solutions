#include <bits/stdc++.h>
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
using namespace std;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, sm[1000005] = {0};
void init(){
    n = read();
    REP(i, 1, n)
        sm[i] = sm[i - 1] ^ i;
}
void solve(){
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        int p = n / i, t = n % i;
        if (p & 1) ans ^= sm[i - 1];
        ans ^= sm[t];
    }
    printf("%d\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}