#include <iostream>
using namespace std;

#include "Node.h"
#include "Tree.h"


// ------------------------Prototypes-------------------------
void newGame();
bool playAgain();
// -----------------------------------------------------------


Tree* tree;  //  Create object pointer

int main() {

    newGame();  //  Start new game
    tree->ifQuestion(); //  play one game
    while(playAgain())  //  if the user wants to play again
    {
        tree->ifQuestion(); //play one more game
    }

    tree->~Tree();  // call the destructor to test it
    return 0;
}


void newGame(){

    cout << "New game is starting..." << endl;
    cout << "Please think of an object and enter a question about it: " << endl;
    string question;  //  Store th 1st Question in the game
    getline(cin, question);
    cout << "Enter the object's name in case the response is yes: " << endl;
    string leftObject;  //  Store the left object
    getline(cin, leftObject);
    cout << "Enter an object's name in case the response is no: " << endl;
    string rightObject;  //  Store the right object
    getline(cin, rightObject);
    tree = new Tree(question, leftObject, rightObject);  //  Create the tree

} // newGame

// PRE: Receives three inputs from the keyboard. Tree class works
// POST: Stores the values to variables and passes them to the tree CTOR


bool playAgain(){


    cout << "Do you want to play another game?" << endl;
    string answer = "";  //  Store yes or no answer
    getline(cin, answer);
    answer = tolower(answer[0]); //  lowercase it

    while (answer != "y" and answer != "n")
    {  //  Make sure the answer is valid
        cout << "Invalid answer! Please enter 'y' for yes and 'n' for no" << endl;
        getline(cin, answer);
        answer = tolower(answer[0]);
    }

    if(answer == "y"){  //  if answer is yes
        return true;  //  Play again
    } //  if(answer == "y")
    else if(answer == "n"){  //  if answer is no
        return false;  //  Do not play again
    } //   else if(answer == "n")


}  //  playAgain


// PRE: Receives yes or no answer from the keyboard
// POST: Returns T/F based on the yes or no