// in the name of god
// Author : Majid Sepasi

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class Task;
class User;
string curUser, curFul;

void mainMenu();
void back_main();
void signUp();
void login();
bool is_username_repeatitive(string );
bool is_username_exist(string , string &);
void show_all_users();
void show_all_tasks();
string get_fullname(string );



vector<User> totalUsers;
vector<Task> totalTasks;

class Date{
	public:
		int year;
		int month;
		int day;
		string hour;
		Date();
		Date(int, int, int , string);
		void get_info();
		string toString();
		bool isEqual(const Date );
		
		
};

class Task{
	public:
		static int uniq;
		int id;
		
		string title;
		string owner;
		Date deadLine;
		
		Task();
		Task(string );
		void view_all_tasks();
		void view_tasks_of(string );
		void add_task();
		void print_task();
		void goto_task_page(int );
		void goto_task_page(string );
		void set_deadline(Date);
		void assign_task_to(string);
		void print_task_all_info();
};

class User{
	public:
		string fullName;
		string userName;
		string password;
		Date birthday;
		User();
		void signUp();
		void login();	
		void show_info();	
		bool isStrongPassword(string );
		void forgot_password();
		void goto_main_page();
};


Date::Date(){}
Date::Date(int y, int m, int d, string h)
{
			year = y;
			month = m;
			day = d;
			hour = h;
}
void Date::get_info()
{
	cout << "\tYear : ";
	cin >> year;
	
	month = -1;
	day = -1;

	while(month < 1 || month > 12)
	{
		cout << "\tMonth [1-12]: ";
		cin >> month;
	}
	while(day < 1 || day > 31)
	{
		cout << "\tDay [1-31]: ";
		cin >> day;
	}

	cout << "Time: \n";
	
	int h = -1;
	int m = -1;
	while(h < 1 || h > 24)
	{
		cout << "\t Hour : ";
		cin >> h;
	}
	while(m < 1 || m > 59)
	{
		cout << "\t Minute : ";
		cin >> m;
	}
	hour = to_string(h) + ":" + to_string(m);
}
string Date::toString()
{
	return (to_string(year)) + "/" + to_string(month) + "/" + to_string(day) + "\t" + hour;
}
bool Date::isEqual(const Date x)
{
	return ( year == x.year && month == x.month && day == x.day);
}


User::User(){}
void User::signUp()
{
	system("cls");
	cout << "Sign up \n";
	cout << "---------\n\n";
	
	User user;
	cout << "Enter user full name : ";
	getline(cin, user.fullName);
	getline(cin, user.fullName);

	cout << "Enter username : ";
	cin >> user.userName;
	while(is_username_repeatitive(user.userName))
	{
		cout << "User name is aleady exist ... try again : ";
		cin >> user.userName;
	}
	string confirm;
	do{
		cout << "Enter password : ";
		cin >> user.password;
		while(isStrongPassword(user.password) == false)
		{
			cout << "This password is not strong !! try again : ";
			cin >> user.password;
		}
		cout << "Enter password again : ";
		cin >> confirm;
		if(user.password != confirm)
		{
			cout << "Passwords don't match. try again ...\n";
		}
	}while(user.password != confirm);
	
	cout << "Enter birthday information :\n";
	Date birtDate;
	birtDate.get_info();
	user.birthday = birtDate;
	
	totalUsers.push_back(user);
	
	cout << "\n\n" << "Sign up has been done successfully ...";
	back_main();
}
void User::login()
{
	system("cls");
	cout << "Login \n";
	cout << "------\n\n";
	
	cout << "Select one of the options below : \n";
	cout << " 1.login \n" ;
	cout << " 2.forgot password \n";
	cout << " 3.back to main menu \n\n";
	
	cout << "Enter your choose : "; 
	int option;
	cin >> option;
	switch(option)
	{
		case 3 : mainMenu(); break;
		case 2 : forgot_password(); break;
		case 1 :
			{
				cout << "\n\n";
				string un, password, pass;
				cout << "Enter user name : ";
				cin >> un;
				if(is_username_exist(un, password) == false)
				{
					cout << "This username doesn't exist !!\n";
				}
				else
				{
					cout << "Enter password : ";
					cin >> pass;
					if(pass == password)
					{
						curUser = un;
						curFul = get_fullname(un);
						goto_main_page();
					}
					else
					{
						cout << "\nThis password is not correct !!";	
					}
				}
			} break;
			
			default : cout << "Wrong option !! \n";
		
	}
	cout << "\n\nEnter any key to load again ...";
	getch();
	login();
}
string get_fullname(string username)
{
	for(int i = 0; i < totalUsers.size(); i++)
	{
		if(totalUsers[i].userName == username)
			return totalUsers[i].fullName;
	}
	return "";
}

