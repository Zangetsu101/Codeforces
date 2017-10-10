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
#define MAX (1<<9)+10
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

vi primes;
bool notPrime[N];

void sieve()
{
    primes.push_back(2);
    for(int i=3;i<N;i+=2)
    {
        if(!notPrime[i])
        {
            primes.push_back(i);
            if(i<=sqrt(N))
            {
                for(int j=i*i;j<N;j+=2*i)
                    notPrime[j]=true;
            }
        }
    }
}

vector< vi > factor(301);
int dp[MAX];
bool flag[MAX][301];
int mask[301];
int data[301];
int cost[301];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    sieve();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>data[i];
        a=data[i];
        int j=0;
        while(j<primes.size()&&primes[j]<=sqrt(a))
        {
            if(a%primes[j]==0)
            {
                factor[i].push_back(primes[j]);
                while(a%primes[j]==0)
                    a/=primes[j];
            }
            j++;
        }
        if(a>1)
            factor[i].push_back(a);
    }
    for(int i=1;i<=n;i++)
        cin>>cost[i];
    int ans=inf;
    for(int i=1;i<=n;i++)
    {
        ms(dp,63);
        ms(mask,0);
        ms(flag,0);
        int lim=factor[i].size();
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<lim;k++)
            {
                if(data[j]%factor[i][k]==0)
                    mask[j]|=1<<k;
            }
        }
        int m=0;
        for(int i=0;i<lim;i++)
            m|=1<<i;
        dp[m]=cost[i];
        flag[m][i]=true;
        for(int j=m;j>0;j--)
        {
            for(int k=1;k<=n;k++)
            {
                if(!flag[j][k]&&dp[j&mask[k]]>dp[j]+cost[k])
                {
                    dp[j&mask[k]]=dp[j]+cost[k];
                    for(int l=1;l<=n;l++)
                        flag[j&mask[k]][l]=flag[j][l];
                    flag[j&mask[k]][k]=true;
                }
            }
        }
        ans=min(ans,dp[0]);
    }
    if(ans!=inf)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
