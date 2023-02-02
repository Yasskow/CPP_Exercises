#include <iostream>
#include <string>
#include <set>
#include <map>
#include <sstream>

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
            string line;
            getline(cin, line);
            stringstream stream(line);
            string key;
            while (!stream.eof()){
                stream >> key;
                if (ourMap.contains(key)){
                    std::cout << ourMap.find(key)->second << " ";
                } else{
                    std::cout << " ??? ";
                }
            }
            std::cout << endl;
        }
        if(value == "print"){
            for(auto elem: ourMap){
                cout << elem.first + " => "+ elem.second << endl;
            }
        }
    }

    return 0;
}