
#include <stdio.h >

int main()
{
    int marks;

    printf("enter your marks here \n ");
    scanf("%d", &marks);
    if (marks > 90 && marks < 100)
    {
        printf("your grade is A congratulation");
    }
    else if (marks > 80 && marks < 90)
    {
        printf("your grade is given B congratulation \n");
    }
    else if (marks > 70 && marks < 80)
    {
        printf("your grade is given C congratulation \n");
    }
    else if (marks > 60 && marks < 70)
    {
        printf("your grade is given D congratulation \n");
    }
    else if (marks > 50 && marks < 60)
    {
        printf("your grade is given E congratulation \n");
    }
    else if (marks > 40 && marks < 50)
    {
        printf("your grade is given F congratulation \n");
    }
    else if (marks >0   && marks <= 30)
    {
        printf("sorry you have not passed the written exams \n");
    }
    else
    {
        printf("please enter a valid value between 0-100 ");
    }

    return 0;
    //try to do this in switch cases not by if or else statement
}