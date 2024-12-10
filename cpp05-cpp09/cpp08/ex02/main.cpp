#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << GREEN "----- MutantStack Basic Operations -----" RESET << std::endl;
    MutantStack<float> mstack;

    mstack.push(5.5);
    mstack.push(17);
    std::cout << "Top element after pushes: " << mstack.top() << std::endl;

    std::cout << "Size before pop: " << mstack.size() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(37.94);
    mstack.push(-13);
    std::cout << "Stack size after multiple pushes: " << mstack.size() << std::endl;

    std::cout << CYAN "MutantStack elements:" RESET << std::endl;
    for (MutantStack<float>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    std::cout << CYAN "MutantStack reverse elements:" RESET << std::endl;
    for (MutantStack<float>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
    {
        std::cout << *it << std::endl;
    }

    std::cout << GREEN "----- Comparison with std::list -----" RESET << std::endl;
    std::list<float> lst;
    lst.push_back(5.5);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(37.94);
    lst.push_back(-13);

    std::cout << CYAN "std::list elements:" RESET << std::endl;
    for (std::list<float>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    std::cout << CYAN "std::list reverse elements:" RESET << std::endl;
    for (std::list<float>::reverse_iterator it = lst.rbegin(); it != lst.rend(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
