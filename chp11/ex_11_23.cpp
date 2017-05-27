#include <map>
#include <string>
#include <iostream>

int main()
{
	std::multimap<std::string, std::string> families;
	for (std::string lastName, childName; std::cin >> lastName >> childName; families.emplace(lastName, childName));
	for (const auto &mm : families)
		std::cout << mm.first << " " << mm.second << std::endl;
	system("pause");
	return 0;
}