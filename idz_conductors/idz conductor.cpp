
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

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
