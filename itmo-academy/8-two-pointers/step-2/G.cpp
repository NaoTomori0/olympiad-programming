// G. Взаимно простой отрезок
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// Дан массив из n чисел a_i. Скажем, что отрезок этого массива a[l..r] (1 ≤ l ≤ r ≤ n)
// хороший, если на этом отрезке НОД всех чисел равен 1. Ваша задача — найти самый
// короткий хороший отрезок.

// Входные данные
// Первая строка содержит целое число n (1 ≤ n ≤ 10^5). Вторая строка содержит числа
// a_i (1 ≤ a_i ≤ 10^18).

// Выходные данные
// Выведите одно число — минимальную длину хорошего отрезка. Если хорошего отрезка
// не существует, выведите −1.

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 5
// 4 6 9 3 6
// ======================================================================
// Выходные данные
// ======================================================================
// 3
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long // Защита от переполнения int

int HOD(int x, int y)
{

    while (x > 0 && y > 0)
    {
        if (x > y)
            x %= y;
        else
            y %= x;
    }
    return x + y;
}

struct mystack
{
    vector<int> s, snod;

    void push(int x)
    {
        s.push_back(x);
        snod.push_back(HOD(x, snod.empty() ? x : snod.back()));
    }

    int pop()
    {
        int ret_val = s.back();
        s.pop_back();
        snod.pop_back();
        return ret_val;
    }

    bool empty()
    {
        return s.empty();
    }

    int get_cur_nod()
    {
        return snod.empty() ? 0 : snod.back();
    }
};

mystack s1, s2;

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

bool good()
{
    return HOD(s1.get_cur_nod(), s2.get_cur_nod()) == 1;
}

void solve()
{
    int n, l = 0;
    cin >> n;
    vector<int> a(n);

    int res = n + 1;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int r = 0; r < n; r++)
    {
        add(a[r]);
        while (good())
        {
            res = min(res, r - l + 1);
            remove();
            l++;
        };
    }
    if (res == n + 1)
        cout << -1;
    else
        cout << res;
}

int32_t main()
{
    // Включаем супер-быстрый ввод-вывод для C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
