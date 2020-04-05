/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4165.md
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
int n, a[100005];
void init(){
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    int mini = 0;
    for (int i = 1; i <= n; ++i)
        a[i] = read() - a[i];
}
inline int sgn(int x){
    return (x == 0 ? 0: (x > 0 ? 1: -1));
}
void solve(){
    ll ans = 0;
    for (int i = 1; i <= n; ){
        int j = i;
        while (j <= n && sgn(a[i]) == sgn(a[j]))
            ++j;
        if (sgn(a[i]) > 0){
            int lst = 0;
            for (int t = i; t < j; ++t){
                if (a[t] > lst) ans += a[t] - lst;
                lst = a[t];
            }
        }else if (sgn(a[i]) < 0){
            int lst = 0;
            for (int t = i; t < j; ++t){
                if (-a[t] > lst) ans += -a[t] - lst;
                lst = -a[t];
            }
        } 
        i = j;
    }
    printf("%lld\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}