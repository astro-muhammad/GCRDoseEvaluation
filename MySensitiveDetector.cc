#include "MySensitiveDetector.hh"
#include "G4Step.hh"
#include "G4HCofThisEvent.hh"
#include "G4TouchableHistory.hh"
#include "G4SystemOfUnits.hh"

MySensitiveDetector::MySensitiveDetector(const G4String& name)
    : G4VSensitiveDetector(name) {
}

MySensitiveDetector::~MySensitiveDetector() {
}

void MySensitiveDetector::Initialize(G4HCofThisEvent* hce) {
    // Initialization logic here
}

G4bool MySensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory* /*history*/) {
    G4double edep = step->GetTotalEnergyDeposit();
    if (edep == 0.) return false;  // No edep, so don't count as hit

    // You could accumulate the dose here, or store the hit for later processing
    // For now, let's just print the energy deposited in this step
    G4cout << "Energy deposited: " << edep / keV << " keV" << G4endl;

    return true;
}

void MySensitiveDetector::EndOfEvent(G4HCofThisEvent* hce) {
    // Finalization logic here
}
