//#include "EasyTrace.h"
//#include "LCD.h"
//#define min3v(v1, v2, v3)   ((v1)>(v2)? ((v2)>(v3)?(v3):(v2)):((v1)>(v3)?(v3):(v1)))//取最大
//#define max3v(v1, v2, v3)   ((v1)<(v2)? ((v2)<(v3)?(v3):(v2)):((v1)<(v3)?(v3):(v1)))//取最小值

//#define min4v(u1, u2, u3)   ((u1)>(u2)? ((u2)>(u3)?(u3):(u2)):((u1)>(u3)?(u3):(u1)))//取最大
//#define max4v(u1, u2, u3)   ((u1)<(u2)? ((u2)<(u3)?(u3):(u2)):((u1)<(u3)?(u3):(u1)))//取最小值

//typedef struct
//	  {
//    unsigned char  red;             // [0,255]
//    unsigned char  green;           // [0,255]
//    unsigned char  blue;            // [0,255]
//    }COLOR_RGB;//RGB格式颜色
//	  
//	typedef struct
//	  {
//    unsigned char  red2;             // [0,255]
//    unsigned char  green2;           // [0,255]
//    unsigned char  blue2;            // [0,255]
//    }COLOR_RGB2;//RGB格式颜色
//	
//typedef struct
//	  {
//    unsigned char  red3;             // [0,255]
//    unsigned char  green3;           // [0,255]
//    unsigned char  blue3;            // [0,255]
//    }COLOR_RGB3;//RGB格式颜色
//	  
//	typedef struct
//	  {
//    unsigned char  red4;             // [0,255]
//    unsigned char  green4;           // [0,255]
//    unsigned char  blue4;            // [0,255]
//    }COLOR_RGB4;//RGB格式颜色
//	typedef struct
//	  {
//    unsigned char  red5;             // [0,255]
//    unsigned char  green5;           // [0,255]
//    unsigned char  blue5;            // [0,255]
//    }COLOR_RGB5;//RGB格式颜色
//	 
//typedef struct
//	  {
//    unsigned char hue;              // [0,240]
//    unsigned char saturation;       // [0,240]
//    unsigned char luminance;        // [0,240]
//    }COLOR_HSL;//HSL格式颜色
//	  
//	typedef struct
//	  {
//    unsigned char hue2;              // [0,240]
//    unsigned char saturation2;       // [0,240]
//    unsigned char luminance2;        // [0,240]
//    }COLOR_HSL2;//HSL格式颜色

//			typedef struct
//	  {
//    unsigned char hue3;              // [0,240]
//    unsigned char saturation3;       // [0,240]
//    unsigned char luminance3;        // [0,240]
//    }COLOR_HSL3;//HSL格式颜色
//	  typedef struct
//	  {
//    unsigned char hue4;              // [0,240]
//    unsigned char saturation4;       // [0,240]
//    unsigned char luminance4;        // [0,240]
//    }COLOR_HSL4;//HSL格式颜色
//	  typedef struct
//	  {
//    unsigned char hue5;              // [0,240]
//    unsigned char saturation5;       // [0,240]
//    unsigned char luminance5;        // [0,240]
//    }COLOR_HSL5;//HSL格式颜色
//	  
//typedef struct
//	  {
//    unsigned int X_Start;              
//    unsigned int X_End;
//	  unsigned int Y_Start;              
//    unsigned int Y_End;
//    }SEARCH_AREA;//区域

//typedef struct
//	  {
//    unsigned int X2_Start;              
//    unsigned int X2_End;
//	  unsigned int Y2_Start;              
//    unsigned int Y2_End;
//    }SEARCH_AREA2;//区域
//	
//	typedef struct
//	  {
//    unsigned int X3_Start;              
//    unsigned int X3_End;
//	  unsigned int Y3_Start;              
//    unsigned int Y3_End;
//    }SEARCH_AREA3;//区域
//typedef struct
//	  {
//    unsigned int X4_Start;              
//    unsigned int X4_End;
//	  unsigned int Y4_Start;              
//    unsigned int Y4_End;
//    }SEARCH_AREA4;//区域
//typedef struct
//	  {
//    unsigned int X5_Start;              
//    unsigned int X5_End;
//	  unsigned int Y5_Start;              
//    unsigned int Y5_End;
//    }SEARCH_AREA5;//区域
//  
//读取RBG格式颜色，唯一需要移植的函数
//extern unsigned short LCD_ReadPoint(unsigned short x,unsigned short y);//读某点颜色
//extern unsigned short LCD_ReadPoint(unsigned short x2,unsigned short y2);//读某点颜色
//extern unsigned short LCD_ReadPoint(unsigned short x3,unsigned short y3);//读某点颜色
//extern unsigned short LCD_ReadPoint(unsigned short x4,unsigned short y4);//读某点颜色
//extern unsigned short LCD_ReadPoint(unsigned short x5,unsigned short y5);//读某点颜色
//		
//static void ReadColor(unsigned int x,unsigned int y,COLOR_RGB *Rgb)
//	{
//		unsigned short C16;

//		C16 = LCD_ReadPoint(x,y);     //读某点颜色

//		Rgb->red   =	 (unsigned char)((C16&0xf800)>>8);
//		Rgb->green =	 (unsigned char)((C16&0x07e0)>>3);
//		Rgb->blue  =   (unsigned char)((C16&0x001f)<<3);
//	}
//	
//static void ReadColor2(unsigned int x2,unsigned int y2,COLOR_RGB2 *Rgb2)
//	{
//		unsigned short C16;

//		C16 = LCD_ReadPoint(x2,y2);     //读某点颜色

//		Rgb2->red2   =	 (unsigned char)((C16&0xf800)>>8);
//		Rgb2->green2 =	 (unsigned char)((C16&0x07e0)>>3);
//		Rgb2->blue2  =   (unsigned char)((C16&0x001f)<<3);
//	}
//static void ReadColor3(unsigned int x3,unsigned int y3,COLOR_RGB3 *Rgb3)
//	{
//		unsigned short C16;

//		C16 = LCD_ReadPoint(x3,y3);     //读某点颜色

//		Rgb3->red3   =	 (unsigned char)((C16&0xf800)>>8);
//		Rgb3->green3 =	 (unsigned char)((C16&0x07e0)>>3);
//		Rgb3->blue3  =   (unsigned char)((C16&0x001f)<<3);
//	}
//	static void ReadColor4(unsigned int x4,unsigned int y4,COLOR_RGB4 *Rgb4)
//	{
//		unsigned short C16;

//		C16 = LCD_ReadPoint(x4,y4);     //读某点颜色

//		Rgb4->red4   =	 (unsigned char)((C16&0xf800)>>8);
//		Rgb4->green4 =	 (unsigned char)((C16&0x07e0)>>3);
//		Rgb4->blue4  =   (unsigned char)((C16&0x001f)<<3);
//	}
//	static void ReadColor5(unsigned int x5,unsigned int y5,COLOR_RGB5 *Rgb5)
//	{
//		unsigned short C16;

//		C16 = LCD_ReadPoint(x5,y5);     //读某点颜色

//		Rgb5->red5   =	 (unsigned char)((C16&0xf800)>>8);
//		Rgb5->green5 =	 (unsigned char)((C16&0x07e0)>>3);
//		Rgb5->blue5  =   (unsigned char)((C16&0x001f)<<3);
//	}


//RGB转HSL
//static void RGBtoHSL(const COLOR_RGB *Rgb, COLOR_HSL *Hsl)
//	{
//			int h,s,l,maxVal,minVal,difVal;
//			int r  = Rgb->red;
//			int g  = Rgb->green;
//			int b  = Rgb->blue;
//		
//				maxVal = max3v(r, g, b);
//				minVal = min3v(r, g, b);
//				
//				difVal = maxVal-minVal;
//		
//		//计算亮度
//			l = (maxVal+minVal)*240/255/2;
//		
//		if(maxVal == minVal)//若r=g=b
//			{
//				h = 0; 
//				s = 0;
//			}
//		else
//		{
//			//计算色调
//			if(maxVal==r)
//			{
//				if(g>=b)
//					h = 40*(g-b)/(difVal);
//				else
//					h = 40*(g-b)/(difVal) + 240;
//			}
//			else if(maxVal==g)
//					h = 40*(b-r)/(difVal) + 80;
//			else if(maxVal==b)
//					h = 40*(r-g)/(difVal) + 160;
//			//计算饱和度
//			if(l == 0)
//					s = (difVal)*240/(511 - (maxVal+minVal));
//			else if(l<=120)
//					s = (difVal)*240/(maxVal+minVal);
//			else
//					s = (difVal)*240/(511 - (maxVal+minVal));
//		}
//			Hsl->hue =        (unsigned char)(((h>240)? 240 : ((h<0)?0:h)));//色度
//			Hsl->saturation = (unsigned char)(((s>240)? 240 : ((s<0)?0:s)));//饱和度
//			Hsl->luminance =  (unsigned char)(((l>240)? 240 : ((l<0)?0:l)));//亮度
//	}

//	//RGB转HSL
//static void RGBtoHSL2(const COLOR_RGB2 *Rgb2, COLOR_HSL2 *Hsl2)
//	{
//			int h,s,l,maxVal,minVal,difVal;
//			int r  = Rgb2->red2;
//			int g  = Rgb2->green2;
//			int b  = Rgb2->blue2;
//		
//				maxVal = max4v(r, g, b);
//				minVal = min4v(r, g, b);
//				
//				difVal = maxVal-minVal;
//		
//		//计算亮度
//			l = (maxVal+minVal)*240/255/2;
//		
//		if(maxVal == minVal)//若r=g=b
//			{
//				h = 0; 
//				s = 0;
//			}
//		else
//		{
//			//计算色调
//			if(maxVal==r)
//			{
//				if(g>=b)
//					h = 40*(g-b)/(difVal);
//				else
//					h = 40*(g-b)/(difVal) + 240;
//			}
//			else if(maxVal==g)
//					h = 40*(b-r)/(difVal) + 80;
//			else if(maxVal==b)
//					h = 40*(r-g)/(difVal) + 160;
//			//计算饱和度
//			if(l == 0)
//					s = (difVal)*240/(511 - (maxVal+minVal));
//			else if(l<=120)
//					s = (difVal)*240/(maxVal+minVal);
//			else
//					s = (difVal)*240/(511 - (maxVal+minVal));
//		}
//			Hsl2->hue2 =        (unsigned char)(((h>240)? 240 : ((h<0)?0:h)));//色度
//			Hsl2->saturation2 = (unsigned char)(((s>240)? 240 : ((s<0)?0:s)));//饱和度
//			Hsl2->luminance2 =  (unsigned char)(((l>240)? 240 : ((l<0)?0:l)));//亮度
//	}
//	
//	static void RGBtoHSL3(const COLOR_RGB3 *Rgb3, COLOR_HSL3 *Hsl3)
//	{
//			int h,s,l,maxVal,minVal,difVal;
//			int r  = Rgb3->red3;
//			int g  = Rgb3->green3;
//			int b  = Rgb3->blue3;
//		
//				maxVal = max4v(r, g, b);
//				minVal = min4v(r, g, b);
//				
//				difVal = maxVal-minVal;
//		
//		//计算亮度
//			l = (maxVal+minVal)*240/255/2;
//		
//		if(maxVal == minVal)//若r=g=b
//			{
//				h = 0; 
//				s = 0;
//			}
//		else
//		{
//			//计算色调
//			if(maxVal==r)
//			{
//				if(g>=b)
//					h = 40*(g-b)/(difVal);
//				else
//					h = 40*(g-b)/(difVal) + 240;
//			}
//			else if(maxVal==g)
//					h = 40*(b-r)/(difVal) + 80;
//			else if(maxVal==b)
//					h = 40*(r-g)/(difVal) + 160;
//			//计算饱和度
//			if(l == 0)
//					s = (difVal)*240/(511 - (maxVal+minVal));
//			else if(l<=120)
//					s = (difVal)*240/(maxVal+minVal);
//			else
//					s = (difVal)*240/(511 - (maxVal+minVal));
//		}
//			Hsl3->hue3 =        (unsigned char)(((h>240)? 240 : ((h<0)?0:h)));//色度
//			Hsl3->saturation3 = (unsigned char)(((s>240)? 240 : ((s<0)?0:s)));//饱和度
//			Hsl3->luminance3 =  (unsigned char)(((l>240)? 240 : ((l<0)?0:l)));//亮度
//	}
//static void RGBtoHSL4(const COLOR_RGB4 *Rgb4, COLOR_HSL4 *Hsl4)
//	{
//			int h,s,l,maxVal,minVal,difVal;
//			int r  = Rgb4->red4;
//			int g  = Rgb4->green4;
//			int b  = Rgb4->blue4;
//		
//				maxVal = max4v(r, g, b);
//				minVal = min4v(r, g, b);
//				
//				difVal = maxVal-minVal;
//		
//		//计算亮度
//			l = (maxVal+minVal)*240/255/2;
//		
//		if(maxVal == minVal)//若r=g=b
//			{
//				h = 0; 
//				s = 0;
//			}
//		else
//		{
//			//计算色调
//			if(maxVal==r)
//			{
//				if(g>=b)
//					h = 40*(g-b)/(difVal);
//				else
//					h = 40*(g-b)/(difVal) + 240;
//			}
//			else if(maxVal==g)
//					h = 40*(b-r)/(difVal) + 80;
//			else if(maxVal==b)
//					h = 40*(r-g)/(difVal) + 160;
//			//计算饱和度
//			if(l == 0)
//					s = (difVal)*240/(511 - (maxVal+minVal));
//			else if(l<=120)
//					s = (difVal)*240/(maxVal+minVal);
//			else
//					s = (difVal)*240/(511 - (maxVal+minVal));
//		}
//			Hsl4->hue4 =        (unsigned char)(((h>240)? 240 : ((h<0)?0:h)));//色度
//			Hsl4->saturation4 = (unsigned char)(((s>240)? 240 : ((s<0)?0:s)));//饱和度
//			Hsl4->luminance4 =  (unsigned char)(((l>240)? 240 : ((l<0)?0:l)));//亮度
//	}
//static void RGBtoHSL5(const COLOR_RGB5 *Rgb5, COLOR_HSL5 *Hsl5)
//	{
//			int h,s,l,maxVal,minVal,difVal;
//			int r  = Rgb5->red5;
//			int g  = Rgb5->green5;
//			int b  = Rgb5->blue5;
//		
//				maxVal = max4v(r, g, b);
//				minVal = min4v(r, g, b);
//				
//				difVal = maxVal-minVal;
//		
//		//计算亮度
//			l = (maxVal+minVal)*240/255/2;
//		
//		if(maxVal == minVal)//若r=g=b
//			{
//				h = 0; 
//				s = 0;
//			}
//		else
//		{
//			//计算色调
//			if(maxVal==r)
//			{
//				if(g>=b)
//					h = 40*(g-b)/(difVal);
//				else
//					h = 40*(g-b)/(difVal) + 240;
//			}
//			else if(maxVal==g)
//					h = 40*(b-r)/(difVal) + 80;
//			else if(maxVal==b)
//					h = 40*(r-g)/(difVal) + 160;
//			//计算饱和度
//			if(l == 0)
//					s = (difVal)*240/(511 - (maxVal+minVal));
//			else if(l<=120)
//					s = (difVal)*240/(maxVal+minVal);
//			else
//					s = (difVal)*240/(511 - (maxVal+minVal));
//		}
//			Hsl5->hue5 =        (unsigned char)(((h>240)? 240 : ((h<0)?0:h)));//色度
//			Hsl5->saturation5 = (unsigned char)(((s>240)? 240 : ((s<0)?0:s)));//饱和度
//			Hsl5->luminance5 =  (unsigned char)(((l>240)? 240 : ((l<0)?0:l)));//亮度
//	}
//	
//匹配颜色
//static int ColorMatch(const COLOR_HSL *Hsl,const TARGET_CONDI *Condition)//HSL格式颜色、判定为的目标条件
//	{
//		if( 
//					Hsl->hue		>	Condition->H_MIN &&
//					Hsl->hue		<	Condition->H_MAX &&
//					Hsl->saturation	>	Condition->S_MIN &&
//					Hsl->saturation	<   Condition->S_MAX &&
//					Hsl->luminance	>	Condition->L_MIN &&
//					Hsl->luminance	<   Condition->L_MAX 
//			)          //hue为色调，saturation为饱和度 ，luminance为亮度
//				return 1;
//		else
//				return 0;
//	}

