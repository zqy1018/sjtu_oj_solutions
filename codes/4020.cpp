#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int n,a[1005],f[1005][1005]={0};
int read(){
    int f=1,x=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x; 
}    
void init(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read(); 
}
void solve(){
    for(int i=1;i<=n;i++){
        int maxi=0;
        for(int j=i;j<=n;j++)
            maxi=max(maxi,f[i-1][j-1]),
            f[i][j]=maxi+(a[j]==i);
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,f[i][n]);
    printf("%d\n",ans);
}
int main(){
    init();
    solve();
    return 0;
}  
