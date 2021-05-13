#pragma once
#include"Vector.h"
#include"File.h";
class Folder
{
private:
	Vector<Folder> folders;
	Vector<File> files;
public:
	Folder();
	Folder(const Vector<Folder>& folders, const Vector<File>& files);

	void setFolders(const Vector<Folder> folders);
	void setFiles(const Vector<File> files);
	void addFolder(const Folder& folder);
	void addFile(const File& file);

	void print();
};

