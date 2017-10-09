#include<fstream.h>
#include<iomanip.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
			//Prototypes

void drivermenu();
void ordermenu();
void endoftrip();
void end_driver(int);
void end_taxi(char []);
void taximenu();
void hire();
void credits();
void displayorder();
void changestattall();
void changestatdall();
void clearall();
void dissallorder();

			//End of prototypes


			//Structures and member functions of structures

struct datey
{
	int dd,mm,yy;
};

struct timey
{
	int min,hr;
};

struct order
{	int id;
	char stat;
	datey d;
	timey t1,t2;
	int driverid;
	char taxino[20];
	float income;
	void display();
	void displayo();
	void output(int);
	order()
	{
		stat='O';
		income=0;
	}
};

void order::output(int row)
{
	gotoxy(4,row) ;
	cout <<id ;
	gotoxy(13,row) ;
	cout <<taxino ;
	gotoxy(28,row) ;
	cout <<driverid ;
	gotoxy(37,row) ;
	cout<<d.dd<<"-"<<d.mm<<"-"<<d.yy ;
	gotoxy(49,row) ;
	cout<<t1.hr<<":"<<t1.min;
	if(stat=='F')
	{
		gotoxy(62,row) ;
		cout<<t2.hr<<":"<<t2.min;
		gotoxy(73,row) ;
		cout<<income;
	}
}


float size3=sizeof(order);

void order::display()
{
	gotoxy(30,8);
	cout<<"Order Number: "<<id<<endl;
	gotoxy(30,10);
	cout<<"Order Date: "<<d.dd<<"-"<<d.mm<<"-"<<d.yy<<endl;
	gotoxy(30,12);
	cout<<"Taxi Number: "<<taxino<<endl;
	gotoxy(30,14);
	cout<<"Driver ID: "<<driverid<<endl;
	gotoxy(30,16);
	cout<<"Time of trip start: "<<t1.hr<<":"<<t1.min<<endl;
	gotoxy(30,18);
	cout<<"Time of trip end: "<<t2.hr<<":"<<t2.min;
	gotoxy(30,20);
	cout<<"Revenue Collected: "<<income;
}

void order::displayo()
{
	gotoxy(30,8);
	cout<<"Order Number: "<<id<<endl;
	gotoxy(30,10);
	cout<<"Order Date: "<<d.dd<<"-"<<d.mm<<"-"<<d.yy<<endl;
	gotoxy(30,12);
	cout<<"Taxi Number: "<<taxino<<endl;
	gotoxy(30,14);
	cout<<"Driver ID: "<<driverid<<endl;
	gotoxy(30,16);
	cout<<"Time of trip start: "<<t1.hr<<":"<<t1.min;
	if(stat=='F')
	{
		gotoxy(30,18);
		cout<<"Time of trip end: "<<t2.hr<<":"<<t2.min;
		gotoxy(30,20);
		cout<<"Revenue Collected: "<<income;
	}
}
			//End of structures


			//Classes and member functions of classes

class driver
{
		char name[20],mobile[15],status;
		int id;
		float salary;
	public:
		driver()
		{
			status='F';
		}
		int retid()
		{
			return id;
		}
		void inname(char []);
		void innumber(char []);
		void changestatd2();
		void changestatd1();
		void insalary(float);
		void input(int);
		void output(int);
		void outputy(int);
		char retstatd();

};


class taxi
{
		char taxino[20],type[10],model[20],stat;
		datey dop;
	public:
		void rettno(char []);
		void intype(char []);
		void inmodel(char[]);
		void indate(datey);
		void changestatt1();
		void changestatt2();
		void input();
		void output(int);
		void add();
		void outputy(int);
		void remove();
		void mod();
		char retstat();
		void rettype(char []);
		taxi()
		{
			stat='F';
		}
};
			      //Member Functions

long size=sizeof(taxi);

void taxi::rettype(char t[10])
{
	strcpy(t,type);
}
char taxi::retstat()
{
	return(stat);
}
void taxi::changestatt1()
{
	stat='O';
}

void taxi::changestatt2()
{
	stat='F';
}


void taxi::rettno(char tno[20])
{
	strcpy(tno,taxino);
}

void taxi::intype(char typee[])
{
	strcpy(type,typee);
}
void taxi::inmodel(char modeley[])
{
	strcpy(model,modeley);
}

void taxi::indate(datey d)
{
	dop=d;
}

void taxi::input()
{
	gotoxy(30,8);
	cout<<"Enter taxi number :";
	gets(taxino);
	gotoxy(30,10);
	cout<<"Enter vehicle type :";
	gets(type);
	gotoxy(30,12);
	cout<<"Enter Model :";
	gets(model);
	gotoxy(30,14);
	cout<<"Enter Date of purchase : ";
	cin>>dop.dd;
	gotoxy(57,14);
	cout<<"-";
	cin>>dop.mm;
	gotoxy(60,14);
	cout<<"-";
	cin>>dop.yy;
}

