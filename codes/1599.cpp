/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu1599.md
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
int n, tp = 0;
int st[1000005] = {0};
char st2[1000005];
void init(){
    n = read();
}
void solve(){
    char ord[3];
    while(n--){
        int opt = read();
        if(opt == 1){
            scanf("%s", ord);
            if(ord[0] == '(' || ord[0] == '[' || ord[0] == '{'){
                tp++, st[tp] = tp, st2[tp] = ord[0];
            }else {
                if(!tp) tp++, st[tp] = tp, st2[tp] = ord[0];
                else{
                    tp++, st2[tp] = ord[0];
                    if(ord[0] == ')'){
                        if(st2[st[tp - 1]] == '(')
                            st[tp] = st[st[tp - 1] - 1];
                        else st[tp] = tp;
                    }else if(ord[0] == ']'){
                        if(st2[st[tp - 1]] == '[')
                            st[tp] = st[st[tp - 1] - 1];
                        else st[tp] = tp;
                    }else if(ord[0] == '}'){
                        if(st2[st[tp - 1]] == '{')
                            st[tp] = st[st[tp - 1] - 1];
                        else st[tp] = tp;
                    }
                }
            }
        }
        if(opt == 2)
            if(tp) tp--;
        if(opt == 3){
            if(tp) putchar(st2[tp]), putchar('\n');
        }
        if(opt == 4){
            if(!tp) printf("YES\n");
            else printf("%s\n", st[tp] == 0 ? "YES": "NO");
        }
    }
}
int main(){
    init();
    solve();
    return 0;
}
