#ifndef GUARD_FAME_CHECKER_H
#define GUARD_FAME_CHECKER_H

#include "main.h"

enum {
    FAMECHECKER_OAK,
    FAMECHECKER_DAISY,
    FAMECHECKER_BROCK,
    FAMECHECKER_MISTY,
    FAMECHECKER_LTSURGE,
    FAMECHECKER_ERIKA,
    FAMECHECKER_KOGA,
    FAMECHECKER_SABRINA,
    FAMECHECKER_BLAINE,
    FAMECHECKER_LORELEI,
    FAMECHECKER_BRUNO,
    FAMECHECKER_AGATHA,
    FAMECHECKER_LANCE,
    FAMECHECKER_BILL,
    FAMECHECKER_MRFUJI,
    FAMECHECKER_GIOVANNI,
    NUM_FAMECHECKER_PERSONS
};

enum {
    FCPICKSTATE_NO_DRAW,
    FCPICKSTATE_SILHOUETTE,
    FCPICKSTATE_COLORED
};

enum {
    FCWINDOWID_LIST,
    FCWINDOWID_UIHELP,
    FCWINDOWID_MSGBOX,
    FCWINDOWID_ICONDESC
};

extern struct ListMenuTemplate gFameChecker_ListMenuTemplate;
extern u8 gIconDescriptionBoxIsOpen;

void ResetFameChecker(void);
void FullyUnlockFameChecker(void);
void UseFameChecker(MainCallback savedCallback);
void SetFlavorTextFlagFromSpecialVars(void);
void UpdatePickStateFromSpecialVar8005(void);

#endif //GUARD_FAME_CHECKER_H
