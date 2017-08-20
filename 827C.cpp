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

int** value[4*N][11];
string str;

int mp(char ch)
{
    switch(ch)
    {
    case 'A':
        return 0;
    case 'C':
        return 1;
    case 'G':
        return 2;
    default:
        return 3;
    }
}

void build(int node,int l,int r)
{
    int mid=(l+r)>>1;
    for(int i=1;i<11;i++)
        value[node][i]=new int*[i];
    for(int i=1;i<11;i++)
    {
        for(int j=0;j<i;j++)
        {
            value[node][i][j]=new int[4];
            for(int k=0;k<4;k++)
                value[node][i][j][k]=0;
        }
    }
    if(l==r)
    {
        for(int i=1;i<11;i++)
            value[node][i][0][mp(str[l])]++;
        return;
    }
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    int pos;
    for(int i=l;i<=r;i++)
    {
        pos=i-l;
        for(int j=1;j<11;j++)
            value[node][j][pos%j][mp(str[i])]++;
    }
}

void update(int node,int l,int r,int pos,int idx,bool flag)
{
    int mid=(l+r)>>1;
    if(pos>r||pos<l)
        return;
    for(int i=1;i<11;i++)
    {
        if(flag)
            value[node][i][(pos-l)%i][idx]++;
        else
            value[node][i][(pos-l)%i][idx]--;
    }
    if(l==r)
        return;
    update(node*2,l,mid,pos,idx,flag);
    update(node*2+1,mid+1,r,pos,idx,flag);
}

int query(int node,int l,int r,int i,int j,string &s,int len)
{
    if(i>r||j<l)
        return 0;
    if(i<=l&&j>=r)
    {
        int pos=(l-i)%len;
        string temp;
        for(int k=0;k<len;k++)
            temp.push_back(s[pos]),pos=(pos+1)%len;
        int ans=0;
        for(int k=0;k<min(len,r-l+1);k++)
            ans+=value[node][len][k][mp(temp[k])];
        return ans;
    }
    int mid=(l+r)>>1;
    return query(node*2,l,mid,i,j,s,len)+query(node*2+1,mid+1,r,i,j,s,len);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    cin>>str;
    int n=str.size();
    build(1,0,n-1);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int t,a,b;
        cin>>t>>a;
        if(t==1)
        {
            a--;
            char ch;
            cin>>ch;
            update(1,0,n-1,a,mp(str[a]),false);
            update(1,0,n-1,a,mp(ch),true);
            str[a]=ch;
        }
        else
        {
            cin>>b;
            string s;
            cin>>s;
            cout<<query(1,0,n-1,--a,--b,s,s.size())<<endl;
        }
    }
    return 0;
}
