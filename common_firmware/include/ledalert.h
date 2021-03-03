/*
 * LED Sequence player
 *
 * Copyright (C) 4var1/beemac, 2020.
 *
 * Released under the GPL License, Version 3
 */
#include "stdint.h"

#define LED_CLOCK_MS 50

// LED Sequence command defines\macros

#define LED_RED 1
#define LED_GREEN 2
#define LED_BLUE 4
#define LED_MAGENTA LED_BLUE | LED_RED
#define LED_CYAN LED_BLUE | LED_GREEN
#define LED_YELLOW LED_RED | LED_GREEN
#define LED_WHITE LED_BLUE | LED_RED | LED_GREEN
#define LED_OFF 0
#define LED_END_SEQUENCE 253
#define LED_REPEAT_LASTX 254
#define WAIT_MS(a) ((a) / (LED_CLOCK_MS))
#define CMDS_RPT(a, b) ((a) + (16 * (b))) //Repeat last x commands - next value last x-1 commands to repeat (0-15) plus 16*number of times - so max is repeat last 16 commands 16 times

// Define sequences here
// Sequence commands are 2 bytes each - first is the colour or other instruction, 2nd is either time to show for LED - or parameter for command.
// End sequences with two LED_END_SEQUENCE
// can loop previous commands with LED_REPEAT_LASTX, CMDS_RPT(2,10) where the two values are the number of previous commands to repeat,how many times.
// Don't nest loops in led sequences, there is no stack!

#define LED_NUM_SEQUENCES 54 //Update when new sequences are added
#define LED_MAX_COMMANDS_IN_SEQUENCE 16

