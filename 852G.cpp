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

struct trie
{
    int value;
    trie* next[5];
    bool isVisited;
    trie()
    {
        value=0;
        for(int i=0;i<5;i++)
            next[i]=nullptr;
        isVisited=false;
    }
}*head;

string pat;
int l;
trie *pointers[300];
int k;

int getCount(trie *crawl,int at)
{
    if(!crawl)
        return 0;
    if(at==l)
    {
        if(!crawl->isVisited)
        {
            crawl->isVisited=true;
            pointers[k++]=crawl;
            return crawl->value;
        }
        return 0;
    }
    int res=0;
    if(pat[at]=='?')
    {
        for(int i=0;i<5;i++)
            res+=getCount(crawl->next[i],at+1);
        res+=getCount(crawl,at+1);
        return res;
    }
    return getCount(crawl->next[pat[at]-'a'],at+1);
}

void addWord(string &str)
{
    trie* crawl=head;
    tr(str,it)
    {
        if(!crawl->next[*it-'a'])
            crawl->next[*it-'a']=new trie;
        crawl=crawl->next[*it-'a'];
    }
    crawl->value++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    head=new trie;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        addWord(str);
    }
    for(int i=0;i<m;i++)
    {
        k=0;
        cin>>pat;
        l=pat.size();
        cout<<getCount(head,0)<<endl;
        for(int j=0;j<k;j++)
            pointers[j]->isVisited=false;
    }
    return 0;
}
