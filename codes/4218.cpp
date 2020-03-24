/*
    Hint: use monotonic queue
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
int n, d, a[5000005];
int que[5000005], hd, tl, que2[5000005], hd2, tl2;
bool is[5000005] = {0};
void init(){
    n = read(), d = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
}
void solve(){
    hd = tl = 0;
    hd2 = tl2 = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        while(tl > hd && que[hd] < i - d)
            hd++;
        while(tl2 > hd2 && que2[hd2] > (n - i + 1) + d)
            hd2++;
        if(!is[i] && a[que[hd]] > 2 * a[i])
            ans++, is[i] = 1;
        if(!is[n - i + 1] && a[que2[hd2]] > 2 * a[n - i + 1])
            ans++, is[n - i + 1] = 1;
        while(tl > hd && a[que[tl - 1]] <= a[i])
            tl--;
        que[tl++] = i;
        while(tl2 > hd2 && a[que2[tl2 - 1]] <= a[n - i + 1])
            tl2--;
        que2[tl2++] = n - i + 1;
    }
    cout << ans << endl;
}
int main(){
    init();
    solve();
    return 0;
}