#include "kolejka.hpp"
#include <iostream>
#include <string>

int main() {
    Queue q({"a", "b", "c"});
    std::cout << "Element na początku kolejki q (a, b, c): " << q.peek() << std::endl;

    Queue q1(3); 
    q1.push("a");
    q1.push("b");

    Queue q2(q1);
    std::cout << "Długość q2 (kopia q1 (a, b)): " << q2.length() << std::endl;
    std::cout << "Element na początku q2: " << q2.peek() << std::endl;

    Queue q3 = std::move(q1);
    std::cout << "Element na początku q3 (przeniesienie q1): " << q3.peek() << std::endl;

    std::cout << "Usuwanie elementów z q2:" << std::endl;
    while (q2.length() > 0){
        std::cout << "Usunięty element: " << q2.remove() << std::endl;
    }

    try{
        std::cout << q2.peek();
    } catch (const std::out_of_range& e){
        std::cerr << "Nie mozna zobaczyc elementu z poczatku kolejki q2: " << e.what() << std::endl;
    }

    q3.push("c");
    try{
        q3.push("d");
    } catch (const std::out_of_range& e){
        std::cerr << "Nie mozna dodac elementu do kolejki q3: " << e.what() << std::endl;
    }

    return 0;
}
