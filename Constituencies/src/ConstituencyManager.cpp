#include "ConstituencyManager.h"
#include <fstream>
#include <algorithm>


ConstituencyManager::ConstituencyManager()
{
    //ctor
}

ConstituencyManager::~ConstituencyManager()
{
    //dtor
}

void ConstituencyManager::loadConstituencies(){
if(!numConstituencies) {
    std::cout<<"No constituencies.";
    return;
}
for(int i=0; i< numConstituencies; i++){
 constituencies.push_back(createConstituency());
}
}

Constituency ConstituencyManager::createConstituency(){
    Constituency temp;
    std::cout<<"Enter constituency name:";
    std::cin>>temp.constituencyName;
    std::cout<<"Enter number of voters for constituency:";
    temp.voters=intInput();
    std::cout<<"Enter number of parties for constituency:";
    temp.parties=intInput();;
    temp.addParties();
    return temp;

}

void ConstituencyManager::generateFile(){
    std::ofstream file_obj("constituencies.txt");
    if (file_obj.is_open())
  {
    for(Constituency temp:constituencies){
        file_obj.write((char*)&temp, sizeof(temp));
    }
  }
}

void ConstituencyManager::noWinner(){
for(Constituency temp:constituencies){
    std::vector<int> votes=temp.getVotes();
    bool flag=false;
    for(unsigned int i = 0; i < votes.size(); i++){
        if(flag) break;
        for(unsigned int j = 0; j < votes.size(); j++){
            if(i!=j){
                if(votes[i]==votes[j]){
                std::cout<<temp.constituencyName<<std::endl;
                flag=true;
                break;
                    }
                }
            }
        }

    }
}


void ConstituencyManager::generateNoWinnerFile(){
std::ofstream file("nowinner.txt");
    if (file.is_open())
  {
   for(Constituency temp:constituencies){
    std::vector<int> votes=temp.getVotes();
    bool flag=false;
    for(unsigned int i = 0; i < votes.size(); i++){
        if(flag) break;
        for(unsigned int j = 0; j < votes.size(); j++){
            if(i!=j){
                   if(votes[i]==votes[j]){
                file<<temp.constituencyName<<std::endl;
                file<<calculatePersentage(temp)<<std::endl;

                flag=true;
                break;

                    }
                }
            }
        }

    }
  }
}

double  ConstituencyManager::calculatePersentage(Constituency temp){
 double sum=calculateTotalVotes(temp);
 double persentage;
 persentage=100-sum*100/temp.voters;
 return persentage;
}

void ConstituencyManager::partiesPercentage(){
std::string sortedNames[numConstituencies];
addNames(sortedNames);
std::sort(sortedNames, sortedNames+numConstituencies);
for(unsigned int i=0; i<constituencies.size(); i++){
    for(unsigned int j=0; j<constituencies.size(); j++){
        if(sortedNames[i]==constituencies[j].constituencyName){
            std::cout<<sortedNames[i]<<std::endl;
           printPartiesPercentage(constituencies[j]);
        }
    }
}
}

void ConstituencyManager::addNames(std::string* sortedNames){
    for(unsigned int i=0; i<constituencies.size(); i++){
        *sortedNames=constituencies[i].constituencyName;
        sortedNames++;
    }
}

void ConstituencyManager::printPartiesPercentage(Constituency constituency){
std::string* names=constituency.getPartiesNames();
std::vector<int> partiesVotes=constituency.getVotes();
for(int i=0; i<constituency.parties; i++){
    std::cout<<*names<<" "<< persentageVotes(partiesVotes[i],constituency)<<std::endl;
    names++;
    }

}

double ConstituencyManager::persentageVotes(int votes,Constituency temp){
double persentage;
double totalVotes=calculateTotalVotes(temp);
persentage=votes*100/totalVotes;
return persentage;

}

 double ConstituencyManager::calculateTotalVotes(Constituency temp){
 double sum=0;
 std::vector<int> votes=temp.getVotes();
 for(int i=0; i<temp.parties; i++){
    sum=sum+votes[i];
 }
 return sum;

 }

