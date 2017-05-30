#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


using std::string;

void wordCounting()
{
	std::unordered_map<string, size_t> word_count;
	for (string word; std::cin >> word; ++word_count[word]);
	for (const auto &um : word_count)
		std::cout << um.first << " occurs " << um.second << (um.second > 1 ? " times " : " time ") << std::endl;
}

void wordTransformation()
{
	std::ifstream to_trans("to_trans.txt"), rule("rule.txt");
	std::unordered_map<string, string> trans_map;
	for (string key, value; rule >> key && getline(rule, value);)
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw std::runtime_error("no rule for " + key);
	for (string text, word; getline(to_trans, text); std::cout << std::endl)
		for (std::istringstream iss(text); iss >> word;) {
			auto map_it = trans_map.find(word);
			std::cout << (map_it == trans_map.end() ? word : map_it->second) << " ";
		}
}
int main()
{
	wordTransformation();
	system("pause");
	return 0;
}

