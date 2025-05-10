#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"

void Player_Action_41(Player* this, PlayState* play);
bool func_808313A8(PlayState* play, Player* this, Actor* actor);
void func_8083D6DC(Player* this, PlayState* play);
s32 Player_SetAction(PlayState* play, Player* this, PlayerActionFunc actionFunc, s32 arg3);
s32 Player_CanThrowCarriedActor(Player* this, Actor* heldActor);
void Player_Anim_PlayOnce(PlayState* play, Player* this, PlayerAnimationHeader* anim);
extern PlayerAnimationHeader* D_8085BE84[PLAYER_ANIMGROUP_MAX][PLAYER_ANIMTYPE_MAX];

RECOMP_PATCH s32 Player_ActionHandler_9(Player* this, PlayState* play) {
    if (this->stateFlags1 & PLAYER_STATE1_CARRYING_ACTOR) {
        if (this->heldActor != NULL) {
                if (CHECK_BTN_ANY(play->state.input->press.button, BTN_CRIGHT | BTN_CLEFT | BTN_CDOWN | BTN_A)) {
                    if (!func_808313A8(play, this, this->heldActor)) {
                        func_8083D6DC(this, play);
                    }
                    return true;
                }
                else if (CHECK_BTN_ANY(play->state.input->press.button, BTN_B)) {
                    if (!func_808313A8(play, this, this->heldActor)) {
                        Player_SetAction(play, this, Player_Action_41, 1);
                        Player_Anim_PlayOnce(play, this, D_8085BE84[PLAYER_ANIMGROUP_put][this->modelAnimType]);
                        return true;
                    }
                }
        }
    }
    return false;
}