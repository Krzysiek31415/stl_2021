#pragma once
#include <string>
#include <functional>
#include <map>

enum class ErrorCode{
                     OK,
                     BadCharacter,
                     BadFormat,
                     DivideBy0,
                     SqrtOfNegativeNumber,
                     ModuleOfNonIntegerValue,
};

struct DataOperation
{
    double number1;
    double number2;
    char sign;
    ErrorCode error;
};
auto add = [](double first, double second){return first + second;};
auto minus = [](double first, double second) {return first - second;};

class Calculator
{
    std::map<char,std::function<double(double, double)>> commands{ {'+',add},{'-',minus}};
    std::string commandLine_{};
public:
    void setCommandLine(std::string line){
        commandLine_ = line;
    }
    std::string getCommandLine() const{
        return commandLine_;
    }
    void input(std::string line);
    DataOperation parse(std::string line);
    friend ErrorCode process(std::string input, double* out);
};

ErrorCode process(std::string input, double* out);