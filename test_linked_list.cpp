#include <cassert>
#include <iostream>

#include "linked_list.cpp"


/**
 * @brief Test that empty list has length 0
*/
void test_empty_list_has_length_zero()
{
    std::cout << "Testing if empty list has length zero";
    LinkedList a{};
    assert(a.length() == 0);
    std::cout << " - Success!\n";
}

/**
 * @brief Test the append method and the indexing operator method
 *
 */
void test_append()
{
    std::cout << "Testing append ";
    LinkedList ll{};
    ll.append(0);
    ll.append(1);
    assert(ll[0] == 0);
    assert(ll[1] == 1);
    std::cout <<" - Success \n";
}

/**
 * @brief Test that accesing an element outside of the
 * bounds throws a range error.
 *
 */
void test_access_element_out_of_bounds_throw_range_error()
{
    std::cout << "Testing if it throws range error when elements are out of range ";
    LinkedList ll{};

    bool throwed_range_error = false;
    try
    {
        int x = ll[0];
    }
    catch (const std::range_error &e)
    {
        throwed_range_error = true;
    }
    assert(throwed_range_error);
    std::cout << " - Success!\n";
}


/**
 * @brief Test that printing works
 *
 */
void test_print()
{
    std::cout << "Testing if print works \n";
    LinkedList ll{};
    ll.print();
    ll.append(0);
    ll.print();
    std::cout << " - Success!\n";
}

void test_index_operator()
{
    std::cout << "Testing index operator";
    LinkedList ll{{8, 7, 6, 5}};
    assert(ll[0] == 8);
    assert(ll[1] == 7);
    ll[2] = 9;
    assert(ll[2] == 9);
    assert(ll[3] == 5);
    std::cout << "- Success! \n";
}

void test_insert()
{
    std::cout <<"Testing insert";
    LinkedList ll{{0, 1}};
    assert(ll.length() == 2);
    ll.insert(42, 0);
    assert(ll.length() == 3);
    assert(ll[0] == 42);
    assert(ll[1] == 0);
    assert(ll[2] == 1);
    ll.insert(43, 1);
    assert(ll.length() == 4);
    assert(ll[0] == 42);
    assert(ll[1] == 43);
    assert(ll[2] == 0);
    assert(ll[3] == 1);
    ll.insert(44, 4);
    assert(ll.length() == 5);
    assert(ll[0] == 42);
    assert(ll[1] == 43);
    assert(ll[2] == 0);
    assert(ll[3] == 1);
    assert(ll[4] == 44);
    std::cout << " - Success!\n";
}

/**
 * @brief Test that we can insert element at the front
 *
 */
void test_push_front()
{
    std::cout << "Testing push front ";
    LinkedList ll{{1, 2, 3}};
    ll.push_front(42);
    assert(ll.length() == 4);
    assert(ll[0] == 42);
    std::cout << " - Success!\n";
}

/**
 * @brief Test that chosen value can be removed 
 * from the array
*/
void test_remove()
{
    std::cout << "Testing remove";
    LinkedList ll{{1, 2, 3, 4, 5}};
    ll.remove(4);
    assert (ll[0] == 1);
    assert(ll[1] == 2);
    assert(ll[2] == 3);
    assert(ll[3] == 4);
    ll.remove(2);
    assert(ll[0] == 1);
    assert(ll[1] == 2);
    assert(ll[2] == 4);
    
    std::cout << " - Success!\n";
}

/***
 * @brief Test that chosen element pops
*/
void test_pop_at_index()
{
    std::cout << "Testing pop at index";
    LinkedList ll{{1, 2, 3, 4, 5}};
    ll.pop(4);
    assert (ll[0] == 1);
    assert(ll[1] == 2);
    assert(ll[2] == 3);
    assert(ll[3] == 4);
    ll.pop(2);
    assert(ll[0] == 1);
    assert(ll[1] == 2);
    assert(ll[2] == 4);
    std::cout << " - Success!\n";
}

/***
 * @brief 
*/
void test_pop()
{
    std::cout << "Testing pop";
    LinkedList ll{{1, 2, 3, 4, 5}};
    ll.pop();
    assert (ll[0] == 1);
    assert(ll[1] == 2);
    assert(ll[2] == 3);
    assert(ll[3] == 4);
    std::cout << " - Success!\n";
}

/**
 * @brief Test that we can construct a LinkedList
 * from a vector of integers
 *
 */
void test_vector_constructor()
{
    std::cout << "Testing vector constructor works ";
    LinkedList ll{{0, 1}};
    assert(ll[0] == 0);
    assert(ll[1] == 1);
    std::cout << " - Success!\n";
}

int main()
{
    test_empty_list_has_length_zero();
    test_access_element_out_of_bounds_throw_range_error();
    test_append();
    test_print();
    test_insert();
    test_index_operator();
    test_push_front(); 
    test_remove();
    test_pop_at_index();
    test_pop();
    test_vector_constructor();
    return 0;
}