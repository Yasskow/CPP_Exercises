#pragma once
#include "../lib/Unit.hpp"
#include "../lib/Ingredient.hpp"
#include "../lib/Consumable.hpp"
#include "../lib/Cupboard.hpp"
#include <list>
#include <algorithm>

class Kitchen{
public:

    const Unit& register_unit(const Unit& unit);
    const Ingredient& register_ingredient(const Ingredient& ingredient);
    const Unit* find_unit(const std::string& name) const;
    const Ingredient* find_ingredient(const std::string& name) const;
    std::optional<Consumable> make_random_consumable(float quantity, unsigned int expiration);
    const Cupboard& get_cupboard() const { return _cupBoard; }
    void store_in_cupboard(const Consumable& consumable);
    void wait_time(unsigned int timeExpir);
private:
    std::list<const Unit*> _units;
    std::list<const Ingredient*> _ingredients;
    Cupboard& _cupBoard;
};
