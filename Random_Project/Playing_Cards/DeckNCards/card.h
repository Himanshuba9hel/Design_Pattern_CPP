#ifndef CARD_H
#define CARD_H

struct CardInfo
{
    virtual ~CardInfo() = default;
};

class Card
{
public:
    virtual ~Card() = default;
    virtual const CardInfo &getInfo() const = 0;
};

#endif // CARD_H