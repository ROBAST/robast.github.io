// Author: Akira Okumura <mailto:oxon@mac.com>
/******************************************************************************
 * Copyright (C) 2006-, Akira Okumura                                         *
 * All rights reserved.                                                       *
 *****************************************************************************/

#ifndef A_OPTICAL_COMPONENT_H
#define A_OPTICAL_COMPONENT_H

#include "ABorderSurfaceCondition.h"
#include "TGeoVolume.h"
#include "TObjArray.h"

///////////////////////////////////////////////////////////////////////////////
//
// AOpticalComponent
//
// Abstract class for optical components
//
///////////////////////////////////////////////////////////////////////////////

class AOpticalComponent : public TGeoVolume {
 private:
  TObjArray* fBorderSurfaceConditionArray;

 public:
  AOpticalComponent();
  AOpticalComponent(const char* name, const TGeoShape* shape,
                    const TGeoMedium* med = 0);
  virtual ~AOpticalComponent();

  void AddBorderSurfaceCondition(ABorderSurfaceCondition* condition);
  ABorderSurfaceCondition* FindBorderSurfaceCondition(
      AOpticalComponent* component2);
  TGeoMaterial* GetOpaqueVacuumMaterial() const;
  TGeoMaterial* GetTransparentVacuumMaterial() const;
  TGeoMedium* GetOpaqueVacuumMedium() const;
  TGeoMedium* GetTransparentVacuumMedium() const;

  ClassDef(AOpticalComponent, 1)
};

#endif  // A_OPTICAL_COMPONENT_H
