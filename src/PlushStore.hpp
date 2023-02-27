#pragma once

#include <string>

using namespace std;

class PlushStore
{
public:
    PlushStore(string name)
        : _name{name} {}

    string get_name() const
    {
        return _name;
    }
    int get_wealth_amount() const
    {
        return _wealth;
    }
    int get_stock_size() const
    {
        return _stock;
    }
    void loan(int cost)
    {
        _wealth += cost;
        _debt += cost + (cost / 10);
    }
    int get_debt_amount() const
    {
        return _debt;
    }
    void make_plush(int cost)
    {
        if (_wealth - cost < 0)
        {
            _wealth = 0;
            return;
        }
        else if (_wealth - cost >= -5 && _wealth - cost <= 0)
        {
            _wealth = 0;
            _stock += 1;
            return;
        }
        _wealth -= cost;
        _stock += 1;
        _experience += 1;
    }

private:
    string _name;
    int _wealth = 0;
    int _stock = 0;
    int _debt = 0;
    int _experience = 0;
};