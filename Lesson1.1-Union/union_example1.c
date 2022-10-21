// Lesson1.1-Union.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#define SIZE 20
union MarketItem
{
	struct Skill { int damage, coolDown; } skillObj;
	struct Armor { float defence; } armorObj;
	struct Weapon { int power; char type[SIZE]; } weaponObj;
}storeObj
;
void main()
{
	union MarketItem newItem = { 51, 52 };
	storeObj.skillObj.damage = 50;
	storeObj.skillObj.coolDown = 10;

	storeObj.weaponObj.power = 100;
	strcpy(storeObj.weaponObj.type, "Sward");
	printf("Memory size occupied by storeObj : %llu\n", sizeof(storeObj));
	printf("Memory size occupied by newItem : %llu\n", sizeof(newItem));

}
