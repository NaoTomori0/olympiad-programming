// C. Присваивание к отрезку
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// Есть массив из n элементов, изначально заполненный нулями. Вам нужно написать
// структуру данных, которая обрабатывает два вида запросов:

// - присвоить всем элементам на отрезке от l до r−1 значение v;
// - узнать текущее значение в ячейке i.

// Входные данные
// Первая строка содержит два числа n и m (1 ≤ n, m ≤ 100000) — размер массива
// и число операций. Далее следует описание операций. Описание каждой операции
// имеет следующий вид:

// 1 l r v — присвоить всем элементам на отрезке от l до r−1 значение v
// (0 ≤ l < r ≤ n, 0 ≤ v ≤ 10^9).
// 2 i — найти значение в ячейке с индексом i (0 ≤ i < n).

// Выходные данные
// Для каждой операции второго типа выведите соответствующее значение.

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 5 5
// 1 0 3 3
// 2 1
// 1 2 4 4
// 2 3
// 2 4
// ======================================================================
// Выходные данные
// ======================================================================
// 3
// 4
// 0
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define forr(i, n) for (int i = 0; i < n; i++)

struct SegTree
{
public:
    SegTree(int n)
    {
        while (size < n)
            size *= 2;
        tree.assign(2 * size - 1, NO_OPERATION);
    }

    void modify(int l, int r, int v) { modify(l, r, v, 0, 0, size); }

    int get(int i)
    {
        int res = get(i, 0, 0, size);
        return (res != NO_OPERATION ? res : 0);
    }

private:
    vector<int> tree;
    int size = 1;
    const int NO_OPERATION = -1e18;

    int get(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
            return tree[x];
        int m = (lx + rx) / 2;
        int res;
        if (i < m)
            res = get(i, 2 * x + 1, lx, m);
        else
            res = get(i, 2 * x + 2, m, rx);
        if (tree[x] != NO_OPERATION)
            return tree[x];
        else
            return res;
    }

    void propagate(int x, int lx, int rx)
    {
        if (tree[x] == NO_OPERATION || rx - lx == 1)
            return;
        tree[2 * x + 1] = tree[x];
        tree[2 * x + 2] = tree[x];
        tree[x] = NO_OPERATION;
    }

    void modify(int l, int r, int v, int x, int lx, int rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
        {
            tree[x] = v;
            return;
        }
        if (rx <= l || lx >= r)
            return;
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    SegTree st(n);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            st.modify(l, r, v);
        }
        else
        {
            int i;
            cin >> i;
            cout << st.get(i) << '\n';
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
