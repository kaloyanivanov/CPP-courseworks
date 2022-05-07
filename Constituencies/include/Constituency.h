#ifndef CONSTITUENCY_H
#define CONSTITUENCY_H
#include <vector>
#include <string>
#include <iostream>

extern int numConstituencies;
int intInput();

class Constituency
{
    public:
        Constituency();
        virtual ~Constituency();
        std::string constituencyName;
        int voters;
        int parties;
        void  addParties();
        std::vector<int> getVotes();
        std::string* getPartiesNames();

    private:
        std::vector<int> votes;
        std::string partiesNames[100];
};

#endif // CONSTITUENCY_H
