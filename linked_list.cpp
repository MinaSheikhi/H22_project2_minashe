#include <iostream>
#include <stdexcept>
#include <vector>

struct Node
{
    // The value at the node
    int value;
    // Pointer to the previous node; here default value nullpointer
    Node *prev = nullptr; 
    // Pointer to the next node; here default value nullpointer
    Node *next = nullptr; 
};

class LinkedList
{
  private:
    // Pointer to the first and last element in the list
    Node *head = nullptr;
    Node *tail = nullptr;
    // Size of the list
    int _size = 0;

    /**
     * @brief Check wheter the given index if out of
     * bound and throw a range error if it is
     *
     * @param index The index to be checked
     */
    void check_index_out_of_bounds(int index)
    {
        if ((index < 0) || (index >= length()))
            throw std::range_error("Index out of bounds");
    }

    /**
     * @brief Find the node at the given index
     *
     * @param index The index where you want the node
     * @return Node* A pointer to the node at the index
     */
    Node *find_node_at_index(int index)
    {
        Node *current = head;
        for (int i = 0; i < index; i++)
            current = current->next;
        return current;
    }

  public:
    // Default constructor
    LinkedList()
    {
    }

    // Constructor for a list of values
    LinkedList(std::vector<int> values)
    {
        for (int v : values)
            append(v);
    }

    // Destructor
    ~LinkedList()
    {
        Node *current = head;
        Node *next = nullptr;
        // Move node until we are at the last element
        while (current != nullptr)
        {
            // (->) accesse members of structure through a pointer
            next = current->next;
            delete current;
            current = next;
        }
    }

    /**
     * @brief Return the length of the list
     *
     * @return int The length
     */
    int length()
    {
        return _size;
    }

    /**
     * @brief Append element to the end of the list
     *
     * @param val The value to be appended
     */
    void append(int val)
    {
        Node *new_node = new Node{val};
        _size++;
        if (head == nullptr)
        {
            head = new_node;
            return;
        }

        Node *current = head;
        // Move node until we are at the last element
        while (current->next != nullptr)
            current = current->next;

        // next element based on current which now is the element before nullpoint is going 
        //to be a node with value given with pointer to nullpoint.
        current->next = new Node{val, current, nullptr};
    }

    /**
     * @brief Print values in the list
     *
     */
    void print()
    {
        std::cout << "[";
        if (head != nullptr)
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                std::cout << current->value;
                std::cout << ", ";
                current = current->next;
            }
            std::cout << current->value;
        }
        std::cout << "]\n";
    }

    /**
     * @brief Get value at a given index
     *
     * @param index The index
     * @return int& Reference to the value at that index
     */
    int &operator[](int index)
    {
        check_index_out_of_bounds(index);
        Node *current = find_node_at_index(index);
        return current->value;
    }

    /**
     * @brief Add element to the beginning of the list
     *
     * @param val The value to be added
     */
    void push_front(int val)
    {
        head = new Node{val, nullptr, head};
        head->prev = nullptr;
        _size++;
    }


    /***
     * @brief Add element to index chosen
     * 
     * @param val The value to be added
     * @param index The index
    */
    void insert(int val, int index)
    {
        if(index == 0)
        {
            push_front(val);
            return; 
        } 

        if (index == _size - 1)
        {
            append(val);
            return;
        }

        //if currents previous node was not a nullpointer (current not a head), the next node will be the new node
        else
        {
            //find the current node at chosen index
            Node *current = find_node_at_index(index-1);
            
            // define next to be current nodes next node (same as before)
            Node *next =  current->next;

            // Set the next node to be a new node with current node as previous node and next node to 
            // be the same as what was currents next node before we implemented the new node.
            current->next = new Node{val, current, next};
            _size++;
            return;
        }
    }

     /**
     * @brief deletes the element at given index from the Linked list.
     * 
     * @param index The index.
     *  
    */
    void remove(int index)
    {
        Node *current = find_node_at_index(index);
        if (index == 0)
        {
            std::cout << "\n else successful \n";
            head = current->next;
            current->prev = nullptr;
        }

        if(current->next != nullptr)
        {   
            Node *prev = find_node_at_index(index - 1);
            prev->next = find_node_at_index(index + 1);
            return;
        }
        else
        {
            tail = current->prev;
            tail->next=nullptr;
            return;
        } 
        //sletter current siden ingenting peker på den nå.
        delete current;

        _size--;
    }

    /***
     * @brief removing element at index given
     * 
     * @param index
     * @return int the value at that index
    */
    int pop(int index)
    {
        Node *current = find_node_at_index(index);
        remove(index);
        return current->value;
    }

    /**
     * @brief removing last element in the list
     * 
     * @return int the last element
    */
    int pop()
    {

        remove(_size - 1);
        return tail->value;
    }
};