/*
    Hint: Disjoint set
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
int n, g[100005], fa[100005], siz[100005], tot;
int Find(int x){
    return (fa[x] == x ? x: (fa[x] = Find(fa[x])));
}
void Union(int x, int y){
    int u = Find(x), v = Find(y);
    if (u == v) return ;
    if (siz[u] < siz[v])
        fa[u] = v, siz[v] += siz[u];
    else 
        fa[v] = u, siz[u] += siz[v];
    --tot;
}
void init(){
    n = read();
    tot = n;
    for (int i = 1; i <= n; ++i)
        fa[i] = i, siz[i] = 1;
    for (int i = 1; i <= n; ++i)
        g[i] = read() + 1, Union(i, g[i]);
}
void solve(){
    printf("%d\n", tot - 1);
}
int main(){
    init();
    solve();
    return 0;
}