 #include<stdio.h  > 
void display(); //funtion prototype (funtion is intialised) $1

int main() { // sleeps after $1 
            //wakes up at $4
int a;
display();  //function call (here the fucntion is to display) EXECUTE
            //the body is printed after function call $2
//$5 the code below the function call are executed 

return 0; //$6
}

void display() {  //body of the function it shows what will be displayed
                  //function definition  $3
printf("hello im ansuman \n ");

}

//$1 - order of running
//control means in which place or under the function is running