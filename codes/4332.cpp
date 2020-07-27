#include <bits/stdc++.h>
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
#define REPR(temp, init_val, end_val) for (int temp = init_val; temp >= end_val; --temp)
using namespace std;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n;
bool vis[1000005] = {0};
void init(){
    n = read();
    for (int i = 2; i <= n; ++i){
        if (!vis[i] && 1ll * i * i <= n){
            for (int j = i * i; j <= n; j += i)
                vis[j] = true;
        }
    }
}
void solve(){
    int ans = 0;
    if (n == 1){
        printf("2\n");
        return ;
    }
    for (int i = 2; i <= n; ++i){
        if (!vis[i]){
            int v = i;
            while (1ll * v * i <= 1ll * n) v *= i;
            ans = max(ans, (n / v) * v + v);
            // ceil((n + 1) / v) * v
        }
    }
    printf("%d\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}