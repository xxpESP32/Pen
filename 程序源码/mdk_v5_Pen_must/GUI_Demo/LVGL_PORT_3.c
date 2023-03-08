#include "LVGL_PORT_3.h"

lv_obj_t* Don_game;
lv_obj_t* Don_src;
lv_obj_t* Obs_src;
lv_obj_t* Obs_src1;
lv_obj_t* cloud_img;

lv_obj_t* game_btn;
lv_obj_t* Play_btn;
lv_obj_t* Play_score;

lv_timer_t* timer;
lv_timer_t* timer1;
lv_timer_t* timer_2;

lv_obj_t*  PORT_3_Back_btn;

uint8_t Task3_FLAG;

struct Dinosaur_FLAG Din;
struct Cloud_FLAG Clu;
struct Cactus_FLAG Cas;

//小恐龙快跑
LV_IMG_DECLARE(New_Dom);
LV_IMG_DECLARE(obs_1);
LV_IMG_DECLARE(obs_2);
LV_IMG_DECLARE(cloud);

static lv_point_t line_points[] = { {-15, 45}, {160, 45} };

/*函数：void LV_Games_Display_Din(lv_obj_t* game) 
*作者：小夏
*形参：lv_obj_t* game
*描述：显示恐龙和路
*修改时间：2022/9/20
*修改内容：无
*/
void LV_Games_Display_Din(lv_obj_t* game) {

    //LV_Game_Display_Cloud(game);
    lv_obj_set_scrollbar_mode(game, LV_SCROLLBAR_MODE_OFF);//不显示滚动条
    lv_obj_clear_flag(game, LV_OBJ_FLAG_SCROLLABLE);//使对象不可滚动。
    lv_obj_t* line1;
    line1 = lv_line_create(game);
    lv_line_set_points(line1, line_points, 2);

    //显示恐龙龙
    Don_src = lv_img_create(game);
    lv_img_set_src(Don_src, &New_Dom);
    //lv_obj_center(Don_src);
    lv_obj_set_pos(Don_src, 0, Din.end_y);

}
/*函数：void my_timer_cloud(lv_timer_t* param)
*作者：小夏
*形参：lv_timer_t* param
*描述：（定时器）云朵的云朵速度随机刷新
*修改时间：2022/9/20
*修改内容：无
*/
void my_timer_cloud(lv_timer_t* param)
{
#if 1
    
    if (obj_4_FLAG == 1) {
        Clu.cloud_value = lv_rand(0, 5);
        Clu.cloud_init -= Clu.cloud_value;
        lv_obj_set_pos(cloud_img, Clu.cloud_init, 0);
        LV_LOG_USER("Read\n");
        if (Clu.cloud_init <= 0) {

            Clu.cloud_init = 130;

        }
    }
    
    
#endif
}
/*函数：void LV_Game_Display_Cloud(lv_obj_t* game) 
*作者：小夏
*形参：lv_obj_t* game
*描述：//云朵显示
*修改时间：2022/9/20
*修改内容：无
*/
void LV_Game_Display_Cloud(lv_obj_t* game) {
    timer_2 = lv_timer_create(my_timer_cloud, 100, NULL);
    cloud_img = lv_img_create(game);
    lv_img_set_src(cloud_img, &cloud);
    lv_obj_set_pos(cloud_img, 130, 0);


}

