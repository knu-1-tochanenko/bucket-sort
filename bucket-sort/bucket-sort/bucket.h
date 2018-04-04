#pragma once

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class BucketSort {
private:
	struct List {
		char data;
		List* next = NULL;
		List* child_lists = NULL;

		void update(char data, List* next, List* child_lists);
		void update(char data, List* next);
		void update_next(List* next);
		void add_child(char data);
		List* take_data_link(char data);
	};

	List* head_element = NULL;
	void print_list(List* element, string str);

public:
	BucketSort();
	
	void add_string(string str_to_add);
	void print_all();
};
