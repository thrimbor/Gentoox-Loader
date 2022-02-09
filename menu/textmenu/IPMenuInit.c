/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "include/config.h"
#include "TextMenu.h"

#include "VideoInitialization.h"
#include "IPMenuActions.h"

TEXTMENU *IPMenuInit(void) {
	
	TEXTMENUITEM *itemPtr;
	TEXTMENU *menuPtr;
	
	//Create the root menu - MANDATORY
	menuPtr = malloc(sizeof(TEXTMENU));
	strcpy(menuPtr->szCaption, "IP:Port Selection (A.B.C.D:P)");
	menuPtr->firstMenuItem=NULL;

	// Connect
	itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
	memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
	strcpy(itemPtr->szCaption, "Connect");
	itemPtr->functionPtr= enableHttpc;
	itemPtr->functionDataPtr = NULL ;
	TextMenuAddItem(menuPtr, itemPtr);
	
	// A
	itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
	memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
	sprintf(itemPtr->szCaption, "%s %i", "A: ", NB_BLOCK_A);
	itemPtr->functionPtr=incrementNumberA;
	itemPtr->functionDataPtr = itemPtr->szCaption;
	TextMenuAddItem(menuPtr, itemPtr);

	// B
	itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
	memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
	sprintf(itemPtr->szCaption, "%s %i", "B: ", NB_BLOCK_B);
	itemPtr->functionPtr=incrementNumberB;
	itemPtr->functionDataPtr = itemPtr->szCaption;
	TextMenuAddItem(menuPtr, itemPtr);

	// C
	itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
	memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
	sprintf(itemPtr->szCaption, "%s %i", "C: ", NB_BLOCK_C);
	itemPtr->functionPtr=incrementNumberC;
	itemPtr->functionDataPtr = itemPtr->szCaption;
	TextMenuAddItem(menuPtr, itemPtr);

	// D
	itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
	memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
	sprintf(itemPtr->szCaption, "%s %i", "D: ", NB_BLOCK_D);
	itemPtr->functionPtr=incrementNumberD;
	itemPtr->functionDataPtr = itemPtr->szCaption;
	TextMenuAddItem(menuPtr, itemPtr);

	// P
	itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
	memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
	sprintf(itemPtr->szCaption, "%s %i", "P: ", NB_PORT);
	itemPtr->functionPtr=incrementNumberP;
	itemPtr->functionDataPtr = itemPtr->szCaption;
	TextMenuAddItem(menuPtr, itemPtr);

	return menuPtr;
}
