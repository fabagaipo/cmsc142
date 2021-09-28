// 8/10 evaluation

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void readInclude(string);

int main(){
	string fileName;

	cin >> fileName;
	
  	readInclude(fileName);

  	return 0;
}

void readInclude(string fileName){
	ifstream reader(fileName);

	if(reader.is_open()){
		string line;
		
		while(getline(reader, line)){
			if(line.find_first_of('#') != string::npos){
                readInclude(line.substr(line.find_first_of('"')+1, line.find_first_of('h')-line.find_first_of('"')));
            }
            else if(line.find_first_of('#') == string::npos){
                cout << line << endl;
            }
        }
    }
    reader.close();
}
