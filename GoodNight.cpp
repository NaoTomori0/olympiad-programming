#include <bits/stdc++.h>
using namespace std;

#define int long long

class Time
{
public:
    Time(int h = 0, int m = 0, int s = 0)
    {
        hour = h;
        minutes = m;
        seconds = s;
    }

    void add(int h = 0, int m = 0, int s = 0)
    {
        seconds += s;
        minutes += seconds / 60;
        seconds %= 60;
        minutes += m;
        hour += minutes / 60;
        minutes %= 60;
        hour = (hour + h) % 24;
    }

    Time getTime() { return *this; }

    void print() { cout << hour << ":" << minutes << ":" << seconds << '\n'; }

private:
    int hour, minutes, seconds;
};

class Human
{
public:
    bool Sleep(int hour = 9, int minutes = 0, Time *t = nullptr)
    {
        bool ok = isAlive && energyСoefficient <= 0.4;
        if (ok)
        {
            if (t != nullptr)
                t->add(hour, minutes);
            energyСoefficient += (hour * 60 + minutes) * sleepEnergyRecoveryСoefficient;
        }
        return isSleeping = ok;
    }

    bool WakeUp()
    {
        bool ok = isAlive && isSleeping;
        if (ok)
            return isSleeping = 0;
        return isSleeping;
    }

    double drinkCoffe(int count = 1)
    {
        if (isAlive && count <= 10)
            return energyСoefficient += 0.13 * count * !isSleeping * (count <= 10);
        else
            return isAlive = false, energyСoefficient = 0.0;
    }

    void SayGoodNight(string lastWords, int hour = 9, int minutes = 0, Time *t = nullptr)
    {
        if (Sleep(hour, minutes, t))
            cout << lastWords << '\n';
    }

    Human(int age = 67, double Health = 100, double energyСoefficient = 0.1)
    {
        isAlive = true;
        isSleeping = false;
        this->age = age;
        this->energyСoefficient = energyСoefficient;
        this->Health = Health;
    }

private:
    const double sleepEnergyRecoveryСoefficient = 0.11;
    bool isSleeping, isAlive;
    int age;
    double energyСoefficient, Health;
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Human bro;
    Time appleWatch(4, 35);

    bro.SayGoodNight("Ночи, мужики.", 9, 35, &appleWatch);
    appleWatch.print();
    return 0;
}