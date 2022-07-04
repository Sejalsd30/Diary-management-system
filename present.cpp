#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<limits>
#include<conio.h>
using namespace std;

class diary
 {
     public:
     char date[20];
     char time[6];
     char name[30];
     char place[25];
     char agenda[500];
     char note[500];
     char note1[500];
     char tho[500];

int password()
{
    system("cls");
    char s[10] = { 0 };
    char con[10];
    int i;
    ifstream inFile;
    inFile.open("password1.txt",ios::in);

    if (inFile.is_open())
    {
        for (int i = 0; i < 9; i++)
        {
            inFile >> con[i];

        }

        inFile.close();

    }
    cout<<"\n\t\t--> ENTER THE PASSWORD: ";
    for (i = 0; i < 10;i++) {
      s[i] = _getch();   _putch('*');
        if (s[i] == 13)
            break;
    }
    int num=strlen(s)-1;
   int res=strncmp(con,s,num);
   if(res==0)
   {
   	cout<<"\n\n\t\t***PASSWORD CORRECT***"<<endl;
   	return 0;
   }
   else
   {
   cout<<"\n\n\t\t***PASSWORD INCORRECT***"<<endl;
   return 1;
   }

}

void addrecord()

{
       cout<<"\n\n\t\t***************************\n";
       cout<<"\t\t* WELCOME TO THE ADD MENU *";
       cout<<"\n\t\t***************************\n\n";
       cout<<"\n\tENTER DATE OF YOUR RECORD:[dd-mm-yyyy]: ";
       cin.ignore(numeric_limits<streamsize>::max(),'\n');
       cin>>date;
       cout<<"\n\tENTER TIME:[hh:mm]: ";
       cin.ignore(numeric_limits<streamsize>::max(),'\n');
       cin>>time;
       cout<<"\n\tENTER NAME: ";
       cin.ignore(numeric_limits<streamsize>::max(),'\n');
       cin>>name;
       cout<<"\n\tENTER PLACE: ";
       cin.ignore(numeric_limits<streamsize>::max(),'\n');
       cin>>place;
       cout<<"\n\tENTER TODAY'S AGENDA: ";
       cin.ignore(numeric_limits<streamsize>::max(),'\n');
       cin>>agenda;
       cout<<"\n\tENTER 1ST NOTE: ";
       cin.ignore(numeric_limits<streamsize>::max(),'\n');
       cin>>note;
       cout<<"\n\tENTER 2ND NOTE: ";
       cin.ignore(numeric_limits<streamsize>::max(),'\n');
       cin>>note1;
       cout<<"\n\tENTER TODAY'S THOUGHT: ";
       cin.ignore(numeric_limits<streamsize>::max(),'\n');
       cin>>tho;
       ofstream myfile;
       myfile.open("b.txt",ios::out);
       myfile<<date<<endl;
       myfile<<time<<endl;
       myfile<<name<<endl;
       myfile<<place<<endl;
       myfile<<agenda<<endl;
       myfile<<note<<endl;
       myfile<<note1<<endl;
       myfile<<tho<<endl;
       myfile.close();
       cout<<"\n\t\tTHANK YOU...";
	   cout<<"\n\t\tYOUR RECORD IS ADDED...\n"<<endl;

}

void viewrecord()

{
   cout<<"\n\n\t\t**************************\n";
   cout<<"\t\t*HERE IS THE VIEWING MENU*";
   cout<<"\n\t\t**************************\n\n";
   ifstream infile;
   infile.open("b.txt");
   infile >> date;
   cout<<"\n\t\tDATE: "<< date << endl;
   infile>>time;
   cout<<"\n\t\tTIME: "<<time<<endl;
   infile>>name;
   cout<<"\n\t\tNAME: "<<name<<endl;
   infile>>place;
   cout<<"\n\t\tPLACE: "<<place<<endl;
   infile>>agenda;
   cout<<"\n\t\tTODAY'S AGENDA1: "<<agenda<<endl;
   infile>>note;
   cout<<"\n\t\t1ST NOTE: "<<note<<endl;
   infile>>note1;
   cout<<"\n\t\t2ND NOTE: "<<note1<<endl;
   infile>>tho;
   cout<<"\n\t\tTODAY'S THOUGHT: "<<tho<<endl;
   infile.close();

   }


void deleterecord()

{
    int x;
    cout<<"\n\n\t\t********************************\n";
    cout<<"\t\t*HERE IS THE DELETE RECORD MENU*";
    cout<<"\n\t\t********************************\n\n";
    x=remove("b.txt");
    if(x==0)
    cout<<"\n\t\tRECORD DELETED SUCCESSFULLY!";
    else
    cout<<"\n\t\tRECORD DOES NOT EXIST!";
    cout<<endl;
}

void editpassword()

{
    char pass1[10], pass2[10];
    cout<<"\n\n\t\t**********************************\n";
    cout<<"\t\t*HERE IS THE CHANGE PASSWORD MENU*";
    cout<<"\n\t\t**********************************\n\n";
    cout <<"\n\t\tENTER YOUR NEW PASSWORD: ";
    int i;
    for (i = 0; i < 10;i++) {
    pass1[i] = _getch();   _putch('*');
    if (pass1[i] == 13)
    break;
    }
    cout <<"\n\t\tRE-ENTER YOUR NEW PASSWORD: ";


int j;
    for (j= 0; j < 10;j++) {
    pass2[j] = _getch();   _putch('*');
    if (pass2[j] == 13)
    break;
    }
    int num=strlen(pass1)-1;
    int c=strncmp(pass1,pass2,num);
    if (c==0)
    {
        cout <<"\n\n\t\t***YOUR PASSWORD HAS BEEN CHANGED SUCCESSFULLY!***"<<endl;
        ofstream inFile;
        inFile.open("password1.txt",ios::out);
        if (inFile.is_open())
    {
        for (int i = 0; i < 9; i++)
        {
            inFile<<pass1[i];
        }
        inFile.close();
    }
    }
    else
    {
        cout<<"\n\t\tINCORRECT PASSWORD"<<endl;
    }
}
};