void taxi::outputy(int row)
{
	gotoxy(15,row);
	cout<<taxino<<" "<<model;
}

void taxi::output(int row)
{
	gotoxy(4,row) ;
	cout <<taxino ;
	gotoxy(25,row) ;
	cout <<type;
	gotoxy(41,row) ;
	cout <<model ;
	gotoxy(62,row) ;
	cout <<dop.dd<<"-"<<dop.mm<<"-"<<dop.yy ;
}


int size2=sizeof(driver);

void driver::insalary(float r)
{
	salary=r;
}

char driver::retstatd()
{
	return(status);
}

void driver::changestatd2()
{
	status='F';
}

void driver::changestatd1()
{
	status='O';
}

void driver::inname(char NAME[])
{
	strcpy(name,NAME);
}

void driver::innumber(char NUMBER[])
{
	strcpy(mobile,NUMBER);
}

void driver::input(int r)
{
	id=r;
	gotoxy(30,8);
	cout<<"Enter Driver Name: ";
	gets(name);
	gotoxy(30,10);
	cout<<"Enter mobile number: ";
	gets(mobile);
	gotoxy(30,12);
	cout<<"Enter salary of driver: ";
	cin>>salary;
}

void driver::outputy(int row)
{
	gotoxy(55,row);
	cout<<id<<" "<<name;
}

void driver::output(int row)
{
	gotoxy(5,row) ;
	cout <<id ;
	gotoxy(14,row) ;
	cout <<name ;
	gotoxy(41,row) ;
	cout <<mobile ;
	gotoxy(59,row) ;
	cout <<salary ;
}


			//End of Classes and members

			//Driver file functions

void changestatdall()
{
	fstream f;
	driver d;
	f.open("driver.dat",ios::in|ios::out|ios::binary);
	while(f.read((char*)&d,size2))
	{
		d.changestatd2();
		f.seekp(-size2,ios::cur);
		f.write((char*)&d,size2);
	}
	f.close();
}

int autogen()
{
	fstream f;
	f.open("driver.dat",ios::in|ios::out|ios::binary);
	if(f.fail())
	{
		cout<<"\n\nUnable to open file";
		getch();
		exit(1);
	}
	driver d;
	int r;
	f.seekg(0,ios::end);
	long t=f.tellg();
	if(t==0)
		r=1;
	else
	{
		f.seekg(-size2,ios::end);
		f.read((char*)&d,size2);
		r=d.retid();
		r++;
	}
	f.close();
	return r;
}

void write()
{
	clrscr();
	driver d;
	fstream f;
	int r;
	r=autogen();
	d.input(r);
	f.open("driver.dat",ios::app|ios::binary);
	if(f.fail())
	{
		cout<<"\n\nUnable to open file";
		getch();
		exit(1);
	}
	f.write((char*)&d,size2);
	cout<<"\n\n\t\tDriver Added";
	f.close();
}

void disdriver()
{
	clrscr();
	driver d;
	int row;
	fstream f;
	f.open("driver.dat",ios::in|ios::binary);
	if(f.fail())
	{
		cerr<<"\nCannot open file";
		getch();
		exit(0);
	}
	gotoxy(30,2) ;
	cout <<"LIST OF DRIVERS" ;
	gotoxy(29,3) ;
	cout <<"~~~~~~~~~~~~~~~" ;
	gotoxy(3,4) ;
	cout <<"DRIVER ID  DRIVER NAME              	PHONE    	  SALARY" ;
	gotoxy(2,5) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
	row=6;
	while(f.read((char*)&d,size2))
	{
		d.output(row);
		row++;
	}
	f.close();
}

void removedriver()
{
	clrscr();
	driver d;
	int flag=0,ID;
	fstream f1,f2;
	f1.open("driver.dat",ios::in|ios::binary);
	if(f1.fail())
	{
		cerr<<"\nCannot open file";
		getch();
		exit(0);
	}
	f2.open("new.dat",ios::out|ios::binary);
	if(f2.fail())
	{
		cerr<<"\nCannot open file";
		getch();
		exit(0);
	}
	cout<<"\n\n\n\n\t\tEnter the ID of the driver you want to remove: ";
	cin>>ID;
	while(f1.read((char*)&d,size2))
	{
		if(d.retid()!=ID)
		{
			f2.write((char*)&d,size2);
		}
		if(d.retid()==ID)
			flag=1;
	}
	if(flag==1)
		cout<<"\n\n\t\tDriver removed";
	if(flag!=1)
		cout<<"\n\n\t\tNo driver found\n";
	f1.close();
	f2.close();
	remove("driver.dat");
	rename("new.dat","driver.dat");
}

