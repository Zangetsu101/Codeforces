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

ll data[N];
ll value[4*N];
int k;

void build(int node,int l,int r)
{
    int mid=(l+r)>>1;
    if(l==r)
    {
        value[node]=data[l]%k;
        return;
    }
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    value[node]=(value[node*2]*value[node*2+1])%k;
}

ll query(int node,int l,int r,int i,int j)
{
    int mid=(l+r)>>1;
    if(i>r||j<l)
        return 1;
    if(i<=l&&j>=r)
        return value[node];
    return (query(node*2,l,mid,i,j)*query(node*2+1,mid+1,r,i,j))%k;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    data[0]=1;
    int n;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>data[i];
    ll ans=0;
    int i=0,j=0;
    build(1,0,n-1);
    ll p;
    while(i<n)
    {
        p=query(1,0,n-1,i,j);
        while(j<n-1&&p%k)
            p=query(1,0,n-1,i,++j);
        if(!(p%k))
            ans+=n-j;
        i++;
        j=max(i,j);
    }
    cout<<ans<<endl;
    return 0;
}
