/*
    Warning: maybe not a good solution
    See the editorial at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4143.md
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
int n, m;
int vis[105][105] = {0};
bool ok[105][105][4][4] = {0}, made[105][105] = {0};
int st[105][105][5] = {0};
char grid[105][105];
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
queue<int> qx, qy;
queue<pair<pair<int, int>, int> > q;
void valid(int bx, int by, int curx, int cury){
    memset(vis, 0, sizeof(vis));
    qx.push(curx), qy.push(cury);
    vis[curx][cury] = 1;
    while (!qx.empty()){
        int cx = qx.front(), cy = qy.front();
        qx.pop(), qy.pop();
        for (int i = 0; i < 4; ++i){
            int ex = cx + dx[i], ey = cy + dy[i];
            if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                continue;
            if (ex == bx && ey == by) continue;
            if (vis[ex][ey] || grid[ex][ey] == 'S') continue;
            vis[ex][ey] = 1;
            qx.push(ex), qy.push(ey);
        }
    }
}
void valid2(int bx, int by){
    memset(vis, 0, sizeof(vis));
    made[bx][by] = true;
    int lis[4], lislen;
    for (int i = 0; i < 4; ++i){
        int x = bx + dx[i], y = by + dy[i];
        if (x < 0 || x >= n || y < 0 || y >= m)
            continue;
        if (vis[x][y] || grid[x][y] == 'S') continue;
        qx.push(x), qy.push(y);
        vis[x][y] = i + 1;
        while (!qx.empty()){
            int cx = qx.front(), cy = qy.front();
            qx.pop(), qy.pop();
            for (int j = 0; j < 4; ++j){
                int ex = cx + dx[j], ey = cy + dy[j];
                if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                    continue;
                if (ex == bx && ey == by) continue;
                if (vis[ex][ey] || grid[ex][ey] == 'S') continue;
                vis[ex][ey] = i + 1;
                qx.push(ex), qy.push(ey);
            }
        }
        lislen = 0;
        for (int j = 0; j < 4; ++j){
            int ex = bx + dx[j], ey = by + dy[j];
            if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                continue;
            if (vis[ex][ey] == i + 1)
                lis[lislen++] = j;
        }
        for (int j = 0; j < lislen; ++j)
            for (int t = 0; t < lislen; ++t)
                ok[bx][by][lis[j]][lis[t]] = true;
    }
}
void init(){
    n = read(), m = read();
    for (int i = 0; i < n; ++i)
        scanf("%s", grid[i]);
}
void solve(){
    int stx = -1, sty = -1;
    int renx = -1, reny = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            if (grid[i][j] == 'P'){
                stx = i, sty = j;
            }
            if (grid[i][j] == 'M'){
                renx = i, reny = j;
            }
        }
    valid(stx, sty, renx, reny);
    memset(st, 0x3f, sizeof(st));
    for (int i = 0; i < 4; ++i){
        int ex = stx + dx[i], ey = sty + dy[i];
        if (ex < 0 || ex >= n || ey < 0 || ey >= m)
            continue;
        if (!vis[ex][ey]) continue;
        q.push(make_pair(make_pair(stx, sty), i));
        st[stx][sty][i] = 1;
    }
    int ans = 0x3f3f3f3f;
    while (!q.empty()){
        auto pp = q.front();
        q.pop();
        int oppo = (pp.second ^ 1);
        int ccx = pp.first.first, ccy = pp.first.second;
        int cx = ccx + dx[oppo], cy = ccy + dy[oppo];
        // new posi for box
        if (cx < 0 || cx >= n || cy < 0 || cy >= m)
            continue;
        if (grid[cx][cy] == 'S') continue;
        if (grid[cx][cy] == 'K'){
            // final
            ans = st[ccx][ccy][pp.second];
            break;
        }
        if (!made[cx][cy])
            valid2(cx, cy);
        int cur_step = st[ccx][ccy][pp.second];
        for (int i = 0; i < 4; ++i){
            if (!ok[cx][cy][pp.second][i])
                continue;
            if (st[cx][cy][i] <= cur_step + 1)
                continue;
            st[cx][cy][i] = cur_step + 1;
            q.push(make_pair(make_pair(cx, cy), i));
        }
    }
    if (ans == 0x3f3f3f3f)
        printf("NO\n");
    else printf("%d\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}