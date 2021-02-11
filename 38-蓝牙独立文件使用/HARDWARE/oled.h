#ifndef  __OLED_H
#define  __OLED_H
#include "sys.h"

//�����Ĺܽ�Ҫ���������е���delay�ĳ�ʼ��������OLED_GPIO_Init()�Ĺ̳ܽ�ʼ������
#define OLED_SCL PBout(6)			//����SCL�Ĺܽ�
#define OLED_SDA PBout(7) 			//����SDA�Ĺܽ�

#define high 1						//�ߵ�ƽ
#define low 0						//�͵�ƽ
#define X_WIDTH 	128				//���
#define Y_WIDTH 	64				//�߶�
#define XLevelL		   0x02			//x�ĵ�λ
#define XLevelH		   0x10			//x�ĸ�λ
#define YLevel       0xB0			//y�ĳ���
#define Brightness 196 //0~255��������

#define OLED_CMD     0	//д����
#define OLED_DATA    1	//д���� 

//against����ʾ��͹���壺0�����壺1
void OLED_GPIO_Init(void);// -- �ܽ�ʹ��
void OLED_IIC_Start(void);// -- ����I2C����
void OLED_IIC_Stop(void);// -- �ر�I2C����
void OLED_Write_IIC_Byte(unsigned char IIC_Byte);// -- ͨ��I2C����дһ��byte������
void OLED_WrDat(unsigned char dat);// -- ��OLED��д����
void OLED_WrCmd(unsigned char cmd);// -- ��OLED��д����
void OLED_Set_Pos(unsigned char x, unsigned char y);// -- ������ʾ����
void OLED_Fill(unsigned char bmp_dat);// -- ȫ����ʾ(��ʾBMPͼƬʱ�Ż��õ��˹���)
void OLED_CLS(void);// -- ��λ/����
void OLED_ON(void);// -- ����oled
void OLED_OFF(void);// -- �ر�oled
void OLED_Init(void);// -- OLED����ʼ�����򣬴˺���Ӧ�ڲ�����Ļ֮ǰ���ȵ���
void OLED_P6x8Str(unsigned char x,unsigned char y,unsigned char ch[],unsigned char against);// -- 6x8������������ʾASCII�����С���У���̫����
void OLED_P8x16Str(unsigned char x,unsigned char y,unsigned char ch[],unsigned char against);// -- 8x16������������ʾASCII�룬�ǳ�����
void OLED_Show6x8(unsigned char x,unsigned char y,unsigned int N,unsigned char against);// -- 6x8������������ʾASCII�����С���еĵ����ַ�����̫����
void OLED_Show8x16(unsigned char x,unsigned char y,unsigned int N,unsigned char against);// -- 8x16������������ʾASCII��ĵ����ַ����ǳ�����
void OLED_Show16x16(unsigned char x,unsigned char y,unsigned int N,unsigned char against);// -- 16x16������������ʾ���ֵ���С���У������ø������塢�Ӵ֡���б���»��ߵ�
void Oled_Printf_U16(unsigned char x,unsigned char y,unsigned int num,unsigned char TextSize);// -- ���16λ�޷����������֣�TextSize��0��6*8 1��8*16
void Oled_Printf_Float(unsigned char x,unsigned char y,float num,unsigned char TextSize);// -- ��ʾ���999.99�����ݣ�TextSize��0��6*8 1��8*16
void OLED_Show1x1(unsigned char x,unsigned char y,unsigned int N,unsigned char against);// -- û�к�����

void OLED_Set_Pixel(unsigned char x, unsigned char y,unsigned char color);//û����ɫ
void OLED_Display(void);                                  //��ʾ
void DrawLine(u8 x1, u8 y1, u8 x2, u8 y2,u8 color);      //��ֱ��
void DrawRectangle(u8 x1, u8 y1, u8 x2, u8 y2,u8 color);   //��������
void DrawPoint(u8 x,u8 y,u8 color);  //����
static void _draw_circle_8(u8 xc, u8 yc, u8 x, u8 y, u8 color);	// -- û�к�����
void DrawCircle(u8 xc, u8 yc, u8 color, u8 r);// ��Բ
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);//��ͼ��
#endif
