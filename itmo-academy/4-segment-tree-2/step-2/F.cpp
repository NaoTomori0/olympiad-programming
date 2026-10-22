// F. Присваивание и сумма
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// Есть массив из n элементов, изначально заполненный нулями. Вам нужно написать
// структуру данных, которая обрабатывает два вида запросов:

// - присвоить всем элементам на отрезке от l до r−1 значение v;
// - узнать сумму на отрезке от l до r−1.

// Входные данные
// Первая строка содержит два числа n и m (1 ≤ n, m ≤ 100000) — размер массива
// и число операций. Далее следует описание операций. Описание каждой операции
// имеет следующий вид:

// 1 l r v — присвоить всем элементам на отрезке от l до r−1 значение v
// (0 ≤ l < r ≤ n, 0 ≤ v ≤ 10^9).
// 2 l r — узнать сумму на отрезке от l до r−1 (0 ≤ l < r ≤ n).

// Выходные данные
// Для каждой операции второго типа выведите соответствующее значение.

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 5 6
// 1 0 3 3
// 2 1 2
// 1 2 4 4
// 2 1 3
// 2 1 4
// 2 3 5
// ======================================================================
// Выходные данные
// ======================================================================
// 3
// 7
// 11
// 4
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()

struct SegTree
{
public:
    SegTree(int n)
    {
        while (size < n)
            size <<= 1;
        tree.assign(2 * size - 1, {0, NO_OPERATION});
    }

    int get(int l, int r) { return get(l, r, 0, 0, size); }

    void modify(int l, int r, int v) { modify(l, r, v, 0, 0, size); }

private:
    struct Node
    {
        int val, mod;
    };
    vector<Node> tree;
    int size = 1;
    const int NO_OPERATION = 1e18;

    void propogate(int x, int lx, int rx)
    {
        if (rx - lx == 1 || tree[x].mod == NO_OPERATION)
            return;
        int m = (lx + rx) / 2;
        tree[2 * x + 1].val = (m - lx) * tree[x].mod;
        tree[2 * x + 1].mod = tree[x].mod;
        tree[2 * x + 2].val = (rx - m) * tree[x].mod;
        tree[2 * x + 2].mod = tree[x].mod;
        tree[x].mod = NO_OPERATION;
    }

    int get(int l, int r, int x, int lx, int rx)
    {
        propogate(x, lx, rx);
        if (rx <= l || lx >= r)
            return 0;
        if (rx <= r && lx >= l)
            return tree[x].val;
        int m = (lx + rx) / 2;
        int ml = get(l, r, 2 * x + 1, lx, m), mr = get(l, r, 2 * x + 2, m, rx);
        return ml + mr;
    }

    void modify(int l, int r, int v, int x, int lx, int rx)
    {
        if (rx <= l || lx >= r)
            return;
        if (rx <= r && lx >= l)
        {
            tree[x].mod = v;
            tree[x].val = v * (rx - lx);
            return;
        }
        propogate(x, lx, rx);
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        tree[x].val = tree[2 * x + 1].val + tree[2 * x + 2].val;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    SegTree st(n);
    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            int v;
            cin >> v;
            st.modify(l, r, v);
        }
        else
            cout << st.get(l, r) << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
