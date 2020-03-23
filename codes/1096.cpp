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
int S, T, M, P;
int a[1000005], b[1000005];
int dis[1000005];
int que[1000005], hd, tl;
void init(){
    for (int i = 1; i <= M; ++i)
        a[i] = read() % P, b[i] = read() % P;
    memset(dis, 0x3f, sizeof(dis));
}
void solve(){
    if (S == T){
        printf("0\n");
        return ;
    }
    if (T >= P) {
        printf("-1\n");
        return ;
    }
    hd = tl = 0;
    if (S < P) dis[S] = 0;
    /* warning: S may be larger than P. */
    S %= P;
    for (int i = 1; i <= M; ++i){
        int t = (1ll * a[i] * S + b[i]) % P;
        if (dis[t] == 1) continue;
        dis[t] = 1;
        if (t == T){
            printf("%d\n", dis[t]);
            return ;
        }
        que[tl++] = t;
    }
    while (tl > hd){
        int h = que[hd++];
        for (int i = 1; i <= M; ++i){
            int t = (1ll * a[i] * h + b[i]) % P;
            if (dis[t] <= dis[h] + 1)
                continue;
            dis[t] = dis[h] + 1;
            if (t == T){
                printf("%d\n", dis[t]);
                return ;
            }
            que[tl++] = t;
        }
    }
    printf("-1\n");
}
int main(){
    while (scanf("%d%d%d%d", &S, &T, &M, &P) == 4){
        init();
        solve();
    }
    return 0;
}