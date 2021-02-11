#ifndef  __OLED_H
#define  __OLED_H
#include "sys.h"

//定义后的管脚要在主函数中调用delay的初始化函数和OLED_GPIO_Init()的管教初始化函数
#define OLED_SCL PBout(6)			//定义SCL的管脚
#define OLED_SDA PBout(7) 			//定义SDA的管脚

#define high 1						//高电平
#define low 0						//低电平
#define X_WIDTH 	128				//宽度
#define Y_WIDTH 	64				//高度
#define XLevelL		   0x02			//x的低位
#define XLevelH		   0x10			//x的高位
#define YLevel       0xB0			//y的长度
#define Brightness 196 //0~255设置亮度

#define OLED_CMD     0	//写命令
#define OLED_DATA    1	//写数据 

//against是显示的凸字体：0凹字体：1
void OLED_GPIO_Init(void);// -- 管脚使能
void OLED_IIC_Start(void);// -- 开启I2C总线
void OLED_IIC_Stop(void);// -- 关闭I2C总线
void OLED_Write_IIC_Byte(unsigned char IIC_Byte);// -- 通过I2C总线写一个byte的数据
void OLED_WrDat(unsigned char dat);// -- 向OLED屏写数据
void OLED_WrCmd(unsigned char cmd);// -- 向OLED屏写命令
void OLED_Set_Pos(unsigned char x, unsigned char y);// -- 设置显示坐标
void OLED_Fill(unsigned char bmp_dat);// -- 全屏显示(显示BMP图片时才会用到此功能)
void OLED_CLS(void);// -- 复位/清屏
void OLED_ON(void);// -- 开启oled
void OLED_OFF(void);// -- 关闭oled
void OLED_Init(void);// -- OLED屏初始化程序，此函数应在操作屏幕之前最先调用
void OLED_P6x8Str(unsigned char x,unsigned char y,unsigned char ch[],unsigned char against);// -- 6x8点整，用于显示ASCII码的最小阵列，不太清晰
void OLED_P8x16Str(unsigned char x,unsigned char y,unsigned char ch[],unsigned char against);// -- 8x16点整，用于显示ASCII码，非常清晰
void OLED_Show6x8(unsigned char x,unsigned char y,unsigned int N,unsigned char against);// -- 6x8点整，用于显示ASCII码的最小阵列的单个字符，不太清晰
void OLED_Show8x16(unsigned char x,unsigned char y,unsigned int N,unsigned char against);// -- 8x16点整，用于显示ASCII码的单个字符，非常清晰
void OLED_Show16x16(unsigned char x,unsigned char y,unsigned int N,unsigned char against);// -- 16x16点整，用于显示汉字的最小阵列，可设置各种字体、加粗、倾斜、下划线等
void Oled_Printf_U16(unsigned char x,unsigned char y,unsigned int num,unsigned char TextSize);// -- 输出16位无符号整型数字，TextSize：0：6*8 1：8*16
void Oled_Printf_Float(unsigned char x,unsigned char y,float num,unsigned char TextSize);// -- 显示最大999.99的数据，TextSize：0：6*8 1：8*16
void OLED_Show1x1(unsigned char x,unsigned char y,unsigned int N,unsigned char against);// -- 没有函数体

void OLED_Set_Pixel(unsigned char x, unsigned char y,unsigned char color);//没有颜色
void OLED_Display(void);                                  //显示
void DrawLine(u8 x1, u8 y1, u8 x2, u8 y2,u8 color);      //画直线
void DrawRectangle(u8 x1, u8 y1, u8 x2, u8 y2,u8 color);   //画正方形
void DrawPoint(u8 x,u8 y,u8 color);  //画点
static void _draw_circle_8(u8 xc, u8 yc, u8 x, u8 y, u8 color);	// -- 没有函数体
void DrawCircle(u8 xc, u8 yc, u8 color, u8 r);// 画圆
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);//画图像
#endif
