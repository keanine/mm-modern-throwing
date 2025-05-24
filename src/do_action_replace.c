#include "DAH_header.h"

bool Action_Drop_Replace(CONDITION_PARAMETERS) {
    Actor* heldActor = this->heldActor;

    if ((this->stateFlags1 & PLAYER_STATE1_CARRYING_ACTOR) && (this->getItemId == GI_NONE) &&
        (heldActor != NULL)) {
            if ((this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) || (heldActor->id == ACTOR_EN_NIW)) {
                *doAction = DO_ACTION_THROW;
                return true;
            }
        }
    return false;
}

bool Attack_Drop(CONDITION_PARAMETERS) {
    Actor* heldActor = this->heldActor;

    if ((this->stateFlags1 & PLAYER_STATE1_CARRYING_ACTOR) && (this->getItemId == GI_NONE) &&
        (heldActor != NULL)) {
            if ((this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) || (heldActor->id == ACTOR_EN_NIW)) {
                *doAction = DO_ACTION_DROP;
                return true;
            }
        }
    return false;
}

DAH_ON_INIT void DAH_on_init() {
    DoActionHelper_RegisterAction(ACTION, Action_Drop_Replace, 146, "Modern Throwing");
    DoActionHelper_RegisterAction(ATTACK_GORON, Attack_Drop, 32, "Modern Throwing");
    DoActionHelper_RegisterAction(ATTACK_ZORA, Attack_Drop, 32, "Modern Throwing");
    DoActionHelper_RegisterAction(ATTACK_DEKU, Attack_Drop, 32, "Modern Throwing");
    DoActionHelper_RegisterAction(ATTACK_HUMAN, Attack_Drop, 32, "Modern Throwing");
}