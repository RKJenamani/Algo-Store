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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vi a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    ll ans=0;
    vi b(2000001,0);
    for(ll i=1;i<a.size();i++)
    {
        for(ll j=a[i];j>a[i-1];j--)
            b[j]=a[i-1];
    }
    for(ll j=a.back()+1;j<=2000000;j++)
    {
        b[j]=a.back();
    }
    for(ll j=0;j<a.size();j++)
    {
        if(j)
        {
            if(a[j]==a[j-1])
                continue;
        }
        ll aj=a[j];
        for(ll i=2*aj;i<=2000000;i+=aj)
        {
            //<i
            ll k=b[i];
            ans=max(ans,k%a[j]);
        }
    }
    cout<<ans<<endl;
}
