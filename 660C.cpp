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
#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d %d",&a,&b)
#define sfff(a,b,c) scanf("%d %d %d",&a,&b,&c)
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

#define N 300001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

vi v;
int data[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    v.push_back(0);
    int cnt=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>data[i];
        if(data[i])
            cnt++;
        else
            v.push_back(i),cnt=0;
        ans=max(ans,cnt);
    }
    v.push_back(n+1);
    int si=0,ei=0;
    for(int i=1;i<v.size()-1;i++)
    {
        int s,e;
        s=v[i-1]+1;
        if(i+k>=v.size())
            e=n;
        else
            e=v[i+k]-1;
        if(e-s+1>ans)
            ans=e-s+1,si=s,ei=e;
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        if(i>=si&&i<=ei)
            cout<<1<<' ';
        else
            cout<<data[i]<<' ';
    }
    cout<<endl;
    return 0;
}
