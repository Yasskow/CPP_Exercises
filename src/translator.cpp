#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace  std;

std::set<string> make_exit_commands(){
    return {"e", "exit", "q", "quit"};
}

int main(){
    string value;
    std::string w1;
    std::string w2;
    auto set = make_exit_commands();
    std::map<string, string> ourMap;

    while (true){
        std::cout << "This is a translator, but it does nothing for now..." << std::endl;
        std::cin >> value;
        if(set.count(value) > 0){
            break;
        }
        if(value == "add"){
            std::cin >>  w1;
            std::cin >> w2;
            ourMap.emplace(w1,w2);
            std::cout << w1 +" => "+w2 << endl;
        }
        if(value == "translate"){
            std::cin >> w1;
            if(!ourMap.contains(w1)){

            }
        }
    }

    return 0;
}