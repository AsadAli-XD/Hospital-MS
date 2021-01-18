// corona hospital data management system.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;

void loggedinadmin();
void loggedindoctor();
void loggedinpatient();
void reguser();
void frgt();
void admin();
void patientScreen1();
void Home();
void readadmindata();
void update_admin_data();
void read_patient_data();
void update_patient_data();
void read_doctor_data();
void update_doctor_data();
void doctorscr();
    // welcome page.
void welcomep()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                  welcome to                                           |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                           hospital management system                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                 -brought to you by group (1)|@@\n";
    cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
    system("pause");
    system("cls");
}

        //structures.
struct patient
{
	char username[10],pass[10],gender[10],name[15],address[30],disease[20],doctor_assigned[20],issue[20];
	int phone,E_phone;
};
struct admin
{
	char username[10],pass[10],name[15];
	int phone;
};
struct doctor
{
	char username[10],pass[10],name[15],speciality[20];
	int phone;
};


int main()
{
	welcomep();
	Home();
}

void Home()
{

        // declaring choice variable for menu 1.
	int choice = 0;
    int choice1 = 0;

    cout << "1) register. \n2) login. \n3)forgotton credentials?\n"; cin >> choice;

    if (choice == 1)
    {
        reguser();
    }
    else if (choice == 2)
    {
        cout << "\nwhat is your occupation? \n1)admin \n2)doctor \n3)patient \n enter your choice: "; cin >> choice1;
        switch (choice1)
        {
        case 1:
            loggedinadmin();
        case 2:
            loggedindoctor();
        case 3:
            loggedinpatient();
        }
    }
    else if (choice == 3)
    {
        frgt();
    }
    else
    {
        cout << "wrong credentials. please try again." << endl;
        system("pause");
        system("cls");
        Home();
    }

    
}

void loggedinadmin()
{
    string user,pass;
    
    struct admin var1;
    int c = 0;
    
    cout << "\t\t\t\t << Admin login  >> \t\t\t\t" << endl;
    cout << "\nEnter user-name : ";
    cin >> user;	

  
	cout << "Enter password : ";
	cin>>pass;
   

    ifstream infile;
     infile.open("alladmins.txt");

    if (infile.fail())
    {
        cout << "\nfile failed";
    }
    else
    {


        while (!infile.eof())
        {
            infile >> var1.username;
            infile >> var1.pass;

            if (user == var1.username && pass == var1.pass)
            {
                cout << "\nvalidation successful!";
                infile.close();
                system("pause");
        		system("cls");
                admin();
            }
            else
            {
                c++;
                cout << "\nwrong credentials";
                if (c > 3)
    			{	
    				cout<<"Sorry! You have typed wrong credential too many times";
        			system("pause");
        			system("cls");
        			infile.close();
        			Home();
    			}
                loggedinadmin();
                
            }
        }
    }
   
    system("pause");
}
void loggedindoctor()
{
    string user,pass;
    struct doctor var1;
    int c = 0;
    cout << "\t\t\t\t << Doctor login  >> \t\t\t\t" << endl;
    cout << "\nEnter user-name : ";
    cin >> user;	

  
	cout << "Enter password : ";
	cin>>pass;

    ifstream infile;
    infile.open("alldoctors.txt");

    if (infile.fail())
    {
        cout << "\nfile failed";
    }
    else
    {
        while (!infile.eof())
        {
            infile >> var1.username;
            infile >> var1.pass;

            if (user == var1.username && pass == var1.pass)
            {
            	cout << "\nvalidation successful!";
               	infile.close();
               	doctorscr();
               
            }
            else
            {
                c++;
                cout << "\nwrong credentials";
                
                if (c > 3)
    			{	
    				cout<<"Sorry! You have typed wrong credential too many times";
        			system("pause");
        			system("cls");
        			infile.close();
        			Home();
    			}
    			loggedinadmin();
            }
        }
    }
   
   
    system("pause");
}
void loggedinpatient()
{
    string user,pass;
    struct patient var1;
    int c = 0;
    cout << "\t\t\t\t << Patient login  >> \t\t\t\t" << endl;
    cout << "\nEnter user-name : ";
    cin >> user;	

  
	cout << "Enter password : ";
	cin>>pass;
	
    ifstream infile;
    infile.open("allpatients.txt");

    if (infile.fail())
    {
        cout << "\nfile failed";
    }
    else
    {
        while (!infile.eof())
        {
            infile >> var1.username;
            infile >> var1.pass;

            if (user == var1.username && pass == var1.pass)
            {
                cout << "\nvalidation successful!";
                infile.close();
                patientScreen1();
            }
            else
            {
            	c++;
                cout << "\nwrong credentials";
                if (c > 3)
    			{	
    				cout<<"Sorry! You have typed wrong credential too many times";
        			system("pause");
        			system("cls");
        			infile.close();
        			Home();
    			}
    			loggedinadmin();
            }
        }
    }
   
    
}

    //register new users.
