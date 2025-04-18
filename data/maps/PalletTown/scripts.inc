# 1 "data/maps/PalletTown/scripts.pory"

# 2 "data/maps/PalletTown/scripts.pory"
.equ LOCALID_SIGN_LADY, 1
# 3 "data/maps/PalletTown/scripts.pory"
.equ LOCALID_PROF_OAK,  3
# 4 "data/maps/PalletTown/scripts.pory"

# 5 "data/maps/PalletTown/scripts.pory"
.equ SIGN_LADY_READY, VAR_TEMP_2
# 6 "data/maps/PalletTown/scripts.pory"

# 7 "data/maps/PalletTown/scripts.pory"
PalletTown_MapScripts::
# 8 "data/maps/PalletTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
# 9 "data/maps/PalletTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_OnFrame
# 10 "data/maps/PalletTown/scripts.pory"
	.byte 0
# 11 "data/maps/PalletTown/scripts.pory"

# 12 "data/maps/PalletTown/scripts.pory"
PalletTown_OnTransition::
# 13 "data/maps/PalletTown/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_PALLET_TOWN
# 14 "data/maps/PalletTown/scripts.pory"
	call_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_TryReadySignLady
# 15 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 0, PalletTown_EventScript_SetSignLadyPos
# 16 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, PalletTown_EventScript_SetSignLadyDone
# 17 "data/maps/PalletTown/scripts.pory"
	end
# 18 "data/maps/PalletTown/scripts.pory"

# 19 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_TryReadySignLady::
# 20 "data/maps/PalletTown/scripts.pory"
	goto_if_unset FLAG_OPENED_START_MENU, EventScript_Return
# 21 "data/maps/PalletTown/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, EventScript_Return
# 22 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 23 "data/maps/PalletTown/scripts.pory"
	return
# 24 "data/maps/PalletTown/scripts.pory"

# 25 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SetSignLadyDone::
# 26 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2
# 27 "data/maps/PalletTown/scripts.pory"
	return
# 28 "data/maps/PalletTown/scripts.pory"

# 29 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SetSignLadyPos::
# 30 "data/maps/PalletTown/scripts.pory"
	goto_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_MoveSignLadyToRouteEntrance
# 31 "data/maps/PalletTown/scripts.pory"
	setobjectxyperm LOCALID_SIGN_LADY, 5, 15
# 32 "data/maps/PalletTown/scripts.pory"
	setobjectmovementtype LOCALID_SIGN_LADY, MOVEMENT_TYPE_FACE_UP
# 33 "data/maps/PalletTown/scripts.pory"
	return
# 34 "data/maps/PalletTown/scripts.pory"

# 35 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_MoveSignLadyToRouteEntrance::
# 36 "data/maps/PalletTown/scripts.pory"
	setobjectxyperm LOCALID_SIGN_LADY, 12, 2
# 37 "data/maps/PalletTown/scripts.pory"
	setobjectmovementtype LOCALID_SIGN_LADY, MOVEMENT_TYPE_FACE_DOWN
# 38 "data/maps/PalletTown/scripts.pory"
	setvar SIGN_LADY_READY, TRUE
# 39 "data/maps/PalletTown/scripts.pory"
	return
# 40 "data/maps/PalletTown/scripts.pory"

# 41 "data/maps/PalletTown/scripts.pory"
PalletTown_OnFrame::
# 42 "data/maps/PalletTown/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_OAK, 2, PalletTown_EventScript_OakRatingScene
# 43 "data/maps/PalletTown/scripts.pory"
	.2byte 0
# 44 "data/maps/PalletTown/scripts.pory"

# 45 "data/maps/PalletTown/scripts.pory"
@ Oak approaches player after exiting their house post Elite Four to check if they should receieve the National Dex
# 46 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakRatingScene::
# 47 "data/maps/PalletTown/scripts.pory"
	lockall
# 48 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 49 "data/maps/PalletTown/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 14, 14
# 50 "data/maps/PalletTown/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_LEFT
# 51 "data/maps/PalletTown/scripts.pory"
	addobject LOCALID_PROF_OAK
