#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
#include<windows.h>
#include<conio.h>
using namespace std;
struct data
{
    string name;
    string id;
    string address;
    int contact;
    int salary;
};
data e[50];
int employeequantity=0;


class datafunctions
  { public:
    void dataenter()
    {   int emp;
        cout<<"No Of data inputs of employee "<<endl;
        cin>>emp;
        for(int i=employeequantity;i<employeequantity+emp;i++)
        {
           cout<<"Enter the data of the Employee "<<i+1<<endl;
           cout<<"Employee name :: ";
           cin>>e[i].name;
           cout<<"Employee ID :: ";
           cin>>e[i].id;
           cout<<"Employee Address :: ";
           cin>>e[i].address;
           cout<<"Employee Contact :: ";
           cin>>e[i].contact;
           cout<<"Employee Salary :: ";
           cin>>e[i].salary;
        }
        employeequantity+=emp;
    };
    void datadelete()
    {
       if(employeequantity!=0)
       {
           char user;
           cout<<"Full Record Deletion [1]"<<endl;
           cout<<"Particular Record Deletion [2]"<<endl;
           user=getch();
           if(user=='1')
           {
               employeequantity=0;
               cout<<"All Record Have Been Cleared"<<endl;

           }
           else if(user=='2')
           {
            string id;
            cout<<"Enter the Employees ID to be deleted :: ";
            cin>>id; 

            for(int i=0;i<employeequantity;i++)
            {
                if(id==e[i].id)
                {  
                  for(int j=i;j<employeequantity;j++)                 
                   {
                      e[j].name=e[j+1].name;
                      e[j].id=e[j+1].id;
                      e[j].address=e[j+1].address;
                      e[j].contact=e[j+1].contact;
                      e[j].salary=e[j+1].salary;
                      
                    }
                    if(i==employeequantity-1)
                    {
                        cout<<"No such Record found"<<endl;
                    }
                  employeequantity--;
                  break;
                }
            }
            cout<<"Employees Data Has been Erased "<<endl;

           }
       }
       else
       {
           cout<<"Employee Record is empty"<<endl;
       }
    };
    void dataupdate()
    {
       if(employeequantity!=0)
       {
            string id;
            cout<<"Enter the Employees ID :: ";
            cin>>id;
            for(int i=0;i<employeequantity;i++)
            {
                if(id==e[i].id)
                {
                   cout<<"Current Data of the Employee"<<endl;
                   cout<<"The Data Of Employee "<<i+1<<endl;
                   cout<<"Employee name "<<e[i].name<<endl;
                   cout<<"Employee ID "<<e[i].id<<endl;
                   cout<<"Employee Address "<<e[i].address<<endl;
                   cout<<"Employee Contact "<<e[i].contact<<endl;
                   cout<<"Employee Salary "<<e[i].salary<<endl; 
                   cout<<"\n\nEnter new Details of the Employee"<<endl;

                   cout<<"\n"<<endl;

                   cout<<"Employee name :: ";
                   cin>>e[i].name;
                   cout<<"Employee ID :: ";
                   cin>>e[i].id;
                   cout<<"Employee Address :: ";
                   cin>>e[i].address;
                   cout<<"Employee Contact :: ";
                   cin>>e[i].contact;
                   cout<<"Employee Salary :: ";
                   cin>>e[i].salary;

                   cout<<"The Data Has Been Updated"<<endl;
                   Sleep(400);                                                


                  break;
                }
                else
                {
                    cout<<"No such Record Found"<<endl;
                }

            }
       }
       else
       {
           cout<<"Employee Record is Empty"<<endl;
       }
    };
    void datasearch()
    {
        if(employeequantity!=0)
        {
            string id;
            cout<<"Enter the Employees ID :: ";
            cin>>id;
            for(int i=0;i<employeequantity;i++)
            {
                if(id==e[i].id)
                {
                   cout<<"The Data Of Employee "<<i+1<<endl;
                   cout<<"Employee name "<<e[i].name<<endl;
                   cout<<"Employee ID "<<e[i].id<<endl;
                   cout<<"Employee Address "<<e[i].address<<endl;
                   cout<<"Employee Contact "<<e[i].contact<<endl;
                   cout<<"Employee Salary "<<e[i].salary<<endl; 
                  break;
                }
                else
                {
                    cout<<"No such Record Found"<<endl;
                }

            }
        }
        else
        {
            cout<<"Employee Record is empty"<<endl;
        }
    };
    void datashow()
    {
       if(employeequantity!=0)
       {
          for(int i=0;i<employeequantity;i++)
          {
              cout<<"The Data Of Employee "<<i+1<<endl;
              cout<<"Employee name "<<e[i].name<<endl;
              cout<<"Employee ID "<<e[i].id<<endl;
              cout<<"Employee Address "<<e[i].address<<endl;
              cout<<"Employee Contact "<<e[i].contact<<endl;
              cout<<"Employee Salary "<<e[i].salary<<endl;
              cout<<"press any button for menu "<<endl;
              char a;
              cin>>a;
              break;
                          
          }
       }
       else
       {
           cout<<"Employee Record Is Empty"<<endl;
           
       }
    };
  };

