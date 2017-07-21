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

int value[4*N];

void update(int node,int l,int r,int pos,int v)
{
    int mid=(l+r)>>1;
    if(l>pos||r<pos)
        return;
    if(pos<=l&&pos>=r)
    {
        value[node]=v;
        return;
    }
    update(node*2,l,mid,pos,v);
    update(node*2+1,mid+1,r,pos,v);
    value[node]=max(value[node*2],value[node*2+1]);
}

int query(int node,int l,int r,int i,int j)
{
    int mid=(l+r)>>1;
    if(i>r||j<l)
        return 0;
    if(i<=l&&j>=r)
        return value[node];
    return max(query(node*2,l,mid,i,j),query(node*2+1,mid+1,r,i,j));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    cin>>n;
    set<int> s;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        int temp=query(1,1,n,1,a)+1;
        ans=max(ans,temp);
        update(1,1,n,a,temp);
    }
    cout<<ans<<endl;
    return 0;
}
