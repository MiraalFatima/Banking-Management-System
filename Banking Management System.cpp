#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
#include <conio.h>
#include<sstream>
#include<ctime>
#include<time.h>
#include<conio.h>
#include <iomanip>
#include<windows.h>
using namespace std;
//class prototyping
class userclient;
class companyclient;
class bankingclient;
void display();
void accountnumber();
class userclient
{
	string name, address, phone, cnic, password, login, accountno;
	long int limit = 0;
	long int accbalance = 0;
	userclient* array;
public:

	userclient()
	{
		//string name = "";
		string address = "";
		string phone = "";
		string cnic = "";
		//string password = "";
		string login = "";
		long int limit = 0;
		array = nullptr;
	}
	void userclient_menu(string idfile1);
	void deposit(string idfile1);
	void setname(string n)
	{
		this->name = n;
	}
	void setaddress(string a)
	{
		this->address = a;
	}
	void setphone(string p)
	{
		this->phone = p;
	}
	void setcnic(string c)
	{
		this->cnic = c;
	}
	void setpassword(string pw)
	{
		this->password = pw;
	}
	void setlogin(string l) //log in is being used as user id down !! yaad rakhna miraal
	{
		this->login = l;
	}
	void setlimit(int lim)
	{
		this->limit = lim;
	}
	void setbalance(long int b)
	{
		this->accbalance += b;
	}
	void setaccountno(string code)
	{
		srand(time(0));
		for (int i = 0; i < 16; i++)
		{
			int digit = rand() % 10;
			code += to_string(digit);
			this->accountno = code;
		}
		cout << code << endl;
	}
	//getters
	long int getbalance(long int balance)
	{
		return balance;
	}
	string getname()
	{
		return name;
	}
	long int getbalance()
	{
		return accbalance;
	}
	string getname(string name)
	{
		return name;
	}
	string getaddress()
	{
		return address;
	}
	string getphone()
	{
		return phone;
	}
	string getcnic()
	{
		return cnic;
	}
	string getpassword()
	{
		return password;
	}
	string getlogin()
	{
		return login;
	}
	int getlimit()
	{
		return limit;
	}
	string getaccountno()
	{
		return accountno;
	}
	bool acclogin(string idfile1, string name, string password)
	{
		string username_ = name;
		string password_ = password;
		bool check = false;
		string line;
		int count = 0;
		string b, l;
		ifstream file;
		file.open(idfile1);
		if (file.is_open())
		{
			while (getline(file, line, '\n'))
			{
				count++;
			}
			file.close();
			file.open(idfile1);
			array = new userclient[count];
			for (int i = 0; i < count; i++)
			{
				getline(file, array[i].name, ',');
				getline(file, array[i].address, ',');
				getline(file, array[i].phone, ',');
				getline(file, array[i].cnic, ',');
				getline(file, array[i].login, ',');
				getline(file, array[i].password, ',');
				getline(file, l, ',');
				getline(file, b, ',');
				getline(file, array[i].accountno, '\n');
				array[i].limit = stol(l);
				array[i].accbalance = stol(b);
			}
			file.close();
			int i = 0;
			for (; i < count; i++)
			{
				if (array[i].name == username_ && array[i].password == password_)
				{

					return 1;
				}
			}
			if (username_ != array[i].name && password_ != array[i].password)
			{
				return 0;
			}

		}
	}
	void deposit(string idfile1, string name, string accno)

