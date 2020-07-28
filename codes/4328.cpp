#include <bits/stdc++.h>
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
char s[5005];
int ord[5005][5005] = {0};
int cnt[5005] = {0};
void init(){
    scanf("%s", s);
}
void solve(){
    int n = strlen(s);
    int hf = (n >> 1);
    REP(i, 0, n - 1)
        ord[i][i] = ord[i + 1][i] = 1;
    cnt[1] = n;
    REP(l, 1, hf){
        REP(i, l, n - l - 1){
            if (ord[i - l + 1][i + l - 1] && s[i - l] == s[i + l])
                ord[i - l][i + l] = ord[i + 1][i + l] + 1, 
                ++cnt[ord[i - l][i + l]];
        }
        REP(i, l - 1, n - l - 1){
            if (ord[i - l + 2][i + l - 1] && s[i - l + 1] == s[i + l]){
                ord[i - l + 1][i + l] = ord[i + 1][i + l] + 1, 
                ++cnt[ord[i - l + 1][i + l]];
            }
        }
    }
    REPR(i, n - 1, 1)
        cnt[i] += cnt[i + 1];
    REP(i, 1, n - 1)
        printf("%d ", cnt[i]);
    printf("%d\n", cnt[n]);
}
int main(){
    init();
    solve();
    return 0;
}