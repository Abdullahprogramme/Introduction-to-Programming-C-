#include <iostream>

int main() {

    // For loops syntax
    // for (initialization; condition; increment) {
    //     // code block
    // }

    // For loop example
    std::cout << "For loop example:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "i = " << i << std::endl;
    }

    std::cout << '\n';

    for (int i{0}, j{0}; i < 5; ++i, ++j) {
        std::cout << "i = " << i << ", j = " << j << std::endl;
    }


    // -----------------------------------------------------------------------------------
    // Nested for loops syntax
    // for (initialization; condition; increment) {
    //     for (initialization; condition; increment) {
    //         // code block
    //     }
    // }

    // Nested for loop example
    std::cout << "\nNested for loop example:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "i = " << i << ", j = " << j << std::endl;
        }
    }



    // -----------------------------------------------------------------------------------
    // While loops syntax
    // while (condition) {
    //     // code block
    // }

    // While loop example
    std::cout << "\nWhile loop example:" << std::endl;
    int j = 0;
    while (j < 5) {
        std::cout << "j = " << j << std::endl;
        ++j;
    }



    // -----------------------------------------------------------------------------------
    // Do-while loops syntax
    // do {
    //     // code block
    // } while (condition);

    // Do-while loop example
    std::cout << "\nDo-while loop example:" << std::endl;
    int k = 0;
    do {
        std::cout << "k = " << k << std::endl;
        ++k;
    } while (k < 5);

    // further types of for loops

    // for each loop syntax
    // for (type variable : array) {
    //     // code block
    // }

    // for each loop example
    std::cout << "\nFor each loop example:" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    for (int element : arr) {
        std::cout << "element = " << element << std::endl;
    }

    // range based for loop syntax
    // for (type variable : range) {
    //     // code block
    // }

    // range based for loop example
    std::cout << "\nRange based for loop example:" << std::endl;
    for (int i : {1, 2, 3, 4, 5}) {
        std::cout << "i = " << i << std::endl;
    }


    // using loops in hashmaps
    // for (auto i = map.begin(); i != map.end(); ++i) {
    //     std::cout << i->first << " : " << i->second << std::endl;
    // }

    // using loops in vectors
    // for (auto i = vec.begin(); i != vec.end(); ++i) {
    //     std::cout << *i << std::endl;
    // }

    return 0;
}