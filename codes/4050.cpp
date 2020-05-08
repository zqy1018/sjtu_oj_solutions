/*
    Hint: use network flow
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
int n, m, a[105][105];
int to[100005], cap[100005], nxt[100005], at[10005], cnt = 0;
int flow[100005] = {0}, cur[100005] = {0}, d[10005] = {0};
int pos[10005] = {0};
bool vis[10005] = {0}, isleft[10005] = {0};
queue<int> q;
int S, T;
inline void addedge(int u_, int v_, int c_){
    if (!isleft[u_]) swap(u_, v_);
    to[cnt] = v_, nxt[cnt] = at[u_], cap[cnt] = c_, at[u_] = cnt++;
    to[cnt] = u_, nxt[cnt] = at[v_], cap[cnt] = 0, at[v_] = cnt++;
}
bool bfs(){
	memset(vis, 0, sizeof(vis));
	q.push(S);
    d[S] = 0, vis[S] = true;
	while (!q.empty()){
		int h = q.front();
        q.pop();
		for (int i = at[h]; i != -1; i = nxt[i]){
			if (!vis[to[i]] && cap[i] > flow[i])
				vis[to[i]] = true, 
				d[to[i]] = d[h] + 1,
                q.push(to[i]);
		}
	}
	return vis[T];
}
int dfs(int u, int f){
	if (u == T || f == 0) return f;
	int now_flow = 0, fl;
	for (int &i = cur[u]; i != -1; i = nxt[i]){
        if (d[to[i]] == d[u] + 1 && (fl = dfs(to[i], min(f, cap[i] - flow[i]))) > 0){
            flow[i] += fl, flow[i ^ 1] -= fl;
            now_flow += fl, f -= fl;
            if (!f) break;
        }
	}
	return now_flow;
}
int dinic(){
	int max_flow = 0, ans;
	while (bfs()){
		for (int i = 0; i <= n * m + 1; ++i)
			cur[i] = at[i];
		max_flow += dfs(S, INF);
	}
	return max_flow;
}
void init(){
    n = read(), m = read();
    int tot = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] = read();
    for (int i = 1; i <= n; ++i)
        for (int j = (i & 1 ? 1: 2); j <= m; j += 2)
            isleft[(i - 1) * m + j] = true;
    memset(at, -1, sizeof(at));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (i < n) addedge((i - 1) * m + j, i * m + j, INF);
            if (j < m) addedge((i - 1) * m + j, (i - 1) * m + j + 1, INF);
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            int id = (i - 1) * m + j;
            if (isleft[id]) 
                to[cnt] = id, nxt[cnt] = at[0], cap[cnt] = a[i][j], at[0] = cnt++,
                to[cnt] = 0, nxt[cnt] = at[id], cap[cnt] = 0, at[id] = cnt++;
            else 
                to[cnt] = n * m + 1, nxt[cnt] = at[id], cap[cnt] = a[i][j], at[id] = cnt++,
                to[cnt] = id, nxt[cnt] = at[n * m + 1], cap[cnt] = 0, at[n * m + 1] = cnt++;
        }
    S = 0, T = n * m + 1;
}
void solve(){
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)    
            sum += a[i][j];
    printf("%d\n", sum - dinic());
}
int main(){
    init();
    solve();
    return 0;
}