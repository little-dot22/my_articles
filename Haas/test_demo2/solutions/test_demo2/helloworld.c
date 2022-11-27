#include <stdio.h>
#include <stdlib.h>
#include <aos/errno.h>
#include <aos/kernel.h>
#include "aos/init.h"
#include "board.h"
#include <k_api.h>
#include "key.h"
#include "led.h"

int k = 0;

void key_short_pressed()
{
    if (k%2 == 0) led_switch(1, LED_ON);
    else led_switch(1, LED_OFF);
    k++;
}
 
 
void key_long_pressed()
{
    if (k%2 == 0) led_switch(1, LED_ON);
    else led_switch(1, LED_OFF);
    k++;
}
 
 
void key_test_init()
{
    key_cfg_t cfg;
    cfg.short_press_handler = key_short_pressed;
    cfg.long_press_handler  = key_long_pressed;
    cfg.long_press_min_ms   = 3;
    cfg.short_press_max_ms  = 1;
    key_init(&cfg);
}
 
 
int application_start(int argc, char *argv[])
{
    printf("key test entry here!\r\n");
 
    key_test_init();
 
    while(1) {
        aos_msleep(1000);
    };
 
}