/*函数：void my_timer_road(lv_timer_t* timer)
*作者：小夏
*形参：lv_timer_t* timer
*描述：（定时器）//定时，障碍物仙人掌随机数量产生和碰撞检测
*修改时间：2022/9/20
*修改内容：无
*/
void my_timer_road(lv_timer_t* timer)
{
#if 1

    if (obj_4_FLAG == 1) {
        if (Cas.OBS == 0) {

            Din.obs_y -= 10;
            //LV_LOG_USER("OBS_Y=%d\n", Din.obs_y);
            if (Cas.OBS_Ch == 0)
            {
                lv_obj_set_pos(Obs_src, Din.obs_y, 26);//一个仙人掌
            }
            else if (Cas.OBS_Ch == 1)
            {
                lv_obj_set_pos(Obs_src1, Din.obs_y, 26);//两个个仙人掌
            }

            if (Din.obs_y == -10)
            {
                //得分
                Din.Don_score++;
                //增加难道
                if (Din.Don_score < 3) {
                    lv_timer_set_period(timer, 200);
                    lv_timer_set_period(timer1, 200);
                }
                if (Din.Don_score == 3) {
                    lv_timer_set_period(timer, 190);
                    lv_timer_set_period(timer1, 190);
                }
                else if (Din.Don_score == 6)
                {
                    lv_timer_set_period(timer, 180);
                    lv_timer_set_period(timer1, 180);
                }
                else if (Din.Don_score == 9)
                {
                    lv_timer_set_period(timer, 170);
                    lv_timer_set_period(timer1, 170);
                }
                else if (Din.Don_score >= 13) {
                    lv_timer_set_period(timer, 150);
                    lv_timer_set_period(timer1, 150);
                }//增加难度
                lv_label_set_text_fmt(Play_score, "Score:%d", Din.Don_score);

                Din.obs_y = 150;//仙人掌复位

                if (Cas.OBS_Ch == 0) {
                    lv_obj_set_pos(Obs_src, Din.obs_y, 26);//一个仙人掌
                }
                else if (Cas.OBS_Ch == 1) {
                    lv_obj_set_pos(Obs_src1, Din.obs_y, 26);//两个个仙人掌
                }

                Cas.Don_rand = lv_rand(0, 1); //产生随机数
                if (Cas.Don_rand == 0) {
                    Cas.OBS_Ch = 0;
                    //LV_LOG_USER("Rand=%d", OBS_Ch);
                }
                else if (Cas.Don_rand == 1) {
                    Cas.OBS_Ch = 1;
                    //LV_LOG_USER("Rand=%d", OBS_Ch);
                }


            }
        }

        if (Din.end_y > 4 & (Din.obs_y >= 8 & Din.obs_y <= 20)) { //碰撞检测

            LV_LOG_USER("end_Game\n");
            Cas.OBS = 1;
            Din.Don_FLAG = 0;
            Clu.cloud_init = 130;
            lv_obj_set_pos(Don_src, 0, 20);
            lv_label_set_text_fmt(Play_score, "Game over");
        }

    }
#endif
}

/*函数：void LV_Get_score(lv_obj_t* game)
*作者：小夏
*形参：lv_obj_t* game
*描述：计算得分
*修改时间：2022/9/20
*修改内容：无
*/
void LV_Get_score(lv_obj_t* game) {
    Play_score = lv_label_create(game);
    lv_obj_align(Play_score, LV_ALIGN_BOTTOM_LEFT, -12, 10);
    lv_obj_set_style_text_font(Play_score, &lv_font_montserrat_10, 0);
    lv_label_set_text_fmt(Play_score, "Score:%d", Din.Don_score);


}

/*函数：static void LV_Play_Handler(lv_event_t* param)
*作者：小夏
*形参：lv_event_t* param
*描述：lv_obj_add_event_cb(Play_btn, LV_Play_Handler, LV_EVENT_ALL, NULL);
       的事件执行函数
			 显示计分和开始复位游戏的callback函数
*修改时间：2022/9/20
*修改内容：无
*/
static void LV_Play_Handler(lv_event_t* param)
{
    lv_event_code_t codes = lv_event_get_code(param);
    if (codes == LV_EVENT_CLICKED) {
        Cas.OBS = 0;
        Din.Don_FLAG = 0;
        Din.obs_y = 130;
        Din.Don_score = 0;
        lv_label_set_text_fmt(Play_score, "Score:%d", Din.Don_score);
        lv_obj_set_pos(Don_src, 0, 20);
        //lv_obj_del(Play_btn);

    }


}

/*函数：void LV_Game_Play_Once(lv_obj_t* game)
*作者：小夏
*形参：lv_obj_t* game
*描述：//复位游戏按键
*修改时间：2022/9/20
*修改内容：无
*/
void LV_Game_Play_Once(lv_obj_t* game) {
    Play_btn = lv_btn_create(game);
    lv_obj_set_size(Play_btn, 60, 12);
    lv_obj_align(Play_btn, LV_ALIGN_TOP_RIGHT, 13, -13);
    lv_obj_set_style_opa(Play_btn, 200, 0);
    lv_obj_t* Play_label = lv_label_create(Play_btn);
    lv_obj_set_style_text_font(Play_label, &lv_font_montserrat_10, 0);
    lv_label_set_text(Play_label, "RESET!");
    lv_obj_center(Play_label);


    lv_obj_add_event_cb(Play_btn, LV_Play_Handler, LV_EVENT_ALL, NULL);
}

/*函数：void LV_Game_Display_Road_Obs(lv_obj_t* game)
*作者：小夏
*形参：lv_obj_t* game
*描述：显示仙人掌
*修改时间：2022/9/20
*修改内容：无
*/
void LV_Game_Display_Road_Obs(lv_obj_t* game)
{
    timer = lv_timer_create(my_timer_road, 200, NULL);
    Obs_src = lv_img_create(game);
    lv_img_set_src(Obs_src, &obs_1);
    Obs_src1 = lv_img_create(game);
    lv_img_set_src(Obs_src1, &obs_2);
    lv_obj_set_pos(Obs_src, 130, 26);
    lv_obj_set_pos(Obs_src1, 1000, 26);

}

