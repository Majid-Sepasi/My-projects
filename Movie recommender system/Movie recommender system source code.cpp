// Author : Majid Sepasi
#include<bits/stdc++.h>
#include<windows.h>

using namespace std;
void DisplayAllMovies(void);
void DisplayRatingOfAnUser(void);
void DisplaySimilarityBetweenTwoUser(void);
void GenerateRecommendation(void);
void RatingToMovie(void);
int RateOfAnUser(int,int);
void AddRemoveMoviePage(void);
void AddMoviePage(void);
void RemoveMoviePage(void);
bool SearchMovie(int);
bool SearchMovie(string s);
void DeleteByName(void);
void DeleteByID(void);
void RetrunToPreviousPage(void);
void ReturnBack(void);
void ReturnBackPage(void);
void ReturnToPrevious(void);
void RatingToMovie(int x,int y ,int z);
double EvaluateSimilarity(int x,int y);
vector<vector<string>>movies;
vector<vector<int>>rates;

void ShowMainMenu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	system("cls");
	cout<<"\n"<<setw(65)<<"MOVIE RECOMMENDATION SYSTEM \n\n";
	cout<<setw(38);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<"********* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"WELCOME TO MAIN MENU ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<"********* \n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\t 1. Display movies"<<endl;
	cout<<"\t 2. Display ratings"<<endl;
	cout<<"\t 3. Display similary between two users"<<endl;
	cout<<"\t 4. Generate recommendation"<<endl;
	cout<<"\t 5. Rate a movie"<<endl;
	cout<<"\t 6. Add/Remove a movie"<<endl;
	cout<<"\t 7. Exit"<<endl<<endl;
	cout<<"\t Enter your choise: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	int option;
	cin>>option;
	while(option<1 || option>7)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<"\t This option is invalid.Try again: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		cin>>option;
	}
	
	switch(option)
	{
		case 1: 	DisplayAllMovies();			break;
		case 2: 	DisplayRatingOfAnUser();			break;	
		case 3: 	DisplaySimilarityBetweenTwoUser();		break;	
		case 4: 	GenerateRecommendation();	break;	
		case 5: 	RatingToMovie();				break;	
		case 6: 	AddRemoveMoviePage();			break;
		case 7: 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	exit(0);			break;		
	}
}

void DisplayAllMovies()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<" ---------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n Display movies \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<" ---------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n\n\t Movie id \t Movie name \t\t\t\t\t\t    Year";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<"\n \t---------- \t------------ \t\t\t\t\t\t   ------\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	for(auto x:movies)
	{
		int cnt=0;
		for(auto y:x)
		{
			if(cnt==0)	cout<<"\t    ";
			cout<<y;
			if(cnt==0)	cout<<"\t\t";
			if(cnt==1)	cout<<string(60-y.size(),' ');
			cnt++;
		}
		cout<<"\n";
	}
	cout<<string(3,'\n')<<string(12,' ')<<"Press 'm' to Main menu, and 'q' to Quit : ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	string op;
	cin>>op;
	while(op!="m" && op!="q")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<string(12,' ')<<"Wrong option. Try again : ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		cin>>op;
	}
	switch(op[0])
	{
		case 'm' : ShowMainMenu();				break;
		case 'q' : SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	exit(0);	break;
	}
}

void DisplayRatingOfAnUser()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<" ----------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n Display Ratings \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<" ----------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n\n Enter user id: ";
	int id;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	cin>>id;
	while(id<1 or id>50)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<" This user id does not exist.Try again: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		cin>>id;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n\n Ratings for user "<<id<<" are:\n\n";
	cout<<" Movie id \t Rating \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<" --------\t ------ \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	for(int i=0;i<rates.size();i++)
	{
		if(rates[i][0]==id)
			cout<<" "<<rates[i][1]<<"\t\t   "<<rates[i][2]<<"\n";
	}
	cout<<"\n\n Press 'r' to Retry,'m' to Main menu,and 'q' to Quit: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	string op;
	cin>>op;
	while(op!="m" && op!="q" && op!="r")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<string(12,' ')<<"Wrong option.Try again : ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		cin>>op;
	}
	switch(op[0])
	{
		case 'm' : ShowMainMenu();				break;
		case 'r' : DisplayRatingOfAnUser();	break;
		case 'q' : SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	exit(0);	break;
	}
}

