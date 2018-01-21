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

#define N 100001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int value[4*N];
int lazy[4*N];
int maxi[4*N];
int sum[N];
int data[N];

void build(int node,int l,int r)
{
    if(l==r)
    {
        value[node]=sum[l];
        maxi[node]=sum[l];
        return;
    }
    int mid=(l+r)>>1;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    value[node]=value[node*2]+value[node*2+1];
    maxi[node]=max(maxi[node*2],maxi[node*2+1]);
}

void update(int node,int l,int r,int i,int j,int v)
{
    if(lazy[node])
    {
        value[node]+=(r-l+1)*lazy[node];
        maxi[node]+=lazy[node];
        if(l!=r)
            lazy[node*2]+=lazy[node],lazy[node*2+1]+=lazy[node];
        lazy[node]=0;
    }
    if(i>r||j<l)
        return;
    if(i<=l&&j>=r)
    {
        value[node]+=(r-l+1)*v;
        maxi[node]+=v;
        if(l!=r)
            lazy[node*2]+=v,lazy[node*2+1]+=v;
        return;
    }
    int mid=(l+r)>>1;
    update(node*2,l,mid,i,j,v);
    update(node*2+1,mid+1,r,i,j,v);
    value[node]=value[node*2]+value[node*2+1];
    maxi[node]=max(maxi[node*2],maxi[node*2+1]);
}

int query(int node,int l,int r,int i,int j)
{
    if(lazy[node])
    {
        value[node]+=(r-l+1)*lazy[node];
        maxi[node]+=lazy[node];
        if(l!=r)
            lazy[node*2]+=lazy[node],lazy[node*2+1]+=lazy[node];
        lazy[node]=0;
    }
    if(i>r||j<l)
        return -inf;
    if(i<=l&&j>=r)
        return maxi[node];
    int mid=(l+r)>>1;
    return max(query(node*2,l,mid,i,j),query(node*2+1,mid+1,r,i,j));
}

int sumQuery(int node,int l,int r,int i)
{
    if(lazy[node])
    {
        value[node]+=(r-l+1)*lazy[node];
        maxi[node]+=lazy[node];
        if(l!=r)
            lazy[node*2]+=lazy[node],lazy[node*2+1]+=lazy[node];
        lazy[node]=0;
    }
    int mid=(l+r)>>1;
    if(i>r||i<l)
        return 0;
    if(i<=l&&i>=r)
        return value[node];
    return sumQuery(node*2,l,mid,i)+sumQuery(node*2+1,mid+1,r,i);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
        sum[i+1]=sum[i]+data[i];
    }
    build(1,1,n);
    if(query(1,1,n,1,n)>d)
    {
        cout<<-1<<endl;
        return 0;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(data[i])
            continue;
        int v=sumQuery(1,1,n,i+1);
        int m=query(1,1,n,i+1,n);
        if(d-m<-v)
        {
            cout<<-1<<endl;
            return 0;
        }
        if(v<0)
        {
            ans++;
            update(1,1,n,i+1,n,d-m);
        }
    }
    cout<<ans<<endl;
    return 0;
}
