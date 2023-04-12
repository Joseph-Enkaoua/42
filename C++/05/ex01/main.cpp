#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(){
    Bureaucrat  moses("moses", 1);
    Form		travelForm("travelForm", 90, 30);
    Form		justAForm("just a form", 60, 2);

    std::cout << moses.getGrade() << std::endl;
    moses.increaseGrade();
    std::cout << moses << std::endl;
    moses.increaseGrade();
    std::cout << moses << std::endl;
    moses.increaseGrade();
    travelForm.beSigned(&moses);
    moses.signForm(justAForm);

	return 0;
}
