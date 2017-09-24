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
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

ll power(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
            res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}

int getFirstDigit(ll a)
{
    while(a>=10)
        a/=10;
    return a;
}

int digitCount(ll a)
{
    int cnt=0;
    while(a)
        a/=10,cnt++;
    return cnt;
}

ll solve(ll a)
{
    int d=getFirstDigit(a);
    int n=digitCount(a);
    ll res=(d-1)*power(10,max(0,n-2));
    while(a%10!=d)
        a--;
    if(digitCount(a)!=n||getFirstDigit(a)!=d)
        return res;
    ll v=1;
    a/=10;
    for(int i=0;i<n-2;i++)
        res+=v*(a%10),a/=10,v*=10;
    return res+1;
}

ll value[20];

int brute(int a)
{
    int res=0;
    for(int i=1;i<=a;i++)
    {
        if(getFirstDigit(i)==i%10)
            res++;
    }
    return res;
}

ll query(ll a)
{
    if(a<=1000)
        return brute(a);
    int n=digitCount(a);
    return solve(a)+value[n-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    value[1]=9;
    for(int i=2;i<=18;i++)
    {
        value[i]=9*power(10,max(0,i-2));
        value[i]+=value[i-1];
    }
    ll l,r;
    cin>>l>>r;
    ll rvalue=query(r),lvalue=query(l-1);
    cout<<rvalue-lvalue<<endl;
    return 0;
}
