using namespace std;

//struct stores single node
struct single_node {
	int value;
	single_node *next;
	single_node()
		: value(0), next(nullptr) {}
	single_node(int value_in)
		: value(value_in), next(nullptr) {}
};

class linked_list {

	//constructors
	linked_list() {
		head = new single_node(0);
	}
	linked_list(int value_in) {
		head = new single_node(value_in);
	}

	//returns value of node at index (linked list is zero indexed)
	int get(int index) {
		int counter = 0;
		single_node* current = new single_node();
		current = head;
		while (current->next != nullptr) {
			if (index == counter) {
				return head->value;
			}
			current = current->next;
		}
		return -1;
	}

private:
	single_node *head;
};