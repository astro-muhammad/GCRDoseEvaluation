#include "MyDetectorConstruction.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"  // For cylindrical shape
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4SDManager.hh"
#include "MySensitiveDetector.hh"  // Include your sensitive detector class

MyDetectorConstruction::MyDetectorConstruction() {}

MyDetectorConstruction::~MyDetectorConstruction() {}

G4VPhysicalVolume* MyDetectorConstruction::Construct() {
    // Get NIST material manager
    G4NistManager* nist = G4NistManager::Instance();

    // Define materials
    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");
    G4Material* water = nist->FindOrBuildMaterial("G4_WATER");

    // World volume
    G4double world_size = 3.0 * m;  // Make sure the world volume is larger than before
    G4Box* solidWorld = new G4Box("World", 0.5 * world_size, 0.5 * world_size, 0.5 * world_size);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, air, "World");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0);

    // Human model volume (represented as a cylinder for simplicity)
    G4double body_radius = 20 * cm;
    G4double body_height = 170 * cm;
    G4Tubs* solidBody = new G4Tubs("Body", 0, body_radius, 0.5 * body_height, 0.0 * deg, 360.0 * deg);
    G4LogicalVolume* logicBody = new G4LogicalVolume(solidBody, water, "Body");

    // Place the human model in the world volume
    new G4PVPlacement(0, G4ThreeVector(0, 0, 0.5 * body_height), logicBody, "Body", logicWorld, false, 0);

    // Sensitive detector for the human model
    auto* sdManager = G4SDManager::GetSDMpointer();
    auto* bodySD = new MySensitiveDetector("BodySD");
    sdManager->AddNewDetector(bodySD);
    logicBody->SetSensitiveDetector(bodySD);

    return physWorld;
}
