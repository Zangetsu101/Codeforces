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
    trie *next[26];
    trie()
    {
        for(int i=0;i<26;i++)
            next[i]=0;
    }
}*root;

void addWord(string str)
{
    int n=str.size();
    trie *crawl=root;
    for(int i=0;i<n;i++)
    {
        if(!crawl->next[str[i]-'a'])
            crawl->next[str[i]-'a']=new trie;
        crawl=crawl->next[str[i]-'a'];
    }
}

pair<int,int> dfs(trie* node)
{
    pii res(-1,1);
    int cnt=0,lcnt=0;
    for(int i=0;i<26;i++)
    {
        if(node->next[i])
        {
            cnt++;
            pii temp=dfs(node->next[i]);
            if(temp.first==-1)
                res.first=1;
            if(temp.second==1)
                lcnt++;
        }
    }
    if(cnt&&cnt==lcnt)
        res.second=-1;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    root=new trie;
    int n,k;
    cin>>n>>k;
    string str;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        addWord(str);
    }
    pii res=dfs(root);
    bool win=false,loose=false;
    if(res.first==1)
        win=true;
    if(res.second==1)
        loose=true;
    if((win&&loose)||(win&&(k%2)))
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
    return 0;
}
