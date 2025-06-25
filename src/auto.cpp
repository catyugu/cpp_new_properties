#include <map>
#include <string>
#include <vector>
#include <iostream>
int main(){
    std::map<std::string, std::vector<int>> m;
    m.insert({"first", {1, 2, 3}});
    m.insert({"second", {4, 5, 6}});
    for (auto& [key, value] : m){
        std::cout<<key<<": "<<value[0]<<" "<<value[1]<<" "<<value[2]<<std::endl;
    }
}