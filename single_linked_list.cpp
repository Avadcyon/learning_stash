#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

struct Node {
	string value;
	Node* next;
	Node* prev;
	Node(string other_value) : prev(nullptr), value(other_value), next(nullptr) {}
};
struct SLlist {
	Node* first;
	Node* last;
	SLlist() : first(nullptr), last(nullptr) {}
};

void pushback(SLlist* some_list, string input_string) {
	Node* node = new Node(input_string);
	if (some_list->first == nullptr) {
		some_list->first = node;
		some_list->last = node;
		return;
	}
	some_list->last->next = node;
	some_list->last = node;
}

void poplist(SLlist* some_list) {
	if (some_list->first == nullptr) {
		return;
	}
	Node* selected_node = some_list->first;
	while (selected_node) {
		if (&some_list->first == &some_list->last) {
			delete some_list->last;
			some_list->first = some_list->last = NULL;
			return;
		}
		some_list->first = selected_node->next;
		delete some_list->last;
	}
}

void make_list(SLlist *emptylist, int size) {
	int n = 0;
	string string_value;
	while (n < size) {
		n++;
		cin >> string_value;
		pushback(emptylist, string_value);
	}
}

void print_list(SLlist *filled_list) {
	Node* selected_node = filled_list->first;
	if (filled_list->first == filled_list->last) {
		cout << &selected_node->value << ' ' << selected_node->value << endl;
	}
	while (selected_node->next != NULL){
		cout << &selected_node->value << ' ' << selected_node->value << endl;
		selected_node = selected_node->next;
	}
	cout << &selected_node->value << ' ' << selected_node->value << endl;
}

void add_element(SLlist* some_list,int position, string element) {
	Node* selected_node = some_list->first;
	int current_position = 1;
	string temp, temp1;
	while (selected_node) {
		if (current_position == position) {
			temp1 = selected_node->value;
			selected_node->value = element;
		}
		if (current_position > position) {
			temp = selected_node->value;
			selected_node->value = temp1;
			temp = temp1;
		}
		selected_node = selected_node->next;
		current_position++;
	}
}

void delete_element(SLlist* some_list, int position) {
	Node* selected_node = some_list->first;
	int current_position = 1;
	string temp, temp1;
	while (selected_node) {
		if (current_position == position) {
			while (selected_node->next != some_list->last){
				selected_node->value = selected_node->next->value;
				selected_node = selected_node->next;
				current_position++;
			}
			selected_node->value = selected_node->next->value;
			selected_node->next = NULL;
			return;
		}
		selected_node = selected_node->next;
		current_position++;
	}
}

void menu(SLlist* listxd) {
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
	SLlist listxd;
	menu(&listxd);
}
