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

#define N 5001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

ll dp[N];
ll sum[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,a,b,k;
    cin>>n>>a>>b>>k;
    dp[a]=1;
    for(int i=1;i<=n;i++)
    {
        if(i!=b)
            sum[i]=sum[i-1]+dp[i];
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==b)
                continue;
            int l=abs(b-j);
            if(b>j)
            {
                if(l%2)
                    l=j+l/2;
                else
                    l=j+l/2-1;
                dp[j]=(sum[j-1]+sum[l]-sum[j])%mod;
            }
            else
            {
                if(l%2)
                    l=j-l/2;
                else
                    l=j-l/2+1;
                dp[j]=(sum[n]-sum[j]+sum[j-1]-sum[l-1])%mod;
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(j!=b)
                sum[j]=(sum[j-1]+dp[j])%mod;
        }
    }
    if(sum[b-1]<0)
        sum[b-1]+=mod;
    if(sum[n]<0)
        sum[n]+=mod;
    cout<<(sum[b-1]+sum[n])%mod<<endl;
    return 0;
}