	{
		string beneficiaryname_ = name;
		string accountnumber = accno;
		int balance = 0;
		string b, l;
		int count = 0;
		string line = "";
		ifstream file;
		file.open(idfile1);
		if (file.is_open())
		{
			while (getline(file, line, '\n'))
			{
				count++;
			}
			file.close();
			file.open(idfile1);
			array = new userclient[count];
			for (int i = 0; i < count; i++)
			{
				getline(file, array[i].name, ',');
				getline(file, array[i].address, ',');
				getline(file, array[i].phone, ',');
				getline(file, array[i].cnic, ',');
				getline(file, array[i].login, ',');
				getline(file, array[i].password, ',');
				getline(file, l, ',');
				getline(file, b, ',');
				getline(file, array[i].accountno, '\n');
				array[i].limit = stol(l);
				array[i].accbalance = stol(b);

				//file.close();

			}
			file.close();
			int i = 0;
			for (; i < count; i++)
			{
				if (array[i].name == beneficiaryname_ && array[i].accountno == accountnumber)
				{
					string deposit = "DEPOSIT";
					string date = "";
					long int money = 0;
					cout << "ENTER THE DATE : " << endl;
					getline(cin, date);
					cout << "ENTER THE AMOUNT YOU WANT TO DEPOSIT : " << endl;
					cin >> money;
					setbalance(money);
					array[i].accbalance += (money);
					cout << "AMOUNT ADDED SUCCESSFULLY" << endl;
					string w2;
					ofstream file1;
					file1.open("user.txt");
					if (file1.is_open())
					{
						for (int i = 0; i < count; i++)
						{
							w2 = to_string(array[i].accbalance);
							file1 << array[i].name << "," << array[i].address << "," << array[i].phone << "," << array[i].login << "," << array[i].password << "," << array[i].limit << "," << w2 << "," << array[i].accountno << endl;
							cout << endl;
						}
					}
				

					string f = "TRANSACTION HISTORY OF " + name;

					fstream filename(f + ".txt", ios::app);
					{
						while (filename.is_open());
						{
							if (filename.is_open());

							{
								filename << date << "," << getname(name) << "," << getbalance(accbalance) << "," << deposit << endl;
								cout << endl;
								filename.close();
							}
						}
					}
					ofstream file("transaction.txt", ios::app);
					{
						while (file.is_open())
						{
							if (file.is_open())
							{
								file << date << "," << getname(name) << "," << getbalance(accbalance) << "," << deposit << endl;
								cout << endl;
							}
							file.close();
						}
					}






				}
				
			}
		}

	}
	void withdraw(string idfile1, string name, string accno)
	{
		string beneficiaryname_ = name;
		string accountnumber = accno;
		int balance = 0;
		string b, l;
		int count = 0;
		string line = "";
		ifstream file;
		file.open(idfile1);
		if (file.is_open())
		{
			while (getline(file, line, '\n'))
			{
				count++;
			}
			file.close();
			file.open(idfile1);
			array = new userclient[count];
			for (int i = 0; i < count; i++)
			{
				getline(file, array[i].name, ',');
				getline(file, array[i].address, ',');
				getline(file, array[i].phone, ',');
				getline(file, array[i].cnic, ',');
				getline(file, array[i].login, ',');
				getline(file, array[i].password, ',');
				getline(file, l, ',');
				getline(file, b, ',');
				getline(file, array[i].accountno, '\n');
				array[i].limit = stol(l);
				array[i].accbalance = stol(b);

				//file.close();

			}
			file.close();
			int i = 0;
			for (; i < count; i++)
			{
				if (array[i].name == beneficiaryname_ && array[i].accountno == accountnumber)
				{
					string withdraw = "WITHDRAW";
					string date = "";
					long int money = 0;
					cout << "ENTER THE DATE : " << endl;
					getline(cin, date);
					cout << "ENTER THE AMOUNT YOU WANT TO WITHDRAW : " << endl;
					cin >> money;
					setbalance(money);
					array[i].accbalance -= (money);
					cout << "AMOUNT WITHDRAWN SUCCESSFULLY" << endl;
					string w2;
					ofstream file1;
					file1.open("user.txt");
					if (file1.is_open())
					{
						for (int i = 0; i < count; i++)
						{
							w2 = to_string(array[i].accbalance);
							{
								string f = "TRANSACTION HISTORY OF " + name;
								fstream filename(f + ".txt", ios::app);
								{
									while (filename.is_open())
									{
										if (filename.is_open())
										{
											ofstream file("transaction.txt", ios::app);
											{
												while (file.is_open())
												{
													if (file.is_open())
													{
														file << date << "," << getname(name) << "," << getbalance(accbalance) << "," << withdraw << endl;
														cout << endl;
													}
													file.close();
												}
											}
											filename << date << "," << getname(name) << "," << getbalance(accbalance) << "," << withdraw << endl;
											cout << endl;
											filename.close();
										}
									}

								}
								filename.close();
								file1 << array[i].name << "," << array[i].address << "," << array[i].phone << "," << array[i].login << "," << array[i].password << "," << array[i].limit << "," << w2 << "," << array[i].accountno << endl;
								cout << endl;
							}
						}

					}
				}
			}
			file.close();

		}
	}

};
class companyclient
{
private:
	string companyname, companyaddress, companytaxnumber, companyid, companypassword;
	long int  companylimit = 0;
	companyclient* array1;
	long int companybalance = 0;

public:

	companyclient()
	{
		string companyname = string("");
		string companyaddress = string("");
		string companytaxnumber = string("");
		string companyid = string("");
		string companypassword = string("");
		long int companylimit = 0;
		long int companybalance = 0;
		array1 = nullptr;

	}
	void companyclient_menu(string b);
	void setcompanyname(string n)
	{
		this->companyname = n;
	}
	void setcompanyaddress(string a)
	{
		this->companyaddress = a;
	}
	void setcompanytaxnumber(string t)
	{
		this->companytaxnumber = t;
	}
	void setcompanyid(string ID)
	{
		this->companyid = ID;
	}
	void setcompanypassword(string pw)
	{
		this->companypassword = pw;
	}

	void setcompanylimit(long int lim)
	{
		this->companylimit = lim;
	}
	void setcompanybalance(long int b)
	{
		this->companybalance = b;
	}
	//getters
	string getcompanyname()
	{
		return companyname;
	}
	string getcompanyaddress()
	{
		return companyaddress;
	}
	string getcompanytaxnumber()
	{
		return companytaxnumber;
	}
	string getcompanyid()
	{
		return companyid;
	}
	string getcompanypassword()
	{
		return companypassword;
	}

	long int getcompanylimit()
	{
		return companylimit;
	}
	long int getcompanybalance()
	{
		return companybalance;
	}


	bool companylogin(string idfile2, string compname, string comppassword)
	{
		string username_ = compname;
		string password_ = comppassword;
		bool check = false;
		string line;
		int count = 0;
		string companyb, companyl;
		ifstream file;
		file.open(idfile2);
		if (file.is_open())
		{
			while (getline(file, line, '\n'))
			{
				count++;
			}
			file.close();
			file.open(idfile2);
			array1 = new companyclient[count];
			for (int i = 0; i < count; i++)
			{
				getline(file, array1[i].companyname, ',');
				getline(file, array1[i].companyaddress, ',');
				getline(file, array1[i].companyid, ',');
				getline(file, array1[i].companypassword, ',');
				getline(file, array1[i].companytaxnumber, ',');
				getline(file, companyl, ',');
				getline(file, companyb, '\n');
				array1[i].companylimit = stol(companyl);
				array1[i].companybalance = stol(companyb);
			}
			file.close();
			int i = 0;
			for (; i < count; i++)
			{
				if (array1[i].companyid == username_ && array1[i].companypassword == password_)
				{
					return 1;
				}
			}
			if (username_ != array1[i].companyid && password_ != array1[i].companypassword)
			{
				return 0;
			}

		}
	}

};
class bankingclient
{

private:
	string bankingusername;
	string bankingpassword;
	bankingclient* array2;

public:
	void bankingclient_menu(string a); //prototype everyfunc in class before making it outside
	bankingclient() //default constructor
	{
		string bankingusername = string("");
		string bankingpassword = string("");
	}

	bankingclient(string username, string password) //parameterized constructor
	{
		this->bankingusername = string(username);
		this->bankingpassword = string(password);
	}


	//getters
	string getbankingusername()
	{
		return bankingusername;
	}

