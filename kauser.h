#ifndef _KAUSER_H_
#define _KAUSER_H_

#include <list>

class kauser
{
    public:
        kauser(int version);
        void addcoach(kauser* coach);
        void removecoach(kauser* coach);
        void addstu(kauser* student);
        void removestu(kauser* student);
        void update();
        void displace();
        int ver;
        int numstudents;
        std::list<kauser*> stu;
        std::list<kauser*> coa;
};

#include "kauser.cpp"

#endif