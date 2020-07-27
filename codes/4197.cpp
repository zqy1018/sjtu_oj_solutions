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
int n, m, a[2005], b[2005], x;
int suma[2005], sumb[2005];
int minia[2005], minib[2005];
void init(){
    n = read(), m = read();
    suma[0] = sumb[0] = 0;
    REP(i, 1, n)
        a[i] = read(), suma[i] = suma[i - 1] + a[i];
    REP(i, 1, m)
        b[i] = read(), sumb[i] = sumb[i - 1] + b[i];
    x = read();
    REP(i, 1, n){
        minia[i] = 0x3f3f3f3f;
        REP(j, 1, n - i + 1)
            minia[i] = min(minia[i], suma[j + i - 1] - suma[j - 1]);
    }
    REP(i, 1, m){
        minib[i] = 0x3f3f3f3f;
        REP(j, 1, m - i + 1)
            minib[i] = min(minib[i], sumb[j + i - 1] - sumb[j - 1]);
    }
}
void solve(){
    int curb = m, ans = 0;
    REP(i, 1, n){
        while (curb > 0 && 1ll * minia[i] * minib[curb] > 1ll * x)
            --curb;
        ans = max(ans, i * curb);
    }
    printf("%d\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}