#include <stdio.h>

//printRow: This is a function that prints a single row of the screen to the board.
//Parameters: z1, z2, z3: the values of the tic_tac_toe board cells in a row and each var represents what will be inside of a cell.
//Returns: None

void printRow(char z1, char z2, char z3) {
        printf("     |      |      \n");
        printf("  %c |  %c  |  %c  \n", z1, z2, z3);
        printf("     |      |      \n");
        //these print the bars that will end up constructing the board 
}

//showBoard: Prints the board to the screen
//Parameters:   board: A ptr to an array of 9 characters representing the tic-tac-toe board.
//              Legal values for each entry are ' ','X','O'
//Returns:      None
void showBoard(char *board){
        printf("\n");
        printRow(board[0], board[1], board[2]);
        printf("-----------------\n");
        printf("-----------------\n");
        printRow(board[3], board[4], board[5]);
        printf("-----------------\n");
        printRow(board[6], board[7], board[8]);
        printf("\n");
//These are a series of print statements that work in conjunction with the printRow function to bring the board to the screen
}

//getMove:      Processes a player move
//Paramters:    
//board: A pointer to an array of 9 characters representing the tic-tac-toe board.
//player: The symbol for the current player (X for 1,O for 2)
//Returns:      
//None
void getMove(char *board, char playerSymbol){
        int position;
        char buffer[255];

        while (1) {
                printf("Please enter a position(1-9) for Player $c: ", playerSymbol);
                scanf(" %s", buffer);
                sscanf(buffer, "%d", &position);
//this prevents an infinite loop
        if (position >= 1 && position <= 9 && board[position - 1] == ' '){
        board[position - 1] = playerSymbol;
        return;
        }
        printf("Sorry, that's an invalid position, please try again!\n");
	  else {
		printf("Sorry, that's an invalid position, please try again!\n");
 }
}
}

//checkWin: checks the board to see if there is a win for the given player
//Parameters: board: A ptr to an array of 9 characters representing the tic-tac-toe board.
//playerSymbol: The symbol for the player being checked for a win ('X','O')
//Returns:   
//non-zero if a win occurs for playerSymbol, zero otherise
int checkWin(char *board, char playerSymbol){
//Checking rows
        if ((board[0] == playerSymbol && board[1] == playerSymbol && board[2] == playerSymbol) ||
        (board[3] == playerSymbol && board[4] == playerSymbol && board[5] == playerSymbol) ||
        (board[6] == playerSymbol && board[7] == playerSymbol && board[8] == playerSymbol)) {
        return 1; //this indicates there is a win
        }

//Checking columns
        if ((board[0] == playerSymbol && board[3] == playerSymbol && board[6] == playerSymbol) ||
        (board[1] == playerSymbol && board[4] == playerSymbol && board[7] == playerSymbol) ||
        (board[2] == playerSymbol && board[5] == playerSymbol && board[8] == playerSymbol)) {
        return 1;  //this indiciates there is a win
        }
//Checking diagonals
        if ((board[0] == playerSymbol && board[4] == playerSymbol && board[8] == playerSymbol) ||
        (board[2] == playerSymbol && board[4] == playerSymbol && board[6] == playerSymbol)) {
        return 1;  // this indicates there is a win
        }

        return 0; //  this is the result of a loss.
}
//checkBoard: checks the board to see if the game is over
//Parameters:   board: A pointer to an array of 9 characters representing the tic-tac-toe board.
//winner: A pointer to an integer to accept the current winner.  0 indicates no winner, otherwise it is the player number
//Returns: 0 if the game is over, non-zero if the game should continue
int checkBoard(char *board, int *winner)
{
        if (checkWin(board, 'X'))
        {
                *winner = 1;
                return 0;
        }
        if (checkWin(board, 'O'))
        {
                *winner = 2;
                return 0;
        }
        int spaceCount = 0;
        for (int i = 0; i < 9; i++)
        {
                if (board[i] == ' ')
                {
                        spaceCount++;
                }
        }
        return spaceCount;
}

//The main function is a compilation of the rest of the previous functions and serves as the "main" function that runs the game 
int main(int argc, char **argv)
{
        char board[9] = {' ', ' ', ' ', ' ', ' ', ' ',  ' ', ' ', ' '};
        char symbols[3]={' ','X','O'};
        int player = 2;
        int winner = 0;
        int running = 1;
        while (running)
        {
                player = (player++) % 2 + 1;
                showBoard(board);
                getMove(board, symbols[player]);
                running = checkBoard(board, &winner);
        }
        showBoard(board);
        if (winner!=0){
                printf("Congratulations player %d!!! You win.\n",player);
        }else{
                printf("It's a tie!!!\n");
        }
        return 0;
}
