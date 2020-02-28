    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    const int N = 2e5 + 87;
    ll n, k, a[N];
    ll c0, cn, cp;
    ll solvene()
    {
        vector<ll> x(a, a + cn);
        vector<ll> y(a + n - cp, a + n);
        ll lo = x[0] * y.back();
        ll hi = x.back() * y[0];
        //cerr << "lo hi "<< lo << ' '<< hi << endl;
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        //cerr << "x= "; for (ll t : x) cerr << t << ' '; cerr << endl;
        //cerr << "y= "; for (ll t : y) cerr << t << ' '; cerr << endl;
        while (lo <= hi) {
            ll mi = lo + (hi - lo) / 2;
            ll c = 0;
            for (ll i = 0, j = 0; i < x.size(); ++i) {
                for (; j < y.size() && x[i] * y[j] <= mi; ++j);
                //cerr << "i,j,x[i] " << i << ' ' << j << ' ' << x[i]<< endl;
                c += j;
            }
            //cerr << "mi, c "<< mi << ' ' << c << endl;
            if (c < k)
                lo = mi + 1;
            else
                hi = mi - 1;
        }
        return lo;
    }
    ll solvenp(ll k)
    {
        vector<ll> x(a, a + cn);
        reverse(x.begin(), x.end());
        vector<ll> y(a + n - cp, a + n);
        ll lo = LLONG_MAX;
        ll hi = LLONG_MIN;
        if (x.size() >= 2) {
            lo = min(lo, x[0] * x[1]);
            hi = max(hi, x[cn - 1] * x[cn - 2]);
        }
        if (y.size() >= 2) {
            lo = min(lo, y[0] * y[1]);
            hi = max(hi, y[cp - 1] * y[cp - 2]);
        }
        while (lo <= hi) {
            ll mi = lo + (hi - lo) / 2;
            ll c = 0;
            for (ll i = cp - 1, j = 0; i >= 0; --i) {
                for (; j < i && y[i] * y[j] <= mi; ++j);
                c += min(j, i);
            }
            for (ll i = cn - 1, j = 0; i >= 0; --i) {
                for (; j < i && x[i] * x[j] <= mi; ++j);
                c += min(j, i);
            }
            //cerr << "mi, c " << mi << ' ' << c << endl;
            if (c < k)
                lo = mi + 1;
            else
                hi = mi - 1;
        }
        return lo;
    }
    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 0)
                ++c0;
            else if (a[i] > 0)
                ++cp;
            else
                ++cn;
        }
        sort(a, a + n);
        ll ne = cn * cp;
        ll n0 = c0 * (c0 - 1) / 2 + c0 * (n - c0);
        ll np = cp * (cp - 1) / 2 + cn * (cn - 1) / 2;

        cout<<"ne "<<ne<<endl;
        cout<<"n0 "<<n0<<endl;
        cout<<"np "<<np<<endl;
        ll ans;
        if (k <= ne) {
            ans = solvene();
        } else if (k <= ne + n0) {
            ans = 0;
        } else {
            ans = solvenp(k - ne - n0);
        }
        cout << ans << "\n";
    }