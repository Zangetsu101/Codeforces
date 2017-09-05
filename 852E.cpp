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

#define N 100001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

ll dp[N][2];
ll value[N][2];
vector< vi > adj(N);
ll ans;

ll modPower(ll a,int b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
            res*=a,res%=mod;
        a*=a;
        a%=mod;
        b>>=1;
    }
    return res;
}

ll modInverse(ll a)
{
    return modPower(a,mod-2);
}

ll dfs(int node,int p,bool mood)
{
    if(dp[node][mood]!=-1)
        return dp[node][mood];
    if(dp[node][!mood]!=-1)
        return dp[node][mood]=dp[node][!mood];
    dp[node][mood]=1;
    value[node][0]=1;
    value[node][1]=1;
    bool flag=false;
    for(int i=0;i<adj[node].size();i++)
    {
        int v=adj[node][i];
        if(v!=p)
        {
            value[node][0]*=dfs(v,node,false);
            value[node][0]%=mod;
            value[node][1]*=dfs(v,node,true);
            value[node][1]%=mod;
            flag=true;
        }
    }
    if(!flag)
        return dp[node][mood];
    return dp[node][mood]=(value[node][0]+value[node][1])%mod;
}

void dfs2(int node,int p)
{
    ans+=dp[node][1];
    ans%=mod;
    for(int i=0;i<adj[node].size();i++)
    {
        int v=adj[node][i];
        if(v!=p)
        {
            value[node][0]=(value[node][0]*modInverse(dp[v][0]))%mod;
            value[node][1]=(value[node][1]*modInverse(dp[v][1]))%mod;
            if(adj[node].size()>1)
                dp[node][0]=dp[node][1]=(value[node][0]+value[node][1])%mod;
            else
                dp[node][0]=dp[node][1]=1;
            value[v][0]*=dp[node][0],value[v][0]%=mod;
            value[v][1]*=dp[node][1],value[v][1]%=mod;
            dp[v][0]=dp[v][1]=(value[v][0]+value[v][1])%mod;
            dfs2(v,node);
            value[v][0]=(value[v][0]*modInverse(dp[node][0]))%mod;
            value[v][1]=(value[v][1]*modInverse(dp[node][1]))%mod;
            if(adj[v].size()>1)
                dp[v][0]=dp[v][1]=(value[v][0]+value[v][1])%mod;
            else
                dp[v][0]=dp[v][1]=1;
            value[node][0]*=dp[v][0],value[node][0]%=mod;
            value[node][1]*=dp[v][1],value[node][1]%=mod;
            dp[node][0]=dp[node][1]=(value[node][0]+value[node][1])%mod;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    cin>>n;
    ms(dp,-1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0,true);
    dfs(1,0,false);
    dfs2(1,0);
    cout<<ans<<endl;
    return 0;
}

/*
8
1 2
1 3
2 4
3 5
3 6
4 7
4 8
*/