//	static int ColorMatch2(const COLOR_HSL2 *Hsl2,const TARGET_CONDI2*Condition2)//HSL格式颜色、判定为的目标条件
//	{
//		if( 
//					Hsl2->hue2		>	Condition2->H2_MIN &&
//					Hsl2->hue2		<	Condition2->H2_MAX &&
//					Hsl2->saturation2	>	Condition2->S2_MIN &&
//					Hsl2->saturation2	<   Condition2->S2_MAX &&
//					Hsl2->luminance2	>	Condition2->L2_MIN &&
//					Hsl2->luminance2	<   Condition2->L2_MAX 
//			)          //hue为色调，saturation为饱和度 ，luminance为亮度
//				return 1;
//		else
//				return 0;
//	}
//	
//			static int ColorMatch3(const COLOR_HSL3 *Hsl3,const TARGET_CONDI3*Condition3)//HSL格式颜色、判定为的目标条件
//	{
//		if( 
//					Hsl3->hue3		>	Condition3->H3_MIN &&
//					Hsl3->hue3		<	Condition3->H3_MAX &&
//					Hsl3->saturation3	>	Condition3->S3_MIN &&
//					Hsl3->saturation3	<   Condition3->S3_MAX &&
//					Hsl3->luminance3	>	Condition3->L3_MIN &&
//					Hsl3->luminance3	<   Condition3->L3_MAX 
//			)          //hue为色调，saturation为饱和度 ，luminance为亮度
//				return 1;
//		else
//				return 0;
//	}
//		static int ColorMatch4(const COLOR_HSL4 *Hsl4,const TARGET_CONDI4*Condition4)//HSL格式颜色、判定为的目标条件
//	{
//		if( 
//					Hsl4->hue4		>	Condition4->H4_MIN &&
//					Hsl4->hue4		<	Condition4->H4_MAX &&
//					Hsl4->saturation4	>	Condition4->S4_MIN &&
//					Hsl4->saturation4	<   Condition4->S4_MAX &&
//					Hsl4->luminance4	>	Condition4->L4_MIN &&
//					Hsl4->luminance4	<   Condition4->L4_MAX 
//			)          //hue为色调，saturation为饱和度 ，luminance为亮度
//				return 1;
//		else
//				return 0;
//	}
//		static int ColorMatch5(const COLOR_HSL5 *Hsl5,const TARGET_CONDI5*Condition5)//HSL格式颜色、判定为的目标条件
//	{
//		if( 
//					Hsl5->hue5		>	Condition5->H5_MIN &&
//					Hsl5->hue5		<	Condition5->H5_MAX &&
//					Hsl5->saturation5	>	Condition5->S5_MIN &&
//					Hsl5->saturation5	<   Condition5->S5_MAX &&
//					Hsl5->luminance5	>	Condition5->L5_MIN &&
//					Hsl5->luminance5	<   Condition5->L5_MAX 
//			)          //hue为色调，saturation为饱和度 ，luminance为亮度
//				return 1;
//		else
//				return 0;
//	}
//	
//搜索腐蚀中心
//static int SearchCentre(unsigned int *x,unsigned int *y,const TARGET_CONDI *Condition,const SEARCH_AREA *Area)
//TARGET_CONDI判定为的目标条件、SEARCH_AREA区域
//	{
//			unsigned int SpaceX,SpaceY,i,j,k,FailCount=0;
//			COLOR_RGB Rgb;
//			COLOR_HSL Hsl;
//			
//			SpaceX = Condition->WIDTH_MIN/3;   //目标最小宽度
//			SpaceY = Condition->HIGHT_MIN/3;   //目标最小高度

//				for(i=Area->Y_Start;i<Area->Y_End;i+=SpaceY)
//				{
//					for(j=Area->X_Start;j<Area->X_End;j+=SpaceX)
//					{
//						FailCount=0;
//						for(k=0;k<SpaceX+SpaceY;k++)
//						{
//							if(k<SpaceX)
//								ReadColor(j+k,i+SpaceY/2,&Rgb);
//							else
//								ReadColor(j+SpaceX/2,i+(k-SpaceX),&Rgb);
//							  RGBtoHSL(&Rgb,&Hsl);
//							
//							if(!ColorMatch(&Hsl,Condition))
//								FailCount++;
//							if(FailCount>((SpaceX+SpaceY)>>ALLOW_FAIL_PER))
//								break;
//						}
//						if(k==SpaceX+SpaceY)
//						{
//							*x = j+SpaceX/2;
//							*y = i+SpaceY/2;
//							return 1;
//						}
//					}
//				}
//		return 0;
//	}

//	static int SearchCentre2(unsigned int *x2,unsigned int *y2,const TARGET_CONDI2 *Condition2,const SEARCH_AREA2 *Area2)
//TARGET_CONDI判定为的目标条件、SEARCH_AREA区域
//	{
//			unsigned int SpaceX2,SpaceY2,q,w,e,FailCount=0;
//			COLOR_RGB2 Rgb2;
//			COLOR_HSL2 Hsl2;
//			
//			SpaceX2 = Condition2->WIDTH2_MIN/3;   //目标最小宽度
//			SpaceY2 = Condition2->HIGHT2_MIN/3;   //目标最小高度

//				for(q=Area2->Y2_Start;q<Area2->Y2_End;q+=SpaceY2)
//				{
//					for(w=Area2->X2_Start;w<Area2->X2_End;w+=SpaceX2)
//					{
//						FailCount=0;
//						for(e=0;e<SpaceX2+SpaceY2;e++)
//						{
//							if(e<SpaceX2)
//								ReadColor2(w+e,q+SpaceY2/2,&Rgb2);
//							else
//								ReadColor2(w+SpaceX2/2,q+(e-SpaceX2),&Rgb2);
//							  RGBtoHSL2(&Rgb2,&Hsl2);
//							
//							if(!ColorMatch2(&Hsl2,Condition2))
//								FailCount++;
//							if(FailCount>((SpaceX2+SpaceY2)>>ALLOW_FAIL_PER))
//								break;
//						}
//						if(e==SpaceX2+SpaceY2)
//						{
//							*x2 = w+SpaceX2/2;
//							*y2 = q+SpaceY2/2;
//							return 1;
//						}
//					}
//				}
//		return 0;
//	}
//	
//	static int SearchCentre3(unsigned int *x3,unsigned int *y3,const TARGET_CONDI3 *Condition3,const SEARCH_AREA3 *Area3)
//TARGET_CONDI判定为的目标条件、SEARCH_AREA区域
//	{
//			unsigned int SpaceX3,SpaceY3,q,w,e,FailCount=0;
//			COLOR_RGB3 Rgb3;
//			COLOR_HSL3 Hsl3;
//			
//			SpaceX3 = Condition3->WIDTH3_MIN/3;   //目标最小宽度
//			SpaceY3 = Condition3->HIGHT3_MIN/3;   //目标最小高度

//				for(q=Area3->Y3_Start;q<Area3->Y3_End;q+=SpaceY3)
//				{
//					for(w=Area3->X3_Start;w<Area3->X3_End;w+=SpaceX3)
//					{
//						FailCount=0;
//						for(e=0;e<SpaceX3+SpaceY3;e++)
//						{
//							if(e<SpaceX3)
//								ReadColor3(w+e,q+SpaceY3/2,&Rgb3);
//							else
//								ReadColor3(w+SpaceX3/2,q+(e-SpaceX3),&Rgb3);
//							  RGBtoHSL3(&Rgb3,&Hsl3);
//							
//							if(!ColorMatch3(&Hsl3,Condition3))
//								FailCount++;
//							if(FailCount>((SpaceX3+SpaceY3)>>ALLOW_FAIL_PER))
//								break;
//						}
//						if(e==SpaceX3+SpaceY3)
//						{
//							*x3 = w+SpaceX3/2;
//							*y3 = q+SpaceY3/2;
//							return 1;
//						}
//					}
//				}
//		return 0;
//			}
//	
//			
//static int SearchCentre4(unsigned int *x4,unsigned int *y4,const TARGET_CONDI4 *Condition4,const SEARCH_AREA4 *Area4)
//TARGET_CONDI判定为的目标条件、SEARCH_AREA区域
//	{
//			unsigned int SpaceX4,SpaceY4,q,w,e,FailCount=0;
//			COLOR_RGB4 Rgb4;
//			COLOR_HSL4 Hsl4;
//			
//			SpaceX4 = Condition4->WIDTH4_MIN/3;   //目标最小宽度
//			SpaceY4 = Condition4->HIGHT4_MIN/3;   //目标最小高度

