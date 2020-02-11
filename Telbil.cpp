#include<fstream>
#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>

#include<string>
#include<process.h>
#include<dos.h>
using namespace std;
class tel_bil
{
private:
int calls;
char name[100],adrs[100];
char city[30];
public:
char tel_no[15];
long unsigned int cons_no;
void show_data();
void get_data();
};
fstream file;
void tel_bil::get_data()
{
char ch[10];
cin.getline(ch,100);
cout<<"\n\tENTER NAME: ";
cin.getline(name,30);
cout<<"\n\tENTER ADDRESS: ";
cin.getline(adrs,100);
cout<<"\n\tENTER CITY: ";
cin.getline(city,40);
cout<<"\n\tENTER TOTAL NO. OF CALLS: ";
cin>>calls;
}
void tel_bil::show_data()
{
float tax=0.02;
float charge;
int n;
char ch;
 if(calls>=50)
 {
n=calls-50;
tax=tax*n;
charge=tax+(2*n)+60;
 }
 else
 {
n=0;
tax=0;
charge=60;
 }
cout<<"**************************************************************************";
cout<<"\n\t\t\t Billing System\n\n";
cout<<"**************************************************************************";
cout<<"\n\t\t\t\tPOSTPAID";
cout<<"\n\n\t\t\t_____________________\n";
cout<<"\n\tTELEPHONE NO.: "<<tel_no;
cout<<"\n\tCONSUMER NO.: "<<cons_no;
cout<<"\n\tCONSUMER NAME: ";
cout<<name;
cout<<"\n\tADDRESS: ";
cout<<adrs;
cout<<"\n\tCITY: ";
cout<<city;
cout<<"\n\tTOTAL NO. OF CALLS: ";
cout<<calls;
cout<<"\n\tFREE CALLS :"<<"50";
cout<<"\n\tCHARGEABLE CALLS: "<<n;
cout<<"\n\tTAX (2%):"<<tax;
cout<<"\n\tCHARGE PER CALL: "<<"Rs.2";
cout<<"\n\tADDITIONAL CHARGES: Rs. 60";
cout<<"\n\tTOTAL CHARGES: "<<charge;
}
int main()
{
tel_bil a;
int choice;
char ch;
cout<<"\n\n\n\t\t\tWELCOME TO THE PROJECT";
cout<<"\n\t\t______";
cout<<"\n\n\t\t\tBHANU TELEPHONE BILLING SYSTEM";
cout<<"\n\t\t______";

 while(1)
 {
 	system("cls");
cout<<"\n\n**************************************************************************";
cout<<"\n\t\t\tBhanu Telephone Billing System\n\n";
cout<<"**************************************************************************\n\n";
 cout<<"\n\t\t\t\tSelect a Option\n\n\t__________________\n";
 cout<<"\n\t1. TO ADD NEW RECORD\n\t__________________\n\n"<<"\t2. TO SEERECORD\n\t__________________\n"<<"\n\t3. FOR ENQUIRY\n\t__________________\n"
 <<"\n\t4. TO MODIFY RECORD\n\t__________________\n"<<"\n\t5. TO DELETE\n\t__________________\n"<<"\n\t6. QUIT\n\t__________________";
 cout<<"\n\n\tENTER YOUR CHOICE: ";
 cin>>choice;
 system("cls");
 if(choice==1) 
 {
 
 char no[15];
 int flag;
 long unsigned int p,q;
 file.open("tel.dat",ios::in|ios::binary|ios::out|ios::app|ios::ate);
 cout<<"\n\tENTER TELEPHONE NO :) ";
 cin.get(ch);
 cin.getline(no,15);
 file.seekg(0);
 flag=0;
 do
{
file.read((char*)&a,sizeof(a));
 if(strcmp(a.tel_no,no)==0)
 {
 cout<<"\n\n\t\tTHIS TELEPHONE NO ALREADY EXISTS :(";
 flag=1;
 getch();
 break;
 }
 }while(!file.eof());
 file.close();
 if(flag==0)
 {
file.open("tel.dat",ios::in|ios::binary|ios::out|ios::app|ios::ate);
file.seekp(0,ios::end);
p=file.tellp();
q=(p/sizeof(a))+1;
strcpy(a.tel_no,no);
a.cons_no=q;
a.get_data();
file.write((char*)&a,sizeof(a));
cout<<"\n\n\t\tRECORD ADDED ||||z";
file.close();
getch();
 }
 }
 else if(choice==2) 
  {
 file.open("tel.dat",ios::in|ios::binary|ios::out|ios::app|ios::ate);
 file.seekg(0);
 int t=0;
 while(file.read((char*)&a,sizeof(a)))
{
 t=1 ;
 cout<<"\n\n";
 a.show_data();
 getch();
}
 if(t==0)
 {
cout<<"\n\n\t\tFILE DOES NOT EXIST.............";
getch();
 }
 file.close();
 }
 else if(choice==3) 
 {
 
 file.open("tel.dat",ios::in|ios::binary|ios::out|ios::app|ios::ate);
 char no1[15];
 int i=0;
 cout<<"\n\n\t\tENTER THE TELEPHONE NO.: ";
 cin.get(ch);
 cin.getline(no1,15);
 file.seekg(0);
 do
 {
file.read((char*)&a,sizeof(a));
if(strcmp(a.tel_no,no1)==0)
{
 a.show_data();
 i=1;
 getch();
 break;
}
 }while(!file.eof());
 if(i==0)
 {
cout<<"\n\n\t\tTHIS TELEPHONE NO. DOES NOT EXIST.........";
getch();
 }
 file.close();
 }
 else if(choice==4) 
 {
 long unsigned int b;
 int s=0;
 file.open("tel.dat",ios::in|ios::binary|ios::out);
 char no2[15],no3[15];
 file.seekg(0);
 cout<<"\n\n\t\tENTER THE TELEPHONE NO. TO BE MODIFIED: ";
 cin.get(ch);
 cin.getline(no2,15);
 while(file.read((char*)&a,sizeof(a)) && s==0)
 {
if(strcmp(a.tel_no,no2)==0)
{
 a.show_data();
 getch();
 system("cls");
 cout<<"\n\t\t\tENTER NEW RECORDS";
 cout<<"\n\n\t\tENTER TELEPHONE NO.: ";
 cin.getline(no3,15);
 strcpy(a.tel_no,no3);
 a.get_data();
 int pos=-1*sizeof(a);
 file.seekp(pos,ios::cur);
 file.write((char*)&a,sizeof(a));
 cout<<"\n\n\t\t RECORD UPDATED...........";
 s=1;

 break;
}
 }
 if(s==0)
 {
 cout<<"\n\n\t\tNO. NOT FOUND......." ;
 getch();
 }
 file.close();
 }
 else if(choice==5) 
 {
 char no[15];
 int k=0;
 cout<<"\n\n\t\tENTER THE TELEPHONE NO. YOU WANT TO DELETE: ";
 cin.get(ch);
 cin.getline(no,15);
 file.open("tel.dat",ios::in|ios::out);
 fstream fp2;
 fp2.open("Temp.dat",ios::out);
 file.seekg(0,ios::beg);
 fp2.seekg(0,ios::beg);
 while(file.read((char*)&a,sizeof(a)))
{
 if(strcmp(a.tel_no,no)==0)
 {
 a.show_data();
 k=1;
 cout<<"\n\n\t\tRECORD DELETED ......";
 }
 else
 fp2.write((char*)&a,sizeof(a));
 }
 fp2.close();
 file.close();
 if(k==0)
 {
cout<<"\n\n\t\tNO. NOT FOUND.......";
 }
 remove("tel.dat");
 rename("Temp.dat","tel.dat");
 getch();
 system("cls");
 }
 else if(choice==6) 
 exit(0);
 else
 {
 cout<<"\n\n\t\tWRONG CHOICE....";
 
 }
 }
}
