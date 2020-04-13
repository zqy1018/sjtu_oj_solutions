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
int n, k, A, B;
void init(){
    n = read(), k = read(), A = read(), B = read();
}
void solve(){
    if (k == 1){
        printf("%lld\n", 1ll * (n - 1) * A);
        return ;
    }
    ll ans = 0;
    while (n > 1){
        if (n < k) {
            ans += 1ll * (n - 1) * A;
            break;
        }
        if (n % k == 0){
            int to = (n / k);
            if (1ll * (n - to) * A < B)
                ans += 1ll * (n - to) * A;
            else 
                ans += B;
            n = to;
        }else {
            int to = (n / k) * k;
            ans += 1ll * (n - to) * A;
            n = to;
        }
    }
    printf("%lld\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}