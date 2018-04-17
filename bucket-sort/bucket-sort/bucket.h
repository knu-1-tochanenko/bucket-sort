#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class BucketSort {
private:
	struct Bucket {
		char data;
		Bucket * child;
		Bucket * next;

		void make_child();
		void copy(Bucket * bucket);

	};

	Bucket * head;

	void print_bucket(string prev_str, Bucket * bucket);

public:

	BucketSort();
	
	void add_element(string element);
	void print();
	void start();

};
