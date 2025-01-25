#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Student
{
	public:
	string name,password,usertype,email;
	int mob;
	
	void registration()
	{
		ofstream f1;
		f1.open("Users.txt", ios::app);   // Open the file in append mode
		
		// Taking user input for registration		
		cout<<"Enter your name:";
		cin.ignore();
    	getline(cin, name);
    	cout<<"Enter password:";
    	getline(cin, password);
    	cout<<"Enter user type(Admin,student):";
		getline(cin, usertype);
		
		// Saving the user data to the file
		f1<<name<<","<<password<<","<<usertype<<endl;
        f1.close();
        cout<<"Registration successful!"<<endl;
	}
		
	void login()
	{
		ifstream f2;
        string name,password,line;
        bool flag = false;
        f2.open("Users.txt");
		cout<<"Enter your name:";
		cin.ignore();
    	getline(cin, name);
    	cout<<"Enter password:";
    	getline(cin, password);
    	while (getline(f2, line))
    	{
    		//size_t is used to represent the size or position of something.
            size_t pos1 = line.find(",");
            size_t pos2 = line.find(",", pos1 + 1);

            string storedUsername = line.substr(0, pos1);
            string storedPassword = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string storedUserType = line.substr(pos2 + 1);

            if(storedUsername==name&&storedPassword==password) 
			{
                cout<<"Login successful!"<<endl;
                cout<<endl;
                cout<<"3.Exit"<<endl;
                cout<<"4.Add course"<<endl;
            	cout<<"5.Update course"<<endl;
            	cout<<"6.Delete course"<<endl;
             	cout<<"7.View courses"<<endl;
            	cout<<"8.Register for course"<<endl;
            	cout<<"9.View registered students"<<endl;	
                flag = true;
                break;
            }
        }
        f2.close();
        if(flag==false)
        {
        	cout<<"Invalid username or password.Try again!"<<endl;
		}    		
	}
	
	void exit()
	{
		cout<<"Exiting...";
	}		
};

class Course
{
	public:
	int fee;
	string id,cname,instructor,duration;
	
	void addCourse()
	{
		ofstream f1;
		f1.open("Courses.txt", ios::app); 
		cout<<"Enter course id:";
	    cin>>id;
		cout<<"Enter course name:";
		cin.ignore();
		getline(cin, cname);
		cout<<"Enter course fee:";
		cin>>fee;
		cout<<"Enter course duration:";
		cin.ignore();
		getline(cin, duration);
		cout<<"Enter instructor name:";
		getline(cin, instructor);
		f1<<id<<","<<cname<<","<<fee<<","<<duration<<","<<instructor<<endl;
		f1.close();
		cout<<"Course is added succesfully!"<<endl;
		cout<<endl;
        cout<<"4.Add course"<<endl;
        cout<<"5.Update course"<<endl;
        cout<<"6.Delete course"<<endl;
        cout<<"7.View courses"<<endl;
        cout<<"8.Register for course"<<endl;
        cout<<"9.View registered students"<<endl;	
	}
	
	void viewCourse()
	{
		ifstream f1;
		string line;
		f1.open("Courses.txt");
		cout<<"Courses:"<<endl;
		cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
		while(getline(f1, line))
		{
			cout<<line<<endl;
		}
		f1.close();
		cout<<endl;
		cout<<"4.Add course"<<endl;
        cout<<"5.Update course"<<endl;
        cout<<"6.Delete course"<<endl;
        cout<<"7.View courses"<<endl;
        cout<<"8.Register for course"<<endl;
        cout<<"9.View registered students"<<endl;	
	}	
};


