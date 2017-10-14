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

#define N 300001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int p[N],r[N];
int length[N];
vector< vi > adj(N);
bool visited[N];
int depth[N];

int parent(int a)
{
    if(p[a]==a)
        return a;
    return p[a]=parent(p[a]);
}

void mergeSet(int a,int b)
{
    a=parent(a),b=parent(b);
    if(r[a]>r[b])
        p[b]=a;
    else
        p[a]=b;
    if(r[a]==r[b])
        r[b]++;
}

void dfs(int node,int p,vi &v)
{
    if(visited[node])
        return;
    v.push_back(node);
    visited[node]=true;
    depth[node]=depth[p]+1;
    for(int i=0;i<adj[node].size();i++)
        dfs(adj[node][i],node,v);
}

int findFurthestNode(vi &v,bool flag)
{
    int temp=0,node=0;
    for(int i=0;i<v.size();i++)
    {
        if(!flag)
            visited[v[i]]=false;
        if(depth[v[i]]>=temp)
            temp=depth[v[i]],node=v[i];
    }
    return node;
}

void createRegion(int node)
{
    if(visited[node])
        return;
    int t=node;
    vi v;
    dfs(node,0,v);
    node=findFurthestNode(v,false);
    v.clear();
    dfs(node,0,v);
    node=findFurthestNode(v,true);
    t=parent(t);
    length[t]=depth[node]-1;
}

void mergeRegion(int a,int b)
{
    a=parent(a),b=parent(b);
    if(a==b)
        return;
    mergeSet(a,b);
    int l1=length[a],l2=length[b];
    a=parent(a);
    int l=max(l1/2,l1-l1/2)+max(l2/2,l2-l2/2)+1;
    length[a]=max(max(l1,l2),l);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    for(int i=1;i<N;i++)
        p[i]=i;
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        mergeSet(a,b);
    }
    for(int i=1;i<=n;i++)
        createRegion(i);
    for(int i=0;i<q;i++)
    {
        int t,a,b;
        cin>>t;
        if(t==1)
        {
            cin>>a;
            cout<<length[parent(a)]<<endl;
        }
        else
        {
            cin>>a>>b;
            mergeRegion(a,b);
        }
    }
    return 0;
}
