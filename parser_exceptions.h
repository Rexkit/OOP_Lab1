//
// Created by User on 27.09.2017.
//

#ifndef OOP_LAB1_PARSER_EXCEPTIONS_H
#define OOP_LAB1_PARSER_EXCEPTIONS_H

#include <string>

using namespace std;

class exceptions{
public:
    explicit exceptions(const string& msg){
        cout << msg << "\n";
    }
};

class exc_missing_data : public exceptions {
public:
    explicit exc_missing_data(const string& msg): exceptions(msg)
    {}
};

class exc_file : public exceptions{
public:
    explicit exc_file(const string& msg): exceptions(msg)
    {}
};

class exc_missing_fileType: public exceptions{
public:
    explicit exc_missing_fileType(const string& msg): exceptions(msg)
    {}
};

class exc_dataType_error: public exceptions{
public:
    explicit exc_dataType_error(const string& msg): exceptions(msg)
    {}
};

#endif //OOP_LAB1_PARSER_EXCEPTIONS_H