class Admin:public Student,public Course
{
	public:	
	void updateCourse()
	{
		string courseId,idToUpdate,line;
		bool flag=false;
		cout<<"Enter course id to update:";
		cin>>idToUpdate;
		ifstream f1;
		f1.open("Courses.txt");
		ofstream f2("TempCourses.txt");
		while(getline(f1, line))
		{			
            courseId=line.substr(0,3);  
			if(courseId != idToUpdate)
			{
				f2<<line<<endl;
			}
			if(courseId == idToUpdate)
			{
				flag=true;
				cout<<"Enter course id:";
        	    cin>>id;
	         	cout<<"Enter course name:";
	        	cin.ignore();
	         	getline(cin, cname);
	        	cout<<"Enter course fee:";
	        	cin>>fee;
	        	cout<<"Enter course duration:";
	         	cin.ignore();
	        	getline(cin, duration);
	        	cout<<"Enter instructor name:";
	        	getline(cin, instructor);
	        	f2<<id<<","<<cname<<","<<fee<<","<<duration<<","<<instructor<<endl;
			}	
		}
		f1.close();
		f2.close();
		remove("Courses.txt");        // Delete the original file
        rename("TempCourses.txt", "Courses.txt");    // Rename the temporary file to the original file name
        if(flag==true)
        {
        	cout<<"Course is updated succesfully!";	
    		cout<<endl;
    		cout<<"4.Add course"<<endl;
            cout<<"5.Update course"<<endl;
            cout<<"6.Delete course"<<endl;
            cout<<"7.View courses"<<endl;
            cout<<"8.Register for course"<<endl;
            cout<<"9.View registered students"<<endl;
		}
		if(flag==false)
		{
			cout<<"Course with the given ID not found."<<endl;
			cout<<endl;
    		cout<<"4.Add course"<<endl;
            cout<<"5.Update course"<<endl;
            cout<<"6.Delete course"<<endl;
            cout<<"7.View courses"<<endl;
            cout<<"8.Register for course"<<endl;
            cout<<"9.View registered students"<<endl;
		}
	}
	
	void deleteCourse()
	{
		string courseId,idToDelete,line;
		bool flag=false;
		cout<<"Enter course id to delete:";
		cin>>idToDelete;
		ifstream f1;
		f1.open("Courses.txt");
		ofstream f2("TempCourses.txt");
		while(getline(f1, line))
		{			
            courseId=line.substr(0,3);  
			if(courseId != idToDelete)
			{
				f2<<line<<endl;
			}
			if(courseId == idToDelete)
			{
				flag=true;
			}	
		}
		f1.close();
		f2.close();
		remove("Courses.txt");        // Delete the original file
        rename("TempCourses.txt", "Courses.txt");    // Rename the temporary file to the original file name
        if(flag==true)
        {
        	cout<<"Course is deleted succesfully!";	
    		cout<<endl;
    		cout<<"4.Add course"<<endl;
            cout<<"5.Update course"<<endl;
            cout<<"6.Delete course"<<endl;
            cout<<"7.View courses"<<endl;
            cout<<"8.Register for course"<<endl;
            cout<<"9.View registered students"<<endl;
		}
		if(flag==false)
		{
			cout<<"Course with the given ID not found."<<endl;
			cout<<endl;
    		cout<<"4.Add course"<<endl;
            cout<<"5.Update course"<<endl;
            cout<<"6.Delete course"<<endl;
            cout<<"7.View courses"<<endl;
            cout<<"8.Register for course"<<endl;
            cout<<"9.View registered students"<<endl;
		}			
	}
	void courseRegistration()
	{
		ofstream f1;
		f1.open("CourseRegistration.txt", ios::app); 
		cout<<"Enter your name:";
		cin.ignore();
    	getline(cin, name);
	    cout<<"Enter your mobile number:";
    	cin>>mob;
    	cout<<"enter email:";
    	cin.ignore();
    	getline(cin, email);
		cout<<"Enter course name:";
		getline(cin, cname);
		f1<<name<<","<<mob<<","<<email<<","<<cname<<endl;
		f1.close();
		cout<<"You are succesfully registered for course!"<<endl;
		cout<<endl;
    	cout<<"4.Add course"<<endl;
        cout<<"5.Update course"<<endl;
        cout<<"6.Delete course"<<endl;
        cout<<"7.View courses"<<endl;
        cout<<"8.Register for course"<<endl;
        cout<<"9.View registered students"<<endl;
	}
	
	void viewRegisteredStudents()
	{
	    ifstream f1;
		string line;
		f1.open("CourseRegistration.txt");
		cout<<"Registered students for courses:"<<endl;
		cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
		while(getline(f1, line))
		{
			cout<<line<<endl;
		}
		f1.close();
		cout<<endl;
		cout<<"4.Add course"<<endl;
        cout<<"5.Update course"<<endl;
        cout<<"6.Delete course"<<endl;
        cout<<"7.View courses"<<endl;
        cout<<"8.Register for course"<<endl;
        cout<<"9.View registered students"<<endl;	
	}		
};
	