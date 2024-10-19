#include "person.h"

using namespace std;

//Khaled Esmail, CS302, Program 1
//function.cpp

/*
This file is where I implement the functions, constructors and destructors for all of my classes.


*/
//base constructor
Person::Person():name(nullptr), franchise(" ")
{
}

//copy constructor
Person::Person(const Person & copy): franchise(copy.franchise)
{
	name = new char[strlen(copy.name)+1];
	strcpy(name,copy.name);
}

//constructor with arguemtns
Person::Person(const string & name,const string & in_franchise): franchise(in_franchise)
{
	this->name = new char[name.size()+1];
	strcpy(this->name,name.c_str());	
}
//destructor
Person::~Person()
{
	delete [] name;
}

//destructor for derived class
Actor::~Actor()
{
	delete [] quote;
}

//initialization list
Actor::Actor():selfie_fee(20),autograph_fee(20),quote(nullptr)
{
}

//constructor with arguments
Actor::Actor(const int & selfie_fee,const int & autograph_fee,const string & franchise,const string & name,const string & quote):Person(name,franchise),selfie_fee(selfie_fee),autograph_fee(autograph_fee)
{
	this->quote = new char[quote.size()+1];
	strcpy(this->quote,quote.c_str());	
}

//copy constructor
Actor::Actor(const Actor & to_copy):Person(to_copy),selfie_fee(to_copy.selfie_fee),autograph_fee(to_copy.autograph_fee) 
{
	quote = new char[strlen(to_copy.quote)+1];
	strcpy(quote,to_copy.quote);
}


//initialization list for artist class
Artist::Artist():drawing_fee(20),autograph_fee(20) 
{
}

//initialization list for anime creator class
Anime_creator::Anime_creator():giveaway_prize(" "),user_number(0)
{
}


//actor quote function
int Actor::actor_quote(const string & actor_quote)
{
	cout << name << ": " << actor_quote << endl;
	return 1;
}

//allows user to get an autograph
int Actor::get_autograph()
{
	cout <<"The autograph will cost " << autograph_fee << " dollars.\n";
	return 1;
}

//book selfie function
int Actor::book_selfie()
{
	cout <<"The selfie will cost " << selfie_fee << " dollars.\n";
	return 1;
}


// allows user to book drawing session
int Artist::drawing_session()
{
	cout <<"The drawing session will cost " << drawing_fee << " dollars.\n";
	return 1;
}

//allows user to get something signed
int Artist::sign()
{
	cout <<"The signing fee is " << autograph_fee << " dollars.\n";
	return 1;	
}

//allows user to get drawing advice from the artist
int Artist::drawing_advice()
{
	cout <<"The drawing advice fee is " << drawing_fee << " dollars.\n";
	return 1;
}

//user can book selfie with anime creator
int Anime_creator::book_selfie()
{
	cout <<"The selfie will cost " << selfie_fee << " dollars.\n";
	return 1;
}

//allows user to ask an anime creator a question
int Anime_creator::QnA(const string & question)
{
	cout <<"Thank you for the question.\n";
	return 1;
}

//user can enter a giveaway
int Anime_creator::giveaway()
{
	CLL CLL_obj;
	srand(time(0));

	int user_number = rand() % 15 + 1;
	cout <<"Your number is: " << user_number << endl;
	
	CLL_obj.build();		 	
	CLL_obj.add();
	CLL_obj.retrieve();

	return 1;
}



