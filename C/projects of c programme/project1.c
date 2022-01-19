
//------------------------------------------------------------------------------------|
//....................................................................................|
//....................................................................................|
//....................................................................................|
//....................................................................................|
//THE NUMBER GUESSING GAME............................................................|
//....................................................................................|
//....................................................................................|
//....................................................................................|
//....................................................................................|
//------------------------------------------------------------------------------------|

#include <stdio.h  >
#include <stdlib.h>
#include <time.h>

int main()
{

    int num;
    int guess, nguess = 0;
    int press, press1, press2, press3, press4, press5;

    srand(time(0));

    num = rand() % 100 + 1; //generate random number between 1 to 100

    //printf("the no. to guess is %d \n", num); //commented as it should be hidden

    printf("welcome to the guessing game \n");
    printf("\n");
    printf("if you want to play the game please press 1 \n");
    
    printf("\n");
    printf("if you want to get a random no. press 2 \n");
    
    printf("\n");
    printf(" or enter any key to exit\n");
    printf("\n ::> ");


    scanf("%d", &press);

    if (press == 1)
    {
        do
        {

            printf("guess the number between 1 to 100  \n ::>");

            scanf("%d", &guess);

            

            if (num == guess)
            {
                printf("congratulation The Number is %d you guessed is right \n", guess);
            }
            else if (guess > num)
            {
                printf("lower number please!! \n ");
            }
            else if (guess < num)
            {
                printf("higher number please!! \n ");
            }
            else if (guess > 100)
            {

                printf("follow instructions and please try again \n");
                continue;
            }

            nguess++;

        } while (guess != num);
        printf("\n");
        printf("you guessed the right number in %d chances \n", nguess);

        printf("\n enter amy key to exit");
        scanf("%d", &press4);
    }

    else if (press == 2)
    {

        srand(time(0));

        num = rand() % 100 + 1; //generate random number between 1 to 100

        printf("the random number is %d \n", num);

        printf("\n");

        printf("press 1 to exit 2 to enter the game \n ");

    

        printf("\n ::>");

        if (press1 == 1)
        {
            printf("thank you \n ");
        }

        else if (press1 == 2)


        {


            printf("WELCOME PLEASE START \n ");

            do
            {

                printf("guess the number between 1 to 100 ::  \n");
                scanf("%d", &guess);

                printf("\n");

                if (num == guess)
                {
                    printf("congratulation The Number is %d you guessed is right \n", guess);
                }
                else if (guess > num)
                {
                    printf("lower number please!! \n");
                }
                else if (guess < num)
                {
                    printf("higher number please!! \n ");
                }
                else if (guess > 100)
                {

                    printf("follow instructions and please try again \n");
                    continue;
                }

                nguess++;

            } while (guess != num);
            printf("\n");
            printf("you guessed the right number in %d chances \n", nguess);


            printf("press 1 to exit \n ");

            printf("::>");

            scanf("%d", &press3);
            if (press3 == 1)
            {
                printf("thank you");
            }
        }

        else
        {
            printf("enter any key to exit \n");

            printf("::>");

            scanf("%d", &press5);
        }
    }

    else
    {

        printf("thank you  \n");
    }

    return 0;
}