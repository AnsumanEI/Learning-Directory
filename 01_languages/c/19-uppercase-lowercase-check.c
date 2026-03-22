 #include<stdio.h  > 
 
int main() { 
char ch;
printf("enter your character here %c%c%c%c%c%c%c%c%c \n " );
scanf("%c"  , &ch ,&ch, &ch ,&ch, &ch ,&ch, &ch ,&ch, &ch);

if(ch<=122 && ch>=97){
    printf("the letter is lowercase ");
}
else {
    printf("the letter is uppercase");

}
return 0;
}