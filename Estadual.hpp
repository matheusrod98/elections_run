#ifndef _ESTADUAL_
#define _ESTADUAL_

#include <string>
#include <vector>

using namespace std;

class Estadual {
    public:
        Estadual(string name);
        vector<vector<int>> getSamples(int begin, int end);
        string getName();

    private:
        string stateName;
        vector<vector<int>> candidatesVotes;
};
#endif /* _ESTADUAL_ */
