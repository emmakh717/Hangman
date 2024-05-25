#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;

int main (){

char start{};
int choice;
  
//Start screen
cout << "     Hangman    " << endl;
cout << " By: Emma Khalil " << endl;
cout << "               " << endl;
cout << "______________  " << endl;
cout << "|       }       " << endl;
cout << "|       O       " << endl;
cout << "|       |       " << endl;
cout << "|      /|\\     " << endl;
cout << "|     / | \\    " << endl;
cout << "|      / \\     " << endl;
cout << "|     /   \\    " << endl;
cout << "|               " << endl;
cout << "|_______________" << endl;
cout << "\nPress Any Key (and enter) to Start\n";
cin >> start;
cout << "1 - Easy\n";
cout << "2 - Medium\n";
cout << "3 - Hard\n\n";
cin >> choice;
  
//CLEAR SCREEN
system("CLS");

//GAME
//Set variables used throughout the game
int tries{8}; //The number of atemps to guess correctly
char guess; //The letter guessed
bool CorrectGuess = false;
char PreviousGuesses[9]; //an array of guesses, needs to be 1 longer than the user can guess because there needs to be a NULL terminator inside the array
char play_again;
  
PreviousGuesses[0] = '\0';
for (int i = 1; i < 8; i++){
PreviousGuesses[i] = '-';
}
PreviousGuesses[8] = '\0'; //stop reading the array

string word; //this will be the word the player has to guess

const string WordList1[23] = {"walk","boil", "book", "beg", "risk", "part", "rush", "drum", "vest", "foot", "shut", "iron", "book", "pine", "wax", "vein", "page", "glow", "boot", "nosy", "eggs", "heap", "case"};

const string WordList2[42] = {"panda", "permit", "mouth", "squeal", "houses", "elated", "argue", "murky", "yield", "grade", "trees", "sleep", "climb", "sugar", "script", "plain", "quill", "woozy", "stroke", "battle", "strange", "degree", "poised", "grape", "spark", "pale", "drink", "animal", "rustic", "title", "trains", "dolls", "desire", "groovy", "glossy", "doubt", "suffer", "soothe", "prick", "narrow", "wound", "stingy"};

const string WordList3[35] = {"umbrella", "aromatic", "hospitable", "spectacular", "subsequent", "wretched", "alleged", "material", "infamous", "measure", "unwritten", "attract", "apologise", "annoyed", "fertile", "enthusiastic", "radiate", "embarrass", "obsequious", "pollution", "payment", "tremble", "marvelous", "tremendous", "committee", "abashed", "friendly", "disagree", "puzzling", "terrific", "connect", "melodic", "confess", "trouble"};
//these are lists of a total of 100 strings

//Get random word
srand(time(NULL)); //Creates a random seed that is used to get a random word from the list above

  
if(choice == 1){
  int RandomNum = rand() % 23; //returns a random number between 0 and 22
word = WordList1[RandomNum];
}
else if(choice == 2){
  int RandomNum = rand() % 42; //returns a random number between 0 and 42
word = WordList2[RandomNum];
}
else if(choice == 3){
  int RandomNum = rand() % 35; //returns a random number between 0 and 35
word = WordList3[RandomNum];
}

//Make word a mystery
string MysteryWord(word.length(), '*'); //This replaces each word with an underscore and stores it in MysteryWord

while (tries >= 0){
//Reset bool
CorrectGuess = false;

//display information related to word for the player
cout << "The word you have to guess is: \n\n" << MysteryWord << endl;
cout << "\nThere are " << MysteryWord.length() << " letters in the word\n\n";
cout << "You have " << tries << " guesses left\n\n";
if(PreviousGuesses[0] == '\0'){
cout << endl;
}
else{
cout << "You have guessed " << PreviousGuesses << endl;
}

//get player guess
cout << "\nGuess a letter: ";
cin >> guess;

//Check if guess is correct
for(int i = 0; i < MysteryWord.length(); i++){ //for the length of the mystery word do the following
if(word[i] == guess){ //check if the word (actual) has the guess in it
MysteryWord[i] = guess;
CorrectGuess = true;
}
}
  if(word == MysteryWord){
    cout << "\n\n\n\nYOU WON!\n\n\nCongratulations! You have guessed the word: " << MysteryWord << endl;
  break;
  }
  if(CorrectGuess == false){
    tries--;
    cout << "Sorry, " << guess << " is not part of the word\n";
  }
  else{
    cout << "Congratulations! " << guess << " is one of the letters\n";
  }

switch(tries){
case 8:{
cout << "______________  " << endl;
cout << "|       }       " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|_______________" << endl;
break;
}
case 7:{
cout << "______________  " << endl;
cout << "|       }       " << endl;
cout << "|       O       " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|_______________" << endl;
if(CorrectGuess == false){
PreviousGuesses[0] = guess;
}
break;
}
case 6:{
cout << "______________  " << endl;
cout << "|       }       " << endl;
cout << "|       O       " << endl;
cout << "|       |       " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|_______________" << endl;
if(CorrectGuess == false){
PreviousGuesses[1] = guess;
}
break;
}
case 5:{
cout << "______________  " << endl;
cout << "|       }       " << endl;
cout << "|       O       " << endl;
cout << "|       |       " << endl;
cout << "|       |       " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|_______________" << endl;
if(CorrectGuess == false){
PreviousGuesses[2] = guess;
}
break;
}
case 4:{
cout << "______________  " << endl;
cout << "|       }       " << endl;
cout << "|       O       " << endl;
cout << "|       |       " << endl;
cout << "|       |       " << endl;
cout << "|       |       " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|_______________" << endl;
if(CorrectGuess == false){
PreviousGuesses[3] = guess;
}
break;
}
case 3:{
cout << "______________  " << endl;
cout << "|       }       " << endl;
cout << "|       O       " << endl;
cout << "|       |       " << endl;
cout << "|      /|       " << endl;
cout << "|     / |       " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|_______________" << endl;
if(CorrectGuess == false){
PreviousGuesses[4] = guess;
}
break;
}
case 2:{
cout << "______________  " << endl;
cout << "|       }       " << endl;
cout << "|       O       " << endl;
cout << "|       |       " << endl;
cout << "|      /|\\     " << endl;
cout << "|     / | \\    " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|               " << endl;
cout << "|_______________" << endl;
if(CorrectGuess == false){
PreviousGuesses[5] = guess;
}
break;
}
case 1:{
cout << "______________  " << endl;
cout << "|       }       " << endl;
cout << "|       O       " << endl;
cout << "|       |       " << endl;
cout << "|      /|\\     " << endl;
cout << "|     / | \\    " << endl;
cout << "|      /        " << endl;
cout << "|     /         " << endl;
cout << "|               " << endl;
cout << "|_______________" << endl;
if(CorrectGuess == false){
PreviousGuesses[6] = guess;
}
break;
}
case 0:{
cout << "______________  " << endl;
cout << "|       }       " << endl;
cout << "|       O       " << endl;
cout << "|       |       " << endl;
cout << "|      /|\\     " << endl;
cout << "|     / | \\    " << endl;
cout << "|      / \\     " << endl;
cout << "|     /   \\    " << endl;
cout << "|               " << endl;
cout << "|_______________" << endl;
cout << "\nGAME OVER!" << endl;
cout << "The word was: " << word << endl;
tries = -1;
break;
}
default:
cout << "If you are seeing this, then there is an error.";
}
}
return 0;
}