void DisplaySimilarityBetweenTwoUser()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<" ------------------------------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n Display Similarity between two users \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<" ------------------------------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
	int first,second;
	cout<<"\n\n Enter first user id: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	cin>>first;
	while(first<1 || first>50)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<" This user id does not exist.Try again: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		cin>>first;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n\n Enter second user id: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	cin>>second;
	while(second<1 || second>50)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<" This user id does not exist.Try again: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		cin>>second;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n\n Similarity between user "<<first<<" and user "<<second<<" is: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<EvaluateSimilarity(first,second);
	cout<<"\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	ReturnToPrevious();
}


void GenerateRecommendation()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);	
	cout<<" ------------------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n Generate recommendations \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<" ------------------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n\n Enter user id: ";
	int id;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	cin>>id;
	while(id<1 or id>50)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<" This user id does not exist.Try again: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		cin>>id;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	set<int>rated;
	vector<int>not_rated;
	ifstream i;
	i.open("Ratings.txt");
	int Id,movie_id;
	set<pair<double,int>>s;
	for(int i=0;i<rates.size();i++)
	{
		if(rates[i][0]==id)
			rated.insert(rates[i][1]);
	}
	for(int i=1;i<=movies.size();i++)
	{
		if(find(rated.begin(),rated.end(),i)==rated.end())
			not_rated.push_back(i);
	}
	
	int rate;
	while(i>>Id)
	{
		i>>movie_id>>rate;
		if(id!=Id)
			s.insert({EvaluateSimilarity(id,Id),Id});
	}
	i.close();
	vector<pair<double,int>>sim(s.rbegin(),s.rend());

	map<int,string>predict;
	const int n=3;
	double score=0;
	for(int k=0;k<not_rated.size();k++)
	{
		bool find=0;
		double dec=0,up=0;
		for(int i=0;i<n;i++)
		{	
			if(RateOfAnUser(sim[i].second,not_rated[k])!=0)
			{
				find=1;
				dec+=sim[i].first;
				up+=RateOfAnUser(sim[i].second,not_rated[k])*sim[i].first;
			}		
		}
		predict[not_rated[k]]=(!find ? "Not predictalbe" :to_string(up/dec));
	}
	vector<pair<string,int>>predictt,tmp;
	for(auto x:predict)
		predictt.push_back({x.second,x.first});
	
	tmp=predictt;
	sort(predictt.rbegin(),predictt.rend());
	cout<<"\n Top "<<n<<" recommendation for user"<<id<<" are:\n\n";
	cout<<" Movie id\t"<<" Movie name\t\t\t\t\t"<<" Year\t"<<" Predicted rating\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);	
	cout<<" --------\t"<<" ----------\t\t\t\t\t"<<" ----\t"<<" ----------------"<<"\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<movies.size();k++)
		{
			if(stoi(movies[k][0])==predictt[i].second)
			{
				cout<<" "<<movies[k][0]<<"\t\t "<<movies[k][1]<<string(48-movies[k][1].size(),' ')<<movies[k][2]<<string(10,' ')<<predictt[i].first<<"\n";
				break;
			}
		}
	}
	while(true)
	{
			cout<<"\n\n ===What do you want to do?====";
			cout<<"\n a. Display all predictions for this user";
			cout<<"\n b. Retry";
			cout<<"\n c. Retrun to main menu";
			cout<<"\n d. Exit";
			cout<<"\n\n Your choise: ";
			string op;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
			cin>>op;
			while(op!="a" && op!="b" && op!="c" && op!="d")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				cout<<" Wrong option.Try again : ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
				cin>>op;
			}
			switch(op[0])
			{
				case 'b' :  GenerateRecommendation();			break;
				case 'c' :  ShowMainMenu();								break;
				case 'd' :  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	exit(0);					break;
				case 'a' :
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						cout<<"\n\n Predictions of unseen movies by user "<<id<<":\n\n";
						cout<<" Movie id\t"<<" Predicted rating\n";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
						cout<<" --------\t"<<" ----------------\n\n";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
						for(int i=0;i<tmp.size();i++)
						{
							for(int k=0;k<movies.size();k++)
							{
								if(stoi(movies[k][0])==tmp[i].second)
								{
									cout<<" "<<movies[k][0]<<"\t\t    "<<tmp[i].first<<"\n";
									break;
								}
							}
						}
					}
			}
		}
	
}

