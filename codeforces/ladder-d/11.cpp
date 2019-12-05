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
bool possible(string &s,ll ind)//0....ind is a factor of the string
{
    ll n=s.size();
    if(n%(ind+1)>0)
        return false;
    ll j=0;
    for(ll i=0;i<n;i++,j++)
    {
        j%=(ind+1);
        if(s[i]!=s[j])
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    set <string > f1,f2;
    string a1="";
    for(ll i=0;i<s1.size();i++)
    {
        a1.pb(s1[i]);
        if(possible(s1,i))
        {
            f1.insert(a1);
        }
    }
    string a2="";
    for(ll i=0;i<s2.size();i++)
    {
        a2.pb(s2[i]);
        if(possible(s2,i))
        {
            f2.insert(a2);
        }
    }
    ll ans=0;
    for(auto &i:f1)
    {
        if(f2.find(i)!=f2.end())
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
}
