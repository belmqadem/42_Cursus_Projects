#include "Array.hpp"

class Person
{
public:
    Person(std::string name = "", int age = 0) : name(name), age(age) {}
    std::string getName() const { return name; }
    int getAge() const { return age; }

private:
    std::string name;
    int age;
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.getName() << " (" << p.getAge() << ")";
    return os;
}

int main()
{
    try
    {
        Array<int> intArray(5);
        std::cout << YELLOW "intArray size: " << intArray.getSize() << RESET << std::endl;
        for (unsigned int i = 0; i < intArray.getSize(); ++i)
        {
            std::cout << "intArray[" << i << "]: " << intArray[i] << std::endl;
        }

        std::cout << std::endl;
        for (unsigned int i = 0; i < intArray.getSize(); ++i)
        {
            intArray[i] = i * 10;
        }
        std::cout << BLUE "After modification:" << RESET << std::endl;
        for (unsigned int i = 0; i < intArray.getSize(); ++i)
        {
            std::cout << "intArray[" << i << "]: " << intArray[i] << std::endl;
        }

        std::cout << std::endl;
        Array<int> copiedArray(intArray);
        std::cout << YELLOW "copiedArray size: " << copiedArray.getSize() << RESET << std::endl;
        for (unsigned int i = 0; i < copiedArray.getSize(); ++i)
        {
            std::cout << "copiedArray[" << i << "]: " << copiedArray[i] << std::endl;
        }

        const Array<int> assignedArray = intArray;
        std::cout << YELLOW "assignedArray size: " << assignedArray.getSize() << RESET << std::endl;
        for (unsigned int i = 0; i < assignedArray.getSize(); ++i)
        {
            std::cout << "assignedArray[" << i << "]: " << assignedArray[i] << std::endl;
        }

        std::cout << std::endl;
        intArray[0] = 999;
        std::cout << BLUE "After modifying intArray[0]:" RESET << std::endl;
        std::cout << "intArray[0]: " << intArray[0] << std::endl;
        std::cout << "copiedArray[0]: " << copiedArray[0] << std::endl;

        // std::cout << std::endl;
        // std::cout << BLUE "Attempting out-of-bounds access:" RESET << std::endl;
        // std::cout << intArray[10] << std::endl;

        std::cout << std::endl;
        Array<Person> personArray(3);
        personArray[0] = Person("Bod", 30);
        personArray[1] = Person("Jax", 25);
        personArray[2] = Person("Jamy", 35);

        std::cout << YELLOW "personArray size: " << personArray.getSize() << RESET << std::endl;
        for (unsigned int i = 0; i < personArray.getSize(); ++i)
        {
            std::cout << "personArray[" << i << "]: " << personArray[i] << std::endl;
        }
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}