// Author : Majid Sepasi
#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int>ids,sIds;
// ############################################################ Commander ###############################################################
class Commander
{
	private:
	string name , nick_name, id;
	public :
		Commander(){};
		
		Commander (string name, string nick_name, string id)
		{
			string idd = id;
			if(idd.size()  > 10)
				idd = idd.substr(0,10);
			if(idd.size() < 10)
				idd = string(10 - idd.size(), '0') + idd;		
			if(ids.count(idd))
			{
				cout << "This id is already exist !!\n";
				return;
			}
			set_name(name);
			set_nick_name(nick_name);
			this->id = idd;
			ids[idd] = 1;
		}
		
		string get_name()
		{
			return this->name;
		}
		void set_name(string name)
		{
			this->name = name;
		}
		
		string get_nick_name()
		{
			return this->nick_name;
		}
		void set_nick_name(string nick_name)
		{
			this->nick_name = nick_name;
		}
		
		string get_id()
		{
			return this->id;
		}
		
		void print()
		{
			cout << name << " " << nick_name << " " << id << "\n";
		}
};

// ######################################################################### Date ##############################################################

class Date
{
	private :
		int year,month,  day;
		
	public:
		Date(){};
		
		Date(int y, int m , int d)
		{
			set_year(y);
			set_month(m);
			set_day(d);
		}
		
		int get_year()
		{
			return year;
		}
		void set_year(int y)
		{
			this->year = y;
		}
		
		int get_month()
		{
			return month;
		}
		void set_month(int m)
		{
			month = min(12,max(1, m));
		}
		
		int get_day()
		{
			return day;
		}
		void set_day(int d)
		{
			if(this->month <= 6)
				day = min(31,max(1, d));
			else
				day = min(30,max(1, d));
		}
		
		
		string toString()
		{
			string Y, M, D;
			Y = to_string(get_year());
			M = (get_month() < 10 ? "0" + to_string(get_month()) : to_string(get_month()));
			D =  (get_day() < 10 ? "0" + to_string(get_day()) : to_string(get_day()));
			return Y + "/" + M + "/" + D;
		}
		
		
		bool isBefore(Date date)
		{
			return this->toString() < date.toString();
		}
		
		bool isBeforeOrSame(Date date)
		{
			return this->toString() <= date.toString();
		}
		bool isAfter(Date date)
		{
			return this->toString() > date.toString();
		}
		bool isAfterOrSame(Date date)
		{
			return this->toString() >= date.toString();
		}
		
};

// ############################################################## Soldier ################################################################

class Soldier 
{
	private:
		string name, nick_name, id , type;
		Date birthday;
	public:
		Soldier(){};
		Soldier(string name, string nick_name, string id,Date birthday, string type)
		{
			string idd = (id.size() > 9 ? id.substr(0,9) : id.size() == 9 ? id : string(9-id.size(), '0') + id);
			if(sIds.count(idd))
			{
				cout << "This Id is already exist !!\n";
				return;
			}
			sIds[idd] = 1;
			set_name(name);
			set_nick_name(nick_name);
			this->id = idd;
			set_birthday(birthday);
			set_type(type);
		}
		
		Soldier(string name, string nick_name,Date birthday, string type)
		{
			string id, idd;
			while(1)
			{
				int rnd = rand() % 10000 + 1;
				id = to_string(rnd);
				idd = (id.size() > 9 ? id.substr(0,9) : id.size() == 9 ? id : string(9-id.size(), '0') + id);
				if(!sIds.count(idd))
					break;
			}
			this->id = idd;
			sIds[idd] = 1;
			set_name(name);
			set_nick_name(nick_name);
			set_birthday(birthday);
			set_type(type);
		}
		
		string get_name()
		{
			return this->name;
		}
		void set_name(string name)
		{
			this->name = name;
		}
		
		string get_nick_name()
		{
			return this->nick_name;
		}
		void set_nick_name(string nick_name)
		{
			this->nick_name = nick_name;
		}
		
		string get_id()
		{
			return this->id;
		}
		
		
		Date get_birthday()
		{
			return this->birthday;
		}
		Date set_birthday(Date birthday)
		{
			this->birthday = birthday;
		}
		
		
		string get_type()
		{
			return this->type;
		}
		
		void set_type(string type)
		{
			this->type = type;
		}
		
