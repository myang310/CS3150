// Assignment # 3

// 1
a) m, n, r
b) m, n
c) bObj, dObj
	bObj.demoFunc();
	((baseCL) dObj).demoFunc();
   dObj
   	dObj.demoFunc();

// 2
baseCL constructor
baseCL constructor
derivedCL constructor
derivedCL destructor
baseCL destructor
baseCL destructor

// 3
template <typename T>
class Node {
public:
T nodeValue;
Node<T> *next;
Node (const T& item, Node<T> *ptr = NULL): nodeValue(item), next(ptr) {}
};

template<class T>
class Queue {
	public:
		Queue() : head(NULL), tail(NULL), size(0) {}

		void push(const value_type& val) {
			Node* node = new Node<T>(val);
			if (head == NULL) {
				head = tail = node;
				size += 1;
			}else {
				tail->next = node;
				size += 1;
			}
		}

		T pop() {
			T val = head->nodeValue;
			Node* pastHead = head;
			head = head->next;
			delete pastHead;
			size -= 1;
			return val;
		}

		bool empty() {
			if (size > 0) return false;
			return true;
		}

		int size() {
			return size;
		}

		T front() {
			return head->nodeValue;
		}

		T back() {
			return tail->nodeValue;
		}


	private:
		Node* head;
		Node* tail;
		int size;
}

template<class T>
class DerivedQueue : public Queue {
	public:
		DerivedQueue() : Queue() {}

		void emergency_push(const value_type& val) {
			Node* node = new Node<T>(val);
			if (head == NULL) {
				head = tail = node;
				size += 1;
			}else {
				node->next = head;
				head = node;
				size += 1;
			}
		}
}

// 4
r->displayEmployeeInfo();
Name: Johns Ross
Social Security Number: 896-54-3217
Status: hourly employee
Payrate: $7.50
Work schedule (hours per week): 40

q->displayEmployeeInfo();
Name: Steve Howard
Social Security Number: 896-54-3217
Status: salaried employee
Salary per week $3330.00

q->employee::displayEmployeeInfo();
Name: Steve Howard
Social Security Number: 896-54-3217

p->displayEmployeeInfo();
Name: Steve Howard
Social Security Number: 896-54-3217
Status: salaried employee
Salary per week $3330.00