class functions
{
    public:
    void loading();
      
};
void functions::loading()
{
    for(int i=0;i<5;i++)
        {
          cout<<".";
          Sleep(800);//1000 as time is in miliseconds for this function
        }
}
int main()
{

/****************************PAGE 1***************************/


system("CLS");
string username,password;//string declare
cout<<"\n\n\t\t Employee Management System"<<endl;
cout<<"\n\n\t\t Please SignUp"<<endl;
cout<<"\t\n"<<endl;
cout<<"\t\t Enter Your Username -> ";
getline(cin,username);
cout<<"\t\t Enter Your Password -> ";
getline(cin,password);
cout<<"\n\n";
cout<<"\n\t Please Wait While Your Account is Being Created";
functions load;//object declare
load.loading();//function call
cout<<endl;
cout<<"\n\t Your Id Has Been Created Successfully ! "<<endl;
Sleep(2500);

start1:

system("CLS");//create a new page and move to it

/****************************PAGE 2****************************/


system("CLS");
string usernamel,passwordl;
cout<<"\n\n\t\t Employee Management System"<<endl;
cout<<"\n\n\t\t Login "<<endl;

cout<<"\n\n\t\t Username:: ";
getline(cin,usernamel);
cout<<"\n\n\t\t Password:: ";
getline(cin,passwordl);
page2:
if(username==usernamel&&password==passwordl)
{
  system("CLS");
  
  
  /****************************PAGE 3****************************/
  while(true)
  {   
      
      char user;
      cout<<"\n\nPress 1 to enter data "<<endl;
      cout<<"Press 2 to show data "<<endl;
      cout<<"Press 3 to search data "<<endl;
      cout<<"Press 4 to update data "<<endl;
      cout<<"Press 5 to delete data "<<endl;
      cout<<"Press 6 to logout"<<endl;
      cout<<"Press 7 to exit"<<endl;
      cout<<""<<endl;
      datafunctions o;
      user=getch();
      switch(user)
      {
          
          case '1': o.dataenter();
          break;
          case '2': o.datashow();
          break;
          case '3': o.datasearch();
          break;
          case '4': o.dataupdate();
          break;
          case '5': o.datadelete();
          break;
          case '6':
          goto page1;
          break;
          case '7':
          break;
          default :
          cout<<"\a Invalid input"<<endl;
          break;
      }
  }

}

else
{
    cout<<"The Username or Password is Incorrect"<<endl;
    Sleep(1500);
    cout<<"To Login again press->[1]"<<endl;
    cout<<"To SignUp again press->[2]"<<endl;    
    cout<<"To close Press Any Button"<<endl;
    cout<<"::> ";
    int input;
    cin>>input;
    if(input==1)
    {
        goto page1;
    }

    else if(input==2)
    {
        goto start;
    }
    
    else
    {
        return 0;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
start:
system("CLS");

cout<<"\n\n\t\t Employee Management System"<<endl;
cout<<"\n\n\t\t Please SignUp"<<endl;
cout<<"\t\n"<<endl;
cout<<"\t\t Enter Your Username -> ";
cin>>username;
cout<<"\t\t Enter Your Password -> ";
cin>>password;
cout<<"\n\n";
cout<<"\n\t Please Wait While Your Account is Being Created";

load.loading();//function call
cout<<endl;
cout<<"\n\t Your Id Has Been Created Successfully ! "<<endl;
Sleep(2500);
goto start1;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
page1:
system("CLS");

cout<<"\n\n\t\t Employee Management System"<<endl;
cout<<"\n\n\t\t Login "<<endl;

cout<<"\n\n\t\t Username:: ";
getline(cin,usernamel);
cout<<"\n\n\t\t Password:: ";
getline(cin,passwordl);
goto page2;
return 0;
}