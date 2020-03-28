/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/cs222quiz_2019.md
*/
#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
char s[100005];
char opr[100005];
int l, lis[100005], tot;
vector<int> vec[10][10];
int read(int &st){
    int f = 1, x = 0;
    while (!isdigit(s[st])){
        // nonsense
        if (s[st] == '-')
            f = -f;
        ++st;
    }
    while (st < l && isdigit(s[st])){
        x = x * 10 + s[st] - '0';
        ++st;
    }
    return f * x;
}
void init(){
    scanf("%s", s);
    l = strlen(s);
    tot = 0;
    int st = 0;
    if (s[0] == '-'){
        lis[tot] = 0;
        opr[tot++] = '-';
        st = 1;
    }
    lis[tot] = read(st);
    while (st < l){
        opr[tot++] = s[st++];
        lis[tot] = read(st);
    }
}
inline int calc(char c, int x, int y){
    if (c == '+') return x + y;
    if (c == '-') return x - y;
    return x * y;
}
void dfs(int l, int r){
    if (!vec[l][r].empty()) return ;
    for (int i = l; i < r; ++i){
        dfs(l, i), dfs(i + 1, r);
        for (auto x: vec[l][i])
            for (auto y: vec[i + 1][r])
                vec[l][r].push_back(calc(opr[i], x, y));
    }
}
void solve(){
    for (int i = 0; i <= tot; ++i)
        vec[i][i].push_back(lis[i]);
    dfs(0, tot);
    sort(vec[0][tot].begin(), vec[0][tot].end());
    printf("%d", vec[0][tot][0]);
    int lb = vec[0][tot].size();
    for (int i = 1; i < lb; ++i)    
        printf(" %d", vec[0][tot][i]);
    printf("\n");
}
int main(){
    init();
    solve();
    return 0;
}