void moddriver()
{
	clrscr();
	driver d;
	char choice='n';
	int ID,flag=0;
	char NAME[20],MOBILE[15];
	float salary;
	cout<<"\n\n\nPlease enter the driver ID for whom you want to make the changes: ";
	cin>>ID;
	fstream f;
	f.open("driver.dat",ios::in|ios::out|ios::binary);
	if(f.fail())
	{
		cerr<<"\nCannot open file";
		getch();
		exit(0);
	}
	while(f.read((char*)&d,size2))
	{
		if(d.retid()==ID)
		{
			flag=1;
			cout<<"\n\nDo you want to edit the name of the driver? press Y for yes: ";
			cin>>choice;
			if(choice=='Y'||choice=='y')
			{
				cout<<"\n\tEnter the new name: ";
				gets(NAME);
				d.inname(NAME);
				f.seekp(-size2,ios::cur);
				f.write((char*)&d,size2);
				choice='n';
				cout<<"\n\n\t\tData Edited!\n\n";
			}
			cout<<"\nDo you want to edit the phone number of the driver? press Y for yes: ";
			cin>>choice;
			if(choice=='Y'||choice=='y')
			{
				cout<<"\n\tEnter the new number: ";
				gets(MOBILE);
				d.innumber(MOBILE);
				f.seekp(-size2,ios::cur);
				f.write((char*)&d,size2);
				choice='n';
				cout<<"\n\n\t\tData Edited!\n\n";
			}
			cout<<"\nDo you want to edit the income of the driver? press Y for yes: ";
			cin>>choice;
			if(choice=='Y'||choice=='y')
			{
				cout<<"\n\tEnter the new salary: ";
				cin>>salary;
				d.insalary(salary);
				f.seekp(-size2,ios::cur);
				f.write((char*)&d,size2);
				choice='n';
				cout<<"\n\n\t\tData Edited!\n\n";
			}
		}
	}
	f.close();
	if(flag==0)
	{
		cout<<"\n\t\tDriver not found..";
		getch();
	}
}

			//End of driver file functions

			//Taxi file functions


void changestattall()
{
	fstream f;
	taxi t;
	f.open("taxiii.dat",ios::in|ios::out|ios::binary);
	while(f.read((char*)&t,size))
	{
		t.changestatt2();
		f.seekp(-size,ios::cur);
		f.write((char*)&t,size);
	}
	f.close();
}

void addtaxi()
{
	clrscr();
	taxi t;
	t.input();
	fstream f;
	f.open("taxiii.dat",ios::app|ios::binary);
	if(f.fail())
	{
		cerr<<"\nCannot open file";
		getch();
		exit(0);
	}
	f.write((char*)&t,sizeof(t));
	f.close();
	cout<<"\n\n\t\tSucessfully added!!\n";
}


void removetaxi()
{
	clrscr();
	taxi t;
	char tno[20],taxino[20];
	int flag=0;
	fstream f1,f2;
	f1.open("taxiii.dat",ios::in|ios::binary);
	if(f1.fail())
	{
		cerr<<"\nCannot open file";
		getch();
		exit(0);
	}
	f2.open("new.dat",ios::out|ios::binary);
	if(f2.fail())
	{
		cerr<<"\nCannot open file";
		getch();
		exit(0);
	}
	cout<<"\n\n\n\n\t\tEnter the taxi number you want to remove: ";
	gets(tno);
	while(f1.read((char*)&t,size))
	{
		t.rettno(taxino);
		if(strcmpi(tno,taxino)!=0)
		{
			f2.write((char*)&t,size);
		}
		if(strcmpi(tno,taxino)==0)
			flag=1;
	}
	if(flag==1)
		cout<<"\n\n\t\tTaxi removed";
	if(flag!=1)
		cout<<"\n\n\t\tNo taxi found\n";
	f1.close();
	f2.close();
	remove("taxiii.dat");
	rename("new.dat","taxiii.dat");
}



