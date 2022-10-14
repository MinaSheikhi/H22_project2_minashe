#include <cassert>
#include <iostream>

#include "array_list.cpp"

/**
 * @brief Test that an empty array list has length zero
 *
 */
void test_empty_array_has_length_zero()
{
    ArrayList a{};
    std::cout << "Test that empty array has length zero";
    assert(a.length() == 0);
    std::cout << " - Success!\n";
}

/**
 * @brief Test the append method and the get method
 *
 */
void test_array_with_two_elements_appended_has_length_two()
{
    std::cout << "Test append";
    ArrayList a{};
    a.append(1);
    a.append(2);
    assert(a.length() == 2);
    assert(a.get(0) == 1);
    assert(a.get(1) == 2);
    std::cout << "- Success!\n";

}


/**
 * @brief Test that printing works
 *
 */
void test_print()
{
    std::cout << "Test print\n";
    ArrayList a{};
    a.append(1);
    a.append(2);
    a.print();
}

/**
 * @brief Test that we can construct an ArrayList from
 * a vector of integers
 *
 */
void test_vector_constructor()
{
    std::cout << "Test the vector constructor";
    ArrayList a{{1, 2, 3}};
    assert(a.length() == 3);
    assert(a.get(0) == 1);
    assert(a.get(1) == 2);
    assert(a.get(2) == 3);

    std::cout << " - Success!\n";
}

/**
 * @brief Test the indexing operator []
 * to both getting at setting values
 *
 */
void test_indexing_operator()
{
    std::cout << "Test the indexing operator";
    ArrayList a{{1, 2}};
    assert(a[0] == 1);
    assert(a[1] == 2);
    a[0] = 5;
    assert(a[0] == 5);
    std::cout << " - Success!\n";
}
/**
 * @brief Test that value can be inserted 
 * at given index.
 */
void test_insert()
{
    std::cout <<"Testing insert";
    ArrayList a{{0, 1}};
    assert(a.length() == 2);
    a.insert(42, 0);
    assert(a.length() == 3);
    assert(a[0] == 42);
    assert(a[1] == 0);
    assert(a[2] == 1);
    a.insert(43, 1);
    assert(a.length() == 4);
    assert(a[0] == 42);
    assert(a[1] == 43);
    assert(a[2] == 0);
    assert(a[3] == 1);
    a.insert(44, 4);
    assert(a.length() == 5);
    assert(a[0] == 42);
    assert(a[1] == 43);
    assert(a[2] == 0);
    assert(a[3] == 1);
    assert(a[4] == 44);
    std::cout << " - Success!\n";
}

/**
 * @brief Test that chosen value can be removed 
 * from the array
*/
void test_remove()
{
    std::cout << "Testing remove";
    ArrayList a{{10, 12, 13, 13, 24, 42}};
    assert(a.length() == 6);
    a.remove(12);
    assert(a.length() == 5);
    assert(a[0] == 10);
    assert(a[1] == 13);
    assert(a[2] == 13);
    assert(a[3] == 24);
    assert(a[4] == 42);
    a.remove(24);
    assert(a.length() == 4);
    assert(a[0] == 10);
    assert(a[1] == 13);
    assert(a[2] == 13);
    assert(a[3] == 42);
    std::cout << "- Success!\n";
}

int main()
{
    /*
    test_empty_array_has_length_zero();
    test_array_with_two_elements_appended_has_length_two();
    test_print();
    test_vector_constructor();
    test_indexing_operator();
    test_insert();
    test_remove();
    */
}