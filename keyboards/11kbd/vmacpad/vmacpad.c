/*
 Copyright 2023 max3-2
*/

#include "quantum.h"

led_config_t g_led_config = { {
	{ 0       , 4              , NO_LED         , 5              , NO_LED },
	{ 1       , NO_LED         , NO_LED         , NO_LED         , NO_LED },
	{ NO_LED  , NO_LED         , 2              , NO_LED         , NO_LED },
	{ 3       , NO_LED         , NO_LED         , NO_LED         , NO_LED }
}, {
// Positions
	{ 18,   13},
    { 18,   26},
    { 18,   39},
    { 18,   52},

	{   100,  6}, {  170,  6}
}, {
	4,
    4,
    4,
    4,
    2,
    2
} };
