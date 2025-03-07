#include "familyTree.h"

Tree::Tree()
{
    std::vector<Person*> _gids;
}

void Tree::addPerson(Person* person)
{
    _gids.push_back(person);
    return;
}

Person* Tree::getPerson(const int gid)
{
    return _gids[gid];
}

void Tree::printChildren(const int gid)
{
    Person* person = getPerson(gid);
    std::vector<int> c_gids = person->getChildren();
    if(!c_gids.empty())
    {
        for(unsigned int i = 0; i < c_gids.size(); ++i)
        {
            Person* p = getPerson(c_gids[i]);
            std::cout << p->getName() << std::endl;
        }
    }
    return;
}

void Tree::printParents(const int gid)
{
    Person* person = getPerson(gid);
    if(person->getPa()!= -1)
    {
        Person* p = getPerson(person->getPa());
        std::cout << p->getName() << std::endl;
    }
    if(person->getPb()!= -1)
    {
        Person* p = getPerson(person->getPb());
        std::cout << p->getName() << std::endl;
    }
    if((person->getPa() == -1)&&(person->getPb() == -1))
    {
        std::cout << "Beide Eltern sind unbekannt." << std::endl;
    }
    return;
}

void Tree::printSiblings(const int gid)
{
    Person* person = getPerson(gid);
    std::vector<int> siblings;
    //Eltern finden
    if(person->getPa()!= -1)
    {
        siblings = getPerson(person->getPa())->getChildren();
    }
    else if(person->getPb()!= -1)
    {
        siblings = getPerson(person->getPb())->getChildren();
    }
    else
    {
        std::cout << "Beide Eltern sind unbekannt." << std::endl;
    }
    //Ausgabe
    if(siblings.size() >= 2)
    {
        int anzahl = siblings.size()-1;   //-1 weil die Person selbst ja auch ein Kind ist
        std::cout << getPerson(gid)->getName() << " hat " << anzahl << " Geschwister:" << std::endl;
        for(unsigned int i = 0; i<siblings.size()-1; ++i)
        {
            std::cout << getPerson(siblings[i])->getName() << std::endl;
        }
    }
    else
    {
        std::cout << getPerson(gid)->getName() << " hat keine Geschwister oder sie sind unbekannt." << std::endl;
    }
    return;
}
