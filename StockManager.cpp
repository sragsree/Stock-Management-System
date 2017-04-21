#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<graphics.h>
#include<conio.h>


struct item
{
	int code;
	char name[20],company[20]
	float stock,price;
	struct dom
	{
		int d,m,y;
	}d_man;
};


void addition(),modification(),deletion(),display(),itemcode();
void stock(),company(),reorder(),line();
int datacheck(item dt);
void main()
{
	textattr(123+444);
	textcolor(BLUE);
	clrscr();
	fstream fp,f;
	item it,t;
	int n,no,num;
	char comp[20];
	long l;
	char usr[20],a,b,c,d,e,z,g,h;
	char usr1[10]="bms";
	cout<<"\n\n\t\tWELCOME TO SUPERMARKET INFORMATION SYSTEM;
	cout<<"\n\t\t======= == =========== =========== ======";
	getch();
	post:cout<<"\n\n\n\tUSERNAME:";
	cin>>usr;
	cout<<"\n\tPASSWORD:";
	a=getch();cout<<"*";
	b=getch();count<<*;
	c=getch();count<<*;
	d=getch();count<<*;
	e=getch();count<<*;
	f=getch();count<<*;
	g=getch();count<<*;
	h=getch();count<<*;
	getch();

	if((a=='p')&&(b=='r')&&(c=='a')&&(d=='n')&&(e=='i')&&(z=='t')&&(g=='h')&&(h=='a')&&(strcmp(usr1,usr)==0))
	{
		cout<<"\n\n\tVerifying input......";
		getch();
		cout<<"\n\n\t\tInitialising data.....";
		getch();
		cout<<"\n\n\t\t\tLoading database.....";
		getch();
	}
	else
	{
		cout<<"\n\n\tVerifying input......";
		getch();
		cout<<"\n\n\tIncorrect username and password";
		getch();
		goto post;
	}
	do
	{
		cout<<"\n\n\t\t\t Main Menu";
		cout<<"\n\t\t\t===========";
		cout<<"\n\n\t\t\t1>Addition";
		cout<<"\n\t\t\t2>Modification";
		cout<<"\n\t\t\t3>Display";
		cout<<"\n\t\t\t4>Deletion";
		cout<<"\n\t\t\t5>Exit";
		cout<<"\n\t\t\tEnter your choice";
		cin>>n;
		switch(n)
			{
				case 1:
						addition();
						break;
				case 2:
						modification();
						break;
				case 3:
						display();
						break;
				case 4:
						deletion();
						break;
				case 5:
						cout<<"\n\n\n\t\t\t Thank You, Have a nice day\n";
						getch();
						break;
				default:
						cout<<"\nInvalid Choice.....";
			}
	}
	while(n!=5);
}


void addition()
{
	item it;
	long l;
	fstream fp;
	fp.open("itemmast.dat",ios::in);
	l=sizeof(it);
	if(fp.bad())
	it.code=1;
	else
	{
		fp.seekg(-l,ios::end);
		fp.read((char*)&it,sizeof(it));
		it.code++;
	}
	fp.close();
	cout<<"\n\t\t\tEnter itemcode: ";
	cout<<it.code;
	cout<<"\n\n\t\t\tEnter item name:";
	gets(it.name);
	cout<<"\n\t\t\tEnter company name:";
	gets(it.company);
	cout<<"\n\t\t\tEnter stack:";
	cin>>it.stock;
	cout<<\n\t\t\tEnter unitprice:";
	cin>>it.price;
	while(1)
	{
		cout<<"\n\t\t\tEnter date of manufacture[dd-mm-yyyy]:";
		cin>>it.d_man.d>>it.d_man.m>>it.d_man.y;
		if(datecheck(it))
			break;
	}
	fp.open("itemmast.dat",ios::app);
	fp.write((char*)&it,sizeof(it));
	fp.close();
	cout<<"\n\t\tRecord added........";
}


int datecheck(item dt)
{
	int days[12] = {31,28,31,30,31,30,31,30,31,31,30,31,30,31};
	if(dt.d_man.y%4==4)
		days[1]=29;
	if(dt.d_man.m>12||days[dt.d_man.m-1]<dt.d_man.d)
		return(0);
	else
		return(1);
}


void modification()
{
	int no;
	fstream fp;
	int l,flag=0;
	item it,t;
	cout<<"\n\n\tModify data";
	cout<<"\n\t=============";
	cout<<"\n\n\tEnter itemcode to be modified"
	cin>>no;
	fp.open(itemmast.dat",ios::in|ios::out);
	while(!fp.eof())
	{
		fp.read((char*)&it,siizeof(it));
		if(fp.eof())break;
			if(no==it.code)
			{
				flag=1;
				t=it;
				l=sizeof(it);
				fp.seekg(-l,ios::cur);
				cout<<"\n\n\t\t\tEnter new Stock:";
				cin>>t.stock;
				t.codr=no;
				cout<<"\n\t\t\tEnter unitprice:";
				cin>>t.price;
				while(1)
				{
					cout<<\n\t\t\tEnter date of manufacture[dd-mm-yyyy]:";
					cin>>t.d_man.d>>t.d_man.m>>t.d_man.y;
					if(datecheck(t))
						break;
				}
				fp.write((char*)&t.sizeof(t));
				cout<<"\n\tRecord Modified....";
				break;
			}
			fp.close();
			if(flag==0)
				cout<<"Record not found.....";
		}
	}
}

		
void display()
{
	int num =0;
	while(num!=5)
	{
		cout<<"\n\t\t\tDisplay SUB menu\n";
		cout<<"\t\t\t*****************\n";
		cout<<"\n\t\t\t1.Item wise";
		cout<<"\n\t\t\t2.Company";
		cout<<"\n\t\t\t3.Reorder details";
		cout<<"\n\t\t\t4.Stock details";
		cout<<"\n\t\t\t5.Exit";
		cout<<"\n\n\t\t\tEnter your choice:";
		cin>>num;
		switch(num)
		{
			case 1:
				itemcode();
				break;
			case 2:
				company();
				break;
			case 3:
				reorder();
				break;
			case 4:
				stock();
				break;
			case 5:
				cout<<"\n\tEnd of display menu......";
				break;
			default:
				cout<<"\n\tInvalid choice.....";
		}
	}
}



