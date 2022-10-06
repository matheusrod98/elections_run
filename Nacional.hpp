#include <string>

#include "Estadual.hpp"

class Nacional {
    public:
        Nacional (std::string name);
        // std::vector<int> getNationalVotes ();

    private:
	// std::vector<int> nationalVotes;
	std::vector<Estadual> states;

};
