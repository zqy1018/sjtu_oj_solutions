/*
    Hint: use extended KMP
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
void exKMP(char s[], char t[], int n, int m, int nxt[], int z[]){
    nxt[0] = m;
    int j = 0, p = 1;
    while (j + 1 < m && t[j] == t[j + 1])
        ++j;
    nxt[1] = j;
    for (int i = 2; i < m; ++i) {
        int r = p + nxt[p] - 1, l = nxt[i - p];
        if (l <= r - i) nxt[i] = l;
        else {
            j = max(0, r - i + 1);
            while (j + i < m && t[j] == t[j + i])
                ++j;
            nxt[i] = j, p = i;
        }
    }

    j = 0, p = 0;
    while (j < n && j < m && s[j] == t[j])
        ++j;
    z[0] = j;
    for (int i = 1; i < n; ++i){
        int r = p + z[p] - 1, l = nxt[i - p];
        if (l <= r - i) z[i] = l;
        else {
            j = max(0, r - i + 1);
            while (j + i < n && j < m && t[j] == s[j + i])
                ++j;
            z[i] = j, p = i;
        }
    }
}
char s[3000005], t[3000005];
int nxt[3000005] = {0}, zs[3000005] = {0}, zt[3000005] = {0};
int n;
void init(){
    scanf("%s%s", s, t);
    n = strlen(s);
    exKMP(s, t, n, n, nxt, zs);
    memset(nxt, 0, sizeof(nxt));
    exKMP(t, s, n, n, nxt, zt);
}
void solve(){
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; ++i){
        int cur = zt[i];
        if (cur == n)
            ans1 = n;
        else if (zs[cur] >= i)
            ans1 = max(ans1, i + cur);
    }
    for (int i = 0; i < n; ++i){
        int cur = zs[i];
        if (cur == n)
            ans2 = n;
        else if (zt[cur] >= i)
            ans2 = max(ans2, i + cur);
    }
    printf("%d\n", max(ans1, ans2)) ;
}
int main(){
    init();
    solve();
    return 0;
}