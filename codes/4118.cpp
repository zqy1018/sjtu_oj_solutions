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
int n, m;
ll dp[28][28][28] = {0}, C[28][28] = {0};
char pre[30], in[30];
ll dfs(int st1, int st2, int l){
    int tot = 0;
    ll res = 1;
    for (int i = st1 + 1, j = st2; i < st1 + l; ){
        int lsti = i, lstj = j;
        while (j < st2 + l - 1 && pre[lsti] != in[j])
            ++i, ++j;
        ++tot;
        res *= dfs(lsti, lstj, j - lstj + 1);
        ++i, ++j;
    }
    res *= C[m][tot];
    return res;
}
void init(){
    m = read();
    scanf("%s%s", pre, in);
    n = strlen(pre);
    C[0][0] = 1;
    for (int i = 1; i <= m; ++i){
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
}
void solve(){
    printf("%lld\n", dfs(0, 0, n));
}
int main(){
    init();
    solve();
    return 0;
}