//
// Created by scott on 9/6/2017.
//

#ifndef GUARD_FIELD_GROUND_EFFECT_H
#define GUARD_FIELD_GROUND_EFFECT_H

#include "global.h"

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
void SetObjectSubpriorityByZCoord(u8, struct Sprite *, u8);
void InitObjectPriorityByZCoord(struct Sprite *, u8);
bool8 IsZCoordMismatchAt(u8, s16, s16);
bool8 AreZCoordsCompatible(u8, u8);
void FieldObjectUpdateSubpriority(struct EventObject *, struct Sprite *);
void DoGroundEffects_OnSpawn(struct EventObject *, struct Sprite *);
void DoGroundEffects_OnBeginStep(struct EventObject *, struct Sprite *);
void DoGroundEffects_OnFinishStep(struct EventObject *, struct Sprite *);

#endif //GUARD_FIELD_GROUND_EFFECT_H
