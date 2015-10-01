// =============================================================================
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2014 projectchrono.org
// All right reserved.
//
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file at the top level of the distribution and at
// http://projectchrono.org/license-chrono.txt.
//
// =============================================================================
// Authors: Radu Serban
// =============================================================================
//
// Utility functions to facilitate adding contact and visualization geometry to
// a body.
//
// =============================================================================

#ifndef CH_UTILS_CREATORS_H
#define CH_UTILS_CREATORS_H

#include <cmath>
#include <vector>
#include <string>

#include "core/ChApiCE.h"
#include "core/ChSmartpointers.h"
#include "core/ChVector.h"
#include "core/ChQuaternion.h"

#include "physics/ChSystem.h"
#include "physics/ChSystemDEM.h"
#include "physics/ChBody.h"
#include "physics/ChMaterialSurface.h"
#include "physics/ChMaterialSurfaceDEM.h"

#include "assets/ChColorAsset.h"
#include "assets/ChSphereShape.h"
#include "assets/ChEllipsoidShape.h"
#include "assets/ChBoxShape.h"
#include "assets/ChCapsuleShape.h"
#include "assets/ChCylinderShape.h"
#include "assets/ChConeShape.h"
#include "assets/ChTriangleMeshShape.h"
#include "assets/ChRoundedBoxShape.h"
#include "assets/ChRoundedConeShape.h"
#include "assets/ChRoundedCylinderShape.h"
#include "assets/ChLineShape.h"

#include "collision/ChCModelBullet.h"
#include "collision/ChCConvexDecomposition.h"

