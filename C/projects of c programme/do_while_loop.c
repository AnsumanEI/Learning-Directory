#include <stdio.h  >

int main()
{
    int guess;
    int num; //delete
    int nguess=1;

    do
    {

        printf("guess the number between 1 to hundred ::  \n");
        scanf("%d", &guess);

        if (num == guess)
        {
            printf("congratulation The Number %d you guessed is right \n", guess);
        }
        else if (guess > num)
        {
            printf("the guessed number is greater than the original number \n");
        }
        else if (guess < num)
        {
            printf("the guessed number is smaller than the original number \n ");
        }
        else
        {
            printf("you guessed the right number in %d attempts  \n " ,nguess);
        }

        nguess++;

    } while (guess!=num);

    return 0;
}