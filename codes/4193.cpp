/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4193.md
*/
#include <bits/stdc++.h>
#define INF 2000000000
#define M 1000000007
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int fac[2005];
int n, a[2005];
int f[2005][2005], tot;
int c[2005], l[2005];
pair<int, int> b[2005];
inline int lowbit(int x){
    return x & (-x);
}
inline int modadd(int x, int y){
    return (x + y >= M ? x + y - M: x + y);
}
void add(int r, int x){
    while (r <= n)
        c[r] = modadd(c[r], x), r += lowbit(r);
}
int query(int r){
    int res = 0;
    while (r > 0)
        res = modadd(res, c[r]), r -= lowbit(r);
    return res;
}
void init(){
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read(), b[i] = make_pair(a[i], i);
    sort(b + 1, b + n + 1);
}
void solve(){
    memset(f, 0, sizeof(f));
    memset(l, 0, sizeof(l));
    l[1] = n;
    for (int i = 1; i <= n; ++i)
        f[i][1] = 1;
    for (int j = 2; j <= n; ++j){
        for (int i = 0; i <= n; ++i)
            c[i] = 0;
        for (int i = 1; i <= n; ++i){
            int pos = b[i].second;
            f[pos][j] = query(pos - 1);
            add(pos, f[pos][j - 1]);
        }
        for (int i = j; i <= n; ++i)
            l[j] = modadd(l[j], f[i][j]);
    }
    int ans = l[n];
    for (int i = n - 1; i >= 1; --i){
        int t = 1ll * l[i] * fac[n - i] % M;
        t = modadd(t, M - 1ll * (1ll * l[i + 1] * fac[n - i - 1] % M) * (i + 1) % M);
        ans = modadd(ans, t);
    }
    printf("%d\n", ans);
}
int main(){
    int T = read();
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= 2000; ++i)
        fac[i] = 1ll * fac[i - 1] * i % M;
    while (T--){
        init();
        solve();
    }
    return 0;
}