# 52 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToPlayersDoor
# 53 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 54 "data/maps/PalletTown/scripts.pory"
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, PalletTown_EventScript_NotBeenToOneIslandYet
# 55 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakLetMeSeePokedex
# 56 "data/maps/PalletTown/scripts.pory"
	setvar VAR_0x8004, 0
# 57 "data/maps/PalletTown/scripts.pory"
	specialvar VAR_RESULT, GetPokedexCount
# 58 "data/maps/PalletTown/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 59 "data/maps/PalletTown/scripts.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 60 "data/maps/PalletTown/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8008
# 61 "data/maps/PalletTown/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8009
# 62 "data/maps/PalletTown/scripts.pory"
	goto_if_lt VAR_0x8009, 60, PalletTown_EventScript_NotEnoughMonsForNationalDex
# 63 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CaughtXImpressiveFollowMe
# 64 "data/maps/PalletTown/scripts.pory"
	closemessage
# 65 "data/maps/PalletTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 66 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabFromHouse
# 67 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabFromHouse
# 68 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 69 "data/maps/PalletTown/scripts.pory"
	opendoor 16, 13
# 70 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 71 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLab
# 72 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 73 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 74 "data/maps/PalletTown/scripts.pory"
	closedoor 16, 13
# 75 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 76 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7
# 77 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
# 78 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 79 "data/maps/PalletTown/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 80 "data/maps/PalletTown/scripts.pory"
	waitstate
# 81 "data/maps/PalletTown/scripts.pory"
	releaseall
# 82 "data/maps/PalletTown/scripts.pory"
	end
# 83 "data/maps/PalletTown/scripts.pory"

# 84 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_EndOakRatingScene::
# 85 "data/maps/PalletTown/scripts.pory"
	closemessage
# 86 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakExit
# 87 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 88 "data/maps/PalletTown/scripts.pory"
	removeobject LOCALID_PROF_OAK
# 89 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
# 90 "data/maps/PalletTown/scripts.pory"
	releaseall
# 91 "data/maps/PalletTown/scripts.pory"
	end
# 92 "data/maps/PalletTown/scripts.pory"

# 93 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_NotEnoughMonsForNationalDex::
# 94 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CaughtXPuttingInHonestEffort
# 95 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_EndOakRatingScene
# 96 "data/maps/PalletTown/scripts.pory"
	end
# 97 "data/maps/PalletTown/scripts.pory"

# 98 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_NotBeenToOneIslandYet::
# 99 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakYouEnjoyingTraveling
# 100 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_EndOakRatingScene
# 101 "data/maps/PalletTown/scripts.pory"
	end
# 102 "data/maps/PalletTown/scripts.pory"

# 103 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToPlayersDoor::
# 104 "data/maps/PalletTown/scripts.pory"
	walk_left
# 105 "data/maps/PalletTown/scripts.pory"
	walk_left
# 106 "data/maps/PalletTown/scripts.pory"
	walk_left
# 107 "data/maps/PalletTown/scripts.pory"
	walk_up
# 108 "data/maps/PalletTown/scripts.pory"
	walk_up
# 109 "data/maps/PalletTown/scripts.pory"
	walk_up
# 110 "data/maps/PalletTown/scripts.pory"
	walk_up
# 111 "data/maps/PalletTown/scripts.pory"
	walk_up
# 112 "data/maps/PalletTown/scripts.pory"
	walk_left
# 113 "data/maps/PalletTown/scripts.pory"
	walk_left
# 114 "data/maps/PalletTown/scripts.pory"
	walk_left
# 115 "data/maps/PalletTown/scripts.pory"
	walk_left
# 116 "data/maps/PalletTown/scripts.pory"
	walk_left
# 117 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 118 "data/maps/PalletTown/scripts.pory"
	step_end
# 119 "data/maps/PalletTown/scripts.pory"

# 120 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakExit::
# 121 "data/maps/PalletTown/scripts.pory"
	walk_right
# 122 "data/maps/PalletTown/scripts.pory"
	walk_right
# 123 "data/maps/PalletTown/scripts.pory"
	walk_right
