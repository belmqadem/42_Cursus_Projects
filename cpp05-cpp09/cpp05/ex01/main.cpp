#include "Form.hpp"

int main() {
    try {
        Form form1("Form A", 50, 50);
        std::cout << form1 << std::endl;

        Bureaucrat bureaucrat1("Jax", 50);
        std::cout << BOLD_GREEN << bureaucrat1.getName() << " has grade " << bureaucrat1.getGrade() << RESET << std::endl;
        bureaucrat1.signForm(form1);
        std::cout << std::endl;

        Bureaucrat bureaucrat2("Bob", 51);
        std::cout << BOLD_GREEN << bureaucrat2.getName() << " has grade " << bureaucrat2.getGrade() << RESET << std::endl;
        bureaucrat2.signForm(form1);
        std::cout << std::endl;

        Form form2("Form B", 150, 150);
        std::cout << form2 << std::endl;

        Bureaucrat bureaucrat3("Jessie", 1);
        std::cout << BOLD_GREEN << bureaucrat3.getName() << " has grade " << bureaucrat3.getGrade() << RESET << std::endl;
        bureaucrat3.signForm(form2);
        std::cout << form2 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
