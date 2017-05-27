#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <exception>

using std::map;
using std::string;
using std::cout;
using std::endl;

map<string, string> buildMap(std::ifstream &map_file)
{
	map<string, string> trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw std::runtime_error("no rule for" + key);
	return trans_map;
}
const string& transform(const string &s, const  map<string, string> &m)
{
	auto map_it = m.find(s);
	if (map_it != m.end())
		return map_it->second;
	else
		return s;
}
void word_transform(std::ifstream &map_file, std::ifstream &input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text)) {
		std::istringstream stream(text);
		std::string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main()
{
	std::ifstream rule("rule.txt");
	std::ifstream input("input.txt");
	word_transform(rule, input);
	system("pause");
	return 0;
}