# 124 "data/maps/PalletTown/scripts.pory"
	walk_right
# 125 "data/maps/PalletTown/scripts.pory"
	walk_right
# 126 "data/maps/PalletTown/scripts.pory"
	walk_down
# 127 "data/maps/PalletTown/scripts.pory"
	walk_down
# 128 "data/maps/PalletTown/scripts.pory"
	walk_down
# 129 "data/maps/PalletTown/scripts.pory"
	walk_down
# 130 "data/maps/PalletTown/scripts.pory"
	walk_down
# 131 "data/maps/PalletTown/scripts.pory"
	walk_right
# 132 "data/maps/PalletTown/scripts.pory"
	walk_right
# 133 "data/maps/PalletTown/scripts.pory"
	walk_right
# 134 "data/maps/PalletTown/scripts.pory"
	step_end
# 135 "data/maps/PalletTown/scripts.pory"

# 136 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabFromHouse::
# 137 "data/maps/PalletTown/scripts.pory"
	walk_right
# 138 "data/maps/PalletTown/scripts.pory"
	walk_right
# 139 "data/maps/PalletTown/scripts.pory"
	walk_right
# 140 "data/maps/PalletTown/scripts.pory"
	walk_right
# 141 "data/maps/PalletTown/scripts.pory"
	walk_right
# 142 "data/maps/PalletTown/scripts.pory"
	walk_down
# 143 "data/maps/PalletTown/scripts.pory"
	walk_down
# 144 "data/maps/PalletTown/scripts.pory"
	walk_down
# 145 "data/maps/PalletTown/scripts.pory"
	walk_down
# 146 "data/maps/PalletTown/scripts.pory"
	walk_down
# 147 "data/maps/PalletTown/scripts.pory"
	walk_right
# 148 "data/maps/PalletTown/scripts.pory"
	walk_right
# 149 "data/maps/PalletTown/scripts.pory"
	walk_right
# 150 "data/maps/PalletTown/scripts.pory"
	walk_right
# 151 "data/maps/PalletTown/scripts.pory"
	walk_right
# 152 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 153 "data/maps/PalletTown/scripts.pory"
	step_end
# 154 "data/maps/PalletTown/scripts.pory"

# 155 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabFromHouse::
# 156 "data/maps/PalletTown/scripts.pory"
	walk_down
# 157 "data/maps/PalletTown/scripts.pory"
	walk_right
# 158 "data/maps/PalletTown/scripts.pory"
	walk_right
# 159 "data/maps/PalletTown/scripts.pory"
	walk_right
# 160 "data/maps/PalletTown/scripts.pory"
	walk_right
# 161 "data/maps/PalletTown/scripts.pory"
	walk_right
# 162 "data/maps/PalletTown/scripts.pory"
	walk_down
# 163 "data/maps/PalletTown/scripts.pory"
	walk_down
# 164 "data/maps/PalletTown/scripts.pory"
	walk_down
# 165 "data/maps/PalletTown/scripts.pory"
	walk_down
# 166 "data/maps/PalletTown/scripts.pory"
	walk_down
# 167 "data/maps/PalletTown/scripts.pory"
	walk_right
# 168 "data/maps/PalletTown/scripts.pory"
	walk_right
# 169 "data/maps/PalletTown/scripts.pory"
	walk_right
# 170 "data/maps/PalletTown/scripts.pory"
	walk_right
# 171 "data/maps/PalletTown/scripts.pory"
	step_end
# 172 "data/maps/PalletTown/scripts.pory"

# 173 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTriggerLeft::
# 174 "data/maps/PalletTown/scripts.pory"
	lockall
# 175 "data/maps/PalletTown/scripts.pory"
	setvar VAR_TEMP_1, 0
# 176 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_OakTrigger
# 177 "data/maps/PalletTown/scripts.pory"
	end
# 178 "data/maps/PalletTown/scripts.pory"

# 179 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTriggerRight::
# 180 "data/maps/PalletTown/scripts.pory"
	lockall
# 181 "data/maps/PalletTown/scripts.pory"
	setvar VAR_TEMP_1, 1
