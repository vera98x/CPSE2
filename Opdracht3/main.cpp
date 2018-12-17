#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <map>
#include <functional>


class end_of_file : public std::exception {
};


std::map<std::string, int> input_read_to_map(std::ifstream & input) {
	std::map<std::string, int> wordMap;
	std::string word = "";
	std::vector<char> v = {};
	while (input >> word) {
		if (wordMap.count(word) > 0) {
			wordMap[word] += 1;
		}
		else {
			wordMap.insert({ word, 1 });
		}
	}
	return wordMap;
}

std::vector<char> input_read(std::ifstream & input) {
	char c;
	std::vector<char> v = {};
	while (input.get(c)) {
		v.push_back(c);
	}
	return v;
}

template <typename T>
std::ofstream & operator<<(std::ofstream & input, const std::vector<T> & rhs) {
	input << '[';
	for (unsigned int i = 0; i < rhs.size(); i++) {
		input << rhs[i] << ',';
	}
	input << ']';

	return input;
}

struct mapTypeMin {
	std::string minS;
	int minI;
};

mapTypeMin newMin(std::map<std::string, int> & mostCommon) {

	std::string minS;
	int minI = 0;

	for (auto elem : mostCommon) {
		minI = elem.second;
		break;
	}

	for (auto elem : mostCommon) {
		if (elem.second < minI) {
			minS = elem.first;
			minI = elem.second;
		}
	}

	return (mapTypeMin{ minS, minI });
}

template<typename A, typename B>
std::pair<B, A> flip_pair(const std::pair<A, B> &p)
{
	return std::pair<B, A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B, A, std::greater<B> > flip_map(const std::map<A, B> &src)
{
	std::multimap<B, A, std::greater<B> > dst;
	std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), flip_pair<A, B>);
	return dst;
}


int main(int argc, char *argv[]) {
	std::cout << "Starting application 01-02 static ball\n";
	std::cout << "test\n";

	std::ifstream input("KingJames.txt");
	std::vector<char> inputVector;
	try {

		inputVector = (input_read(input));
		input.close();
		std::cout << "reading done\n";
		std::cout << "go in vector\n";
		std::cout << (inputVector.size());
		std::cout << "vector done \n";
		int counterLines = 0;
		int counterAlpha = 0;

		std::for_each(inputVector.begin(), inputVector.end(),
			[&counterLines](auto& item) -> void {if (item == '\n') { counterLines++; }});

		std::cout << counterLines << "\n";

		std::for_each(inputVector.begin(), inputVector.end(),
			[&counterAlpha](auto& item) -> void {if (isalpha(item)) { counterAlpha++; }});

		std::cout << counterAlpha << "\n";


		std::for_each(inputVector.begin(), inputVector.end(),
			[](auto& item) -> void {if (item >= 'A' && item <= 'Z') { item = (item - 'A' + 'a'); }});

		std::cout << inputVector[8] << "\n"; // proof : G went to g
		std::array<std::array<unsigned int, 2>, 26> alphabetcounter = { { 0, 0 } };
		
		std::for_each(inputVector.begin(), inputVector.end(),
			[&alphabetcounter](auto& item) -> void {
			if (item >= 'a' && item <= 'z') {
				if (alphabetcounter[item % 32-1][0] > 0) {
					alphabetcounter[item % 32-1][0] += 1;
				}
				else { alphabetcounter[item % 32 - 1][1] = item; alphabetcounter[item % 32 - 1][0] = 1;
				}
			}
		});

		for (int i = 0; i < 26; i++) {
			std::cout << char(alphabetcounter[i][1]) << ":	" << alphabetcounter[i][0] << "\n";
		}
		std::cout << "sorting"<< "\n";
		std::sort(alphabetcounter.begin(), alphabetcounter.end());
		std::cout << "sorting done" << "\n";
		for (int i = 0; i < 26; i++) {
			std::cout << char(alphabetcounter[i][1]) << ":	" << alphabetcounter[i][0] << "\n";
		}

		std::cout << "mapping" << "\n";
		std::ifstream input("KingJames.txt");
		std::map<std::string, int> mapping = input_read_to_map(input);
		input.close();
		std::cout << "mapping done" << "\n";
		
		std::multimap<int, std::string, std::greater<int> > mostCommon = flip_map(mapping);

		int i = 0;
		std::cout << "Result!!" << "\n";
		for (auto elem : mostCommon) {
			std::cout<< elem.first << "	" << elem.second << "\n"; 
			i++;
			if (i > 10) {
				break;
			}
		}


		
	}
	catch (end_of_file) {
		input.close();
	}
	
	while (true) {

	}
	std::cout << "Terminating application\n";
	return 0;
}