namespace chrono {
namespace utils {

// -----------------------------------------------------------------------------
// AddSphereGeometry
// AddEllipsoidGeometry
// AddBoxGeometry
// AddCapsuleGeometry
// AddCylinderGeometry
// AddConeGeometry
// AddTriangleMeshGeometry
// AddRoundedBoxGeometry
// AddRoundedCylinderGeometry
// AddTorusGeometry
//
// Utility functions for adding contact and asset geometry shapes to a body
// -----------------------------------------------------------------------------
ChApi
void AddSphereGeometry(ChBody* body,
                       double radius,
                       const ChVector<>& pos = ChVector<>(0, 0, 0),
                       const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                       bool visualization = true);

ChApi
void AddEllipsoidGeometry(ChBody* body,
                          const ChVector<>& size,
                          const ChVector<>& pos = ChVector<>(0, 0, 0),
                          const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                          bool visualization = true);

ChApi
void AddBoxGeometry(ChBody* body,
                    const ChVector<>& size,
                    const ChVector<>& pos = ChVector<>(0, 0, 0),
                    const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                    bool visualization = true);

ChApi
void AddCapsuleGeometry(ChBody* body,
                        double radius,
                        double hlen,
                        const ChVector<>& pos = ChVector<>(0, 0, 0),
                        const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                        bool visualization = true);

ChApi
void AddCylinderGeometry(ChBody* body,
                         double radius,
                         double hlen,
                         const ChVector<>& pos = ChVector<>(0, 0, 0),
                         const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                         bool visualization = true);

ChApi
void AddConeGeometry(ChBody* body,
                     double radius,
                     double height,
                     const ChVector<>& pos = ChVector<>(0, 0, 0),
                     const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                     bool visualization = true);

ChApi
void AddTriangleMeshGeometry(ChBody* body,
                             const std::string& obj_filename,
                             const std::string& name,
                             const ChVector<>& pos = ChVector<>(0, 0, 0),
                             const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                             bool visualization = true);

ChApi
void AddTriangleMeshConvexDecomposition(ChBody* body,
                                        const std::string& obj_filename,
                                        const std::string& name,
                                        const ChVector<>& pos = ChVector<>(0, 0, 0),
                                        const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                                        double skin_thickness = 0,
                                        bool use_original_asset = true);

ChApi
void AddTriangleMeshConvexDecompositionV2(ChBody* body,
                                          const std::string& obj_filename,
                                          const std::string& name,
                                          const ChVector<>& pos = ChVector<>(0, 0, 0),
                                          const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                                          bool use_original_asset = true);

ChApi
void AddTriangleMeshConvexDecompositionSplit(ChSystem* system,
                                             const std::string& obj_filename,
                                             const std::string& name,
                                             const ChVector<>& pos,
                                             const ChQuaternion<>& rot,
                                             ChSharedPtr<ChMaterialSurface> material,
                                             double total_mass);

ChApi
void AddRoundedBoxGeometry(ChBody* body,
                           const ChVector<>& size,
                           double srad,
                           const ChVector<>& pos = ChVector<>(0, 0, 0),
                           const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                           bool visualization = true);

ChApi
void AddRoundedCylinderGeometry(ChBody* body,
                                double radius,
                                double hlen,
                                double srad,
                                const ChVector<>& pos = ChVector<>(0, 0, 0),
                                const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                                bool visualization = true);

// Creates a compound torus shape using cylinders
ChApi
void AddTorusGeometry(ChBody* body,
                      double radius,
                      double thickness,
                      int segments = 20,
                      int angle = 360,
                      const ChVector<>& pos = ChVector<>(0, 0, 0),
                      const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                      bool visualization = true);

// -----------------------------------------------------------------------------
// CreateBoxContainer
// InitializeObject
// FinalizeObject
// LoadConvex
// AddConvex
//
// Utility functions for creating objects
// -----------------------------------------------------------------------------

// Create a fixed body with contact and asset geometry representing a box with 5
// walls (no top).
ChApi
ChSharedPtr<ChBody> CreateBoxContainer(ChSystem* system,
                                       int id,
                                       ChSharedPtr<ChMaterialSurfaceBase> mat,
                                       const ChVector<>& hdim,
                                       double hthick,
                                       const ChVector<>& pos = ChVector<>(0, 0, 0),
                                       const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                                       bool collide = true,
                                       bool y_up = false,
                                       bool overlap = false,
                                       bool closed = false);

// -----------------------------------------------------------------------------
// CreateCylindricalContainerFromBoxes
// InitializeObject
// FinalizeObject
// LoadConvex
// AddConvex
//
// Utility functions for creating objects
// -----------------------------------------------------------------------------

// Create a cylindrical container body with contact and asset geometry representing a cylindrical container
// represented by boxes.
// The container is aligned with the z direction. The position refers to the center of the bottom inner circle.
// Only half of the cylinder is visualized.
ChApi
ChSharedPtr<ChBody> CreateCylindricalContainerFromBoxes(ChSystem* system,
                                                        int id,
                                                        ChSharedPtr<ChMaterialSurfaceBase> mat,
                                                        const ChVector<>& hdim,
                                                        double hthick,
                                                        int numBoxes,
                                                        double rho,
                                                        double collisionEnvelope,
                                                        const ChVector<>& pos = ChVector<>(0, 0, 0),
                                                        const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                                                        bool collide = true,
                                                        bool overlap = false,
                                                        bool closed = false,
                                                        bool isBoxBase = true);

ChApi
void InitializeObject(ChSharedPtr<ChBody> body,
                      double mass,
                      ChSharedPtr<ChMaterialSurfaceBase> mat,
                      const ChVector<>& pos = ChVector<>(0, 0, 0),
                      const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                      bool collide = true,
                      bool fixed = false,
                      int collision_family = 2,
                      int do_not_collide_with = 4);

ChApi
void FinalizeObject(ChSharedPtr<ChBody> body, ChSystem* system);

// Given a file containing an obj, this function will load the obj file into a
// mesh and generate its convex decomposition
ChApi
void LoadConvexMesh(const std::string& file_name,
                    geometry::ChTriangleMeshConnected& convex_mesh,
                    collision::ChConvexDecompositionHACDv2& convex_shape,
                    const ChVector<>& pos = ChVector<>(0, 0, 0),
                    const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                    int hacd_maxhullcount = 1024,
                    int hacd_maxhullmerge = 256,
                    int hacd_maxhullvertexes = 64,
                    double hacd_concavity = 0.01,
                    double hacd_smallclusterthreshold = 0.0,
                    double hacd_fusetolerance = 1e-6);

// Given a convex mesh and it's decomposition add it to a ChBody
// use_original_asset can be used to specify if the mesh or the convex decomp
// should be used for visualization
ChApi
void AddConvexCollisionModel(ChSharedPtr<ChBody> body,
                             geometry::ChTriangleMeshConnected& convex_mesh,
                             collision::ChConvexDecompositionHACDv2& convex_shape,
                             const ChVector<>& pos = ChVector<>(0, 0, 0),
                             const ChQuaternion<>& rot = ChQuaternion<>(1, 0, 0, 0),
                             bool use_original_asset = true);

}  // end namespace utils
}  // end namespace chrono

#endif