# 182 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_OakTrigger
# 183 "data/maps/PalletTown/scripts.pory"
	end
# 184 "data/maps/PalletTown/scripts.pory"

# 185 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTrigger::
# 186 "data/maps/PalletTown/scripts.pory"
	famechecker FAMECHECKER_OAK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
# 187 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 188 "data/maps/PalletTown/scripts.pory"
	delay 30
# 189 "data/maps/PalletTown/scripts.pory"
	playbgm MUS_OAK, 0
# 190 "data/maps/PalletTown/scripts.pory"
	message PalletTown_Text_OakDontGoOut
# 191 "data/maps/PalletTown/scripts.pory"
	waitmessage
# 192 "data/maps/PalletTown/scripts.pory"
	delay 85
# 193 "data/maps/PalletTown/scripts.pory"
	closemessage
# 194 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 195 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 196 "data/maps/PalletTown/scripts.pory"
	playse SE_PIN
# 197 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 198 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 199 "data/maps/PalletTown/scripts.pory"
	delay 30
# 200 "data/maps/PalletTown/scripts.pory"
	addobject LOCALID_PROF_OAK
# 201 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakEnterLeft
# 202 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakEnterRight
# 203 "data/maps/PalletTown/scripts.pory"
	delay 30
# 204 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakGrassUnsafeNeedMon
# 205 "data/maps/PalletTown/scripts.pory"
	closemessage
# 206 "data/maps/PalletTown/scripts.pory"
	delay 30
# 207 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakLeadPlayerToLabLeft
# 208 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakLeadPlayerToLabRight
# 209 "data/maps/PalletTown/scripts.pory"
	opendoor 27, 11
# 210 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 211 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLab
# 212 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 213 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 214 "data/maps/PalletTown/scripts.pory"
	closedoor 27, 11
# 215 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 216 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
# 217 "data/maps/PalletTown/scripts.pory"
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
# 218 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1
# 219 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 220 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 221 "data/maps/PalletTown/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 222 "data/maps/PalletTown/scripts.pory"
	waitstate
# 223 "data/maps/PalletTown/scripts.pory"
	releaseall
# 224 "data/maps/PalletTown/scripts.pory"
	end
# 225 "data/maps/PalletTown/scripts.pory"

# 226 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakEnterLeft::
# 227 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLeft
# 228 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 229 "data/maps/PalletTown/scripts.pory"
	return
# 230 "data/maps/PalletTown/scripts.pory"

# 231 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakEnterRight::
# 232 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterRight
# 233 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 234 "data/maps/PalletTown/scripts.pory"
	return
# 235 "data/maps/PalletTown/scripts.pory"

# 236 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakLeadPlayerToLabLeft::
# 237 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabLeft
# 238 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabLeft
# 239 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 240 "data/maps/PalletTown/scripts.pory"
	return
# 241 "data/maps/PalletTown/scripts.pory"

# 242 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakLeadPlayerToLabRight::
# 243 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabRight
# 244 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabRight
# 245 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 246 "data/maps/PalletTown/scripts.pory"
	return
# 247 "data/maps/PalletTown/scripts.pory"

# 248 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterLeft::
# 249 "data/maps/PalletTown/scripts.pory"
	walk_up
# 250 "data/maps/PalletTown/scripts.pory"
	walk_up
# 251 "data/maps/PalletTown/scripts.pory"
	walk_up
# 252 "data/maps/PalletTown/scripts.pory"
    walk_up
# 253 "data/maps/PalletTown/scripts.pory"
    walk_up
# 254 "data/maps/PalletTown/scripts.pory"
    walk_left
# 255 "data/maps/PalletTown/scripts.pory"
    walk_left
# 256 "data/maps/PalletTown/scripts.pory"
    walk_left
# 257 "data/maps/PalletTown/scripts.pory"
    walk_left
# 258 "data/maps/PalletTown/scripts.pory"
    walk_left
# 259 "data/maps/PalletTown/scripts.pory"
    walk_left
# 260 "data/maps/PalletTown/scripts.pory"
    walk_left
# 261 "data/maps/PalletTown/scripts.pory"
    walk_left
