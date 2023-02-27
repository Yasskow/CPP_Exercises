#pragma once

class Plush
{
public:
    Plush(int cost)
        : _cost{cost}
    {
    }

    void set_cost(int newcost)
    {
        _cost = newcost;
    }
    int get_cost() const
    {
        return _cost;
    }

private:
    int _cost = 10;
};