#include <cstdio>
#include <algorithm>
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
int n, k;
int to[200005], at[100005], nxt[200005], cnt = 0;
int ans[100005], tot = 0;
int dfs(int cur, int fa){
    int maxi = 0, siz = 1;
    for (int i = at[cur]; i; i = nxt[i]){
        int v = to[i];
        if (v == fa) continue;
        int dd = dfs(v, cur);
        siz += dd;
        maxi = max(maxi, dd);
    }
    maxi = max(maxi, n - siz);
    if (maxi <= k) ans[++tot] = cur;
    return siz;
}
void init(){
    n = read(), k = read();
    for (int i = 1; i < n; ++i){
        int u = read(), v = read();
        to[++cnt] = v, nxt[cnt] = at[u], at[u] = cnt;
        to[++cnt] = u, nxt[cnt] = at[v], at[v] = cnt;
    }
}
void solve(){
    dfs(1, 0);
    if (tot == 0){
        printf("None\n");
    }else {
        sort(ans + 1, ans + tot + 1)    ;
        for (int i = tot; i > 1; --i)
            printf("%d ", ans[i]);
        printf("%d\n", ans[1]);
    }
    
}
int main(){
    init();
    solve();
    return 0;
}