//				for(q=Area4->Y4_Start;q<Area4->Y4_End;q+=SpaceY4)
//				{
//					for(w=Area4->X4_Start;w<Area4->X4_End;w+=SpaceX4)
//					{
//						FailCount=0;
//						for(e=0;e<SpaceX4+SpaceY4;e++)
//						{
//							if(e<SpaceX4)
//								ReadColor4(w+e,q+SpaceY4/2,&Rgb4);
//							else
//								ReadColor4(w+SpaceX4/2,q+(e-SpaceX4),&Rgb4);
//							  RGBtoHSL4(&Rgb4,&Hsl4);
//							
//							if(!ColorMatch4(&Hsl4,Condition4))
//								FailCount++;
//							if(FailCount>((SpaceX4+SpaceY4)>>ALLOW_FAIL_PER))
//								break;
//						}
//						if(e==SpaceX4+SpaceY4)
//						{
//							*x4 = w+SpaceX4/2;
//							*y4 = q+SpaceY4/2;
//							return 1;
//						}
//					}
//				}
//		return 0;
//			}
//	extern u16 xx0;
//    extern u16 yy0;
//static int SearchCentre5(unsigned int *x5,unsigned int *y5,const TARGET_CONDI5 *Condition5,const SEARCH_AREA5 *Area5)
//TARGET_CONDI判定为的目标条件、SEARCH_AREA区域
//	{
//          
//		
//		
//			unsigned int SpaceX5,SpaceY5,q,w,e,FailCount=0;
//			COLOR_RGB5 Rgb5;
//			COLOR_HSL5 Hsl5;
//			
//			SpaceX5 = Condition5->WIDTH5_MIN/3;   //目标最小宽度
//			SpaceY5 = Condition5->HIGHT5_MIN/3;   //目标最小高度

//				for(q=Area5->Y5_Start;q<Area5->Y5_End;q+=SpaceY5)
//				{
//					for(w=Area5->X5_Start;w<Area5->X5_End;w+=SpaceX5)
//					{
//						FailCount=0;
//						for(e=0;e<SpaceX5+SpaceY5;e++)
//						{
//							if(e<SpaceX5)
//								ReadColor5(w+e,q+SpaceY5/2,&Rgb5);
//							else
//								ReadColor5(w+SpaceX5/2,q+(e-SpaceX5),&Rgb5);
//							  RGBtoHSL5(&Rgb5,&Hsl5);
//							
//							if(!ColorMatch5(&Hsl5,Condition5))
//								FailCount++;
//							if(FailCount>((SpaceX5+SpaceY5)>>ALLOW_FAIL_PER))
//								break;
//						}
//						if(e==SpaceX5+SpaceY5)
//						{
//							*x5 = w+SpaceX5/2;
//							*y5 = q+SpaceY5/2;
//							
//							if((*x5<10)&&(*y5<10))
//								{
//									*x5=xx0;
//									*y5=yy0;
//								}
//							
//							return 1;
//						}
//					}
//				}
//		
//				
//				
//				return 0;
//			}
//	
//从腐蚀中心向外腐蚀，得到新的腐蚀中心
//static int Corrode(unsigned int oldx,unsigned int oldy,const TARGET_CONDI *Condition,RESULT *Resu)
//{
//	unsigned int Xmin,Xmax,Ymin,Ymax,i,FailCount=0;
//	COLOR_RGB Rgb;
//	COLOR_HSL Hsl;
//	
//	for(i=oldx;i>IMG_X;i--)
//		{
//				ReadColor(i,oldy,&Rgb);
//				RGBtoHSL(&Rgb,&Hsl);
//				if(!ColorMatch(&Hsl,Condition))
//					FailCount++;
//				if(FailCount>(((Condition->WIDTH_MIN+Condition->WIDTH_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Xmin=i;
//	FailCount=0;
//	
//	for(i=oldx;i<IMG_X+IMG_W;i++)
//		{
//				ReadColor(i,oldy,&Rgb);
//				RGBtoHSL(&Rgb,&Hsl);
//				if(!ColorMatch(&Hsl,Condition))
//					FailCount++;
//				if(FailCount>(((Condition->WIDTH_MIN+Condition->WIDTH_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Xmax=i;
//	FailCount=0;
//	
//	for(i=oldy;i>IMG_Y;i--)
//		{
//				ReadColor(oldx,i,&Rgb);
//				RGBtoHSL(&Rgb,&Hsl);
//				if(!ColorMatch(&Hsl,Condition))
//					FailCount++;
//				if(FailCount>(((Condition->HIGHT_MIN+Condition->HIGHT_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Ymin=i;
//	FailCount=0;
//	
//	for(i=oldy;i<IMG_Y+IMG_H;i++)
//		{
//				ReadColor(oldx,i,&Rgb);
//				RGBtoHSL(&Rgb,&Hsl);
//				if(!ColorMatch(&Hsl,Condition))
//					FailCount++;
//				if(FailCount>(((Condition->HIGHT_MIN+Condition->HIGHT_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Ymax=i;
//	FailCount=0;
//	
//	Resu->x	= (Xmin+Xmax)/2;
//	Resu->y	= (Ymin+Ymax)/2;
//	Resu->w	= Xmax-Xmin;
//	Resu->h	= Ymax-Ymin;

//	if(
//			 ((Xmax-Xmin)>(Condition->WIDTH_MIN)) && ((Ymax-Ymin)>(Condition->HIGHT_MIN)) &&\
//			 ((Xmax-Xmin)<(Condition->WIDTH_MAX)) && ((Ymax-Ymin)<(Condition->HIGHT_MAX))
//	   )
//		  return 1;	
//	else
//		  return 0;	
//}



//从腐蚀中心向外腐蚀，得到新的腐蚀中心2
//static int Corrode2(unsigned int oldx2,unsigned int oldy2,const TARGET_CONDI2 *Condition2,RESULT2 *Resu2)
//{
//	unsigned int Xmin,Xmax,Ymin,Ymax,i,FailCount=0;
//	COLOR_RGB2 Rgb2;
//	COLOR_HSL2 Hsl2;
//	
//	for(i=oldx2;i>IMG_X;i--)
//		{
//				ReadColor2(i,oldy2,&Rgb2);
//				RGBtoHSL2(&Rgb2,&Hsl2);
//				if(!ColorMatch2(&Hsl2,Condition2))
//					FailCount++;
//				if(FailCount>(((Condition2->WIDTH2_MIN+Condition2->WIDTH2_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Xmin=i;
//	FailCount=0;
//	
//	for(i=oldx2;i<IMG_X+IMG_W;i++)
//		{
//				ReadColor2(i,oldy2,&Rgb2);
//				RGBtoHSL2(&Rgb2,&Hsl2);
//				if(!ColorMatch2(&Hsl2,Condition2))
//					FailCount++;
//				if(FailCount>(((Condition2->WIDTH2_MIN+Condition2->WIDTH2_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Xmax=i;
//	FailCount=0;
//	
//	for(i=oldy2;i>IMG_Y;i--)
//		{
//				ReadColor2(oldx2,i,&Rgb2);
//				RGBtoHSL2(&Rgb2,&Hsl2);
//				if(!ColorMatch2(&Hsl2,Condition2))
//					FailCount++;
//				if(FailCount>(((Condition2->HIGHT2_MIN+Condition2->HIGHT2_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Ymin=i;
//	FailCount=0;
//	
//	for(i=oldy2;i<IMG_Y+IMG_H;i++)
//		{
//				ReadColor2(oldx2,i,&Rgb2);
//				RGBtoHSL2(&Rgb2,&Hsl2);
//				if(!ColorMatch2(&Hsl2,Condition2))
//					FailCount++;
//				if(FailCount>(((Condition2->HIGHT2_MIN+Condition2->HIGHT2_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Ymax=i;
//	FailCount=0;
//	
//	Resu2->x2	= (Xmin+Xmax)/2;
//	Resu2->y2	= (Ymin+Ymax)/2;
//	Resu2->w2	= Xmax-Xmin;
//	Resu2->h2	= Ymax-Ymin;

//	if(
//			 ((Xmax-Xmin)>(Condition2->WIDTH2_MIN)) && ((Ymax-Ymin)>(Condition2->HIGHT2_MIN)) &&\
//			 ((Xmax-Xmin)<(Condition2->WIDTH2_MAX)) && ((Ymax-Ymin)<(Condition2->HIGHT2_MAX))
//	   )
//		  return 1;	
//	else
//		  return 0;	
//}
//static int Corrode3(unsigned int oldx3,unsigned int oldy3,const TARGET_CONDI3 *Condition3,RESULT3 *Resu3)
//{
//	unsigned int Xmin,Xmax,Ymin,Ymax,i,FailCount=0;
//	COLOR_RGB3 Rgb3;
//	COLOR_HSL3 Hsl3;
//	
//	for(i=oldx3;i>IMG_X;i--)
//		{
//				ReadColor3(i,oldy3,&Rgb3);
//				RGBtoHSL3(&Rgb3,&Hsl3);
//				if(!ColorMatch3(&Hsl3,Condition3))
//					FailCount++;
//				if(FailCount>(((Condition3->WIDTH3_MIN+Condition3->WIDTH3_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Xmin=i;
//	FailCount=0;
//	
//	for(i=oldx3;i<IMG_X+IMG_W;i++)
//		{
//				ReadColor3(i,oldy3,&Rgb3);
//				RGBtoHSL3(&Rgb3,&Hsl3);
//				if(!ColorMatch3(&Hsl3,Condition3))
//					FailCount++;
//				if(FailCount>(((Condition3->WIDTH3_MIN+Condition3->WIDTH3_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Xmax=i;
//	FailCount=0;
//	
//	for(i=oldy3;i>IMG_Y;i--)
//		{
//				ReadColor3(oldx3,i,&Rgb3);
//				RGBtoHSL3(&Rgb3,&Hsl3);
//				if(!ColorMatch3(&Hsl3,Condition3))
//					FailCount++;
//				if(FailCount>(((Condition3->HIGHT3_MIN+Condition3->HIGHT3_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Ymin=i;
//	FailCount=0;
//	
//	for(i=oldy3;i<IMG_Y+IMG_H;i++)
//		{
//				ReadColor3(oldx3,i,&Rgb3);
//				RGBtoHSL3(&Rgb3,&Hsl3);
//				if(!ColorMatch3(&Hsl3,Condition3))
//					FailCount++;
//				if(FailCount>(((Condition3->HIGHT3_MIN+Condition3->HIGHT3_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Ymax=i;
//	FailCount=0;
//	
//	Resu3->x3	= (Xmin+Xmax)/2;
//	Resu3->y3	= (Ymin+Ymax)/2;
//	Resu3->w3	= Xmax-Xmin;
//	Resu3->h3	= Ymax-Ymin;

//	if(
//			 ((Xmax-Xmin)>(Condition3->WIDTH3_MIN)) && ((Ymax-Ymin)>(Condition3->HIGHT3_MIN)) &&\
//			 ((Xmax-Xmin)<(Condition3->WIDTH3_MAX)) && ((Ymax-Ymin)<(Condition3->HIGHT3_MAX))
//	   )
//		  return 1;	
//	else
//		  return 0;	
//}


//从腐蚀中心向外腐蚀，得到新的腐蚀中心2
//static int Corrode4(unsigned int oldx4,unsigned int oldy4,const TARGET_CONDI4 *Condition4,RESULT4 *Resu4)
//{
//	unsigned int Xmin,Xmax,Ymin,Ymax,i,FailCount=0;
//	COLOR_RGB4 Rgb4;
//	COLOR_HSL4 Hsl4;
//	
//	for(i=oldx4;i>IMG_X;i--)
//		{
//				ReadColor4(i,oldy4,&Rgb4);
//				RGBtoHSL4(&Rgb4,&Hsl4);
//				if(!ColorMatch4(&Hsl4,Condition4))
//					FailCount++;
//				if(FailCount>(((Condition4->WIDTH4_MIN+Condition4->WIDTH4_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Xmin=i;
//	FailCount=0;
//	
//	for(i=oldx4;i<IMG_X+IMG_W;i++)
//		{
//				ReadColor4(i,oldy4,&Rgb4);
//				RGBtoHSL4(&Rgb4,&Hsl4);
//				if(!ColorMatch4(&Hsl4,Condition4))
//					FailCount++;
//				if(FailCount>(((Condition4->WIDTH4_MIN+Condition4->WIDTH4_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Xmax=i;
//	FailCount=0;
//	
//	for(i=oldy4;i>IMG_Y;i--)
//		{
//				ReadColor4(oldx4,i,&Rgb4);
//				RGBtoHSL4(&Rgb4,&Hsl4);
//				if(!ColorMatch4(&Hsl4,Condition4))
//					FailCount++;
//				if(FailCount>(((Condition4->HIGHT4_MIN+Condition4->HIGHT4_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Ymin=i;
//	FailCount=0;
//	
//	for(i=oldy4;i<IMG_Y+IMG_H;i++)
//		{
//				ReadColor4(oldx4,i,&Rgb4);
//				RGBtoHSL4(&Rgb4,&Hsl4);
//				if(!ColorMatch4(&Hsl4,Condition4))
//					FailCount++;
//				if(FailCount>(((Condition4->HIGHT4_MIN+Condition4->HIGHT4_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Ymax=i;
//	FailCount=0;
//	
//	Resu4->x4	= (Xmin+Xmax)/2;
//	Resu4->y4	= (Ymin+Ymax)/2;
//	Resu4->w4	= Xmax-Xmin;
//	Resu4->h4	= Ymax-Ymin;

