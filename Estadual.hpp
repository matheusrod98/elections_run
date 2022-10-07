#ifndef _ESTADUAL_
#define _ESTADUAL_

#include <string>
#include <vector>

class Estadual {
    public:
        Estadual(std::string name);
        std::vector<std::vector<int>> getSamples(int begin, int end);
        std::string getName();

    private:
        std::string stateName;
        std::vector<std::vector<int>> candidatesVotes;
};
#endif /* _ESTADUAL_ */
