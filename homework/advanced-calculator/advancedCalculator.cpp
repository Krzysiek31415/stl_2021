#include <string>
#include <iostream>
#include "advancedCalculator.hpp"
#include <functional>
#include <map>

// funkcje dzialaja na obiektach ...bledy 

void Calculator::input(std::string line)
{
    std::cout<<"Calculate: ";
    std::string temp{};
    std::getline(std::cin, temp);
    setCommandLine(temp);
}

DataOperation Calculator::parse(std::string s)
{
    return DataOperation{1,2,'+',ErrorCode::Ok};
}

ErrorCode process(std::string input, double* out)
{
    DataOperation dataOperation = Calculator::parse(input);
    std::cout<<dataOperation.sign <<"  OK \n";
    if(dataOperation.error == ErrorCode::Ok)
    {
        switch(dataOperation.sign)
        {
            case '+':
                *out = Calculator::commands['+'](dataOperation.number1, dataOperation.number2);
                std::cout<<"OK\n";
                break;
            case '-':
                break;
        }
        return ErrorCode::Ok;
    }
    else
    {
        return ErrorCode::BadCharacter;
    }
    
}

