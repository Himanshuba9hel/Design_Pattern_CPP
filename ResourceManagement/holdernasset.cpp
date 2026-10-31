#include "holdernasset.h"

HolderNAsset::HolderNAsset() {}


Pencil *Student::giveAsset(Student *borrower)
{
    this->borrower = borrower;
    Pencil* temp = pencil;
    pencil = nullptr;
    return temp;
}

void Student::takeAsset(Student *giver, Pencil *givenAsset)
{
    this->pencil = givenAsset;
    this->giver = giver;
    giver->setBorrower(this);
}
