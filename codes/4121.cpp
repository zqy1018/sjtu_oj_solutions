#include <bits/stdc++.h>
#define INF 2000000000
#define modadd(x, y) (x + y >= k ? x + y - k: x + y)
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, m, k;
int a[405][405], sum[405][405] = {0};
int cnt[1000005] = {0};
int lis[405], tot;
void init(){
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            a[i][j] = read();
            sum[i][j] = sum[i][j - 1] + a[i][j];
        }
}
void solve(){
    ll ans = 0;
    for (int i = 1; i <= m; ++i){
        for (int j = i; j <= m; ++j){
            cnt[0] = 1;
            tot = 1, lis[1] = 0;
            int sm = 0;
            for (int t = 1; t <= n; ++t){
                sm = modadd(sm, (sum[t][j] - sum[t][i - 1]) % k);
                ans += cnt[sm];
                ++cnt[sm];
                lis[++tot] = sm;
            }
            for (int i = 1; i <= tot; ++i)
                cnt[lis[i]] = 0;
        }
    }
    printf("%lld\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}