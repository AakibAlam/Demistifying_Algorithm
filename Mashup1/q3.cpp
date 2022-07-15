#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ff first
#define ss second
#define pb push_back
#define int long long
#define double long double
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vpii vector<pii>
#define pii pair<int, int>
#define Size(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define ffor(i, a, n) for (int i = a; i < n; i++)
#define rfor(i, a, n) for (int i = n - 1; i >= a; i--)
#define pinf 1e18
#define ninf -1e18
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
string yon[] = {"NO", "YES"};
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using muloset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1000005;
const int mod = 1000000007;

vvi factor(MAXN);

template <class T>
void scan(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
        cin >> v[i];
}
template <class T>
void print(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void sieve()
{
    for (int i = 1; i < MAXN; i++)
    {
        for (int j = i; j < MAXN; j += i)
            factor[j].pb(i);
    }
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case #" t ": ";

        sieve();

        int n;
        cin >> n;
        vi v(MAXN), v1(MAXN), v2(MAXN);
        ffor(i, 0, n)
        {
            int x;
            cin >> x;
            v1[x] = 1;
            for (auto j : factor[x])
                v[j]++;
        }
        int cnt = 0;
        for (int i = MAXN - 1; i > 0; i--)
        {
            if (v[i] > v2[i])
            {
                if (!v1[i])
                    cnt++;
                for (auto j : factor[i])
                    v2[j] = max(v2[j], v[i]);
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}