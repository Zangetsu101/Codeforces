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

#define N 10010
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

struct trie
{
    trie* next[26];
    bool flag;
    trie()
    {
        for(int i=0;i<26;i++)
            next[i]=0;
        flag=false;
    }
}*root;

void addWord(string str,int n)
{
    trie *crawl=root;
    for(int i=0;i<n;i++)
    {
        if(!crawl->next[str[i]-'a'])
            crawl->next[str[i]-'a']=new trie;
        crawl=crawl->next[str[i]-'a'];
    }
    crawl->flag=true;
}

vector<string> ans;
string t;

void buildTree(trie* node)
{
    if(node->flag)
        ans.push_back(t);
    for(int i=0;i<26;i++)
    {
        if(node->next[i])
        {
            t.push_back('a'+i);
            buildTree(node->next[i]);
            t.pop_back();
        }
    }
}

bool dp[N][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    root=new trie;
    string str;
    cin>>str;
    int n=str.size();
    if(n<7)
    {
        cout<<0<<endl;
        return 0;
    }
    dp[n][0]=dp[n][1]=true;
    for(int i=n-2;i>4;i--)
    {
        if(i+2<=n)
        {
            if(dp[i+2][1])
                dp[i][0]=true;
            else if(dp[i+2][0])
            {
                bool flag=false;
                for(int j=0;j<2;j++)
                {
                    if(str[i+j]!=str[i+2+j])
                        flag=true;
                }
                dp[i][0]=flag;
            }
        }
        if(i+3<=n)
        {
            if(dp[i+3][0])
                dp[i][1]=true;
            else if(dp[i+3][1])
            {
                bool flag=false;
                for(int j=0;j<3;j++)
                {
                    if(str[i+j]!=str[i+3+j])
                        flag=true;
                }
                dp[i][1]=flag;
            }
        }
        if(dp[i][0])
            addWord(str.substr(i,2),2);
        if(dp[i][1])
            addWord(str.substr(i,3),3);
    }
    buildTree(root);
    cout<<ans.size()<<endl;
    tr(ans,it)
        cout<<*it<<endl;
    return 0;
}