void RatingToMovie()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	system("cls");
	cout<<" ------------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n Rate a movie \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<" ------------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n\n Enter the Information Below ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<"\n = = = = = = = = = = = = = = \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	int id,movie_id,rate;
	cout<<" User ID:\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	cin>>id;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<" Movie ID:\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	cin>>movie_id;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<" Rating(1-5):\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	cin>>rate;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<"\n = = = = = = = = = = = = = = \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n\n Do you want to save(Y/N)? ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	string op;
	cin>>op;
	while(op!="Y" && op!="N")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<" Wrong option.Try again : ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		cin>>op;
	}
	switch(op[0])
	{
		case 'N' :	RetrunToPreviousPage();	break;
		case 'Y':
		{
			if(id<1 || id>50)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				cout<<"\n This user id does not exist.";
				RetrunToPreviousPage();
			}
			if(!SearchMovie(movie_id))
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				cout<<"\n This movie id does not exist.";
				RetrunToPreviousPage();
			}
			if(rate<0 || rate>5)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				cout<<"\n This rating is not valid.(only between 1 to 5)";
				RetrunToPreviousPage();	
			}
			RatingToMovie(id,movie_id,rate);
			RetrunToPreviousPage();
			break;
		}
	}
}

void AddRemoveMoviePage()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	system("cls");
	cout<<" --------------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n Add/Remove a movie \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<" --------------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n\n = = = =What do you want to do?= = = = \n";
	cout<<"\n a.Add a new movie";
	cout<<"\n b.Remove a movie";
	cout<<"\n c.Retrun to main menu";
	cout<<"\n d.Exit";
	cout<<"\n\n Your choise? ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	string op;
	cin>>op;
	while(op!="a" && op!="b" && op!="c" && op!="d")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<" Wrong option.Try again : ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		cin>>op;
	}
	switch(op[0])
	{
		case 'a' : AddMoviePage();		break;
		case 'b' : RemoveMoviePage();	break;
		case 'c' : ShowMainMenu();			break;
		case 'd' : SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	exit(0);
	}
}

void RatingToMovie(int Id,int movie_id,int Rate)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	bool find=0;
	for(int i=0;i<rates.size();i++)
	{
		if(rates[i][0]==Id && rates[i][1]==movie_id)
		{
			rates[i][2]=Rate;
			find=true;
		}
	}
	if(!find)
	{
		rates.push_back({Id,movie_id,Rate});
		sort(rates.begin(),rates.end());
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	cout<<"\n The record was successfully saved.";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}

void AddMoviePage()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	system("cls");
	cout<<" ------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n Add a movie \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<" ------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n\n Enter the Information Below \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<" = = = = = = = = = = = = = = ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n Name:\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	string name;
	getline(cin,name);
	getline(cin,name);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<" Year:\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	int year;
	cin>>year;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<"\n = = = = = = = = = = = = = = ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n\n Do you want to save(Y/N)";
	string op;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	cin>>op;
	while(op!="Y" && op!="N")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<" Wrong option.Try again : ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		cin>>op;
	}
	switch(op[0])
	{
		case 'N' : ReturnBack();
		case 'Y' :
			{
				if(SearchMovie(name))
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
					cout<<"\n\n This movie already exists.";
					ReturnBack();
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
				cout<<"\n\n The record was successfully saved.";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				movies.push_back({to_string(stoi(movies[movies.size()-1][0])+1),name,to_string(year)});
				ReturnBack();
			}
	}	
}

