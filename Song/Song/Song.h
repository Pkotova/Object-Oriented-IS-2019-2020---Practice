#pragma once
#include<iostream>
using std::ostream;
using std::istream;

class Song
{
private:

	int id;
	char name[32];
	char singer[32];
	int year;
	int views;

public:

	Song();
	Song(int newId, const char* newName, const char* newSinger, int newYear, int newViews);
	Song(int newId);
	Song(const char* newSinger);
	Song(const char* newName, int newYear);
	Song(int newViews, const char* newName);

	void setId(int newId);
	int getId()const;

	void setName(const char* newName);
	const char* getName()const;

	void setSinger(const char* newSinger);
	const char* getSinger()const;

	void setYear(int newYear);
	int getYear()const;

	void setViews(int newViews);
	int getViews()const;

	
	friend void sort(Song* songs, int size);
	int operator-(Song& otherSong);
	Song& operator=(const Song& otherSong);
	friend Song& hasTheMostViews(Song* songs, int size);

	friend ostream& operator<<(ostream& out,const Song& song);
	friend istream& operator>>(istream& in,  Song& song);

};