static const uint8_t ui8_led_sequences[LED_NUM_SEQUENCES][LED_MAX_COMMANDS_IN_SEQUENCE * 2] = {

    {LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(0), LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_SHORT_GREEN

    {LED_RED, WAIT_MS(200), LED_OFF, WAIT_MS(0), LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_SHORT_RED

    {LED_BLUE, WAIT_MS(200), LED_OFF, WAIT_MS(0), LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_SHORT_BLUE

    {LED_YELLOW, WAIT_MS(200), LED_OFF, WAIT_MS(0), LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_SHORT_YELLOW

    {LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(0), LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_BLUEFLASH_1

    {LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(50), LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(0), LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_BLUEFLASH_2

    {LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(50), LED_REPEAT_LASTX, CMDS_RPT(2, 1), LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_BLUEFLASH_3

    {LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(50), LED_REPEAT_LASTX, CMDS_RPT(2, 2), LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_BLUEFLASH_4

    {LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(50), LED_REPEAT_LASTX, CMDS_RPT(2, 3), LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_BLUEFLASH_5

    {LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(50), LED_REPEAT_LASTX, CMDS_RPT(2, 4), LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_BLUEFLASH_6

    {LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(50), LED_REPEAT_LASTX, CMDS_RPT(2, 5), LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_BLUEFLASH_7

    {LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(50), LED_REPEAT_LASTX, CMDS_RPT(2, 6), LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_BLUEFLASH_8

    {LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(50), LED_REPEAT_LASTX, CMDS_RPT(2, 7), LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_BLUEFLASH_9

    {LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(50), LED_REPEAT_LASTX, CMDS_RPT(2, 8), LED_BLUE, WAIT_MS(50), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_BLUEFLASH_10

    {LED_YELLOW, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 9), LED_YELLOW, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_YELLOW_SLOWFLASH_10;

    {LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 4), LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_GREEN_SLOWFLASH_5;

    {LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 2), LED_GREEN, WAIT_MS(750), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_GREEN_SLOWFLASH_2_LONGGREEN;

    {LED_RED, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 5), LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_RED_SLOWFLASH_5;

    {LED_RED, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 2), LED_RED, WAIT_MS(750), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_RED_SLOWFLASH_2_LONGRED;

    {LED_WHITE, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 2), LED_GREEN, WAIT_MS(750), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_WHITE_SLOWFLASH_2_LONGGREEN;

    {LED_WHITE, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 2), LED_RED, WAIT_MS(750), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_WHITE_SLOWFLASH_2_LONGRED;

    {LED_GREEN, WAIT_MS(50), LED_OFF, WAIT_MS(0), LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_GREENFLASH_1

    {LED_RED, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_YELLOW, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_GREEN, WAIT_MS(750), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_RED_YELLOW_LONGGREEN

    {LED_BLUE, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 2), LED_GREEN, WAIT_MS(750), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_BLUE_SLOWFLASH_2_LONGGREEN;

    {LED_BLUE, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 2), LED_RED, WAIT_MS(750), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_BLUE_SLOWFLASH_2_LONGRED;

    {LED_RED, WAIT_MS(50), LED_OFF, WAIT_MS(50), LED_REPEAT_LASTX, CMDS_RPT(2, 2), LED_RED, WAIT_MS(50), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_REDFLASH_3

    {LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(200),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_GREEN_SLOWFLASH_1;

    {LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 1), LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_GREEN_SLOWFLASH_2;

    {LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 2), LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_GREEN_SLOWFLASH_3;

    {LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 3), LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_GREEN_SLOWFLASH_4;

    {LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 5), LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_GREEN_SLOWFLASH_6;

    {LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 6), LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_GREEN_SLOWFLASH_7;

    {LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 7), LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_GREEN_SLOWFLASH_8;

    {LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 8), LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_GREEN_SLOWFLASH_9;

    {LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 9), LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_GREEN_SLOWFLASH_10;

    {LED_RED, WAIT_MS(750), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 3), LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_LONGRED_LONGRED_LONGRED;

    {LED_OFF, WAIT_MS(1000), LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_OFF_1S

    {LED_RED, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_REDSLOWFLASH_1

    {LED_RED, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_RED, WAIT_MS(50), LED_OFF, WAIT_MS(0), LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_REDSLOWFLASH_2

    {LED_RED, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 2), LED_RED, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_REDSLOWFLASH_3

    {LED_YELLOW, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 3), LED_YELLOW, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_YELLOWSLOWFLASH_4

    {LED_YELLOW, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 4), LED_YELLOW, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_YELLOWSLOWFLASH_5

    {LED_YELLOW, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 5), LED_YELLOW, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_YELLOWSLOWFLASH_6

    {LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 6), LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_GREENSLOWFLASH_7

    {LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 7), LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_GREENSLOWFLASH_8

    {LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 8), LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_GREENSLOWFLASH_9

    {LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 9), LED_GREEN, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_GREENSLOWFLASH_10

    {LED_RED, WAIT_MS(750), LED_OFF, WAIT_MS(200), LED_GREEN, WAIT_MS(750), LED_OFF, WAIT_MS(200), LED_BLUE, WAIT_MS(750), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_LONGRED_LONGGREEN_LONGBLUE

    {LED_YELLOW, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_YELLOW_SLOWFLASH

    {LED_YELLOW, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 2), LED_GREEN, WAIT_MS(750), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_YELLOW_SLOWFLASH_2_LONGGREEN;

    {LED_YELLOW, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_REPEAT_LASTX, CMDS_RPT(2, 2), LED_RED, WAIT_MS(750), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_YELLOW_SLOWFLASH_2_LONGRED;

    {LED_RED, WAIT_MS(200), LED_OFF, WAIT_MS(200), LED_BLUE, WAIT_MS(200), LED_OFF, WAIT_MS(0),
     LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_SHORTRED_SHORTBLUE

    {LED_RED, WAIT_MS(5000), LED_OFF, WAIT_MS(0), LED_END_SEQUENCE, LED_END_SEQUENCE}, //LED_SEQUENCE_EXTRA_LONGRED

    {LED_OFF, WAIT_MS(100), LED_END_SEQUENCE, LED_END_SEQUENCE} //LED_SEQUENCE_OFF_100MS
};

// ui8_sequence
#define LED_SEQUENCE_SHORT_GREEN 0
#define LED_SEQUENCE_SHORT_RED 1
#define LED_SEQUENCE_SHORT_BLUE 2
#define LED_SEQUENCE_SHORT_YELLOW 3
#define LED_SEQUENCE_BLUEFLASH_1 4
#define LED_SEQUENCE_BLUEFLASH_2 5
#define LED_SEQUENCE_BLUEFLASH_3 6
#define LED_SEQUENCE_BLUEFLASH_4 7
#define LED_SEQUENCE_BLUEFLASH_5 8
#define LED_SEQUENCE_BLUEFLASH_6 9
#define LED_SEQUENCE_BLUEFLASH_7 10
#define LED_SEQUENCE_BLUEFLASH_8 11
#define LED_SEQUENCE_BLUEFLASH_9 12
#define LED_SEQUENCE_BLUEFLASH_10 13
#define LED_SEQUENCE_YELLOW_SLOWFLASH_10 14
#define LED_SEQUENCE_GREEN_SLOWFLASH_5 15
#define LED_SEQUENCE_GREEN_SLOWFLASH_2_LONGGREEN 16
#define LED_SEQUENCE_RED_SLOWFLASH_5 17
#define LED_SEQUENCE_RED_SLOWFLASH_2_LONGRED 18
#define LED_SEQUENCE_WHITE_SLOWFLASH_2_LONGGREEN 19
#define LED_SEQUENCE_WHITE_SLOWFLASH_2_LONGRED 20
#define LED_SEQUENCE_GREENFLASH_1 21
#define LED_SEQUENCE_RED_YELLOW_LONGGREEN 22
#define LED_SEQUENCE_BLUE_SLOWFLASH_2_LONGGREEN 23
#define LED_SEQUENCE_BLUE_SLOWFLASH_2_LONGRED 24
#define LED_SEQUENCE_REDFLASH_3 25
#define LED_SEQUENCE_GREEN_SLOWFLASH_1 26
#define LED_SEQUENCE_GREEN_SLOWFLASH_2 27
#define LED_SEQUENCE_GREEN_SLOWFLASH_3 28
#define LED_SEQUENCE_GREEN_SLOWFLASH_4 29
#define LED_SEQUENCE_GREEN_SLOWFLASH_6 30
#define LED_SEQUENCE_GREEN_SLOWFLASH_7 31
#define LED_SEQUENCE_GREEN_SLOWFLASH_8 32
#define LED_SEQUENCE_GREEN_SLOWFLASH_9 33
#define LED_SEQUENCE_GREEN_SLOWFLASH_10 34
#define LED_SEQUENCE_LONGRED_LONGRED_LONGRED 35
#define LED_SEQUENCE_OFF_1S 36
#define LED_SEQUENCE_REDSLOWFLASH_1 37
#define LED_SEQUENCE_REDSLOWFLASH_2 38
#define LED_SEQUENCE_REDSLOWFLASH_3 39
#define LED_SEQUENCE_YELLOWSLOWFLASH_4 40
#define LED_SEQUENCE_YELLOWSLOWFLASH_5 41
#define LED_SEQUENCE_YELLOWSLOWFLASH_6 42
#define LED_SEQUENCE_GREENSLOWFLASH_7 43
#define LED_SEQUENCE_GREENSLOWFLASH_8 44
#define LED_SEQUENCE_GREENSLOWFLASH_9 45
#define LED_SEQUENCE_GREENSLOWFLASH_10 46
#define LED_SEQUENCE_LONGRED_LONGGREEN_LONGBLUE 47
#define LED_SEQUENCE_YELLOW_SLOWFLASH 48
#define LED_SEQUENCE_YELLOW_SLOWFLASH_2_LONGGREEN 49
#define LED_SEQUENCE_YELLOW_SLOWFLASH_2_LONGRED 50
#define LED_SEQUENCE_SHORTRED_SHORTBLUE 51
#define LED_SEQUENCE_EXTRA_LONGRED 52
#define LED_SEQUENCE_OFF_100MS 53

#define LED_EVENT_WIRELESS_BOARD_POWER_ON LED_SEQUENCE_RED_YELLOW_LONGGREEN
#define LED_EVENT_BLUETOOTH_CONNECT LED_SEQUENCE_BLUE_SLOWFLASH_2_LONGGREEN
#define LED_EVENT_BLUETOOTH_DISCONNECT LED_SEQUENCE_BLUE_SLOWFLASH_2_LONGRED
#define LED_EVENT_MOTOR_ON_WAIT LED_SEQUENCE_SHORTRED_SHORTBLUE //LED_SEQUENCE_SHORT_YELLOW
#define LED_EVENT_MOTOR_ON_COMPLETE LED_SEQUENCE_GREEN_SLOWFLASH_2
#define LED_EVENT_MOTOR_OFF LED_SEQUENCE_RED_SLOWFLASH_2_LONGRED
#define LED_EVENT_LIGHTS_OFF LED_SEQUENCE_WHITE_SLOWFLASH_2_LONGRED
#define LED_EVENT_LIGHTS_ON LED_SEQUENCE_WHITE_SLOWFLASH_2_LONGGREEN
#define LED_EVENT_ASSIST_LIMITS_REACHED LED_SEQUENCE_SHORT_RED //LED_SEQUENCE_REDFLASH_3
#define LED_EVENT_ASSIST_LEVEL_DECREASE LED_SEQUENCE_SHORT_GREEN
#define LED_EVENT_ASSIST_LEVEL_INCREASE LED_SEQUENCE_SHORT_GREEN
#define LED_EVENT_WALK_ASSIST_ACTIVE LED_SEQUENCE_SHORT_GREEN
#define LED_EVENT_ANT_CONNECT LED_SEQUENCE_GREEN_SLOWFLASH_2_LONGGREEN
#define LED_EVENT_ANT_DISCONNECT LED_SEQUENCE_SHORT_RED
#define LED_EVENT_ENTER_DFU LED_SEQUENCE_BLUEFLASH_10
#define LED_EVENT_CONFIGURATION_MODE LED_SEQUENCE_BLUEFLASH_10
#define LED_EVENT_SHORT_GREEN LED_SEQUENCE_SHORT_GREEN
#define LED_EVENT_SHORT_RED LED_SEQUENCE_SHORT_RED
#define LED_EVENT_SHORT_BLUE LED_SEQUENCE_SHORT_BLUE
#define LED_EVENT_CONFIG_LEV_ACTIVE LED_SEQUENCE_RED_SLOWFLASH_5
#define LED_EVENT_CONFIG_CTRL_ACTIVE LED_SEQUENCE_GREEN_SLOWFLASH_5
#define LED_EVENT_BATTERY_SOC_0_PERCENT LED_SEQUENCE_OFF_1S
#define LED_EVENT_BATTERY_SOC_10_PERCENT LED_SEQUENCE_REDSLOWFLASH_1
#define LED_EVENT_BATTERY_SOC_20_PERCENT LED_SEQUENCE_REDSLOWFLASH_2
#define LED_EVENT_BATTERY_SOC_30_PERCENT LED_SEQUENCE_REDSLOWFLASH_3
#define LED_EVENT_BATTERY_SOC_40_PERCENT LED_SEQUENCE_YELLOWSLOWFLASH_4
#define LED_EVENT_BATTERY_SOC_50_PERCENT LED_SEQUENCE_YELLOWSLOWFLASH_5
#define LED_EVENT_BATTERY_SOC_60_PERCENT LED_SEQUENCE_YELLOWSLOWFLASH_6
#define LED_EVENT_BATTERY_SOC_70_PERCENT LED_SEQUENCE_GREENSLOWFLASH_7
#define LED_EVENT_BATTERY_SOC_80_PERCENT LED_SEQUENCE_GREENSLOWFLASH_8
#define LED_EVENT_BATTERY_SOC_90_PERCENT LED_SEQUENCE_GREENSLOWFLASH_9
#define LED_EVENT_BATTERY_SOC_100_PERCENT LED_SEQUENCE_GREENSLOWFLASH_10
#define LED_EVENT_WAIT_1S LED_SEQUENCE_OFF_1S
#define LED_EVENT_DEEP_SLEEP LED_SEQUENCE_RED_YELLOW_LONGGREEN
#define LED_EVENT_BRIGHTNESS_CHECK LED_SEQUENCE_RED_YELLOW_LONGGREEN
#define LED_EVENT_STREET_MODE_OFF LED_SEQUENCE_YELLOW_SLOWFLASH_2_LONGRED
#define LED_EVENT_STREET_MODE_ON LED_SEQUENCE_YELLOW_SLOWFLASH_2_LONGGREEN

// Deprecated - please use the equivalents below
// extern void led_init(void);                                             // call this to setup app timers
// extern void led_alert(uint8_t ui8_sequence);                            // call this to queue and play a sequence - e.g. led_alert(LED_SEQUENCE_SHORT_GREEN);
// extern void led_clear_queue(void);                                      // used if you want to play a sequence right now. clear the queue then the next thing you play is up now.
// extern void led_hold_queue(void);                                       // Used to keep the current sequence playing until you release the queue
// extern void led_release_queue(void);                                    // Go back to normal - play the queue as it happens
// extern void led_set_global_brightness(uint8_t ui8_global_brightness);   // Default is 1 - lowest. 3 currently is highest.

void led_init(void);                                           // call this to setup app timers
void led_sequence_play(uint8_t ui8_sequence);                  // call this to queue and play a sequence - e.g. led_sequence_play(LED_SEQUENCE_SHORT_GREEN);
void led_sequence_play_next(uint8_t ui8_sequence);             // used if you want to play a sequence next in the queue - clears queue and plays
void led_sequence_play_next_until(uint8_t ui8_sequence);       // used if you want to play a repeating sequence next in the queue - clears queue and plays a repeating sequence
void led_sequence_play_now(uint8_t ui8_sequence);              // used if you want to play a sequence now - stops current sequence and plays
void led_sequence_play_now_until(uint8_t ui8_sequence);        // used if you want to play a sequence now - stops current sequence and plays a repeating sequence
void led_sequence_cancel_play_until();                         // Cancel repeating sequence
void led_set_global_brightness(uint8_t ui8_global_brightness); // Default is 1 - lowest 'on'. 7 currently is highest. 0 will switch leds off
//void led_clear_queue_and_stop_current_sequence(void);