# 262 "data/maps/PalletTown/scripts.pory"
    walk_left
# 263 "data/maps/PalletTown/scripts.pory"
    step_end
# 264 "data/maps/PalletTown/scripts.pory"

# 265 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterRight::
# 266 "data/maps/PalletTown/scripts.pory"
	walk_up
# 267 "data/maps/PalletTown/scripts.pory"
    walk_up
# 268 "data/maps/PalletTown/scripts.pory"
	walk_up
# 269 "data/maps/PalletTown/scripts.pory"
	walk_up
# 270 "data/maps/PalletTown/scripts.pory"
    walk_up
# 271 "data/maps/PalletTown/scripts.pory"
    walk_up
# 272 "data/maps/PalletTown/scripts.pory"
    walk_left
# 273 "data/maps/PalletTown/scripts.pory"
    walk_left
# 274 "data/maps/PalletTown/scripts.pory"
    walk_left
# 275 "data/maps/PalletTown/scripts.pory"
    walk_left
# 276 "data/maps/PalletTown/scripts.pory"
    walk_left
# 277 "data/maps/PalletTown/scripts.pory"
    walk_left
# 278 "data/maps/PalletTown/scripts.pory"
    walk_left
# 279 "data/maps/PalletTown/scripts.pory"
    walk_left
# 280 "data/maps/PalletTown/scripts.pory"
    walk_left
# 281 "data/maps/PalletTown/scripts.pory"
    step_end
# 282 "data/maps/PalletTown/scripts.pory"

# 283 "data/maps/PalletTown/scripts.pory"
	.macro walk_to_lab
# 284 "data/maps/PalletTown/scripts.pory"
	walk_right
# 285 "data/maps/PalletTown/scripts.pory"
    walk_right
# 286 "data/maps/PalletTown/scripts.pory"
    walk_right
# 287 "data/maps/PalletTown/scripts.pory"
    walk_right
# 288 "data/maps/PalletTown/scripts.pory"
    walk_right
# 289 "data/maps/PalletTown/scripts.pory"
    walk_right
# 290 "data/maps/PalletTown/scripts.pory"
    walk_right
# 291 "data/maps/PalletTown/scripts.pory"
    walk_right
# 292 "data/maps/PalletTown/scripts.pory"
    walk_right
# 293 "data/maps/PalletTown/scripts.pory"
    walk_right
# 294 "data/maps/PalletTown/scripts.pory"
    walk_right
# 295 "data/maps/PalletTown/scripts.pory"
    walk_right
# 296 "data/maps/PalletTown/scripts.pory"
    walk_right
# 297 "data/maps/PalletTown/scripts.pory"
    walk_right
# 298 "data/maps/PalletTown/scripts.pory"
    walk_right
# 299 "data/maps/PalletTown/scripts.pory"
    walk_right
# 300 "data/maps/PalletTown/scripts.pory"
    walk_right
# 301 "data/maps/PalletTown/scripts.pory"
    walk_right
# 302 "data/maps/PalletTown/scripts.pory"
    walk_right
# 303 "data/maps/PalletTown/scripts.pory"
    walk_right
# 304 "data/maps/PalletTown/scripts.pory"
    walk_down
# 305 "data/maps/PalletTown/scripts.pory"
    walk_down
# 306 "data/maps/PalletTown/scripts.pory"
    walk_down
# 307 "data/maps/PalletTown/scripts.pory"
    walk_down
# 308 "data/maps/PalletTown/scripts.pory"
    walk_down
# 309 "data/maps/PalletTown/scripts.pory"
    walk_down
# 310 "data/maps/PalletTown/scripts.pory"
    walk_down
# 311 "data/maps/PalletTown/scripts.pory"
    walk_down
# 312 "data/maps/PalletTown/scripts.pory"
    walk_down
# 313 "data/maps/PalletTown/scripts.pory"
    walk_down
# 314 "data/maps/PalletTown/scripts.pory"
    walk_down
# 315 "data/maps/PalletTown/scripts.pory"
    walk_down
# 316 "data/maps/PalletTown/scripts.pory"
    walk_right
