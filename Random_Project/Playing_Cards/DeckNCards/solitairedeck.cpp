#include "solitairedeck.h"

SolitaireDeck::SolitaireDeck() {}

SolitaireCard::SolitaireCard()
{
    for(int suitNumber =  static_cast<int>(SolitaireCardInfo::Suits::Heart);
        suitNumber < 4; suitNumber++)
    {
        SolitaireCardInfo::Suits suit = static_cast<SolitaireCardInfo::Suits>(suitNumber);
    }
}
