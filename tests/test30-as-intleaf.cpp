#include "../src/ArrayNode.hpp"
#include "../src/Node.hpp"
#include "../src/NodeKind.hpp"
#include "../src/IntLeaf.hpp"
#include "../src/ObjectNode.hpp"
#include "../src/StringLeaf.hpp"
#include <catch2/catch_test_macros.hpp>

/* Json files are in directory `json` in the root directory of the TP. */
std::string json_dir = "../json/";

// In order toi solve this test, you probably need to add the following line
// at the top of Node.hpp
//     class IntLeaf;
// and the following line at the top of Node.cpp
//     #include "IntLeaf.hpp"

TEST_CASE("There is a member-function Node::as_IntLeaf")
{
    std::unique_ptr<Node> node = IntLeaf::make_ptr(42);
    auto bnode = node->as_IntLeaf();
    int data = bnode->data();
    REQUIRE(data == 42);
}

/* The return type of as_IntLeaf() is not trivial! Think about it. */

TEST_CASE("Node::as_IntLeaf returns a nullptr if Node is not a IntLeaf")
{

    std::unique_ptr<Node> node2 = StringLeaf::make_ptr("Hello world");
    REQUIRE(node2->as_IntLeaf() == nullptr);

    std::unique_ptr<Node> node3 = ArrayNode::make_ptr();
    REQUIRE(node3->as_IntLeaf() == nullptr);

    std::unique_ptr<Node> node4 = ObjectNode::make_ptr();
    REQUIRE(node4->as_IntLeaf() == nullptr);
}

TEST_CASE("Node::as_IntLeaf is not virtual")
{

    std::unique_ptr<Node> node2 = StringLeaf::make_ptr("Hello world");
    REQUIRE(node2->as_IntLeaf() == nullptr);

    std::unique_ptr<Node> node3 = ArrayNode::make_ptr();
    REQUIRE(node3->as_IntLeaf() == nullptr);

    std::unique_ptr<Node> node4 = ObjectNode::make_ptr();
    REQUIRE(node4->as_IntLeaf() == nullptr);
}

#include "routine_memory_check.cpp"