# 317 "data/maps/PalletTown/scripts.pory"
    walk_right
# 318 "data/maps/PalletTown/scripts.pory"
    walk_right
# 319 "data/maps/PalletTown/scripts.pory"
    walk_right
# 320 "data/maps/PalletTown/scripts.pory"
    walk_right
# 321 "data/maps/PalletTown/scripts.pory"
    walk_right
# 322 "data/maps/PalletTown/scripts.pory"
    walk_right
# 323 "data/maps/PalletTown/scripts.pory"
    walk_up
# 324 "data/maps/PalletTown/scripts.pory"
    walk_up
# 325 "data/maps/PalletTown/scripts.pory"
    walk_up
# 326 "data/maps/PalletTown/scripts.pory"
    walk_left
# 327 "data/maps/PalletTown/scripts.pory"
	.endm
# 328 "data/maps/PalletTown/scripts.pory"

# 329 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabLeft::
# 330 "data/maps/PalletTown/scripts.pory"
	walk_right
# 331 "data/maps/PalletTown/scripts.pory"
	walk_to_lab
# 332 "data/maps/PalletTown/scripts.pory"
	walk_left
# 333 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 334 "data/maps/PalletTown/scripts.pory"
	step_end
# 335 "data/maps/PalletTown/scripts.pory"

# 336 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabRight::
# 337 "data/maps/PalletTown/scripts.pory"
	walk_right
# 338 "data/maps/PalletTown/scripts.pory"
	walk_down
# 339 "data/maps/PalletTown/scripts.pory"
	walk_to_lab
# 340 "data/maps/PalletTown/scripts.pory"
	walk_left
# 341 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 342 "data/maps/PalletTown/scripts.pory"
	step_end
# 343 "data/maps/PalletTown/scripts.pory"

# 344 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterLab::
# 345 "data/maps/PalletTown/scripts.pory"
	walk_up
# 346 "data/maps/PalletTown/scripts.pory"
	set_invisible
# 347 "data/maps/PalletTown/scripts.pory"
	step_end
# 348 "data/maps/PalletTown/scripts.pory"

# 349 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabLeft::
# 350 "data/maps/PalletTown/scripts.pory"
	walk_right
# 351 "data/maps/PalletTown/scripts.pory"
    walk_right
# 352 "data/maps/PalletTown/scripts.pory"
	walk_to_lab
# 353 "data/maps/PalletTown/scripts.pory"
	step_end
# 354 "data/maps/PalletTown/scripts.pory"

# 355 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabRight::
# 356 "data/maps/PalletTown/scripts.pory"
	walk_right
# 357 "data/maps/PalletTown/scripts.pory"
    walk_right
# 358 "data/maps/PalletTown/scripts.pory"
	walk_down
# 359 "data/maps/PalletTown/scripts.pory"
	walk_to_lab
# 360 "data/maps/PalletTown/scripts.pory"
	step_end
# 361 "data/maps/PalletTown/scripts.pory"

# 362 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerEnterLab::
# 363 "data/maps/PalletTown/scripts.pory"
	walk_left
# 364 "data/maps/PalletTown/scripts.pory"
	walk_up
# 365 "data/maps/PalletTown/scripts.pory"
	set_invisible
# 366 "data/maps/PalletTown/scripts.pory"
	step_end
# 367 "data/maps/PalletTown/scripts.pory"

# 368 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLady::
# 369 "data/maps/PalletTown/scripts.pory"
	lock
# 370 "data/maps/PalletTown/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2, PalletTown_EventScript_SignLadyDone
# 371 "data/maps/PalletTown/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, PalletTown_EventScript_SignLadyJustShowedSign
# 372 "data/maps/PalletTown/scripts.pory"
	goto_if_eq SIGN_LADY_READY, TRUE, PalletTown_EventScript_SignLadyStartShowSign
# 373 "data/maps/PalletTown/scripts.pory"
	goto_if_set FLAG_TEMP_2, PalletTown_EventScript_SignLadyGoReadSign
# 374 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_HmmIsThatRight
# 375 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
# 376 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 377 "data/maps/PalletTown/scripts.pory"
	playse SE_PIN
