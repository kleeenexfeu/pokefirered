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
