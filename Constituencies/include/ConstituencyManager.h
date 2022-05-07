#ifndef CONSTITUENCYMANAGER_H
#define CONSTITUENCYMANAGER_H
#include "Constituency.h"



class ConstituencyManager
{
    public:
        ConstituencyManager();
        virtual ~ConstituencyManager();
        void loadConstituencies();
        void generateFile();
        void partiesPercentage();
        void noWinner();
        void generateNoWinnerFile();

    private:
         std::vector<Constituency> constituencies;
         Constituency createConstituency();
         double calculatePersentage(Constituency);
         void addNames(std::string*);
         void printPartiesPercentage(Constituency);
         double persentageVotes(int,Constituency);
         double calculateTotalVotes(Constituency);
};

#endif // CONSTITUENCYMANAGER_H
