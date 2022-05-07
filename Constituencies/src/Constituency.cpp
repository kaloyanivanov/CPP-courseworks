#include "Constituency.h"

Constituency::Constituency()
{
    //ctor
}

Constituency::~Constituency()
{
    //dtor
}

int numConstituencies;


void  Constituency::addParties(){
if(!parties) {
    std::cout<<"No parties";
    return;
}
int numVotes;
for(int i = 0; i < parties; i ++){
    std::cout<<"Enter name of party:";
    std::cin>>partiesNames[i];
    std::cout<<"Enter number of votes for party:";
    numVotes=intInput();
    votes.push_back(numVotes);
    }
}

 std::vector<int> Constituency::getVotes(){
 return votes;
 }

 std::string* Constituency::getPartiesNames(){
  return partiesNames;
  }

  int intInput(){
    int temp;
    std::cin>>temp;
    while(std::cin.fail()) {
        std::cout << "Error" << std::endl;
        std::cout << "Enter number" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> temp;
    }
    return temp;
}
