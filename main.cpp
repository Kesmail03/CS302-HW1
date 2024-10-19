//main.cpp

//Khaled Esmail, CS302, Program 1
//This is the main file where I get the info from the user 
//This has my menus which allows the user to see who they want at comic con
//This is where I call my functions


#include"person.h"



using namespace std;

int main()
{
	string name(" "), franchise(" "), quote (" "), question(" ");
	int option(0), option2 (0);
	bool stop (true);
	int selfie_fee(20), autograph_fee(20);
	vector <Actor> vector_actor;
	vector <Artist> vector_artist;
	vector <Anime_creator> vector_anime;
	while(stop)
	{
		cout<<"Please enter the name\n"; 
		getline(cin,name);
		cout<<"Please enter the franchise\n";
		getline(cin,franchise);
		cout<<"1.Actor\n"<<"2.Artist\n"<<"3.Anime creator\n"<<"4.Quit\n";
		cout<<"Please choose who you would like to see at comic con\n";
		cin >> option;
		cin.ignore(100, '\n');
		switch(option)
		{
			case 1:
				{
					Actor an_actor(selfie_fee,autograph_fee,franchise,name,quote);
					cout<<"Please choose what you would like to do with this actor.\n";
					cout<<"1.Actor quote\n"<<"2.Actor autograph\n"<<"3.Actor selfie\n";
					cin >> option2;
					cin.ignore(100, '\n');
					switch(option2)
					{
						case 1:
							cout<<"Enter the quote you would like the actor to say.\n";
							cin >> quote;	
							an_actor.actor_quote(quote);
							break;
						case 2:
							an_actor.get_autograph();
							break;
						case 3:
							an_actor.book_selfie();
							break;
					}
					vector_actor.push_back(an_actor);
				}
				break;
			case 2:
				{
					Artist an_artist;
					cout<<"Please choose what you would like to do with this Artist.\n";
					cout<<"1.Drawing Session\n"<<"2.Get Something Signed\n"<<"3.Get Drawing Advice\n";
					cin >> option2;
					switch(option2)
					{
						case 1:	
							an_artist.drawing_session();
							break;
						case 2:
							an_artist.sign();	
							break;
						case 3:
							an_artist.drawing_advice();
							break;
					}
					vector_artist.push_back(an_artist);
				}
				break;
			case 3:
				{
					Anime_creator an_anime;
					cout<<"Please choose what you would like to do with this Anime creator.\n";
					cout<<"1.Book a selfie\n"<<"2.Ask a question\n"<<"3.Enter a giveaway\n";
					cin >> option2;
					switch(option2)
					{
						case 1:
							an_anime.book_selfie();
							break;
						case 2:
							cout <<"Please enter your question.\n";
							cin >> question;
							an_anime.QnA(question);
							break;
						case 3:
							an_anime.giveaway();
							break;
					}
					vector_anime.push_back(an_anime);
				}
				break;
			case 4:
				stop = false;
				break;
				
		}	
		
	}
	




	return 0;
}


