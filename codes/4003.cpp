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
int K;
ll n;
ll lowbit(ll x){
    return x & (-x);
}
void init(){
    n = read(), K = read();
}
int Count(ll x){
    int res = 0;
    while (x > 0) ++res, x -= lowbit(x);
    return res;
}
void solve(){
    ll ans = 0;
    if (n <= K) {
        printf("%lld\n", K - n);
        return ;
    }
    while (Count(n) > K)
        ans += lowbit(n), n += lowbit(n);
    printf("%lld\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}