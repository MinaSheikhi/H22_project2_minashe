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
    ArrayListNode *prev = nullptr;
    // Pointer to the next node; here default value nullpointer
    ArrayListNode *next=nullptr; 


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

    /**
     *@brief checks if index is smaller than 0 or
     * bigger than or like the size.
     * 
     * @param index the index
    */
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

    // Destructor
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

    /**
     * @brief append an array to the end of the list.
     * Increases the size by 1 for each appending.
     * 
     * @param array a vector of integers
    */
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

    /**
     * @brief prints the list elements.
     * 
    */
    void print()
    {
        std::cout << "[";
        if (head != nullptr)
        {
            ArrayListNode *current = head;
            while (current->next != nullptr)
            {
                current->array->print();
                std::cout << " ";
                current = current->next;                
                current->array->print();
            }
            
            std::cout << "] \n";
        }
    }

    /**
     * @brief finds the node at the given index
     * 
     * @param index the index chosen
     * @return ArrayListNode* a pointer to the index chosen
    */
    ArrayListNode *find_node_at_index(int index)
    {
        ArrayListNode *current = head;
        for (int i = 0; i < index; i++)
            current = current->next;
        return current;
    }

    /**
     * @brief Get value at given index
     * 
     * @param index the index
     * 
     * @return ArrayList& Reference to the array at that index
    */
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
    lal.append({4, 5, 6});  // Append a second list
    lal.print();            // Print the entire LinkedArrayList
    lal[0]->append(42);    // Append the number 42 to the first ArrayList
    lal.print();            // Print the entire LinkedArrayList again

    return 0;
}