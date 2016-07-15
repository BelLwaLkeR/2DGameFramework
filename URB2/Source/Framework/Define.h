#pragma once

#if defined(DEBUG) || defined(_DEBUG)
#define DEBUG_MODE
#endif // DEBUG || _DEBUG

#define USE_KEYBOARD_NUM	1
#define USE_PAD_NUM			12
#define INPUT_NUM			USE_KEYBOARD_NUM + USE_PAD_NUM