void reguser()
{
    system("cls");
    string un, pw,nm,gen,add,iss,spe;
	int p,ep;          
	int choice3 = 0;
    cout << "who do you wanna register as ?" << endl;
    cout << "1.admin\n2.doctor\n3.patient " << endl; cout << ">> ";  cin >> choice3;
                //make different register functions for admins, doctors & patients.
    if (choice3 == 1)
    {
        cout << "Enter a username : "; 
		cin >> un;
        cout << "Enter a password : "; 
		cin >> pw;
        cout << "Enter your name : "; 
		cin >> nm;
		cout << "Enter your Phone Number : "; 
		cin >> p;
		
        ofstream regdata("alladmins.txt");
        regdata <<"\n" <<un << "\n" << pw<< "\n"<<nm<<"\n" << p <<"\n" << endl << endl;
        regdata.close();
        
        cout << "\n\nyou're registered ! now please login again to continue. " << endl;
     
        system("cls");
        Home();
    }
    else if (choice3 == 2)
    {
        cout << "Enter a username : "; 
		cin >> un;
        cout << "Enter a password : "; 
		cin >> pw;
        cout << "Enter your name : "; 
		cin >> nm;
		cout << "Enter your Phone Number : "; 
		cin >> p;
		cout << "Enter Speciality : "; 
		cin >> spe;
		
        ofstream regdata("alldoctors.txt", ios::app | ios::binary);
        regdata << "\n " << un << "\n" << pw <<"\n" << nm<<"\n" << p <<"\n" << spe<< endl << endl;
        regdata.close();
        cout << "\n\nyou're registered ! now please login again to continue. " << endl;
    
        system("cls");
        
        Home();
    }
    else if (choice3 == 3)
    {
        cout << "Enter a username : "; 
		cin>>un;
        cout << "Enter a password : "; 
		cin >> pw;
        cout << "Enter your name : "; 
		cin >> nm;
        cout << "Enter your gender : "; 
		cin >> gen;
        cout << "Enter your address : "; 
		cin >> add;
        cout<<"Enter your Health Issue : "; 
		cin >>iss;
        cout<<"Enter your Phone Number : "; 
		cin >>p;
        cout << "Enter your Emergency Phone Number : "; 
		cin >>ep;


        ofstream regdata("allpatients.txt");
        regdata << "\n " << un << "\n" << pw <<"\n" << nm<<"\n" <<gen<<"\n"<<add <<"\n"<<iss<<"\n" <<p <<"\n"<<ep<<  endl << endl;
        regdata.close();
        cout << "\n\nyou're registered ! now please login again to continue. " << endl;
        system("cls");
    
        Home();
    }
    
}

    //forgotton credentials.
void frgt()
{
    system("cls");
    cout << ">> if you forgot password then contact admin at: +923xx-xxxxxxx. name: xyz." << endl;
    system("pause");
   	Home();
}

void readadmindata()
{
	char un[10], pw[10], nm[15];
	int p;
   	struct admin var1;
    	
    ifstream read;
	read.open("alladmins.txt");
			
	if(read.fail())
	{
		cout<<"\nFile Not Opened";
	}
	else
	{
		cout<<"\n\nData Loaded Successfully!";
		while(!read.eof())
		{
			if(strcmp(un,var1.username)==0 && 	strcmp(pw,var1.pass)==0 && strcmp(nm,var1.name)==0 && p==var1.phone)
			{	
				read>>var1.username;
				read>>var1.pass;
				read>>var1.name;
				read>>var1.phone;
			}
			else
			{
				read>>var1.username;
				read>>var1.pass;
				read>>var1.name;
				read>>var1.phone;
				cout<<"\n\n\t\t\t\t\tUsername : "<<var1.username;
				cout<<"\n\t\t\t\t\tPassword : "<<var1.pass;
				cout<<"\n\t\t\t\t\tName : "<<var1.name;
				cout<<"\n\t\t\t\t\tPhone number : "<<var1.phone;	
			}
			for(int i=0;i<10;i++)
			{
				un[i]=var1.username[i];
			}
			for(int i=0;i<10;i++)
			{
				pw[i]=var1.pass[i];
			}
			for(int i=0;i<15;i++)
			{
				nm[i]=var1.name[i];
			}
			p=var1.phone;
		}
		read.close();	
		admin();	
	}
}

