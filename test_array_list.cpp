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
    std::cout <<"Testing insert \n";
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
    ArrayList b{{10, 12, 13, 13, 24, 42}};
    assert(b.length() == 6);
    b.remove(1);
    assert(b.length() == 5);
    assert(b[0] == 10);
    assert(b[1] == 13);
    assert(b[2] == 13);
    assert(b[3] == 24);
    assert(b[4] == 42);
    b.remove(3);
    assert(b.length() == 4);
    assert(b[0] == 10);
    assert(b[1] == 13);
    assert(b[2] == 13);
    assert(b[3] == 42);
    std::cout << "- Success!\n";
}

/***
 * @brief Test that chosen element pops
*/
void test_pop_at_index()
{
    std::cout << "Testing pop at index";
    ArrayList a{{4, 5, 6, 9}};    
    assert (a.pop(1) == 5);
    assert(a[0] == 4);
    assert(a[1] == 6);
    assert(a[2] == 9);
    std::cout << "- Success\n";
}

/***
 * @brief Test that last element in list pop.
*/

void test_pop()
{
    std::cout << "Testing pop";
    ArrayList a{{4, 5, 6, 9}};    
    assert (a.pop() == 9);
    assert(a[0] == 4);
    assert(a[1] == 5);
    assert(a[2] == 6);
    std::cout << "- Success\n";
}

void test_capacity()
{
    std::cout << "Testing capacity";
    ArrayList a{};
    assert(a.capacity() == 1);
    a.append(3);
    a.append(4);
    assert(a.capacity() == 2);
    a.append(8);
    a.append(5);
    a.append(5);
    assert(a.capacity() == 8);
    std::cout << "- Success\n";

}

/***
 * @brief Test shrink_to_fit
*/

void test_shrink_to_fit_remove()
{
    std::cout << "Testing shrink to fit in remove method";
    ArrayList a{{}};

    for(int i = 0; i < 10; i++)
    {
        a.append(i);
    }
    assert(a.capacity() == 16);
    
    for (int i = 0; i < 7; i++)
    {
        a.remove(i);
    }
    assert(a.capacity() == 4);
    std::cout << "- Success\n";    
}


void test_shrink_to_fit_pop()
{
    std::cout << "Testing shrink to fit in pop method";
    ArrayList a{{}};

    for(int i = 0; i < 10; i++)
    {
        a.append(i);
    }
    assert(a.capacity() == 16);
    
    for (int i = 0; i < 7; i++)
    {
        a.pop(i);
    }

    assert(a.capacity() == 4);
    std::cout << "- Success\n";
}

int main()
{
    
    test_empty_array_has_length_zero();
    test_array_with_two_elements_appended_has_length_two();
    test_print();
    test_vector_constructor();
    test_indexing_operator(); 
    test_insert();
    test_remove();
    test_pop_at_index();
    test_pop();
    test_capacity();
    test_shrink_to_fit_remove();
    test_shrink_to_fit_pop();
}
