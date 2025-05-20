// ----------------------------------------------------------------------
// File: score.c
//
// Name: Al Shaffer, Paul Clark, John Rolfe 
//
// Description: This is the implementation of the SCORE module of the
//     YAHTZEE game. It keeps track of the score card, enters new
//     scores as requested, and displays the score as requested.
// ----------------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "score.h"
#include "screen.h"

#define NUMBER_OF_ENTRIES   13  // Does not count the subtotals and totals
#define BONUS_THRESHOLD     65  // Amount needed in left col to trigger bonus
#define BONUS_AMOUNT        35  // Bonus ammount  
#define FINAL_OFFSET        29  // Final scoreboard right column offset
#define COLUMN_OFFSET       10  // Scoreboard right column offset
#define HEADER_OFFSET       3   // Header offset
#define LEFT_ALIGN          3   // Aighn left column
#define RIGHT_ALIGN         2   // Alighn right column



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
    for(int i=0; i<sizeof(Score)/sizeof(Score[0]); i++){
        printf("Resetting Score[%d]\n", i);
        Score[i].value =    0;
        Score[i].used =     0;
    }
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
    
    int array_size =    sizeof(Score)/sizeof(Score[0]);
    int total_left =    0;
    int total_right =   0;
    int bonus =         0;
    int row_length =    strlen(Entry_names[1]);

    screen_cursor(0,0);
    printf("  LEFT SECTION         YAHTZEE         RIGHT SECTION\n\n\n\n");

    //loop through and print the Entry_names and scores
    for(int i=1; i<array_size; i++){
        //Set the print location
        if(i < array_size/2){
            screen_cursor(i+HEADER_OFFSET,0);
            total_left += Score[i].value; //Running total of left
        }else{
            screen_cursor(i+HEADER_OFFSET - array_size/2, strlen(Entry_names[1])+COLUMN_OFFSET);
            total_right += Score[i].value; //Running total of right
        }

        //Print item number and column entry
        if(Score[i].used == 0){
            printf("%2i ",i);
        }else{
            printf("   ");
        }

        printf("%s %i\n",Entry_names[i],Score[i].value);

    }

    //SET BONUS
    if(total_left >= BONUS_THRESHOLD){ 
        bonus = BONUS_AMOUNT;
    }else{
        bonus = 0; 
    }


    //Print running scores
    //LHS
    screen_cursor(array_size/2+HEADER_OFFSET,0);
    printf("============================== ===");
    //Print total score
    screen_cursor(array_size/2+HEADER_OFFSET+1,0);
    printf("TOTAL SCORE");
    screen_cursor(array_size/2+HEADER_OFFSET+1,row_length +LEFT_ALIGN);
    printf("%3i",total_left + total_right);
    //Print Bonus
    screen_cursor(array_size/2+HEADER_OFFSET+2,0);
    printf("Bonus");
    screen_cursor(array_size/2+HEADER_OFFSET+2,row_length +LEFT_ALIGN);
    printf("%3i",bonus);
    //Print total left
    screen_cursor(array_size/2+HEADER_OFFSET+3,0);
    printf("Total Left");
    screen_cursor(array_size/2+HEADER_OFFSET+3,row_length +LEFT_ALIGN);
    printf("%3i",total_left);

    //RHS
    screen_cursor(array_size/2+HEADER_OFFSET,row_length+COLUMN_OFFSET);
    printf("============================== ===");
    //Print total left
    screen_cursor(array_size/2+HEADER_OFFSET+1,row_length+COLUMN_OFFSET);
    printf("TOTAL LEFT");
    screen_cursor(array_size/2+HEADER_OFFSET+1,2*row_length +COLUMN_OFFSET+RIGHT_ALIGN);
    printf("%3i",total_left);
    //Print total right
    screen_cursor(array_size/2+HEADER_OFFSET+2,row_length+COLUMN_OFFSET);
    printf("TOTAL right");
    screen_cursor(array_size/2+HEADER_OFFSET+2,2*row_length +COLUMN_OFFSET+RIGHT_ALIGN);
    printf("%3i",total_right);
    //Print grand total
    screen_cursor(array_size/2+HEADER_OFFSET+3,row_length+COLUMN_OFFSET);
    printf("GRAND TOTAL");
    screen_cursor(array_size/2+HEADER_OFFSET+3,2*row_length +COLUMN_OFFSET+RIGHT_ALIGN);
    printf("%3i",total_right+total_left+bonus);
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
    int array_size =    sizeof(Score)/sizeof(Score[0]);
    int total_upper =   0;
    int total_lower =   0;
    int bonus =         0;
    
    //loop through upper section
    //Set the print location
    screen_cursor(0,0);
    printf("UPPER SECTION\n");
    for(int i=1; i<array_size/2; i++){
        printf("%s %3i\n",Entry_names[i],Score[i].value);
        total_upper += Score[i].value;
    }

    //SET BONUS
    if(total_upper >= BONUS_THRESHOLD){ 
        bonus = BONUS_AMOUNT;
    }

    printf("=========================== ===\n");
    printf("TOTAL SCORE");
    screen_cursor(array_size/2+2, FINAL_OFFSET);
    printf("%3i\n",total_upper);
    printf("BONUS");
    screen_cursor(array_size/2+3, FINAL_OFFSET);
    printf("%3i\n",bonus);
    printf("TOTAL UPPER");
    screen_cursor(array_size/2+4, FINAL_OFFSET);
    printf("%3i\n",bonus+total_upper);


    printf("LOWER SECTION\n");
    for(int i=array_size/2; i<array_size; i++){
        printf("%s %3i\n",Entry_names[i],Score[i].value);
        total_lower += Score[i].value;
    }
    printf("=========================== ===\n");
    printf("TOTAL UPPER");
    screen_cursor(array_size+7, FINAL_OFFSET);
    printf("%3i\n",total_upper+bonus);
    printf("TOTAL LOWER");
    screen_cursor(array_size+8, FINAL_OFFSET);
    printf("%3i\n",total_lower);
    printf("GRAND TOTAL");
    screen_cursor(array_size+9, FINAL_OFFSET);
    printf("%3i\n",bonus+total_upper+total_lower );


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
    if(score < 0){
        return !SUCCESS;
    }

    if(item > NUMBER_OF_ENTRIES +1 || item <1){
        return !SUCCESS;
    }

    if(Score[item].used){
        return !SUCCESS;
    }else{
        Score[item].value = score;
        Score[item].used = 1;
        return SUCCESS;
    }
}//end score_set