int main()
{
     system("color B");

     cout<<"\n\n\t***********************************\n";
     cout<<"\t*PASSWORD PROTECTED PERSONAL DIARY*\n";
     cout<<"\t***********************************";
     cout<<"\n\n\t\tMAIN MENU:";
     cout<<"\n\n\tADD RECORD\t[1]";
     cout<<"\n\tVIEW RECORD\t[2]";
     cout<<"\n\tDELETE RECORD\t[3]";
     cout<<"\n\tEDIT PASSWORD\t[4]";
     cout<<"\n\tEXIT\t\t[5]";
     cout<<"\n\n\tENTER YOUR CHOICE:";

diary dk;
int i;
cin>>i;
if(i==1)
{
if(dk.password()==0)
{
dk.addrecord();
}
cout<<"\n\t\t***THANK YOU FOR USING THE DIARY!*** ";
getch();
}
else if(i==2)
{
if(dk.password()==0)
{
dk.viewrecord();}
cout<<"\n\t\t***THANK YOU FOR USING THE DIARY!*** ";
getch();}
else if(i==4)
{
if(dk.password()==0)
{
dk.editpassword();
}
cout<<"\n\t\t***THANK YOU FOR USING THE DIARY!***";
getch();}
else if(i==3)
{
if(dk.password()==0)
{dk.deleterecord();}
cout<<"\n\t\t***THANK YOU FOR USING THE DIARY!*** ";
getch();
}
else if(i==5)
{
cout<<"\n\n\t\t***THANK YOU FOR USING THE DIARY!*** ";
getch();
}
else{
cout<<"\n\t\tYOU ENTERED WRONG CHOICE..";
getch();
}
}
