#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool readFile(string);

int main(){
	string filename;

	cin >> filename;
  	readFile(filename);

  	return 0;
}

bool readFile(string filename){
	ifstream file(filename);

	if(file.is_open()){
		string lines;
		while(getline(file, lines)){
			if(lines.find("#include") != string::npos) {
				string newFile = lines.substr(lines.find('"') + 1, lines.find("h") - lines.find('"'));
				readFile(newFile);
				continue;
			}
			cout << lines << endl;
		}
		file.close();	
		return true;
	}
	return false;
}
