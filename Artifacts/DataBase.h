/*
 * AUTHOR: Liam Knight
 * CLASS: CS1D
 * SECTION: Data Base and file reading
 */

#include <bits/stdc++.h>
#include <queue>

using namespace std;
#ifndef DATABASE_H_
#define DATABASE_H_

struct souvenir
{
	string souvenir;
	double price;
};

class souvenirList
{
private:
	souvenir souvenirs[7];
	int noSouvenirs = 5;
public:
	souvenirList();
	void addSouvenir(souvenir a)
	{
		//If we can still add souvenirs to the list
		if(noSouvenirs < 7)
		{
			souvenirs[noSouvenirs] = a;
			noSouvenirs++;
		}
	}
	void removeSouvenir(int i)
	{
		//i refers to the index we want to erase
		if(i < noSouvenirs)
		{
			souvenirs[i] = souvenirs[noSouvenirs];
			souvenirs[noSouvenirs].price = 0.0;
			souvenirs[noSouvenirs].souvenir = "a";
		}
	}
	void editSouvenir(int i, string s, double p)
	{
		//i refers to the index we are editing
		if(s == "a" || p == 0 || i >= 7)
		{
			//for the purpose of editing a souvenir, these inputs are illegal.
			return;
		}
		souvenirs[i].souvenir = s;
		souvenirs[i].price = p;
	}
};

class anythingelse
{
public:
	int key;
	int distance;
	string name;
	bool operator>(const anythingelse b) const
	{
		return distance > b.distance;
	}
	bool operator<(const anythingelse b) const
	{
		return distance < b.distance;
	}
	bool operator>=(const anythingelse b) const
	{
		return distance >= b.distance;
	}
	bool operator <=(const anythingelse b) const
	{
		return distance <= b.distance;
	}
};

class stadium
{
private:
	int key;
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
	souvenirList souvenirs;
	priority_queue<anythingelse> distances;
public:
	void setAll(int k, string a, string b, int c, string d, string e, string f, int g, int h, string i, string j) //set everything EXCEPT its distances and souvenirs
	{
		key = k;
		teamName = a;
		stadiumName = b;
		seatingCapacity = c;
		location = d;
		playingSurface = e;
		League = f;
		dateOpened = g;
		DTCF = h;
		Typology = i;
		roofType = j;
	}
	void addDistance(int k, int d, string n)
	{
		anythingelse newDistance;
		newDistance.key = k;
		newDistance.distance = d;
		newDistance.name = n;
		distances.push(newDistance);
	}
	void printName()
	{
		cout << stadiumName << endl;
	}
	priority_queue<anythingelse> getDistance()
		{
			return distances;
		}

};

void fileRead(stadium a[40], int);

#endif /* DATABASE_H_ */
