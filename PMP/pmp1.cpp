// Sir Ryan's demo code

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    string fileName;

    cin>>fileName;

    readInclude(fileName);

    return 0;
}

void readInclude(string fileName){
    ifstream reader(fileName);

    if(reader.is_open()){
        string line;
        
        while(getline(reader,line)){

            stringstream ss(line);

            string str;

            ss >> str;

            if(str.compare("#include") == 0){
                ss >> str;
                //"sample.h"
                string f = str.substr(1,str.length()-2);
                readInclude(f);
            }
            cout<<line<<end1;
        }
    }
}
