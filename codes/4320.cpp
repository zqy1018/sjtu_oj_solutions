#include <bits/stdc++.h>
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, a[1000005];
void init(){
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
}
void solve(){
    ll sm = a[1] + a[2];
    ll ans = a[1] + a[2];
    ll mini0 = min(0, a[1] + a[2]), mini1 = a[1];
    REP(i, 3, n){
        sm += a[i];
        if (i & 1)
            ans = max(ans, sm - mini1), mini1 = min(mini1, sm);
        else 
            ans = max(ans, sm - mini0), mini0 = min(mini0, sm);
    }
    printf("%lld\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}