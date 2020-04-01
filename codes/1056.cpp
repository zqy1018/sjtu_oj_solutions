/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu1056.md
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
int n, m, unused;
multiset<int> st;
int fa[500005], siz[500005];
bool vis[500005] = {0};
char opt[3];
void reduce(int pos){
    st.erase(st.find(pos));
}
void append(int pos){
    st.insert(pos);
}
 
// things above can be replaced by a BST, if STL is banned
int Find(int x){
    return (fa[x] == x ? x: (fa[x] = Find(fa[x])));
}
void Union(int x, int y){
    int u = Find(x), v = Find(y);
    if (u == v || !u || !v) return ;
    if (!vis[u]) append(1), vis[u] = true, --unused;
    if (!vis[v]) append(1), vis[v] = true, --unused;
    reduce(siz[u]);
    reduce(siz[v]);
    append(siz[u] + siz[v]);
    if (siz[u] > siz[v])
        fa[v] = u, siz[u] += siz[v];
    else
        fa[u] = v, siz[v] += siz[u];
}
void init(){
    n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        fa[i] = i, siz[i] = 1;
    fa[0] = 0, siz[0] = 0;
    unused = n;
}
void solve(){
    while (m--) {
        scanf("%s", opt);
        if (opt[0] == 'C'){
            int x = read(), y = read();
            Union(x, y);
        }
        if (opt[0] == 'D'){
            int x = Find(read());
            if (!x) continue;
            if (vis[x]) reduce(siz[x]);
            fa[x] = 0;
        }
        if (opt[0] == 'Q'){
            int t = read();
            if (st.size() < t) {
                t -= st.size();
                printf("%d\n", (t > unused ? 0: 1));
            }else {
                multiset<int>::iterator iter = st.end();
                while (t--)
                    --iter;
                printf("%d\n", *iter);
            }
        }
    } 
}
int main(){
    init();
    solve();
    return 0;
}