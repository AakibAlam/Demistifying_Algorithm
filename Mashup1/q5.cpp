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

const int MAXN = 100005;
const int mod = 1000000007;

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

int exp(int a, int b)
{
    a %= mod;
    int res = 1;
    while (b)
    {
        if (b % 2)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
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
        int n;
        cin >> n;
        vi v(n);
        map<int, int> p;
        ffor(i, 0, n)
        {
            cin >> v[i];
            p[v[i]]++;
        }
        int x = 1, res = 1, temp, flag = 0;
        for (auto i : p)
        {
            if (!flag && ((i.ss) & 1))
            {
                x = x * ((1 + i.ss) / 2) % (mod - 1);
                flag = 1;
                continue;
            }
            x = x * (1 + i.ss) % (mod - 1);
        }
        for (auto i : p)
        {
            if (flag)
            {
                temp = (i.ss * x) % (mod - 1);
                res = (res * exp(i.ff, temp)) % mod;
            }
            else
            {
                temp = ((i.ss) / 2 * x) % (mod - 1);
                res = (res * exp(i.ff, temp)) % mod;
            }
        }
        cout << res << "\n";
    }
    return 0;
}