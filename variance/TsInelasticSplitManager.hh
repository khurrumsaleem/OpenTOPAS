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

#ifndef TsInelasticSplitManager_hh
#define TsInelasticSplitManager_hh

#include "TsVBiasingProcess.hh"

#include <vector>

class TsParameterManager;
class TsGeometryManager;
class G4GenericBiasingPhysics;

class TsInelasticSplitManager : public TsVBiasingProcess
{
public:
	TsInelasticSplitManager(G4String name, TsParameterManager*, TsGeometryManager*);
	~TsInelasticSplitManager();

	void ResolveParameters();
	void Initialize();
	void Clear();
	void SetGenericBiasing(); 
	void AddBiasingProcess() { return; };
	
	G4GenericBiasingPhysics* GetGenericBiasingPhysics();
	G4String GetTypeName() { return fType;};
	
private:
	TsParameterManager* fPm;

	G4String fName;
	G4String fType;
		
	G4int fNbOfParticles;
	G4String* fProcessesToBias;
	G4String* fParticlesToBias;
	std::vector<G4String> fProcessToBias;
};
#endif
