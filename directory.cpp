#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
#include <sstream>
#include "file.h"
#include "directory.h"
using namespace std;




void directory::make_new_dir(string name_dir)
{
	directory* x = new directory(name_dir);
	inner_directories.push_back(x);
	
}
file* directory::search_inner_files(string a)
{
	for(int x = 0; x < inner_Files.size();x++)
	{
		if(inner_Files[x]->get_name() == a)
			return inner_Files[x];
	}
}
bool directory::_if_the_directory_excists(string name)
{
	for(int i = 0;i < inner_directories.size();i++)
	{
		if(inner_directories[i]->get_name_dir() == name)
			return true;
	}
	return false;
}


bool directory::_if_the_file_excists(string name)
{
	for(int index = 0; index < inner_Files.size(); index++)
	{
		if(inner_Files[index]->get_name() == name )
			return true;
	}

	return false;
}
void directory::remove_file(string name_)
{
	for(int j = 0;j < inner_Files.size();j++)
	{
		if(inner_Files[j]->get_name() == name_)
		{
			inner_Files.erase(inner_Files.begin()+ j);
			return;
		}
	}
}

string directory::get_name_dir()
{
	return name;
}

directory* directory::search_for_the_dir(string name_dir)
{	
		for(int i =0;i<inner_directories.size();i++)
		{   
			if(inner_directories[i]->get_name_dir() == name_dir)
			{ 
				return inner_directories[i];
			}
		}
	
}
string directory::find_the_file(string filename)
{
	for(int k = 0;k < inner_Files.size();k++)
	{
		if(inner_Files[k]->get_name() == filename)
			return inner_Files[k]->get_name();
	}
}
void directory::add_file(string name_file,string x)
{	
	file* myfile = new file;
	myfile->set_name(name_file);
	myfile->set_availablity(x);
	inner_Files.push_back(myfile);
}

void directory::remove_directory(string name)
{
	for(int i = 0;i<inner_directories.size();i++)
	{
		if(inner_directories[i]->get_name_dir() == name)
			inner_directories.erase(inner_directories.begin() + i);
	}
}