void modtaxi()
{
	clrscr();
	int flag=0;
	taxi t;
	char choice='n';
	char tno[20],taxino[20],type[10],model[20];
	datey d;
	cout<<"\n\n\nPlease enter the taxi number for whom you want to make the changes: ";
	gets(tno);
	fstream f;
	f.open("taxiii.dat",ios::in|ios::out|ios::binary);
	if(f.fail())
	{
		cerr<<"\nCannot open file";
		getch();
		exit(0);
	}
	while(f.read((char*)&t,size))
	{
		t.rettno(taxino);
		if(strcmpi(tno,taxino)==0)
		{
					flag=1;
					cout<<"\n\nDo you want to edit the type of taxi, press Y for yes: ";
					cin>>choice;
					if(choice=='Y'||choice=='y')
					{
						cout<<"\n\tEnter the new taxi type: ";
						gets(type);
						t.intype(type);
						f.seekp(-size,ios::cur);
						f.write((char*)&t,size);
						choice='n';
						cout<<"\n\n\t\tData Edited!\n\n";
					}
					cout<<"\nDo you want to edit the model of taxi, press Y for yes: ";
					cin>>choice;
					if(choice=='Y'||choice=='y')
					{
						cout<<"\n\tEnter the new taxi model: ";
						gets(model);
						t.inmodel(model);
						f.seekp(-size,ios::cur);
						f.write((char*)&t,size);
						choice='n';
						cout<<"\n\n\t\tData Edited!\n\n";
					}
					cout<<"\nDo you want to edit the date of purchase of taxi, press Y for yes: ";
					cin>>choice;
					if(choice=='Y'||choice=='y')
					{
						cout<<"\n\tEnter Date of purchase :";
						cin>>d.dd;
						gotoxy(35,13);
						cout<<"-";
						cin>>d.mm;
						gotoxy(38,13);
						cout<<"-";
						cin>>d.yy;
						t.indate(d);
						f.seekp(-size,ios::cur);
						f.write((char*)&t,size);
						choice='n';
						cout<<"\n\n\t\tData Edited!\n\n";
					}
		}
	}
	if(flag==0)
	{
		cout<<"\n\t\tTaxi not found..";
		getch();
	}
	f.close();
}
void distaxi()
{
	clrscr();
	taxi t;
	int row;
	fstream f;
	f.open("taxiii.dat",ios::in|ios::binary);
	if(f.fail())
	{
		cerr<<"\nCannot open file";
		getch();
		exit(0);
	}
	gotoxy(30,2) ;
	cout <<"LIST OF TAXI'S" ;
	gotoxy(29,3) ;
	cout <<"~~~~~~~~~~~~~~~~~" ;
	gotoxy(3,4) ;
	cout <<"TAXI NO           	TYPE	        MODEL   	   DATE OF PURCHASE" ;
	gotoxy(2,5) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
	row=6;
	while(f.read((char*)&t,size))
	{
		t.output(row);
		row++;
	}
	f.close();
}
			//end of taxi file functions

			//order file functions

void disorder()
{
	char choice,ch;
	C:
	clrscr();
	char c1=178, c2=177, c3=176 ;
	int k=1 ;
	gotoxy(1,2) ;
	for (int i=1; i<=1840; i++)
	{
		if (k == 1)
			cout <<c1 ;
		else
		if (k == 2)
			cout <<c2 ;
		else
		if (k == 3)
			cout <<c3 ;
		k++ ;
		if (k == 4)
			k = 1 ;
	}
	for (i=5; i<=21; i++)
	{
		gotoxy(21,i) ;
		cout <<"                                        " ;
	}
	gotoxy(32,6) ;
	cout <<"Taxi management shit" ;
	gotoxy(32,7) ;
	cout <<"~~~~~~~~~~~~~~~~" ;
	gotoxy(32,9) ;
	cout <<"DISPLAY" ;
	gotoxy(32,11) ;
	cout <<"1: Any one order" ;
	gotoxy(32,13) ;
	cout <<"2: All orders" ;
	gotoxy(32,17) ;
	cout <<"3: Go back to previous menu" ;
	gotoxy(32,20) ;
	cout <<"Enter Choice: " ;
	fflush(stdin);
	cin>>choice;
	switch(choice)
	{
		case '1': displayorder();
			break;
		case '2': dissallorder();
			break;
		case '3': return;
		default:cout<<"Please enter a valid option...";
			ch=getch();
			goto C;
	}
}

void dissallorder()
{
	clrscr();
	order o;
	int row;
	fstream f;
	f.open("order.dat",ios::in|ios::binary);
	if(f.fail())
	{
		cerr<<"\nCannot open file";
		getch();
		exit(0);
	}
	gotoxy(30,2) ;
	cout <<"LIST OF ORDERS" ;
	gotoxy(29,3) ;
	cout <<"~~~~~~~~~~~~~~~" ;
	gotoxy(3,4) ;
	cout <<"ORDER ID  Taxi Number	Driver ID	Date	Start Time   End Time   Revenue" ;
	gotoxy(2,5) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
	row=6;
	while(f.read((char*)&o,size3))
	{
		o.output(row);
		row++;
	}
	f.close();
}

void displayorder()
{
	clrscr();
	order o;
	int oid,flag=0;
	cout<<"\n\nEnter your order ID: ";
	cin>>oid;
	fstream f;
	f.open("order.dat",ios::in|ios::binary);
	if(f.fail())
	{
		cerr<<"\nUnable to open file..";
		getch();
		exit(1);
	}
	while(f.read((char*)&o,size3))
	{
		if(o.id==oid)
		{
			flag=1;
			o.displayo();
		}
	}
	if(flag==0)
	{
		cout<<"\n\nNo order found\n";
		return;
	}
	f.close();
}

