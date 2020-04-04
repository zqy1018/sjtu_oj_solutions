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
int n, k;
pair<int, int> p[50005];
int vis[100005] = {0};
const int M = 100007;
int c[2][11][50005] = {0};
int f[2][11];
inline int lowbit(int x){
    return x & (-x);
}
inline int modadd(int x, int y){
    return (x + y >= M ? x + y - M: x + y);
}
void add(int v, int k, int *cc){
    while (k <= n)
        cc[k] = modadd(cc[k], v), k += lowbit(k);
}
int query(int r, int *cc)   {
    int res = 0;
    while (r > 0)
        res = modadd(res, cc[r]), r -= lowbit(r);
    return res;
}
void init(){
    n = read(), k = read();
    for (int i = 1; i <= n; ++i)
        p[i].first = read(), p[i].second = read();
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; ++i)   
        vis[p[i].second] = i;
    int cur = 0;
    for (int i = 1; i <= 100000; ++i)
        if (vis[i]) p[vis[i]].second = ++cur;
}
void solve(){
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        int pos = p[i].second;
        // 求解
        for (int j = 1; j <= k; ++j)
            f[0][j] = modadd(query(pos - 1, c[0][j]), query(pos - 1, c[1][j - 1])), 
            f[1][j] = modadd(
                modadd(query(n, c[1][j]), M - query(pos, c[1][j])), 
                modadd(query(n, c[0][j - 1]), M - query(pos, c[0][j - 1]))
            );
        
        ans = modadd(ans, f[0][k]), ans = modadd(ans, f[1][k]);
        
        // 更新
        add(1, pos, c[0][0]), add(1, pos, c[1][0]);
        for (int j = 1; j <= k; ++j)
            add(f[0][j], pos, c[0][j]), add(f[1][j], pos, c[1][j]);
    }
    printf("%d\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}