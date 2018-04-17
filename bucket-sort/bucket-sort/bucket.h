#pragma once

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template <typename BucketType> class BucketSort {
private:
	struct Bucket {
		BucketType data;
		Bucket * child;
		Bucket * next;
	};

	Bucket * head;

public:

	Bucket();
	
	void add_element(string element);
	void print();

};
