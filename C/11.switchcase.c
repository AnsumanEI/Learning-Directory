#include <stdio.h  >

int main()
{
    int rating;
    printf("enter your rating (1-5) \n");
    scanf("%d", &rating);
    switch (rating)
    {
    case 1:
        printf("your rating has been registerd (1) \n");
        break;
    case 2:
        printf("your rating has been registerd (2) \n");
        break;
    case 3:
        printf("your rating has been registerd (3) \n");
        break;
    case 4:
        printf("your rating has been registerd (4) \n");
        break;
    case 5:
        printf("your rating has been registerd (5) \n");
        break;
    default:
        printf("please enter a valid rating");

        break;
    }
    return 0;
}