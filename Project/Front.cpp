#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
#include<windows.h>
#include<conio.h>
#include<iomanip>
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

class functions
{
    public:
    void loading();
    void revoke();
      
};
void functions::loading()
{
    for(int i=0;i<5;i++)
        {
          cout<<".";
          Sleep(700);//700 as time is in miliseconds for this function
        }
}
void functions::revoke()
{
    for(int i=0;i<500;i++)
        {
          cout<<"(*-*)";
          Sleep(8);//8 as time is in miliseconds for this function
          
        }
}

int adminAccess()
{
    
    functions l1;
    string key;
    string Adminkey="211110";
    int revokecount=0;
    system("CLS");
    cout<<"\n"<<setw(54)<<right<<"  ----------------------------";
    cout<<"\n"<<setw(50)<<right<<" ADMIN ACCESS INTIALISING";
    l1.loading();
    cout<<"\n"<<setw(54)<<right<<"  ----------------------------";
    Sleep(300);
    admin:
    cout<<"\n\n\t\t Enter the ADMIN KEY :: ";
    cin>>key;
    if(revokecount>=2)
    {
        cout<<"\n"<<setw(54)<<right<<"  ------------------------------";
        cout<<"\n"<<setw(53)<<right<<"   AUTHORISATION REVOKE!!!    ";
        cout<<"\n"<<setw(53)<<right<<"EMERGENCY SHUTDOWN INITIATING ";
        l1.loading();
        cout<<"\n"<<setw(54)<<right<<"  ------------------------------";
        l1.revoke();
        return 0;
        
        
    }
    
    if(key==Adminkey&&revokecount<2)
    {
        system("CLS");
        cout<<"\n"<<setw(54)<<right<<"  ----------------------------";
        cout<<"\n"<<setw(53)<<right<<" ADMIN ACCESS GRANTED ";
        l1.loading();
        cout<<"\n"<<setw(54)<<right<<"  ----------------------------";
        Sleep(700);
        return 101;
    }
    else
    {
        revokecount++;
        goto admin;
    }
    
    
    
}
int close()
{
    return 0;
}
class datafunctions
  { public:
    void dataenter()
    {   
        system("CLS");
        if(adminAccess()==101)
        {
        dataEnter:
        
        int emp;
        cout<<"\n\n\t\t No Of data inputs of employee ";
        cin>>emp;
        for(int i=employeequantity;i<employeequantity+emp;i++)
        {
           cout<<"\t\t Enter the data of the Employee "<<i+1<<endl;
           cout<<"\t\t Employee name :: ";
           cin>>e[i].name;
           cout<<"\t\t Employee ID :: ";
           cin>>e[i].id;
           cout<<"\t\t Employee Address :: ";
           cin>>e[i].address;
           cout<<"\t\t Employee Contact :: ";
           cin>>e[i].contact;
           cout<<"\t\t Employee Salary :: ";
           cin>>e[i].salary;
        }
        employeequantity+=emp;
        }
        else if(adminAccess()==0)
        {
            close();
        }
    };
    void datadelete()
    {
        system("CLS");
       if(adminAccess()==101)
       { 
       if(employeequantity!=0)
       {
           char user;
           cout<<"\n\t\t Full Record Deletion [1]"<<endl;
           cout<<"\t\t Particular Record Deletion [2]"<<endl;
           user=getch();
           if(user=='1')
           {
               employeequantity=0;
               cout<<"\t\t All Record Have Been Cleared"<<endl;

           }
           else if(user=='2')
           {
            string id;
            cout<<"\n\t\t Enter the Employees ID to be deleted :: ";
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
                        cout<<"\n\t\t No such Record found"<<endl;
                    }
                  employeequantity--;
                  break;
                }
            }
            cout<<"\n\t\t Employees Data Has been Erased "<<endl;

           }
       }
       else
       {
           cout<<"\n\t\t Employee Record is empty"<<endl;
       }
       }
       else if(adminAccess()==0)
        {
            close();
        }

    };
    void dataupdate()
    {
        system("CLS");
     if(adminAccess()==101)
     {  
       if(employeequantity!=0)
       {
           system("CLS");
            string id;
            cout<<"\n\t\t Enter the Employees ID :: ";
            cin>>id;
            for(int i=0;i<employeequantity;i++)
            {
                if(id==e[i].id)
                {
                   cout<<"\n"<<setw(54)<<right<<"---------------------------";
		           cout<<"\n"<<setw(53)<<right<<" CURRENT EMPLOYEE PROFILE  ";
			       cout<<"\n"<<setw(54)<<right<<"---------------------------";
                   
                   cout<<"\t\t Employee name "<<e[i].name<<endl;
                   cout<<"\t\t Employee ID "<<e[i].id<<endl;
                   cout<<"\t\t Employee Address "<<e[i].address<<endl;
                   cout<<"\t\t Employee Contact "<<e[i].contact<<endl;
                   cout<<"\t\t Employee Salary "<<e[i].salary<<endl; 
                   cout<<"\n\n\t\t Enter new Details of the Employee"<<endl;

                   cout<<"\n"<<endl;

                   cout<<"\n"<<setw(54)<<right<<"---------------------------";
		           cout<<"\n"<<setw(53)<<right<<"  UPDATE EMPLOYEE PROFILE  ";
			       cout<<"\n"<<setw(54)<<right<<"---------------------------";

                   cout<<"\t\t Employee name :: ";
                   cin>>e[i].name;
                   cout<<"\t\t Employee ID :: ";
                   cin>>e[i].id;
                   cout<<"\t\t Employee Address :: ";
                   cin>>e[i].address;
                   cout<<"\t\t Employee Contact :: ";
                   cin>>e[i].contact;
                   cout<<"\t\t Employee Salary :: ";
                   cin>>e[i].salary;

                   cout<<"\n\t\t The Data Has Been Updated"<<endl;
                   Sleep(400);
                   system("CLS");                                                


                  break;
                }
                else
                {
                    cout<<"\n\t\t No such Record Found"<<endl;
                    system("CLS");
                }

            }
       }
       else
       {
           cout<<"\n\t\t Employee Record is Empty"<<endl;
       }
      }
      else if(adminAccess()==0)
        {
            close();
        }
    };
    void datasearch()
    {
        system("CLS");
        if(employeequantity!=0)
        {
            
            string id;
            cout<<"\n\t\t Enter the Employees ID :: ";
            cin>>id;
            for(int i=0;i<employeequantity;i++)
            {
                if(id==e[i].id)
                {

                   cout<<"\n"<<setw(54)<<right<<"---------------------------";
		           cout<<"\n"<<setw(53)<<right<<"   VIEW EMPLOYEE PROFILE   ";
			       cout<<"\n"<<setw(54)<<right<<"---------------------------";
                   cout<<"\n\t\t The Data Of Employee "<<i+1<<endl;
                   cout<<"\t\t Employee name "<<e[i].name<<endl;
                   cout<<"\t\t Employee ID "<<e[i].id<<endl;
                   cout<<"\t\t Employee Address "<<e[i].address<<endl;
                   cout<<"\t\t Employee Contact "<<e[i].contact<<endl;
                   cout<<"\t\t Employee Salary "<<e[i].salary<<endl; 
                  break;
                }
                else
                {
                    cout<<"\n\t\t No such Record Found"<<endl;
                    Sleep(500);
                    system("CLS");
                }

            }
        }
        else
        {
            cout<<"Employee Record is empty"<<endl;
            Sleep(500);
            system("CLS");
        }
    };
    void datashow()
    {
        system("CLS");
       if(employeequantity!=0)
       {
          for(int i=0;i<employeequantity;i++)
          {
              cout<<"\n"<<setw(54)<<right<<"---------------------------";
		      cout<<"\n"<<setw(53)<<right<<"  EMPLOYEE DATA ID :: "<<i+1;
			  cout<<"\n"<<setw(54)<<right<<"---------------------------";
              cout<<"\t\t Employee name "<<e[i].name<<endl;
              cout<<"\t\t Employee ID "<<e[i].id<<endl;
              cout<<"\t\t Employee Address "<<e[i].address<<endl;
              cout<<"\t\t Employee Contact "<<e[i].contact<<endl;
              cout<<"\t\t Employee Salary "<<e[i].salary<<endl;
              cout<<"\t\t press any button for menu "<<endl;
              char a;
              cin>>a;
              break;
                          
          }
       }
       else
       {
           cout<<"\n\t\t Employee Record Is Empty"<<endl;
           Sleep(500);
           system("CLS");
       }
    };
  };


