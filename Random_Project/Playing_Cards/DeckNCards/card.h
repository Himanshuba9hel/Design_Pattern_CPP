#ifndef CARD_H
#define CARD_H

class Card
{
public:
    ~Card() = default;
    virtual void getInfo() const = 0;
};

#endif // CARD_H
