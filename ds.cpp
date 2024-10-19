#include "person.h"

using namespace std;

//Khaled Esmail, CS302, Program 1
//ds.cpp
/*
This file is where I implemented my data structures and their constructors and functions
The purpose of this CLL was to have an initial build of 10 people then the person can add themself to the list.
*/
//default constructor
c_node::c_node():next(nullptr)
{
}

//copy constructor
c_node::c_node(const c_node & copy):next(nullptr),lottery_num(copy.lottery_num)
{
}

//constructor with arguments
c_node::c_node(const int & a_num):next(nullptr)
{
}

//base constructor
CLL::CLL():rear(nullptr)
{
}
//destructor
CLL::~CLL()
{
	remove_all();
}

//destructor
c_node::~c_node()
{
	next = nullptr;
}

//setter function
void c_node::set_next(c_node * new_next)
{
	next = new_next;
}

//getter function
c_node *& c_node::get_next()
{
	return next;
}	

//checks if next is or isn't null
bool c_node::has_next() const
{
	if(next)
		return true;
	else
		return false;
}

//setter
void c_node::set_data(int & data)
{
	lottery_num = data;		
}
//getter
int c_node::get_data(int & data)
{
	return lottery_num;
}

//display node
int c_node::c_display()
{
	cout << lottery_num << endl;
	return 1;
}
//wrapper function
int CLL::build()
{	
	for(int count = 1; count <= 10; ++count)
	{
		build(rear,count);
	}
	return 1;
}
//builds initial list of people that entered the giveaway
int CLL::build(c_node *& rear,int & count)
{
	if(!rear)
	{
		rear = new c_node;
		rear->set_data(count);
		rear->set_next(rear);
	}
	if(rear)
	{
		c_node * temp = new c_node;
		temp->set_data(count);
		temp->set_next(rear->get_next());
		rear->set_next(temp);
	}
	return 1;
}
//wrapper function
int CLL::display()
{
	if(!rear) return 0;
	return display(rear);
}

//recursive display all and return count function
int CLL::display(c_node *& rear)
{
	//base case
	if(this->rear == rear)
		return 0;
	cout <<"This is the data in the list\n";
	cout <<	rear->c_display() << endl; 
	return display(rear->get_next()) + 1;


}

//add the user to the list of people in the giveaway
int CLL::add()
{
	if(rear)
	{
		int count = display();
		c_node * temp = new c_node;
		temp->set_data(count);
		temp->set_next(rear->get_next());
		rear->set_next(temp);
	}
	return 1;

}
//wrapper function
int CLL::remove()
{
	if(!rear) return 0;
	if(rear->get_next() == rear)
	{
		delete rear;
		rear =nullptr;
	}
	c_node * temp = rear->get_next();
	rear->get_next() = temp->get_next();
	delete temp;
	temp = nullptr;
	return 1;
}
//wrapper function
int CLL::remove_all()
{
	if(!rear) return 0;
	return remove_all(rear);
}


//recursive delete all
int CLL::remove_all(c_node *& rear)
{
	if(this->rear==rear)
	{
		delete rear;
		rear = nullptr;
	}
	c_node * temp = rear->get_next();
	rear->get_next() = temp->get_next();
	delete temp;
	temp = nullptr;
	return remove_all(rear->get_next());	

}
//search function
int CLL::retrieve()
{
	
	return 1;
}

//assignment operator
CLL & CLL::operator=(const CLL & src)
{
	if(this == &src)
		return *this;
	remove_all();
	
	return *this;
}