# 378 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_ExclamationMark
# 379 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 380 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_Delay48
# 381 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 382 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OhLookLook
# 383 "data/maps/PalletTown/scripts.pory"
	closemessage
# 384 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_EventScript_SignLadyMoveOutOfWayRight
# 385 "data/maps/PalletTown/scripts.pory"
	call_if_ne VAR_FACING, DIR_EAST, PalletTown_EventScript_SignLadyMoveOutOfWayLeft
# 386 "data/maps/PalletTown/scripts.pory"
	copyobjectxytoperm LOCALID_SIGN_LADY
# 387 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_TEMP_2
# 388 "data/maps/PalletTown/scripts.pory"
	release
# 389 "data/maps/PalletTown/scripts.pory"
	end
# 390 "data/maps/PalletTown/scripts.pory"

# 391 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyMoveOutOfWayRight::
# 392 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayRight
# 393 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 394 "data/maps/PalletTown/scripts.pory"
	return
# 395 "data/maps/PalletTown/scripts.pory"

# 396 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyMoveOutOfWayLeft::
# 397 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayLeft
# 398 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 399 "data/maps/PalletTown/scripts.pory"
	return
# 400 "data/maps/PalletTown/scripts.pory"

# 401 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyDone::
# 402 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
# 403 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 404 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_RaisingMonsToo
# 405 "data/maps/PalletTown/scripts.pory"
	release
# 406 "data/maps/PalletTown/scripts.pory"
	end
# 407 "data/maps/PalletTown/scripts.pory"

# 408 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyGoReadSign::
# 409 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
# 410 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 411 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_ReadItReadIt
# 412 "data/maps/PalletTown/scripts.pory"
	release
# 413 "data/maps/PalletTown/scripts.pory"
	end
# 414 "data/maps/PalletTown/scripts.pory"

# 415 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyJustShowedSign::
# 416 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
# 417 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 418 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_SignsAreUsefulArentThey
# 419 "data/maps/PalletTown/scripts.pory"
	release
# 420 "data/maps/PalletTown/scripts.pory"
	end
# 421 "data/maps/PalletTown/scripts.pory"

# 422 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_SignLadyMoveOutOfWayRight::
# 423 "data/maps/PalletTown/scripts.pory"
	walk_right
# 424 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_left
# 425 "data/maps/PalletTown/scripts.pory"
	step_end
# 426 "data/maps/PalletTown/scripts.pory"

# 427 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_SignLadyMoveOutOfWayLeft::
# 428 "data/maps/PalletTown/scripts.pory"
	walk_left
# 429 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_right
# 430 "data/maps/PalletTown/scripts.pory"
	step_end
# 431 "data/maps/PalletTown/scripts.pory"

# 432 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_FatMan::
# 433 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CanStoreItemsAndMonsInPC, MSGBOX_NPC
# 434 "data/maps/PalletTown/scripts.pory"
	end
# 435 "data/maps/PalletTown/scripts.pory"

# 436 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OaksLabSign::
# 437 "data/maps/PalletTown/scripts.pory"
	lockall
# 438 "data/maps/PalletTown/scripts.pory"
	famechecker FAMECHECKER_OAK, 0
# 439 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakPokemonResearchLab
# 440 "data/maps/PalletTown/scripts.pory"
	releaseall
# 441 "data/maps/PalletTown/scripts.pory"
	end
# 442 "data/maps/PalletTown/scripts.pory"

# 443 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_PlayersHouseSign::
# 444 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
# 445 "data/maps/PalletTown/scripts.pory"
	end
# 446 "data/maps/PalletTown/scripts.pory"

# 447 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_RivalsHouseSign::
# 448 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
# 449 "data/maps/PalletTown/scripts.pory"
	end
# 450 "data/maps/PalletTown/scripts.pory"

# 451 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_TownSign::
# 452 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
# 453 "data/maps/PalletTown/scripts.pory"
	end
# 454 "data/maps/PalletTown/scripts.pory"

# 455 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_TrainerTips::
# 456 "data/maps/PalletTown/scripts.pory"
	lockall
