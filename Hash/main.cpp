#include "../FSProject/List.h"
#include "Dictionary.h"
#include <iostream>
#include <string>
#include <vector>




int main(void) {
	Dictionary<std::string, int> dictionary;

	dictionary.Insert("A", 0);
	dictionary.Insert("B", 1);
	dictionary.Insert("C", 2);


	return 0;
}
