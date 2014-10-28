#include <list>
#include <queue>
#include <iostream>

#include "kauser.h"

kagraph::kagraph()
{
	database = new kauser*[1];
	graphversion = 0;
	maxusers = 1;
	nextfill = 0;
}

kagraph::~kagraph()
{
	for (int i = 0; i < maxusers; i++)
	{
		if (database[i] != NULL)
			delete database[i];
	}
	delete [] database;
}

void kagraph::adduser()
{
	int value;
	if (!removedusers.empty())
	{
		value = removedusers.front();
		removedusers.pop();
	}

	else
	{
		value = nextfill;
		if (nextfill >= maxusers)
		{
			kauser** follow = new kauser*[2*maxusers];
			for (int i = 0; i<maxusers; i++)
			{
				follow[i] = database[i];
			}
			delete [] database;
			database = follow;
			maxusers = 2*maxusers; 
		}
		nextfill++;
	}
	database[value] = new kauser(graphversion);
}

void kagraph::removeuser(int remove)
{
	if (remove < maxusers)
	{
		if (database[remove] != NULL)
		{
			(database[remove])->displace();
			delete database[remove];
			database[remove] = NULL;
			removedusers.push(remove);
		}
	}
}

void kagraph::addrelation(int coach, int student)
{
	if (coach < maxusers && student < maxusers)
	{
		if (database[coach] != NULL && database[student] != NULL)
		{
			database[coach]->addstu(database[student]);
			database[student]->addcoach(database[coach]);
		}
	}
}

void kagraph::breakrelation(int coach, int student)
{
	if (coach < maxusers && student < maxusers)
	{
		if (database[coach] != NULL && database[student] != NULL)
		{
			database[coach]->removestu(database[student]);
			database[student]->removecoach(database[coach]);
		}
	}
}

void kagraph::updateuser(int user)
{
	if (user < maxusers)
	{
		if (database[user] != NULL)
			database[user]->update();
	}
}

void kagraph::total_infection(int patzero)
{
	infection(patzero,maxusers);
}

void kagraph::limited_infection(int patzero, int updates)
{
	infection(patzero, updates);
}

void kagraph::infection(int patzero, int updates)
{
	graphversion++;
	std::queue<kauser*> con_users;
	con_users.push(database[patzero]);
	while(!con_users.empty() && updates > 0)
	{
		kauser* sneeze = con_users.front();
		con_users.pop();
		if (sneeze->ver < graphversion)
		{
			sneeze->ver = graphversion;
			updates--;
		}

		std::list<kauser*>::const_iterator iterator;
		for (iterator = (sneeze->stu).begin(); iterator != (sneeze->stu).end(); ++iterator) 
		{
    		if ((*iterator)->ver < graphversion)
    		{
    			(*iterator)->ver = graphversion;
    			updates--;
    			con_users.push(*iterator);
    		}
		}
		for (iterator = (sneeze->coa).begin(); iterator != (sneeze->coa).end(); ++iterator) 
		{
    		if ((*iterator)->ver < graphversion)
    			con_users.push(*iterator);
		}
	}
}
