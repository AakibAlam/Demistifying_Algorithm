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

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case #" t ": ";
        int n;
        cin >> n;
        vi deg(n + 1);
        vvi adj(n + 1);
        bool flag = true;
        int x = 0, y = 0, z = 1;
        map<pii, int> p;
        ffor(i, 1, n)
        {
            int u, v;
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
            adj[u].pb(v);
            adj[v].pb(u);
            p[{u, v}] = p[{v, u}] = i;
        }
        ffor(i, 1, n + 1)
        {
            if (deg[i] > 2)
            {
                flag = false;
                break;
            }
            if (deg[i] == 1)
                x = i;
        }
        if (!flag)
        {
            cout << "-1\n";
            continue;
        }
        vi res(n);
        ffor(i, 1, n)
        {
            for (auto j : adj[x])
            {
                if (j == y)
                    continue;
                if (i & 1)
                    res[p[{x, j}]] = 2;
                else
                    res[p[{x, j}]] = 3;
                // cout << x << " " << j << " " << p[{x, j}] << "--\n";
                y = x, x = j;
                break;
            }
        }
        ffor(i, 1, n)
                cout
            << res[i] << " ";
        cout << "\n";
    }
    return 0;
}