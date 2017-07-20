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
#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d %d",&a,&b)
#define sfff(a,b,c) scanf("%d %d %d",&a,&b,&c)
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

#define N 50001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int dp[N][501];
bool visited[N];
int parent[N];
vector< vi > adj(N);
int n,k;
ll ans;

void dfs(int node,int p)
{
    if(visited[node])
        return;
    visited[node]=true;
    parent[node]=p;
    for(int i=0;i<adj[node].size();i++)
        dfs(adj[node][i],node);
    dp[node][0]=1;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<adj[node].size();j++)
        {
            if(adj[node][j]!=parent[node])
                dp[node][i]+=dp[adj[node][j]][i-1];
        }
    }
}

void solve(int node)
{
    if(visited[node])
        return;
    visited[node]=true;
    ans+=dp[node][k];
    if(parent[node]!=-1)
    {
        dp[parent[node]][0]=0;
        for(int i=0;i<k;i++)
            dp[parent[node]][i+1]-=dp[node][i];
        for(int i=0;i<k-1;i++)
            ans+=1LL*dp[node][i]*dp[parent[node]][k-i-1];
    }
    for(int i=0;i<adj[node].size();i++)
        solve(adj[node][i]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    ms(visited,false);
    solve(1);
    cout<<ans<<endl;
    return 0;
}
