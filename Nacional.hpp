#include <vector>

#include "Estadual.hpp"

class Nacional {
    public:
        Nacional();
        std::vector<int> getNationalVotes();
	std::vector<Estadual> getStates();

    private:
	std::vector<int> nationalVotes;
	std::vector<Estadual> states;
};