void endoftrip()
{
	clrscr();
	order o;
	time to;
	int flag=0,id;
	fstream f;
	int did;
	char tno[20];
	f.open("order.dat",ios::in|ios::out|ios::binary);
	if(f.fail())
	{
		cerr<<"\nUnable to open file..";
		getch();
		exit(1);
	}
	cout<<"\n\nEnter the order ID: ";
	cin>>id;
	while(f.read((char*)&o,size3))
	{
		if(id==o.id)
		{
			flag=1;
			if(o.stat=='F')
			{
				cout<<"\n\n\a\t\tTrip already ended...";
				getch();
				return;
			}
			gettime(&to);
			o.t2.hr=to.ti_hour;
			o.t2.min=to.ti_min;
			o.stat='F';
			cout<<"\n\tEnter the revenue collected: ";
			cin>>o.income;
			f.seekp(-size3,ios::cur);
			f.write((char*)&o,size3);
			strcpy(tno,o.taxino);
			did=o.driverid;
			break;
		}
	}
	f.close();
	if(flag!=1)
	{
		cout<<"\nNo order found..\n";
		return;
	}
	if(flag==1)
	{
		end_taxi(tno);
		end_driver(did);
		o.display();
	}

}

void end_taxi(char tno[20])
{
	fstream f1;
	char taxino[20];
	taxi t;
	f1.open("taxiii.dat",ios::out|ios::in|ios::binary);
	if(f1.fail())
	{
		cout<<"\n\nUnable to open file";
		getch();
		exit(1);
	}
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&t,size))
	{
		t.rettno(taxino);
		if(strcmpi(tno,taxino)==0)
		{
			t.changestatt2();
			f1.seekp(-size,ios::cur);
			f1.write((char*)&t,size);
		}
	}
	f1.close();

}

void end_driver(int did)
{
	driver d;
	fstream f2;
	f2.open("driver.dat",ios::out|ios::in|ios::binary);
	if(f2.fail())
	{
		cout<<"\n\nUnable to open dfile";
		getch();
		exit(1);
	}
	while(f2.read((char*)&d,size2))
	{
		if(did==d.retid())
		{
			d.changestatd2();
			f2.seekp(-size2,ios::cur);
			f2.write((char*)&d,size2);
		}
	}
	f2.close();

}

int autogeno()
{
	fstream f;
	f.open("order.dat",ios::in|ios::out|ios::binary);
	if(f.fail())
	{
		cout<<"\n\nUnable to open file";
		getch();
		exit(1);
	}
	order o;
	int r;
	f.seekg(0,ios::end);
	long t=f.tellg();
	if(t==0)
		r=1;
	else
	{
		f.seekg(-size3,ios::end);
		f.read((char*)&o,size3);
		r=o.id;
		r++;
	}
	f.close();
	return r;
}

void hire()
{
	clrscr();
	int flag1=0,flag2=0,flag3=0,flag4=0,row=10,j=10;
	fstream f;
	taxi t;
	driver d;
	char ttaxino[20],taxino[20],type[10],ttype[10];
	int driverid,ddriverid;
	f.open("taxiii.dat",ios::in|ios::binary);
	if(f.fail())
	{
		cerr<<"Failed to Open file!";
		getch();
		exit(1);
	}
	gotoxy(10,5);
	cout<<"Enter the type of taxi you want to hire: \n";
	gotoxy(10,6);
	cin>>type;

	f.seekg(0,ios::beg);
	while(f.read((char*)&t,size))
	{
		t.rettype(ttype);
		if(strcmpi(ttype,type)==0 && t.retstat()=='F')
		{
			flag1=1;
			gotoxy(15,8);
			cout<<"Taxi's";
			t.outputy(j);
			j++;
		}
	}
	f.close();
	if(flag1==0)
	{
		cout<<"\nNo Taxi's availabe..\n";
		return;
	}
	fstream f2;
	f2.open("driver.dat",ios::in|ios::binary);
	if(f2.fail())
	{
		cerr<<"Failed to Open file!";
		getch();
		exit(1);
	}
	f2.seekg(0,ios::beg);
	while(f2.read((char*)&d,size2))
	{
		if(d.retstatd()=='F')
		{
			gotoxy(50,8);
			cout<<"|";
			gotoxy(55,8);
			cout<<"Drivers";
			flag2=1;
			d.outputy(row);
			row++;
		}
	}
	f2.close();
	if(flag2==0)
	{
		cout<<"\nNo drivers availabe..\n";
		return;
	}
	cout<<"\n\n\n\t\tEnter the taxi number you want to send: ";
	gets(taxino);
	f.open("taxiii.dat",ios::in|ios::out|ios::binary);
	if(f.fail())
	{
		cerr<<"Failed to Open file!";
		getch();
		exit(1);
	}

	f.seekg(0,ios::beg);
	while(f.read((char*)&t,size))
	{
		t.rettno(ttaxino);
		if(strcmpi(ttaxino,taxino)==0)
		{
			flag3=1;
			break;
		}
	}
	if(flag3==0)
	{
		cout<<"\n\nInvalid taxi number...";
		return;
	}
	cout<<"\t\tEnter the Driver ID you want to send : ";

	cin>>driverid;

	f2.open("driver.dat",ios::out|ios::in|ios::binary);
	if(f2.fail())
	{
		cerr<<"Failed to Open file!";
		getch();
		exit(1);
	}
	f2.seekg(0,ios::beg);
	while(f2.read((char*)&d,size2))
	{
		ddriverid=d.retid();
		if(driverid==ddriverid)
		{
			flag4=1;
			break;
		}
	}
	if(flag4==0)
	{
		cout<<"\n\nInvalid driver ID...";
		return;
	}
		if(flag3!=0)
	{
		t.changestatt1();
		f.seekp(-size,ios::cur);
		f.write((char*)&t,size);
	}
	f.close();
	if(flag4!=0)
	{
		d.changestatd1();
		f2.seekp(-size2,ios::cur);
		f2.write((char*)&d,size);
	}
	f2.close();
	time to;
	gettime(&to);
	order o;
	o.t1.hr=to.ti_hour;
	o.t1.min=to.ti_min;
	o.id=autogeno();
	date dd;
	getdate(&dd);
	o.d.dd=dd.da_day;
	o.d.mm=dd.da_mon;
	o.d.yy=dd.da_year;
	o.driverid=ddriverid;
	strcpy(o.taxino,taxino);
	o.income=0;
	fstream f3;
	f3.open("order.dat",ios::app|ios::binary);
	if(f3.fail())
	{
		cerr<<"\n\nUnable to open file..\n";
		getch();
		exit(1);
	}
	f3.write((char*)&o,size3);
	f3.close();
	cout<<"\n\n\t\tOrder successful...Order ID is: "<<o.id;
}


