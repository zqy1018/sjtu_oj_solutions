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
char s[100005];
int n, cnt[26] = {0};
char ans[100005], st[100005];
void init(){
    scanf("%s", s);
    n = strlen(s);
    REP(i, 0, n - 1)
        ++cnt[s[i] - 'a'];
}
void solve(){
    int top = 0, cur = 0;
    int l = 0;
    REP(i, 0, 25){
        while (top && st[top] <= i + 'a')
            ans[l++] = st[top], --top;
        while (cnt[i]){
            if (s[cur] == i + 'a'){
                ans[l++] = i + 'a';
            }else {
                st[++top] = s[cur];
            }
            --cnt[s[cur] - 'a'];
            ++cur;
        }
    }
    while (top)
        ans[l++] = st[top], --top;
    ans[n] = '\0';
    printf("%s\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}