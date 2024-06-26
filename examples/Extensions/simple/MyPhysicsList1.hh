//
// This file was copied from geant4/examples/extended/analysis to TOPAS
// as an example of a user-contributed physics list.
// The only addition for TOPAS was to also pass the pointer to
// the TsParameterManager so that you can use TOPAS parameters to further
// control your physics.
//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************

#ifndef MyPhysicsList1_hh
#define MyPhysicsList1_hh

#include "G4VUserPhysicsList.hh"
#include "globals.hh"

class TsParameterManager;

class MyPhysicsList1 : public G4VUserPhysicsList
{
public:
	MyPhysicsList1(TsParameterManager* pM);
	virtual ~MyPhysicsList1();

	// Construct particle and physics
	virtual void ConstructParticle();
	virtual void ConstructProcess();

	virtual void SetCuts();

private:

	// these methods Construct physics processes and register them
	void ConstructDecay();
	void ConstructEM();

	TsParameterManager* fPm;
};

#endif