void update_admin_data()
{
	int k=0;
	string line;
   	string find;
    			
	string un, pw,nm;
	int p;    

   	ofstream myfile;
   	myfile.open("alladmins.txt");		

   	cout<<"\n\nEnter the Name of Person You want update Details of :"<<endl;
    cin>>find; 
           		
	ifstream file;
	cout<<line;
		
    file.open("alladmins.txt");
		  	
		
    while (!file.eof() && line!=find)
    {
		getline(file,line);
    }

    cout << "Enter New username : "; 
	cin >> un;
    cout << "Enter New password : "; 
	cin >> pw;
    cout << "Enter New name : "; 
	cin >> nm;
	cout << "Enter New Phone Number : "; 
	cin >> p;
            	
    cout<<"\n\nData is Changed and  Searching have been Occured if not then U entered Wrong name\n";
            	
    myfile <<"\n" <<un << "\n" << pw<< "\n"<<nm<<"\n" << p <<"\n" << endl << endl;
        
        
    myfile.close();
    file.close();
    admin();
}

void read_patient_data()
{
	char un[10], pw[10],nm[15],gen[10],add[30],iss[20],spe[20];
	int p,ep;
	
	struct patient var1;
	
	ifstream read;
	read.open("allpatients.txt");
			
	if(read.fail())
	{
		cout<<"\nFile Not Opened";
	}
	else
	{
		cout<<"\n\nData Loaded Successfully!";
		while(!read.eof())
		{
			if(strcmp(un,var1.username)==0 && strcmp(pw,var1.pass)==0 && strcmp(nm,var1.name)==0 && p==var1.phone)
			{	
				read>>var1.username;
				read>>var1.pass;
				read>>var1.name;
				read>>var1.gender;
				read>>var1.address;
				read>>var1.issue;
				read>>var1.E_phone;
				read>>var1.phone;
				
			}
			else
			{
				read>>var1.username;
				read>>var1.pass;
				read>>var1.name;
				read>>var1.gender;
				read>>var1.address;
				read>>var1.issue;
				read>>var1.E_phone;
				read>>var1.phone;
				cout<<"\n\n\t\t\t\t\tUsername : "<<var1.username;
				cout<<"\n\t\t\t\t\tPassword : "<<var1.pass;
				cout<<"\n\t\t\t\t\tName : "<<var1.name;
				cout<<"\n\t\t\t\t\tGender : "<<var1.gender;
				cout<<"\n\t\t\t\t\tAddress : "<<var1.address;
				cout<<"\n\t\t\t\t\tIssue : "<<var1.issue;
				cout<<"\n\t\t\t\t\tPhone number : "<<var1.phone;
				cout<<"\n\t\t\t\t\tE-Phone number : "<<var1.E_phone;
									
			}
			for(int i=0;i<10;i++)
			{
				un[i]=var1.username[i];
			}
			for(int i=0;i<10;i++)
			{
				pw[i]=var1.pass[i];
			}
			for(int i=0;i<15;i++)
			{
				nm[i]=var1.name[i];
			}
			p=var1.phone;
		}
		read.close();	
		admin();	
	}
}
void update_patient_data()
{
	int k=0;
	string line;
   	string find;
    			
	string un, pw,nm,gen,add,iss;
	int p,ep;  

   	ofstream myfile;
   	myfile.open("allpatients.txt");		

   	cout<<"\n\nEnter the Name of Person You want update Details of :"<<endl;
    cin>>find; 
           		
	ifstream file;
	cout<<line;
		
    file.open("allpatients.txt");
		  	
		
    while (!file.eof() && line!=find)
    {
		getline(file,line);
    }

    cout << "Enter New username : "; 
	cin >> un;
    cout << "Enter New password : "; 
	cin >> pw;
    cout << "Enter New name : "; 
	cin >> nm;
	cout<<"Enter Gender : ";
	cin>>gen;
	cout<<"Enter New Address : ";
	cin>>add;
	cout<<"Enter New Health Problem : ";
	cin>>iss;
	cout << "Enter New Phone Number : "; 
	cin >> p;
	cout<<"Enter New E-Contact : ";
	cin>>ep;
            	
    cout<<"\n\nData is Changed and  Searching have been Occured if not then U entered Wrong name\n";
            	
    myfile <<"\n " << un << "\n" << pw <<"\n" << nm<<"\n" <<gen<<"\n"<<add <<"\n"<<iss<<"\n" <<p <<"\n"<<ep<<  endl << endl;
        
        
    myfile.close();
    file.close();
    admin();
}
void read_doctor_data()
{
	char un[10], pw[10],nm[15],spe[20];
	int p;
   	struct doctor var1;
    	
    ifstream read;
	read.open("alldoctors.txt");
			
	if(read.fail())
	{
		cout<<"\nFile Not Opened";
	}
	else
	{
		cout<<"\n\nData Loaded Successfully!";
		while(!read.eof())
		{
			if(strcmp(un,var1.username)==0 && 	strcmp(pw,var1.pass)==0 && strcmp(nm,var1.name)==0 && p==var1.phone)
			{	
				read>>var1.username;
				read>>var1.pass;
				read>>var1.name;
				read>>var1.phone;
				read>>var1.speciality;
			}
			else
			{
				read>>var1.username;
				read>>var1.pass;
				read>>var1.name;
				read>>var1.phone;
				read>>var1.speciality;
				cout<<"\n\n\t\t\t\t\tUsername : "<<var1.username;
				cout<<"\n\t\t\t\t\tPassword : "<<var1.pass;
				cout<<"\n\t\t\t\t\tName : "<<var1.name;
				cout<<"\n\t\t\t\t\tPhone number : "<<var1.phone;
				cout<<"\n\t\t\t\t\tSpecialies in : "<<var1.speciality;	
			}
			for(int i=0;i<10;i++)
			{
				un[i]=var1.username[i];
			}
			for(int i=0;i<10;i++)
			{
				pw[i]=var1.pass[i];
			}
			for(int i=0;i<15;i++)
			{
				nm[i]=var1.name[i];
			}
			for(int i=0;i<20;i++)
			{
				spe[i]=var1.speciality[i];
			}
			p=var1.phone;
		}
		read.close();	
		admin();	
	}
}
void update_doctor_data()
{
	int k=0;
	string line;
   	string find;
    			
	string un, pw,nm,sp;
	int p;    

   	ofstream myfile;
   	myfile.open("alldoctors.txt");		

   	cout<<"\n\nEnter the Name of Person You want update Details of :"<<endl;
    cin>>find; 
           		
	ifstream file;
	cout<<line;
		
    file.open("alldoctors.txt");
		  	
		
    while (!file.eof() && line!=find)
    {
		getline(file,line);
    }

    cout << "Enter New username : "; 
	cin >> un;
    cout << "Enter New password : "; 
	cin >> pw;
    cout << "Enter New name : "; 
	cin >> nm;
	cout << "Enter New Phone Number : "; 
	cin >> p;
	cout << "Enter New Speciality : "; 
	cin >> sp;
            	
    cout<<"\n\nData is Changed and  Searching have been Occured if not then U entered Wrong name\n";
            	
    myfile <<"\n" << un << "\n" << pw <<"\n" << nm<<"\n" << p <<"\n" << sp<< endl << endl;
        
        
    myfile.close();
    file.close();
    admin();
}
void admin() 
{
    int c = 0,c1;
    cout << "\n\n\t\t\t\t\t <<<< welcome admin >>>\t\t" << endl;
    cout << "\n\t\t\t\t\t1)View Admin data \n\t\t\t\t\t2)Edit Admin Data \n\t\t\t\t\t3)View Doctor's data \n\t\t\t\t\t4)Edit Doctor's Data \n\t\t\t\t\t5)View Patient's data \n\t\t\t\t\t6)Edit Patient's Data \n\t\t\t\t\t7)Go back\n";
    cout << " >> "; 
    cin >> c;
    
    if(c==1)
    {
    	readadmindata();
	}
	
	else if(c==2)
	{
		update_admin_data();
	}
	else if(c==3)
	{
		read_doctor_data();
	}
	else if(c==4)
	{
		update_doctor_data();
	}
	else if(c==5)
	{
		read_patient_data();
	}
	else if(c==6)
	{
		update_patient_data();
	}
	else if(c==7)
	{
		Home();
	}
	else
	{
		cout<<"\n\n Wrong Choice!";
		admin();
	}
	
}

