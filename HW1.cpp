// Write a function that returns the number of zeros in a given simple list of numbers.

int zero_count (std::list<int> list) {
	int count = 0;
	for (std::list<int>::iterator iterator = list.begin(); iterator != list.end(); iterator++) {
		if (*iterator == 0) count++;
	}
	return count;
}

// Write a function that takes a simple list of numbers as a parameter and returns a
// list with the largest and smallest numbers in the given list.

std::list<int> find_largest_smallest (std::list<int> list) {
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

}

// Arrays: Write a program that tests if a 2D square array is symmetric about the diagonal 
// from (0,0) to (n-1,n-1). (from EPI)
bool is_diagonal(int (&square)[][n], int n) { 

}

// Stacks and Queues: Write a programt to evaluate arithmetical expressions that use + and * 
// applied to nonnegative integer arguments. Expressions are in reverse-Polish notation, 
// e.g., 3 4 + 5 *, 1 3 + 5 7 + *. (from EPI)
int calculate() {

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

}

// Write a program to find the unique positive integer whose square has the form 
// 1_2_3_4_5_6_7_8_9_0, where each "_" is a single digit. (from Euler)
int find_unique_square() {
	
}
