 #include<stdio.h  > 
 #include<ctype.h>
int main() { 

char alphabet;

printf("enter an  alphabet ::");

putchar(' . ');

alphabet = getchar();

if (islower(alphabet)){

    printf("the alphabet in upper case letter is :");
    putchar(toupper(alphabet));

    
}
else{putchar(tolower(alphabet));}

return 0;
}