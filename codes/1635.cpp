/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu1635.md
*/
#include <cstdio>
#include <cstring>
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
int to2[2000005], nxt2[2000005], at2[3000005] = {0}, cnt2 = 0;
int to[2000005], nxt[2000005], at[1000005] = {0}, w[2000005], cnt = 0;
int dis[1000005];
void init(){
    n = read(), m = read();
    for (int i = 1; i <= m; ++i){
        int u = read(), v = read(), ww = read();
        to[++cnt] = v, w[cnt] = ww, nxt[cnt] = at[u], at[u] = cnt;
        to[++cnt] = u, w[cnt] = ww, nxt[cnt] = at[v], at[v] = cnt;
    }
}
void solve(){
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    to2[++cnt2] = 1, nxt2[cnt2] = at2[0], at2[0] = cnt2;
    int cur = 0;
    for (int i = 1; i <= n; ++i){
        while (!at2[cur]) ++cur;
        for (int j = at2[cur]; j; j = nxt2[j]){
            int u = to2[j];
            if (dis[u] < cur) continue;
            for (int t = at[u]; t; t = nxt[t]){
                int v = to[t];
                if (dis[v] <= dis[u] + w[t]) continue;
                dis[v] = dis[u] + w[t];
                to2[++cnt2] = v, nxt2[cnt2] = at2[dis[v]], at2[dis[v]] = cnt2;
            }
        }
        ++cur;
    }
    printf("%d\n", dis[n]);
}
int main(){
    init();
    solve();
    return 0;
}