/*!
\file
\brief Lab2_Sem2 Header
\author Rybin Aleksandr 1 course 2 half
\date 05.04.2017
\version 1.0
*/

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


/*!
\brief Push element in stek
\param[in] stek Pointer to stek vector
\param[in] index Pointer to index of end of stek vector
\param[in] element Object to push
\return void
\ingroup Stek
*/
void push(int* stek, int* index,int element);

/*!
\brief Pop element from stek
\param[in] stek Pointer to stek vector
\param[in] index Pointer to index of end of stek vector
\return tmp Last object in stek
\ingroup Stek
*/
int pop(int* stek, int* index);
