/*
    Hint: use integer partition
*/
#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
ll f[105][105] = {0}, tot[105];
int a[105], n, c;
void init(){
    n = read(), c = read();
    for (int i = 1; i <= n; ++i)    
        a[i] = read();
    sort(a + 1, a + n + 1);
    
    f[0][0] = 1;
    for (int i = 1; i <= 100; ++i){
        f[i][1] = 1;
        for (int j = 2; j <= i; ++j)
            f[i][j] = f[i - 1][j - 1] + f[i - j][j];
        tot[i] = 0;
        for (int j = 1; j <= i; ++j)
            tot[i] += f[i][j];
    }
}
void solve(){
    ll ans = 1;
    for (int i = 1; i <= n; ){
        int j = i;
        while (j <= n && a[i] == a[j])
            ++j;
        ans = 1ll * ans * tot[j - i];
        i = j;
    }
    printf("%lld\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}