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

ll fuel[N];
ll cost[N];
ll arr[N];
int n;

int calc(bool flag)
{
    int i,j;
    for(int k=0;k<n;k++)
    {
        if(arr[k]>=0)
        {
            i=j=k;
            break;
        }
    }
    int f=arr[i];
    if(flag)
    {
        while(true)
        {
            while(f+arr[(j+1)%n]>=0)
            {
                if((j+1)%n==i)
                    return i;
                f+=arr[(j+1)%n],j=(j+1)%n;
            }
            while(f+arr[(j+1)%n]<0)
                f+=arr[(i-1+n)%n],i=(i-1+n)%n;
        }
    }
    else
    {
        while(true)
        {
            while(f+arr[(j-1+n)%n]>=0)
            {
                if((j-1+n)%n==i)
                    return i;
                f+=arr[(j-1+n)%n],j=(j-1+n)%n;
            }
            while(f+arr[(j-1+n)%n]<0)
                f+=arr[(i+1)%n],i=(i+1)%n;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    cin>>n;
    set<int> ans;
    for(int i=0;i<n;i++)
        cin>>fuel[i];
    for(int i=0;i<n;i++)
        cin>>cost[i];
    for(int i=0;i<n;i++)
        arr[i]=fuel[i]-cost[i];
    int idx=calc(true);
    ans.insert(idx+1);
    int at=(idx-1+n)%n;
    ll prev=0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[at]>=prev)
            ans.insert(at+1),prev=0;
        else
            prev=prev-arr[at];
        at=(at-1+n)%n;
    }
    for(int i=0;i<n;i++)
        arr[i]=fuel[i]-cost[(i-1+n)%n];
    idx=calc(false);
    ans.insert(idx+1);
    at=(idx+1)%n;
    prev=0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[at]>=prev)
            ans.insert(at+1),prev=0;
        else
            prev=prev-arr[at];
        at=(at+1)%n;
    }
    cout<<ans.size()<<endl;
    tr(ans,it)
        cout<<*it<<' ';
    cout<<endl;
    return 0;
}
