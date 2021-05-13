#include <iostream>
#include"File.h"
#include"Folder.h"
int main()
{
	File f1("test.txt", "12.05.2021", type::text_file, 13);
	File f2("unknown.dkr", "12.03.2020", type::undef, 0);
	File f3("wedding.mp4", "02.10.2011", type::video, 13000);
	File f4("main.cpp", "15.12.2001", type::programming, 5);
	File f5("activation.bat", "22.07.2003", type::system_related, 2);
	File f6("setup.exe", "29.02.2004", type::executable, 1);
	File f7("more.PNG", "12.05.2021", type::image, 4);
	File f8("egypy.pptx", "12.03.2003", type::presentation, 2);
	File f9("ocenki.xsls", "06.06.1999", type::spreadsheet, 78);
	File f10("users.db", "02.02.2021", type::data_and_database, 102);
	File f11("shop.php", "01.08.2016", type::script, 6);
	File f12("index.html", "02.11.2017", type::internet_related, 22);
	File f13("mspaint.shortcut", "05.02.2021", type::shortcut, 0);
	File f14("pishtovi.zip", "18.05.2018", type::archive, 15);
	File f15("azis_ledena_kralica.mp3", "24.03.2014", type::sound_and_music, 8);

	f1.print();
	f2.print();
	f3.print();
	f4.print();
	f5.print();
	f6.print();
	f7.print();
	f8.print();
	f9.print();
	f10.print();
	f11.print();
	f12.print();
	f13.print();
	f14.print();
	f15.print();

	f1.print();

}