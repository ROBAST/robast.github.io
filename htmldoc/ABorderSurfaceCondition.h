/******************************************************************************
 * Copyright (C) 2006-, Akira Okumura                                         *
 * All rights reserved.                                                       *
 *****************************************************************************/

#ifndef A_BORDER_SURFACE_CONDITION_H
#define A_BORDER_SURFACE_CONDITION_H

///////////////////////////////////////////////////////////////////////////////
//
// ABorderSurfaceCondition
//
// Defines the condition of the boarder surface between two volumes. Works as
// G4LogicalBorderSurface + G4OpticalSurface in Geant4.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef ROOT_TObject
#include "TObject.h"
#endif

class AOpticalComponent;

class ABorderSurfaceCondition : public TObject {
private:
  AOpticalComponent* fComponent[2];
  Double_t           fSigma;

public:
  ABorderSurfaceCondition(AOpticalComponent* component1, AOpticalComponent* component2);
  virtual ~ABorderSurfaceCondition();

  const AOpticalComponent* GetComponent1() const {return fComponent[0];}
  const AOpticalComponent* GetComponent2() const {return fComponent[1];}
  Double_t                 GetGaussianRoughness() const {return fSigma;}
  void                     SetGaussianRoughness(Double_t sigma /* (rad) */);

  ClassDef(ABorderSurfaceCondition, 1)
};

#endif // A_BORDER_SURFACE_CONDITION_H
