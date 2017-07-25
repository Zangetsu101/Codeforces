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
#define mod 100000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int n;
vector<vi > adj(N);
int chainHead[N];
int value[4*N];
int lazy[4*N];

int func(int a,int b)
{
    return a+b;
}

void update(int node,int l,int r,int i,int j,int v)
{
    if(lazy[node]!=-1)
    {
        value[node]=lazy[node]*(r-l+1);
        if(l!=r)
            lazy[node*2]=lazy[node*2+1]=lazy[node];
        lazy[node]=-1;
    }
    if(i>r||j<l)
        return;
    if(i<=l&&j>=r)
    {
        value[node]=v*(r-l+1);
        if(l!=r)
            lazy[node*2]=lazy[node*2+1]=v;
        return;
    }
    int mid=(l+r)>>1;
    update(node*2,l,mid,i,j,v);
    update(node*2+1,mid+1,r,i,j,v);
    value[node]=func(value[node*2],value[node*2+1]);
}

int query(int node,int l,int r,int i,int j)
{
    if(lazy[node]!=-1)
    {
        value[node]=lazy[node]*(r-l+1);
        if(l!=r)
            lazy[node*2]=lazy[node*2+1]=lazy[node];
        lazy[node]=-1;
    }
    if(i>r||j<l)
        return 0;
    if(i<=l&&j>=r)
        return value[node];
    int mid=(l+r)>>1;
    return func(query(node*2,l,mid,i,j),query(node*2+1,mid+1,r,i,j));
}

struct node
{
    int parent;
    int chain;
    int children;
    int pos;
    int schild;
    int depth;
}nodes[N];

int dfs(int node,int parent,int d)
{
    nodes[node].parent=parent;
    nodes[node].children=1;
    nodes[node].depth=d;
    int snode=0,ssize=0;
    for(int i=0;i<adj[node].size();i++)
    {
        int v=adj[node][i];
        if(v!=parent)
        {
            nodes[node].children+=dfs(v,node,d+1);
            if(nodes[v].children>ssize)
                ssize=nodes[v].children,snode=v;
        }
    }
    nodes[node].schild=snode;
    return nodes[node].children;
}

void HLD(int node,int &chain,int &pos)
{
    if(!chainHead[chain])
        chainHead[chain]=node;
    nodes[node].chain=chain;
    nodes[node].pos=pos;
    //update(1,0,n-1,pos,nodes[node].value);
    if(nodes[node].schild)
        HLD(nodes[node].schild,chain,++pos);
    for(int i=0;i<adj[node].size();i++)
    {
        int v=adj[node][i];
        if(v!=nodes[node].parent&&v!=nodes[node].schild)
            HLD(v,++chain,++pos);
    }
}

void init()
{
    ms(lazy,-1);
    dfs(1,0,1);
    int pos=1;
    int chain=1;
    HLD(1,chain,pos);
}

int pathQuery(int x,int y)
{
    int ans=0;
    while(nodes[x].chain!=nodes[y].chain)
    {
        int top;
        if(nodes[chainHead[nodes[x].chain]].depth>nodes[chainHead[nodes[y].chain]].depth)
        {
            top=chainHead[nodes[x].chain];
            ans=func(ans,query(1,1,n,nodes[top].pos,nodes[x].pos));
            x=nodes[top].parent;
        }
        else
        {
            top=chainHead[nodes[y].chain];
            ans=func(ans,query(1,1,n,nodes[top].pos,nodes[y].pos));
            y=nodes[top].parent;
        }
    }
    ans=func(ans,query(1,1,n,min(nodes[x].pos,nodes[y].pos),max(nodes[x].pos,nodes[y].pos)));
    return ans;
}

void pathUpdate(int x,int y,int v)
{
    while(nodes[x].chain!=nodes[y].chain)
    {
        int top;
        if(nodes[chainHead[nodes[x].chain]].depth>nodes[chainHead[nodes[y].chain]].depth)
        {
            top=chainHead[nodes[x].chain];
            update(1,1,n,nodes[top].pos,nodes[x].pos,v);
            x=nodes[top].parent;
        }
        else
        {
            top=chainHead[nodes[y].chain];
            update(1,1,n,nodes[top].pos,nodes[y].pos,v);
            y=nodes[top].parent;
        }
    }
    update(1,1,n,min(nodes[x].pos,nodes[y].pos),max(nodes[x].pos,nodes[y].pos),v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int q;
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        int a;
        cin>>a;
        adj[i+1].push_back(a);
        adj[a].push_back(i+1);
    }
    init();
    for(int i=0;i<q;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int ans=0;
        pathUpdate(b,a,1);
        ans=max(ans,pathQuery(c,a));
        ans=max(ans,pathQuery(c,b));
        update(1,1,n,1,n,0);
        pathUpdate(a,c,1);
        ans=max(ans,pathQuery(b,c));
        //ans=max(ans,pathQuery(b,a));
        update(1,1,n,1,n,0);
        //pathUpdate(b,c,1);
        //ans=max(ans,pathQuery(a,b));
        //ans=max(ans,pathQuery(a,c));
        //update(1,1,n,1,n,0);
        cout<<ans<<endl;
    }
    return 0;
}