//	if(
//			 ((Xmax-Xmin)>(Condition4->WIDTH4_MIN)) && ((Ymax-Ymin)>(Condition4->HIGHT4_MIN)) &&\
//			 ((Xmax-Xmin)<(Condition4->WIDTH4_MAX)) && ((Ymax-Ymin)<(Condition4->HIGHT4_MAX))
//	   )
//		  return 1;	
//	else
//		  return 0;	
//}



//从腐蚀中心向外腐蚀，得到新的腐蚀中心2
//static int Corrode5(unsigned int oldx5,unsigned int oldy5,const TARGET_CONDI5 *Condition5,RESULT5 *Resu5)
//{
//	unsigned int Xmin,Xmax,Ymin,Ymax,i,FailCount=0;
//	COLOR_RGB5 Rgb5;
//	COLOR_HSL5 Hsl5;
//	
//	for(i=oldx5;i>IMG_X;i--)
//		{
//				ReadColor5(i,oldy5,&Rgb5);
//				RGBtoHSL5(&Rgb5,&Hsl5);
//				if(!ColorMatch5(&Hsl5,Condition5))
//					FailCount++;
//				if(FailCount>(((Condition5->WIDTH5_MIN+Condition5->WIDTH5_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Xmin=i;
//	FailCount=0;
//	
//	for(i=oldx5;i<IMG_X+IMG_W;i++)
//		{
//				ReadColor5(i,oldy5,&Rgb5);
//				RGBtoHSL5(&Rgb5,&Hsl5);
//				if(!ColorMatch5(&Hsl5,Condition5))
//					FailCount++;
//				if(FailCount>(((Condition5->WIDTH5_MIN+Condition5->WIDTH5_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Xmax=i;
//	FailCount=0;
//	
//	for(i=oldy5;i>IMG_Y;i--)
//		{
//				ReadColor5(oldx5,i,&Rgb5);
//				RGBtoHSL5(&Rgb5,&Hsl5);
//				if(!ColorMatch5(&Hsl5,Condition5))
//					FailCount++;
//				if(FailCount>(((Condition5->HIGHT5_MIN+Condition5->HIGHT5_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Ymin=i;
//	FailCount=0;
//	
//	for(i=oldy5;i<IMG_Y+IMG_H;i++)
//		{
//				ReadColor5(oldx5,i,&Rgb5);
//				RGBtoHSL5(&Rgb5,&Hsl5);
//				if(!ColorMatch5(&Hsl5,Condition5))
//					FailCount++;
//				if(FailCount>(((Condition5->HIGHT5_MIN+Condition5->HIGHT5_MAX)>>2)>>ALLOW_FAIL_PER))
//					break;	
//		}
//	Ymax=i;
//	FailCount=0;
//	
//	Resu5->x5	= (Xmin+Xmax)/2;
//	Resu5->y5	= (Ymin+Ymax)/2;
//	Resu5->w5	= Xmax-Xmin;
//	Resu5->h5	= Ymax-Ymin;

//	if(
//			 ((Xmax-Xmin)>(Condition5->WIDTH5_MIN)) && ((Ymax-Ymin)>(Condition5->HIGHT5_MIN)) &&\
//			 ((Xmax-Xmin)<(Condition5->WIDTH5_MAX)) && ((Ymax-Ymin)<(Condition5->HIGHT5_MAX))
//	   )
//		  return 1;	
//	else
//		  return 0;	
//}



//唯一的API，用户将识别条件写入Condition指向的结构体中，该函数将返回目标的x，y坐标和长宽
//返回1识别成功，返回1识别失败
//int Trace(const TARGET_CONDI *Condition,RESULT *Resu)  //TARGET_CONDI识别条件  RESULT识别结果
//{
//	unsigned int i;
//	static unsigned int x0,y0,flag=0;  //静态变量
//	static SEARCH_AREA Area={IMG_X,IMG_X+IMG_W,IMG_Y,IMG_Y+IMG_H};  //x坐标 y坐标  w宽度  h高度
//	RESULT Result;	//RESULT识别结果
//	

//	if(flag==0)    //已经定义
//		{
//			if(SearchCentre(&x0,&y0,Condition,&Area))  //搜索腐蚀中心   &是取地址运算符
//				 flag=1;
//			else
//				{
//						Area.X_Start= IMG_X	       ;
//						Area.X_End  = IMG_X+IMG_W  ;
//						Area.Y_Start= IMG_Y		     ;
//						Area.Y_End  = IMG_Y+IMG_H  ;

//						if(SearchCentre(&x0,&y0,Condition,&Area))	
//						{
//							flag=0;
//							return 0;
//						}	
//				}
//		}
//	Result.x = x0;
//	Result.y = y0;
//	
//	for(i=0;i<ITERATE_NUM;i++)  //进行迭代计算
//		 Corrode(Result.x,Result.y,Condition,&Result);
//		
//	if(Corrode(Result.x,Result.y,Condition,&Result))//从腐蚀中心向外腐蚀
//		{
//			x0=Result.x;
//			y0=Result.y;
//			Resu->x=Result.x;
//			Resu->y=Result.y;
//			Resu->w=Result.w;
//			Resu->h=Result.h;
//			flag=1;

//			Area.X_Start= Result.x - ((Result.w)>>1);
//			Area.X_End  = Result.x + ((Result.w)>>1);
//			Area.Y_Start= Result.y - ((Result.h)>>1);
//			Area.Y_End  = Result.y + ((Result.h)>>1);


//			return 1;
//		}
//	else
//		{
//			flag=0;
//			return 0;
//		}

//}
//int Trace2(const TARGET_CONDI2 *Condition2,RESULT2 *Resu2)  //TARGET_CONDI识别条件  RESULT识别结果
//{
//	unsigned int i;
//	static unsigned int x0,y0,flag=0;  //静态变量
//	static SEARCH_AREA2 Area2={IMG_X2,IMG_X2+IMG_W2,IMG_Y2,IMG_Y2+IMG_H2};  //x坐标 y坐标  w宽度  h高度
//	RESULT2 Result2;	//RESULT识别结果
//	

//	if(flag==0)    //已经定义
//		{
//			if(SearchCentre2(&x0,&y0,Condition2,&Area2))  //搜索腐蚀中心   &是取地址运算符
//				 flag=1;
//			else
//				{
//						Area2.X2_Start= IMG_X2	       ;
//						Area2.X2_End  = IMG_X2+IMG_W2  ;
//						Area2.Y2_Start= IMG_Y2		     ;
//						Area2.Y2_End  = IMG_Y2+IMG_H2  ;

//						if(SearchCentre2(&x0,&y0,Condition2,&Area2))	
//						{
//							flag=0;
//							return 0;
//						}	
//				}
//		}
//	Result2.x2 = x0;
//	Result2.y2 = y0;
//	
//	for(i=0;i<ITERATE_NUM;i++)  //进行迭代计算
//		 Corrode2(Result2.x2,Result2.y2,Condition2,&Result2);
//		
//	if(Corrode2(Result2.x2,Result2.y2,Condition2,&Result2))//从腐蚀中心向外腐蚀
//		{
//			x0=Result2.x2;
//			y0=Result2.y2;
//			Resu2->x2=Result2.x2;
//			Resu2->y2=Result2.y2;
//			Resu2->w2=Result2.w2;
//			Resu2->h2=Result2.h2;
//			flag=1;

//			Area2.X2_Start= Result2.x2 - ((Result2.w2)>>1);
//			Area2.X2_End  = Result2.x2 + ((Result2.w2)>>1);
//			Area2.Y2_Start= Result2.y2 - ((Result2.h2)>>1);
//			Area2.Y2_End  = Result2.y2 + ((Result2.h2)>>1);


//			return 1;
//		}
//	else
//		{
//			flag=0;
//			return 0;
//		}

//}


//int Trace3(const TARGET_CONDI3 *Condition3,RESULT3 *Resu3)  //TARGET_CONDI识别条件  RESULT识别结果
//{
//	unsigned int i;
//	static unsigned int x0,y0,flag=0;  //静态变量
//	static SEARCH_AREA3 Area3={IMG_X3,IMG_X3+IMG_W3,IMG_Y3,IMG_Y3+IMG_H3};  //x坐标 y坐标  w宽度  h高度
//	RESULT3 Result3;	//RESULT识别结果
//	

//	if(flag==0)    //已经定义
//		{
//			if(SearchCentre3(&x0,&y0,Condition3,&Area3))  //搜索腐蚀中心   &是取地址运算符
//				 flag=1;
//			else
//				{
//						Area3.X3_Start= IMG_X3	       ;
//						Area3.X3_End  = IMG_X3+IMG_W3  ;
//						Area3.Y3_Start= IMG_Y3		     ;
//						Area3.Y3_End  = IMG_Y3+IMG_H3  ;

//						if(SearchCentre3(&x0,&y0,Condition3,&Area3))	
//						{
//							flag=0;
//							return 0;
//						}	
//				}
//		}
//	Result3.x3 = x0;
//	Result3.y3 = y0;
//	
//	for(i=0;i<ITERATE_NUM;i++)  //进行迭代计算
//		 Corrode3(Result3.x3,Result3.y3,Condition3,&Result3);
//		
//	if(Corrode3(Result3.x3,Result3.y3,Condition3,&Result3))//从腐蚀中心向外腐蚀
//		{
//			x0=Result3.x3;
//			y0=Result3.y3;
//			Resu3->x3=Result3.x3;
//			Resu3->y3=Result3.y3;
//			Resu3->w3=Result3.w3;
//			Resu3->h3=Result3.h3;
//			flag=1;

//			Area3.X3_Start= Result3.x3 - ((Result3.w3)>>1);
//			Area3.X3_End  = Result3.x3 + ((Result3.w3)>>1);
//			Area3.Y3_Start= Result3.y3 - ((Result3.h3)>>1);
//			Area3.Y3_End  = Result3.y3 + ((Result3.h3)>>1);


//			return 1;
//		}
//	else
//		{
//			flag=0;
//			return 0;
//		}

//}

//int Trace4(const TARGET_CONDI4 *Condition4,RESULT4 *Resu4)  //TARGET_CONDI识别条件  RESULT识别结果
//{
//	unsigned int i;
//	static unsigned int x0,y0,flag=0;  //静态变量
//	static SEARCH_AREA4 Area4={IMG_X4,IMG_X4+IMG_W4,IMG_Y4,IMG_Y4+IMG_H4};  //x坐标 y坐标  w宽度  h高度
//	RESULT4 Result4;	//RESULT识别结果
//	

//	if(flag==0)    //已经定义
//		{
//			if(SearchCentre4(&x0,&y0,Condition4,&Area4))  //搜索腐蚀中心   &是取地址运算符
//				 flag=1;
//			else
//				{
//						Area4.X4_Start= IMG_X4	       ;
//						Area4.X4_End  = IMG_X4+IMG_W4  ;
//						Area4.Y4_Start= IMG_Y4		     ;
//						Area4.Y4_End  = IMG_Y4+IMG_H4  ;

//						if(SearchCentre4(&x0,&y0,Condition4,&Area4))	
//						{
//							flag=0;
//							return 0;
//						}	
//				}
//		}
//	Result4.x4 = x0;
//	Result4.y4 = y0;
//	
//	for(i=0;i<ITERATE_NUM;i++)  //进行迭代计算
//		 Corrode4(Result4.x4,Result4.y4,Condition4,&Result4);
//		
//	if(Corrode4(Result4.x4,Result4.y4,Condition4,&Result4))//从腐蚀中心向外腐蚀
//		{
//			x0=Result4.x4;
//			y0=Result4.y4;
//			Resu4->x4=Result4.x4;
//			Resu4->y4=Result4.y4;
//			Resu4->w4=Result4.w4;
//			Resu4->h4=Result4.h4;
//			flag=1;

//			Area4.X4_Start= Result4.x4 - ((Result4.w4)>>1);
//			Area4.X4_End  = Result4.x4 + ((Result4.w4)>>1);
//			Area4.Y4_Start= Result4.y4 - ((Result4.h4)>>1);
//			Area4.Y4_End  = Result4.y4 + ((Result4.h4)>>1);


//			return 1;
//		}
//	else
//		{
//			flag=0;
//			return 0;
//		}

//}


//int Trace5(const TARGET_CONDI5 *Condition5,RESULT5 *Resu5)  //TARGET_CONDI识别条件  RESULT识别结果
//{
//	unsigned int i;
//	static unsigned int x0,y0,flag=0;  //静态变量
//	static SEARCH_AREA5 Area5={IMG_X5,IMG_X5+IMG_W5,IMG_Y5,IMG_Y5+IMG_H5};  //x坐标 y坐标  w宽度  h高度
//	RESULT5 Result5;	//RESULT识别结果
//	
//	

//	if(flag==0)    //已经定义
//		{
//			if(SearchCentre5(&x0,&y0,Condition5,&Area5))  //搜索腐蚀中心   &是取地址运算符
//				 flag=1;
//			else
//				{
//						Area5.X5_Start= IMG_X5	       ;
//						Area5.X5_End  = IMG_X5+IMG_W5  ;
//						Area5.Y5_Start= IMG_Y5		     ;
//						Area5.Y5_End  = IMG_Y5+IMG_H5  ;

