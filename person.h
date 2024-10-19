//person.h

//Khaled Esmail, CS302, Program 1
//This .h file contains all of the libraries I need and all of my classes
//This has the classes in which I manage my nodes and data structures



#pragma once
#include <string>
#include <vector>
#include <cstring>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::string;
using std::vector;




//my base class
class Person
{
	public:
		Person();
		Person(const string & name,const string & franchise);
		Person(const Person & copy);
		~Person();
		Person & operator=(const Person & src);
		bool is_available(const string & name);
		int make_appointment();
		int cancel();
	protected:
		char * name;
		string franchise;
	

};
//derived actor class
class Actor: public Person
{
	public:
		Actor();
		Actor(const Actor & to_copy);
		Actor(const int & selfie_fee,const int & autograph_fee,const string & franchise,const string & name,const string & quote);
		~Actor();
		Actor & operator=(const Actor & src);
		void display() const;
		int get_autograph();
		int book_selfie();
		int actor_quote(const string & actor_quote);

	protected:
		int selfie_fee;
		int autograph_fee;
		char * quote;

};

// derived artist class
class Artist: public Person
{
	public:
		Artist();
		void display() const;
		int drawing_session();
		int sign();//they sign a comic book or art
		int drawing_advice();

	protected:
		int drawing_fee;//the fee for the drawing session and advice are the same
		int autograph_fee;
};

// derived anime creator class
class Anime_creator: public Person
{
	public:
		Anime_creator();
		int book_selfie();
		int QnA(const string & question);
		int giveaway();
	protected:
		string giveaway_prize;
		int user_number;
		int selfie_fee;
};

//node for my CLL
class c_node: public Anime_creator
{
	public:
		c_node();
		~c_node();
		c_node(const c_node & copy);
		c_node(const int & a_num);
		c_node *& get_next();
		int get_data(int & data);
		void set_next(c_node * new_next);
		void set_data(int & data);
		bool has_next() const;
		int c_display();
		
	
	private:
		c_node * next;
		int lottery_num;

};

//manages the CLL
class CLL
{
	public:
		CLL();
		~CLL();
		CLL(const CLL & to_copy);
		CLL & operator=(const CLL & src);
		int build();
		int add();
		int remove();
		int display();
		int retrieve();
		int remove_all();
		


	private:
		c_node * rear;
		int build(c_node *& rear, int & count);
		int display(c_node *& rear);
		int remove_all(c_node *& rear);
		int retrieve(c_node *& rear);
};

//node for my ALL
/*
class node
{
	public:
		node();
		node(const node & copy);
		node(const string & a_event);
		node *& get_next();
		void set_next(node * new_next);
		bool has_next() const;

	private:
		node * next;
		string event_name;


};
*/