# 457 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PressStartToOpenMenu
# 458 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 459 "data/maps/PalletTown/scripts.pory"
	releaseall
# 460 "data/maps/PalletTown/scripts.pory"
	end
# 461 "data/maps/PalletTown/scripts.pory"

# 462 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyTrigger::
# 463 "data/maps/PalletTown/scripts.pory"
	lockall
# 464 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_WalkInPlaceFasterRight
# 465 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 466 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 467 "data/maps/PalletTown/scripts.pory"
	call PalletTown_EventScript_SignLadyShowSign
# 468 "data/maps/PalletTown/scripts.pory"
	releaseall
# 469 "data/maps/PalletTown/scripts.pory"
	end
# 470 "data/maps/PalletTown/scripts.pory"

# 471 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyShowSign::
# 472 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 473 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_LookCopiedTrainerTipsSign
# 474 "data/maps/PalletTown/scripts.pory"
	closemessage
# 475 "data/maps/PalletTown/scripts.pory"
	delay 20
# 476 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 477 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_OPENED_START_MENU
# 478 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 479 "data/maps/PalletTown/scripts.pory"
	setvar SIGN_LADY_READY, FALSE
# 480 "data/maps/PalletTown/scripts.pory"
	special SetWalkingIntoSignVars
# 481 "data/maps/PalletTown/scripts.pory"
	special DisableMsgBoxWalkaway
# 482 "data/maps/PalletTown/scripts.pory"
	signmsg
# 483 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PressStartToOpenMenuCopy
# 484 "data/maps/PalletTown/scripts.pory"
	normalmsg
# 485 "data/maps/PalletTown/scripts.pory"
	return
# 486 "data/maps/PalletTown/scripts.pory"

# 487 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyStartShowSign::
# 488 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
# 489 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 490 "data/maps/PalletTown/scripts.pory"
	call PalletTown_EventScript_SignLadyShowSign
# 491 "data/maps/PalletTown/scripts.pory"
	release
# 492 "data/maps/PalletTown/scripts.pory"
	end

PalletTown_EventScript_GuardMan::
# 495 "data/maps/PalletTown/scripts.pory"
	lockall
# 496 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_GuardMan, MSGBOX_NPC
# 497 "data/maps/PalletTown/scripts.pory"
	releaseall
	return


PalletTown_EventScript_GuardTrigger::
# 501 "data/maps/PalletTown/scripts.pory"
	lock
# 502 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 503 "data/maps/PalletTown/scripts.pory"
	playse SE_PIN
# 504 "data/maps/PalletTown/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 505 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 506 "data/maps/PalletTown/scripts.pory"
	delay 80
# 507 "data/maps/PalletTown/scripts.pory"
	applymovement 4, PalletTown_Movement_FaceUp
# 508 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 509 "data/maps/PalletTown/scripts.pory"
	delay 80
# 510 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_GuardMan, MSGBOX_NPC
# 511 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_GuardManPlayer
# 512 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 513 "data/maps/PalletTown/scripts.pory"
	applymovement 4, PalletTown_Movement_FaceRight
# 514 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 515 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 516 "data/maps/PalletTown/scripts.pory"
	release
	return


# 519 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_GuardManPlayer:
# 520 "data/maps/PalletTown/scripts.pory"
	walk_right
# 520 "data/maps/PalletTown/scripts.pory"
	walk_right
	step_end

# 523 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_FaceDown:
# 524 "data/maps/PalletTown/scripts.pory"
	face_down
	step_end

# 527 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_FaceUp:
# 528 "data/maps/PalletTown/scripts.pory"
	face_up
	step_end

# 531 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_FaceRight:
# 532 "data/maps/PalletTown/scripts.pory"
	face_right
	step_end

PalletTown_EventScript_HideGuard::
# 536 "data/maps/PalletTown/scripts.pory"
	faceplayer
# 537 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_SEABREEZE_GUARD_MAN
# 538 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1
# 539 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_EventScript_HideGuard_Text_0
	return


PalletTown_EventScript_HideGuard_Text_0:
# 539 "data/maps/PalletTown/scripts.pory"
	.string "ok$"
