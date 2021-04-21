/*
 * function.cpp
 *
 *  Created on: Apr 21, 2021
 *      Author: liame
 */


#include "dataBase.h"
#include <bits/stdc++.h>
#include <fstream>

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

	for(int i = 0; i < loops; i++)
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


	for(int i = 0; i < loops; i++)
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
