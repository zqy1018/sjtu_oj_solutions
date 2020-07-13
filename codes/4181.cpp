#include <bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define MAXN 200005
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
#define REPR(temp, init_val, end_val) for (int temp = init_val; temp >= end_val; --temp)
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}

int n, m;
int lst[5041][7], tot;
bool ok[650][650] = {0};
int f[10][650];
void init(){
    n = read(), m = read();
    tot = 0;
    int tmp[10];
    REP(i, 0, m - 1)
        tmp[i] = i + 1;
    do{
        bool flag = true;
        REP(i, 1, m - 1){
            if (abs(tmp[i] - tmp[i - 1]) == 1){
                flag = false;
                break;
            }
        }
        if (flag){
            ++tot;
            REP(i, 0, m - 1)
                lst[tot][i] = tmp[i];
        }
    }while (next_permutation(tmp, tmp + m));
    REP(i, 1, tot)
        REP(j, i, tot){
            ok[i][j] = ok[j][i] = true;
            REP(k, 0, m - 1){
                if (abs(lst[i][k] - lst[j][k]) == 1){
                    ok[i][j] = ok[j][i] = false;
                    break;
                }
            }
        }
}
void solve(){
    int tmp[10], ans = 0;
    REP(i, 0, m - 1)
        tmp[i] = read();
    REP(i, 1, tot){
        bool flag = true;
        int res = 0;
        REP(j, 0, m - 1){
            if (tmp[j] != lst[i][j] && tmp[j]){
                flag = false;
                break;
            }
            res += lst[i][j] * (j + 1);
        }
        if (flag) f[1][i] = res;
        else f[1][i] = -1;
    }
    REP(i, 2, n){
        REP(j, 0, m - 1)
            tmp[j] = read();
        REP(j, 1, tot){
            f[i][j] = -1;
            REP(t, 1, tot){
                if (!ok[j][t] || f[i - 1][t] < 0) continue;
                bool flag = true;
                int res = 0;
                REP(u, 0, m - 1){
                    if (tmp[u] != lst[j][u] && tmp[u]){
                        flag = false;
                        break;
                    }
                    res += lst[j][u] * (u + 1);
                }
                if (flag) 
                    f[i][j] = max(f[i][j], f[i - 1][t] + res);
            }
            ans = max(ans, f[i][j]);
        }
    }
    printf("%d\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}