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

#define N 1000001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

struct matrix
{
    int r,c;
    ll mat[101][101];

    matrix(int a,int b)
    {
        r=a,c=b;
        ms(mat,0);
    }
    void print()
    {
        cout<<"--------------"<<endl;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cout<<mat[i][j]<<' ';
            cout<<endl;
        }
        cout<<"--------------"<<endl;
    }
};

matrix multiply(matrix &a,matrix &b)
{
    matrix res(a.r,b.c);
    for(int i=0;i<res.r;i++)
    {
        for(int j=0;j<res.c;j++)
        {
            for(int k=0;k<a.c;k++)
            {
                res.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%mod;
                res.mat[i][j]%=mod;
            }
        }
    }
    return res;
}

matrix modPower(matrix &a,int b)
{
    matrix res(a.r,a.c);
    for(int i=0;i<res.r;i++)
        res.mat[i][i]=1;
    while(b)
    {
        if(b&1)
            res=multiply(res,a);
        a=multiply(a,a);
        b>>=1;
    }
    return res;
}

int first[N],cost[N],last[N];
int fcnt[101],cnt[101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,l,m;
    cin>>n>>l>>m;
    matrix res(m,m),f(1,m);
    for(int i=0;i<n;i++)
    {
        cin>>first[i];
        first[i]%=m;
        f.mat[0][first[i]]++;
    }
//    f.print();
    for(int i=0;i<n;i++)
    {
        cin>>cost[i];
        cost[i]%=m;
        cnt[cost[i]]++;
    }
    for(int i=0;i<n;i++)
        cin>>last[i];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
            res.mat[i][(i+j)%m]+=cnt[j];
    }
//    res.print();
    res=modPower(res,l-2);
//    res.print();
    res=multiply(f,res);
//    res.print();
    ll ans=0;
    for(int i=0;i<n;i++)
        ans+=res.mat[0][(m-(cost[i]+last[i])+m)%m],ans%=mod;
    cout<<ans<<endl;
    return 0;
}
