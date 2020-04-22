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
int n, m;
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
char s[1005][1005];
int d1[1005][1005], d2[1005][1005];
bool vis[1005][1005];
queue<int> qx, qy;
void bfs(int xxx, int yyy, int d[][1005]){
    qx.push(xxx), qy.push(yyy);
    d[xxx][yyy] = 0;
    memset(vis, 0, sizeof(vis));
    vis[xxx][yyy] = true;
    while (!qx.empty()){
        int cx = qx.front(), cy = qy.front();
        qx.pop(), qy.pop();
        for (int i = 0; i < 4; ++i){
            int ex = cx + dx[i], ey = cy + dy[i];
            if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                continue;
            if (vis[ex][ey] || s[ex][ey] == '#') continue;
            d[ex][ey] = d[cx][cy] + 1;
            qx.push(ex), qy.push(ey);
            vis[ex][ey] = true;
        }
    }
}
void init(){
    scanf("%d%d", &n, &m);
    if (n <= 20){
        for (int i = 0; i < n; ++i)
            scanf("%s", s[i]);
    }else {
        char o[10];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j){
                scanf("%s", o);
                s[i][j] = o[0];
            }
    }
    
}
void solve(){
    int stx1, stx2, sty1, sty2;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            if (s[i][j] == 'H') stx1 = i, sty1 = j;
            if (s[i][j] == 'S') stx2 = i, sty2 = j;
        }
    memset(d1, 0x3f, sizeof(d1));
    memset(d2, 0x3f, sizeof(d2));
    bfs(stx1, sty1, d1);
    bfs(stx2, sty2, d2);
    int ans = INF;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i][j] == 'B' && d1[i][j] < 0x3f3f3f3f && d2[i][j] < 0x3f3f3f3f){
                if (d1[i][j] + d2[i][j] < ans)
                    ans = d1[i][j] + d2[i][j];
            }
    printf("%d\n", ans) ;
}
int main(){
    init();
    solve();
    return 0;
}