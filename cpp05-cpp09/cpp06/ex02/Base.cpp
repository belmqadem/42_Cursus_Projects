#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
    std::cout << "Base destructor called" << std::endl;
}

Base * generate(void) {
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0) {
        return new A();
    } else if (random == 1) {
        return new B();
    } else {
        return new C();
    }
}

void identify(Base* p) {
    A* a = dynamic_cast<A*>(p);
    if (a) {
        std::cout << "A" << std::endl;
        return;
    }

    B* b = dynamic_cast<B*>(p);
    if (b) {
        std::cout << "B" << std::endl;
        return;
    }

    C* c = dynamic_cast<C*>(p);
    if (c) {
        std::cout << "C" << std::endl;
        return;
    }

    std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    } catch (std::exception &e) {
        try {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        } catch (std::exception &e) {
            try {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            } catch (std::exception &e) {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}