void RemoveMoviePage()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	system("cls");
	cout<<" ------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n Remove a movie \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<" ------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n\n = = = = Remove by name or ID?= = = =";
	cout<<"\n a.By name";
	cout<<"\n b.By ID";
	cout<<"\n\n Your choise: ";
	string op;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	cin>>op;
	while(op!="a" && op!="b")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<" Wrong option.Try again : ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		cin>>op;
	}
	switch(op[0])
	{
		case 'a' : 	DeleteByName();			break;
		case 'b' :  DeleteByID();			break;
	}
}

void DeleteByName()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n\n Enter the name of movie:";
	string name;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	getline(cin,name);
	getline(cin,name);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n Are you sure you want to delete \""<<name<<"\"(Y/N)? ";
	string op;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	cin>>op;
	while(op!="Y" && op!="N")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<" Wrong option.Try again : ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		cin>>op;
	}
	switch(op[0])
	{
		case 'N': ReturnBackPage();	break;
		case 'Y':
		{
				if(!SearchMovie(name))
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
					cout<<"\n\n This movie does not exist.";
					ReturnBackPage();
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				int ID;
				vector<vector<string>>tmp;
				for(int i=0;i<movies.size();i++)
				{
					if(movies[i][1]!=name)
						tmp.push_back({movies[i][0],movies[i][1],movies[i][2]});
					else
						ID=stoi(movies[i][0]);
						
				}
				movies=tmp;
				tmp.clear();
				vector<vector<int>>tmp2;
				for(int i=0;i<rates.size();i++)
				{
					if(rates[i][1]!=ID)
						tmp2.push_back({rates[i][0],rates[i][1],rates[i][2]});
				}
				rates=tmp2;
				tmp2.clear();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
				cout<<"\n\n The record was successfully removed.";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				ReturnBackPage();
				break;
		}
	}
}

void DeleteByID()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n\n Enter Movie ID: ";
	int id;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	cin>>id;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n Are you sure you want to delete  \"movie"<<id<<"\"(Y/N)? ";
	string op;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	cin>>op;
	while(op!="Y" && op!="N")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<" Wrong option.Try again : ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		cin>>op;
	}
	switch(op[0])
	{
		case 'N': ReturnBackPage();	break;
		case 'Y':
		{
				if(!SearchMovie(id))
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
					cout<<"\n\n This movie does not exist.";
					ReturnBackPage();
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				int ID;
				vector<vector<string>>tmp;
				for(int i=0;i<movies.size();i++)
				{
					if(stoi(movies[i][0])!=id)
						tmp.push_back({movies[i][0],movies[i][1],movies[i][2]});
					else ID=stoi(movies[i][0]);	
				}
				movies=tmp;
				tmp.clear();
				vector<vector<int>>tmp2;
				for(int i=0;i<rates.size();i++)
				{
					if(rates[i][1]!=ID)
						tmp2.push_back({rates[i][0],rates[i][1],rates[i][2]});
				}
				rates=tmp2;
				tmp2.clear();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
				cout<<"\n\n The record was successfully removed.";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				ReturnBackPage();
				break;
		}
	}
}

double EvaluateSimilarity(int id1,int id2)
{ 
	int sum1=0;
	int sum2=0;
	double sum_common=0;
	map<int,int>f;
	bool find=0;
	for(int i=0;i<rates.size();i++)
	{
		if(rates[i][0]==id1)
			f[rates[i][1]]=rates[i][2];
	}
	for(int i=0;i<rates.size();i++)
	{
		if(rates[i][0]==id2)
		{
			if(f.count(rates[i][1]))
			{
				find=1;
				sum1+=pow(f[rates[i][1]],2);
				sum2+=pow(rates[i][2],2);
				sum_common+=f[rates[i][1]]*rates[i][2];
			}
		}
	}
	double Denominator=sqrt(sum1)*sqrt(sum2);
	return (find ?  double(sum_common)/(Denominator) : 0);
}