/*函数：void my_timer(lv_timer_t* timer)
*作者：小夏
*形参：lv_timer_t* timer
*描述：（定时器）跳跃后的复位延时
*修改时间：2022/9/20
*修改内容：无
*/
void my_timer(lv_timer_t* timer)
{
#if 1

    if (obj_4_FLAG == 1) {
        if (Din.Don_FLAG == 1) {
            Din.end_y += 8;
            lv_obj_set_pos(Don_src, 0, Din.end_y);
            //LV_LOG_USER("end_y=%d\n", end_y);
            if (Din.end_y == 20) {
                Din.Don_FLAG = 0;

            }

        }
    }
#endif
}

/*函数：void my_timer(lv_timer_t* timer)
*作者：小夏
*形参：lv_timer_t* timer
*描述：lv_obj_add_event_cb(game_btn, LV_Game_Handler, LV_EVENT_ALL, NULL);
			 的事件执行函数
			 跳跃按键callback函数
*修改时间：2022/9/20
*修改内容：无
*/
static void LV_Game_Handler(lv_event_t* param)
{
    lv_event_code_t codes_1 = lv_event_get_code(param);

    if (codes_1 == LV_EVENT_CLICKED)
    {
        Din.end_y -= 8;
        //LV_LOG_USER("end_y=%d\n", end_y);
        lv_obj_set_pos(Don_src, 0, Din.end_y);
        if (Din.end_y <= 4) {
            Din.Don_FLAG = 1;
        }
    }


}


/*函数：void LV_Games_Display_btn(lv_obj_t* game)
*作者：小夏
*形参：lv_obj_t* game
*描述：显示跳跃 UP 按键
*修改时间：2022/9/20
*修改内容：无
*/
void LV_Games_Display_btn(lv_obj_t* game)
{
    timer1 = lv_timer_create(my_timer, 200, NULL);

    game_btn = lv_btn_create(game);
    lv_obj_set_size(game_btn, 40, 12);
    lv_obj_align(game_btn, LV_ALIGN_BOTTOM_MID, 0, 10);
    lv_obj_set_style_radius(game_btn, 2, 0);
    lv_obj_t* game_label = lv_label_create(game_btn);
    lv_obj_set_style_text_font(game_label, &lv_font_montserrat_10, 0);
    lv_label_set_text(game_label, "UP");
    lv_obj_center(game_label);
    lv_obj_add_event_cb(game_btn, LV_Game_Handler, LV_EVENT_ALL, NULL);
}
/*函数：static void PORT_3_Back_btn_Handler(lv_event_t* param)
*作者：小夏
*形参：lv_event_t* param
*描述：lv_obj_add_event_cb(PORT_3_Back_btn, PORT_3_Back_btn_Handler, LV_EVENT_ALL, NULL);
			 的事件执行函数
			 退出按键功能
*修改时间：2022/9/20
*修改内容：无
*/
static void PORT_3_Back_btn_Handler(lv_event_t* param) {

    lv_event_code_t vscode = lv_event_get_code(param);
    lv_obj_t* mune = lv_event_get_target(param);

    if (vscode == LV_EVENT_CLICKED) {
        if (mune == PORT_3_Back_btn) {
            obj_4_FLAG = 0;
            lv_timer_pause(timer);
            lv_timer_pause(timer1);
            lv_timer_pause(timer_2);
            lv_timer_del(timer);
            lv_timer_del(timer1);
            lv_timer_del(timer_2);
            lv_obj_del(obj_4);
        }
        LV_Menu_Init();

    }
}
/*函数：void LV_PORT_3_Back_btn(lv_obj_t* one) 
*作者：小夏
*形参：lv_obj_t* one
*描述：退出按键绘制
*修改时间：2022/9/20
*修改内容：无
*/
void LV_PORT_3_Back_btn(lv_obj_t* one) {
    PORT_3_Back_btn = lv_btn_create(one);
    lv_obj_set_size(PORT_3_Back_btn, 36, 12);
    lv_obj_set_style_radius(PORT_3_Back_btn, 5, 0);
    lv_obj_align(PORT_3_Back_btn, LV_ALIGN_TOP_LEFT, -13, -13);
    lv_obj_set_style_bg_color(PORT_3_Back_btn, lv_color_hex(0x808A87), LV_PART_MAIN);
    lv_obj_t* Back_label = lv_label_create(PORT_3_Back_btn);
    lv_label_set_recolor(Back_label, true);
    lv_label_set_text(Back_label, "#000000 <#");
    lv_obj_center(Back_label);

    lv_obj_add_event_cb(PORT_3_Back_btn, PORT_3_Back_btn_Handler, LV_EVENT_ALL, NULL);
}