	string getbankingpassword()
	{
		return bankingpassword;
	}
	//setters
	void setbankingusername(string username)
	{
		(this->bankingusername) = username;
	}

	void setbankingpassword(string password)
	{
		(this->bankingpassword) = password;

	}
	bool banklogin(string idfile3, string bankingname, string bankingpassword)
	{
		string username_ = bankingname;
		string password_ = bankingpassword;
		bool check = false;
		string line;
		int count = 0;
		ifstream file;
		file.open(idfile3);
		if (file.is_open())
		{
			while (getline(file, line, '\n'))
			{
				count++;
			}
			file.close();
			file.open(idfile3);
			array2 = new bankingclient[count];
			for (int i = 0; i < count; i++)
			{
				getline(file, array2[i].bankingusername, ',');
				getline(file, array2[i].bankingpassword, '\n');

			}
			file.close();
			int i = 0;
			for (; i < count; i++)
			{
				if (array2[i].bankingusername == username_ && array2[i].bankingpassword == password_)
				{
					return 1;
				}
			}
			if (username_ != array2[i].bankingusername && password_ != array2[i].bankingpassword)
			{
				cout << "THE PASSWORD OR THE ACCOUNT NAME IS INCORRECT :(" << endl;
				return 0;
			}

		}
	}

};


void userclient::userclient_menu(string idfile1)
{
	int choice;
	choice = 0;
	system("cls");
	display();
	cout << "\t\t---DEAR CUSTOMER ENTER YOUR CHOICE--- " << endl;
	cout << "\t\t\t\t 1. CREATE ACCOUNT " << endl;
	cout << "\t\t\t\t 2. LOG-IN" << endl;
	cout << "\t\t\t\t 3. EXIT " << endl;
	cin >> (choice);
	switch (choice)
	{
	case 1:
	{
		if (choice == 1)
		{

			string name = ""; //= new string(*name);
			string address = ""; //= new string(*address);
			string phone = ""; //= new string(*phone);
			string cnic = "";//= new string(*cnic);
			string userid = ""; //= new string(*userid);
			string password = "";// = new string(*password);
			int balance = 0;//= new int(*balance);
			int limit = 0;
			string accountno = "";
			cin.ignore();
			cout << "ENTER NAME: ";
			getline(cin, name);
			setname(name);
			cout << "ENTER ADDRESS :";
			getline(cin, address);
			setaddress(address);
			cout << endl;
			cout << "ENTER PHONE: ";
			getline(cin, phone);
			setphone(phone);
			cout << endl;
			cout << "ENTER CNIC: ";
			getline(cin, cnic);
			setcnic(cnic);
			cout << endl;
			cout << "ENTER USER ID: ";
			getline(cin, userid);
			setlogin(userid);
			cout << endl;
			cout << "ENTER PASSWORD: ";
			getline(cin, password);
			setpassword(password);
			cout << endl;
			cout << "ENTER ESTIMATED WITHDRAWL LIMIT: ";
			cin >> (balance);
			setlimit(balance);
			cout << "CURRENT BALANCE :";
			cout << limit;
			cout << "ACCOUNT NO. " << endl;
			setaccountno(accountno);
			cout << endl;
			cout << "DEAR MR/MS " << name << "YOU HAVE SUCCESSFULLY CREATED A TEMPORARY ACCOUNT" << endl;
			cout << "YOU ARE REQUESTED TO WAIT FOR THE BANKING EMPLOYEE'S APPROVAL FOR PERMANENT ACCOUNT" << endl;
			fstream file("user.txt", ios::app);
			{
				while (file.is_open())
				{
					if (file.is_open())
					{
						file << getname() << "," << getaddress() << "," << getphone() << "," << getcnic() << "," << getlogin() << "," << getpassword() << "," << getlimit() << "," << getbalance() << "," << getaccountno() << endl;
						cout << endl;
					}
					file.close();
				}
			}
			break;
		}
	}
	case 2:
	{
		if (choice == 2)
		{
			string username = "";
			string password = "";

			cout << "ENTER USERNAME : " << endl;
			cin.ignore();
			getline(cin, username);
			//setname(username);
			cout << "ENTER PASSWORD :" << endl;
			getline(cin, password);
			//setpassword(password);
			bool flag = acclogin(idfile1, username, password);
			if (flag == 1)
			{
				system("cls");
				display();
				cout << "\t\t\tPLEASE CHOOSE FROM THE OPTIONS BELOW : " << endl;
				cout << "\t\t\t\t\t 1.DEPOSIT " << endl;
				cout << "\t\t\t\t\t 2.WITHDRAW " << endl;
				cout << "\t\t\t\t\t 3.VIEW BALANCE " << endl;
				cout << "\t\t\t\t\t 4.TRANSACTION HISTORY" << endl;
				cout << "\t\t\t\t\t 5.TRANSFER " << endl;
				int Choice;
				cin >> Choice;

				if (Choice == 1)
				{
					system("cls");
					display();

					string accountno = "";
					string username = "";
					int balance = 0;
					cout << "ENTER YOUR NAME : " << endl;
					cin.ignore();
					getline(cin, username);
					//setname(username);
					cout << "ENTER YOUR ACCOUNT NUMBER :" << endl;
					getline(cin, accountno);
					//setpassword(password);
					deposit(idfile1, username, accountno);
				}
				if (Choice == 2)
				{
					system("cls");
					display();
					string accountno = "";
					string username = "";
					int balance = 0;
					cout << "ENTER YOUR NAME : " << endl;
					cin.ignore();
					getline(cin, username);
					//setname(username);
					cout << "ENTER YOUR ACCOUNT NUMBER :" << endl;
					getline(cin, accountno);
					//setpassword(password);
					withdraw(idfile1, username, accountno);

				}
			}

			else if (flag == 0)
			{
				cout << "not log in";
			}
		}

	}
	}
}

