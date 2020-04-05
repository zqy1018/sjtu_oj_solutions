/*
    Hint: build triangular matrix
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
int n, len[1005] = {0}, tmp[1005];
char s[1005][1005];
void init(){
    n = read();
    for (int i = 0; i < n; ++i)
        scanf("%s", s[i]);
}
void solve(){
    int ans = 0;
    for (int i = n - 1; i >= 0; --i){
        for (int j = 0; j < n; ++j)
            len[j] = (s[j][i] == '0' ? 0: len[j] + 1), 
            tmp[j] = len[j];
        sort(tmp, tmp + n);
        for (int j = n - 1; j >= 0; --j)
            ans = max(ans, tmp[j] * (n - j));
    }
    printf("%d\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}