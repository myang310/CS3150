// Assignment # 4

// 1
a) n, r
b) m, n
c) 	bObj.demoFunc() calls BaseCL.demoFunc();
	dObj.demoFunc() calls DerivedCL.demoFunc();

// 2
class Queue<T> {
	Node<T> head;
	Node<T> tail;
	int size;

	public Queue() {
		head = null;
		tail = null;
		size = 0;
	}

	void push(T data) {
		Node<T> node = new Node<T>(data);
		if (this.empty())
			head = node;
		else {
			tail.next = node;
		tail = node;
		size++;
	}

	T pop() {
		T data = head.nodeValue;
		head = head.next;
		size--;
	}

	T front() {
		return head.nodeValue;
	}

	boolean empty() {
		return (head == null);
	}
}

class DerivedQueue<T> extends Queue<T> {
	public DerivedQueue() {
		super.class();
	}

	void emergency_push(T data) {
		Node<T> node = new Node<T>(data, head);
		head = node;
		size++;
	}
}

// 3
r.displayEmployeeInfo();
Name: Johns Ross
Social Security Number: 896-54-3217
Status: hourly employee
Payrate: $7.50 per hour
Work schedule (hours per week) 40

q.displayEmployeeInfo();
Name: Steve Howard
Social Security Number: 896-54-3217
Status: salaried employee
Salary per week $3330.00

p.displayEmployeeInfo();
Name: Steve Howard
Social Security Number: 896-54-3217
Status: salaried employee
Salary per week $3330.00
