#include "/home/nthieu6/ClionProjects/Algorithm/tasks/TaskB.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

namespace jhelper {

struct Test {
	std::string input;
	std::string output;
	bool active;
};

bool check(std::string expected, std::string actual) {
	while(!expected.empty() && isspace(*--expected.end()))
		expected.erase(--expected.end());
	while(!actual.empty() && isspace(*--actual.end()))
		actual.erase(--actual.end());
	return expected == actual;
}

} // namespace jhelper

int main() {
	std::vector<jhelper::Test> tests = {
		{"2\n1 2 3 4 5 6\n", "5\n", true},
	};
	bool allOK = true;
	int testID = 0;
	for(const jhelper::Test& test: tests ) {
		std::cout << "Test #" << ++testID << std::endl;
		std::cout << "Input: \n" << test.input << std::endl;
		std::cout << "Expected output: \n" << test.output << std::endl;
		if (test.active) {
			std::stringstream in(test.input);
			std::ostringstream out;
			TaskB solver;
			solver.solve(in, out);
			std::cout << "Actual output: \n" << out.str() << std::endl;
			bool result = jhelper::check(test.output, out.str());
			allOK = allOK && result;
			std::cout << "\nResult: " << (result ? "OK" : "Wrong answer") << std::endl;
			std::cout << "\n----------------------------------------------";
		}
		else {
			std::cout << "SKIPPED\n";
		}

		std::cout << std::endl;

	}
	if(allOK) {
		std::cout << "All OK" << std::endl;
	}
	else {
		std::cout << "Some cases failed" << std::endl;
	};
	return 0;
}
