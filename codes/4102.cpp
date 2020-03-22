/* 
    Hint: use two monotonic queues (one for max and one for min)
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
int k, n;
int qmin[3000005][2], qmax[3000005][2];
int hdmin, tlmin, hdmax, tlmax;
void init(){
    k = read(), n = read();
}
void solve(){
    int lst = 0;
    int ans = 0;
    hdmin = tlmin = hdmax = tlmax = 0;
    for (int i = 1; i <= n; ++i){
        int a = read();
        while (tlmax > hdmax && qmax[tlmax - 1][0] <= a)
            --tlmax;
        qmax[tlmax][0] = a, qmax[tlmax++][1] = i;
        while (tlmin > hdmin && qmin[tlmin - 1][0] >= a)
            --tlmin;
        qmin[tlmin][0] = a, qmin[tlmin++][1] = i;
        while (qmax[hdmax][0] - qmin[hdmin][0] > k){
            ++lst;
            if (qmax[hdmax][1] == lst) ++hdmax;
            if (qmin[hdmin][1] == lst) ++hdmin;
        }
        ans = max(ans, i - lst);
    }
    printf("%d\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}