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

#define N 200001
#define mod 1000000007
#define inf 1e15

typedef long long ll;
typedef unsigned long long ull;

ll data[N];
vector< vi > adj(N);
ll dp[N];
ll value[N];
ll ans=-inf;

void dfs(int node,int p)
{
    ll b=-inf,sb=-inf;
    for(int i=0;i<adj[node].size();i++)
    {
        int v=adj[node][i];
        if(v!=p)
        {
            dfs(v,node);
            if(dp[v]>=b)
                sb=b,b=dp[v];
            else if(dp[v]>sb)
                sb=dp[v];
        }
    }
    if(sb!=-inf)
        ans=max(ans,b+sb);
    dp[node]=b;
    value[node]=data[node];
    for(int i=0;i<adj[node].size();i++)
    {
        if(adj[node][i]!=p)
            value[node]+=value[adj[node][i]];
    }
    dp[node]=max(dp[node],value[node]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>data[i];
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    if(ans!=-inf)
        cout<<ans<<endl;
    else
        cout<<"Impossible"<<endl;
    return 0;
}
