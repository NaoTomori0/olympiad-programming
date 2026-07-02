// F. Отрезки с небольшим разбросом
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// Дан массив из n чисел a_i. Скажем, что отрезок этого массива a[l..r] (1 ≤ l ≤ r ≤ n)
// хороший, если на этом отрезке разница между максимальным и минимальным элементом
// не больше k. Ваша задача — найти число различных хороших отрезков.

// Входные данные
// Первая строка содержит целые числа n и k (1 ≤ n ≤ 10^5, 0 ≤ k ≤ 10^18). Вторая строка
// содержит числа a_i (1 ≤ a_i ≤ 10^18).

// Выходные данные
// Выведите одно число — число хороших отрезков.

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 7 3
// 2 6 4 3 6 8 9
// ======================================================================
// Выходные данные
// ======================================================================
// 16
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long

const long long INF = 4'000'000'000'000'000'000LL;

struct st
{
    vector<int> s, mins, maxs;

    void push(int x)
    {
        s.push_back(x);
        mins.push_back(mins.empty() ? x : std::min(x, mins.back()));
        maxs.push_back(maxs.empty() ? x : std::max(x, maxs.back()));
    }

    int pop()
    {
        int ret = s.back();
        s.pop_back();
        mins.pop_back();
        maxs.pop_back();
        return ret;
    }

    bool empty()
    {
        return s.empty();
    }

    int min()
    {
        return mins.empty() ? INF : mins.back();
    }

    int max()
    {
        return maxs.empty() ? -INF : maxs.back();
    }
};

st s1, s2;

void add(int x)
{
    s2.push(x);
}

void remove()
{
    if (s1.empty())
        while (!s2.empty())
            s1.push(s2.pop());
    s1.pop();
}

bool good(int k)
{
    int mn = min(s1.min(), s2.min());
    int mx = max(s1.max(), s2.max());
    return mx - mn <= k;
}

void solve()
{
    int n, k, l = 0, res = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int r = 0; r < n; r++)
    {
        add(a[r]);
        while (!good(k))
        {
            remove();
            l++;
        }

        res += r - l + 1;
    }
    cout << res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
