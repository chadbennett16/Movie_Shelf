/*	Movie Shelf
	Chad Bell
	10/05/2018		*/

/*  The purpose of this program is to keep a catalog of movies that are added to it 
	The user can add their movie catalog by entering the ADD command and then entering the necessary information on the movie
	The user can view their entire catalog or just one single movie via a command 
	The user can also search all added movies of a particular genre or leading star
	All movie info is saved into a text file so the information can be saved throughout multiple runs
	
	For now, this program is strictly terminal based
	A GUI is being considered to add movie posters and provide  a "Netflix-like" catalog of movies */

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Movie {

public:
	string Name, Genre, Year, Lead;

	void add_movie(string title, vector<Movie> catalog);
	void view_movie(string title, vector<Movie> catalog);
};


void Movie::add_movie(string title, vector<Movie> catalog) {

	//Check if the Movie is already in the catalog

	for (int i = 0; i < catalog.size(); i++) {
		if (catalog[i].Name == title) {
			cout << title << " is already in your catalog!" << endl << endl;
			return;
		}

	}
	
	//Otherwise, add Movie information to the vector and file

	string genre, year, lead;
	ofstream file;
	file.open("movie_catalog.txt", ios::app);

	cout << endl;
	cout << "What genre is " << title << ": ";
	getline(cin, genre);
	cout << endl;
	cout << "What year was " << title << " released: ";
	getline(cin, year);
	cout << endl;
	cout << "Who stars in " << title << ": ";
	getline(cin, lead);
	cout << endl;

	Name = title;
	Genre = genre;
	Year = year;
	Lead = lead;

	file << Name << endl;
	file << Genre << endl;
	file << Year << endl;
	file << Lead << endl;
	file << endl;

	cout << title << " added to catalog!" << endl;

	file.close();

}

void search_movie(string command) {


}

void Movie::view_movie(string title, vector<Movie> catalog) {


	
	
	/*cout << endl;
	cout << Name << " (" << Year << ")" << endl;
	cout << "Genre: " << Genre << endl;
	cout << "Leading Star: " << Lead << endl;
	cout << endl;*/

}

vector<Movie> fill_list() {

	ifstream file;
	file.open("movie_catalog.txt", ios::in);

	vector<Movie> movie_list;
	int i = 0;
	string space;
	while (!file.eof()) {
		Movie movie;
		getline(file, movie.Name);
		getline(file, movie.Genre);
		getline(file, movie.Year);
		getline(file, movie.Lead);
		getline(file, space);

		movie_list.push_back(movie);
	}

	file.close();
	return movie_list;
}

int main()
{
	
	cout << "Welcome to your digital movie catalog!" << "\n\n\n";

	vector<Movie> catalog = fill_list();

	while (1) {

		string command;
		Movie movie;

		cout << "Enter a command (ADD/VIEW title/SEARCH genre or actor/QUIT): ";
		getline(cin, command);

		string token = command.substr(0, command.find(" "));

		if (command == "QUIT" || command == "quit") break;

		else if (token == "ADD") {

			string title = command.substr(4);
			movie.add_movie(title, catalog);

		}

		else if (token == "VIEW") {

			string title = command.substr(5);
			movie.view_movie(title, catalog);

		}

		else cout << "Invalid command!" << endl;
	}

	return 0;
}