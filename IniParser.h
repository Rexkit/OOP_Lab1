//
// Created by User on 27.09.2017.
//

#ifndef OOP_LAB1_INIPARSER_H
#define OOP_LAB1_INIPARSER_H

#include <iostream>
#include <map>
#include <sstream>
#include "parser_exceptions.h"

using namespace std;

class IniParser {
public:
    explicit IniParser(const char*, string, string);
    ~IniParser();
    void Initialize()
    throw (exc_file,exc_missing_fileType);
    bool IsHaveSection() const
    throw (exc_missing_data);
    bool IsHaveParam() const
    throw (exc_missing_data);
    template<typename T>
    T GetValue() const
    throw (exc_dataType_error) {
        string str = sectionParamName.at(section).at(paramName);
        istringstream ss(str);
        T value;
        ss >> value;
        return value;
    }
private:
    map<string,map<string,string>> sectionParamName;
    const char* fileName;
    string section;
    string paramName;
};



#endif //OOP_LAB1_INIPARSER_H
