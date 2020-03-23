#include "Song.h"

Song::Song()
{
	setId(0);
	setName("Default name");
	setSinger("Default Singer");
	setYear(1900);
	setViews(0);
}

Song::Song(int newId, const char* newName, const char* newSinger, int newYear, int newViews)
{
	setId(newId);
	setName(newName);
	setSinger(newSinger);
	setYear(newYear);
	setViews(newViews);
}

Song::Song(int newId)
{
	setId(newId);
}

Song::Song(const char* newSinger)
{
	setSinger(newSinger);
}

Song::Song(const char* newName, int newYear)
{
	setName(newName);
	setYear(newYear);
}

Song::Song(int newViews, const char* newName)
{
	setViews(newViews);
	setName(newName);
}

void Song::setId(int newId)
{
	this->id = newId;
}

int Song::getId() const
{
	return this->id;
}

void Song::setName(const char* newName)
{
	strcpy_s(this->name, 32, newName);
}

const char* Song::getName() const
{
	return this->name;
}

void Song::setSinger(const char* newSinger)
{
	strcpy_s(this->singer, 32, newSinger);
}

const char* Song::getSinger() const
{
	return this->singer;
}

void Song::setYear(int newYear)
{
	this->year = newYear;
}

int Song::getYear() const
{
	return this->year;
}

void Song::setViews(int newViews)
{
	this->views = newViews;
}

int Song::getViews() const
{
	return this->views;
}

void Song::sort(Song* songs, int size)
{
	for (size_t i = 0; i < size - 1 ; i++)
	{
		for (size_t j = 0; j < size - i - 1 ; j++)
		{
			if (songs[j].getYear() > songs[j+1].getYear())
			{
				Song temp = songs[j];
				songs[j] = songs[j+2];
				songs[j+2] = temp;
			}
		}
	}
}

int Song::operator-(Song& otherSong)
{
	int difference = this->getYear() - otherSong.getYear();
	return (difference < 0) ? difference + (2 * (-1 * difference)) : difference;
}

Song& Song::operator=(const Song& otherSong)
{
	if (this != &otherSong)	
	{
		this->id = otherSong.id;
		strcpy_s(this->name, 32, otherSong.name);
		strcpy_s(this->singer, 32, otherSong.singer);
		this->year = otherSong.year;
		this->views = otherSong.views;
	}

	return *this;
}

Song& Song::hasTheMostViews(Song* songs, int size)
{
	//this->sort(songs, size);
	//return songs[0];

	Song temp = songs[0];
	for (size_t i = 0; i < size; i++)
	{
		if (songs[i].getViews() > temp.getViews())
		{
			temp = songs[i];
		}
	}
	return temp;
}

ostream& operator<<(ostream& out, const Song& song)
{
	std::cout << "ID: ";
	out << song.id;
	std::cout << "Name: ";
	out << song.name;
	std::cout << "Singer: ";
	out << song.singer;
	std::cout << "Year: ";
	out << song.year;
	std::cout << "Views: ";
	out << song.views;

	return out;
}

istream& operator>>(istream& in, const Song& song)
{
	std::cout << "ID: ";
	in >> song.id;
	std::cout << "Name: ";
	in >> song.name;
	std::cout << "Singer: ";
	in >> song.singer;
	std::cout << "Year: ";
	in >> song.year;
	std::cout << "Views: ";
	in >> song.views;

	return in;
}

// -----------------------------------
// out of the class

void swap(Song& s1, Song& s2) {

}