int main()
{

/****************************PAGE 1***************************/

start:
system("CLS");
string username,password;//string declare
cout<<"\n"<<setw(54)<<right<<"----------------------------";
cout<<"\n"<<setw(53)<<right<<" EMPLOYEE MANAGEMENT SYSTEM ";
cout<<"\n"<<setw(54)<<right<<"----------------------------";
cout<<"\n\n\n \t\t Employee Management System"<<endl;
cout<<"\n\n\t\t Please SignUp"<<endl;
cout<<"\t\n"<<endl;
cout<<"\t\t Enter Your Username -> ";
cin>>username;
cout<<endl;
cout<<"\t\t Enter Your Password -> ";
cin>>password;


        string::iterator it;
    for(it=username.begin();it!=username.end();it++)
    {
        if (*it>0&&*it<48||*it>122&&*it<127||(*it>57&&*it<65)||(*it>90&&*it<97))
		{
			cout<<"\n\n"<<right<<setw(25)<<" ";
			cout<<setw(30)<<left<<"Name cannot contain SPECIAL CHARACTERS...";
            Sleep(1300);
			goto start;
		}
        }
    

if(username.length() < 4)
	{
		cout<<"\n"<<setw(70)<<right<< " Username length must be atleast 4 characters long";
        Sleep(1500);
		cin.get();
		goto start;
	}
    
   
	else  
	{
		
		
		if(password.length() < 6)
		{
			cout<<"\n"<<setw(70)<<right<< " Password length must be atleast 6 characters long";
            Sleep(1500);
            goto start;
            
		}
		else 
		{
            cout<<"\n\n";
cout<<setw(70)<<"\n\t Please Wait While Your Account is Being Created";
functions load;//object declare
load.loading();//function call
cout<<endl;
cout<<setw(70)<<"\n\t Your Id Has Been Created Successfully ! "<<endl;
Sleep(2500);



/****************************PAGE 2****************************/
page1:
system("CLS");//create a new page and move to it
string usernamel,passwordl;
cout<<"\n\n"<<endl;
cout<<"\n"<<setw(49)<<right<<"--------------------";
cout<<"\n"<<setw(48)<<right<<"  EMPLOYEE LOGIN  ";
cout<<"\n"<<setw(49)<<right<<"--------------------";

cout<<"\n\n\t\t Username:: ";
cin>>usernamel;
cout<<"\n\n\t\t Password:: ";
cin>>passwordl;

if(username==usernamel&&password==passwordl)
{
  system("CLS");
  
  
  /****************************PAGE 3****************************/
  while(true)
  {   
      
      char user;
      cout<<"\n"<<setw(51)<<right<<"-----------------------";
	  cout<<"\n"<<setw(48)<<right<<"  EMPLOYEE MENU  ";
	  cout<<"\n"<<setw(51)<<right<<"-----------------------";
	  cout<<"\n\n\t\t          ___________________________ "<<endl;
      cout<<"\t\t         |> ENTER DATA(admin) -->[1]  |"<<endl;
      cout<<"\t\t         |> SHOW DATA         -->[2]  |"<<endl;
      cout<<"\t\t         |> SEARCH DATA       -->[3]  |"<<endl;
      cout<<"\t\t         |> UPDATE DATA(admin)-->[4]  |"<<endl;
      cout<<"\t\t         |> DELETE DATA(admin)-->[5]  |"<<endl;
      cout<<"\t\t         |> LOGOUT USER       -->[6]  |"<<endl;
      cout<<"\t\t         |> CLOSE PROGRAMME   -->[7]  |"<<endl;
      cout<<"\t\t          ---------------------------- "<<endl;
      datafunctions o;
      functions l;
      cout<<"\n\t\t::";
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
          case '6': cout<<"\n\n\t\t LOGGING YOU OUT";
                   l.loading();
          goto page1;
          break;
          case '7':
          cout<<"\n\n\t\t VISIT AGAIN!!";
                   l.loading();
          return 0;
          default :
          cout<<"\a Invalid input"<<endl;
          Sleep(500);
          break;
      }
  }

}

else
{
    cout<<"\n\n\t\t The Username or Password is Incorrect"<<endl;
    Sleep(1500);
    cout<<"\t\t ______________________________"<<endl;
    cout<<"\t\t|> To Login again press ->[1]   |"<<endl;
    cout<<"\t\t|> To SignUp again press->[2]   |"<<endl;    
    cout<<"\t\t|> To close Press Any Button    |"<<endl;
    cout<<"\t\t ------------------------------"<<endl;
    cout<<"\t\t::> ";
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

        }
    }	

return 0;
}