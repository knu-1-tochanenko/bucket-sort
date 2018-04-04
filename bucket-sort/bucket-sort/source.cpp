#include "bucket.h"

int main() {
	BucketSort mysort;
	mysort.add_string("fuck");
	mysort.add_string("no");
	mysort.print_all();
	system("pause");
}