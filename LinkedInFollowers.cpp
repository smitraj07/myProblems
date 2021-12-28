/*
* Written by Smit Raj.
*
* Program: To find which LinkedIn connection do not follow you.
*
* connections.txt : Copy all your conection list (cntrl+a, cntrl+c)
*                   This should copy all your connections with some other
*                   unwanted strings, each in a new ine
*
* followers.txt  : Copy all your follower list (cntrl+a, cntrl+c)
*                  This should copy all your followers with some other
*                  unwanted strings, each in a new ine
*
* keys :           You can modify the keys based on your output needed to be
*                  filtered.
*
* Console output : List of connection who do not follow you. (with some exra string, can filter out mannualy)
*  
*/


#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <bits/stdc++.h>
#include <set>
#include <fstream>

using namespace std;


bool
notKeyWord(const string& str)
{
    vector<string> keys = {"is", "reachable", "Connections", "followers", "connected", "message", "Connected", "Followed", "Follow", 
                            "Message", "Search", "name", "occupation", "|", "||", "added", "notifications"};
    for (auto key : keys)
    {
        if (str.find(key) != string::npos)
            return false;
    }

    return true;
}

int 
main()
{
    fstream yourConnections;
    yourConnections.open("connections.txt", ios::in);

    set<string> connectionSet;
    string temp;
    while(getline(yourConnections, temp))
    {
        if (notKeyWord(temp))
            connectionSet.insert(temp);
        temp.clear();
    }

    fstream yourFollowers;
    set<string> minusSet;
    yourFollowers.open("followers.txt", ios::in);
    while(getline(yourFollowers, temp))
    {
        if (connectionSet.find(temp) == connectionSet.end() && notKeyWord(temp))
        {
            minusSet.insert(temp);
        }
        temp.clear();
    }

    for (auto name : minusSet)
    {
        cout << name << endl;
    }

    return 0;
}
