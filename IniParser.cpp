//
// Created by User on 27.09.2017.
//

#include "IniParser.h"
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

IniParser::IniParser(const char* filename, string sect, string paraName) {
    fileName = filename;
    paramName = paraName;
    section = sect;
}

void IniParser::Initialize() throw (exc_file, exc_missing_fileType){
    string tempStr;
    string tempSection;
    ifstream fin(fileName);
    if(!fin)
        throw exc_file("Can't find that file");
    if(fileName[strlen(fileName)-1] != 'i' || fileName[strlen(fileName)-2] != 'n' || fileName[strlen(fileName)-3] != 'i')
        throw exc_missing_fileType("Invalid file type");
    while(getline(fin, tempStr)) {
        tempStr.erase(std::remove(tempStr.begin(),tempStr.end(),' '),tempStr.end());
        char firstLetter = tempStr[0];
        if (firstLetter == '[')
            tempSection = tempStr.substr(1,tempStr.size()-2);
        else if(firstLetter == 0 || firstLetter == ';')
            continue;
        else {
            unsigned int pos = tempStr.find('=');
            unsigned int commentPos = tempStr.find(';');
            string paramName = tempStr.substr(0,pos);
            string param = tempStr.substr(pos+1,commentPos-pos-1);
            sectionParamName[tempSection][paramName] = param;
        }
    }
}

IniParser::~IniParser() = default;

bool IniParser::IsHaveSection() const throw (exc_missing_data)  {
    for (const auto &ptr : sectionParamName)
        if(ptr.first == section)
            return true;
    throw exc_missing_data("No such section");
}

bool IniParser::IsHaveParam() const throw (exc_missing_data) {
    for (const auto &ptr : sectionParamName)
        if(ptr.first == section)
            for(const auto &ptr2 : ptr.second)
                if(ptr2.first == paramName)
                    return true;
    throw exc_missing_data("No such parameter");
}

