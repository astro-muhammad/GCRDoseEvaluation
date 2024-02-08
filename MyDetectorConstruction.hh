#ifndef MyDetectorConstruction_hh
#define MyDetectorConstruction_hh

#include "G4VUserDetectorConstruction.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction {
public:
    MyDetectorConstruction();
    virtual ~MyDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
};

#endif
