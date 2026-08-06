// B. YetnotherrokenKeoard
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест256 мегабайт
// У Поликарпа беда — сломалась клавиатура на его ноутбуке.

// Теперь, когда он нажимает клавишу 'b', она отрабатывает подобно необычному backspace: происходит удаление последней (самой правой) строчной буквы в набранной строке. Если в набранной строке нет ни одной строчной буквы, то нажатие полностью игнорируется.

// Аналогично, когда он нажимает клавишу 'B', то происходит удаление последней (самой правой) прописной буквы в набранной строке. Если в набранной строке нет ни одной прописной буквы, то нажатие полностью игнорируется.

// В обоих случаях буквы 'b' и/или 'B' при нажатии на эти клавиши не добавляются в набранную строку.

// Рассмотрим пример. Пусть последовательность нажатий имела вид «ARaBbbitBaby». В этом случае набранная строка будет изменяться следующим образом: «» →A
//  «A» →R
//  «AR» →a
//  «ARa» →B
//  «Aa» →b
//  «A» →b
//  «A» →i
//  «Ai» →t
//  «Ait» →B
//  «it» →a
//  «ita» →b
//  «it» →y
//  «ity».

// По заданной последовательности нажатых клавиш выведите набранную строку после обработки всех нажатий.

// Входные данные
// В первой строке входных данных содержится целое число t
//  (1≤t≤1000
// ) — количество наборов входных данных в тесте.

// Далее содержится t
//  непустых строк, которые состоят из строчных и прописных букв латинского алфавита.

// Гарантируется, что каждая строка содержит хотя бы одну букву и сумма длин строк не превосходит 106
// .

// Выходные данные
// Для каждого набора входных данных выведите результат обработки нажатий в отдельной строке. Если набранная строка пустая, то выведите пустую строку.

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 12
// ARaBbbitBaby
// YetAnotherBrokenKeyboard
// Bubble
// Improbable
// abbreviable
// BbBB
// BusyasaBeeinaBedofBloomingBlossoms
// CoDEBARbIES
// codeforces
// bobebobbes
// b
// TheBBlackbboard
// ======================================================================
// Выходные данные
// ======================================================================
// ity
// YetnotherrokenKeoard
// le
// Imprle
// revile
//
// usyasaeeinaedofloominglossoms
// CDARIES
// codeforces
// es
//
// helaoard
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node
{
    char value;
    int index;
};

struct TwoStack
{

    void push_back(char a)
    {
        if (islower(a))
            low.push({a, cnt++});
        else
            up.push({a, cnt++});
        s++;
    }

    void remove_low()
    {
        if (low.empty())
            return;
        Node last = low.top();
        low.pop();
    }

    void remove_up()
    {
        if (up.empty())
            return;
        Node last = up.top();
        up.pop();
    }

    int size()
    {
        return s;
    }

    string result()
    {
        string res = "";
        stack<Node> r1, r2;
        while (!low.empty())
        {
            Node t = low.top();
            low.pop();
            r1.push(t);
        }
        while (!up.empty())
        {
            Node t = up.top();
            up.pop();
            r2.push(t);
        }

        while (!r1.empty() || !r2.empty())
        {
            if (r1.empty())
            {
                Node n2 = r2.top();
                res.push_back(n2.value);
                r2.pop();
                continue;
            }
            if (r2.empty())
            {
                Node n1 = r1.top();
                res.push_back(n1.value);
                r1.pop();
                continue;
            }

            Node n1 = r1.top(), n2 = r2.top();
            if (n1.index < n2.index)
            {
                res.push_back(n1.value);
                r1.pop();
            }
            else
            {
                res.push_back(n2.value);
                r2.pop();
            }
        }

        return res;
    }

private:
    stack<Node> low, up;
    int s = 0, cnt = 0;
};

void solve()
{
    string s;
    cin >> s;
    TwoStack res;
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == 'b')
        {
            res.remove_low();
            continue;
        }
        if (s[i] == 'B')
        {
            res.remove_up();
            continue;
        }

        res.push_back(s[i]);
    }
    cout << res.result() << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
