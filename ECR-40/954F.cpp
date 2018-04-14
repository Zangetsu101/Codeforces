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

#define N 10001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

typedef vector< vector<ll> > matrix;

matrix multiply(matrix a,matrix b)
{
    int n=a.size(),m=b[0].size();
    matrix res(n,vector<ll>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<b.size();k++)
                res[i][j]=(res[i][j]+a[i][k]*b[k][j])%mod;
        }
    }
    return res;
}

matrix power(matrix a,ll b)
{
    matrix res(a.size(),vector<ll>(a[0].size(),0));
    for(int i=0;i<a.size();i++)
        res[i][i]=1;
    while(b)
    {
        if(b&1)
            res=multiply(res,a);
        a=(multiply(a,a));
        b>>=1;
    }
    return res;
}

matrix states[]={{{1,1,0},{1,1,1},{0,1,1}},{{0,0,0},{0,1,1},{0,1,1}},{{1,0,0},{0,0,0},{0,0,1}},
                 {{0,0,0},{0,0,0},{0,0,1}},{{1,1,0},{1,1,0},{0,0,0}},{{0,0,0},{0,1,0},{0,0,0}},
                 {{1,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}}};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    ll last=1,var=0;
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,pair<bool,int> > > v;
    v.push_back({1,{true,0}});
    for(int i=0;i<n;i++)
    {
        int a;
        ll l,r;
        cin>>a>>l>>r;
        v.push_back({l,{true,a}});
        v.push_back({r,{false,a}});
    }
    sort(all(v));
    v.push_back({m,{true,0}});
    int i=1;
    matrix ans={{0},{1},{0}};
    int a[4]={0};
    while(i<v.size())
    {
        matrix temp=power(states[var],v[i].first-last);
        ans=multiply(temp,ans);
        last=v[i].first;
        v[i].second.first?a[v[i].second.second]++:a[v[i].second.second]--;
        var=0;
        for(int j=1;j<4;j++)
        {
            if(a[j])
                var|=(1<<(j-1));
        }
        for(int j=0;j<3;j++)
            ans[j][0]*=(((~var)>>j)&1);
        i++;
    }
    cout<<ans[1][0]<<endl;
    return 0;
}
/*
2 10
2 2 8
3 5 5
 */
