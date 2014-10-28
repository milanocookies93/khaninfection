#ifndef _KAGRAPH_H_
#define _KAGRAPH_H_

#include <list>
#include <queue>

#include "kauser.h"

class kagraph
{
    public:
        kagraph();
        ~kagraph();
        void adduser();
        void removeuser(int remove);
        void addrelation(int coach, int student);
        void breakrelation(int coach, int student);
        void updateuser(int user);
        void total_infection(int patzero);
        void limited_infection(int patzero, int updates);
        int graphversion;
        kauser** database;
        int maxusers;
        int nextfill;
        std::queue<int> removedusers;

    private:
        void infection(int patzero, int updates);
};

#include "kagraph.cpp"

#endif