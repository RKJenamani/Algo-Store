#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector <int> vi;
typedef pair <ll, ll> ii;
typedef vector <ii> vii;
typedef vector <string> vs;
#define mod 1000000007
#define pb push_back
#define mp make_pair
using namespace std;

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void build(ll tree[],ll a[], ll v, ll tl, ll tr) //O(n)
{
	
	if(tl==tr)
		tree[v] = a[tl];
	else
	{
		ll tm=(tl+tr)/2;
		build(tree,a,2*v,tl,tm);
		build(tree,a,2*v+1,tm+1,tr);
		tree[v]=tree[2*v]+tree[2*v+1];
	}
}

ll query(ll tree[],ll v,ll tl,ll tr, ll l, ll r) //O(logn)
{
	if (l>r)
		return 0;
	if(l==tl && r==tr)
		return tree[v];
	else
	{
		ll tm=(tl+tr)/2;
		return query(tree,2*v,tl,tm,l,min(r,tm))+query(tree,2*v+1,tm+1,tr,max(l,tm+1),r);
	}
}
void update(ll tree[], ll v, ll tl, ll tr, ll pos, ll new_val) //O(logn)
{
	if(tl==tr)
		tree[v]=new_val;
	else
	{
		ll tm =(tl+tr)/2;
		if(pos<=tm)
			update(tree,v*2,tl,tm,pos,new_val);
		else
			update(tree,v*2+1,tm+1,tr,pos,new_val);
		tree[v] = tree[v*2] + tree[v*2+1];
	}
}
int main()
{
	ll MAXN=100,l,r,m,value;
	cout<<"Input array size: ";
	cin>>MAXN;
	ll tree[4*MAXN+1];
	ll a[MAXN];
	cout<<"Size: "<<MAXN<<endl;
	cout<<"Input Elements: ";
	for(ll i=0;i<MAXN;i++)
		cin>>a[i];
	build(tree,a,1,0,MAXN-1);
	cout<<endl;
	cout<<"Enter index to search between: ";
	cin>>l>>r;
	cout<<query(tree,1,0,MAXN-1,l,r)<<endl;
	cout<<"Enter index of element you want to update: ";
	cin>>m;
	cout<<"Input value: ";
	cin>>value;
	a[m]=value;
	update(tree,1,0,MAXN-1,m,value);
	cout<<endl;
	cout<<"Enter index to search between: ";
	cin>>l>>r;
	cout<<query(tree,1,0,MAXN-1,l,r)<<endl;
	return 0;
}