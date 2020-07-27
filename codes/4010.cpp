#include <bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define MAXN 200005
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
#define REPR(temp, init_val, end_val) for (int temp = init_val; temp >= end_val; --temp)
using namespace std;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, a[1005], l[1005], r[1005];
void init(){
    n = read();
    REP(i, 1, n)
        l[i] = i - 1, r[i] = i + 1,
        a[i] = read();
    l[1] = n, r[n] = 1;
}
void solve(){
    int curdir = 1, cur = 1;
    REP(T, 1, n - 1){
        int mini = INF, tmp = cur;
        do{
            mini = min(mini, a[tmp]);
            tmp = (curdir ? r[tmp]: l[tmp]);
        }while (tmp != cur);
        do{
            a[tmp] -= mini - 1;
            tmp = (curdir ? r[tmp]: l[tmp]);
        }while (tmp != cur);
        for (; ; ){
            --a[cur];
            if (!a[cur]){
                if (curdir){
                    int to = l[cur];
                    r[to] = r[cur], l[r[cur]] = to;
                    cur = to;
                }else {
                    int to = r[cur];
                    l[to] = l[cur], r[l[cur]] = to;
                    cur = to;
                }
                curdir ^= 1;
                break;
            }
            cur = (curdir ? r[cur]: l[cur]);
        }
    }
    printf("%d\n", cur);
}
int main(){
    init();
    solve();
    return 0;
}