#include "MyCustomPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4HadronPhysicsQGSP_BERT.hh"

MyCustomPhysicsList::MyCustomPhysicsList() {
    // Electromagnetic Physics
    RegisterPhysics(new G4EmStandardPhysics());

    // Decay Physics
    RegisterPhysics(new G4DecayPhysics());

    // Elastic Scattering
    RegisterPhysics(new G4HadronElasticPhysics());

    // Hadronic Physics
    RegisterPhysics(new G4HadronPhysicsQGSP_BERT());
}

MyCustomPhysicsList::~MyCustomPhysicsList() {}