		int get_age(Date x)
		{
			return x.get_year() - this->birthday.get_year();
		}
		
		
		bool Equals(Soldier s)
		{
			return this->get_name() == s.get_name() && this->get_nick_name() == s.get_nick_name() &&
					this->get_birthday().toString() == s.get_birthday().toString() && this->get_type() == s.get_type();
		}
		
		string toString()
		{
			return "[  Soldier :\t" + this->get_name() + "\t" + this->get_nick_name() + "\t" +this->get_birthday().toString() + "\t" + this->get_id() + "\t" + this->type + "  ]";
		}
};

// ################################################################### WAR BASE ###################################################################

class base
{
	private:
		int sol_count = 0;
		Commander commander;
		int capacity;
		Soldier * soldiers = new Soldier[1000];
		int id;
		string name;
		Date res_date;
		static int id_count;
		
	public:
		base(){};
		
		base(string name, int capacity, Date res_date)
		{
			id_count ++;
			if(id_count > 7)
			{
				cout << "The number of war bases if full !!\n";
				return;
			}
			this->id = id_count;
			set_name(name);
			set_capacity(capacity);
			set_res_date(res_date);
		}
		
		base(string name, int capacity)
		{
			set_res_date(Date(9999,9999,9999));
			id_count ++;
			if(id_count > 7)
			{
				cout << "The number of war bases if full !!\n";
				return;
			}
			this->id = id_count;
			set_name(name);
			set_capacity(capacity);
		}
		
		base(string name)
		{
			set_res_date(Date(9999,9999,9999));
			id_count ++;
			if(id_count > 7)
			{
				cout << "The number of war bases if full !!\n";
				return;
			}
			this->id = id_count;
			this->name = name;
			this->capacity = 25;
		}
		
		string get_name()
		{
			return this->name;
		}
		void set_name(string name)
		{
			this->name = name;
		}
		
		int get_capacity()
		{
			return this->capacity;
		}
		void set_capacity(int capacity)
		{
			this->capacity = capacity;
		}
		
		void set_res_date(Date res_date)
		{
			this->res_date = res_date;
		}
		Date get_res_date()
		{
			return this->res_date;
		}
		
		
		Commander get_commander()
		{
			return this->commander;
		}
		void set_commander(Commander c)
		{
			this->commander = c;
		}
		
		
		int get_sol_count()
		{
			return this->sol_count;
		}
		
		bool register_soldier(Soldier s)
		{
			
			if(s.get_birthday().isAfter(this->res_date) || registered(s) || this->sol_count == capacity)
				return false;
			soldiers[this->sol_count++] = s;
			return true;
		}
		
		bool registered(Soldier s)
		{
			for(int i = 0 ; i < this->sol_count; i++)
				if(soldiers[i].get_id()== s.get_id())
					return true;
			return false;	
		}
		
		bool increase_capacity(int x)
		{
			set_capacity(this->get_capacity() + x);
		}
		
		Soldier *get_SoldireList()
		{
			Soldier *list = new Soldier[this->sol_count];
			for(int i = 0 ; i < this->sol_count; i++)
				list[i] = soldiers[i];
			
			return list;
		}
		
		
		string toString()
		{
			return "[ base :\t" + this->get_name() + "\t" + to_string(this->get_capacity()) +
					 "\t" + this->get_commander().get_name() + "\t" + this->get_res_date().toString() + "\t" + to_string(this->get_sol_count()) + "  ]"; 
		}
	
};
int base :: id_count = 0;


// ################################################################### Winner ###################################################

class War_winner
{
	private:
		string emperor;
		string country_name;
		base *country_bases = new base[7];
		int bases_count ;
		int soldiers_count;
		float sol_level;
	public:
		War_winner(){};
		
		War_winner(string em, string cn,float sl)
		{
			bases_count = 0;
			soldiers_count = 0;
			set_emperor(em);
			set_country_name(cn);
			set_sol_level(sl);
		}
		
		float get_sol_level()
		{
			return this->sol_level;
		}
		void set_sol_level(float l)
		{
			this->sol_level = (l < 0 ? 0.1 : l >=1 ? 0.9 : l);
		}
		string get_emperor()
		{
			return this->emperor;
		}
		void set_emperor(string emperor)
		{
			this->emperor = emperor;
		}
		
		string get_country_name()
		{
			return this->country_name;
		}
		void set_country_name(string cn)
		{
			this->country_name = cn;
		}
		
		int get_soldires_count()
		{
			int c = 0;
			for(int i = 0 ; i < bases_count; i++)
				c += country_bases[i].get_sol_count();
			return c;
		}
		
