#include <iostream>
#include "Song.h"
using std::cin;
using std :: cout;
int main()
{
    Song s1;
    Song s2(1, "Halo", "Beyonce", 2009, 6000000);
    Song s3(2);
    Song s4("Afrika", 1982);
    Song s5(50000000, "Bohemian Rapsody");

    Song songs[3];
    cin >> songs[0];
    cin >> songs[1];
    cin >> songs[2];
    cout << std::endl;
    songs[0] - songs[1];
    //cout<<hasTheMostViews(songs, 3);
    sort(songs, 3);
    for (size_t i = 0; i < 3; i++)
    {
        cout << songs[i];
        cout << std::endl;
    }
}

