#ifndef _ESTADUAL_
#define _ESTADUAL_

#include <string>
#include <vector>

class Estadual {
    public:
        Estadual (std::string name);
        std::vector<std::vector<int>> getVotes();
        std::string getName();

    private:
        std::string stateName;
        std::vector<std::vector<int>> votesByMonth;
};
#endif /* _ESTADUAL_ */
