/*
    Hint: use a deque to replace the stack and find the relation between the result 
        and the length of consecutive 1's at the front/back of the deque
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
int n, fa[200005], len[200005] = {0};
int val[200005] = {0};
deque<int> dq;
char opt[10];
void init(){
    n = read();
}
int Find(int x){
    return (fa[x] == x ? x: (fa[x] = Find(fa[x])));
}
void solve(){
    bool rt = true;
    for (int i = 1; i <= n; ++i){
        scanf("%s", opt);
        if (opt[0] == 'P'){
            if (opt[1] == 'U'){
                int x = read();
                fa[i] = i, val[i] = x;
                if (rt){
                    if (x == 0) len[i] = 0;
                    else {
                        if (!dq.empty() && val[dq.back()])
                            fa[i] = Find(dq.back()), ++len[fa[i]];
                        else 
                            len[i] = 1;
                    }
                    dq.push_back(i);
                }else {
                    if (x == 0) len[i] = 0;
                    else {
                        if (!dq.empty() && val[dq.front()])
                            fa[i] = Find(dq.front()), ++len[fa[i]];
                        else 
                            len[i] = 1;
                    }
                    dq.push_front(i);
                }
            }else{
                if (dq.empty()) continue;
                if (rt) {
                    if (val[dq.back()])
                        --len[Find(dq.back())];
                    dq.pop_back();
                }else {
                    if (val[dq.front()])
                        --len[Find(dq.front())];
                    dq.pop_front();
                }
            }
        }
        if (opt[0] == 'R'){
            rt = !rt;
        }
        if (opt[0] == 'Q'){
            if (dq.empty()){
                printf("Invalid.\n");
            }else {
                if (dq.size() == 1){
                    printf("%d\n", val[dq.front()]);
                }else if (dq.size() == 2){
                    printf("%d\n", (val[dq.front()] & val[dq.back()]) ^ 1);
                }else {
                    if (!rt) {
                        int ll = len[Find(dq.back())];
                        if (ll >= dq.size() - 1)
                            printf("%d\n", ll & 1);
                        else printf("%d\n", (ll + 1) & 1);
                    }else {
                        int ll = len[Find(dq.front())];
                        if (ll >= dq.size() - 1)
                            printf("%d\n", ll & 1);
                        else printf("%d\n", (ll + 1) & 1);
                    }
                }
            }
        }
    }
}
int main(){
    init();
    solve();
    return 0;
}