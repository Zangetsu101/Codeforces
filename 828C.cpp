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

//#define endl "\n"
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

#define N 2000001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

bool flag[4*N];
char ans[N];

void update(int node,int l,int r,int i,int j,string &s)
{
    int mid=(l+r)>>1;
    if(i>r||j<l||flag[node])
        return;
    if(i<=l&&j>=r)
    {
        for(int k=0;k<r-l+1;k++)
            ans[l+k]=s[l-i+k];
        flag[node]=true;
        return;
    }
    update(node*2,l,mid,i,j,s);
    update(node*2+1,mid+1,r,i,j,s);
    flag[node]=flag[node*2]&&flag[node*2+1];
}

struct node
{
    string s;
    int l;
    vi v;
};
node data[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    cin>>n;
    int sz=0;
    for(int i=0;i<n;i++)
    {
        cin>>data[i].s;
        int k;
        cin>>k;
        data[i].l=data[i].s.size();
        for(int j=0;j<k;j++)
        {
            int temp;
            cin>>temp;
            data[i].v.push_back(temp-1);
            sz=max(sz,temp+data[i].l-1);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<data[i].v.size();j++)
            update(1,0,sz-1,data[i].v[j],data[i].v[j]+data[i].l-1,data[i].s);
    }
    for(int i=0;i<sz;i++)
    {
        if(!ans[i])
            cout<<'a';
        else
            cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
