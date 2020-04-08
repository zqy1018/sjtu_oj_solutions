#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct node{
    int x, y, to;
    node(int _x, int _y, int _t):
        x(_x), y(_y), to(_t){}
    node(){}
};
node q[100005];//N0 S3 W2 E1
int n, m, ma[55][55] = {0};
int rear = 0, front = 0;
int st[2], ls[2];   // start point and destination
const int dx[] = {-1, 0, 0, 1}, dy[] = {0, 1, -1, 0};
int dis[55][55][4];
char dir;
inline void enque(int a, int b, int c){
    q[rear++] = node(a, b, c);
}
int bfs(){
    int dir_id;
    if (dir == 'N') dir_id = 0;
    if (dir == 'S') dir_id = 3;
    if (dir == 'E') dir_id = 1;
    if (dir == 'W') dir_id = 2;
    dis[st[0]][st[1]][dir_id] = 0;
    enque(st[0], st[1], dir_id);
    while (rear > front){
        int cx = q[front].x;
        int cy = q[front].y;
        int cd = q[front++].to;
        int step = dis[cx][cy][cd];
        for (int i = 0; i < 4; ++i)
            if (cd != i && cd + i != 3 && dis[cx][cy][i] == 0x3f3f3f3f)
                dis[cx][cy][i] = step + 1, enque(cx, cy, i); 
        for (int i = 0; i < 3; ++i){
            cx += dx[cd], cy += dy[cd];
            if (cx <= 0 || cy <= 0 || cx >= n || cy >= m)
                break;
            if (ma[cx][cy]) break;  // keypoint
            if (dis[cx][cy][cd] < 0x3f3f3f3f) continue;
            dis[cx][cy][cd] = step + 1, enque(cx, cy, cd);
        } 
    }
    int res = 0x3f3f3f3f;
    for (int i = 0; i < 4; ++i)
        res = min(res, dis[ls[0]][ls[1]][i]);
    return res;
}
int main(){//仅有left right 
    scanf("%d%d", &n, &m);
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            int t;
            scanf("%d", &t);
            if(t)
                ma[i][j] = ma[i - 1][j - 1] = ma[i - 1][j] = ma[i][j - 1] = 1;
        }
    }
    scanf("%d%d%d%d %c", &st[0], &st[1], &ls[0], &ls[1], &dir);
    if (ma[st[0]][st[1]] || ma[ls[0]][ls[1]]){
        printf("-1\n");
        return 0;
    }    
    int ans = bfs();
    printf("%d\n", (ans < 0x3f3f3f3f ? ans: -1));
    return 0;    
}