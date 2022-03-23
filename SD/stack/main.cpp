#include <iostream>
#include "stack.h"

std::string infix_to_postfix(std::string input) {
	// Create a 256-sized array for mapping any char.
	int prec[1 << 8] = { 0 };

	// Any other symbols have least precedence
	prec['+'] = 1;
	prec['-'] = 2;
	prec['*'] = 3;
	prec['/'] = 4;

	// Initialize an empty stack and an empty string.
	stack<char> st;
	std::string output;

	// Traverse the string and process each character according to the
	// postfix algorithm.
	for (size_t i = 0; i < input.length(); ++i) {
		char current = input[i];

		// Found a digit
		if (current >= '0' && current <= '9') {
			output += current;
		}
		else if (current == '(') {
			// Found an open paranthesis
			st.push(current);
		}
		else if (current == ')') {
			// Found a closed paranthesis
			while (st.top() != '(') {
				output += st.pop();
			}
			st.pop();
		}
		else {
			// Found an operator
			while (!st.empty() && prec[st.top()] >= prec[current]) {
				output += st.pop();
			}
			st.push(current);
		}
	}

	// Output remaining operators
	while (!st.empty()) {
		output += st.pop();
	}

	return output;
}

int main()
{
	std::string input, output;
	std::cin >> input;
	output = infix_to_postfix(input);
	std::cout << output;
}