void patientScreen1()
{
	cout<<"\n\n\t\t\t\t\t1)View His Patient Card\n\t\t\t\t\t2)Find Suitable Doctor\n\t\t\t\t\t3)Go Back\n";
	int c;
	cin>>c;
	
	

	if(c==1)
	{
	
		char un[10], pw[10],nm[15],gen[10],add[30],iss[20],spe[20],name[15];
	int p,ep;
	
	cout<<"\nPlz Enter your Name : ";
	cin>>name[15];
	
	struct patient var1;
	
	ifstream read;
	read.open("allpatients.txt");
			
	if(read.fail())
	{
		cout<<"\nFile Not Opened";
	}
	else
	{
		cout<<"\n\nData Loaded Successfully!";
		while(!read.eof())
		{
			if(strcmp(un,var1.username)==0 && strcmp(pw,var1.pass)==0 && strcmp(nm,var1.name)==0 && p==var1.phone)
			{	
				read>>var1.username;
				read>>var1.pass;
				read>>var1.name;
				read>>var1.gender;
				read>>var1.address;
				read>>var1.issue;
				read>>var1.E_phone;
				read>>var1.phone;
				
			}
			else
			{
				read>>var1.username;
				read>>var1.pass;
				read>>var1.name;
				read>>var1.gender;
				read>>var1.address;
				read>>var1.issue;
				read>>var1.E_phone;
				read>>var1.phone;
				
					cout<<"\n\n\t\t\t\t\tUsername : "<<var1.username;
					cout<<"\n\t\t\t\t\tPassword : "<<var1.pass;
					cout<<"\n\t\t\t\t\tName : "<<var1.name;
					cout<<"\n\t\t\t\t\tGender : "<<var1.gender;
					cout<<"\n\t\t\t\t\tAddress : "<<var1.address;
					cout<<"\n\t\t\t\t\tIssue : "<<var1.issue;
					cout<<"\n\t\t\t\t\tPhone number : "<<var1.phone;
					cout<<"\n\t\t\t\t\tE-Phone number : "<<var1.E_phone;
				}
				
									
			}
			for(int i=0;i<10;i++)
			{
				un[i]=var1.username[i];
			}
			for(int i=0;i<10;i++)
			{
				pw[i]=var1.pass[i];
			}
			for(int i=0;i<15;i++)
			{
				nm[i]=var1.name[i];
			}
			p=var1.phone;
		}
		read.close();	
		patientScreen1();	
		
	}
	
	else if(c==3)
	{
		Home();
	}
	else
	{
		cout<<"\nWrong Choice";
		patientScreen1();
	}
}
void doctorscr()
{
	cout<<"\n\n\t\t\t\t2)His Data\n\t\t\t\t2)Patient Data\n\t\t\t\t3)Go Back\n>>";
	int c;
	cin>>c;
	
	if(c==1)
	{
		struct doctor var1;
		int c=0;
		
		char name[10];
		cout<<"Please Enter Your Name : ";
		cin>>name[10];
	
		ifstream read;
		read.open("alldoctors.txt");
			
		if(read.fail())
		{
			cout<<"\nFile Not Opened";
		}
		else
		{
			while(!read.eof())
			{
					read>>var1.username;
					read>>var1.pass;
					read>>var1.name;
					read>>var1.phone;
					read>>var1.speciality;
			
				if(strcmp(name,var1.name)==0)
				{
					cout<<"\n\n\t\t\t\t\tUsername : "<<var1.username;
					cout<<"\n\t\t\t\t\tPassword : "<<var1.pass;
					cout<<"\n\t\t\t\t\tName : "<<var1.name;
					cout<<"\n\t\t\t\t\tPhone number : "<<var1.phone;
					cout<<"\n\t\t\t\t\tSpecializes in : "<<var1.speciality;
					c++;					
				}
				else
				{
					
				}
				
			}
			if(c==0)
			{
				cout<<"\n\nRecord Not Exist!";
			}
			read.close();	
			doctorscr();	
		}
	}
	else if(c==3)
	{
		Home();
	}
	else
	{
		cout<<"\nWrong Choice";
		doctorscr();
	}

}