//						if(SearchCentre5(&x0,&y0,Condition5,&Area5))	
//						{
//							flag=0;
//							return 0;
//						}	
//				}
//		}
//	Result5.x5 = x0;
//	Result5.y5 = y0;
//	
//	for(i=0;i<ITERATE_NUM;i++)  //进行迭代计算
//		 Corrode5(Result5.x5,Result5.y5,Condition5,&Result5);
//		
//	if(Corrode5(Result5.x5,Result5.y5,Condition5,&Result5))//从腐蚀中心向外腐蚀
//		{
//			x0=Result5.x5;
//			y0=Result5.y5;
//			Resu5->x5=Result5.x5;
//			Resu5->y5=Result5.y5;
//			Resu5->w5=Result5.w5;
//			Resu5->h5=Result5.h5;
//			flag=1;

//			Area5.X5_Start= Result5.x5 - ((Result5.w5)>>1);
//			Area5.X5_End  = Result5.x5 + ((Result5.w5)>>1);
//			Area5.Y5_Start= Result5.y5 - ((Result5.h5)>>1);
//			Area5.Y5_End  = Result5.y5 + ((Result5.h5)>>1);


//			return 1;
//		}
//	else
//		{
//			flag=0;
//			return 0;
//		}

//}
#include "EasyTrace.h"
#include "LCD.h"
#define min3v(v1, v2, v3)   ((v1)>(v2)? ((v2)>(v3)?(v3):(v2)):((v1)>(v3)?(v3):(v1)))//取最大
#define max3v(v1, v2, v3)   ((v1)<(v2)? ((v2)<(v3)?(v3):(v2)):((v1)<(v3)?(v3):(v1)))//取最小值

#define min4v(u1, u2, u3)   ((u1)>(u2)? ((u2)>(u3)?(u3):(u2)):((u1)>(u3)?(u3):(u1)))//取最大
#define max4v(u1, u2, u3)   ((u1)<(u2)? ((u2)<(u3)?(u3):(u2)):((u1)<(u3)?(u3):(u1)))//取最小值

typedef struct
	  {
    unsigned char  red;             // [0,255]
    unsigned char  green;           // [0,255]
    unsigned char  blue;            // [0,255]
    }COLOR_RGB;//RGB格式颜色
	  
	typedef struct
	  {
    unsigned char  red2;             // [0,255]
    unsigned char  green2;           // [0,255]
    unsigned char  blue2;            // [0,255]
    }COLOR_RGB2;//RGB格式颜色
	
typedef struct
	  {
    unsigned char  red3;             // [0,255]
    unsigned char  green3;           // [0,255]
    unsigned char  blue3;            // [0,255]
    }COLOR_RGB3;//RGB格式颜色
	  
	typedef struct
	  {
    unsigned char  red4;             // [0,255]
    unsigned char  green4;           // [0,255]
    unsigned char  blue4;            // [0,255]
    }COLOR_RGB4;//RGB格式颜色
	typedef struct
	  {
    unsigned char  red5;             // [0,255]
    unsigned char  green5;           // [0,255]
    unsigned char  blue5;            // [0,255]
    }COLOR_RGB5;//RGB格式颜色
	  
		
typedef struct
	  {
    unsigned char hue;              // [0,240]
    unsigned char saturation;       // [0,240]
    unsigned char luminance;        // [0,240]
    }COLOR_HSL;//HSL格式颜色
	  
	typedef struct
	  {
    unsigned char hue2;              // [0,240]
    unsigned char saturation2;       // [0,240]
    unsigned char luminance2;        // [0,240]
    }COLOR_HSL2;//HSL格式颜色
	  
	typedef struct
	  {
    unsigned char hue3;              // [0,240]
    unsigned char saturation3;       // [0,240]
    unsigned char luminance3;        // [0,240]
    }COLOR_HSL3;//HSL格式颜色
	  typedef struct
	  {
    unsigned char hue4;              // [0,240]
    unsigned char saturation4;       // [0,240]
    unsigned char luminance4;        // [0,240]
    }COLOR_HSL4;//HSL格式颜色
	  typedef struct
	  {
    unsigned char hue5;              // [0,240]
    unsigned char saturation5;       // [0,240]
    unsigned char luminance5;        // [0,240]
    }COLOR_HSL5;//HSL格式颜色
	  

typedef struct
	  {
    unsigned int X_Start;              
    unsigned int X_End;
	  unsigned int Y_Start;              
    unsigned int Y_End;
    }SEARCH_AREA;//区域

typedef struct
	  {
    unsigned int X2_Start;              
    unsigned int X2_End;
	  unsigned int Y2_Start;              
    unsigned int Y2_End;
    }SEARCH_AREA2;//区域
	typedef struct
	  {
    unsigned int X3_Start;              
    unsigned int X3_End;
	  unsigned int Y3_Start;              
    unsigned int Y3_End;
    }SEARCH_AREA3;//区域
typedef struct
	  {
    unsigned int X4_Start;              
    unsigned int X4_End;
	  unsigned int Y4_Start;              
    unsigned int Y4_End;
    }SEARCH_AREA4;//区域
typedef struct
	  {
    unsigned int X5_Start;              
    unsigned int X5_End;
	  unsigned int Y5_Start;              
    unsigned int Y5_End;
    }SEARCH_AREA5;//区域
  
	
	
	
	
//读取RBG格式颜色，唯一需要移植的函数
extern unsigned short LCD_ReadPoint(unsigned short x,unsigned short y);//读某点颜色
extern unsigned short LCD_ReadPoint(unsigned short x2,unsigned short y2);//读某点颜色
extern unsigned short LCD_ReadPoint(unsigned short x3,unsigned short y3);//读某点颜色
extern unsigned short LCD_ReadPoint(unsigned short x4,unsigned short y4);//读某点颜色
extern unsigned short LCD_ReadPoint(unsigned short x5,unsigned short y5);//读某点颜色

static void ReadColor(unsigned int x,unsigned int y,COLOR_RGB *Rgb)
	{
		unsigned short C16;

		C16 = LCD_ReadPoint(x,y);     //读某点颜色

		Rgb->red   =	 (unsigned char)((C16&0xf800)>>8);
		Rgb->green =	 (unsigned char)((C16&0x07e0)>>3);
		Rgb->blue  =   (unsigned char)((C16&0x001f)<<3);
	}
	
static void ReadColor2(unsigned int x2,unsigned int y2,COLOR_RGB2 *Rgb2)
	{
		unsigned short C16;

		C16 = LCD_ReadPoint(x2,y2);     //读某点颜色

		Rgb2->red2   =	 (unsigned char)((C16&0xf800)>>8);
		Rgb2->green2 =	 (unsigned char)((C16&0x07e0)>>3);
		Rgb2->blue2  =   (unsigned char)((C16&0x001f)<<3);
	}
static void ReadColor3(unsigned int x3,unsigned int y3,COLOR_RGB3 *Rgb3)
	{
		unsigned short C16;

		C16 = LCD_ReadPoint(x3,y3);     //读某点颜色

		Rgb3->red3   =	 (unsigned char)((C16&0xf800)>>8);
		Rgb3->green3 =	 (unsigned char)((C16&0x07e0)>>3);
		Rgb3->blue3  =   (unsigned char)((C16&0x001f)<<3);
	}
	static void ReadColor4(unsigned int x4,unsigned int y4,COLOR_RGB4 *Rgb4)
	{
		unsigned short C16;

		C16 = LCD_ReadPoint(x4,y4);     //读某点颜色

		Rgb4->red4   =	 (unsigned char)((C16&0xf800)>>8);
		Rgb4->green4 =	 (unsigned char)((C16&0x07e0)>>3);
		Rgb4->blue4  =   (unsigned char)((C16&0x001f)<<3);
	}
	static void ReadColor5(unsigned int x5,unsigned int y5,COLOR_RGB5 *Rgb5)
	{
		unsigned short C16;

		C16 = LCD_ReadPoint(x5,y5);     //读某点颜色

		Rgb5->red5   =	 (unsigned char)((C16&0xf800)>>8);
		Rgb5->green5 =	 (unsigned char)((C16&0x07e0)>>3);
		Rgb5->blue5  =   (unsigned char)((C16&0x001f)<<3);
	}
	


//RGB转HSL
static void RGBtoHSL(const COLOR_RGB *Rgb, COLOR_HSL *Hsl)
	{
			int h,s,l,maxVal,minVal,difVal;
			int r  = Rgb->red;
			int g  = Rgb->green;
			int b  = Rgb->blue;
		
				maxVal = max3v(r, g, b);
				minVal = min3v(r, g, b);
				
				difVal = maxVal-minVal;
		
		//计算亮度
			l = (maxVal+minVal)*240/255/2;
		
		if(maxVal == minVal)//若r=g=b
			{
				h = 0; 
				s = 0;
			}
		else
		{
			//计算色调
			if(maxVal==r)
			{
				if(g>=b)
					h = 40*(g-b)/(difVal);
				else
					h = 40*(g-b)/(difVal) + 240;
			}
			else if(maxVal==g)
					h = 40*(b-r)/(difVal) + 80;
			else if(maxVal==b)
					h = 40*(r-g)/(difVal) + 160;
			//计算饱和度
			if(l == 0)
					s = (difVal)*240/(511 - (maxVal+minVal));
			else if(l<=120)
					s = (difVal)*240/(maxVal+minVal);
			else
					s = (difVal)*240/(511 - (maxVal+minVal));
		}
			Hsl->hue =        (unsigned char)(((h>240)? 240 : ((h<0)?0:h)));//色度
			Hsl->saturation = (unsigned char)(((s>240)? 240 : ((s<0)?0:s)));//饱和度
			Hsl->luminance =  (unsigned char)(((l>240)? 240 : ((l<0)?0:l)));//亮度
	}

	//RGB转HSL
static void RGBtoHSL2(const COLOR_RGB2 *Rgb2, COLOR_HSL2 *Hsl2)
	{
			int h,s,l,maxVal,minVal,difVal;
			int r  = Rgb2->red2;
			int g  = Rgb2->green2;
			int b  = Rgb2->blue2;
		
				maxVal = max4v(r, g, b);
				minVal = min4v(r, g, b);
				
				difVal = maxVal-minVal;
		
		//计算亮度
			l = (maxVal+minVal)*240/255/2;
		
		if(maxVal == minVal)//若r=g=b
			{
				h = 0; 
				s = 0;
			}
		else
		{
			//计算色调
			if(maxVal==r)
			{
				if(g>=b)
					h = 40*(g-b)/(difVal);
				else
					h = 40*(g-b)/(difVal) + 240;
			}
			else if(maxVal==g)
					h = 40*(b-r)/(difVal) + 80;
			else if(maxVal==b)
					h = 40*(r-g)/(difVal) + 160;
			//计算饱和度
			if(l == 0)
					s = (difVal)*240/(511 - (maxVal+minVal));
			else if(l<=120)
					s = (difVal)*240/(maxVal+minVal);
			else
					s = (difVal)*240/(511 - (maxVal+minVal));
		}
			Hsl2->hue2 =        (unsigned char)(((h>240)? 240 : ((h<0)?0:h)));//色度
			Hsl2->saturation2 = (unsigned char)(((s>240)? 240 : ((s<0)?0:s)));//饱和度
			Hsl2->luminance2 =  (unsigned char)(((l>240)? 240 : ((l<0)?0:l)));//亮度
	}
static void RGBtoHSL3(const COLOR_RGB3 *Rgb3, COLOR_HSL3 *Hsl3)
	{
			int h,s,l,maxVal,minVal,difVal;
			int r  = Rgb3->red3;
			int g  = Rgb3->green3;
			int b  = Rgb3->blue3;
		
				maxVal = max4v(r, g, b);
				minVal = min4v(r, g, b);
				
				difVal = maxVal-minVal;
		
		//计算亮度
			l = (maxVal+minVal)*240/255/2;
		
		if(maxVal == minVal)//若r=g=b
			{
				h = 0; 
				s = 0;
			}
		else
		{
			//计算色调
			if(maxVal==r)
			{
				if(g>=b)
					h = 40*(g-b)/(difVal);
				else
					h = 40*(g-b)/(difVal) + 240;
			}
			else if(maxVal==g)
					h = 40*(b-r)/(difVal) + 80;
			else if(maxVal==b)
					h = 40*(r-g)/(difVal) + 160;
			//计算饱和度
			if(l == 0)
					s = (difVal)*240/(511 - (maxVal+minVal));
			else if(l<=120)
					s = (difVal)*240/(maxVal+minVal);
			else
					s = (difVal)*240/(511 - (maxVal+minVal));
		}
			Hsl3->hue3 =        (unsigned char)(((h>240)? 240 : ((h<0)?0:h)));//色度
			Hsl3->saturation3 = (unsigned char)(((s>240)? 240 : ((s<0)?0:s)));//饱和度
			Hsl3->luminance3 =  (unsigned char)(((l>240)? 240 : ((l<0)?0:l)));//亮度
	}
