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
#define pii pair<ll,ll>
#define all(c) c.begin(),c.end()
#define ms(a,c) memset(a,c,sizeof(a))
#define tr(c,i) for(decltype((c).begin()) i=(c).begin();i!=(c).end();i++)
#define trr(c,i) for(decltype((c).rbegin()) i=(c).rbegin();i!=(c).rend();i++)

using namespace std;

#define N 1001
#define mod 1000000007
#define inf 1e13

typedef long long ll;
typedef unsigned long long ull;

struct point
{
    ll x,y;
};

ll gcd(ll a,ll b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

pii dhal(point a,point b)
{
    ll dx=a.x-b.x;
    ll dy=a.y-b.y;
    ll g=gcd(dx,dy);
    dx/=g,dy/=g;
    return pii(dx,dy);
}

pii func(vector<point> v)
{
    pii d=dhal(v[0],v[1]);
    for(int i=2;i<v.size();i++)
    {
        if(dhal(v[i],v[0])!=d)
            return pii(inf,inf);
    }
    return d;
}

point data[N];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll y;
        cin>>y;
        data[i].x=i+1;
        data[i].y=y;
    }
    for(int i=1;i<n;i++)
    {
        pii d=dhal(data[0],data[i]);
        vector<point> v;
        for(int j=1;j<n;j++)
        {
            if(dhal(data[0],data[j])!=d)
                v.push_back(data[j]);
        }
        if(v.size()==1)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
        pii d2;
        if(v.size()>1)
            d2=func(v);
        if(d2==d)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    vector<point> v;
    for(int i=1;i<n;i++)
        v.push_back(data[i]);
    pii temp=func(v);
    if(temp!=pii(inf,inf)&&temp!=dhal(data[0],data[1]))
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
    return 0;
}
