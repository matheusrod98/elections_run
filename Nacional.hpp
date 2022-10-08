#include <vector>

#include "Estadual.hpp"

using namespace std;

class Nacional {
    public:
        Nacional();
	vector<Estadual> getStates();

    private:
	vector<int> nationalVotes;
	vector<Estadual> states;
};
