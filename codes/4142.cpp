/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4142.md
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
int n, m;
int at[100005] = {0}, nxt[1000005], w[1000005], to[1000005], cnt = 0;
int id[1000005], tot = 0;
bool is_mul[500005] = {0};
int dfn[100005] = {0}, low[100005], D = 0;
int ffa[100005], siz[100005];
unordered_map<int, int> mp[100005];
int Find(int x){
    return (ffa[x] == x ? x: (ffa[x] = Find(ffa[x])));
}
int Union(int x, int y){
    int u = Find(x), v = Find(y);
    if (u == v) return 0;
    if (siz[u] > siz[v])
        ffa[v] = u, siz[u] += siz[v];
    else    
        ffa[u] = v, siz[v] += siz[u];
    return 1;
}
inline int get(int x){
    return ((x & 1) ? x + 1: x - 1);
}
bool cmp(int i, int j){
    return w[i] < w[j];
}
void tarjan(int cur, int fa){
    dfn[cur] = low[cur] = ++D;
    for (int i = at[cur]; i; i = nxt[i]){
        int v = to[i];
        if (v == fa) continue;
        if (!dfn[v]){
            tarjan(v, cur);
            if (low[v] > dfn[cur] && !is_mul[(i + 1) >> 1]){
                id[++tot] = ((i & 1) ? (i + 1): i);
            }else {
                low[cur] = min(low[cur], low[v]);
                id[++tot] = ((i & 1) ? i: (i - 1));
            }
        }else 
            low[cur] = min(low[cur], dfn[v]), 
            id[++tot] = ((i & 1) ? i: (i - 1));
    }
}
void init(){
    n = read(), m = read();
    for (int i = 1; i <= m; ++i){
        int u = read(), v = read(), ww1 = read(), ww2 = read();
        if (u == v) continue;
        if (u > v) swap(u, v);
        if (mp[u].count(v)){
            int pos = mp[u][v];
            w[pos] = min(w[pos], ww1), w[pos + 1] = min(w[pos + 1], ww2);
            is_mul[(pos + 1) >> 1] = true;
        }else {
            mp[u][v] = cnt + 1;
            to[++cnt] = v, nxt[cnt] = at[u], w[cnt] = ww1, at[u] = cnt;
            to[++cnt] = u, nxt[cnt] = at[v], w[cnt] = ww2, at[v] = cnt;
        }
    }
    for (int i = 1; i <= n; ++i)
        ffa[i] = i, siz[i] = 1;
}
void solve(){
    int lft = n; 
    long long ans = 0;
    tarjan(1, 0);
    sort(id + 1, id + tot + 1, cmp);
    for (int i = 1; lft > 1; ++i){
        int u = to[id[i]], v = to[get(id[i])], ww = w[id[i]];
        if (Union(u, v))
            --lft, ans += ww;
    }
    printf("%lld\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}