		int get_bases_count()
		{
			return this->bases_count;
		}
		
		void add_base(base b)
		{
			country_bases[bases_count ++] = b;	
		}
		
		void get_country_info()
		{
			cout << "Country name :\t\t" << this->get_country_name() << "\n";
			cout << "Emperor name :\t\t" <<this->get_emperor() << "\n";
			cout << "Bases count :\t\t" << this->get_bases_count() << "\n";
			cout << "Soldiers count :\t" << this->get_soldires_count() << "\n"; 
			cout << "Soldiers level :\t" << this->get_sol_level() << "\n";
			cout << "Total power = " << this->get_soldires_count() << " * " << this->get_sol_level() << " = " << this->get_soldires_count() * this->get_sol_level()  <<"\n";
		}
		
		void get_Winner(War_winner other)
		{
			double f, s;
			f = this->get_soldires_count() * this->sol_level;
			s = other.get_soldires_count() * other.sol_level;
			
			if(s == f)
				cout << this->get_country_name() << " And" << other.get_country_name() <<" have equal power !!\n";
			else if(s > f)
				cout << other.get_country_name() <<  " is winner of war !!\n";
			else
				cout << this->get_country_name() <<  " is winner of war !!\n";
		}	
};
int main()
{
	Soldier s1("majid", "mac gregor", Date(1377,11,19), "Warrior");
	Soldier s2("hosein", "batista ", "1234", Date(1379,4,13), "Archer");
	Soldier s3("mahmood", "khabibbbb", "4444231214444434232", Date(1378,1,3), "Sworder");
	Soldier s4("hashem", "wild cat", Date(1375,7,29), "Warrior");
	Soldier s5("yahya", "wild lion", Date(1376,12,30), "Warrior");
	Soldier s6("saeed", "wild eagle", Date(1374,3,14), "Warrior");
	Soldier s7("ehsan", "wild chicken", Date(1374,1,15), "Warrior");
	Soldier s8("ali", "lovely eagle", Date(1377,11,19), "Warrior");
	Soldier s9("ghasem", "lovely lion", Date(1377,11,19), "Warrior");
	Soldier s10("mahdi", "lovely cat", Date(1377,11,19), "Warrior");
	
	Commander c1 ("Mehrdad","wolf","99");
	Commander C2 ("Sajad","flower","39");
	
	base b1("killers",1,Date(1380,1,1));
	base b2("wilds",20);
	base b3("tigers");
	base b4("cats",5);

	b1.set_commander(c1);
	b2.set_commander(C2);
	
	b1.register_soldier(s1);
	b1.increase_capacity(1);
	b1.register_soldier(s2);
	
	b2.register_soldier(s3);
	b2.register_soldier(s4);
	b2.register_soldier(s5);
	b2.register_soldier(s6);
	
	b3.register_soldier(s7);
	b3.register_soldier(s8);

	b4.register_soldier(s9);
	b4.register_soldier(s10);
	
	cout << b1.toString() << "\n Soldiers list :\n";
	Soldier *list =  b1.get_SoldireList();
	for(int i = 0 ; i < b1.get_sol_count(); i++)
		cout << "  " << list[i].toString() << "\n";
	cout << "\n\n";
	
	cout << b2.toString() << "\n Soldiers list :\n";
	Soldier *list2 =  b2.get_SoldireList();
	for(int i = 0 ; i < b2.get_sol_count(); i++)
		cout << "  " << list2[i].toString() << "\n";
	cout << "\n\n";
	
	
	cout << b3.toString() << "\n Soldiers list :\n";
	Soldier *list3 =  b3.get_SoldireList();
	for(int i = 0 ; i < b3.get_sol_count(); i++)
		cout << "  " << list3[i].toString() << "\n";
	cout << "\n\n";
	
	cout << b4.toString() << "\n Soldiers list :\n";
	Soldier *list4 =  b4.get_SoldireList();
	for(int i = 0 ; i < b4.get_sol_count(); i++)
		cout << "  " << list4[i].toString() << "\n";
	cout << "\n\n";
	
	
	War_winner w1("boyka", "america",0.5);
	War_winner w2("Ip man", "china", 0.9);
	
	w1.add_base(b1);
	w1.add_base(b3);
	w1.add_base(b4);
	w2.add_base(b2);
	
	w1.get_country_info();
	cout << "\n";
	w2.get_country_info();
	cout<< "\n";
	
	w1.get_Winner(w2);
	
}
