#include "ConstituencyManager.h"

using namespace std;

void menu();


int main()
{
    ConstituencyManager test2;
    cout<<"Enter number of constituencies of country:";
    numConstituencies=intInput();
    menu();

    return 0;
}


void menu(){
    ConstituencyManager test;
    test.loadConstituencies();
    int choice;
	do {
			cout<<" Menu"<<endl;
			cout<<"            1. Generate file with constituencies"<<endl;
			cout<<"            2. Print parties percentage"<<endl;
			cout<<"            3. Print constituencies with no winner"<<endl;
			cout<<"            4. Generate file with constituencies with no winner"<<endl;
			cout<<"            5. Exit."<<endl;
			cout<<"Enter your choice: ";
			choice=intInput();

			switch (choice) {
			case 1: {
				test.generateFile();
			}
				break;
			case 2: {
				test.partiesPercentage();
			}
				break;
			case 3: {
				test.noWinner();
			}
				break;
            case 4: {
				test.generateNoWinnerFile();
			}
				break;
			default: {
				cout<<"Out of the system.";
			}
				return;
			}

		} while (choice != 5);

}
