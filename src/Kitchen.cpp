#include "Kitchen.hpp"

bool compare(const std::string& str1, const std::string& str2){ 
    return std::lexicographical_compare(str1.begin(), 
        str1.end(), str2.begin(), str2.end(), 
        [](char e, char t){return tolower(e) == tolower(t);});
}

const Unit& Kitchen::register_unit(const Unit& unit){
   _units.emplace_back(&unit);
   return unit;
}

const Ingredient& Kitchen::register_ingredient(const Ingredient& ingredient){
    _ingredients.emplace_back(&ingredient);
    return ingredient;
}

const Ingredient* Kitchen::find_ingredient(const std::string& name) const{
    auto it = std::find_if(_ingredients.begin(), _ingredients.end(), 
        [&name](const Ingredient* ingredient){
            return compare(ingredient->name, name);});
    return it == _ingredients.end() ? nullptr : *it;
}

const Unit* Kitchen::find_unit(const std::string& name) const{
    auto it = std::find_if(_units.begin(), _units.end(), 
        [&name](const Unit* unit){return unit->name == name;});
    return it == _units.end() ? nullptr : *it;
}

std::optional<Consumable> Kitchen::make_random_consumable(float quantity, unsigned int expiration){
    if(_ingredients.empty()){
        return std::nullopt;
    }
    auto consumable = Consumable{**_ingredients.begin(), quantity, expiration};
    return std::optional<Consumable>(consumable);
}

void Kitchen::store_in_cupboard(const Consumable& consumable){
    _cupBoard.consumables.emplace_back(consumable);
}

void Kitchen::wait_time(unsigned int timeExpir){
    for(const auto& elem: _cupBoard.consumables){
        if(elem.expiration_time.has_value()){
            auto tmp = elem.expiration_time.value();
            elem.expiration_time.value() = tmp - timeExpir;
        }
    }
}