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

ll data[4*N];
ll con[4*N],var[4*N],lazy[4*N];

class segmentTree
{
    int n;
    
    void pUpdate(int node, int l, int r, int p, ll v)
    {
        int mid=(l+r)>>1;
        if(p>r||p<l)
            return;
        if(p==l&&p==r)
        {
            data[node]=v;
            return;
        }
        pUpdate(node*2, l, mid, p, v);
        pUpdate(node*2+1, mid+1, r, p, v);
        data[node]=max(data[node*2],data[node*2+1]);
    }
    
    ll pQuery(int node, int l, int r, int i, int j)
    {
        int mid=(l+r)>>1;
        if(i>r||j<l)
            return 0;
        if(i<=l&&j>=r)
            return data[node];
        return max(pQuery(node*2, l, mid, i, j), pQuery(node*2+1, mid+1, r, i, j));
    }
public:
    segmentTree(int n)
    {
        this->n=n;
    }
    
    void update(int pos,ll value)
    {
        pUpdate(1,1,n,pos,value);
    }
    
    ll query(int i,int j)
    {
       return pQuery(1,1,n,i,j);
    }
};

class dividedSegmentTree
{
    int n;
    segmentTree st=0;
    
    void pUpdateConst(int node, int l, int r, int p, ll v)
    {
        int mid=(l+r)>>1;
        if(lazy[node])
        {
            var[node]=lazy[node];
            con[node]=st.query(l,r);
            if(l!=r)
                lazy[node*2]=lazy[node*2+1]=lazy[node];
            lazy[node]=0;
        }
        if(p>r||p<l)
            return;
        if(p==l&&p==r)
        {
            con[node]=v;
            return;
        }
        pUpdateConst(node*2, l, mid, p, v);
        pUpdateConst(node*2+1, mid+1, r, p, v);
        if(con[node*2]+var[node*2]>con[node*2+1]+var[node*2+1])
            con[node]=con[node*2],var[node]=var[node*2];
        else
            con[node]=con[node*2+1],var[node]=var[node*2+1];
    }
    
    void pUpdateVar(int node, int l, int r, int i, int j, ll v)
    {
        int mid=(l+r)>>1;
        if(lazy[node])
        {
            var[node]=lazy[node];
            con[node]=st.query(l,r);
            if(l!=r)
                lazy[node*2]=lazy[node*2+1]=lazy[node];
            lazy[node]=0;
        }
        if(i>r||j<l)
            return;
        if(i<=l&&j>=r)
        {
            var[node]=v;
            con[node]=st.query(l,r);
            if(l!=r)
                lazy[node*2]=lazy[node*2+1]=v;
            return;
        }
        pUpdateVar(node*2, l, mid, i, j, v);
        pUpdateVar(node*2+1, mid+1, r, i, j, v);
        if(con[node*2]+var[node*2]>con[node*2+1]+var[node*2+1])
            con[node]=con[node*2],var[node]=var[node*2];
        else
            con[node]=con[node*2+1],var[node]=var[node*2+1];
    }
    
    ll pQuery(int node,int l,int r,int i,int j)
    {
        int mid=(l+r)>>1;
        if(lazy[node])
        {
            var[node]=lazy[node];
            con[node]=st.query(l,r);
            if(l!=r)
                lazy[node*2]=lazy[node*2+1]=lazy[node];
            lazy[node]=0;
        }
        if(i>r||j<l)
            return 0;
        if(i<=l&&j>=r)
            return con[node]+var[node];
        return max(pQuery(node*2,l,mid,i,j),pQuery(node*2+1,mid+1,r,i,j));
    }

public:
    dividedSegmentTree(int n,segmentTree &t)
    {
        st=t;
        this->n=n;
    }
    
    void updateCon(int p,ll v)
    {
        pUpdateConst(1,1,n,p,v);
    }
    
    void updateVar(int i,int j,ll v)
    {
        pUpdateVar(1,1,n,i,j,v);
    }
    
    ll query(int i,int j)
    {
        return pQuery(1,1,n,i,j);
    }
};

int arr[N],limit[N],temp[N];
ll dp[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,c;
    cin>>n>>c;
    segmentTree t(N);
    vector<int> v;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        temp[i]=arr[i];
        sum+=temp[i];
        v.push_back(arr[i]);
    }
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    for(int i=1;i<=n;i++)
    {
        arr[i]=lower_bound(all(v),arr[i])-v.begin()+1;
        limit[i]=t.query(1,arr[i]-1)+1;
        t.update(arr[i],i);
    }
    segmentTree con(n);
    dividedSegmentTree st(n,con);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        con.update(i,dp[i-1]);
        st.updateCon(i,dp[i-1]);
        st.updateVar(limit[i],i,temp[i]);
        dp[i]=dp[i-1];
        if(i-c+1>0)
            dp[i]=max(dp[i],st.query(1,i-c+1));
    }
    cout<<sum-dp[n]<<endl;
    return 0;
}
