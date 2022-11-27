# 1 实验目的
HaaS100 开发板板载了六颗 LED 灯，任选其中一个作为指示灯，实现每当用户按下NETWORK 配网键，改变灯的亮灭状态一次。
# 2 实验原理
## 2.1 按键驱动
Haas100提供的按键驱动接口如下所示：

    typedef struct {
    
        uint32_t short_press_max_ms;   // default 2000
    
        uint32_t long_press_min_ms;    // default 5000
    
        void (*short_press_handler)(void);
    
        void (*long_press_handler)(void);
    
    } key_cfg_t;

    int key_init(key_cfg_t *cfg);
这里可以自定义长按短按的触发时间，考虑到本实验不涉及长按短按的区别，故触发时间均调至极短，且长按短按的回调函数相同。
## 2.2 LED驱动
Haas100提供的LED驱动接口如下所示：

    typedef enum {
        LED_OFF,
        LED_ON
    } led_e;
    
    void led_switch(int id, led_e onoff);
函数的第一个参数是LED的编号，第二个参数控制亮暗。
# 3 主要代码
    #include <stdio.h>
    #include <stdlib.h>
    #include <aos/errno.h>
    #include <aos/kernel.h>
    #include "aos/init.h"
    #include "board.h"
    #include <k_api.h>
    #include "key.h"
    #include "led.h"

    int k = 0;      // 设置全局变量k控制1号LED的亮暗

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
# 4 实验结果
程序正常编译烧录后，用户按下NETWORK配网键，灯的亮灭状态会改变一次。