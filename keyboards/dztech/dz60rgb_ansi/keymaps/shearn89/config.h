#pragma once

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define AUTO_SHIFT_TIMEOUT 140
#define NO_AUTO_SHIFT_SPECIAL

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
