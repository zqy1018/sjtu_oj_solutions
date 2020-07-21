#include <bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define MAXN 200005
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
int n, m, k;
int a[500005], cur[25] = {0}, t[25], c[25];
int f[500005];
void init(){
    n = read(), m = read(), k = read();
    REP(i, 1, n)
        a[i] = read();
    REP(i, 1, m)
        t[i] = read(), c[i] = read();
    a[0] = 0;
}
void solve(){
    f[0] = 0;
    REP(i, 1, n){
        f[i] = f[i - 1] + k;
        REP(j, 1, m){
            while (a[cur[j] + 1] <= a[i] - t[j])
                ++cur[j];
            f[i] = min(f[i], f[cur[j]] + c[j]);
        }
    }
    printf("%d\n", f[n]);
}
int main(){
    init();
    solve();
    return 0;
}