#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
/*
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <array>
#include <vector>
*/
/*
idz 4a9

int main() {
	double x, a, tmp;
	tmp = 1;
	cout << "enter x, enter a" << endl;
	cin >> x >> a;
	if (a <= 0) { cout << "a is invalid" << endl;}
	else{
		if (x <= 1 and x > a and x > 0) {
			for (int i = 1; ; i++) {
				tmp *= x;
				if (abs(tmp / i) < a) {
					cout << "pobeda, k =" << i << endl;
				}
			}
		}
		else if (x > a and x > 1) {
			int flag = 0;
			for (int i = 1; i < 10; i++) {
				tmp *= x;
				if (abs(tmp / i) < a) {
					cout << "pobeda, k =" << i << endl;
					break;
					flag = 1;
				}
			}
			if (flag == 0) {
				cout << "x and a is incorrect";
			}
		}
		if(x < a) {
			cout << "1" << endl;
		}
	}
}


1

int main() {
	double x, y;
	cin >> x >> y;
	if (abs(x) + abs(y)) < 1 {
		cout << "the dot is in the area";
	}
	else {
		cout << "the dot is not in the area";
	}
}

2

double factorial(int x) {
	if (x < 0) {
		return 0;
	}
	if (x == 0) {
		return 1;
	}
	else {
		return x * factorial(x - 1);
	}
}
double suml(int k) {
	double sum = 0;
	for (int l = 2; l < k+1; l++) {
		sum = sum + pow(l, -1);
	}
	return sum;
}
double func(int n) {
	double res,chlen;
	if (n <= 0) {
		return 0;
	}
	if (n == 1) {
		return 1 / pow(2, -1);
	}
	if (n >= 1) {
		res = factorial(n) / suml(n) + func(n - 1);
	}
}

int main() {
	int n;
	cin >> n;
	cout << func(n);
}


3

double factorial(int x) {
	if (x < 0) {
		return 0;
	}
	if (x == 0) {
		return 1;
	}
	else {
		return x * factorial(x - 1);
	}
}
double func(double x, double epsilon, int n = 0) {
	double chlen = pow(-1, n) * pow(x, 2 * n) / factorial(n);
	if (abs(chlen) <= epsilon) {
		return 0;
	}
	else {
		return chlen + func(x,epsilon,n+1);
	}
}
int main() {
	double eps, x;
	int n;
	cout << "enter eps,x"<< endl;
	cin >> eps;
	cin	>> x;
	double answer = func(x, eps);
	cout << answer;
}


idz 4b13
 
int main() {
    int i, j,str;
    char st;
    cout << "Pered vami - shahmatnaya doska, razmestite konya:" << endl;
    char nums[8] = { '1','2','3','4','5','6','7','8' };
    char doska[8][8] = {
        {' ','*',' ','*',' ','*',' ','*'},
        {'*',' ','*',' ','*',' ','*',' '},
        {' ','*',' ','*',' ','*',' ','*'},
        {'*',' ','*',' ','*',' ','*',' '},
        {' ','*',' ','*',' ','*',' ','*'},
        {'*',' ','*',' ','*',' ','*',' '},
        {' ','*',' ','*',' ','*',' ','*'},
        {'*',' ','*',' ','*',' ','*',' '}, };
    cout << " abcdefgh" << endl;
    for (int i = 0; i < 8; i++) {
        cout << nums[i];
        for (int j = 0; j < 8; j++) {
            cout << doska[i][j];
        }
        cout << endl;
    }
    cout << "vvedite bukvu stolbca:";
    cin >> st; 
    switch (st) {
    case 'a':
        st = 0;
        break;
    case 'b':
        st = 1;
        break;
    case 'c':
        st = 2;
        break;
    case 'd':
        st = 3;
        break;
    case 'e':
        st = 4;
        break;
    case 'f':
        st = 5;
        break;
    case 'g':
        st = 6;
        break;
    case 'h':
        st = 7;
        break;
    default:
        cout << "stolbec is invalid" << endl;
        break;
    }
    cout << "vvedite nomer stroki:";
    cin >> str;
    if (str > 8 || str < 1) {
        cout << "str is invalid" << endl;
    }
    str = str - 1;
    doska[str][st] = 'K';
    if (str + 2 < 8 and st + 1 < 8) {
        doska[str + 2][st + 1] = 'X';
    }
    if (str + 2 < 8 and st - 1 > 0) {
        doska[str + 2][st - 1] = 'X';
    }
    if (str - 2 > 0 and st + 1 < 8) {
        doska[str - 2][st + 1] = 'X';
    }
    if (str - 2 > 0 and st - 1 > 0) {
        doska[str - 2][st - 1] = 'X';
    }
    if (str + 1 < 8 and st + 2 < 8) {
        doska[str + 1][st + 2] = 'X';
    }
    if (str - 1 > 0 and st + 2 < 8) {
        doska[str - 1][st + 2] = 'X';
    }
    if (str + 1 < 8 and st - 2 > 0) {
        doska[str + 1][st - 2] = 'X';
    }
    if (str - 1 > 0 and st - 2 > 0) {
        doska[str - 1][st - 2] = 'X';
    }
    cout << " abcdefgh"<< endl;
    for (int i = 0; i < 8; i++) {
        cout << nums[i];
        for (int j = 0; j < 8; j++) {
            cout << doska[i][j];
        }
        cout << endl;
    }
}


5a v - 13

double dividers(int N) {
	int sumofdivs = 1;
	for (int i = 2; i < ceil(sqrt(N)); i++) {
		if (N % i == 0) {
			sumofdivs += i;
			sumofdivs += N / i;
		}
	}
	return sumofdivs;
}

int main() {
	int N;
	cout << "Enter N" << endl;
	cin >> N;
	for (int i = N; i > 0; i--) {
		if (dividers(i) == i) {
			cout << i << endl;
		}
	}
}

double func2(int n,int a, int c) {
    return (a * n + c) % 10;
}
double func(int n, int a, int c) {
    if (n <= 9 && n > 0) {
        return n;
    }
    else {
        return func2(n, a, c) * func(n - 1 - func2(n, a, c), a, c) + n;
    }
}
int main() {
    int a, c, M;
    cin >> a >> c >> M;
    if (M < 0 || a < 0 || c << 0) {
        cout << "invalid value";
    }
    cout << func(M, a, c);
}


5b13

string inversedrepeatedstring(int n, int counter,int space) {
	for (int k = 0; k < space; k++) {
		cout << " ";
	}
	for (int j = 0; j < n; j++) {
		cout << char(counter);
	}
	cout << endl;
	if (counter > 65) {
		return inversedrepeatedstring(n + 4, counter - 1,space - 2);
	}
	else {
		return "";
	}
}

string repeatedstring(int n,int counter,int space) {
	for (int k = 0; k < space; k++) {
		cout << " ";
	}
	for (int j = 0; j < n; j++) {
		cout << char(counter);
	}
	cout << endl;
	if (n > 20) {
		return repeatedstring(n - 4, counter + 1,space+2);
	}
	else {
		return inversedrepeatedstring(n+4,counter-1,space-2);
	}
}

int main() {
	repeatedstring(120,65,0);
}

04.11 2

double arifavg(double *a,int x) {
	double sum = 0;
	for (int i = 0; i < x; i++) {
		sum += a[i];
	}
	return sum / x;
}

int main() {
	double X[60];
	double Y[75];
	double Z[80];
	cout << arifavg(X, 60) << endl << arifavg(Y,75) << endl << arifavg(Z,80);
}

04.11 3

double sumxd(vector<int> q, vector<int> w, vector<int> e) {
	double sum1, sum2, sum3;
	for (int i = 0; i < 40; i++) {
		if (i < 20) {
			sum1 += cos(q.at(i));
			sum2 += sin(w.at(i));
		}
		sum3 += log(abs(e.at(i)));
	}
	return (sum1 + sum2) / sum3;
}

int main() {
	vector<int> a;
	vector<int> b; 
	vector<int> c;
	cout << sumxd(a, b, c);
}


double cosinus(double f) {
	return cos(f);
}
double sinus(double f) {
	return sin(f);
}
double modullog(double f) {
	return log(abs(f));
}
double summ(vector<double> mass, int k, double(&function)(double)) {
	double sum1 = 0;
	for (int i = 0; i < k; k++) {
		sum1 += function(mass.at(i));
	}
	return sum1;
}

int  main() {
	vector<double> a, b, c;
	double z = (summ(a, 20, cosinus) + summ(b, 20, sinus)) / summ(c,40,modullog);
}


kr 2v12

int main() {
	double x, sum, znam, chis, znak;
	cin >> x;
	sum = 0;
	znam = 1;
	chis = 1;
	znak = 2;
	for (int i = 1; i < 14; i++) {
		chis *= x;
		znam *= i;
		if (i % 2 == 1) {
			sum += pow((-1), znak) * chis / znam;
			znak += 1;
		}
	}
	cout << sum;
}

kr 3v12

int main() {
	double sum,eps,chlen,chisl,znam;
	cout << "enter eps" << endl;
	cin >> eps;
	cout << "enter member" << endl;
	cin >> chlen;
	sum = 0;
	int n = 1;
	chisl = 1;
	znam = 1;
	int factorial = 1;
	sum = (-1) * chisl / znam;
	while (abs(chisl / znam) > eps) {
		chisl = chisl * chlen * chlen * (-1);
		znam = factorial * (2*n) * (2*n - 1);
		sum += chisl / znam;
		n++;
	}
	cout << sum;
}

kr-1
#include <iostream>
#include <string>

int numlast(string str, char chr) {
	int last = -1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == chr) {
			last = i;
		}
	}
	return last;
}

int main() {
	string str;
	int num;
	char chr;
	cout << "enter string, then enter char" << endl;
	cin >> str >> chr;
	if (numlast(str, chr) != -1) {
		cout << numlast(str, chr) + 1;
	}
	else { cout << -1; }
}

kr-2
int findnums(int arr[][7], int j, int i) {
	int tmp = 100000000;
	for (int k = 0; k < j; k++) {
		int flag = 1;
		for (int h = 0; h < i; h++) {
			if (arr[i][j] != 0) {
				flag *= arr[i][j];
			}
		}
		if (tmp > flag) {
			tmp = flag;
		}
	}
	return tmp;
}
int main() {
	int arr1[10][7];
	int arr2[10][7];
	cout << "enter nums of matrix1, matrix[n][7]" << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; i < 7; i++) {
			cin >> arr1[i][j];
		}
	}
	cout << "enter nums of matrix2, matrix[n][7]" << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; i < 7; i++) {
			cin >> arr2[i][j];
		}
	}
	cout << findnums(arr1, 10, 7) << findnums(arr2, 10, 7) << endl;
}

kr-3
double f(double qwe) {
	return qwe*qwe;
}
double func(double f(double), int e,double vector[]) {
	double sum = 0;
	for (int j = 0; j < e; j++) {
		sum += f(vector[j]);
	}
	return sum;
}
int main() {
	double n;
	cin >> n;
	double *vector{ new double[n] };
	for (int i = 0; i < n; i++) {
		cin >> vector[i];
	}
	cout << func(f, n, vector);
}

kr-4
int superreverse(int arr[], int n) {
	if (n >= 0) {
		cout << arr[n] * (-1) << endl;
		return superreverse(arr, n - 1);
	}
}
int main() {
	cout << "enter len of array of numbers, then enter array" << endl;
	int n;
	cin >> n;
	int* arr{ new int[n] };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	superreverse(arr, n-1);
}

kr-1perepis


void procedure(string str) {
	int i = 0;
	while (i < str.length()) {
		if (str[i] == '1') {
			str[i] = '0';
			i++;
		}
		if (str[i] == '0') {
			str[i] = '1';
			i++;
		}
	}
}
int main() {
	string str,q;
	cout << "enter string of 0 and 1" << endl;
	cin >> str;
	procedure(str);
	cout << str;
}

kr-2perepis

#include <iostream>
#include <array>
using namespace std;
void procedure(double A[2][3], int k, int p, double C[2]) {
    for (int i = 0; i < k; i++) {
        double sum = 0;
        for (int j = 0; j < p; j++) {
            sum += A[i][j];
        }
        C[i] = sum;
    }
}
int main() {
    double A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    double C[2];
    procedure(A, 2, 3, C);
    for (int i = 0; i < 2; ++i) {
        cout << C[i] << " ";
    }
    cout << endl;
    return 0;
}

void procedure(string str,int k,int& counter) {
	int w = 0;
	int j = 0;
	int count1 = 0;
	
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ') { count1++; }
	}

	if (k == 1) {
		counter = 0;
		while (str[j] != ' ') {
			j++;
			counter++;
			counter + 1;
		}
		return;
	}

	if (k == count1+1) {
		j = str.length();
		while (str[j] != ' ') {
			j--;
			counter++;
			counter - 1;
		}
		return;
	}

	while (w < k) {
		if (j < str.length()) {
			j++;
		}
		if (str[j] == ' ') {
			w++;
		}
	}
	j = j - 1;
	while (str[j] != ' ') {
		j--;
		counter++;
	}
}

int main() {
	int k;
	string str = "Some find birdsong to be a very melodic set of sounds, although it seems to be just a way of animal communication";
	// 21 - ' ' 22 - words
	cin >> k;
	int counter = 0;
	if (k > 22 or k < 1) {
		cout << "wrong num of word";
	}
	else {
		procedure(str, k, counter);
		cout << counter;
	}
}

struct Student 
{
	string name;
	string surname;
	string patronymic;
	string grade_book;
	string score;
};
struct Exam 
{
	string discipline;
	string group;
	string date;
	struct Student stud[30];
};

Student parse_student(string raw_string) 
{
	Student rawstudent;
	string stud_info;
	stringstream stream_info(raw_string);
	int j = 0;
	while (getline(stream_info, stud_info, ';')){
		if (j % 5 == 0){
			rawstudent.name = stud_info;
		}
		if (j % 5 == 1){
			rawstudent.surname = stud_info;
		}
		if (j % 5 == 2){
			rawstudent.patronymic = stud_info;
		}
		if (j % 5 == 3){
			rawstudent.grade_book = stud_info;
		}
		if (j % 5 == 4){
			rawstudent.score = stud_info;
		}
		j++;
	}
	return rawstudent;
}

void parse_file(ifstream* filexd, struct Exam* ex) {
	string temp;
	int i = 0;
	int k = 0;
	while (getline(*filexd,temp,'\n')) {
		i++;
		if (i == 1) {
			ex->discipline = temp;
		}
		if (i == 2) {
			ex->group = temp;
		}
		if (i == 3) {
			ex->date = temp;
		}
		if (i > 3) {
			ex->stud[k] = parse_student(temp);
			k++;
		}
	}
}

int main(){
	ifstream file("C:/Users/svato/OneDrive/Рабочий стол/file.txt");
	Exam examen;
	parse_file(&file, &examen);
	for (int iter = 0; iter < 30; iter++) {
		if (examen.stud[iter].score == "2") {
			cout << examen.stud[iter].surname;
		}
	}
}

*/

