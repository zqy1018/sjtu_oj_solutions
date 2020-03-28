/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/cs222quiz_2019.md
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
int n, f[3005];
char s[3005];
bool ok[3005][3005] = {0};
void init(){
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i){
        ok[i][i] = true;
        for (int j = i - 1, k = i + 1; j >= 0 && k < n && s[j] == s[k]; --j, ++k)
            ok[j][k] = true;
        for (int j = i, k = i + 1; j >= 0 && k < n && s[j] == s[k]; --j, ++k)
            ok[j][k] = true;
    }
}
void solve(){
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j <= i; ++j)
            if (ok[j][i])
                f[i + 1] = min(f[i + 1], f[j] + 1);
    }
    printf("%d\n", f[n] - 1);
}
int main(){
    init();
    solve();
    return 0;
}