/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu1625.md
*/
#include <cstdio>
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
int n, q, ans[500005] = {0}, tans[1500005];
int at[100005] = {0}, nxt[200005], to[200005], cnt = 0;
int at2[3000005] = {0}, nxt2[3000005], to2[3000005], cnt2 = 0;
int par[100005], dep[100005];
bool vis[100005] = {0}, typ[500005] = {0};
int Find(int x){
    return (par[x] == x ? x: (par[x] = Find(par[x])));
}
void Union(int xxxx, int yyyy){
    int u = Find(xxxx), v = Find(yyyy);
    if (u == v) return ;
    par[u] = v;
}
void init(){
    n = read();
    for (int i = 1; i < n; ++i){
        int u = read(), v = read();
        to[++cnt] = v, nxt[cnt] = at[u], at[u] = cnt;
        to[++cnt] = u, nxt[cnt] = at[v], at[v] = cnt;
    }
    q = read();
    for (int i = 1; i <= q; ++i){
        int u = read(), v = read(), w = read();
        to2[++cnt2] = v, nxt2[cnt2] = at2[u], at2[u] = cnt2;    // u v
        to2[++cnt2] = u, nxt2[cnt2] = at2[v], at2[v] = cnt2;    // v u
        to2[++cnt2] = u, nxt2[cnt2] = at2[w], at2[w] = cnt2;    // w u
        to2[++cnt2] = w, nxt2[cnt2] = at2[u], at2[u] = cnt2;    // u w
        to2[++cnt2] = w, nxt2[cnt2] = at2[v], at2[v] = cnt2;    // v w
        to2[++cnt2] = v, nxt2[cnt2] = at2[w], at2[w] = cnt2;    // w v
    }
}
void dfs(int cur, int fa){
    par[cur] = cur;
    for (int i = at[cur]; i; i = nxt[i]){
        int v = to[i];
        if (v == fa) continue;
        dep[v] = dep[cur] + 1, dfs(v, cur), Union(v, cur);
    }
    vis[cur] = true;
    for (int i = at2[cur]; i; i = nxt2[i]){
        int v = to2[i];
        if (i % 6 == 0){
            // as a root, determine the type
            int u = to2[i - 3], ccnt = 0;
            if (Find(u) == cur) ++ccnt;
            if (Find(v) == cur) ++ccnt;
            if (ccnt == 2) typ[i / 6] = false;  // both in w
            else if (ccnt == 1) ans[i / 6] = cur;
            else typ[i / 6] = true;
 
            if (vis[v])
                tans[i / 2] = Find(v);
        }else {
            if (!vis[v]) continue;
            int iid = (i / 6), idx = i % 6;
            if (idx <= 2)
                tans[iid * 3 + 1] = Find(v);
            else if (idx <= 4)  
                tans[iid * 3 + 2] = Find(v);
            else
                tans[iid * 3 + 3] = Find(v);
        }
    }
}
void solve(){
    dep[1] = 0;
    dfs(1, 0);
    for (int i = 1; i <= q; ++i){
        ans[i] = tans[i * 3 - 2];
        if (dep[ans[i]] < dep[tans[i * 3 - 1]])
            ans[i] = tans[i * 3 - 1];
        if (dep[ans[i]] < dep[tans[i * 3]])
            ans[i] = tans[i * 3];
    }
    for (int i = 1; i <= q; ++i)
        printf("%d\n", ans[i]);
}
int main(){
    init();
    solve();
    return 0;
}