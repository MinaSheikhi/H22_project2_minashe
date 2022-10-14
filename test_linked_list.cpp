#include <cassert>
#include <iostream>

#include "linked_list.cpp"

/**
 * @brief Test the append method and the indexing operator method
 *
 */
void test_append_and_get()
{
    LinkedList ll{};
    ll.append(0);
    ll.append(1);
    assert(ll[0] == 0);
    assert(ll[1] == 1);
}

/**
 * @brief Test that accesing an element outside of the
 * bounds throws a range error.
 *
 */
void test_access_element_out_of_bounds_throw_range_error()
{
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
}

/**
 * @brief Test that we can construct a LinkedList
 * from a vector of integers
 *
 */
void test_vector_constructor()
{
    LinkedList ll{{0, 1}};
    assert(ll[0] == 0);
    assert(ll[1] == 1);
}

/**
 * @brief Test that printing works
 *
 */
void test_print()
{
    LinkedList ll{};
    ll.print();
    ll.append(0);
    ll.print();
}

/**
 * @brief Test that we can insert element at the front
 *
 */
void test_push_front()
{
    LinkedList ll{{1, 2, 3}};
    ll.push_front(42);
    assert(ll.length() == 4);
    assert(ll[0] == 42);
}

int main()
{
    test_append_and_get();
    test_access_element_out_of_bounds_throw_range_error();
    test_vector_constructor();
    test_print();
    test_push_front();
    return 0;
}