#include "Bureaucrat.hpp"

int main(){

    Bureaucrat  moses("moses", 1);
    std::cout << moses.getGrade() << std::endl;
    moses.decreaseGrade();
    std::cout << moses << std::endl;
    moses.increaseGrade();
    std::cout << moses << std::endl;
    moses.increaseGrade();
    std::cout << moses << std::endl;
    moses.increaseGrade();

	return 0;
}
