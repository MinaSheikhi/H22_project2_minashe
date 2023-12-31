# H22_project2_minashe

# IN1910 Project 2 

My repo did not have any release branch. Therefore I was not able to make an open pull request.

- Repo url: https://github.uio.no/IN1910/H22_project2_minashe.git

## Author
- Mina Sheikhi (minashe@mail.uio.no)

## Commands to compile and run the files
I have used the codes from the lectures to do this project. Specialy problem
1,2 and 3.

array_list (problem 1):
	c++ test_array_list.cpp -o array_list --std=c++14


linked_list (problem 2): 
	c++ test_linked_list.cpp -o linked_list --std=c++14

compare_array_list_and_linked_list og plot av filene i den (problem 3):
  c++ compare_array_list_and_linked_list.cpp --std=c++14 -o comp
  py plot_compare.py

linked array list (problem 4): 
  c++ linked_array_list.cpp -o la -std=c++14



# Part 3: Comparing the ArrayList and the LinkedList

## Exercise 3a) Algorithm analysis

ArrayList and LinkedList behave similarly from the outside, but they have 
different performance characteristics.

Given we have n number of elementes in the list and index i, the cost of each 
of following operations on each type of list in Big-Oh notation will be:

- Get element i by index 
  - ArrayList: Total cost is O(1). Since arrays are contiguous in memory, the
                operation is not dependent on list size.
  
  - LinkedList: Total cost is O(n). Linked lists are not stored contiguously in
                memory. Each node can exist in completely different place. 
                Importance is for each node to know where next one is stored. 
                Therefor we have to iterate from tail or head to the index we want.
                It is size dependent.
  
- Insert at front
  - ArrayList: Total cost is O(n). We need to move every other elemenent in
               the list one index up to make space. This is dependent in the 
               size of the list. Then we have to add the element to the fornt
               which requiers one operation. 
  
  - LinkedList: Total cost is O(1). Head pointer points to the first element
                therefore no need to move the element index. The operations
                doesn't depend on the size.


- Insert at back (aka append)
    - ArrayList: Since we only assign the value to the firs unused element
                 of underlying storage the cost is O(1). The cost is not dependent
                 of length of array. Since we have used resize function 
                 which increase the size to 2n when no memory storage is left,
                 the operation can sometimes depend on size of array. 
                 Cost will therefore be O(1) and sometimes O(n).
  
    - LinkedList: Total cost is O(1). Tail pointer points to last element 
                  so we don't need to iterate through the list. Therefore
                  The operation is not dependent on the size.
    

- Insert into middle of list
    - ArrayList: Total cost of O(n - i) where i is the index.
                 We have to move elemets with indices above the index to make room.
                 Therefor it is dependent on the size.
                 
    - LinkedList: Total cost is O(n). Insertion itself has cost O(1) since it is one 
                  one operation. But we have to iterate through the list to find the
                  index the node is connecting to. This operation is size dependent.
                  

- Remove element from back
    - ArrayList: Total cost is O(1). Since arrays are contiguous in memory insert one
                 operation where the size of array decrease. But since we have implemented 
                 shrink to fit method which copy all elements of original array to new array
                 the cost could be size dependent i.e O(n).
                
    - LinkedList: Total cost is O(n). It has to iterate through the list to find the 
                  the last element in the list O(n), then some operations to remove the current
                  node which has cost of O(1). The operation is size dependent.

- Remove element from middle
    - ArrayList: Total cost is O(n). It has to iterate through the list to find the 
                  the index element in the list O(n), then some operations to remove the current
                  node. This has cost of O(1). Then possibly usage of shrink to fit method which 
                  also has cost of O(n). The operation is size dependent.
                 
    - LinkedList: Total cost is O(n). It has to iterate through the list to find the 
                  the index element in the list O(n), then some operations to remove the current
                  node which has cost of O(1). The operation is size dependent.


- Print
    - ArrayList: Total cost is O(n). Because of the for loop list has to iterate from the first 
                 index to the last and print out all the elements. Size dependent.
                 
    - LinkedList: Total cost is O(n). Also here the list has to iterate from the head
                  through the list and print out each element. Size dependent. 

## Exercise 3b) Timing your implementation

Write down the expression for the run time in the readme file.

We see that ArrayList(get) has O(1), ArrayList(insert) has O(n), LinkedList(get) has O(n), and 
LinkedList(insert) has O(1) cost. This seems reasonable.
