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

#define N 2000010
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

vi primes;
bool notPrime[N];
ll fact[N];
ll inv[N];

void sieve()
{
    primes.push_back(2);
    for(int i=3;i<N;i+=2)
    {
        if(notPrime[i])
            continue;
        primes.push_back(i);
        if(i<=sqrt(N))
        {
            for(int j=i*i;j<N;j+=2*i)
                notPrime[j]=true;
        }
    }
}

ll power(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans*=a,ans%=mod;
        a*=a,a%=mod;
        b>>=1;
    }
    return ans;
}

ll modInverse(ll a)
{
    return power(a,mod-2);
}

ll nCr(int n,int r)
{
    return (((fact[n]*inv[n-r])%mod)*inv[r])%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    sieve();
    fact[0]=inv[0]=1;
    for(int i=1;i<N;i++)
        fact[i]=(fact[i-1]*i)%mod,inv[i]=modInverse(fact[i]);
    int q;
    cin>>q;
    for(int j=0;j<q;j++)
    {
        int x,y;
        cin>>x>>y;
        ll ans=1;
        int i=0;
        while(i<primes.size()&&primes[i]<=sqrt(x))
        {
            int cnt=0;
            while(x%primes[i]==0)
                cnt++,x/=primes[i];
            i++;
            if(!cnt)
                continue;
            ans=(ans*nCr(y+cnt-1,cnt))%mod;
        }
        if(x>1)
            ans=(ans*y)%mod;
        ans=(ans*power(2,y-1))%mod;
        cout<<(ans+mod)%mod<<endl;
    }
    return 0;
}
