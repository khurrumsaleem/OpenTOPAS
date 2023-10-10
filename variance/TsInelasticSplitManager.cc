//
// ********************************************************************
// *                                                                  *
// * Copyright 2022 The TOPAS Collaboration                           *
// *                                                                  *
// * Permission is hereby granted, free of charge, to any person      *
// * obtaining a copy of this software and associated documentation   *
// * files (the "Software"), to deal in the Software without          *
// * restriction, including without limitation the rights to use,     *
// * copy, modify, merge, publish, distribute, sublicense, and/or     *
// * sell copies of the Software, and to permit persons to whom the   *
// * Software is furnished to do so, subject to the following         *
// * conditions:                                                      *
// *                                                                  *
// * The above copyright notice and this permission notice shall be   *
// * included in all copies or substantial portions of the Software.  *
// *                                                                  *
// * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  *
// * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES  *
// * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND         *
// * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT      *
// * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,     *
// * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     *
// * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR    *
// * OTHER DEALINGS IN THE SOFTWARE.                                  *
// *                                                                  *
// ********************************************************************
//

#include "TsInelasticSplitManager.hh"
#include "TsGeometryManager.hh"
#include "TsParameterManager.hh"

#include "G4UImanager.hh"
#include "G4UIcommand.hh"
#include "G4SystemOfUnits.hh"
#include "G4GenericBiasingPhysics.hh"

#include "globals.hh"
#include <vector>

TsInelasticSplitManager::TsInelasticSplitManager(G4String name, TsParameterManager* pM, TsGeometryManager* gM)
: TsVBiasingProcess(name, pM, gM), fPm(pM), fName(name)
{
	ResolveParameters();
}


TsInelasticSplitManager::~TsInelasticSplitManager()
{;}


void TsInelasticSplitManager::ResolveParameters() {
    fProcessesToBias = fPm->GetStringVector(GetFullParmName("ProcessesNamed"));
    G4int nbOfProcess = fPm->GetVectorLength(GetFullParmName("ProcessesNamed"));
    fParticlesToBias = fPm->GetStringVector(GetFullParmName("ParticlesNamed"));
    fNbOfParticles = fPm->GetVectorLength(GetFullParmName("ParticlesNamed"));
	fType = fPm->GetStringParameter(GetFullParmName("Type"));
	
    for ( int i = 0; i < nbOfProcess; i++ )
        fProcessToBias.push_back(fProcessesToBias[i]);
}


void TsInelasticSplitManager::Initialize() {
	SetGenericBiasing();
}


void TsInelasticSplitManager::SetGenericBiasing() {
	return;
}


G4GenericBiasingPhysics* TsInelasticSplitManager::GetGenericBiasingPhysics() {
	G4GenericBiasingPhysics* biasingPhysics = new G4GenericBiasingPhysics();
	for ( int i = 0; i < fNbOfParticles; i++ )
		biasingPhysics->PhysicsBias(fParticlesToBias[i], fProcessToBias);
	
    return biasingPhysics;
}


void TsInelasticSplitManager::Clear() {
	return;
}