static void RGBtoHSL4(const COLOR_RGB4 *Rgb4, COLOR_HSL4 *Hsl4)
	{
			int h,s,l,maxVal,minVal,difVal;
			int r  = Rgb4->red4;
			int g  = Rgb4->green4;
			int b  = Rgb4->blue4;
		
				maxVal = max4v(r, g, b);//19 37 19
				minVal = min4v(r, g, b);
				
				difVal = maxVal-minVal;//18
		
		//计算亮度
			l = (maxVal+minVal)*240/255/2;//26
		
		if(maxVal == minVal)//若r=g=b
			{
				h = 0; 
				s = 0;
			}
		else
		{
			//计算色调
			if(maxVal==r)
			{
				if(g>=b)
					h = 40*(g-b)/(difVal);
				else
					h = 40*(g-b)/(difVal) + 240;
			}
			else if(maxVal==g)
					h = 40*(b-r)/(difVal) + 80;//0-3
			else if(maxVal==b)
					h = 40*(r-g)/(difVal) + 160;//77
			//计算饱和度
			if(l == 0)
					s = (difVal)*240/(511 - (maxVal+minVal));
			else if(l<=120)
					s = (difVal)*240/(maxVal+minVal);
			else
					s = (difVal)*240/(511 - (maxVal+minVal));
		}
			Hsl4->hue4 =        (unsigned char)(((h>240)? 240 : ((h<0)?0:h)));//色度
			Hsl4->saturation4 = (unsigned char)(((s>240)? 240 : ((s<0)?0:s)));//饱和度
			Hsl4->luminance4 =  (unsigned char)(((l>240)? 240 : ((l<0)?0:l)));//亮度
	}
static void RGBtoHSL5(const COLOR_RGB5 *Rgb5, COLOR_HSL5 *Hsl5)
	{
			int h,s,l,maxVal,minVal,difVal;
			int r  = Rgb5->red5;
			int g  = Rgb5->green5;
			int b  = Rgb5->blue5;
		
				maxVal = max4v(r, g, b);
				minVal = min4v(r, g, b);
				
				difVal = maxVal-minVal;//150-50
		
		//计算亮度
			l = (maxVal+minVal)*240/255/2;  
		
		if(maxVal == minVal)//若r=g=b
			{
				h = 0; 
				s = 0;
			}
		else
		{
			//计算色调
			if(maxVal==r)
			{
				if(g>=b)
					h = 40*(g-b)/(difVal);//120
				else
					h = 40*(g-b)/(difVal) + 240;
			}
			else if(maxVal==g)
					h = 40*(b-r)/(difVal) + 80;
			else if(maxVal==b)
					h = 40*(r-g)/(difVal) + 160;
			//计算饱和度
			if(l == 0)
					s = (difVal)*240/(511 - (maxVal+minVal));//2400/511-200
			else if(l<=120)
					s = (difVal)*240/(maxVal+minVal);
			else
					s = (difVal)*240/(511 - (maxVal+minVal));
		}
			Hsl5->hue5 =        (unsigned char)(((h>240)? 240 : ((h<0)?0:h)));//色度
			Hsl5->saturation5 = (unsigned char)(((s>240)? 240 : ((s<0)?0:s)));//饱和度
			Hsl5->luminance5 =  (unsigned char)(((l>240)? 240 : ((l<0)?0:l)));//亮度
	}
//匹配颜色
static int ColorMatch(const COLOR_HSL *Hsl,const TARGET_CONDI *Condition)//HSL格式颜色、判定为的目标条件
	{
		if( 
					Hsl->hue		>	Condition->H_MIN &&
					Hsl->hue		<	Condition->H_MAX &&
					Hsl->saturation	>	Condition->S_MIN &&
					Hsl->saturation	<   Condition->S_MAX &&
					Hsl->luminance	>	Condition->L_MIN &&
					Hsl->luminance	<   Condition->L_MAX 
			)          //hue为色调，saturation为饱和度 ，luminance为亮度
				return 1;
		else
				return 0;
	}

	static int ColorMatch2(const COLOR_HSL2 *Hsl2,const TARGET_CONDI2*Condition2)//HSL格式颜色、判定为的目标条件
	{
		if( 
					Hsl2->hue2		>	Condition2->H2_MIN &&
					Hsl2->hue2		<	Condition2->H2_MAX &&
					Hsl2->saturation2	>	Condition2->S2_MIN &&
					Hsl2->saturation2	<   Condition2->S2_MAX &&
					Hsl2->luminance2	>	Condition2->L2_MIN &&
					Hsl2->luminance2	<   Condition2->L2_MAX 
			)          //hue为色调，saturation为饱和度 ，luminance为亮度
				return 1;
		else
				return 0;
	}
		static int ColorMatch3(const COLOR_HSL3 *Hsl3,const TARGET_CONDI3*Condition3)//HSL格式颜色、判定为的目标条件
	{
		if( 
					Hsl3->hue3		>	Condition3->H3_MIN &&
					Hsl3->hue3		<	Condition3->H3_MAX &&
					Hsl3->saturation3	>	Condition3->S3_MIN &&
					Hsl3->saturation3	<   Condition3->S3_MAX &&
					Hsl3->luminance3	>	Condition3->L3_MIN &&
					Hsl3->luminance3	<   Condition3->L3_MAX 
			)          //hue为色调，saturation为饱和度 ，luminance为亮度
				return 1;
		else
				return 0;
	}
		static int ColorMatch4(const COLOR_HSL4 *Hsl4,const TARGET_CONDI4*Condition4)//HSL格式颜色、判定为的目标条件
	{
		if( 
					Hsl4->hue4		>	Condition4->H4_MIN &&
					Hsl4->hue4		<	Condition4->H4_MAX &&
					Hsl4->saturation4	>	Condition4->S4_MIN &&
					Hsl4->saturation4	<   Condition4->S4_MAX &&
					Hsl4->luminance4	>	Condition4->L4_MIN &&
					Hsl4->luminance4	<   Condition4->L4_MAX 
			)          //hue为色调，saturation为饱和度 ，luminance为亮度
				return 1;
		else
				return 0;
	}
		static int ColorMatch5(const COLOR_HSL5 *Hsl5,const TARGET_CONDI5*Condition5)//HSL格式颜色、判定为的目标条件
	{
		if( 
					Hsl5->hue5		>	Condition5->H5_MIN &&
					Hsl5->hue5		<	Condition5->H5_MAX &&
					Hsl5->saturation5	>	Condition5->S5_MIN &&
					Hsl5->saturation5	<   Condition5->S5_MAX &&
					Hsl5->luminance5	>	Condition5->L5_MIN &&
					Hsl5->luminance5	<   Condition5->L5_MAX 
			)          //hue为色调，saturation为饱和度 ，luminance为亮度
				return 1;
		else
				return 0;
	}
//搜索腐蚀中心
static int SearchCentre(unsigned int *x,unsigned int *y,const TARGET_CONDI *Condition,const SEARCH_AREA *Area)
//TARGET_CONDI判定为的目标条件、SEARCH_AREA区域
	{
			unsigned int SpaceX,SpaceY,i,j,k,FailCount=0;
			COLOR_RGB Rgb;
			COLOR_HSL Hsl;
			
			SpaceX = Condition->WIDTH_MIN/3;   //目标最小宽度
			SpaceY = Condition->HIGHT_MIN/3;   //目标最小高度

				for(i=Area->Y_Start;i<Area->Y_End;i+=SpaceY)
				{
					for(j=Area->X_Start;j<Area->X_End;j+=SpaceX)
					{
						FailCount=0;
						for(k=0;k<SpaceX+SpaceY;k++)
						{
							if(k<SpaceX)
								ReadColor(j+k,i+SpaceY/2,&Rgb);
							else
								ReadColor(j+SpaceX/2,i+(k-SpaceX),&Rgb);
							  RGBtoHSL(&Rgb,&Hsl);
							
							if(!ColorMatch(&Hsl,Condition))
								FailCount++;
							if(FailCount>((SpaceX+SpaceY)>>ALLOW_FAIL_PER))
								break;
						}
						if(k==SpaceX+SpaceY)
						{
							*x = j+SpaceX/2;
							*y = i+SpaceY/2;
							return 1;
						}
					}
				}
		return 0;
	}

static int SearchCentre2(unsigned int *x2,unsigned int *y2,const TARGET_CONDI2 *Condition2,const SEARCH_AREA2 *Area2)
//TARGET_CONDI判定为的目标条件、SEARCH_AREA区域
	{
			unsigned int SpaceX2,SpaceY2,q,w,e,FailCount=0;
			COLOR_RGB2 Rgb2;
			COLOR_HSL2 Hsl2;
			
			SpaceX2 = Condition2->WIDTH2_MIN/3;   //目标最小宽度
			SpaceY2 = Condition2->HIGHT2_MIN/3;   //目标最小高度

				for(q=Area2->Y2_Start;q<Area2->Y2_End;q+=SpaceY2)
				{
					for(w=Area2->X2_Start;w<Area2->X2_End;w+=SpaceX2)
					{
						FailCount=0;
						for(e=0;e<SpaceX2+SpaceY2;e++)
						{
							if(e<SpaceX2)
								ReadColor2(w+e,q+SpaceY2/2,&Rgb2);
							else
								ReadColor2(w+SpaceX2/2,q+(e-SpaceX2),&Rgb2);
							  RGBtoHSL2(&Rgb2,&Hsl2);
							
							if(!ColorMatch2(&Hsl2,Condition2))
								FailCount++;
							if(FailCount>((SpaceX2+SpaceY2)>>ALLOW_FAIL_PER))
								break;
						}
						if(e==SpaceX2+SpaceY2)
						{
							*x2 = w+SpaceX2/2;
							*y2 = q+SpaceY2/2;
							return 1;
						}
					}
				}
		return 0;
	}
	
static int SearchCentre3(unsigned int *x3,unsigned int *y3,const TARGET_CONDI3 *Condition3,const SEARCH_AREA3 *Area3)
//TARGET_CONDI判定为的目标条件、SEARCH_AREA区域
	{
			unsigned int SpaceX3,SpaceY3,q,w,e,FailCount=0;
			COLOR_RGB3 Rgb3;
			COLOR_HSL3 Hsl3;
			
			SpaceX3 = Condition3->WIDTH3_MIN/3;   //目标最小宽度
			SpaceY3 = Condition3->HIGHT3_MIN/3;   //目标最小高度

				for(q=Area3->Y3_Start;q<Area3->Y3_End;q+=SpaceY3)
				{
					for(w=Area3->X3_Start;w<Area3->X3_End;w+=SpaceX3)
					{
						FailCount=0;
						for(e=0;e<SpaceX3+SpaceY3;e++)
						{
							if(e<SpaceX3)
								ReadColor3(w+e,q+SpaceY3/2,&Rgb3);
							else
								ReadColor3(w+SpaceX3/2,q+(e-SpaceX3),&Rgb3);
							  RGBtoHSL3(&Rgb3,&Hsl3);
							
							if(!ColorMatch3(&Hsl3,Condition3))
								FailCount++;
							if(FailCount>((SpaceX3+SpaceY3)>>ALLOW_FAIL_PER))
								break;
						}
						if(e==SpaceX3+SpaceY3)
						{
							*x3 = w+SpaceX3/2;
							*y3 = q+SpaceY3/2;
							return 1;
						}
					}
				}
		return 0;
			}
	
			
static int SearchCentre4(unsigned int *x4,unsigned int *y4,const TARGET_CONDI4 *Condition4,const SEARCH_AREA4 *Area4)
//TARGET_CONDI判定为的目标条件、SEARCH_AREA区域
	{
			unsigned int SpaceX4,SpaceY4,q,w,e,FailCount=0;
			COLOR_RGB4 Rgb4;
			COLOR_HSL4 Hsl4;
			
			SpaceX4 = Condition4->WIDTH4_MIN/3;   //目标最小宽度
			SpaceY4 = Condition4->HIGHT4_MIN/3;   //目标最小高度

				for(q=Area4->Y4_Start;q<Area4->Y4_End;q+=SpaceY4)
				{
					for(w=Area4->X4_Start;w<Area4->X4_End;w+=SpaceX4)
					{
						FailCount=0;
						for(e=0;e<SpaceX4+SpaceY4;e++)
						{
							if(e<SpaceX4)
								ReadColor4(w+e,q+SpaceY4/2,&Rgb4);
							else
								ReadColor4(w+SpaceX4/2,q+(e-SpaceX4),&Rgb4);
							  RGBtoHSL4(&Rgb4,&Hsl4);
							
							if(!ColorMatch4(&Hsl4,Condition4))
								FailCount++;
							if(FailCount>((SpaceX4+SpaceY4)>>ALLOW_FAIL_PER))
								break;
						}
						if(e==SpaceX4+SpaceY4)
						{
							*x4 = w+SpaceX4/2;
							*y4 = q+SpaceY4/2;
							return 1;
						}
					}
				}
		return 0;
			}
	extern u16 xx0;
    extern u16 yy0;
