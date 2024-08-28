#ifndef GUARD_ITEM_MENU_ICONS_H
#define GUARD_ITEM_MENU_ICONS_H

extern const struct CompressedSpriteSheet gSpriteSheet_BagMale;
extern const struct CompressedSpriteSheet gSpriteSheet_BagFemale;
extern const struct CompressedSpritePalette gSpritePalette_Bag;
extern const struct CompressedSpriteSheet gBagSwapSpriteSheet;
extern const struct CompressedSpritePalette gBagSwapSpritePalette;

void ResetItemMenuIconState(void);
void CreateItemMenuSwapLine(void);
void RemoveBagItemIconSprite(bool8 a0);
void AddBagItemIconSprite(u16 itemId, bool8 a0);
void CreateBerryPouchItemIcon(u16 itemId, u8 idx);
void UpdateItemMenuSwapLinePos(s16 x, u16 y);
void SetItemMenuSwapLineInvisibility(bool8 invisible);
void SetBagVisualPocketId(u8);
void ShakeBagSprite(void);
void AddBagVisualSprite(u8 animNum);

#endif // GUARD_ITEM_MENU_ICONS_H