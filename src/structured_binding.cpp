#include <map>
#include <string>
#include <vector>
#include <iostream>
std::tuple<int, std::string, double> get_student_info(std::string name){
    if (name.compare("Alice")==0){
        return {1, "Computer Science", 3.0};
    }else{
        return {2, "Economics", 3.5};
    }
}
int main(){
    auto [id, major, gpa] = get_student_info("Alice");
    std::cout<<"id: " << id<<"; major: "<<major<<"; GPA: "<<gpa<<std::endl;
}