int RateOfAnUser(int user_id,int movie_id)
{
	ifstream i;
	i.open("Ratings.txt");
	int id,m_id,rate;
	while(i>>id)
	{
		i>>m_id>>rate;
		if(id==user_id && movie_id==m_id)
		{
			i.close();
			return rate;
		}
	}
	i.close();
	return 0;
}

bool SearchMovie(int movie_id)
{
	for(int i=0;i<movies.size();i++)
	{
		if(movies[i][0]==to_string(movie_id))
			return true;
	}
	return false;
}
bool SearchMovie(string movie_name)
{
	for(int i=0;i<movies.size();i++)
	{
		if(movies[i][1]==movie_name)
			return true;
	}
	return false;
}
void RetrunToPreviousPage()
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		cout<<"\n\n Press 'r' to Retry,'m' to Main menu,and 'q' to Quit: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		string op;
		cin>>op;
		while(op!="m" && op!="q" && op!="r")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			cout<<" Wrong option.Try again : ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
			cin>>op;
		}
		switch(op[0])
		{
			case 'm' : ShowMainMenu();				break;
			case 'r' : RatingToMovie();		break;
			case 'q' : SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	exit(0);	break;
		}
}

void ReturnBack()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n\n Press 'r' to Retry,'p' to Previous,'m' to Main menu,and 'q' to Quit: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	string op;
	cin>>op;
	while(op!="m" && op!="q" && op!="r" && op!="p")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<" Wrong option.Try again : ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		cin>>op;
	}
	switch(op[0])
	{
		case 'm' : ShowMainMenu();				break;
		case 'r' : AddMoviePage();			break;
		case 'q' : SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	exit(0);	break;
		case 'p' : AddRemoveMoviePage();	break;
	}
}
void ReturnBackPage()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<"\n\n Press 'r' to Retry,'p' to Previous,'m' to Main menu,and 'q' to Quit: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	string op;
	cin>>op;
	while(op!="m" && op!="q" && op!="r" && op!="p")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<" Wrong option.Try again : ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		cin>>op;
	}
	switch(op[0])
	{
		case 'm' : ShowMainMenu();				break;
		case 'r' : RemoveMoviePage();		break;
		case 'q' : SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	exit(0);	break;
		case 'p' : AddRemoveMoviePage();	break;
	}
}

void ReturnToPrevious()
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		cout<<"\n\n Press 'r' to Retry,'m' to Main menu,and 'q' to Quit: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		string op;
		cin>>op;
		while(op!="m" && op!="q" && op!="r")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			cout<<" Wrong option.Try again : ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
			cin>>op;
		}
		switch(op[0])
		{
			case 'm' : ShowMainMenu();						break;
			case 'r' : DisplaySimilarityBetweenTwoUser();		break;
			case 'q' : SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	exit(0);			break;
		}
}

int main(void)
{
	string l;
	ifstream fr("Movies.txt");
	while(getline(fr,l))
	{
		int backSlashT=1;
		int lt=0;
		int f;
		vector<string>tmp;
		while(backSlashT<=3)
		{
			f=l.find("\t",lt);
			tmp.push_back(l.substr(lt,f-lt));
			lt=f+1;
			backSlashT++;
		}
		movies.push_back(tmp);
		tmp.clear();
	}
	fr.close();
	
	ifstream read("Ratings.txt");
	while(!read.eof())
	{
		int x;
		vector<int>a;
		for(int k=1;k<=3;k++)
		{
			read>>x;
			a.emplace_back(x);
		}
		rates.emplace_back(a);
	}
	read.close();
	ShowMainMenu();	
}


