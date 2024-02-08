#ifndef MyPrimaryGeneratorAction_hh
#define MyPrimaryGeneratorAction_hh

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4GeneralParticleSource.hh"

class MyPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
    MyPrimaryGeneratorAction();
    virtual ~MyPrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event* anEvent);

private:
    G4GeneralParticleSource* fParticleSource;
};

#endif