void clearall()
{
	clrscr();
	char choice;
	fstream f;
	cout<<"\n\nAre you sure to clear all orders? Press \'Y\' for yes: ";
	cin>>choice;
	if(choice=='n'||choice=='N')
		return;
	else if(choice=='y'||choice=='Y')
	{
		f.open("order.dat",ios::out|ios::trunc|ios::binary);
		f.close();
		changestattall();
		changestatdall();
		cout<<"\n\nFile cleaned";
	}
	else
	{
		cout<<"\n\nPleasse enter a valid choice";
		getch();
		return;
	}

}
			//end of order file functions



			//main() start

int start=1;

void main()
{
	char choice;
	int i,k;
	char ch,c1,c2,c3;
	do
	{
		A:
		clrscr();
		if(start==1)
		{
			c1=178, c2=177, c3=176 ;
			k=1 ;
			gotoxy(1,2) ;
			for (   i=1; i<=1840; i++)
			{
				if (k == 1)
					cout <<c1 ;
				else
				if (k == 2)
					cout <<c2 ;
				else
				if (k == 3)
					cout <<c3 ;
				k++ ;
				if (k == 4)
					k = 1 ;
			}
			for (i=5; i<=21; i++)
			{
				gotoxy(21,i) ;
				cout <<"                                        " ;
			}
			gotoxy(30,10);
			cout<<"TAXI MANAGEMENT PROGRAM";
			gotoxy(25,13);
			cout<<"...Managing Taxi's since 2004";
			getch();
			start++;
			gotoxy(25,20);
			cout<<"LOADING";
			for(int v=0;v<20;v++)
			{
				gotoxy(28+v,31);
				cout<<"�";
				delay(50);
			}
		}
		clrscr();
		k=1 ;
		c1=178, c2=177, c3=176 ;
		gotoxy(1,2) ;
		for (   i=1; i<=1840; i++)
		{
			if (k == 1)
				cout <<c1 ;
			else
			if (k == 2)
				cout <<c2 ;
			else
			if (k == 3)
				cout <<c3 ;
			k++ ;
			if (k == 4)
				k = 1 ;
		}
		for (i=5; i<=21; i++)
		{
			gotoxy(21,i) ;
			cout <<"                                        " ;
		}


		gotoxy(32,6) ;
		cout <<"Taxi management program" ;
		gotoxy(32,7) ;
		cout <<"~~~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(32,9) ;
		cout <<"1: Taxi" ;
		gotoxy(32,11) ;
		cout <<"2: Driver" ;
		gotoxy(32,13) ;
		cout <<"3: Order" ;
		gotoxy(32,15) ;
		cout <<"4: Credits" ;
		gotoxy(32,17) ;
		cout <<"5. Exit" ;
		gotoxy(32,20) ;
		cout <<"Enter Choice: " ;
		fflush(stdin);
		cin>>choice;
		switch(choice)
		{
			case '1': taximenu();
				break;
			case '2': drivermenu();
				break;
			case '3': ordermenu();
				break;
			case '4': credits();
				break;
			case '5': exit(0);
			default:cout<<"\nPlease enter a valid option..";
				ch=getch();
				goto A;
		}
	}while(1);
}
			//main() end

			//Menus

