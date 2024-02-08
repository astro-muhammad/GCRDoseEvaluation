#ifndef MyCustomPhysicsList_hh
#define MyCustomPhysicsList_hh

#include "G4VModularPhysicsList.hh"

class MyCustomPhysicsList : public G4VModularPhysicsList {
public:
    MyCustomPhysicsList();
    virtual ~MyCustomPhysicsList();
};

#endif // MyCustomPhysicsList_hh
