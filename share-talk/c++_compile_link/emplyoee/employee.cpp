#include <iostream>
class Employee;
Employee* findEmployee(const std::string &surname, const std::string givenName, bool retired = false){
    std::cout << "version 1" << std::endl;
    return NULL;
}
Employee* findEmployee(const std::string &fullname, bool retired = false) {
    std::cout << "version 2" << std::endl;
    return NULL;
}

int main(void) {
    findEmployee("shaocong", "liang");
    return 0;
}