void taximenu()
{
	char choice;
	char echoice,ch;
	B:
	clrscr();
	char c1=178, c2=177, c3=176 ;
	int k=1 ;
	gotoxy(1,2) ;
	for (int i=1; i<=1840; i++)
	{
		if (k == 1)
			cout <<c1 ;
		else
		if (k == 2)
			cout <<c2 ;
		else
		if (k == 3)
			cout <<c3 ;
		k++ ;
		if (k == 4)
			k = 1 ;
	}
	for (i=5; i<=21; i++)
	{
		gotoxy(21,i) ;
		cout <<"                                        " ;
	}
	gotoxy(32,6) ;
	cout <<"Taxi management Program" ;
	gotoxy(32,7) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~" ;
	gotoxy(32,9) ;
	cout <<"1: Add a taxi" ;
	gotoxy(32,11) ;
	cout <<"2: Remove a taxi" ;
	gotoxy(32,13) ;
	cout <<"3: Modify taxi details" ;
	gotoxy(32,15) ;
	cout <<"4: Display all taxi\'s" ;
	gotoxy(32,17) ;
	cout <<"5: Go back to previous menu" ;
	gotoxy(32,20) ;
	cout <<"Enter Choice: " ;
	fflush(stdin);
	cin>>choice;
	switch(choice)
	{
		case '1': addtaxi();
			break;
		case '2': removetaxi();
			break;
		case '3': modtaxi();
			break;
		case '4': distaxi();
			break;
		case '5': return;
		default:cout<<"\nEnter a valid option";
			ch=getch();
			goto B;
	}
	cout<<"\n\n\n\t\tDo you want to continue? Press Y for yes: ";
	fflush(stdin);
	cin>>echoice;
	if(echoice=='y'||echoice=='Y')
		goto B;
	else
	return;
}


void drivermenu()
{
	char choice,echoice;
	C:
	clrscr();
	char c1=178, c2=177, c3=176 ;
	int k=1 ;
	gotoxy(1,2) ;
	for (int i=1; i<=1840; i++)
	{
		if (k == 1)
			cout <<c1 ;
		else
		if (k == 2)
			cout <<c2 ;
		else
		if (k == 3)
			cout <<c3 ;
		k++ ;
		if (k == 4)
			k = 1 ;
	}
	for (i=5; i<=21; i++)
	{
		gotoxy(21,i) ;
		cout <<"                                        " ;
	}
	gotoxy(32,6) ;
	cout <<"Taxi management Program" ;
	gotoxy(32,7) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~" ;
	gotoxy(32,9) ;
	cout <<"1: Add a driver" ;
	gotoxy(32,11) ;
	cout <<"2: Remove a driver" ;
	gotoxy(32,13) ;
	cout <<"3: Modify Driver details" ;
	gotoxy(32,15) ;
	cout <<"4: Display all drivers" ;
	gotoxy(32,17) ;
	cout <<"5: Go back to previous menu" ;
	gotoxy(32,20) ;
	cout <<"Enter Choice: " ;
	cin>>choice;
	switch(choice)
	{
		case '1': write();
			break;
		case '2': removedriver();
			break;
		case '3': moddriver();
			break;
		case '4': disdriver();
			break;
		case '5': return;
		default:cout<<"\nEnter a valid option";
			getch();
			goto C;
	}
	cout<<"\n\n\n\t\tDo you want to continue? Press Y for yes: ";
	cin>>echoice;
	if(echoice=='y'||echoice=='Y')
		goto C;
	else
	return;
}

void ordermenu()
{
	char echoice,choice;
	C:
	clrscr();
	char c1=178, c2=177, c3=176 ;
	int k=1 ;
	gotoxy(1,2) ;
	for (int i=1; i<=1840; i++)
	{
		if (k == 1)
			cout <<c1 ;
		else
		if (k == 2)
			cout <<c2 ;
		else
		if (k == 3)
			cout <<c3 ;
		k++ ;
		if (k == 4)
			k = 1 ;
	}
	for (i=5; i<=21; i++)
	{
		gotoxy(21,i) ;
		cout <<"                                        " ;
	}
	gotoxy(32,6) ;
	cout <<"Taxi management Program" ;
	gotoxy(32,7) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~" ;
	gotoxy(32,9) ;
	cout <<"1: Hire a taxi" ;
	gotoxy(32,11) ;
	cout <<"2: Mark end of the trip" ;
	gotoxy(32,13) ;
	cout <<"3. Display order" ;
	gotoxy(32,15) ;
	cout <<"4. Clear order's file" ;
	gotoxy(32,17) ;
	cout <<"5. Go back to previous menu" ;
	gotoxy(32,20) ;
	cout <<"Enter Choice: " ;
	cin>>choice;
	switch(choice)
	{
		case '1': hire();
			break;
		case '2': endoftrip();
			break;
		case '3': disorder();
			break;
		case '4': clearall();
			break;
		case '5': return;
		default:cout<<"\nEnter a valid option";
			getch();
			goto C;
	}
	cout<<"\n\n\n\t\tDo you want to continue? Press Y for yes: ";
	cin>>echoice;
	if(echoice=='y'||echoice=='Y')
		goto C;
	else
	return;
}
				//end of menus

				//Extra Functions

