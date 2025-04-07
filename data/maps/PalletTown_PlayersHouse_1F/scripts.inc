# 1 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 2 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
.equ LOCALID_MOM, 1
# 3 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 4 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_MapScripts::
# 5 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	.byte 0
# 6 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 7 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_EventScript_Mom::
# 8 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	lock
# 9 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	faceplayer
# 10 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	goto_if_set FLAG_BEAT_RIVAL_IN_OAKS_LAB, PalletTown_PlayersHouse_1F_EventScript_MomHeal
# 11 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	checkplayergender
# 12 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale
# 13 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale
# 14 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 15 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_FaceOriginalDirection
# 16 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 17 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	release
# 18 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	end
# 19 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 20 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale::
# 21 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou
# 22 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	return
# 23 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 24 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale::
# 25 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou
# 26 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	return
# 27 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 28 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_EventScript_MomHeal::
# 29 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest
# 30 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 31 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	call EventScript_OutOfCenterPartyHeal
# 32 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare
# 33 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	release
# 34 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	end
# 35 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 36 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
@ Displays special text if interacted with from side or back (which are normally inaccessible)
# 37 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_EventScript_TV::
# 38 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	lockall
# 39 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	goto_if_eq VAR_FACING, DIR_NORTH, PalletTown_PlayersHouse_1F_EventScript_TVScreen
# 40 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_OopsWrongSide
# 41 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	releaseall
# 42 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	end
# 43 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 44 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_EventScript_TVScreen::
# 45 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	checkplayergender
# 46 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenMale
# 47 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale
# 48 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	releaseall
# 49 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	end
# 50 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 51 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_EventScript_TVScreenMale::
# 52 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad
# 53 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	return
# 54 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 55 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale::
# 56 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad
# 57 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	return

PalletTown_PlayersHouse_1F_EventScript_MomRunningShoes::
# 61 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	lock
# 62 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 63 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	setvar VAR_MOM_RUNNING_SHOES, 1
# 64 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	playse SE_PIN
# 65 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
# 66 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 67 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	delay 80
# 68 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	applymovement LOCALID_MOM, PalletTown_PlayersHouse_1F_Movement_MomGiveShoesMovement
# 69 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 70 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_PlayersHouse_1F_Movement_FaceUp
# 71 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 72 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	delay 80
# 73 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 74 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_MomRunningShoes1, MSGBOX_NPC
# 75 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 76 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 77 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_TriedOnRunningShoes
# 78 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 79 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 80 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_MomRunningShoes2, MSGBOX_NPC
# 81 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	applymovement LOCALID_MOM, PalletTown_PlayersHouse_1F_Movement_MomReturn
# 82 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 83 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 84 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	release
	return


# 87 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_Movement_MomGiveShoesMovement:
# 88 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 88 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 89 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_left
# 89 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_left
# 89 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_left
# 89 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_left
# 90 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	face_down
	step_end

# 93 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_Movement_MomReturn:
# 94 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 94 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 94 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 94 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 95 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_up
# 95 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_up
# 96 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	face_left
	step_end

# 99 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_Movement_FaceUp:
# 100 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	face_up
	step_end