void companyclient::companyclient_menu(string idfile2)
{
	int choice;
	choice = 0;
	system("cls");
	display();
	cout << "\t\t---DEAR CUSTOMER ENTER YOUR CHOICE--- " << endl;
	cout << "\t\t\t\t 1. CREATE ACCOUNT " << endl;
	cout << "\t\t\t\t 2. LOG-IN" << endl;
	cout << "\t\t\t\t 3. EXIT " << endl;
	cin >> (choice);
	switch (choice)
	{
	case 1:
	{
		if (choice == 1)
		{

			string companyname = ""; //= new string(*name);
			string companyaddress = ""; //= new string(*address);
			string copanytaxnumber = ""; //= new string(*phone);
			string companypassword = "";//= new string(*cnic);

			long int companybalance = 0;//= new int(*balance);
			long int companylimit = 0;
			cin.ignore();
			cout << "ENTER COMPANY NAME: ";
			getline(cin, companyname);
			setcompanyname(companyname);
			cout << "ENTER COMPANY ADDRESS :";
			getline(cin, companyaddress);
			setcompanyaddress(companyaddress);
			cout << endl;
			cout << "ENTER COMPANY ACCOUNT ID: ";
			getline(cin, companyid);
			setcompanyid(companyid);
			cout << endl;
			cout << "ENTER COMPANY ACCOUNT PASSWORD: ";
			getline(cin, companypassword);
			setcompanypassword(companypassword);
			cout << endl;
			cout << "ENTER COMPANY TAX NUMBER : ";
			getline(cin, companytaxnumber);
			setcompanytaxnumber(companytaxnumber);
			cout << endl;
			cout << "ENTER ESTIMATED WITHDRAWL LIMIT: ";
			cin >> (companybalance);
			setcompanylimit(companybalance);
			cout << "CURRENT COMPANY BALANCE :";
			cout << companylimit;
			cout << endl;
			cout << "DEAR MR/MS " << "YOU HAVE SUCCESSFULLY CREATED A TEMPORARY ACCOUNT FOR YOUR " << companyname << "COMPANY" << endl;
			cout << "YOU ARE REQUESTED TO WAIT FOR THE BANKING EMPLOYEE'S APPROVAL FOR PERMANENT ACCOUNT" << endl;
			fstream file("companyclientdata.txt", ios::app);
			{
				while (file.is_open())
				{
					if (file.is_open())
					{
						file << getcompanyname() << "," << getcompanyaddress() << "," << getcompanyid() << "," << getcompanypassword() << "," << getcompanytaxnumber() << "," << getcompanylimit() << "," << getcompanybalance() << ",";
						accountnumber();
						cout << endl;

					}
					file.close();
				}
			}
			break;
		}
	}
	case 2:
	{
		string usernamec = "";
		string passwordc = "";

		cout << "ENTER COMPANY ACCOUNT ID : " << endl;
		cin.ignore();
		getline(cin, usernamec);
		//setcompanyname(usernamec);
		cout << "ENTER COMPANY ACCOUNT PASSWORD :" << endl;
		getline(cin, passwordc);
		//setcompanypassword(passwordc);
		bool flag = companylogin(idfile2, usernamec, passwordc);
		if (flag == true)
		{
			system("cls");
			display();
			cout << "\t\t\tPLEASE CHOOSE FROM THE OPTIONS BELOW : " << endl;
			cout << "\t\t\t\t\t 1.DEPOSIT " << endl;
			cout << "\t\t\t\t\t 2.WITHDRAW " << endl;
			cout << "\t\t\t\t\t 3.VIEW BALANCE " << endl;
			cout << "\t\t\t\t\t 4.TRANSACTION HISTORY" << endl;
			cout << "\t\t\t\t\t 5.TRANSFER " << endl;
			cout << "\t\t\t\t\t 6. REQUEST LOAN " << endl;
			int Choice;
			cin >> Choice;

		}
		else if (flag == 0)
		{
			cout << "not log in";
		}

	}

	}
}
void bankingclient::bankingclient_menu(string idfile3)
{
	int choice;
	choice = 0;
	system("cls");
	display();
	cout << "\t\t---DEAR BANKING EMPLOYEE KINDLY ENTER YOUR CHOICE--- " << endl;
	cout << "\t\t\t\t 1. NEW EMPLOYEE ACCOUNT " << endl;
	cout << "\t\t\t\t 2. LOG-IN" << endl;
	cout << "\t\t\t\t 3. EXIT " << endl;
	cin >> (choice);
	switch (choice)
	{
	case 1:
	{
		if (choice == 1)
		{
			string usernameb = string("");
			string passwordb = string("");
			system("cls");
			display();
			cin.ignore();
			cout << "ENTER BANKING USERNAME :" << endl;
			getline(cin, usernameb);
			setbankingusername(usernameb);
			cout << endl;
			cout << "ENTER BANKING PASSWORD :" << endl;
			getline(cin, passwordb);
			setbankingpassword(passwordb);
			cout << endl;
			cout << "YOU ARE ALL SET :)" << endl;
			cout << "WE WARMLY WELCOME YOU ON BOARD TO AL-FATEMAH BANKING CORPORATION :)" << endl;

			fstream file("admindata.txt", ios::app);
			{
				while (file.is_open())
				{
					if (file.is_open())
					{
						file << getbankingusername() << "," << getbankingpassword() << endl;
					}
					file.close();
				}
			}
			break;
		}

	}
	case 2:
	{
		string username = "";
		string password = "";

		cout << "ENTER USERNAME : " << endl;
		cin.ignore();
		getline(cin, username);
		//setname(username);
		cout << "ENTER PASSWORD :" << endl;
		getline(cin, password);
		//setpassword(password);
		bool flag = banklogin(idfile3, username, password);
		if (flag == 1)
		{
			system("cls");
			display();
			cout << "\t\t---DEAR BANKING EMPLOYEE KINDLY ENTER YOUR CHOICE--- " << endl;
			cout << " \t\t\t1.VIEW LIST OF ALL CLIENTS " << endl;
			cout << " \t\t\t2. ACCOUNT REQUESTS " << endl;
			cout << " \t\t\t3. LOAN REQUESTS " << endl;
			cout << " \t\t\t4.VIEW TRANSACTION HISTORY " << endl;
			cout << " \t\t\t5. FREEZE ACCOUNT " << endl;
			int Choice;
			cin >> Choice;
		}
		else if (flag == 0)
		{
			cout << "not log in";
		}


	}

	}
}

