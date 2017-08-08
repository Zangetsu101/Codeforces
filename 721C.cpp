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

#define N 5001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int edge[N][N];
bool visited[N];
int dp[N][N];
short value[N][N];
vector< vi > adj(N);
int n;
short priority[N];

void dfs(int node,int prev,int p)
{
    if(visited[node])
        return;
    priority[node]=p;
    visited[node]=true;
    for(int i=0;i<adj[node].size();i++)
    {
        int v=adj[node][i];
        if(v!=prev&&p-1<priority[v])
        {
            visited[v]=false;
            dfs(v,node,p-1);
        }
    }
}

void bfs(int node)
{
    ms(dp,63);
    ms(visited,false);
    dp[node][1]=0;
    priority_queue< pii,vii > q;
    q.push(pii(priority[node],node));
    while(!q.empty())
    {
        node=q.top().second;
        q.pop();
        if(visited[node])
            continue;
        visited[node]=true;
        for(int i=0;i<adj[node].size();i++)
        {
            int v=adj[node][i];
            if(visited[v])
                continue;
            for(int j=1;j<=n;j++)
            {
                if(1LL*dp[v][j]>1LL*dp[node][j-1]+edge[node][v])
                {
                    dp[v][j]=dp[node][j-1]+edge[node][v];
                    value[v][j]=node;
                }
            }
            q.push(pii(priority[v],v));
        }
    }
}

//bool check(int v)
//{
//    int node=n;
//    while(v>1)
//        node=value[node][v--];
//    return node==1;
//}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int m,t;
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++)
        priority[i]=N;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge[a][b]=c;
        adj[a].push_back(b);
    }
    dfs(1,0,n);
    bfs(1);
    int ans=0;
    for(int i=n;i>0;i--)
    {
        if(dp[n][i]<=t)
        {
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    stack<short> s;
    s.push(n);
    int node=n;
    for(int i=ans;i>1;i--)
        s.push(value[node][i]),node=value[node][i];
    while(!s.empty())
        cout<<s.top()<<' ',s.pop();
    cout<<endl;
    return 0;
}
