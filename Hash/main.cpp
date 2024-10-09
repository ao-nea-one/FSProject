#include "../FSProject/List.h"
#include "Dictionary.h"
#include <iostream>
#include <string>
#include <vector>


size_t hash(const std::string &key) {
	return std::hash<std::string>()(key);
}

int main(void) {
	Dictionary<std::string, int, 2, hash> dictionary;

	dictionary.Insert("A", 0);
	dictionary.Insert("B", 1);
	dictionary.Insert("C", 2);
	dictionary.Remove("C");

	int i = -1;

	dictionary.Find("A", i);

	std::cout << i << std::endl;

	return 0;
}
