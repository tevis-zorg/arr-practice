#include <iostream>

using namespace std;

extern int shipGamePlay();

int main () {

    char respond;

    shipGamePlay();

    cout << "Continue ?(y/n)" << endl;
    cin >> respond;

    if ( respond == 'y' || respond == 'Y') {

        shipGamePlay();

    } else if ( respond == 'n' || respond == 'N') {

        cout << "Thanks for playing!" << endl;

    }

    return 0;

}

int shipGamePlay () {

    //put "1" to indicate there is a ship
    int row, column;

    bool ships [4][5] = {
        {0, 1, 1, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {0, 0, 1, 0, 1}
    };

    //Keep track of how many hits the player has and how many turns they have played
    int hits = 0;
    int missed = 8;
    int numberOfTurns = 0;

    //coordinate check is valid or out of bound
    //bool rowParamCheck, columnParamCheck;


    //Allow the player to keep going until they've hit all of ships or out of shell
    while ( hits < 4 && missed > 0) {


        //Coordinate selecting phase
        cout << "Selecting coordinate! \n" << endl;

        //Ask player to choose the row
        cout << "Choose the row number in range (0 - 3)" << endl;
        cin >> row;

        //Ask player to choose the column
        cout << "Choose the column number in range (0 - 4)" << endl;
        cin >> column;

        //Check if the ship exist at the given coordinate
        if( ships[row][column] && row <= 3 && column <= 4) {

            //if player hits the ship, resets the value becomes 0
            ships[row][column] = 0;

            //increase the hit counter
            hits++;

            //Tell the player that they've hit a ship and how many ships remains
            cout << "Hit! " << (4-hits) << " left.\n\n" << endl;

        } else if ( !ships[row][column] && row <= 3 && column <= 4){

            //Update how many chance left
            missed--;
            cout << "Miss : " << (missed) << " Shell Remains\n\n" << endl;

        } else {
            //Invalid coordinate
            cout << "Invalid coordinate!" << endl;
            break;
            shipGamePlay();
        };



        //Count how many turns the player has taken
        numberOfTurns++;

    }

    if( hits == 4 && missed > 0 ) {

        cout << "Victory! \n" << endl;
        cout << "You won in " << numberOfTurns << " turns" << endl;

    } else if ( missed == 0 ) {

        cout << "Sorry out of chance!\n\n" << endl;

    }


    return 0;

};
