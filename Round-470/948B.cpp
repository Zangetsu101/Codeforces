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

#define N 1000001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

bool notPrime[N];
vi primes;

void sieve()
{
	primes.push_back(2);
	for(int i=3;i<=N;i+=2)
	{
		notPrime[i-1]=true;
		if(!notPrime[i])
		{
			primes.push_back(i);
			if(i<=sqrt(N))
			{
				for(int j=i*i;j<=N;j+=2*i)
					notPrime[j]=true;
			}
		}
	}
	notPrime[2]=false;
}

int findLargest(int x)
{
	priority_queue<int> q;
	q.push(x);
	int temp;
	while(notPrime[temp=q.top()])
	{
		q.pop();
		int i=0;
		while(temp%primes[i])
			i++;
		q.push(primes[i]);
		q.push(temp/primes[i]);
	}
	return temp;
}

int ans;

void func(int a)
{
	if(!notPrime[a])
	{
		ans=min(ans,a);
		return;
	}
	int x=findLargest(a);
	int t=a/x;
	t--;
	ans=min(ans,t*x+1);
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	sieve();
	int x;
	cin>>x;
	ans=x;
	int t=findLargest(x);
	int a=x/t;
	a--;
	for(int i=a*t+1;i<x;i++)
		func(i);
	cout<<ans<<endl;
	return 0;
}
