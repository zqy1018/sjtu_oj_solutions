#include <bits/stdc++.h>
using namespace std;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, m;
void init(){
    n = read(), m = read();
}
void solve(){
    int ans = INT_MAX;
    while (m--){
        int a = read(), b = read();
        int t = (n * b - 1) / (a + b) + 1;
        ans = min(ans, t * a - (n - t) * b);
    }
    printf("%d\n", ans);
}
int main(){
    int T = read();
    while (T--){
        init();
        solve();
    }
    return 0;
}