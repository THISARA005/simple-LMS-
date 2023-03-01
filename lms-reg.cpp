#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;


void headStudent();
void headAccount();
void headCourse();



class members{
	public:

		char member_name[50];
		int registration_no;
		char gender;
		char email[30];
		char phone_no[10];
		int year;
		int semester;
		char course[30];




};
	   class Student:public members
		{
		    public:


	    void getData()
		{
			cout<<"\n Please Enter Your Details:";
			cout<<"Student Full Name:";
			cin>>member_name;
			cout<<"Student Registration Number:";
			cin>>registration_no;
			cout<<"Your Gender ";
			cin>>gender;
			cout<<"Your Email";
			cin>>email;
			cout<<"Phone no";
			cin>>phone_no;
			cout<<"Academic Year ";
			cin>>year;
			cout<<"Current semester:";
			cin>>semester;
			cout<<"Your Courses";
			cin>>course;

		}

	   void showData()
		{
			cout<<"\n\nStudents Details\n\n";

			cout<<"student Name :"<<member_name<<endl;
			cout<<"student Registration No: "<<registration_no<<endl;
			cout<<"Gender : "<<gender<<endl;
			cout<<"Email : "<<email<<endl;
			cout<<"Phone no: "<<phone_no<<endl;
			cout<<"Academic Year : "<<year<<endl;
			cout<<"current Semester"<<semester<<endl;
			cout<<"Your Courses: "<<course<<endl;

		}

		void listData()
		{
			cout.setf(ios::left);
			cout<<setw(12)<<registration_no;
			cout<<setw(20)<<member_name;
			cout<<setw(20)<<email;
			cout<<setw(15)<<phone_no;
			cout<<setw(10)<<year;
			cout<<setw(10)<<semester;
			cout<<setw(20)<<course;
			cout<<endl;
		}
		int getregNo(){}
     }s;



class Admin:public members{

        public:
            int account_no;
            int course_code;


		    int getAccno()
			{
			  return account_no;
			}

			int getCrscode()
			{
			  return course_code;
			}

			Admin()
		   {
			account_no=0000;
			strcpy(member_name,"Empty");
			strcpy(email,"Empty");
			course_code=0;
			strcpy(course,"Empty");

			cout<<"Default Constructor Invoked....";
		   }




		    void cr_account()
			{
			cout<<"\nEnter Account Details\n";

			cout<<"Your Full Name: ";
			cin>>member_name;
			cout<<"Your Account no: ";
			cin>>account_no;
			cout<<"Email: ";
			cin>>email;

			}

			void showData_acc()
		    {
			cout<<"\n\nAccount Details\n\n";

			cout<<"Account No.: "<<account_no<<endl;
			cout<<"Name : "<<member_name<<endl;
			cout<<"Email: "<<email<<endl;

		    }

		    void listData_acc()
		    {
			cout.setf(ios::left);
			cout<<setw(20)<<account_no;
			cout<<setw(30)<<member_name;
			cout<<setw(20)<<email;

			cout<<endl;
		    }

			void cr_course()
			{
			cout<<"\nEnter Courses Details\n";
			cout<<"Course code : ";
			cin>>course_code;
			cout<<"Course : ";
			cin>>course;


			}

			void showData_crs()
		    {
			cout<<"\n\nCourse Details\n\n";

			cout<<"Course code     : "<<course_code<<endl;
			cout<<"Course          : "<<course<<endl;

		    }

		    void listData_crs()
		    {
			cout.setf(ios::left);
			cout<<setw(20)<<course_code;
			cout<<setw(25)<<course;

			cout<<endl;
		    }

	 }ad;



     void addStudent()
   {
	ofstream fout;
	fout.open("Stu_Data.txt",ios::out|ios::app|ios::binary);
	s.getData();
	fout.write((char*)&s,sizeof(members));
	fout.close();
	cout<<"\n\nData Saved to file....\n";
	s.showData();
   }



     void showStudents()
   {
	ifstream fin;
	fin.open("Stu_Data.txt",ios::in|ios::binary);
	headStudent();
	while(fin.read((char*)&s,sizeof(s)))
	{

		s.listData();
	}
	fin.close();
   }



      void headStudent()
		{
			cout.setf(ios::left);
			cout<<setw(10)<<"Registration number";
			cout<<setw(20)<<"Full Name";
			cout<<setw(20)<<"Email";
			cout<<setw(15)<<"Phone number";
			cout<<setw(10)<<"Year";
			cout<<setw(10)<<"Semester";
			cout<<setw(20)<<"Course";
			cout<<endl;
		}


	void modifyStudent()
  {
	fstream fio;
	fio.open("Stu_Data.txt",ios::in|ios::out|ios::binary);
	int rg,flag=0, pos;
	cout<<"Enter Reg_No. to be modified: ";
	cin>>rg;

	while(fio.read((char*)&s,sizeof(s)))
	{
		if(rg==s.getregNo())
		{
			pos=fio.tellg();
			cout<<"Following record found to be modified....\n";
			s.showData();

			cout<<"\nEnter new record details\n";
			fio.seekg(pos-sizeof(s));
			s.getData();
			fio.write((char*)&s,sizeof(s));
			flag++;
		}
	}
	fio.close();
	if (flag==0)
		cout<<"No such Registration number in file...\n";
}