void User::goto_main_page()
{
	system("cls");
	cout << "Main page \n";
	cout << "----------\n\n";
	cout << "User name : " << curUser << endl;
	cout << "Full name : " << curFul << endl << endl;
	
	cout << "Select one of the options below : \n";
	cout << " 1.View all tasks \n";
	cout << " 2.View user tasks \n";
	cout << " 3.Add new task \n";
	cout << " 4.Return to login menu \n";
	cout << " 5.Return to main menu \n\n";
	
	cout << "Enter your choose : ";
	int op;
	cin >> op;
	Task task;
	switch(op)
	{
		case 1: task.view_all_tasks(); break;
		case 2:
			{
				string un;
				cout << "\n\nEnter username to show their tasks : ";
				cin >> un;
				task.view_tasks_of(un);
			}break;
		case 3: task.add_task(); break;
		case 4 : login(); break;
		case 5 : mainMenu(); break;
		default : cout << "Wrong option !!\n";
	}
	cout << "Enter any key to load again ...";
	getch();
	goto_main_page();
}
void User::show_info()
{
	cout << fullName << ", " << userName << ", " << password << ", " << birthday.toString();
	cout << endl;
}
bool User::isStrongPassword(string s)
{
	regex valid("[0-9]{1,3}[A-Z][a-z]{5,10}");
	return regex_match(s, valid) ;
}
void User::forgot_password()
{
	system("cls");
	cout << "Forgot password \n";
	cout << "--------------\n\n";
	
	string uname, h;
	cout << "Enter user name : ";
	cin >> uname;
	Date d;
	d.get_info();
	bool find = 0;
	for(int i = 0; i < totalUsers.size(); i++)
	{
		if(totalUsers[i].userName == uname && totalUsers[i].birthday.isEqual(d))
		{
			cout << "Enter new password : ";
			string newpass;
			cin >> newpass;
			while(isStrongPassword(newpass) == false)
			{
				cout << "This password is not strong !! try again : ";
				cin >> newpass;
			}
			totalUsers[i].password = newpass;
			cout << "The password has been changed successfully .. \n";
			find = 1;
			break;
		}
	}
	if(!find)
		cout << "Account didn't find !!\n";

	cout << "Enter a key to back login page ...";
	getch();
	login();	
}


int Task::uniq = 1;
Task::Task(){}
Task::Task(string title)
{
	this -> title = title;
	id = uniq++;
	owner = "";
}
void Task::set_deadline(Date d)
{
	deadLine = d;
	cout << "\n\nTask deadline has been setted successfully ...\n\n";
}

