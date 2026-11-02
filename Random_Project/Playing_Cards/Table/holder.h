#ifndef HOLDER_H
#define HOLDER_H

class Card;
class Holder
{
public:
    virtual void receiveCard() = 0;
    virtual void giveCard() = 0;
};

#endif // HOLDER_H