void stchoice()
      {
	      int ch1;
	      cout<<"\t\t 1) Register for a course\n";
		  cout<<"\t\t 2) Modify data\n";

		  cout<<"Enter your choice: ";
		  cin>>ch1;

		  switch(ch1)
		  {
		     case 1: addStudent(); break;
			 case 2: modifyStudent();
		  }
	   }

void addAccount()
   {
	ofstream fout;
	fout.open("Acct_Data.txt",ios::out|ios::app|ios::binary);
	ad.cr_account();
	fout.write((char*)&ad,sizeof(Admin));
	fout.close();
	cout<<"\n\nData Saved to file....\n";
	ad.showData_acc();
   }


 void showAccounts()
   {
	ifstream fin;
	fin.open("Acct_Data.txt",ios::in|ios::binary);
	headAccount();
	while(fin.read((char*)&ad,sizeof(ad)))
	{
		//ad.showData_acc();
		ad.listData_acc();
	}
	fin.close();
   }

void headAccount()
		    {
			cout.setf(ios::left);
			cout<<setw(15)<<"Account_No";
			cout<<setw(20)<<"Name";
			cout<<setw(20)<<"Email";
			cout<<setw(15)<<"Designation";
			cout<<endl;
		    }



void modifyAccount()
  {
	fstream fio;
	fio.open("Acct_Data.txt",ios::in|ios::out|ios::binary);
	int ac,flag=0, pos;
	cout<<"Enter Account_No. to be modified: ";
	cin>>ac;

	while(fio.read((char*)&ad,sizeof(ad)))
	{
		if(ac==ad.getAccno())
		{
			pos=fio.tellg();
			cout<<"Following record found to be modified....\n";
			ad.showData_acc();

			cout<<"\nEnter new record details\n";
			fio.seekg(pos-sizeof(ad));
			ad.cr_account();
			fio.write((char*)&ad,sizeof(ad));
			flag++;
		}
	}
	fio.close();
	if (flag==0)
		cout<<"No such Account number in file...\n";
}



void addCourse()
   {
	ofstream fout;
	fout.open("Course_Data.bin",ios::out|ios::app|ios::binary);
	ad.cr_course();
	fout.write((char*)&ad,sizeof(Admin));
	fout.close();
	cout<<"\n\nData Saved to file....\n";
	ad.showData_crs();
   }


void showCourses()
   {
	ifstream fin;
	fin.open("Course_Data.bin",ios::in|ios::binary);
	headCourse();
	while(fin.read((char*)&ad,sizeof(ad)))
	{

		ad.listData_crs();
	}
	fin.close();
   }



void modifyCourse()
  {
	fstream fio;
	fio.open("Course_Data.bin",ios::in|ios::out|ios::binary);
	int crs,flag=0, pos;
	cout<<"Enter Course code to be modified: ";
	cin>>crs;

	while(fio.read((char*)&ad,sizeof(ad)))
	{
		if(crs==ad.getCrscode())
		{
			pos=fio.tellg();
			cout<<"Following record found to be modified....\n";
			ad.showData_crs();

			cout<<"\nEnter new record details\n";
			fio.seekg(pos-sizeof(ad));
			ad.cr_course();
			fio.write((char*)&ad,sizeof(ad));
			flag++;
		}
	}
	fio.close();
	if (flag==0)
		cout<<"No such course code in file...\n";
}


void headCourse()
		    {
			cout.setf(ios::left);
			cout<<setw(15)<<"course code";
			cout<<setw(25)<<"course";
			cout<<setw(20)<<"lecturer";
			cout<<endl;
		    }



void adchoice()
      {
	      int ch2;
	      cout<<"\t\t 1) create accounts\n";
		  cout<<"\t\t 2) create courses\n";
		  cout<<"\t\t 3) show all accounts\n";
		  cout<<"\t\t 4) show all courses\n";

		  cout<<"Enter your choice: ";
		  cin>>ch2;

		  switch(ch2)
		  {
		     case 1: addAccount(); break;
			 case 2: addCourse(); break;
			 case 3: cout<<"\nDETAILS OF ACCOUNTS\n\n"; showAccounts(); break;
			 case 4: cout<<"\nDETAILS OF COURSES\n\n"; showCourses();

		  }
	   }


void menu()
{
    cout<<"______________________________________\n";

	cout<<"              MENUE                  \n";
	cout<<"_______________________________________\n\n";

	cout<<"Press the number according to your designation\n\n";
	cout<<"1. Student\n";
	cout<<"2. Lecturer\n";
	cout<<"3. Member of Management staff\n";
	cout<<"4. Admin\n\n";
	cout<<"Enter your choice: ";
}


int main()
{
  int choice;
  members s[1000];

  do
   {
     system("cls");
	 menu();
	 cin>>choice;
	 switch(choice)
	 {
	   case 1: stchoice(); break;
	   case 2: cout<<"\nDETAILS OF REGISTERED STUDENTS\n\n";showStudents(); break;
	   case 3: cout<<"\nDETAILS OF REGISTERED STUDENTS\n\n";showStudents(); break;
	   case 4: adchoice();
	 }
	 system("pause");
	}
	while(choice);

	return 0;
}




