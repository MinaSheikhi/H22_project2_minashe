#include <iostream>
#include <stdexcept>
#include <vector>

struct Node
{
    // The value at the node
    int value;
    // Pointer to the next node
    Node *next = nullptr;
};

class LinkedList
{
  private:
    // Pointer to the first element in the list
    Node *head = nullptr;
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
            next = current->next;
            delete current;
            current = next;
        }
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

        current->next = new_node;
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
        head = new Node{val, head};
        _size++;
    }
};