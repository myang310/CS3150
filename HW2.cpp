// Ming Yang
// Assignment # 2 - Review of STL

// Write a function that returns the number of zeros in a given simple list of numbers.

int zero_count (std::list<int> list) {
	// Keep count of the number of zeroes in the list by checking each number in the list
	// to see if it is zero is not. If so, increment counter. Otherwise, do nothing.
	int count = 0;
	for (std::list<int>::iterator iterator = list.begin(); iterator != list.end(); iterator++) {
		if (*iterator == 0) count++;
	}
	return count;
}

// Write a function that takes a simple list of numbers as a parameter and returns a
// list with the largest and smallest numbers in the given list.

std::list<int> find_largest_smallest (std::list<int> list) {
	// Run through the list once and keep track of the most current largest and smallest #
	int largest = list.front();
	int smallest = list.front();
	for (std::list<int>::iterator iterator = list.begin() + 1; iterator != list.end(); iterator++) {
		if (*iterator > largest) largest = *iterator;
		else if (*iterator < smallest) smallest = *iterator;
	}
	std::list<int> result;
	result.push_back(largest).push_back(smallest);
	return result;
}

// Write a function that takes an integer n as a parameter and prints the first n rows 
// of the Pascal's triangle.

void print_pascal (int n) {
	// If the given n is not at least 1, then no rows of Pascal's triangle will print
	if (n >= 1) {
		std::cout << "1" << std::endl;

		// Chose to use a queue as you determine the numbers of Pascal's triangle
		// by summing pairs of numbers in the row above. A queue allows for the
		// previous row of numbers to be summed in order to attain the current row,
		// and for the current row of numbers to be added to the back of the queue.
		std::queue<int> queue;
	} 

	// For each row of Pascal's triangle, print the 1s on the ends and store those
	// 1s and all the numbers in between in order in the queue. This allows for the
	// augend to be popped and the addend to be read, but popped in the following
	// operation.
	for (int i = 1; i < n; i++) {
		queue.push(1);
		std::cout << "1 ";

		// 
		for (int j = 0; j < i - 2; j++) {
			int first = queue.pop();
			int second = queue.front();
			int sum = a + b;
			queue.push(sum);
			std::cout << sum << " ";
		}
		queue.pop();

		queue.push(1);
		std::cout << "1" << std::endl;
	}
}

// Arrays: Write a program that tests if a 2D square array is symmetric about the diagonal 
// from (0,0) to (n-1,n-1). (from EPI)
bool is_diagonal(int** square, int n) {
	// Check for equality between the left side of the diagonal and the top side. Check from
	// left to right on the left side and top to bottom on the top side. If at any point,
	// there's an inequality, return false. Otherwise, it will return true.
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (square[i][j] != square[j][i]) 
				return false;
		}
	}

	return true;

}

// Stacks and Queues: Write a program to evaluate arithmetical expressions that use + and * 
// applied to nonnegative integer arguments. Expressions are in reverse-Polish notation, 
// e.g., 3 4 + 5 *, 1 3 + 5 7 + *. (from EPI)
int calculate(std::string expression) {
	// Place the expression into a string stream to separate the expression
    std::string buffer;
    std::stringstream ss(expression);

    std::stack<std::string> stack;

    // While strings are being extracted from the stream, check if they are numbers or
    // operators. If it's a number, add it to the stack. Otherwise, pop the last two
    // numbers from the stack and perform the appropriate calculation. Then place the
    // result back into the stack.
    while (ss >> buf) {
    	switch(buf) {
    		case "+":
    			int a = std::stoi(stack.pop());
    			int b = std::stoi(stack.pop());
    			stack.push(std::to_string(a + b));
    			break;
    		case "*":
    			int a = std::stoi(stack.pop());
    			int b = std::stoi(stack.pop());
    			stack.push(std::to_string(a * b));
    			break;
    		default:
    			stack.push(buf);
    			break;
    	}
    }

    // The last number in the stack should be the result of the whole expression
    return std::stoi(stack.pop());
}

// Hash tables: Write a program that finds the most common object in an array of objects. 
// Each object is a pair of strings. Treat strings as being the same if they are equal 
// when converted to lower case. (from EPI)
class pair_strings {
	public:
		bool operator==(pair_strings pairs) {
			std::string a, b;
			std::transform(this->first.begin(), this->first.end(), a.begin(), ::tolower);
			std::transform(this->second.begin(), this->second.end(), a.begin(), ::tolower);
			std::transform(pairs.first.begin(), pairs.first.end(), b.begin(), ::tolower);
			std::transform(pairs.second.begin(), pairs.second.end(), b.begin(), ::tolower);

			if (a.first == b.first && a.second == b.second) 
				return true;
			else if (a.first == b.second && a.second == b.first) 
				return true;
			else 
				return false;
		}

	private:
		std::string first;
		std::string second;
}

pair_strings find_most_common(pair_strings objects[], int n) {
	std::unordered_map<pair_strings, int> string_map; // Use a hash table to track frequencies

	// Add each new pair_strings object into the hash table. Set the pair_strings as the key
	// and 1 as the starting value. Increment it's value if it's already in the hash table.
	for (int i = 0; i < n; i++) {
		std::pair<std::iterator, bool> pair = string_map.insert(objects[i], 1);
		bool not_new = std::get<bool>(pair);

		if (not_new) {
			string_map.at(objects[i]) += 1;
		}
	}

	// Iterate through the hash table and search for the key with the largest value
	// keeping the largest found thus far in tracking values, max and most_common.
	int max = 1;
	pair_strings most_common;
	for (std::unordered_map<pair_strings, int>::iterator iterator = string_map.begin(); 
		iterator != string_map.end(); 
		iterator++) {
		if (it->second > max) {
			max = it->second;
			most_common = it->first;
		}
	}

	return most_common;
}

// Write a program to find the unique positive integer whose square has the form 
// 1_2_3_4_5_6_7_8_9_0, where each "_" is a single digit. (from Euler)
int find_unique_square() {
	// Logic: 
	// In order to have a 0 as the last digit, the square root has to end in 0
	// as well, meaning the last two digits are both 0 (1_2_3_4_5_6_7_8_9 left).
	// In order for the last digit to be 9, the square root of it must be either
	// 3 or 7 in order to get 9 or 49 as the square.
	// The number must be between 101,010,101 and 138,902,6623 to cover the range
	// of possible squares.
	long long i = 101010103;
	while (i < 1389026623) {
		long long square = i * i;
		int expected = 9; // the current end number to match
		while (square > 0) {
			// Check if the last digits match. If not, move on to the next number
			int digit = (int)(square % 10);
			if (digit != expected) 
				break;
			// Otherwise, try the next number - truncating off the last 2 digits
			else {
				square /= 100;
				expected--;
			}
		}
		// If has found all the necessary digits, return the original number
		if (expected == 0)
			return (int) i;
		// Otherwise, try out the next number ending with a 3 or a 7
		else {
			if (i % 10 == 3) 	i += 4; // increments i to end in 7
			else 				i += 6; // increments i to end in 3
		}
	}
	return -1;
}