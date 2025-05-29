#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"

void Player_Action_41(Player* this, PlayState* play);
bool func_808313A8(PlayState* play, Player* this, Actor* actor);
void func_8083D6DC(Player* this, PlayState* play);
s32 Player_SetAction(PlayState* play, Player* this, PlayerActionFunc actionFunc, s32 arg3);
void Player_Anim_PlayOnce(PlayState* play, Player* this, PlayerAnimationHeader* anim);
extern PlayerAnimationHeader* D_8085BE84[PLAYER_ANIMGROUP_MAX][PLAYER_ANIMTYPE_MAX];

Player* gThis;
PlayState* gPlay;

RECOMP_HOOK("Player_ActionHandler_9") s32 Player_ActionHandler_9_Hook(Player* this, PlayState* play) {
    gThis = this;
    gPlay = play;
}

RECOMP_HOOK_RETURN("Player_ActionHandler_9") s32 Player_ActionHandler_9_Return() {
    if (CHECK_BTN_ANY(gPlay->state.input->press.button, BTN_A)) {
        if (!func_808313A8(gPlay, gThis, gThis->heldActor)) {
            func_8083D6DC(gThis, gPlay);
        }
    }
    else if (CHECK_BTN_ANY(gPlay->state.input->press.button, BTN_B)) {
        if (!func_808313A8(gPlay, gThis, gThis->heldActor)) {
            Player_SetAction(gPlay, gThis, Player_Action_41, 1);
            Player_Anim_PlayOnce(gPlay, gThis, D_8085BE84[PLAYER_ANIMGROUP_put][gThis->modelAnimType]);
        }
    }
}