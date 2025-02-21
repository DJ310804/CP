// Code By DJ
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define all(x) x.begin(), x.end()
constexpr int MOD = 1000000007;
constexpr int INF = 0x7fffffffffffffff;

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vpii = vector<pii>;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// order_of_key, find_by_order

template<typename Container>
void printContainer(const Container& container) {
    for (const auto& item : container) {
        cout << item << " ";
    }
    cout << endl;
}

int getMSB(int n) {
    return n == 0 ? 0 : 1 << (31 - __builtin_clz(n));
}

int pow(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) res *= x;
        y >>= 1;
        x *= x;
    }
    return res;
}

int mod_pow(int x, int y, int mod) {
    int res = 1;
    while (y > 0) {
        if (y & 1) res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

int mod_div(int p, int q) {
    return (p % MOD) * mod_pow(q, MOD - 2, MOD) % MOD;
}

vi fact(1, 1);

void precompute_factorials(int n) {
    for (int i = fact.size(); i <= n; ++i) {
        fact.push_back(fact.back() * i % MOD);
    }
}

int ncr(int n, int r) {
    if (r > n) return 0;
    precompute_factorials(n);
    return mod_div(fact[n], fact[n - r] * fact[r] % MOD);
}

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

int comnSuff(int a, int b) {
    for (int i = 0; i < 30; ++i) {
        if ((a & (1 << i)) != (b & (1 << i))) {
            return i;
        }
    }
    return 30;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/
typedef pair<int, int> Interval;
vector<Interval> mergeIntervals(vector<Interval> &intervals)
{
    if (intervals.empty())
        return {};
 
    // Sort intervals by start time
    sort(intervals.begin(), intervals.end());
 
    vector<Interval> result;
    result.push_back(intervals[0]);
 
    for (size_t i = 1; i < intervals.size(); i++)
    {
        auto &last = result.back();
        if (intervals[i].first <= last.second + 1)
        {                                                        // Overlapping or adjacent
            last.second = max(last.second, intervals[i].second); // Merge
        }
        else
        {
            result.push_back(intervals[i]); // Add new interval
        }
    }
 
    return result;
}
vector<Interval> intervalIntersection(vector<Interval> &set1, vector<Interval> &set2)
{
    vector<Interval> result;
    int i = 0, j = 0;
    sort(all(set1));
    sort(all(set2));
    while (i < set1.size() && j < set2.size())
    {
        int start = max(set1[i].first, set2[j].first);
        int end = min(set1[i].second, set2[j].second);
 
        if (start <= end)
        {
            result.push_back({start, end});
        }
        if (set1[i].second < set2[j].second)
            i++;
        else
            j++;
    }
    return result;
}
vector<Interval> valid_range(int prev, int curr)
{
    // prev ^ x >= curr
    vector<Interval> result;
    int value = 0;
    for (int i = 30 - 1; i >= 0; i--)
    {
        int currb = 0;
        int prevb = 0;
        if (curr & (1ll << i))
        {
            currb = 1;
        }
        if (prev & (1ll << i))
        {
            prevb = 1;
        }
        if (currb)
        {
            value = value | ((1 - prevb) * (1ll << i));
        }
        else
        {
            int lb = value | ((1 - prevb) * (1ll << i));
            int rb = lb;
            for (int j = i - 1; j >= 0; j--)
            {
                rb |= (1ll << j);
            }
            result.push_back({lb, rb});
            value = value | ((prevb) * (1ll << i));
        }
    }
    result.push_back({value, value});
    return result;
}
bool isPresentInIntervals(const vector<Interval> &intervals, int x)
{
    int left = 0, right = intervals.size() - 1;
 
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
 
        if (intervals[mid].first <= x && x <= intervals[mid].second)
        {
            return true; // x is inside the interval
        }
        else if (intervals[mid].second < x)
        {
            left = mid + 1; // Search in the right half
        }
        else
        {
            right = mid - 1; // Search in the left half
        }
    }
 
    return false; // x is not in any interval
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vi v(n);
    for(auto &a:v)cin>>a;
    reverse(all(v));
    int prev = 0;
    vector<Interval> full = {{0, (1ll << 30) - 1}};
    vector<vector<Interval>> possible(n);
    for (int i = 0; i < n; i++)
    {
        vector<Interval> vv = valid_range(prev, v[i]);
        vector<Interval> ii = mergeIntervals(vv);
        ii = intervalIntersection(ii, full);
        full = ii;
        possible[i] = ii;
        prev ^= v[i];
    }
    auto check = [&](int d, int x)
    {
        return isPresentInIntervals(possible[d], x);
    };
    while (q--)
    {
        int x;
        cin >> x;
        int lo = 0, hi = n, ans = n;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (mid == n)
            {
                break;
            }
            if (check(mid, x))
            {
                lo = mid + 1;
            }
            else
            {
                ans = mid;
                hi = mid - 1;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
}

signed main() {
    // cout << fixed << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}