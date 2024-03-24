#include "global.h"
#include "gflib.h"
#include "battle_anim.h"
#include "decompress.h"
#include "digit_obj_util.h"
#include "dynamic_placeholder_text_util.h"
#include "event_data.h"
#include "item.h"
#include "link.h"
#include "link_rfu.h"
#include "menu.h"
#include "minigame_countdown.h"
#include "new_menu_helpers.h"
#include "pokemon_jump.h"
#include "random.h"
#include "save.h"
#include "script.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "trig.h"
#include "constants/items.h"
#include "constants/songs.h"

#include "util.h"
#include "random.h"
#include "pokedex.h"
#include "money.h"
#include "pokemon_icon.h"
#include "mail.h"
#include "event_data.h"
#include "strings.h"
#include "pokemon_special_anim.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
#include "task.h"
#include "naming_screen.h"
#include "overworld.h"
#include "party_menu.h"
#include "trainer_pokemon_sprites.h"
#include "field_specials.h"
#include "battle.h"
#include "pokemon_jump.h"
#include "battle_message.h"
#include "battle_anim.h"
#include "battle_ai_script_commands.h"
#include "battle_scripts.h"
#include "reshow_battle_screen.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "constants/battle_anim.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_script_commands.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"
#include "constants/abilities.h"
#include "constants/pokemon.h"
#include "constants/maps.h"



/*
A lot of space have been save in this file, it can now be used
to store many functions if needed.
*/


static void SendLinkData_Leader(void); // REFERENCES
static void SendLinkData_Member(void); // REFERENCES
static bool32 ExitGame(void); // REFERENCES ??
static bool32 DoGameIntro(void); // REFERENCES
static bool32 TryGivePrize(void); // REFERENCES
static void Task_CommunicateMonInfo(u8 taskId); // REFERENCES
static u16 GetPrizeItemId(void); // REFERENCES
static void Msg_WantToPlayAgain(void); // REFERENCES
static void Msg_SavingDontTurnOff(void); // REFERENCES
static void EraseMessage(void); // REFERENCES
static void Msg_SomeoneDroppedOut(void); // REFERENCES
static void Msg_CommunicationStandby(void); // REFERENCES
static void DrawPlayerNameWindows(void); // REFERENCES ??
static void SpriteCB_Star(struct Sprite *sprite); // REFERENCES
static void TruncateToFirstWordOnly(u8 *str); // LAST FUNCTION OF THE FILE, KEEPING IT FOR NOW
static void PrintRecordsText(u16 windowId); // REFERENCES ??
static bool32 TryUpdateRecords(u32, u16, u16); // REFERENCES ??

// Deleting things would make things in the RAM move, so we keep 'em
EWRAM_DATA static struct PokemonJump *sPokemonJump = NULL;
EWRAM_DATA static struct PokemonJumpGfx *sPokemonJumpGfx = NULL; // EWRAM DATA, DON'T DELETE

bool32 ProteanActivation(void)
{
    u32 moveType;
    GET_MOVE_TYPE(gCurrentMove, moveType);

    if (
    gBattleMons[gBattlerAttacker].ability == ABILITY_PROTEAN
    && (gBattleMons[gBattlerAttacker].type1 != moveType || gBattleMons[gBattlerAttacker].type2 != moveType)
    && gCurrentMove != MOVE_STRUGGLE
    )
    {
        PREPARE_TYPE_BUFFER(gBattleTextBuff1, moveType);
        SET_BATTLER_TYPE(gBattlerAttacker, moveType);
        gLastUsedAbility = ABILITY_PROTEAN;
        gBattleScripting.battler = gBattlerAttacker;
        RecordAbilityBattle(gBattlerAttacker, gLastUsedAbility);
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_ColorChangeActivates;
        return TRUE;
    } 
    else
       return FALSE;
}

bool8 AccuracyCalcHelper(u16 move)
{
    if (gStatuses3[gBattlerTarget] & STATUS3_ALWAYS_HITS && gDisableStructs[gBattlerTarget].battlerWithSureHit == gBattlerAttacker)
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    if (!(gHitMarker & HITMARKER_IGNORE_ON_AIR) && gStatuses3[gBattlerTarget] & STATUS3_ON_AIR)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    gHitMarker &= ~HITMARKER_IGNORE_ON_AIR;

    if (!(gHitMarker & HITMARKER_IGNORE_UNDERGROUND) && gStatuses3[gBattlerTarget] & STATUS3_UNDERGROUND)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    gHitMarker &= ~HITMARKER_IGNORE_UNDERGROUND;

    if (!(gHitMarker & HITMARKER_IGNORE_UNDERWATER) && gStatuses3[gBattlerTarget] & STATUS3_UNDERWATER)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    gHitMarker &= ~HITMARKER_IGNORE_UNDERWATER;

    if ((WEATHER_HAS_EFFECT && (gBattleWeather & B_WEATHER_RAIN) && gBattleMoves[move].effect == EFFECT_THUNDER)
     || (WEATHER_HAS_EFFECT && (gBattleWeather & B_WEATHER_HAIL) && move == MOVE_BLIZZARD)
     || (gBattleMoves[move].effect == EFFECT_ALWAYS_HIT || gBattleMoves[move].effect == EFFECT_VITAL_THROW))
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    return FALSE;
}

void StartPokemonJump(u16 partyId, MainCallback exitCallback)
{
    // REFERENCES
}
static void RecvLinkData_Leader(void)
{
    // REFERENCES
}
static void SendLinkData_Leader(void)
{
    // REFERENCES
}
static void RecvLinkData_Member(void)
{
    // REFERENCES
}
static void SendLinkData_Member(void)
{
    // REFERENCES
}
static bool32 ExitGame(void)
{
    // REFERENCES
}
static bool32 DoGameIntro(void)
{
    // REFERENCES
}
static bool32 TryGivePrize(void)
{
    // REFERENCES
}
static void Task_CommunicateMonInfo(u8 taskId)
{
    // REFERENCES
}
static u16 GetPrizeItemId(void)
{
    // REFERENCES
}
bool32 IsSpeciesAllowedInPokemonJump(u16 species)
{
    return 1; // REFERENCES
}
static void Msg_WantToPlayAgain(void)
{
    // REFERENCES
}
static void Msg_SavingDontTurnOff(void)
{
    // REFERENCES
}
static void EraseMessage(void)
{
    // REFERENCES
}
static void Msg_SomeoneDroppedOut(void)
{
    // REFERENCES
}
static void Msg_CommunicationStandby(void)
{
    // REFERENCES
}
static void DrawPlayerNameWindows(void)
{
    // REFERENCES ??
}
static void SpriteCB_Star(struct Sprite *sprite)
{
    // REFERENCES
}
void ResetPokemonJumpRecords(void)
{
    // REFERENCES
}
static bool32 TryUpdateRecords(u32 jumpScore, u16 jumpsInRow, u16 excellentsInRow)
{
    // REFERENCES ??
}
static void PrintRecordsText(u16 windowId)
{
    // REFERENCES
}

void IsPokemonJumpSpeciesInParty(void) // SPECIAL ?
{
    gSpecialVar_Result = FALSE;
}

void ShowPokemonJumpRecords(void)
{
    // REFERENCES ??
}

asm(".org . + ((0x14B6D4 - 0x1475C0) - .) ");
static void TruncateToFirstWordOnly(u8 *str)
{
    for (;*str != EOS; str++)
    {
        if (*str == CHAR_SPACE)
        {
            *str = EOS;
            break;
        }
    }
    // LAST FUNCTIONS, KEEPING IT
}
