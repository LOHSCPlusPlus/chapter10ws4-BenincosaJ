#include "Rabbit.h"
#include <iostream>
using namespace std;

Rabbit::Rabbit(){
  for (int index = 0; index < MAX_CHAR_LEN; index++) {
        name[index] = '\0';
    }
    maxWeight = 0;
    yearRecognized = 0;
    isRare = false;
    isValid = false;
}

void Rabbit::print(ostream &out){
  out << name << ";" << maxWeight << ";" << yearRecognized << ";" << isRare << endl;
}

void Rabbit::readFromUser(){
    cout << "Enter a rabbit name: ";
    if (cin.peek() == '\n') {
        cin.ignore(100, '\n');
    }
    cin.get(name, MAX_CHAR_LEN);
    maxWeight = readDouble("Enter max rabbit weight: ");
    yearRecognized = readInt("Enter year recognized: ");
    isRare = readBool("Is this rabbit rare (y/n)? ");
    isValid = true;
}

 void Rabbit::readFromFile(ifstream &inFile){
    inFile.get(name, MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile >> maxWeight;
    inFile.ignore(100,';');
    inFile >> yearRecognized;
    inFile.ignore(100,';');
    inFile >> isRare;
    inFile.ignore(100,'\n');
    isValid = !inFile.eof();
}

bool Rabbit::getIsValid(){
  return isValid;
}

void Rabbit::makeInvalid(){
  isValid = false;
}