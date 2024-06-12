//###########################################################################
//
// FILE:   debug.h
//
// TITLE:  Assert definition macro for debug.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.3 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

#ifndef DEBUG_H
#define DEBUG_H

//*****************************************************************************
//
// Prototype for the function that is called when an invalid argument is passed
// to an API.  This is only used when doing a DEBUG build. It is the
// application's responsibility to define the __error__ function.
//
//*****************************************************************************
extern void __error__(char *filename, uint32_t line);

//*****************************************************************************
//
// The ASSERT macro, which does the actual assertion checking.  Typically, this
// will be for procedure arguments.
//
//*****************************************************************************
#ifdef DEBUG
#define ASSERT(expr) do                                                       \
                     {                                                        \
                         if(!(expr))                                          \
                         {                                                    \
                             __error__(__FILE__, __LINE__);                   \
                         }                                                    \
                     }                                                        \
                     while(0)
#else
#define ASSERT(expr)
#endif

#endif // DEBUG_H