void credits()
{
	clrscr();
	char c1=178, c2=177, c3=176 ;
	int k=1 ;
	gotoxy(1,2) ;
	for (int i=1; i<=1840; i++)
	{
		if (k == 1)
			cout <<c1 ;
		else
		if (k == 2)
			cout <<c2 ;
		else
		if (k == 3)
			cout <<c3 ;
		k++ ;
		if (k == 4)
			k = 1 ;
	}
	for (i=5; i<=21; i++)
	{
		gotoxy(21,i) ;
		cout <<"                                        " ;
	}
	gotoxy(32,6) ;
	cout <<"Credits" ;
	gotoxy(32,7) ;
	cout <<"~~~~~~~" ;
	gotoxy(32,9) ;
	cout <<"MADE BY:" ;
	gotoxy(32,13) ;
	delay(350);
	cout <<"1: Aniket Pradhan" ;
	gotoxy(32,15) ;
	delay(350);
	cout <<"2: Pulkit Arora" ;
	gotoxy(32,17) ;
	delay(350);
	cout <<"3: Emil Mary Jo" ;
	gotoxy(30,13);
	delay(350);
	cout<<"-";
	gotoxy(31,13);
	delay(350);
	cout<<"-";
	gotoxy(50,13);
	delay(350);
	cout<<"-";
	gotoxy(51,13);
	delay(350);
	cout<<"-";
	gotoxy(30,15);
	delay(350);
	cout<<"-";
	gotoxy(31,15);
	delay(350);
	cout<<"-";
	gotoxy(50,15);
	delay(350);
	cout<<"-";
	gotoxy(51,15);
	delay(350);
	cout<<"-";
	gotoxy(30,17);
	delay(350);
	cout<<"-";
	gotoxy(31,17);
	delay(350);
	cout<<"-";
	gotoxy(50,17);
	delay(350);
	cout<<"-";
	gotoxy(51,17);
	delay(350);
	cout<<"-";
	getch();
	return;
}

				//COMMENTS

/*void addexpense()
{
	float expend;
	driver d;
	fstream f;
	f.open("driver.dat",ios::in|ios::out|ios::binary);
	if(f.fail())
	{
		cerr<<"Unable to open file.";
		getch();
		exit(0);
	}
	int ID,flag=0;
	cout<<"\nEnter the ID for which you want to add expense: ";
	cin>>ID;
	while(f.read((char*)&d,size2))
	{
		if(d.retid()==ID)
		{
			flag=1;
			cout<<"\nEnter the amount: ";
			cin>>expend;
			d.expensee(expend);
			f.seekp(-size2,ios::cur);
			f.write((char*)&d,size2);
			cout<<"\n\nExpense added";
			break;
		}
	}
	if(flag==0)
		cout<<"\nNo ID found";
	f.close();
}
*/




/*
class ordertaxi
{
		taxi t;
		driver d;
	public:
		void input(taxi,driver);
		void output();
};

int size3=sizeof(ordertaxi);

void ordertaxi::output()
{
	t.out();
	d.out();
}

void ordertaxi::input(taxi a,driver b)
{
	t=a;
	d=b;
}

void disorder()
{
	ordertaxi o;
	fstream f;
	f.open("order.dat",ios::in|ios::binary);
	if(f.fail())
	{
		cerr<<"\nCannot open file";
		getch();
		exit(0);
	}
	while(f.read((char*)&o,size3))
	{
		o.output();
		cout<<endl<<endl;
	}
	f.close();
}



void refresh()
{
	ordertaxi o;
	taxi t;
	driver d;
	fstream f1,f2,f3;
	f1.open("taxiii.dat",ios::in|ios::binary);
	if(f1.fail())
	{
		cerr<<"\nCannot open file";
		getch();
		exit(0);
	}
	f2.open("driver.dat",ios::in|ios::binary);
	if(f2.fail())
	{
		cerr<<"\nCannot open file";
		getch();
		exit(0);
	}
	f3.open("order.dat",ios::trunc|ios::out|ios::binary);
	if(f3.fail())
	{
		cerr<<"\nCannot open file";
		getch();
		exit(0);
	}
	char tno[10];
	while(f1.read((char*)&t,size)||f2.read((char*)&d,size2))
	{
		o.input(t,d);
		f3.write((char*)&o,size3);
	}
	cout<<"\nList refreshed..\n";
	f1.close();
	f2.close();
	f3.close();
}
*/

