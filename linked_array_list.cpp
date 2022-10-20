// In this problem we are extending doubly list so that each node in linked ist will be an Arraylist.

#include <iostream>
#include <vector>
#include <memory>
#include "array_list.cpp"

struct ArrayListNode
{
    //unique pointer pointing to value in <memory> ArrayList 
    std::unique_ptr<ArrayList> array; 
    // Pointer to the previous node; here default value nullpointer
    ArrayListNode *prev;
    // Pointer to the next node; here default value nullpointer
    ArrayListNode *next; 


ArrayListNode(std::vector<int> values, ArrayListNode *previous, ArrayListNode *next_)
    
{
    array = std::make_unique<ArrayList> (values);
    ArrayListNode *prev = previous;
    ArrayListNode *next = next_;
}
};

class LinkedArrayList
{
    private:
    // Pointer to the first and last element in the list
    ArrayListNode *head = nullptr;
    ArrayListNode *tail = nullptr;
    int _size = 0;

    void check_index_out_of_bounds(int index)
    {
        if ((index < 0) || (index >= _size))
            throw std::range_error("Index out of bounds");
    }

    public:

    // Default constructor
    LinkedArrayList()
    {
    }

    ~LinkedArrayList(){
        ArrayListNode *current = head;
        ArrayListNode *next = nullptr;

        while(current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void append(std::vector<int> array)
    {
        _size++;
        if (head == nullptr)
        {
            head = new ArrayListNode{array, nullptr, nullptr};
            tail = head;
        } else {
            tail->next = new ArrayListNode{array, tail, nullptr};
            tail = tail->next;
        }   
    }

    void print()
    {

        std::cout << "[";
        if(head != nullptr)
        {
            ArrayListNode *current = head;
            while (current->next != nullptr)
            {
                current->array->print();
                std::cout << " " ;
                current = current->next;
            }
            current->array->print();
        }
        std::cout << "] \n";
    }

    ArrayListNode *find_node_at_index(int index)
    {
        ArrayListNode *current = head;
        for (int i = 0; i < index; i++)
            current = current->next;
        return current;
    }


    std::unique_ptr<ArrayList> &operator[](int index)
    {
        check_index_out_of_bounds(index);
        ArrayListNode *current = find_node_at_index(index);
        return current->array;
    }

};


int main()
{
    LinkedArrayList lal{};  // Create an empty LinkedArrayList
    lal.append({1, 2});   // Append first list
    //lal.append({4, 5, 6});  // Append a second list
    lal.print();            // Print the entire LinkedArrayList
    //lal[0]->append(42);    // Append the number 42 to the first ArrayList
    //lal.print();            // Print the entire LinkedArrayList again

    return 0;
}