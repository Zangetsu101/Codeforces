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

#define N 200001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int data[N];
int lmin[N],rmin[N];
int ans[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    vii v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
        v.push_back(pii(data[i],i+1));
    }
    sort(all(v));
    set<int> s;
    set<int>::iterator it;
    for(int i=1;i<=n;i++)
        rmin[i]=n+1;
    for(int i=0;i<n;i++)
    {
        it=s.lower_bound(v[i].second);
        if(it==s.begin())
            lmin[v[i].second]=0;
        else
            it--,lmin[v[i].second]=*it,it++;
        if(it!=s.end())
            rmin[v[i].second]=*it;
        s.insert(v[i].second);
    }
    for(int i=1;i<=n;i++)
        ans[i]=-1;
    for(int i=n-1;i>=0;i--)
    {
        int j=rmin[v[i].second]-lmin[v[i].second]-1;
        while(ans[j]==-1)
            ans[j]=v[i].first,j--;
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}
