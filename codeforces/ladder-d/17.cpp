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
    string s;
    cin>>s;
    /*vi odda,oddb,evena,evenb;
    for(ll i=0;i<s.size();i++)
    {
        if(s[i]=='a')
        {
            if(i%2)
                odda.pb(i);
            else
                evena.pb(i);
        }
        else
        {
            if(i%2)
                oddb.pb(i);
            else
                evenb.pb(i);
        }
    }*/
    ll n=s.size();
    ll odd=0,even=0;
    ll a[n][4];//odda,evena,oddb,evenb;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<4;j++)
            a[i][j]=0;
    }
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='a')
        {
            if(i%2)
            {
                a[i][0]=1;
            }
            else
            {
                a[i][1]=1;
            }
        }
        else
        {
            if(i%2)
                a[i][2]=1;
            else
                a[i][3]=1;
        }
    }
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<4;j++)
        {
            a[i][j]+=a[i-1][j];
        }
    }
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='a')
        {
            if(i%2)//finish at odda
            {
                odd+=a[i][0];
                even+=a[i][1];
            }
            else//finish at evena
            {
                odd+=a[i][1];
                even+=a[i][0];
            }
        }
        else
        {
            if(i%2)
            {
                odd+=a[i][2];
                even+=a[i][3];
            }
            else//finish at evenb;
            {
                odd+=a[i][3];
                even+=a[i][2];
            }
        }
    }
    cout<<even<<" "<<odd<<"\n";
}
