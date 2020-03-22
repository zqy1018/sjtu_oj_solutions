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
int to[200005], nxt[200005], at[100005] = {0}, cnt = 0;
int n, a[100005], fa[100005] = {0};
ll ans[100005] = {0}, siz[100005] = {0};
void dfs(int cur, int faa){
    fa[cur] = faa;
    for (int i = at[cur]; i; i = nxt[i]){
        int v = to[i];
        if (v == faa) continue;
        siz[cur] += a[v], dfs(v, cur);
    }
}
void dfs2(int cur){
    if (fa[cur] != 0){
        ans[cur] += siz[fa[cur]] - a[cur];
        ans[cur] += a[fa[fa[cur]]];
    }
    for (int i = at[cur]; i; i = nxt[i]){
        int v = to[i];
        if (v == fa[cur]) continue;
        ans[cur] += siz[v], dfs2(v);
    }
}
void init(){
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i < n; ++i){
        int u = read() + 1, v = read() + 1;
        to[++cnt] = v, nxt[cnt] = at[u], at[u] = cnt;
        to[++cnt] = u, nxt[cnt] = at[v], at[v] = cnt;
    }
    a[0] = 0;
}
void solve(){
    dfs(1, 0);
    dfs2(1);
    for (int i = 1; i < n; ++i)
        printf("%lld ", ans[i]);
    printf("%lld\n", ans[n]);
}
int main(){
    init();
    solve();
    return 0;
}