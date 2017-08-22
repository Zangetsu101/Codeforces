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

const int sz=31;

struct node
{
    int value;
    node* next[2];
    node()
    {
        value=0;
        next[0]=next[1]=0;
    }
}*root;

void add(int v)
{
    node* crawl=root;
    for(int i=0;i<sz+1;i++)
    {
        int f=(v>>(sz-i))&1;
        if(!crawl->next[f])
            crawl->next[f]=new node;
        crawl=crawl->next[f],crawl->value++;
    }
}

void rem(int v)
{
    node* crawl=root;
    for(int i=0;i<sz+1;i++)
    {
        int f=(v>>(sz-i))&1;
        crawl=crawl->next[f];
        if(!crawl)
            break;
        crawl->value--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    cin>>n;
    root=new node;
    for(int i=0;i<n;i++)
    {
        int t,p,l;
        cin>>t>>p;
        if(t==1)
            add(p);
        else if(t==2)
            rem(p);
        else
        {
            cin>>l;
            node* crawl=root;
            int ans=0;
            for(int j=0;j<sz+1;j++)
            {
                int f=(l>>(sz-j))&1;
                int m=(p>>(sz-j))&1;
                if(f)
                {
                    if(crawl->next[m])
                        ans+=crawl->next[m]->value;
                    crawl=crawl->next[!m];
                }
                else
                    crawl=crawl->next[m];
                if(!crawl)
                    break;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
