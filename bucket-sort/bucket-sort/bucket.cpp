#include "bucket.h"

void BucketSort::print_bucket(string prev_str, Bucket * bucket) {
	if (bucket == NULL) {
		prev_str = prev_str.substr(0, prev_str.size() - 1);
		cout << prev_str << endl;
	}
	else {
		print_bucket(prev_str + bucket->data, bucket->child);
		if (bucket->next != NULL) {
			print_bucket(prev_str, bucket->next);
		}
	}
}

BucketSort::BucketSort() {
	head = new Bucket();
	head->data = 'a';
	head->child = NULL;
	head->next = NULL;

	Bucket *last_element = head;

	for (int i = 1; i < 26; i++) {
		Bucket * new_element = new Bucket();
		new_element->data = (char)('a' + i);
		new_element->child = NULL;
		last_element->next = new_element;
		last_element = new_element;
	}

}

void BucketSort::add_element(string element) {
	transform(element.begin(), element.end(), element.begin(), ::tolower);

	Bucket * current_layer = head;

	for (int i = 0; i < element.length(); i++) {
		char current_char = element[i];

		if (current_layer->data == 'Z') {
			current_layer->data = current_char;
			current_layer->make_child();

			current_layer = current_layer->child;
		}
		else {
			Bucket * sub_bucket = current_layer;
			while ((sub_bucket->next != NULL) && (sub_bucket->data < current_char))
				sub_bucket = sub_bucket->next;

			if (sub_bucket->data == current_char) {
				// If current bucket has the same value as the string[i]
				if (sub_bucket->child == NULL) {
					
					sub_bucket->make_child();
					
					current_layer = sub_bucket->child;
					continue;
				}
				else {
					current_layer = sub_bucket->child;
					continue;
				}
			}
			else if (sub_bucket->data < current_char) {
				Bucket * new_current_layer = new Bucket();
				
				new_current_layer->next = sub_bucket->next;
				sub_bucket->next = new_current_layer;
				new_current_layer->data = current_char;
				
				new_current_layer->make_child();
				
				current_layer = new_current_layer->child;
				continue;
			}
			else {
				Bucket * new_current_layer = new Bucket();
				new_current_layer->copy(sub_bucket);
				sub_bucket->data = current_char;
				sub_bucket->next = new_current_layer;
				sub_bucket->make_child();


				current_layer = sub_bucket->child;
				continue;
			}
		}

	}

}

void BucketSort::print() {
	system("cls");
	Bucket * cur = head;
	for (int i = 0; i < 26; i++) {
		if (cur->child != NULL) {
			string str = "";
			str += cur->data;
			print_bucket(str, cur->child);
		}
		cur = cur->next;
	}
}

void BucketSort::start() {
	while (1) {
		system("cls");
		
		string str;
		cout << "Write string : ";
		cin >> str;
		add_element(str);
		
		cout << "Continue? 1/0 : ";
		int n;
		cin >> n;
		if (n == 0)
			break;
	}
}

void BucketSort::Bucket::make_child() {
	this->child = new Bucket();
	this->child->child = NULL;
	this->child->next = NULL;
	this->child->data = 'Z';
}

void BucketSort::Bucket::copy(Bucket * bucket) {
	this->data = bucket->data;
	this->next = bucket->next;
	this->child = bucket->child;
}
