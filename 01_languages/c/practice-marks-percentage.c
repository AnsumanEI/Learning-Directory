#include <stdio.h>
#include <math.h>

int main()
{
    int  maths, english, physics , a;
    float percentage, b, c;
    printf("enter your mark in maths  (out of 70) \n ");
    scanf("%d", &maths);
    printf("enter your mark in english (out of 70) \n ");
    scanf("%d", &english);
    printf("enter your mark in physics (out of 70) \n ");
    scanf("%d", &physics);

    b = maths + english + physics;
    c = 0.476190476;

    percentage = b * c;

    if (maths < 71 && english < 71 && physics < 71)
    {
        if ( maths > 33 && english > 33 && physics > 33 && percentage > 40)
        {

            printf("congratulation you have passed your total percentage is %f  \n", percentage);
        }
        else if (maths < 33 && physics < 33 && english < 33)
        {
            printf(" you have failed in all subjects \n");
        }
        else if (physics < 33)
        {
            printf("you have failed in physics \n");
        }
        else if (english < 33)
        {
            printf("you have failed in english \n");
        }
        else if (maths < 33)
        {
            printf(" you have failed in  maths \n");
        }
        else
        {
            printf("please contact your teacher for more enquiry \n");
        }
    }
    else
    {
        printf("please enter valid marks to get your resullt \n ");
    }
    printf("press 1 to exit \n");
    scanf("%d", &a);
    if (a == 1)
    {
        printf("thank you");
    }
    else
    {
        printf("not thank you");
    }

    return 0;
}
