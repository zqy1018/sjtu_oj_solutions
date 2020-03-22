/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4290.md
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
int n, m;
int at[100005] = {0}, nxt[100005], to[100005], cnt = 0;
int f[100005] = {0};
bool vis[100005] = {0};
void dfs(int cur){
    vis[cur] = true;
    for (int i = at[cur]; i; i = nxt[i]){
        if (!vis[to[i]])
            f[to[i]] = f[cur], dfs(to[i]);
    }
}
void init(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        to[++cnt] = u, nxt[cnt] = at[v], at[v] = cnt;
    }
}
void solve(){
    for (int i = n; i >= 1; --i){
        if (!vis[i])
            f[i] = i, dfs(i);
    }
    for (int i = 1; i < n; ++i)
        printf("%d ", f[i]);
    printf("%d\n", f[n]);
}
int main(){
    init();
    solve();
    return 0;
}