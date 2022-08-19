 // RONIT SINGH
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define row 4
#define col 4
void display(int arr[row][col]);
void swap(int *, int *);
int issort(int arr[row][col]);
int up(int arr[row][col]);
int down(int arr[row][col]);
int left(int arr[row][col]);
int right(int arr[row][col]);
void rule();
void showmove(int, char [20]);
int posrow = row-1;
int poscol = col-1;
int main()
{
    int arr[row][col] = {
        {8, 3, 7, 5},
        {4, 9, 2, 1},
        {12, 13, 11, 6},
        {14, 10, 15, 0}};
    int moves = 100, flag;
    char key;
    char name[20];
    rule();
    system("cls");
    printf("\n\n Enter Your Name : ");
    fgets(name, 20, stdin);
    fflush(stdin);
    showmove(moves, name);
    display(arr);
    while (1)
    {
    	fflush(stdin);
        key = getch();
        fflush(stdin);
        if (key >= 97 && key <= 112)
            key = key - 32;
        switch (key)
        {
        case 69:
        	printf("\n\n\t\tOOPS..! %s You have exit the Game", name);
            printf("\n Thank You For Playing, %s", name);
            exit(1);
        case 65:
			flag=left(arr);
            if (flag)
            {
                moves--;
                system("cls");
                showmove(moves, name);
                display(arr);
            }
            break;
        case 87:
			flag = up(arr);
            if (flag)
            {
                moves--;
                system("cls");
                showmove(moves, name);
                display(arr);
            }
            break;
        case 68:
			flag = right(arr);
            if (flag)
            {
                moves--;
                system("cls");
                showmove(moves, name);
                display(arr);
            }
            break;
        case 83:
			flag=down(arr);
            if (flag)
            {
                moves--;
                system("cls");
                showmove(moves, name);
                display(arr);
            }
            break;

        default:
            printf("\n\tInvalid Choice\n");
            break;
        }
        if (issort(arr))
        {
            printf("\n\n\t\tCongratulations..! %s You have won the Game", name);
            break;
        }
        else if (moves == 0)
        {
            printf("\n\n\t\tSorry..! %s You have lost the Game", name);
            break;
        }
    }

    return 0;
}
void display(int arr[row][col])
{
    int i, j;
    printf("\n\n\n\t|");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
                printf("     |");
            else
                printf("%4d |", arr[i][j]);
        }
        if (i < row - 1)
            printf("\n\t|");
    }
}
void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
int issort(int arr[row][col])
{
    int max, i, j;
    max = arr[0][0];
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (arr[i][j] != 0)
            {
                if (max > arr[i][j])
                    return 0;
                else
                    max = arr[i][j];
            }
        }
    }
    return 1;
}

int up(int arr[row][col])
{
    int i, j;
    if (posrow != 0)
    {
        swap(&arr[posrow][poscol], &arr[posrow - 1][poscol]);
        posrow--;
        return 1;
    }
    return 0;
}
int down(int arr[row][col])
{
    int i, j;
    if (posrow != row - 1)
    {
        swap(&arr[posrow][poscol], &arr[posrow + 1][poscol]);
        posrow++;
        return 1;
    }
    return 0;
}
int left(int arr[row][col])
{
    int i, j;
    if (poscol != 0)
    {
        swap(&arr[posrow][poscol], &arr[posrow][poscol - 1]);
        poscol--;
        return 1;
    }
    return 0;
}
int right(int arr[row][col])
{
    int i, j;
    if (poscol != col - 1)
    {
        swap(&arr[posrow][poscol], &arr[posrow][poscol + 1]);
        poscol++;
        return 1;
    }
    return 0;
}
void rule()
{
    int win[row][col] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0}};
    printf("\n\t\tRule OF THIS GAME\n");
    printf("\n1. You can move only one step at a time by using following key : ");
    printf("\n\t A\t: Move Left");
    printf("\n\t W\t: Move Up");
    printf("\n\t D\t: Move Right");
    printf("\n\t S\t: Move Down");
    printf("\n\n2. You can move numbers at empty position only");
    printf("\n\n3. For Each valid move\t: Your total number of move will be decreased by 1");
    printf("\n\n4. Wining Situation\t: Numbers in a 4*4 matrix should be in order from 1 to 15");
    printf("\n\n\t\t Wining Situation");
    display(win);
    printf("\n\n5. You can exit the game at any time by pressing \'E\'");
    printf("\n So Try to win in minimum no of moves");
    printf("\n\t\tHappy Gaming , Good Luck\n");
    printf("\n\n Enter any key to start________");
    fflush(stdin);
    getch();
    fflush(stdin);
}
void showmove(int move, char name[20])
{
    printf("\n\n\t\tRemaining Moves : %d",move);
}
