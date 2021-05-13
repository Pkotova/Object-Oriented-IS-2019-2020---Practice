#include "Folder.h"

Folder::Folder()
{
	setFolders(Vector<Folder>::Vector());
	setFiles(Vector<File>::Vector());
}

Folder::Folder(const Vector<Folder>& folders, const Vector<File>& files)
{
	setFolders(folders);
	setFiles(files);
}

void Folder::setFolders(const Vector<Folder> folders)
{
	this->folders = folders;
}

void Folder::setFiles(const Vector<File> files)
{
	this->files = files;
}

void Folder::addFolder(const Folder& folder)
{
	this->folders.push(folder);
}

void Folder::addFile(const File& file)
{
	this->files.push(file);
}

void Folder::print()
{
	std::cout << "Folder";
	for (size_t i = 0; i < files.getSize(); i++)
	{
		files[i].print();
	}
}
