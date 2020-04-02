/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4123.md
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
int n, m, ql[100005], qr[100005], qx[100005];
int seg[263000] = {0}, tag[263000] = {0};
int siz, _a, _b, _v;
char s[100005], ans[100005] = {0};
void pushdown(int id, int len){
    if (tag[id] != 0){
        if (tag[id] == 1) 
            seg[id << 1] = seg[id << 1 | 1] = 0;
        else
            seg[id << 1] = seg[id << 1 | 1] = len;
        tag[id << 1] = tag[id << 1 | 1] = tag[id];
        tag[id] = 0;
    }
}
void update(int id, int l, int r){
    if (r < _a || l > _b) return ;
    if (l >= _a && r <= _b){
        if (_v == 1) seg[id] = 0;
        else seg[id] = (r - l + 1);
        tag[id] = _v;
        return ;
    }
    int len = (r - l + 1) >> 1;
    pushdown(id, len);
    update(id << 1, l, l + len - 1);
    update(id << 1 | 1, l + len, r);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
int query(int id, int l, int r){
    if (r < _a || l > _b) return 0;
    if (l >= _a && r <= _b) return seg[id];
    int len = (r - l + 1) >> 1;
    pushdown(id, len);
    return query(id << 1, l, l + len - 1) + query(id << 1 | 1, l + len, r);
}
void dfs(int id, int len){
    pushdown(id, len);
    if ((id << 1) >= siz) return ;
    dfs(id << 1, len >> 1);
    dfs(id << 1 | 1, len >> 1);
}
void init(){
    n = read(), m = read();
    scanf("%s", s);
    for (int i = 1; i <= m; ++i)
        ql[i] = read(), qr[i] = read(), qx[i] = read();
    for (siz = 1; siz < n; siz <<= 1);
}
void solve(){
    if (n == 1) {
        printf("%s\n", s);
        return ;
    }
    for (int j = 0; j < 26; ++j){
        for (int i = 0; i < n; ++i){
            if (s[i] - 'a' <= j)
                seg[i + siz] = 1;
            else seg[i + siz] = 0;
            tag[i + siz] = 0;
        }
        for (int i = siz - 1; i >= 1; --i)
            seg[i] = seg[i << 1] + seg[i << 1 | 1], 
            tag[i] = 0;
        for (int i = 1; i <= m; ++i){
            _a = ql[i], _b = qr[i];
            int sm = query(1, 1, siz);
            if (sm == _b - _a + 1) continue;
            if (qx[i] == 1)
                _v = 2, _b = _a + sm - 1, update(1, 1, siz), 
                _v = 1, _a = _b + 1, _b = qr[i], update(1, 1, siz);
            else
                _v = 2, _a = _b - sm + 1, update(1, 1, siz), 
                _v = 1, _b = _a - 1, _a = ql[i], update(1, 1, siz);
        }
        dfs(1, (siz >> 1));
        for (int i = 0; i < n; ++i)
            if (seg[i + siz] && !ans[i])
                ans[i] = j + 'a';
    }
    ans[n] = '\0';
    printf("%s\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}