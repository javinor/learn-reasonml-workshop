/*
 Tuple are convenient when the additional structure doesn't need
 its own name, e.g. cards in a deck.
 */

type rank =
  | Ace
  | King
  | Queen
  | Jack
  | Number(int);

type suit =
  | Club
  | Diamond
  | Heart
  | Spade;

type card = (rank, suit);

/*
 IMPLEMENT ME
 Write a function that given two cards returns the high one.
 A card is considered "higher" is its rank is higher.
 e.g. Ace > King, Jack > Number(10), etc.
 */
let highCard = (card1: card, card2: card) => failwith("implement me");

/*
 IMPLEMENT ME
 Write a function that returns true iff the given hand has a flush,
 i.e., all 5 card have the same suit.
 */
type hand = (card, card, card, card, card);
let hasFlush = (hand: hand) => failwith("implement me");

TestUtils.runTests(
  __MODULE__,
  () => {
    TestUtils.test("should find the high card 9 of Spades", () =>
      assert(
        (Number(9), Spade)
        == highCard((Number(9), Spade), (Number(4), Diamond)),
      )
    );

    TestUtils.test("should find the high card Jack of Clubs", () =>
      assert((Jack, Club) == highCard((Jack, Club), (Number(10), Heart)))
    );

    TestUtils.test("should find the high card Ace of Diamods", () =>
      assert((Ace, Heart) == highCard((Ace, Heart), (Ace, Diamond)))
    );

    TestUtils.test("should find a flush", () =>
      assert(
        true
        == hasFlush((
             (Ace, Heart),
             (Ace, Heart),
             (Jack, Heart),
             (Number(9), Heart),
             (Number(2), Heart),
           )),
      )
    );

    TestUtils.test("should not find a flush", () =>
      assert(
        false
        == hasFlush((
             (Ace, Club),
             (Ace, Heart),
             (Jack, Heart),
             (Number(9), Heart),
             (Number(2), Heart),
           )),
      )
    );
  },
);