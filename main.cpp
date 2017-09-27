#include <iostream>
#include "IniParser.h"

using namespace std;

int main() {
    string fileName, type, section, paramName;
    cout << "====== INI FILE PARSER ======" << "\n";
    cout << "ENTER FILENAME(*.ini):" << "\n";
    cin >> fileName;
    cout << "ENTER DATA TYPE(int,double,string):" << "\n";
    cin >> type;
    cout << "ENTER SECTION:" << "\n";
    cin >> section;
    cout << "ENTER PARAMETER NAME:" << "\n";
    cin >> paramName;
    IniParser test(fileName.c_str(),section, paramName);
    test.Initialize();
    test.IsHaveSection();
    test.IsHaveParam();
    if(type == "int" || type == "INT")
        cout << "YOUR PARAMETER: " << test.GetValue<int>();
    else if(type == "double" || type == "DOUBLE")
        cout << "YOUR PARAMETER: " << test.GetValue<double>();
    else if(type == "string" || type == "STRING")
        cout << "YOUR PARAMETER: " << test.GetValue<string>();
    else
        cout << "Type is not correct";
    return 0;
}