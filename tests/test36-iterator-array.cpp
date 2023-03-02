#include "../src/Node.hpp"
#include "../src/JsonParser.hpp"
#include <catch2/catch_test_macros.hpp>

/* Json files are in directory `json` in the root directory of the TP. */
std::string json_dir = "../json/";

TEST_CASE("One may iterate through ArrayNode with foreach.")
{
    std::unique_ptr<Node> node = JsonParser::parse_from_file(json_dir + "pokedex.json");
    ArrayNode *pokemons = node->as_ObjectNode()->at("pokemon")->as_ArrayNode();
    unsigned i = 0;
    for (std::unique_ptr<Node> const &pokemon : *pokemons)
    {
        ++i;
        REQUIRE(pokemon->as_ObjectNode() != nullptr);
        REQUIRE(pokemon->as_ObjectNode()->at("name") != nullptr);
        std::cerr << pokemon->as_ObjectNode()->at("name")->print() << std::endl;
    }
    REQUIRE(i == 151);
}

#include "routine_memory_check.cpp"