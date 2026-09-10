// I. Монстры
// ограничение по времени на тест2 секунды
// ограничение по памяти на тест256 мегабайт

// Вы и несколько монстров находитесь в лабиринте. Когда вы передвигаетесь на одну
// клетку, каждый монстр также может передвинуться на одну клетку. Ваша цель –
// добраться до границы лабиринта и при этом не быть пойманным монстром. Считается,
// что монстр поймал вас, если он стоит в той же клетке, что и вы.

// Вы хотите придумать такой маршрут, чтобы достичь границы наверняка, то есть даже
// если все монстры изначально знают ваш маршрут, то не смогут вас поймать.

// Входные данные
// Первая строка содержит два целых числа n и m (1 ≤ n, m ≤ 1000) – размерность
// лабиринта.

// Далее идут n строк из m символов – описание лабиринта. Каждый символ может быть
// либо '.' – пустое место, '#' – препятствие, 'A' – ваша стартовая позиция, 'M' – монстр.

// Гарантируется, что символ 'A' содержится в описании ровно один раз.

// Выходные данные
// В первой строке выведите «YES» без кавычек, если существует такой путь, или «NO»
// без кавычек иначе.

// Если путь существует, то во второй строке выведите описание пути в виде строки
// из символов 'L', 'R', 'U', 'D', обозначающих направление движения (влево, вправо,
// вверх, вниз). Если существует несколько ответов, то выведите любой (длиной
// не более n·m символов).

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 5 8
// ########
// #M..A..#
// #.#.M#.#
// #M#..#..
// #.######
// ======================================================================
// Выходные данные
// ======================================================================
// YES
// RRDDR
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int moveX[] = {-1, 0, 1, 0};
const int moveY[] = {0, -1, 0, 1};
const char resReve[] = {'R', 'D', 'L', 'U'};
int n, m;
const int INF = 1e9;

bool canMove(int i, int x, int y)
{
    return x + moveX[i] < m && x + moveX[i] >= 0 && y + moveY[i] >= 0 && y + moveY[i] < n;
}

void solve()
{
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<int>> dist(n, vector<int>(m, INF)), distPlayer(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    pair<int, int> playerPos;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'M')
            {
                q.push({i, j});
                dist[i][j] = 0;
            } // y , x
            if (s[i][j] == 'A')
            {
                playerPos = {i, j};
                distPlayer[i][j] = 0;
            } // y , x
        }
    }

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newX = cur.second + moveX[i], newY = cur.first + moveY[i];
            if (canMove(i, cur.second, cur.first) && s[newY][newX] != '#' && dist[newY][newX] == INF)
            {
                dist[newY][newX] = dist[cur.first][cur.second] + 1;
                q.push({newY, newX});
            }
        }
    }
    q.push(playerPos);
    pair<int, int> maxPos = {-1, -1};
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.first == n - 1 || cur.second == m - 1 || cur.first == 0 || cur.second == 0)
            maxPos = {cur.first, cur.second};

        for (int i = 0; i < 4; i++)
        {
            int newX = cur.second + moveX[i], newY = cur.first + moveY[i];
            if (canMove(i, cur.second, cur.first) && s[newY][newX] != '#' && distPlayer[newY][newX] == -1 && distPlayer[cur.first][cur.second] + 1 < dist[newY][newX])
            {
                if (newY == n - 1 || newX == m - 1 || newX == 0 || newY == 0)
                    maxPos = {newY, newX};
                distPlayer[newY][newX] = distPlayer[cur.first][cur.second] + 1;
                q.push({newY, newX});
            }
        }
    }
    if (maxPos.first == -1)
    {
        cout << "NO\n";
        return;
    }
    q.push(maxPos);
    string result = "";
    cout << "YES\n";
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (distPlayer[cur.first][cur.second] == 0)
        {
            cout << result.size() << '\n';
            reverse(result.begin(), result.end());
            cout << result << '\n';
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int newX = cur.second + moveX[i], newY = cur.first + moveY[i];
            if (canMove(i, cur.second, cur.first) && distPlayer[newY][newX] != -1 && distPlayer[newY][newX] + 1 == distPlayer[cur.first][cur.second])
            {
                result.push_back(resReve[i]);
                q.push({newY, newX});
            }
        }
    }
}

// for (auto &i : distPlayer)
// {
//     for (auto &j : i)
//         cout << j << '\t';
//     cout << '\n';
// }

// for (auto &i : dist)
// {
//     for (auto &j : i)
//         cout << j << '\t';
//     cout << '\n';
// }

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