void itemcode()
{
	fstream fp;
	item it;
	int no,flag=0;
	cout<<:\n\tEnter itemcode to be searched:";
	cin>>no;
	fp.open("itemmast.dat",ios::in);
	while(!fp.eof())
	{
		fp.read((char*)&it,sizeof(it));
		if(fp.eof())
			break;
		if(no==it.code)
		{
			flag=1;
			cout<<"\n\t\tItem Details\n";
			cout<<"\n\t\t~~~~ ~~~~~~~";
			cout<<"\n\tName			:"<<it.name;
			cout<<"\n\tCompany		:"<<it.company;
			cout<<"\n\tStock		:"<<it.stock;
			cout<<"\n\tUnit price	:"<<it.price;
			cout<<"\n\tDate of manufacture:"<<it.d_man.d<<"-"<<it.d_man.m<<"-"<<it.d_man.y<<"\n";
			break;
		}
	}
	if(flag==0)	
		cout<<"\n\tRecord not found.....";
}


void stock()
{
	item it;
	fstream fp;
	fp.open("itemmast.dat",ios::in);
	line();
	cout<<"\n
	Code"<<setw(10)<<"Name"<<setw(10)<<"\tCompany"<<setw(10)<<"Stock";
	cout<<setw(20)<<"Date of Manufacture\n";
	line();
	while(!fp.eof())
	{
		fp.read((char*)&it,sizeof(it));
		if(fp.eof())break;
		cout<<" "<<it.code<<setw(15)<<it.name<<setw(13)<<it.company<<setw(9)<<it.stock;
		cout<<setw(10)<<it.d_man.d<<"-"<<it.d_man.m<<"-"<<it.d_man.y<<"\n";
	}
	line();
	fp.close();
}
	
	
void company()
{
	item it;
	fstream fp;
	int flag=0;
	char comp[20];
	cout<<"\n\tEnter company name to be searched:";
	cin>>comp;
	fp.open("itemmast.dat",ios::in);
	cout<<"\n\t\t"<<com<<"Company Products\n";
	line();
	cout<<"\n Code"<<setw(10)<<"Name"<<setw(10)<<"Stock";
	cout<<setw(20)<<"Date of Manufacture\n";
	line();	
	while(!fp.eof())
	{
		fp.read((char*)&it,sizeof(it));
		if(fp.eof())break;
			if(strcmp(it.company,comp)==0)
			{
				cout<<""<<it.code<<setw(15)<<it.name<<setw(7)<<it.stock;
				cout<<setw(10)<<it.d_man.d<<"-"<<it.d_man.m<<"-"<<it.d_man.y<<\n";
				flag=1;
			}
	}
	line();
	if(flag==0)
	cout<<"\n\tRecord not found.....";
	fp.close();
}


void reorder()
{
	fstream fp;
	item it;
	int flag=0;
	fp.open("itemmast.dat", ios::in);
	line();
	cout<<"\n\n\t\t\t\tItem to Order\n";
	line();
	cout<<"\n
	Code"<<setw(10)<<"Name"<<setw(10)<<"Company"<<setw(10)<<"Stock";
	cout<<setw(10)<<"Date of Manufacture\n";
	while(!fp.eof())
	{
		fp.read(char*)&it,sizeof(it));
		if(fp.eof())
			break;
		if(it.stock<5)
		{
			flag=1;	
			cout<<" "<<it.code<<setw(10)<<it.name<<setw(10)<<it.company<<setw(10);
			cout<<it.stock<<setw(10)<<it.d_man.d<<"-"<<it.d_man.m<<"-"<<it.d_man.y<<"\n";
		}
	}
	fp.close();
	line();
	if(flag==0)
		cout<<"\n\t no item to be reordered\n";
}


void deletion()
{
	fstream fp,f;
	item it;
	int no;
	f.open("temp.dat",ios::out);
	cout<<"\n\t Enter item code to delete:";
	cin>>no;
	fp.open("itemmast.dat",ios::in);
	while(!fp.eof)
	{
		fp.read((char*)&it,sizeof(it));
		if(fp.eof())
			break;
		if(it.code!=no)
			f.write((char*)&it,sizeof(it));
	}
	f.close();
	fp.close();
	fp.open("itemmast.dat",ios::out);
	f.open("temp.dat",ios::in);
	while(!f.eof())
	{
		f.read((char*)&it,sizeof(it));
		if(f.eof()) break;
			fp.write((char*)&it,sizeof(it));
	}
	f.close();
	fp.close();
	cout<<"\n Item deleted...\n";
}

void line()
{
	for(int i=1;i<80;i++)
		printf("%c",196);
}










 



