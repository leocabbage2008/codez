"""Functions to help play and score a game of blackjack.

How to play blackjack:    https://bicyclecards.com/how-to-play/blackjack/
"Standard" playing cards: https://en.wikipedia.org/wiki/Standard_52-card_deck
"""


def value_of_card(card):
    """Determine the scoring value of a card.

    :param card: str - given card.
    :return: int - value of a given card.  See below for values.

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 1
    3.  '2' - '10' = numerical value.
    """
    if card == 'A':
        return 1
    if card in ('J', 'Q', 'K'):
        return 10
    return int(card)


def higher_card(card_one, card_two):
    """Determine which card has a higher value in the hand.

    :param card_one, card_two: str - cards dealt in hand.  See below for values.
    :return: str or tuple - resulting Tuple contains both cards if they are of equal value.

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 1
    3.  '2' - '10' = numerical value.
    """
    card_one_face = card_one in ('J', 'Q', 'K')
    card_two_face = card_two in ('J', 'Q', 'K')
    if card_one_face and card_two_face:
        return (card_one, card_two)
    if (card_one_face and card_two == '10') or (card_two_face and card_one == '10'):
        return(card_one, card_two)
    if card_one == card_two:
        return (card_one, card_two)
    if card_one == 'A':
        return card_two
    if card_two == 'A':
        return card_one
    return str(max(int(card_one), int(card_two)))


def value_of_ace(card_one, card_two):
    """Calculate the most advantageous value for the ace card.

    :param card_one, card_two: str - card dealt. See below for values.
    :return: int - either 1 or 11 value of the upcoming ace card.

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 11 (if already in hand)
    3.  '2' - '10' = numerical value.
    """
    if card_one in ('J', 'Q', 'K'):
        card_one = 10
    if card_two in ('J', 'Q', 'K'):
        card_two = 10
    if card_one == 'A':
        card_one = 11
    if card_two == 'A':
        card_two = 11
    card_one = int(card_one)
    card_two = int(card_two)
    if card_one+card_two+11 <= 21:
        return 11
    return 1


def is_blackjack(card_one, card_two):
    """Determine if the hand is a 'natural' or 'blackjack'.

    :param card_one, card_two: str - card dealt. See below for values.
    :return: bool - is the hand is a blackjack (two cards worth 21).

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 11 (if already in hand)
    3.  '2' - '10' = numerical value.
    """
    return ((card_one in ('J', 'Q', 'K') or card_one == '10') and card_two == 'A') or ((card_two in ('J', 'Q', 'K') or card_two == '10') and card_one == 'A')


def can_split_pairs(card_one, card_two):
    """Determine if a player can split their hand into two hands.

    :param card_one, card_two: str - cards dealt.
    :return: bool - can the hand be split into two pairs? (i.e. cards are of the same value).
    """
    return (card_one == 'Q' and card_two == 'K') or (card_one == 'K' and card_two == 'Q') or (card_one == card_two)


def can_double_down(card_one, card_two):
    """Determine if a blackjack player can place a double down bet.

    :param card_one, card_two: str - first and second cards in hand.
    :return: bool - can the hand can be doubled down? (i.e. totals 9, 10 or 11 points).
    """
    if card_one == 'A':
        card_one = 1
    if card_two == 'A':
        card_two = 1
    if card_one in ('J', 'Q', 'K'):
        card_one = 10
    if card_two in ('J', 'Q', 'K'):
        card_two = 10
    card_one = int(card_one)
    card_two = int(card_two)
    return card_one+card_two == 9 or card_one+card_two == 10 or card_one+card_two == 11
