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

#define N 300001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

struct trie
{
    int v;
    trie* next[2];
    trie()
    {
        v=0;
        next[0]=next[1]=nullptr;
    }
}*head;

void add(int value)
{
    trie* crawl=head;
    for(int i=0;i<26;i++)
    {
        int f=(value>>25-i)&1;
        if(!crawl->next[f])
            crawl->next[f]=new trie;
        crawl->v++;
        crawl=crawl->next[f];
    }
    crawl->v++;
}

int query(int value)
{
    trie* crawl=head;
    int res=0;
    for(int i=0;i<26;i++)
    {
        int f=(value>>25-i)&1;
        if(!crawl||!crawl->next[f])
            return res;
        if(crawl->next[f]->v<(1<<25-i))
            crawl=crawl->next[f];
        else
            crawl=crawl->next[f^1],res|=1<<25-i;
    }
    return res;
}

bool mp[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    head=new trie;
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(!mp[a])
            add(a);
        mp[a]=true;
    }
    int v=0;
    for(int i=0;i<q;i++)
    {
        int a;
        cin>>a;
        v^=a;
        cout<<query(v)<<endl;
    }
    return 0;
}
