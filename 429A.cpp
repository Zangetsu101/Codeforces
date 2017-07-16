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

#define N 100001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

vector< vi > adj(N);
bool visited[N];
int target[N],initial[N];
int lazy[N];
vi ans;

void propagate(int node)
{
    if(visited[node])
        return;
    for(int i=0;i<adj[node].size();i++)
        lazy[adj[node][i]]++;
}

void dfs(int node)
{
    if(visited[node])
        return;
    visited[node]=true;
    lazy[node]%=2;
    if(lazy[node])
    {
        initial[node]=!initial[node];
        for(int i=0;i<adj[node].size();i++)
            propagate(adj[node][i]);
    }
    if(initial[node]!=target[node])
    {
        ans.push_back(node);
        for(int i=0;i<adj[node].size();i++)
            propagate(adj[node][i]);
    }
    for(int i=0;i<adj[node].size();i++)
        dfs(adj[node][i]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a)
            initial[i+1]=true;
    }
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a)
            target[i+1]=true;
    }
    dfs(1);
    cout<<ans.size()<<endl;
    tr(ans,it)
        cout<<*it<<endl;
    return 0;
}
