/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4195.md
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
int n, a[100005], id[100005];
int to[200005], at[100005], nxt[200005], cnt = 0;
int ans[100005];
int zjdd[100005][3];        // 直径端点，不会表达
int fa[100005][20] = {0}, dep[100005] = {0};
int sum[100005] = {0};
int fa2[100005];
int Find(int x){
    return (fa2[x] == x ? x: (fa2[x] = Find(fa2[x])));
}
void Union(int x, int y){
    int u = Find(x), v = Find(y);
    if (u == v) return ;
    fa2[v] = u;
}
int poww(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1) res = 1ll * res * a % M;
        a = 1ll * a * a % M, b >>= 1;
    }
    return res;
}
void dfs(int cur, int ffa){
    for (int i = at[cur]; i; i = nxt[i]){
        int v = to[i];
        if (v == ffa) continue;
        fa[v][0] = cur, sum[v] = sum[cur] + a[v];
        dep[v] = dep[cur] + 1;
        dfs(v, cur);
    }
}
int lca(int x, int y){
    if (dep[x] != dep[y]){
        if (dep[x] < dep[y]) swap(x, y);
        int diff = dep[x] - dep[y];
        for (int t = 1, p = 0; diff > 0; t <<= 1, ++p)
            if (t & diff)
                x = fa[x][p], diff -= t; 
    }
    if (x == y) return x;
    for (int j = 19; j >= 0; --j)
        if (fa[x][j] != fa[y][j])
            x = fa[x][j], y = fa[y][j];
    return fa[x][0]; 
}
int dis(int x, int y){
    int llca = lca(x, y);
    return sum[x] + sum[y] - 2 * sum[llca] + a[llca];
}
void init(){
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i < n; ++i){
        int u = read(), v = read();
        to[++cnt] = v, nxt[cnt] = at[u], at[u] = cnt;
        to[++cnt] = u, nxt[cnt] = at[v], at[v] = cnt;
    }
    for (int i = 1; i < n; ++i)
        id[i] = read();
 
    sum[1] = a[1], dep[1] = 1, dfs(1, 0);
    for (int j = 1; j < 20; ++j){
        bool flag = false;
        for (int i = 1; i <= n; ++i)
            fa[i][j] = fa[fa[i][j - 1]][j - 1], 
            flag = (flag || fa[i][j]);
        if (!flag) break;
    }
}
void solve(){
    int aans = 1;
    for (int i = 1; i <= n; ++i)
        zjdd[i][0] = zjdd[i][1] = i, zjdd[i][2] = a[i], 
        fa2[i] = i, 
        aans = 1ll * aans * a[i] % M;
 
    ans[n] = aans;
    for (int i = n - 1; i >= 1; --i){
        int u = Find(to[id[i] << 1]), v = Find(to[(id[i] << 1) - 1]);
        int res = INT_MIN, ans1, ans2;
        for (int uu = 0; uu < 2; ++uu)
            for (int vv = 0; vv < 2; ++vv){
                int tmp = dis(zjdd[u][uu], zjdd[v][vv]);
                // cout << " " << tmp << " " <<  zjdd[u][uu] << " " << zjdd[v][vv] << endl;
                if (tmp > res)
                    res = tmp, ans1 = zjdd[u][uu], ans2 = zjdd[v][vv];
            }
        if (zjdd[u][2] > res) res = zjdd[u][2], ans1 = zjdd[u][0], ans2 = zjdd[u][1];
        if (zjdd[v][2] > res) res = zjdd[v][2], ans1 = zjdd[v][0], ans2 = zjdd[v][1];
        // cout << res << endl;
        aans = 1ll * aans * poww(zjdd[u][2], M - 2) % M;
        aans = 1ll * aans * poww(zjdd[v][2], M - 2) % M;
        Union(u, v);
        zjdd[u][0] = ans1, zjdd[u][1] = ans2, zjdd[u][2] = res;
        aans = 1ll * aans * res % M;
        ans[i] = aans;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[i]);
}
int main(){
    init();
    solve();
    return 0;
}