all: array_list linked_list

linked_list: linked_list.cpp test_linked_list.cpp
	c++ test_linked_list.cpp -o linked_list --std=c++14

array_list: array_list.cpp test_array_list.cpp
	c++ test_array_list.cpp -o array_list --std=c++14

compare_array_list_and_linked_list.cpp: 
	c++ compare_array_list_and_linked_list.cpp -o comp

clean:
	rm -f array_list linked_list