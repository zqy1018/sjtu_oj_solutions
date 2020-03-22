/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4289.md
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
int n;
int at[100005], nxt[200005], to[200005], cnt = 0;
int d[100005] = {0};
double p[100005] = {0}, ans = 0;
void dfs(int cur, int fa){
    int cnt = 0;
    for (int i = at[cur]; i; i = nxt[i]){
        int v = to[i];
        if (v == fa) continue;
        ++cnt;
    }
    if (!cnt){
        ans += p[cur] * d[cur];
        return ;
    }
    for (int i = at[cur]; i; i = nxt[i]){
        int v = to[i];
        if (v == fa) continue;
        p[v] = p[cur] * (1.0 / cnt);
        d[v] = d[cur] + 1;
        dfs(v, cur);
    }
}
void init(){
    n = read();
    for (int i = 1; i < n; ++i){
        int u = read(), v = read();
        to[++cnt] = v, nxt[cnt] = at[u], at[u] = cnt;
        to[++cnt] = u, nxt[cnt] = at[v], at[v] = cnt;
    }
}
void solve(){
    p[1] = 1.0;
    dfs(1, 0);
    printf("%.2lf\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}