void accountnumber()
{

}


void gotoxy(int x, int y)
{

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPosition{};
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void mainmenu()
{
	int choice;
	choice = 0;
	string idfile1 = string("user.txt"); // file name to store user credentials
	string idfile2 = string("companyclientdata.txt"); // file name to store comapnyclient credentials
	string idfile3 = string("admindata.txt"); //file to store admin credentials
	do
	{
	B:
		system("cls");
		system("Color 0B");

		gotoxy(25, 7);	cout << "           ||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		Sleep(40);
		gotoxy(25, 8);	cout << "           ||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		Sleep(40);
		gotoxy(25, 9);	cout << "           |||                                            |||" << endl;
		Sleep(40);
		gotoxy(25, 10);	cout << "           |||                                            |||" << endl;
		Sleep(40);
		gotoxy(25, 11);	cout << "           |||                                            |||" << endl;
		Sleep(40);
		gotoxy(25, 12);	cout << "           |||                WELCOME TO                  |||" << endl;
		Sleep(40);
		gotoxy(25, 13);	cout << "           |||          Al-Fatemah  BANKING  SYSTEM       |||" << endl;
		Sleep(40);
		gotoxy(25, 14);	cout << "           |||                                            |||" << endl;
		Sleep(40);
		gotoxy(25, 15);	cout << "           |||                ENTER YOUR CHOICE           |||" << endl;
		Sleep(40);
		gotoxy(25, 16);	cout << "           |||                 1: USER CLIENT             |||" << endl;
		Sleep(40);
		gotoxy(25, 17);	cout << "           |||                 2: COMPANY CLIENT          |||" << endl;
		Sleep(40);
		gotoxy(25, 18);	cout << "           |||                 3: BANKING CLIENT          |||" << endl;
		Sleep(40);
		gotoxy(25, 19);	cout << "           |||                 4: EXIT THE PORTAL         |||" << endl;
		Sleep(40);
		gotoxy(25, 20);	cout << "           |||                                            |||" << endl;
		Sleep(40);
		gotoxy(25, 21);	cout << "           |||                                            |||" << endl;
		Sleep(40);
		gotoxy(25, 22);	cout << "           ||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		Sleep(40);
		gotoxy(25, 23);	cout << "           ||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		Sleep(40);

		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			display();
			userclient* userclientObj = new userclient;
			userclientObj->userclient_menu(idfile1);
			delete userclientObj;
			break;
		}
		case 2:
		{
			display();
			companyclient* companyclientObj = new companyclient;
			companyclientObj->companyclient_menu(idfile2);
			delete companyclientObj;
			break;
		}
		case 3:
		{
			display();
			bankingclient* bankingclientObj = new bankingclient;
			bankingclientObj->bankingclient_menu(idfile3);
			delete bankingclientObj;
			goto B;
			break;

		}
		case 4:
			system("cls");
			display();
			cout << "\n\n";
			cout << "\t\t\t   Thanking you for visitng Al-Fatemah Online Banking Portal :)" << endl;
			cout << "\t\t\t\t Hope to see you soon" << endl;
			break;
		default:
			cout << "\t\t\t---Invalid Choice---" << endl;
			break;
		}
	} while (choice != 4);

}
void display()
{
	cout << "\n\n\t\t\t\t ____________________ " << endl;
	cout << "\t\t\t\t |                           |" << endl;
	cout << "\t\t\t\t |    BANKING SYSTEM !!!       |" << endl;
	cout << "\t\t\t\t |________________               |" << endl;
	cout << "\n\n";
}

int main()
{
	cout << "Welcome to Al-Fatimah Banking System" << endl;
	display();
	mainmenu();

}