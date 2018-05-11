#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>

#define endl "\n"
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b)
#define pf printf
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define all(c) c.begin(),c.end()
#define ms(a,c) memset(a,c,sizeof(a))
#define tr(c,i) for(decltype((c).begin()) i=(c).begin();i!=(c).end();i++)
#define trr(c,i) for(decltype((c).rbegin()) i=(c).rbegin();i!=(c).rend();i++)

using namespace std;

#define N 31
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int dp[N][N][55];
bool flag[N][N][55];

int func(int h,int w,int k)
{
    int &ans=dp[h][w][k];
    if(flag[h][w][k])
        return ans;
    flag[h][w][k]=true;
    if(h*w==k||!k)
        return ans=0;
    for(int i=1;i<h;i++)
    {
        for(int j=0;j<=k;j++)
            ans=min(ans,func(i,w,j)+func(h-i,w,k-j)+w*w);
    }
    for(int i=1;i<w;i++)
    {
        for(int j=0;j<=k;j++)
            ans=min(ans,func(h,i,j)+func(h,w-i,k-j)+h*h);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,m,k;
    ms(dp,63);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cout<<func(n,m,k)<<endl;
    }
    return 0;
}
