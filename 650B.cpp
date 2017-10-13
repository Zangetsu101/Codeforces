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

#define N 500001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

ll a,b;
char orien[N];
int n;

bool possible(ll m,ll t)
{
    ll cnt=0;
    for(int i=1;i<=m;i++)
    {
        if(orien[i]=='w')
            cnt++;
    }
    ll ans=(m-1)*a+cnt*b+m;
    ll i=n,j=m;
    ll d=1;
    while(j!=1)
    {
        if(orien[j]=='w')
            cnt--;
        if(orien[i]=='w')
            cnt++;
        i--,j--;
        ans=min(ans,(2*min(d,j-1)+max(d,j-1))*a+cnt*b+m);
        d++;
    }
    return ans<=t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    ll t;
    cin>>n>>a>>b>>t;
    cin>>&orien[1];
    int low=0,high=n,mid;
    while(high>low)
    {
        mid=(low+high+1)>>1;
        if(possible(mid,t))
            low=mid;
        else
            high=mid-1;
    }
    cout<<low<<endl;
    return 0;
}
