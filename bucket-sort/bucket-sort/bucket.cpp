#include "bucket.h"

void BucketSort::List::update(char data, List * next, List * child_lists) {
	
	this->data = data;
	this->next = next;
	this->child_lists = child_lists;
}

void BucketSort::List::update(char data, List * next) {
	
	this->data = data;
	this->next = next;
}

inline void BucketSort::List::update_next(List * next) {
	this->next = next;
}

void BucketSort::List::add_child(char data) {
	
	List* new_child;
	List* point = this->child_lists;

	if (this->child_lists == NULL) {
		new_child = new List;
		new_child->update(data, NULL, NULL);
		this->update(this->data, this->next, new_child);
		return;
	}

	if (this->child_lists->next == NULL) {
		if (this->child_lists->data < data) {
			new_child = new List;
			new_child->update(data, NULL, NULL);
			this->child_lists->update_next(new_child);
		}
		else {
			new_child = new List;
			new_child->update(data, this->child_lists, NULL);
		}
	}

	while (point != NULL && (point->data < data))
		point = point->next;
	if (point == NULL) {
		point = this->child_lists;
		while (point->next != NULL)
			point = point->next;
		new_child = new List;
		new_child->update(data, point->next, NULL);
		point->update_next(new_child);
	}
	else if (point->data < data) {
		point = this->child_lists;
		while (point->next->data < data)
			point = point->next;
		new_child = new List;
		new_child->update(data, point->next, NULL);
		point->update_next(new_child);
	}
	else {
		return;
	}
}

BucketSort::List* BucketSort::List::take_data_link(char data) {
	List* cur_element = this;

	while (cur_element != NULL && (cur_element->data != data)) {
		cur_element = cur_element->next;
	}

	return cur_element;
}

void BucketSort::print_list(List * element, string str) {
	if (element->child_lists != NULL)
		print_list(element->child_lists, str + element->data);
	cout << str + element->data << endl;
	if (element->next == NULL)
		str = str.substr(0, str.size() - 1);
}

BucketSort::BucketSort() {
	head_element = NULL;
}

void BucketSort::add_string(string str_to_add) {
	int start_value = 0;
	if (head_element == NULL) {
		head_element = new List;
		head_element->update(str_to_add[0], NULL, NULL);
		start_value++;
	}
	List* cur_element = head_element;

	if (cur_element->take_data_link(str_to_add[0]) != NULL)
		cur_element = cur_element->take_data_link(str_to_add[0]);

	for (int i = start_value; i < str_to_add.length(); i++) {
		cur_element->add_child(str_to_add[i]);

		if (cur_element->take_data_link(str_to_add[i]) != NULL)
			cur_element = cur_element->take_data_link(str_to_add[i]);
	}
}

void BucketSort::print_all() {
	print_list(head_element, "");
}
