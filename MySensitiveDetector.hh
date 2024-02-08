#ifndef MySensitiveDetector_h
#define MySensitiveDetector_h 1

#include "G4VSensitiveDetector.hh"

class G4Step;
class G4HCofThisEvent;
class G4TouchableHistory;

class MySensitiveDetector : public G4VSensitiveDetector {
public:
    MySensitiveDetector(const G4String& name);
    virtual ~MySensitiveDetector();

    virtual void Initialize(G4HCofThisEvent* hce) override;
    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history) override;
    virtual void EndOfEvent(G4HCofThisEvent* hce) override;
};

#endif
