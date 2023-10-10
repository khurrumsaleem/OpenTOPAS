//
// ********************************************************************
// *                                                                  *
// *                                                                  *
// * This file was obtained from Topas MC Inc under the license       *
// * agreement set forth at http://www.topasmc.org/registration       *
// * Any use of this file constitutes full acceptance of              *
// * this TOPAS MC license agreement.                                 *
// *                                                                  *
// ********************************************************************
//

#ifndef MyScoreCharge_hh
#define MyScoreCharge_hh

#include "TsVBinnedScorer.hh"

class MyScoreCharge : public TsVBinnedScorer
{
public:
	MyScoreCharge(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM, TsExtensionManager *eM,
						 G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	virtual ~MyScoreCharge();

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);
};
#endif
