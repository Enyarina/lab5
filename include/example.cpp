#include <iostream>
#include <string>
#include <utility>

class dog {
public:
    std::string word = "gav";
    int i;
    dog()
    {}
    explicit dog(std::string str)
    {word = str;}
};
