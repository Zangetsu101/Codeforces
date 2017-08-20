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

int sum[N];
vi reqValues;
int n;

bool isPossible(int value)
{
    map<int,bool> mp;
    for(int i=1;i<=n;i++)
       mp[value+sum[i]]=true;
    for(int i=0;i<reqValues.size();i++)
    {
        if(!mp[reqValues[i]])
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>sum[i],sum[i]+=sum[i-1];
    for(int i=0;i<k;i++)
    {
        int a;
        cin>>a;
        reqValues.push_back(a);
    }
    map<int,bool> mp;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(isPossible(reqValues.front()-sum[i]))
        {
            if(!mp[reqValues.front()-sum[i]])
                ans++,mp[reqValues.front()-sum[i]]=true;
        }
    }
    cout<<ans<<endl;
    return 0;
}
