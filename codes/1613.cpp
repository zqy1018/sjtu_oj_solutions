/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu1613.md
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
int n, W;
int f[1005], w[1005], v[1005];
int lis[1005], lis_len = 0;
int dp[1005][8005] = {0};
int to[1005], at[1005] = {0}, nxt[1005], cnt = 0;
int du[1005] = {0};
int tim[1005], D = 0, siz[1005] = {0};
void ddfs(int cur){
    siz[cur] = 1;
    for (int i = at[cur]; i; i = nxt[i])
        ddfs(to[i]), siz[cur] += siz[to[i]];
    tim[++D] = cur;
}
void init(){
    n = read(), W = read();
    for (int i = 1; i <= n; ++i){
        f[i] = read(), w[i] = read(), v[i] = read();
        if (f[i] > 0) 
            to[++cnt] = i, nxt[cnt] = at[f[i]], at[f[i]] = cnt, ++du[i];
    }
    w[n + 1] = v[n + 1] = 0;
    for (int i = 1; i <= n; ++i){
        if (du[i]) continue;
        if (at[i] > 0){
            to[++cnt] = i, nxt[cnt] = at[n + 1], at[n + 1] = cnt;
        }else {
            lis[++lis_len] = i;
        }
    }
    ddfs(n + 1);
}
void solve(){
    for (int i = 1; i <= D; ++i){
        int iid = tim[i];
        int ww = w[iid], vv = v[iid];
        for (int j = 0; j <= W; ++j){
            int cdt = dp[i - siz[iid]][j];
            if (j >= ww) cdt = max(cdt, dp[i - 1][j - ww] + vv);
            dp[i][j] = cdt;
        }
    }
    for (int i = 1; i <= lis_len; ++i){
        int ww = w[lis[i]], vv = v[lis[i]];
        for (int j = W; j >= ww; --j)
            dp[D][j] = max(dp[D][j], dp[D][j - ww] + vv);
    }
    printf("%d\n", dp[D][W]);
}
int main(){
    init();
    solve();
    return 0;
}