#include <list>

kauser::kauser(int version)
{
    ver = version;
    numstudents = 0;
}

void kauser::addcoach(kauser* coach)
{
    coa.push_back(coach);
    if (coach->ver > ver)
        ver = coach->ver;
}

void kauser::removecoach(kauser* coach)
{
    coa.remove(coach);
}

void kauser::addstu(kauser* student)
{
    stu.push_back(student);
}

void kauser::removestu(kauser* student)
{
    stu.remove(student);
}

void kauser::update()
{
	std::list<kauser*>::const_iterator iterator;
	for (iterator = coa.begin(); iterator != coa.end(); ++iterator) 
	{
    	if ((*iterator)->ver > ver)
    		ver = (*iterator)->ver;
	}
}

void kauser::displace()
{
	std::list<kauser*>::const_iterator iterator;
	for (iterator = coa.begin(); iterator != coa.end(); ++iterator) 
	{
    	(*iterator)->removestu(this);
	}
	for (iterator = stu.begin(); iterator != stu.end(); ++iterator) 
	{
    	(*iterator)->removecoach(this);
	}
}  