struct FT {
    vector<ll> s;
    FT(ll n) : s(n) {}
    void update(ll pos, ll dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    void range_update(ll l,ll r,ll val)
    {
        update(l,val);
        update(r+1,-val);
    }
    ll query(ll pos) 
    { // sum of values in [0, pos]
        pos++;
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
            return res;
    }
    ll lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
        // Returns n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0) return -1;
        ll pos = 0;
        for (ll pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
                pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};