static int SearchCentre5(unsigned int *x5,unsigned int *y5,const TARGET_CONDI5 *Condition5,const SEARCH_AREA5 *Area5)
//TARGET_CONDI判定为的目标条件、SEARCH_AREA区域
	{
          
		
		
			unsigned int SpaceX5,SpaceY5,q,w,e,FailCount=0;
			COLOR_RGB5 Rgb5;
			COLOR_HSL5 Hsl5;
			
			SpaceX5 = Condition5->WIDTH5_MIN/3;   //目标最小宽度
			SpaceY5 = Condition5->HIGHT5_MIN/3;   //目标最小高度

				for(q=Area5->Y5_Start;q<Area5->Y5_End;q+=SpaceY5)
				{
					for(w=Area5->X5_Start;w<Area5->X5_End;w+=SpaceX5)
					{
						FailCount=0;
						for(e=0;e<SpaceX5+SpaceY5;e++)
						{
							if(e<SpaceX5)
								ReadColor5(w+e,q+SpaceY5/2,&Rgb5);
							else
								ReadColor5(w+SpaceX5/2,q+(e-SpaceX5),&Rgb5);
							  RGBtoHSL5(&Rgb5,&Hsl5);
							
							if(!ColorMatch5(&Hsl5,Condition5))
								FailCount++;
							if(FailCount>((SpaceX5+SpaceY5)>>ALLOW_FAIL_PER))
								break;
						}
						if(e==SpaceX5+SpaceY5)
						{
							*x5 = w+SpaceX5/2;
							*y5 = q+SpaceY5/2;
							
							if((*x5<10)&&(*y5<10))
								{
									*x5=xx0;
									*y5=yy0;
								}
							
							return 1;
						}
					}
				}
		
				
				
				return 0;
			}
	
