#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 20000005;

vector<bool> prm(MAXN);
vector<int> prime, cnt(MAXN), res(MAXN);

int32_t main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        cnt[v[i]]++;
    }

    for (int i = 2; i < MAXN; i++)
    {
        if (!prm[i])
        {
            prime.push_back(i);
            for (int j = i * i; j < MAXN; j += i)
                prm[j] = true;
        }
    }

    for (int i = 2; i < MAXN; i++)
    {
        if (!prm[i])
        {
            for (int j = MAXN / i; j > 0; j--)
                cnt[j] += cnt[j * i];
        }
    }

    for (int i = MAXN - 1; i > 0; i--)
    {
        res[i] = cnt[i] * i;
        for (auto j : prime)
        {
            if (i * j >= MAXN)
                break;
            res[i] = max(res[i], res[i * j] + (cnt[i] - cnt[i * j]) * i);
        }
    }

    cout << res[1] << "\n";

    return 0;
}