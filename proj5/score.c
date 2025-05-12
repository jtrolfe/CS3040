// ----------------------------------------------------------------------
// File: score.c
//
// Name: Al Shaffer & Paul Clark (add your name as an author of this file)
//
// Description: This is the implementation of the SCORE module of the
//     YAHTZEE game. It keeps track of the score card, enters new
//     scores as requested, and displays the score as requested.
// ----------------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include "score.h"
#include "screen.h"

#define NUMBER_OF_ENTRIES 13  // Does not count the subtotals and totals


// **************************************************************************
// ****************************  DEFINED TYPES   ****************************
// **************************************************************************

// An entry in a scorecard
struct entry_t {
    unsigned int value;
    bool         used;
};


// **************************************************************************
// **************************** GLOBAL VARIABLES ****************************
// **************************************************************************

// The Scorecard
static struct entry_t Score[NUMBER_OF_ENTRIES+1]; // row 0 is not used

// The Entry Names in a scorecard
static char *Entry_names[] = {
    "******** NOT USED *********",
    "Aces     (total of all 1's)",   // Keep these col's all the same widths
    "Twos     (total of all 2's)",
    "Threes   (total of all 3's)",
    "Fours    (total of all 4's)",
    "Fives    (total of all 5's)",
    "Sixes    (total of all 6's)",
    "3 of a Kind  (add all dice)",
    "4 of a Kind  (add all dice)",
    "Full House   (score 25)    ",
    "Sm. Straight (score 30)    ",
    "Lg. Straight (score 40)    ",
    "YAHTZEE      (score 50)    ",
    "Chance       (add all dice)"
};


// **************************************************************************
// *************************** EXTERNAL FUNCTIONS ***************************
// **************************************************************************

// ---------------------------------------------------------------------
// Function
//     score_reset
// Inputs
//     none
// Outputs
//     none
// Description
//     Initializes all the scorecard entries to zero and unused.
// ---------------------------------------------------------------------
void score_reset(void)
{
    // Add your code here
}//end score_reset


// ---------------------------------------------------------------------
// Function
//     score_display
// Inputs
//     none
// Outputs
//     none
// Description
//     Displays the current scorecard using the entire screen.
// ---------------------------------------------------------------------
void score_display(void)
{
    // Add your code here
}//end score_display


// ---------------------------------------------------------------------
// Function
//     score_display_final
// Inputs
//     none
// Outputs
//     none
// Description
//     Displays the final scorecard in a simple format.
// ---------------------------------------------------------------------
void score_display_final(void)
{
    // Add your code here
}//end score_display_final


// ---------------------------------------------------------------------
// Function
//     score_set
// Inputs
//     item
//         This is the line in the scorecard to put the score.
//     score
//         This is the score to be put on the selected line.
// Outputs
//     function result
// Description
//     This function updates the line on the scorecard with the given
//     score. The item must not already be used by a previous entry, or
//     the function returns a non-SUCCESS and no change to the card
//     happens. The given item must also exist, or the function returns
//     a non-SUCCESS and no change to the card happens. Otherwise, the
//     requested change occurs, and a SUCCESS is returned.
// ---------------------------------------------------------------------
int score_set(const int item, const int score)
{
    // Add your code here
}//end score_set