/*
struct Conductor{
	string name;
	int conductivity;
	string conductor_type;
};

Conductor parse_conductor(string rawconductor) {
	Conductor parsed_conductor;
	stringstream rawconductor_stream(rawconductor);
	string conductor_data;
	int params = 3;
	for (int i = 0; getline(rawconductor_stream, conductor_data, ' '); i++) {
		switch(i%params){
			case(0): parsed_conductor.name = conductor_data;
			case(1): {
				stringstream conductivity_stream;
				conductivity_stream << conductor_data;
				int conductivity_value;
				conductivity_stream >> conductivity_value;
				parsed_conductor.conductivity = conductivity_value; }
			case(2): parsed_conductor.conductor_type = conductor_data;
		}
	}
	return parsed_conductor;
}

void parse_file(ifstream *rawstream, Conductor *conductors) {
	string rawconductorstr;
	for (int j = 0; getline(*rawstream, rawconductorstr, '\n'); j++) {
		conductors[j] = parse_conductor(rawconductorstr);
	}
	
}

int main(){
	ifstream file_stream("C:/Users/svato/OneDrive/Рабочий стол/testfile.txt");
	Conductor conductors[5];
	parse_file(&file_stream,conductors);
	cout << conductors[2].conductivity;
}
*/

/* РАбота со списком.
1) Создание списка(n)
2) Добавление эл-та в любую позицию списка
3) Удаление эл-та из списка
4) удаление всего списка
5) Распечатка списка
6) Выход из программы
*/

/*
struct Node {
	string value;
	Node* next;
	Node(string other_value) : value(other_value), next(nullptr) {}
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
		if (listxd->first != NULL || point == 1) {
			cout << "Перезапустите программу для повтороного создания списка";
			return;
		}
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
*/


struct Node {
	string value;
	Node* next;
	Node(string other_value) :value(other_value), next(nullptr) {}
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

