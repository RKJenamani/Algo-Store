#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define lf long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair <ll,ll> ii;
typedef vector <ll> vi;
typedef vector <ii> vii;
typedef vector <bool> vb;
typedef vector <vector <ll> > vv;
typedef vector <string> vs;
typedef vector <lf> vf;
#define tr1(x) cerr << #x << ": " << x << endl
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl
#define tr3(x,y,z) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define mod 1000000007
#define inf 9999999999999999ll
ll fun(vi &items,vi &price,ll money)//returns money left & updates items.
{
    for(ll i=4;i>=0;i--)
    {
        items[i]+=money/price[i];
        money-=money/price[i] * price[i];
    }
    return money;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vi price(5,0);
    ll n;
    cin>>n;
    vi a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    for(ll i=0;i<5;i++)
        cin>>price[i];
    ll money=0;
    vi item(5,0);
    for(ll i=0;i<n;i++)
    {
        money+=a[i];
        money=fun(item,price,money);
    }
    for(ll i=0;i<5;i++)
    {
        cout<<item[i]<<" ";
    }
    cout<<"\n"<<money<<"\n";
}
