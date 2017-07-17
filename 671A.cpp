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
#define pii pair<double,int>
#define all(c) c.begin(),c.end()
#define ms(a,c) memset(a,c,sizeof(a))
#define tr(c,i) for(decltype((c).begin()) i=(c).begin();i!=(c).end();i++)
#define trr(c,i) for(decltype((c).rbegin()) i=(c).rbegin();i!=(c).rend();i++)

using namespace std;

#define N 100001
#define mod 1000000007
#define inf 1e10

typedef long long ll;
typedef unsigned long long ull;

struct point
{
    double x,y;
    point(double x=0,double y=0)
    {
        this->x=x;
        this->y=y;
    }
};
point points[N];

double dis[N];

double sqr(double a)
{
    return a*a;
}

double calDistance(point a,point b)
{
    return sqrt(sqr(b.x-a.x)+sqr(b.y-a.y));
}

double ax,ay,bx,by,rx,ry;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    cin>>ax>>ay>>bx>>by>>rx>>ry;
    point r(rx,ry),a(ax,ay),b(bx,by);
    int n;
    cin>>n;
    double ans=0;
    vector<pair<double,int> > da,db;
    //da.push_back(pii(-inf,-1)),db.push_back(pii(-inf,-1));
    for(int i=0;i<n;i++)
    {
        double x,y;
        cin>>x>>y;
        points[i]=point(x,y);
        dis[i]=calDistance(points[i],r);
        ans+=dis[i]*2;
        da.push_back(pii(dis[i]-calDistance(points[i],a),i)),db.push_back(pii(dis[i]-calDistance(points[i],b),i));
    }
    sort(all(da)),sort(all(db));
    double sum1=da.back().first;
    for(int i=n-1;i>=0;i--)
    {
        if(db[i].second!=da.back().second)
        {
            sum1=max(sum1,sum1+db[i].first);
            break;
        }
    }
    double sum2=db.back().first;
    for(int i=n-1;i>=0;i--)
    {
        if(da[i].second!=db.back().second)
        {
            sum2=max(sum2,sum2+da[i].first);
            break;
        }
    }
    cout<<fixed<<setprecision(8)<<ans-max(sum1,sum2)<<endl;
    return 0;
}
