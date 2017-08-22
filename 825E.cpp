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

int degree[N];

struct segmentTree
{
    int value[4*N];

    void build(int node,int l,int r)
    {
        int mid=(l+r)>>1;
        if(l==r)
        {
            value[node]=l;
            return;
        }
        build(node*2,l,mid);
        build(node*2+1,mid+1,r);
        if(degree[value[node*2]]<degree[value[node*2+1]])
            value[node]=value[node*2];
        else
            value[node]=value[node*2+1];
    }
    void update(int node,int l,int r,int pos,int v)
    {
        if(pos>r||pos<l)
            return;
        if(pos==l&&pos==r)
        {
            degree[l]=v;
            value[node]=l;
            return;
        }
        int mid=(l+r)>>1;
        update(node*2,l,mid,pos,v);
        update(node*2+1,mid+1,r,pos,v);
        if(degree[value[node*2]]<degree[value[node*2+1]])
            value[node]=value[node*2];
        else
            value[node]=value[node*2+1];
    }
    int query()
    {
        return value[1];
    }
}st;

vector< vi > adj(N);
int res[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    degree[0]=inf;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[b].push_back(a);
        degree[a]++;
    }
    st.build(1,1,n);
    int cnt=0;
    int value=n;
    set<int> s;
    while(cnt<n)
    {
        while(degree[st.query()]==0)
        {
            int node=st.query();
            s.insert(node);
            st.update(1,1,n,node,inf);
        }
        if(!s.empty())
        {
            int node=*s.rbegin();
            res[node]=value--;
            for(int i=0;i<adj[node].size();i++)
                st.update(1,1,n,adj[node][i],degree[adj[node][i]]-1);
            s.erase(--s.end());
            cnt++;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<res[i]<<' ';
    cout<<endl;
    return 0;
}
