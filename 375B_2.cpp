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

vector< vi > v(N);
int mp[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<m;j++)
        {
            char a;
            cin>>a;
            if(a=='1')
                cnt++;
            else
                cnt=0;
            v[j].push_back(cnt);
        }
    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<v[i].size();j++)
            mp[v[i][j]]++;
        int cnt=0;
        for(int j=m;j>0;j--)
        {
            while(mp[j])
            {
                cnt++;
                ans=max(ans,cnt*j);
                mp[j]--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
