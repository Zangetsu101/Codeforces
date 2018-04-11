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

#define N 150001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

ll data[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    map<ll,int> mp;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>data[i];
    for(int i=1;i<=n;i++)
    {
        int t=mp[data[i]];
        if(t)
            data[t]=0,mp[data[i]]=0,data[i]*=2,i--;
        else
            mp[data[i]]=i;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(data[i])
            cnt++;
    }
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++)
    {
        if(data[i])
            cout<<data[i]<<' ';
    }
    cout<<endl;
    return 0;
}
