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
int n;
int to[200005], at[100005] = {0}, nxt[200005], cnt = 0, id[200005] = {0}, tot = 0;
bool used[100005] = {0};
bool dfs(int cur, int fa){
    bool ans = false;
    for (int i = at[cur]; i; i = nxt[i]){
        if(to[i] == fa) continue;
        bool res = dfs(to[i], cur);
        if(id[i] == 2){
            if(!res) used[to[i]] = ans = true, tot++;
            else ans = true;
        }else{
            if(res) ans = true;
        }
    }
    return ans;
}
void init(){
    n = read();
    for (int i = 1; i < n; ++i){
        int u = read(), v = read(), st = read();
        to[++cnt] = v, nxt[cnt] = at[u], id[cnt] = st, at[u] = cnt;
        to[++cnt] = u, nxt[cnt] = at[v], id[cnt] = st, at[v] = cnt;
    }
}
void solve(){
	dfs(1, 0);
    printf("%d\n", tot);
    for (int i = 1; i <= n; ++i)
        if(used[i]) printf("%d ", i);
}
int main(){
	init();
	solve();
	return 0;
}