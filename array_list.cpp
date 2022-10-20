#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>

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

    /***
     * @brief replace underlying storage array with smallest
     * capacity 2^n. 
     * Copy all elements of original array over to the new 
     * arrat and delete old array.
    */

    void shrink_to_fit()
    {
        for (int n = 0; pow(2,n) < _size; n++)
        {
            _capacity = pow(2, n+1);

        }

        int *new_data = new int[_capacity];

        for (int i = 0; i < _size; i++)
        {
             new_data[i] = _data[i];           
        }

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

    //capacity of array
    int capacity()
    {
        return _capacity;
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
        std::cout << "[";
        for (int i = 0; i < _size - 1; i++)
        {
            std::cout << _data[i] << ", ";
        }
        std::cout << _data[_size - 1] << "]\n";
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

   if (_size >= _capacity)
    {   
        resize();
    }
    
    if (index == _size)
    {
        append(val);
        return;
    } 
    
 
    for (int i = _size; i > index; i--){
       _data[i] = _data[i - 1];
    }

        _data[index] = val;
        _size++;
      
   }

    /**
     * @brief deletes the element from the list.
     * 
     * @param index the index
     *  
    */
    void remove(int index)
    {        
        for (int i = index; i < _size - 1; i++)
        {
           _data[i] = _data[i + 1];
        }
        _size--;

         //shrinking the array to fit if less than 25% of allocated capacity is used
        if ( _size <  0.25*_capacity) 
        {
            shrink_to_fit();
        }
    }

    /***
     * @brief removing element at index given
     * 
     * @param index
     * @return int the value at that index
    */

    int pop(int index){
        
        int old_value = _data[index];

        for (int i = index; i < _size - 1; i++){
            _data[i] = _data[i + 1];            
        }
        _size--;

         //shrinking the array to fit if less than 25% of allocated capacity is used
         if (_size < 0.25*_capacity) 
        {
            shrink_to_fit();
        }
        return old_value;
    }

    /**
     * @brief removing last element in the list
     * 
     * @return int the last element
    */
    
    int pop(){
        
        int old_value = _data[_size - 1];
        _size--;

        //shrinking the array to fit if less than 25% of allocated capacity is used
         if ( _size < 0.25*_capacity) 
        {
            shrink_to_fit();
        }
        return old_value;
  
    }
};