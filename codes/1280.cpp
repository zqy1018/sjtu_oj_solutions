#include <bits/stdc++.h>
#define INF 2000000000
#define M 100000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, ff, a[2005], f[2005][1005] = {0};
void init(){
    n = read(), ff = read();
    for (int i = 1; i <= n; ++i) 
        a[i] = read();
}
void solve(){
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i){
        a[i] %= ff;
        for (int j = 0, k = a[i]; j < ff; ++j, k = (k == ff - 1 ? 0: k + 1))
            f[i][k] = (f[i - 1][k] + f[i - 1][j]) % M;
    }
    printf("%d\n", (f[n][0] + M - 1) % M);
}
int main(){
    init();
    solve();
    return 0;
}