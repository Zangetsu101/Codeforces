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
#include <bitset>

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
	trie* next[2]={0,0};
	int cnt=0;
}*root;

void add(int x)
{
	trie* crawl=root;
	for(int i=0;i<32;i++)
	{
		crawl->cnt++;
		if(!crawl->next[(x>>(31-i))&1])
			crawl->next[(x>>(31-i))&1]=new trie;
		crawl=crawl->next[(x>>(31-i))&1];
	}
	crawl->cnt++;
}

void remove(int x)
{
	trie* crawl=root;
	for(int i=0;i<32;i++)
	{
		crawl->cnt--;
		crawl=crawl->next[(x>>(31-i))&1];
	}
	crawl->cnt--;
}

int find(int x)
{
	int ans=0;
	trie* crawl=root;
	for(int i=0;i<32;i++)
	{
		if(crawl->next[(x>>(31-i))&1]&&crawl->next[(x>>(31-i))&1]->cnt)
		{
			ans|=(x&(1<<(31-i)));
			crawl=crawl->next[(x>>(31-i))&1];
		}
		else
		{
			ans|=(1<<(31-i));
			ans^=(x&(1<<(31-i)));
			crawl=crawl->next[((x>>(31-i))^1)&1];
		}
	}
	return ans;
}

int a[N],p[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	int n;
	root=new trie;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>p[i],add(p[i]);
	for(int i=0;i<n;i++)
	{
		int temp=find(a[i]);
		cout<<(temp^a[i])<<' ';
		remove(temp);
	}
	return 0;
}
