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

class matrix
{
    ll mat[16][16];
public:
    int n,m;
    matrix(int a=1,int b=1)
    {
        n=a,m=b;
        ms(mat,0);
    }

    void print()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<mat[i][j]<<' ';
            cout<<endl;
        }
    }

    matrix operator*(matrix a)
    {
        matrix res(n,a.m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<a.m;j++)
            {
                for(int k=0;k<m;k++)
                    res[i][j]=(res[i][j]+mat[i][k]*a[k][j])%mod;
            }
        }
        return res;
    }

    ll* operator[](int idx)
    {
        return mat[idx];
    }
};

matrix modPower(matrix a,ll b)
{
    matrix res(a.n,a.m);
    for(int i=0;i<res.n;i++)
        res[i][i]=1;
    while(b)
    {
        if(b&1)
            res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}

vector<matrix> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    for(int i=1;i<=16;i++)
    {
        matrix a(i,i);
        for(int j=0;j<i;j++)
        {
            for(int k=j-1;k<j+2;k++)
            {
                if(k>=0&&k<i)
                    a[j][k]=1;
            }
        }
        v.push_back(a);
    }
    int n;
    ll k;
    cin>>n>>k;
    int last=16;
    matrix a(16);
    a[0][0]=1;
    for(int i=0;i<n;i++)
    {
        ll s,t;
        int y;
        cin>>s>>t>>y;
        matrix b(y+1);
        for(int j=0;j<min(y+1,last);j++)
            b[j][0]=a[j][0];
        a=modPower(v[y],min(k,t)-s)*b;
        last=y+1;
    }
    cout<<a[0][0]<<endl;
    return 0;
}
