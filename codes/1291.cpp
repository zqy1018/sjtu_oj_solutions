/*
    Hint: use combinatorics
*/
#include <bits/stdc++.h>
#define INF 2000000000
#define M 1000000007
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, f[1005] = {0}, C[1005][1005] = {0};
void init(){
    n = read();
    C[0][0] = 1;
    for (int i = 1; i <= n; ++i){
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
    }
}
void solve(){
    if (n <= 1) {
        printf("%d\n", n);
        return ;
    }
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; ++i){
        int tt = 2;
        while (tt - 1 <= i)
            tt <<= 1;
        tt >>= 1;
        int lsize = min(tt >> 1, i - tt + 1);
        lsize += (tt - 1) >> 1;
        f[i] = 1ll * (C[i - 1][lsize]) * f[lsize] % M,
        f[i] = 1ll * f[i] * f[i - lsize - 1] % M;
    }
    int ans = 2ll * f[n] % M;
    printf("%d\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}