/*
 * function.cpp
 *
 *  Created on: Apr 21, 2021
 *      Author: liame
 */


#include <bits/stdc++.h>
#include <fstream>
#include "functions.h"

using namespace std;

souvenirList::souvenirList()
{
	souvenirs[0].souvenir = "Baseball Cap";
	souvenirs[0].price = 19.99;
	souvenirs[1].souvenir = "Baseball Bat";
	souvenirs[1].price = 89.39;
	souvenirs[2].souvenir = "Team Pennant";
	souvenirs[2].price = 17.99;
	souvenirs[3].souvenir = "Autographed Baseball";
	souvenirs[3].price = 29.99;
	souvenirs[4].souvenir = "Team Jersey";
	souvenirs[4].price = 199.99;
}

//This function takes in a array of stadiums and fills them with text input
/************************************************************************************************************
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!IMPORTANT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! *
 ************************************************************************************************************
 * This function has 4 assumptions:
 * 		the array is currently empty
 * 		the count given is EXACTLY EQUAL to the number of items in the file
 * 		All of the input files have information for at least one stadium
 * 		All of the input files are formated correctly
 * 	In addition this function requires a text file named "Stadiums.txt"
 *		And a text file named Distances.txt
 *
 *************************************************************************************************************/
void fileRead(stadium a[40], int loops)
{
	int key;
	int key2;
	int distance;
	string teamName;
	string stadiumName;
	int seatingCapacity;
	string location;
	string playingSurface;
	string League;
	int dateOpened;
	int DTCF; //Distance to center Field
	string Typology;
	string roofType;
	fstream infile;
	infile.open("Stadiums.txt");

	for(int i = 1; i <= loops; i++)
	{
		infile >> key;
		infile.ignore(10000, '\n');
		getline(infile, teamName);
		getline(infile, stadiumName);
		infile >> seatingCapacity;
		infile.ignore(1000, '\n');
		getline(infile, location);
		getline(infile, playingSurface);
		getline(infile, League);
		infile >> dateOpened;
		infile.ignore(1000, '\n');
		infile >> DTCF;
		infile.ignore(1000, '\n');
		getline(infile, Typology);
		getline(infile, roofType);

		a[i].setAll(key, teamName, stadiumName, seatingCapacity, location, playingSurface, League, dateOpened, DTCF, Typology, roofType);
	}

	infile.close();
	infile.open("Distances.txt");
	stadiumName = "";


	for(int i = 1; i <= loops; i++)
	{
		infile >> key;
		infile.ignore(1000, '\n');
		while(getline(infile, stadiumName))
		{
			if(stadiumName == "")
			{
				break;
			}
			infile >> key2;
			infile.ignore(1000, '\n');
			infile >> distance;
			infile.ignore(1000, '\n');
			a[i].addDistance(key2, distance, stadiumName);
		}
	}
}

//This function takes in a array of stadiums and fills them with text input from a given fileName
/************************************************************************************************************
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!IMPORTANT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! *
 ************************************************************************************************************
 * This function has 4 assumptions:
 * 		fileName is a string that accuratley describes a text file
 * 		the text file that fileName describes has all of the neccesary input
 * 		The input file is formated correctly
 * 		The key given in the text file is not equal to any key currently in the list
 * 			If the previous assumption isnt met, the info at the key value will be replaced
 *
 *************************************************************************************************************/
void expandData(stadium a[40], string fileName, int &count)
{
	int key;
	int key2;
	int distance;
	string teamName;
	string stadiumName;
	int seatingCapacity;
	string location;
	string playingSurface;
	string League;
	int dateOpened;
	int DTCF; //Distance to center Field
	string Typology;
	string roofType;
	fstream infile;
	infile.open(fileName);

		infile >> key;
		infile.ignore(10000, '\n');
		getline(infile, teamName);
		getline(infile, stadiumName);
		infile >> seatingCapacity;
		infile.ignore(1000, '\n');
		getline(infile, location);
		getline(infile, playingSurface);
		getline(infile, League);
		infile >> dateOpened;
		infile.ignore(1000, '\n');
		infile >> DTCF;
		infile.ignore(1000, '\n');
		getline(infile, Typology);
		getline(infile, roofType);

		a[key].setAll(key, teamName, stadiumName, seatingCapacity, location, playingSurface, League, dateOpened, DTCF, Typology, roofType);
		while(getline(infile, stadiumName))
		{
			if(stadiumName == "")
			{
				break;
			}
			infile >> key2;
			infile.ignore(1000, '\n');
			infile >> distance;
			infile.ignore(1000, '\n');
			a[key].addDistance(key2, distance, stadiumName);
		}
		count++;
}

void fileSave(stadium a[40], int loops)
{
	int key;
	int key2;
	int distance;
	string teamName;
	string stadiumName;
	int seatingCapacity;
	string location;
	string playingSurface;
	string League;
	int dateOpened;
	int DTCF; //Distance to center Field
	string Typology;
	string roofType;
	fstream infile;
	infile.open("Stadiums.txt");

	for(int i = 1; i <= loops; i++)
	{
		a[i].getAll(key, teamName, stadiumName, seatingCapacity, location, playingSurface, League, dateOpened, DTCF, Typology, roofType);
		infile << key << endl;
		infile << teamName << endl;
		infile << stadiumName << endl;
		infile << seatingCapacity << endl;
		infile << location << endl;
		infile << playingSurface << endl;
		infile << League << endl;
		infile << dateOpened << endl;
		infile << DTCF << endl;
		infile << Typology << endl;
		infile << roofType << endl << endl;
	}

	infile.close();
	infile.open("Distances.txt");



	for(int i = 1; i <= loops; i++)
	{
		infile << i << endl;
		for(unsigned int j = 0; j < a[i].getDistance().size(); j++)
		{
			getDistance(stadiumName, distance, key2, j, a[i].getDistance());
			infile << stadiumName << endl;
			infile << key2 << endl;
			infile << distance << endl << endl;
		}
	}
}

void DFS(int v, bool visited[40], stadium a[40])
{
	int key;
	int distance;
	string stadium;
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    a[v].printName();//Test line

    // Recur for all the vertices adjacent
    // to this vertex
   for (unsigned int i = 0; i != a[v].getDistance().size(); ++i)
   {
	   getDistance(stadium, distance, key, i, a[v].getDistance());
           if (!visited[key])
           {
               DFS(key, visited, a);
           }
   }

}

void BFS(int s, bool visited[40], stadium a[40])
{

    // Create a queue for BFS
    list<int> queue;
    int key;
    int distance;
    string stadium = "Chase Field";

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it

        s = *queue.begin();
        queue.erase(queue.begin());
        a[s].printName();


        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (unsigned int i = 0; i != a[s].getDistance().size(); ++i)
        {
        	getDistance(stadium, distance, key, i, a[s].getDistance());
        	if (visited[key] == false)
            {
                visited[key] = true;
                queue.push_back(key);
            }
        }
    }
}

void getDistance(string &name, int &distance, int &key, int index, priority_queue<anythingelse> a)
{
	for(int i = 0; i < index; i++)
	{
		a.pop();
	}
	name = a.top().name;
	key = a.top().key;
	distance = a.top().distance;
}