//从腐蚀中心向外腐蚀，得到新的腐蚀中心
static int Corrode(unsigned int oldx,unsigned int oldy,const TARGET_CONDI *Condition,RESULT *Resu)
{
	unsigned int Xmin,Xmax,Ymin,Ymax,i,FailCount=0;
	COLOR_RGB Rgb;
	COLOR_HSL Hsl;
	
	for(i=oldx;i>IMG_X;i--)
		{
				ReadColor(i,oldy,&Rgb);
				RGBtoHSL(&Rgb,&Hsl);
				if(!ColorMatch(&Hsl,Condition))
					FailCount++;
				if(FailCount>(((Condition->WIDTH_MIN+Condition->WIDTH_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Xmin=i;
	FailCount=0;
	
	for(i=oldx;i<IMG_X+IMG_W;i++)
		{
				ReadColor(i,oldy,&Rgb);
				RGBtoHSL(&Rgb,&Hsl);
				if(!ColorMatch(&Hsl,Condition))
					FailCount++;
				if(FailCount>(((Condition->WIDTH_MIN+Condition->WIDTH_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Xmax=i;
	FailCount=0;
	
	for(i=oldy;i>IMG_Y;i--)
		{
				ReadColor(oldx,i,&Rgb);
				RGBtoHSL(&Rgb,&Hsl);
				if(!ColorMatch(&Hsl,Condition))
					FailCount++;
				if(FailCount>(((Condition->HIGHT_MIN+Condition->HIGHT_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Ymin=i;
	FailCount=0;
	
	for(i=oldy;i<IMG_Y+IMG_H;i++)
		{
				ReadColor(oldx,i,&Rgb);
				RGBtoHSL(&Rgb,&Hsl);
				if(!ColorMatch(&Hsl,Condition))
					FailCount++;
				if(FailCount>(((Condition->HIGHT_MIN+Condition->HIGHT_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Ymax=i;
	FailCount=0;
	
	Resu->x	= (Xmin+Xmax)/2;
	Resu->y	= (Ymin+Ymax)/2;
	Resu->w	= Xmax-Xmin;
	Resu->h	= Ymax-Ymin;

	if(
			 ((Xmax-Xmin)>(Condition->WIDTH_MIN)) && ((Ymax-Ymin)>(Condition->HIGHT_MIN)) &&\
			 ((Xmax-Xmin)<(Condition->WIDTH_MAX)) && ((Ymax-Ymin)<(Condition->HIGHT_MAX))
	   )
		  return 1;	
	else
		  return 0;	
}



//从腐蚀中心向外腐蚀，得到新的腐蚀中心2
static int Corrode2(unsigned int oldx2,unsigned int oldy2,const TARGET_CONDI2 *Condition2,RESULT2 *Resu2)
{
	unsigned int Xmin,Xmax,Ymin,Ymax,i,FailCount=0;
	COLOR_RGB2 Rgb2;
	COLOR_HSL2 Hsl2;
	
	for(i=oldx2;i>IMG_X;i--)
		{
				ReadColor2(i,oldy2,&Rgb2);
				RGBtoHSL2(&Rgb2,&Hsl2);
				if(!ColorMatch2(&Hsl2,Condition2))
					FailCount++;
				if(FailCount>(((Condition2->WIDTH2_MIN+Condition2->WIDTH2_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Xmin=i;
	FailCount=0;
	
	for(i=oldx2;i<IMG_X+IMG_W;i++)
		{
				ReadColor2(i,oldy2,&Rgb2);
				RGBtoHSL2(&Rgb2,&Hsl2);
				if(!ColorMatch2(&Hsl2,Condition2))
					FailCount++;
				if(FailCount>(((Condition2->WIDTH2_MIN+Condition2->WIDTH2_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Xmax=i;
	FailCount=0;
	
	for(i=oldy2;i>IMG_Y;i--)
		{
				ReadColor2(oldx2,i,&Rgb2);
				RGBtoHSL2(&Rgb2,&Hsl2);
				if(!ColorMatch2(&Hsl2,Condition2))
					FailCount++;
				if(FailCount>(((Condition2->HIGHT2_MIN+Condition2->HIGHT2_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Ymin=i;
	FailCount=0;
	
	for(i=oldy2;i<IMG_Y+IMG_H;i++)
		{
				ReadColor2(oldx2,i,&Rgb2);
				RGBtoHSL2(&Rgb2,&Hsl2);
				if(!ColorMatch2(&Hsl2,Condition2))
					FailCount++;
				if(FailCount>(((Condition2->HIGHT2_MIN+Condition2->HIGHT2_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Ymax=i;
	FailCount=0;
	
	Resu2->x2	= (Xmin+Xmax)/2;
	Resu2->y2	= (Ymin+Ymax)/2;
	Resu2->w2	= Xmax-Xmin;
	Resu2->h2	= Ymax-Ymin;

	if(
			 ((Xmax-Xmin)>(Condition2->WIDTH2_MIN)) && ((Ymax-Ymin)>(Condition2->HIGHT2_MIN)) &&\
			 ((Xmax-Xmin)<(Condition2->WIDTH2_MAX)) && ((Ymax-Ymin)<(Condition2->HIGHT2_MAX))
	   )
		  return 1;	
	else
		  return 0;	
}




//从腐蚀中心向外腐蚀，得到新的腐蚀中心2
static int Corrode3(unsigned int oldx3,unsigned int oldy3,const TARGET_CONDI3 *Condition3,RESULT3 *Resu3)
{
	unsigned int Xmin,Xmax,Ymin,Ymax,i,FailCount=0;
	COLOR_RGB3 Rgb3;
	COLOR_HSL3 Hsl3;
	
	for(i=oldx3;i>IMG_X;i--)
		{
				ReadColor3(i,oldy3,&Rgb3);
				RGBtoHSL3(&Rgb3,&Hsl3);
				if(!ColorMatch3(&Hsl3,Condition3))
					FailCount++;
				if(FailCount>(((Condition3->WIDTH3_MIN+Condition3->WIDTH3_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Xmin=i;
	FailCount=0;
	
	for(i=oldx3;i<IMG_X+IMG_W;i++)
		{
				ReadColor3(i,oldy3,&Rgb3);
				RGBtoHSL3(&Rgb3,&Hsl3);
				if(!ColorMatch3(&Hsl3,Condition3))
					FailCount++;
				if(FailCount>(((Condition3->WIDTH3_MIN+Condition3->WIDTH3_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Xmax=i;
	FailCount=0;
	
	for(i=oldy3;i>IMG_Y;i--)
		{
				ReadColor3(oldx3,i,&Rgb3);
				RGBtoHSL3(&Rgb3,&Hsl3);
				if(!ColorMatch3(&Hsl3,Condition3))
					FailCount++;
				if(FailCount>(((Condition3->HIGHT3_MIN+Condition3->HIGHT3_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Ymin=i;
	FailCount=0;
	
	for(i=oldy3;i<IMG_Y+IMG_H;i++)
		{
				ReadColor3(oldx3,i,&Rgb3);
				RGBtoHSL3(&Rgb3,&Hsl3);
				if(!ColorMatch3(&Hsl3,Condition3))
					FailCount++;
				if(FailCount>(((Condition3->HIGHT3_MIN+Condition3->HIGHT3_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Ymax=i;
	FailCount=0;
	
	Resu3->x3	= (Xmin+Xmax)/2;
	Resu3->y3	= (Ymin+Ymax)/2;
	Resu3->w3	= Xmax-Xmin;
	Resu3->h3	= Ymax-Ymin;

	if(
			 ((Xmax-Xmin)>(Condition3->WIDTH3_MIN)) && ((Ymax-Ymin)>(Condition3->HIGHT3_MIN)) &&\
			 ((Xmax-Xmin)<(Condition3->WIDTH3_MAX)) && ((Ymax-Ymin)<(Condition3->HIGHT3_MAX))
	   )
		  return 1;	
	else
		  return 0;	
}


//从腐蚀中心向外腐蚀，得到新的腐蚀中心2
static int Corrode4(unsigned int oldx4,unsigned int oldy4,const TARGET_CONDI4 *Condition4,RESULT4 *Resu4)
{
	unsigned int Xmin,Xmax,Ymin,Ymax,i,FailCount=0;
	COLOR_RGB4 Rgb4;
	COLOR_HSL4 Hsl4;
	
	for(i=oldx4;i>IMG_X;i--)
		{
				ReadColor4(i,oldy4,&Rgb4);
				RGBtoHSL4(&Rgb4,&Hsl4);
				if(!ColorMatch4(&Hsl4,Condition4))
					FailCount++;
				if(FailCount>(((Condition4->WIDTH4_MIN+Condition4->WIDTH4_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Xmin=i;
	FailCount=0;
	
	for(i=oldx4;i<IMG_X+IMG_W;i++)
		{
				ReadColor4(i,oldy4,&Rgb4);
				RGBtoHSL4(&Rgb4,&Hsl4);
				if(!ColorMatch4(&Hsl4,Condition4))
					FailCount++;
				if(FailCount>(((Condition4->WIDTH4_MIN+Condition4->WIDTH4_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Xmax=i;
	FailCount=0;
	
	for(i=oldy4;i>IMG_Y;i--)
		{
				ReadColor4(oldx4,i,&Rgb4);
				RGBtoHSL4(&Rgb4,&Hsl4);
				if(!ColorMatch4(&Hsl4,Condition4))
					FailCount++;
				if(FailCount>(((Condition4->HIGHT4_MIN+Condition4->HIGHT4_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Ymin=i;
	FailCount=0;
	
	for(i=oldy4;i<IMG_Y+IMG_H;i++)
		{
				ReadColor4(oldx4,i,&Rgb4);
				RGBtoHSL4(&Rgb4,&Hsl4);
				if(!ColorMatch4(&Hsl4,Condition4))
					FailCount++;
				if(FailCount>(((Condition4->HIGHT4_MIN+Condition4->HIGHT4_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Ymax=i;
	FailCount=0;
	
	Resu4->x4	= (Xmin+Xmax)/2;
	Resu4->y4	= (Ymin+Ymax)/2;
	Resu4->w4	= Xmax-Xmin;
	Resu4->h4	= Ymax-Ymin;

	if(
			 ((Xmax-Xmin)>(Condition4->WIDTH4_MIN)) && ((Ymax-Ymin)>(Condition4->HIGHT4_MIN)) &&\
			 ((Xmax-Xmin)<(Condition4->WIDTH4_MAX)) && ((Ymax-Ymin)<(Condition4->HIGHT4_MAX))
	   )
		  return 1;	
	else
		  return 0;	
}



//从腐蚀中心向外腐蚀，得到新的腐蚀中心2
static int Corrode5(unsigned int oldx5,unsigned int oldy5,const TARGET_CONDI5 *Condition5,RESULT5 *Resu5)
{
	unsigned int Xmin,Xmax,Ymin,Ymax,i,FailCount=0;
	COLOR_RGB5 Rgb5;
	COLOR_HSL5 Hsl5;
	
	for(i=oldx5;i>IMG_X;i--)
		{
				ReadColor5(i,oldy5,&Rgb5);
				RGBtoHSL5(&Rgb5,&Hsl5);
				if(!ColorMatch5(&Hsl5,Condition5))
					FailCount++;
				if(FailCount>(((Condition5->WIDTH5_MIN+Condition5->WIDTH5_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Xmin=i;
	FailCount=0;
	
	for(i=oldx5;i<IMG_X+IMG_W;i++)
		{
				ReadColor5(i,oldy5,&Rgb5);
				RGBtoHSL5(&Rgb5,&Hsl5);
				if(!ColorMatch5(&Hsl5,Condition5))
					FailCount++;
				if(FailCount>(((Condition5->WIDTH5_MIN+Condition5->WIDTH5_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Xmax=i;
	FailCount=0;
	
	for(i=oldy5;i>IMG_Y;i--)
		{
				ReadColor5(oldx5,i,&Rgb5);
				RGBtoHSL5(&Rgb5,&Hsl5);
				if(!ColorMatch5(&Hsl5,Condition5))
					FailCount++;
				if(FailCount>(((Condition5->HIGHT5_MIN+Condition5->HIGHT5_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Ymin=i;
	FailCount=0;
	
	for(i=oldy5;i<IMG_Y+IMG_H;i++)
		{
				ReadColor5(oldx5,i,&Rgb5);
				RGBtoHSL5(&Rgb5,&Hsl5);
				if(!ColorMatch5(&Hsl5,Condition5))
					FailCount++;
				if(FailCount>(((Condition5->HIGHT5_MIN+Condition5->HIGHT5_MAX)>>2)>>ALLOW_FAIL_PER))
					break;	
		}
	Ymax=i;
	FailCount=0;
	
	Resu5->x5	= (Xmin+Xmax)/2;
	Resu5->y5	= (Ymin+Ymax)/2;
	Resu5->w5	= Xmax-Xmin;
	Resu5->h5	= Ymax-Ymin;

	if(
			 ((Xmax-Xmin)>(Condition5->WIDTH5_MIN)) && ((Ymax-Ymin)>(Condition5->HIGHT5_MIN)) &&\
			 ((Xmax-Xmin)<(Condition5->WIDTH5_MAX)) && ((Ymax-Ymin)<(Condition5->HIGHT5_MAX))
	   )
		  return 1;	
	else
		  return 0;	
}

//唯一的API，用户将识别条件写入Condition指向的结构体中，该函数将返回目标的x，y坐标和长宽
//返回1识别成功，返回1识别失败
int Trace(const TARGET_CONDI *Condition,RESULT *Resu)  //TARGET_CONDI识别条件  RESULT识别结果
{
	unsigned int i;
	static unsigned int x0,y0,flag=0;  //静态变量
	static SEARCH_AREA Area={IMG_X,IMG_X+IMG_W,IMG_Y,IMG_Y+IMG_H};  //x坐标 y坐标  w宽度  h高度
	RESULT Result;	//RESULT识别结果
	

	if(flag==0)    //已经定义
		{
			if(SearchCentre(&x0,&y0,Condition,&Area))  //搜索腐蚀中心   &是取地址运算符
				 flag=1;
			else
				{
						Area.X_Start= IMG_X	       ;
						Area.X_End  = IMG_X+IMG_W  ;
						Area.Y_Start= IMG_Y		     ;
						Area.Y_End  = IMG_Y+IMG_H  ;

						if(SearchCentre(&x0,&y0,Condition,&Area))	
						{
							flag=0;
							return 0;
						}	
				}
		}
	Result.x = x0;
	Result.y = y0;
	
	for(i=0;i<ITERATE_NUM;i++)  //进行迭代计算
		 Corrode(Result.x,Result.y,Condition,&Result);
		
	if(Corrode(Result.x,Result.y,Condition,&Result))//从腐蚀中心向外腐蚀
		{
			x0=Result.x;
			y0=Result.y;
			Resu->x=Result.x;
			Resu->y=Result.y;
			Resu->w=Result.w;
			Resu->h=Result.h;
			flag=1;

			Area.X_Start= Result.x - ((Result.w)>>1);
			Area.X_End  = Result.x + ((Result.w)>>1);
			Area.Y_Start= Result.y - ((Result.h)>>1);
			Area.Y_End  = Result.y + ((Result.h)>>1);


			return 1;
		}
	else
		{
			flag=0;
			return 0;
		}

}
int Trace2(const TARGET_CONDI2 *Condition2,RESULT2 *Resu2)  //TARGET_CONDI识别条件  RESULT识别结果
{
	unsigned int i;
	static unsigned int x0,y0,flag=0;  //静态变量
	static SEARCH_AREA2 Area2={IMG_X2,IMG_X2+IMG_W2,IMG_Y2,IMG_Y2+IMG_H2};  //x坐标 y坐标  w宽度  h高度
	RESULT2 Result2;	//RESULT识别结果
	

	if(flag==0)    //已经定义
		{
			if(SearchCentre2(&x0,&y0,Condition2,&Area2))  //搜索腐蚀中心   &是取地址运算符
				 flag=1;
			else
				{
						Area2.X2_Start= IMG_X2	       ;
						Area2.X2_End  = IMG_X2+IMG_W2  ;
						Area2.Y2_Start= IMG_Y2		     ;
						Area2.Y2_End  = IMG_Y2+IMG_H2  ;

						if(SearchCentre2(&x0,&y0,Condition2,&Area2))	
						{
							flag=0;
							return 0;
						}	
				}
		}
	Result2.x2 = x0;
	Result2.y2 = y0;
	
	for(i=0;i<ITERATE_NUM;i++)  //进行迭代计算
		 Corrode2(Result2.x2,Result2.y2,Condition2,&Result2);
		
	if(Corrode2(Result2.x2,Result2.y2,Condition2,&Result2))//从腐蚀中心向外腐蚀
		{
			x0=Result2.x2;
			y0=Result2.y2;
			Resu2->x2=Result2.x2;
			Resu2->y2=Result2.y2;
			Resu2->w2=Result2.w2;
			Resu2->h2=Result2.h2;
			flag=1;

			Area2.X2_Start= Result2.x2 - ((Result2.w2)>>1);
			Area2.X2_End  = Result2.x2 + ((Result2.w2)>>1);
			Area2.Y2_Start= Result2.y2 - ((Result2.h2)>>1);
			Area2.Y2_End  = Result2.y2 + ((Result2.h2)>>1);


			return 1;
		}
	else
		{
			flag=0;
			return 0;
		}

}

int Trace3(const TARGET_CONDI3 *Condition3,RESULT3 *Resu3)  //TARGET_CONDI识别条件  RESULT识别结果
{
	unsigned int i;
	static unsigned int x0,y0,flag=0;  //静态变量
	static SEARCH_AREA3 Area3={IMG_X3,IMG_X3+IMG_W3,IMG_Y3,IMG_Y3+IMG_H3};  //x坐标 y坐标  w宽度  h高度
	RESULT3 Result3;	//RESULT识别结果
	

	if(flag==0)    //已经定义
		{
			if(SearchCentre3(&x0,&y0,Condition3,&Area3))  //搜索腐蚀中心   &是取地址运算符
				 flag=1;
			else
				{
						Area3.X3_Start= IMG_X3	       ;
						Area3.X3_End  = IMG_X3+IMG_W3  ;
						Area3.Y3_Start= IMG_Y3		     ;
						Area3.Y3_End  = IMG_Y3+IMG_H3  ;

						if(SearchCentre3(&x0,&y0,Condition3,&Area3))	
						{
							flag=0;
							return 0;
						}	
				}
		}
	Result3.x3 = x0;
	Result3.y3 = y0;
	
	for(i=0;i<ITERATE_NUM;i++)  //进行迭代计算
		 Corrode3(Result3.x3,Result3.y3,Condition3,&Result3);
		
	if(Corrode3(Result3.x3,Result3.y3,Condition3,&Result3))//从腐蚀中心向外腐蚀
		{
			x0=Result3.x3;
			y0=Result3.y3;
			Resu3->x3=Result3.x3;
			Resu3->y3=Result3.y3;
			Resu3->w3=Result3.w3;
			Resu3->h3=Result3.h3;
			flag=1;

			Area3.X3_Start= Result3.x3 - ((Result3.w3)>>1);
			Area3.X3_End  = Result3.x3 + ((Result3.w3)>>1);
			Area3.Y3_Start= Result3.y3 - ((Result3.h3)>>1);
			Area3.Y3_End  = Result3.y3 + ((Result3.h3)>>1);


			return 1;
		}
	else
		{
			flag=0;
			return 0;
		}

}

int Trace4(const TARGET_CONDI4 *Condition4,RESULT4 *Resu4)  //TARGET_CONDI识别条件  RESULT识别结果
{
	unsigned int i;
	static unsigned int x0,y0,flag=0;  //静态变量
	static SEARCH_AREA4 Area4={IMG_X4,IMG_X4+IMG_W4,IMG_Y4,IMG_Y4+IMG_H4};  //x坐标 y坐标  w宽度  h高度
	RESULT4 Result4;	//RESULT识别结果
	

	if(flag==0)    //已经定义
		{
			if(SearchCentre4(&x0,&y0,Condition4,&Area4))  //搜索腐蚀中心   &是取地址运算符
				 flag=1;
			else
				{
						Area4.X4_Start= IMG_X4	       ;
						Area4.X4_End  = IMG_X4+IMG_W4  ;
						Area4.Y4_Start= IMG_Y4		     ;
						Area4.Y4_End  = IMG_Y4+IMG_H4  ;

						if(SearchCentre4(&x0,&y0,Condition4,&Area4))	
						{
							flag=0;
							return 0;
						}	
				}
		}
	Result4.x4 = x0;
	Result4.y4 = y0;
	
	for(i=0;i<ITERATE_NUM;i++)  //进行迭代计算
		 Corrode4(Result4.x4,Result4.y4,Condition4,&Result4);
		
	if(Corrode4(Result4.x4,Result4.y4,Condition4,&Result4))//从腐蚀中心向外腐蚀
		{
			x0=Result4.x4;
			y0=Result4.y4;
			Resu4->x4=Result4.x4;
			Resu4->y4=Result4.y4;
			Resu4->w4=Result4.w4;
			Resu4->h4=Result4.h4;
			flag=1;

			Area4.X4_Start= Result4.x4 - ((Result4.w4)>>1);
			Area4.X4_End  = Result4.x4 + ((Result4.w4)>>1);
			Area4.Y4_Start= Result4.y4 - ((Result4.h4)>>1);
			Area4.Y4_End  = Result4.y4 + ((Result4.h4)>>1);


			return 1;
		}
	else
		{
			flag=0;
			return 0;
		}

}


int Trace5(const TARGET_CONDI5 *Condition5,RESULT5 *Resu5)  //TARGET_CONDI识别条件  RESULT识别结果
{
	unsigned int i;
	static unsigned int x0,y0,flag=0;  //静态变量
	static SEARCH_AREA5 Area5={IMG_X5,IMG_X5+IMG_W5,IMG_Y5,IMG_Y5+IMG_H5};  //x坐标 y坐标  w宽度  h高度
	RESULT5 Result5;	//RESULT识别结果
	
	

	if(flag==0)    //已经定义
		{
			if(SearchCentre5(&x0,&y0,Condition5,&Area5))  //搜索腐蚀中心   &是取地址运算符
				 flag=1;
			else
				{
						Area5.X5_Start= IMG_X5	       ;
						Area5.X5_End  = IMG_X5+IMG_W5  ;
						Area5.Y5_Start= IMG_Y5		     ;
						Area5.Y5_End  = IMG_Y5+IMG_H5  ;

						if(SearchCentre5(&x0,&y0,Condition5,&Area5))	
						{
							flag=0;
							return 0;
						}	
				}
		}
	Result5.x5 = x0;
	Result5.y5 = y0;
	
	for(i=0;i<ITERATE_NUM;i++)  //进行迭代计算
		 Corrode5(Result5.x5,Result5.y5,Condition5,&Result5);
		
	if(Corrode5(Result5.x5,Result5.y5,Condition5,&Result5))//从腐蚀中心向外腐蚀
		{
			x0=Result5.x5;
			y0=Result5.y5;
			Resu5->x5=Result5.x5;
			Resu5->y5=Result5.y5;
			Resu5->w5=Result5.w5;
			Resu5->h5=Result5.h5;
			flag=1;

			Area5.X5_Start= Result5.x5 - ((Result5.w5)>>1);
			Area5.X5_End  = Result5.x5 + ((Result5.w5)>>1);
			Area5.Y5_Start= Result5.y5 - ((Result5.h5)>>1);
			Area5.Y5_End  = Result5.y5 + ((Result5.h5)>>1);


			return 1;
		}
	else
		{
			flag=0;
			return 0;
		}

}
