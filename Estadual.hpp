#include <string>

#define MAX_SAMPLES 200000
#define MAX_MONTHS 5

class Estadual {
    public:
        Estadual (std::string name);
        std::vector getVotes;
        std::string getName;

    private:
        std::string stateName;
        std::vector<std::vector<int>> samplesByMonth;
};
