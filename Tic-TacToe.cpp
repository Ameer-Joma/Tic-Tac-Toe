#include <stdio.h>

int main() {
        printf("**************************************************\n******Welcome to the Tic-Tac-Toe game******\n**************************************************\n");

    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    char player1[30]; 
    char player2[30];
    char new1[30];
    char choose;
    char restart;
    int exit = 0;
    int row, column;

    do {
        do { //Users are allowed to enter their names and their choice if they want to choose x or o
            printf("Enter name for Player 1: ");
            scanf("%s", player1);

            printf("Enter name for Player 2: ");
            scanf("%s", player2);

            printf("%s, choose 'X' or 'O': ", player1);
            scanf(" %c", &new1[0]);

            if ('a' <= new1[0] && new1[0] <= 'z') { //To support uppercase and lowercase letters
                new1[0] = new1[0] - 32;
            }

            if (new1[0] == 'X' || new1[0] == 'O') {
                if (new1[0] == 'X') {
                    new1[1] = 'O';
                } else {
                    new1[1] = 'X';
                }
                break;
            } else {
                printf("wrong choice please Choose X or O to continue.\n");
            }
        } while (1);

        printf("%s: %c\n", player1, new1[0]);
        printf("%s: %c\n", player2, new1[1]);


                do {//It changes the username in every time roles are swapped
            if (new1[0] == 'X') {
                printf("\nIt is %s's turn", player1);
            } else {
                printf("\nIt is %s's turn", player2);
            }


            printf("\nEnter:\nV to view the board \nP to play \nQ for exit\n");
            scanf(" %c", &choose);
            if ('a' <= choose && choose <= 'z') {
                choose = choose - 32;
            }

            switch (choose) {
                case 'V'://Print the board
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            printf(" %c ", board[i][j]);
                            if (j <= 1) {
                                printf("|");
                            }
                        }
                        printf("\n");
                        if (i <= 1) {
                            printf("---|---|--\n");
                        }
                    }
                    printf("\n");
                    break;

                case 'P'://
                    
                    printf("Enter the row index: ");
                    scanf("%d", &row);
                    printf("Enter the column index: ");
                    scanf("%d", &column);

                    if (row < 0 || row >= 3 || column < 0 || column >= 3 || board[row][column] != '-') {
                        printf("Invalid move\n");
                    } else {
                        board[row][column] = new1[0];

                        for (int i = 0; i < 3; i++) {
                            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
                                printf("congratulations Player %c win\n", new1);// row win
                                exit = 1;
                                break;
                            }
                            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
                                printf("congratulations Player %c win\n", new1);// column win
                                exit = 1;
                                break;
                            }
                        }

                        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
                            printf("congratulations Player %c wins\n", new1);//diagonal 1 win
                            exit = 1;
                            break;
                        }
                        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
                            printf("congratulations Player %c win\n", new1);// diagonal 2 win
                            exit = 1;
                            break;
                        }

                        int draw = 1;// check the drow
                        for (int i = 0; i < 3; i++) {
                            for (int j = 0; j < 3; j++) {
                                if (board[i][j] == '-') {
                                    draw = 0;
                                    break;
                                }
                            }    if (!draw) {

                              break;
                            }
                        }

                        if (draw) {
                            printf("It ends with a draw\n");
                            exit = 1;
                            break;
                        }

                        if (new1[0] == new1[0]) {// swap players
                            new1[0] = new1[1];
                        } else {
                            new1[0] = new1[0];
                        }
                    }
                    break;
                case 'H':            // Display game rules
                    printf("Game Rules:\n");
                    printf("1. Players take turns to place their symbol X or O on the board.\n");
                    printf("2. The first player to get three of their symbols in a row horizontally, vertically, or diagonally wins.\n");
                    printf("3. If the board is full and no one wins the game is a draw.\n");
                    printf("4. you can restart the game if it is drow or wins.\n");
                    break;

                case 'Q':
                    printf("Exiting the game.\n"); // it will Exit the game
                    exit = 1;
                    break;

                default:
                    printf("wrong choice \n");
            }

        } while (!exit);

        printf("\nDo you want to restart the game? Y if yes N if NO: ");
        scanf(" %c", &restart);
        if ('a' <= restart && restart <= 'z') { //To support uppercase and lowercase letters
                restart = restart - 32;
        }

        if (restart != 'Y') {
            printf("game ended.\n");
            break;
        }

        
        for (int i = 0; i < 3; i++) {// Reset the board
            for (int j = 0; j < 3; j++) {
                board[i][j] = '-';
            }
        }
        exit = 0;
        new1[0] = player1[0];        
        new1[1] = player2[0];        

    } while (1);

    return 0;
}
