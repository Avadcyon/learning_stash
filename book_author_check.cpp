#include <iostream>
#include <string>
#include <fstream>
#include <set>
using namespace std;
struct Book {
	string name;
	string date;
	string author;
};
void condition_check(Book* info, string our_author,int count_of_books) {
	set<string> valid_dates = { "1980","1981","1982","1983","1984","1985" };
	for (int i; i < count_of_books; i++) {
		if (valid_dates.count(info->date) > 0) {
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
	condition_check(books,author_name,size);
}
