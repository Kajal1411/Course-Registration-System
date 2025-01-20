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