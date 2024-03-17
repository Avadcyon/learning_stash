#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Book {
	string name;
	string date;
	string author;
};
void condition_check(Book* info, string our_author) {
	for (int i; i < 3; i++) {
		if (info->date == "1980" || info->date == "1983" || info->date == "1982" || info->date == "1983" || info->date == "1984" || info->date == "1985") {
			if (info->author == our_author) {
				cout << info->name;
			}
		}
	}
}
int main() {
	string author_name;
	int size;
	cout << "Введите размер спика книг";
	cin >> size;
	Book *books = new Book[size];
	cout << "Введите имя автора";
	cin >> author_name;
	condition_check(books,author_name);
}
