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

#define N 35005
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

struct segmentedTree
{
    int value[4*N];
    int lazy[4*N];
    void update(int node,int l,int r,int i,int j,int v)
    {
        if(lazy[node])
        {
            value[node]+=lazy[node];
            if(l!=r)
                lazy[node*2]+=lazy[node],lazy[node*2+1]+=lazy[node];
            lazy[node]=0;
        }
        if(i>r||j<l)
            return;
        if(i<=l&&j>=r)
        {
            value[node]+=v;
            if(l!=r)
                lazy[node*2]+=v,lazy[node*2+1]+=v;
            return;
        }
        int mid=(l+r)>>1;
        update(node*2,l,mid,i,j,v);
        update(node*2+1,mid+1,r,i,j,v);
        value[node]=max(value[node*2],value[node*2+1]);
    }

    void update2(int node,int l,int r,int pos,int v)
    {
        if(lazy[node])
        {
            value[node]+=lazy[node];
            if(l!=r)
                lazy[node*2]+=lazy[node],lazy[node*2+1]+=lazy[node];
            lazy[node]=0;
        }
        int mid=(l+r)>>1;
        if(pos>r||pos<l)
            return;
        if(pos<=l&&pos>=r)
        {
            value[node]=v;
            return;
        }
        update2(node*2,l,mid,pos,v);
        update2(node*2+1,mid+1,r,pos,v);
        value[node]=max(value[node*2],value[node*2+1]);
    }

    int query(int node,int l,int r,int i,int j)
    {
        int mid=(l+r)>>1;
        if(lazy[node])
        {
            value[node]+=lazy[node];
            if(l!=r)
                lazy[node*2]+=lazy[node],lazy[node*2+1]+=lazy[node];
            lazy[node]=0;
        }
        if(i>r||j<l)
            return 0;
        if(i<=l&&j>=r)
            return value[node];
        return max(query(node*2,l,mid,i,j),query(node*2+1,mid+1,r,i,j));
    }
}st[2];

int data[N];
int last[N];
int pos[N];
//int temp[2][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>data[i];
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(pos[data[i]])
            last[i]=pos[data[i]];
        else
            cnt++;
        st[0].update2(1,0,n,i,cnt);
        //temp[0][i]=cnt;
        pos[data[i]]=i;
    }
    int v=1;
    for(int i=2;i<=k;i++)
    {
        v=i&1;
        for(int j=0;j<i;j++)
            st[v^1].update2(1,0,n,j,st[v].query(1,0,n,0,j));//,temp[v^1][j]=st[v].query(1,0,n,0,j);
        for(int j=i;j<=n;j++)
        {
            st[v].update(1,0,n,last[j],j-1,1);
//            for(int l=0;l<=n;l++)
//                cout<<st[v].query(1,0,n,l,l)<<' ';
//            cout<<endl;
            st[v^1].update2(1,0,n,j,st[v].query(1,0,n,0,j));
            //temp[v^1][j]=st[v].query(1,0,n,0,j);
        }
    }
    cout<<st[v^1].query(1,0,n,0,n)<<endl;
    return 0;
}
