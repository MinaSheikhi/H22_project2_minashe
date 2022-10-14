#include <iostream>
#include <stdexcept>
#include <vector>

class ArrayList
{
  private:
    // Array containing the acutaul data in the list
    int *_data;
    // Capacity of the array
    int _capacity = 1;
    // Size of the array
    int _size = 0;


    /**
     * @brief Resize array with a growth factor of 2.
     * Copy all elements of the original array over to
     * the new array and delete the old array.
     *
     */
    void resize()
    {
        _capacity *= 2;
        int *new_data = new int[_capacity];
        for (int i = 0; i < _size; i++)
            new_data[i] = _data[i];

        //delete only deletes 1 object. to delete all of the objects in array add delete[]
        delete[] _data;
        _data = new_data;
    }

  public:
    // Default constructor
    ArrayList()
    {
        _data = new int[_capacity];
    }

    // Constructor for a list of values
    ArrayList(std::vector<int> values)
    {
        if (_capacity < values.size())
            _capacity = values.size();

        _data = new int[_capacity];
        for (int value : values)
            append(value);
    }

    // Destructor
    ~ArrayList()
    {
        delete[] _data;
    }

    // Length of array
    int length()
    {
        return _size;
    }

    /**
     * @brief Append element to the end of the list
     *
     * @param n The value to be appended
     */
    void append(int n)
    {
        if (_size >= _capacity)
            resize();
        _data[_size] = n;
        _size++;
    }

    /**
     * @brief Get value at a given index.
     * Throws a range error in index if out of bounds
     *
     * @param index The index
     * @return int The value at that index
     */
    int get(int index)
    {
        if ((index < 0) || (index >= _size))
        {
            throw std::range_error("Index is out of bounds");
        }
        return _data[index];
    }

    /**
     * @brief Prints the array
     *
     */
    void print()
    {
        std::cout << "ArrayList([";
        for (int i = 0; i < _size - 1; i++)
        {
            std::cout << _data[i] << ", ";
        }
        std::cout << _data[_size - 1] << "])\n";
    }

    /**
     * @brief Get a reference to the value at a given index.
     * Throws a range error if index is out of bounds
     *
     * @param index The index
     * @return int The value at that index
     */
    int &operator[](int index)
    {
        if ((index < 0) || (index >= _size))
        {
            throw std::range_error("Index is out of bounds");
        }
        return _data[index];
    }

    /**
     * @brief get a value and an index.
     * throw an error if index is out of bounds
     * 
     * increase size by 1
     * 
     * move values to the right of index moves one index up.
     * 
     * @param val the value
     * @param index the index
     *  
    */
   void insert(int val, int index)
   {
    if ((index < 0) || (index > _size)){
        throw std::range_error("index is out of bounds");
    }
      
    _size++;

    for (int i = _size; i > index; i--){
        _data[i] = _data[i - 1];
    }

    _data[index] = val;
   }

    /**
     * @brief deletes the element from the list.
     * 
     * @param elem the element
     *  
    */
    void remove(int elem)
    {        
        for (int i = 0; i < _size; i++){
            if (_data[i] == elem)
            {
                for (int j = i; j < _size - 1; j++)
                {
                    _data[j] = _data[j+1]; 
                } 
                _size--;               
            }
            
        }
        
    }

    /***
     * @brief removing element at index given
     * @param index
     * @return the element of index given
    */

    int pop(int index){
        
        for (int i = index; i < _size; i++){
            
        }
    }

    
    int pop(){
        remove(_data[_size - 1]);
        return _data[_size - 1];
    }

};