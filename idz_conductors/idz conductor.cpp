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

Conductor parse_conductor(string rawconductor) { // parse conductor from string of conductor data
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

int parse_file(ifstream* rawstream, Conductor* conductors) { // parse file by splitting the file into lines  with conductor data
	string rawconductorstr;
	int j = 0;
	while(getline(*rawstream, rawconductorstr, '\n')) {
		conductors[j] = parse_conductor(rawconductorstr);
		j++;
	}
	return j;
}

void merge(Conductor array[], int const left, int const mid, int const right) {
	int const subArrayOne_mid = mid - left + 1;
	int const subArrayTwo_mid = right - mid;
	Conductor* leftArray = new Conductor[subArrayOne_mid];
	Conductor* rightArray = new Conductor[subArrayTwo_mid];
	for (int i = 0; i < subArrayOne_mid; i++){
		leftArray[i] = array[left + i];
	}
	for (int j = 0; j < subArrayTwo_mid; j++) {
		rightArray[j] = array[mid + 1 + j];
	}
	// making two sub arrays and filling it by the original ^^^ 

	int indexOfSubArrayOne = 0;
	int	indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne_mid && indexOfSubArrayTwo < subArrayTwo_mid) {
		if (leftArray[indexOfSubArrayOne].conductivity <= rightArray[indexOfSubArrayTwo].conductivity) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne_mid) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo_mid) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

void mergeSort(Conductor array[], int const begin, int const end)
{
	if (begin >= end){
		return;
	}
	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

void displaySortedArray(Conductor A[], ofstream &stream,int size,string pathToOut) { //func to create output file with sorted array of conductors
	string conductor_data;
	stream.open(pathToOut);
	for (int i = 0; i < size; i++) {
		stream << A[i].name << " " << A[i].conductivity << " " << A[i].conductor_type << "\n";
	}
}

void printArray(Conductor A[], int size){
	for (int i = 0; i < size; i++){
			if (A[i].conductor_type == "halfconductor") {
				cout << A[i].conductivity << " " << A[i].name << "\n";
			}
	}
	cout << endl;
}

int main(){
	string path;
	string outpath;
	Conductor conductors[100];
	cout << "input path to file with conductors \n WARNING: use / instead of \\ : the program may not run correctly otherwise \n be sure that path doesn't contain russian letters or other symbols like \" \n";
	cin >> path;
	cout << "input path to output file(sorted array) \n if u want to create such file by this algorythm, add a name of file after path:";
	cin >> outpath;
	ifstream file_stream;
	file_stream.open(path);
	int countof_conductors = parse_file(&file_stream,conductors);
	mergeSort(conductors, 0, countof_conductors);
	printArray(conductors, countof_conductors);
	ofstream outfile_stream; 
	displaySortedArray(conductors, outfile_stream, countof_conductors, outpath);
	cout << "if nothing happens(empty \"outputfile\" in specified earlyer path and there's no data on screen) - try to check correctness of input data";
}
