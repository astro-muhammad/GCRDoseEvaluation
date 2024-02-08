#include "MyPrimaryGeneratorAction.hh"
#include "G4GeneralParticleSource.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"

MyPrimaryGeneratorAction::MyPrimaryGeneratorAction() {
    fParticleSource = new G4GeneralParticleSource();

    // Example: setting up a proton source
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition* particle = particleTable->FindParticle("proton");
    fParticleSource->SetParticleDefinition(particle);

    // Correct way to set energy and momentum direction for G4GeneralParticleSource
    fParticleSource->GetCurrentSource()->GetEneDist()->SetMonoEnergy(100 * MeV);
    fParticleSource->GetCurrentSource()->GetAngDist()->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
}

MyPrimaryGeneratorAction::~MyPrimaryGeneratorAction() {
    delete fParticleSource;
}

void MyPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
    fParticleSource->GeneratePrimaryVertex(anEvent);
}
