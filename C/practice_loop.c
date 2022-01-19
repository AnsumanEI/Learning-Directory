 #include<stdio.h  > 
 
int main() {

int natural = 0; //intial loop counter


printf("enter a nnumber between 10 - 20 \n");
scanf("%d" , &natural);

while (natural>=10 && natural<=20){

    printf(" %d \n" , natural);
    natural++;
}
return 0;
}