void Task::assign_task_to(string un)
{
	
	bool find = 0;
	string full;
	for(int i = 0; i < totalUsers.size(); i++)
	{
		if(totalUsers[i].userName == un)
		{
			find = 1;
			full = totalUsers[i].fullName;
		}
	}
	if(!find)
	{
		cout << "This username doesn't exist !!\n\n";
		return;
	}
	
	cout << "Are you sure you want to assign the task to this user ?[y/n]";
	char ans;
	cin >> ans;
	if(ans == 'y' || ans == 'Y')
	{	
		owner = un;
		cout << "Task has been assigned successfully to user ...\n\n";
		return;
	}	
	cout << "Assignig task has been cancelled ...\n\n";
}
void Task:: print_task()
{
	cout << "Task id = " << id << "\t" << "Task title : " << title << endl;
}
void Task::print_task_all_info()
{
	cout << "\tTask id : " << id << "\n";
	cout << "\tTask title : " << title << endl;
	cout << "\tTask owner : " << owner << endl;
	cout << "\tTask deadline : " << deadLine.toString() << endl << endl;
}
void Task::goto_task_page(int tid)
{
	cout << "Task page \n";
	cout << "---------\n\n";;
	system("cls");
	
	if(tid >= uniq)
	{
		cout << "This task doesn't exist !! \n\n";
		cout << "\n\nEnter any key to return main page of tasks ...";
		getch();
		view_all_tasks();
		return ;
	}
	else
	{
		cout << "\n\nAll information of tasks : \n";
		for(int i = 0; i < totalTasks.size(); i++)
		{
			if(totalTasks[i].id == tid)
			{
				totalTasks[i].print_task_all_info();
				cout << "Do you want to set deadline ?[y/n] ";
				char op;
				cin >> op;
				if(op == 'y' || op == 'Y')
				{
					cout << "\n\nYou are setting deadline for task ...\n\n";
					Date d;
					d.get_info();
					totalTasks[i].set_deadline(d);
				} 
				
				cout << "Do you want to assign this title to someone ?[y/n]";
				cin >> op;
				if(op == 'y' || op == 'Y')
				{
					cout << "\n\nYou are assigning a task ...\n\n";
					cout << "Enter username : ";
					string us;
					cin >> us;
					totalTasks[i].assign_task_to(us);
				}
				else
				{
					cout << "\n\nYou cancelled the assigning ...\n\n";
				}
			}
		}
	}
}
void Task::goto_task_page(string title)
{
	system("cls");
	cout << "Task page \n";
	cout << "---------\n\n";;
	bool exist = 0;
	for(int i = 0; i < totalTasks.size(); i++)
	{
		if(totalTasks[i].title == title)
		{
			exist = 1;
			break;
		}
	}
	
	if(!exist)
	{
		cout << "This task doesn't exist !! \n\n";
		cout << "\n\nEnter any key to return main page of tasks ...";
		getch();
		view_all_tasks();
		return ;
	}
	else
	{
		cout << "\n\nAll information of tasks : \n";
		for(int i = 0; i < totalTasks.size(); i++)
		{
			if(totalTasks[i].title == title)
			{
				totalTasks[i].print_task_all_info();
				cout << "Do you want to set deadline ?[y/n] ";
				char op;
				cin >> op;
				if(op == 'y' || op == 'Y')
				{
					cout << "\n\nYou are setting deadline for task ...\n\n";
					Date d;
					d.get_info();
					totalTasks[i].set_deadline(d);
				} 
				
				cout << "Do you want to assign this title to someone ?[y/n]";
				cin >> op;
				if(op == 'y' || op == 'Y')
				{
					cout << "\n\nYou are assigning a task ...\n\n";
					cout << "Enter username : ";
					string us;
					cin >> us;
					totalTasks[i].assign_task_to(us);
				}
				else
				{
					cout << "\n\nYou cancelled the assigning ...\n\n";
				}
			}
		}
	}
}
void Task::view_all_tasks()
{
	system("cls");
	cout << "View all tasks \n";
	cout << "----------------\n\n";
	for(int i = 0; i < totalTasks.size(); i++)
	{
		totalTasks[i].print_task();
	}
	
	cout << "\nSelect one of the options below : \n";
	cout << "  1.Go to task page \n";
	cout << "  2.Back to main page \n";
	cout << "  3.Back to main menu \n\n";
	
	cout << "Enter your choose : ";
	int op;
	cin >> op;
	Task task;
	User u;
	switch(op)
	{
		case 1 :
			{
				cout << '\n';
				cout << "	1.Go to task page with id \n";
				cout << "	2.Go to task page with title \n\n";
				cout << "	Your choise : ";
				int opp;
				cin >> opp;
				cout << "\n";
				switch(opp)
				{
					case 1 :
					{
						cout << "	Enter task id : ";
						int tid ;
						cin >> tid;
						task.goto_task_page(tid);
					 } break;
					 
					case 2 :
					{
						string t ;
						cout << "	Enter task title : ";
						getline(cin, t);
						getline(cin, t);
						task.goto_task_page(t);
					 } break;
					 
					 default: cout << "wrong option !!";
				}
			} break;
			
		case 2 :{u.goto_main_page();}break;
		case 3: mainMenu(); break;
		default : cout << "\n\nWrong option. !! ";
		
	}

	cout << "\n\nEnter any key to Return to main page menu ...";
	getch();
	u.goto_main_page();
}
void Task::add_task()
{
	system("cls");
	cout << "Add task \n";
	cout << "--------\n\n";
	
	cout << "Enter title : ";
	string title;
	getline(cin, title);
	getline(cin, title);
	Task task(title);
	totalTasks.push_back(task);
	cout << "The task has been created successfully ...\n\n";
}
void Task::view_tasks_of(string userName)
{
	system("cls");
	cout << "View all tasks of user \n";
	cout << "-----------------------\n\n";
	cout <<"Username : " << userName << endl << endl;
	bool find = false;
	for(int i = 0; i < totalTasks.size(); i++)
	{
		if(totalTasks[i].owner == userName)
		{
			find = true;
			totalTasks[i].print_task();
		}
		
	}
	if(!find)
	{
		cout << "\n\nThere is no task !!" << endl << endl;
	}
	cout << "\n\nEnter any key to Return to main page menu ...";
	getch();
	User u;
	u.goto_main_page();
}



int main()
{
	mainMenu();
}

void mainMenu(){
	system("cls");
	cout << "\n" << string(30, ' ') << " * Welcome to our \"task management system\" dear user * " << "\n\n";
	
	cout << "Select one of the options below :" << endl;
	cout << "\t 1.Sign up" << endl;
	cout << "\t 2.Login" << endl;
	cout << "\t 3.Exit" << endl << endl;
	cout << "Enter your choose : ";
	int op;
	cin >> op;
	
	User usr;
	switch(op)
	{
		case 1 : usr.signUp(); break;
		case 2 : usr.login(); break;
		case 3 : exit(0);
		default : cout << "Wrong input !! "; back_main(); 
	}
}

void back_main()
{
	cout << "\n\n" << "Press any key to back main menu ... ";
	getch();
	system("cls");
	mainMenu();
}


bool is_username_repeatitive(string u)
{
	for(int i = 0; i < totalUsers.size(); i++)
		if(totalUsers[i].userName == u)
			return true;
	
	return false;
}

bool is_username_exist(string u , string &pass)
{
	for(int i = 0; i < totalUsers.size(); i++)
	{
		if(totalUsers[i].userName == u){
			pass = totalUsers[i].password;
			return true;
		}
	}
		
	return false;
}
void show_all_tasks()
{
	for(int i = 0; i < totalTasks.size(); i++)
	{
		totalTasks[i].print_task_all_info();
	}
	cout << endl << endl;
}

void show_all_users(){
	for(int i = 0; i < totalUsers.size(); i++)
	{
		totalUsers[i].show_info();
	}
	cout << endl << endl;
}
