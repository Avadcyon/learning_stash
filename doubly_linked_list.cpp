
struct Node {
	Node* prev;
	string value;
	Node* next;
	Node(string other_value) : prev(nullptr), value(other_value), next(nullptr) {}
};
struct DLlist {
	Node* first;
	Node* last;
};

void add_element(DLlist* some_list, int position, string element) {
	Node* ptr_temp_node = new Node(element);
	if (position == 1) {
		some_list->first = ptr_temp_node;
		some_list->last = some_list->first;
	}
	else 
	{
		Node* selected_node = some_list->first;
		int current_position = 1;
		string temp, temp1;
		while (selected_node) {
			if (current_position == position) {
				ptr_temp_node->next = selected_node;
				selected_node->next->prev = ptr_temp_node;
				return;
			}
			if (!(selected_node->next)) {
				selected_node->next = ptr_temp_node;
				ptr_temp_node->prev = selected_node;
				some_list->last = ptr_temp_node;
				return;
			}
			selected_node = selected_node->next;
			current_position++;
		}
	}
}

void print_list(DLlist* some_list) {
	Node* selected_node = some_list->first;
	if (some_list) {
		cout << "null";
		return;
	}
	if (&some_list->first == &some_list->last) {
		cout << &selected_node->value << ' ' << selected_node->value << endl;
	}
	while (selected_node->next != NULL) {
		cout << &selected_node->value << ' ' << selected_node->value << endl;
		selected_node = selected_node->next;
	}
	cout << &selected_node->value << ' ' << selected_node->value << endl;
}

void make_list(DLlist *emptylist, int size) {
	int n = 0;
	string string_value;
	while (n < size) {
		n++;
		cin >> string_value;
		add_element(emptylist, n, string_value);
	}
}

void delete_element(DLlist* some_list, int position) {
	Node* selected_node = some_list->first;
	int current_position = 1;
	string temp, temp1;
	Node* tempnode;
	while (selected_node) {
		if (current_position == position) {
			if (some_list->first == some_list->last) {
				delete selected_node;
				return;
			}
			if (selected_node->next && selected_node->prev) {
				selected_node->next->prev = selected_node->prev;
				selected_node->prev->next = selected_node->next;

			}
			if (selected_node->next && !selected_node->prev) {
				some_list->first = some_list->first->next;
				some_list->first->prev = nullptr;
			}
			if (!selected_node->next && selected_node->prev) {
				some_list->last = some_list->last->prev;
				some_list->last->next = nullptr;
			}
			delete selected_node;
			return;
		}
		selected_node = selected_node->next;
		current_position++;
	}
}

void poplist(DLlist* some_list) {
	if (some_list->first == nullptr) {
		return;
	}
	Node* selected_node = some_list->first;
	while (selected_node) {
		if (some_list->last == some_list->first) {
			delete some_list->last;
			some_list->last = nullptr;
			some_list->first = nullptr;
			return;
		}
		delete_element(some_list, 1);
	}
}


void menu(DLlist* listxd) {
	int point;
	cout << "Введите номер необходимого действия:\n1)Создание списка\n2)Добавление эл-та по индексу\n3)Удаление из списка по индексу\n4)Удаление списка\n5)Вывод списка\n6)Выход из меню\n";
	cin >> point;
	while (point != 6) {
		if (point != 1 && point != 2 && point != 3 && point != 4 && point != 5 && point != 6) {
			cout << "Введите номер необходимого действия";
		}
		if (point == 1) {
			int size;
			cout << "Введите желаемый размер списка";
			cin >> size;
			if (size != 0) {
				cout << "Введите элементы через Enter";
				make_list(listxd, size);
			}
		}
		if (point == 2) {
			int pos;
			string elem;
			cout << "Введите позицию в списке";
			cin >> pos;
			cout << "Введите элемент";
			cin >> elem;
			add_element(listxd, pos, elem);
		}
		if (point == 3) {
			int pos;
			cout << "Введите позицию в списке";
			cin >> pos;
			delete_element(listxd, pos);
		}
		if (point == 4) {
			poplist(listxd);
		}
		if (point == 5) {
			print_list(listxd);
		}
		cout << "Введите номер необходимого действия:\n1)Создание списка\n2)Добавление эл-та по индексу\n3)Удаление из списка по индексу\n4)Удаление списка\n5)Вывод списка\n6)Выход из меню\n";
		cin >> point;
	}
	if (point == 6) {
		cout << "Вы завершили работу со списком";
	}
}


int main() {
	DLlist listxd;
	menu(&listxd);
}
