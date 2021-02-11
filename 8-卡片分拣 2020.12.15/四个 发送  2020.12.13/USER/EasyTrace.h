//#ifndef EASY_TRACE_H
//#define EASY_TRACE_H

//#define IMG_X 0	  //图片x坐标
//#define IMG_Y 0	  //图片y坐标
//#define IMG_W 320 //图片宽度
//#define IMG_H 240 //图片高度

//#define IMG_X2 0	  //图片x坐标
//#define IMG_Y2 0	  //图片y坐标
//#define IMG_W2 320 //图片宽度
//#define IMG_H2 240 //图片高度

//#define IMG_X3 0	  //图片x坐标
//#define IMG_Y3 0	  //图片y坐标
//#define IMG_W3 320 //图片宽度
//#define IMG_H3 240 //图片高度

//#define IMG_X4 0	  //图片x坐标
//#define IMG_Y4 0	  //图片y坐标
//#define IMG_W4 320 //图片宽度
//#define IMG_H4 240 //图片高度

//#define IMG_X5 0	  //图片x坐标
//#define IMG_Y5 0	  //图片y坐标
//#define IMG_W5 320 //图片宽度
//#define IMG_H5 240 //图片高度

//#define ALLOW_FAIL_PER 3 //容错率，每1<<ALLOW_FAIL_PER个点允许出现一个错误点，容错率越大越容易识别，但错误率越大
//#define ITERATE_NUM    8 //迭代次数，迭代次数越多识别越精确，但计算量越大

//typedef struct{
//    unsigned char  H_MIN;//目标最小色调
//    unsigned char  H_MAX;//目标最大色调	
//    
//	unsigned char  S_MIN;//目标最小饱和度  
//    unsigned char  S_MAX;//目标最大饱和度
//	
//	unsigned char  L_MIN;//目标最小亮度  
//    unsigned char  L_MAX;//目标最大亮度
//	
//	unsigned int  WIDTH_MIN;//目标最小宽度
//	unsigned int  HIGHT_MIN;//目标最小高度

//	unsigned int  WIDTH_MAX;//目标最大宽度
//	unsigned int  HIGHT_MAX;//目标最大高度

//}TARGET_CONDI;//判定为的目标条件

//typedef struct{
//    unsigned char  H2_MIN;//目标最小色调
//    unsigned char  H2_MAX;//目标最大色调	
//    
//	unsigned char  S2_MIN;//目标最小饱和度  
//    unsigned char  S2_MAX;//目标最大饱和度
//	
//	unsigned char  L2_MIN;//目标最小亮度  
//    unsigned char  L2_MAX;//目标最大亮度
//	
//	unsigned int  WIDTH2_MIN;//目标最小宽度
//	unsigned int  HIGHT2_MIN;//目标最小高度

//	unsigned int  WIDTH2_MAX;//目标最大宽度
//	unsigned int  HIGHT2_MAX;//目标最大高度

//}TARGET_CONDI2;//判定为的目标条件

//typedef struct{
//    unsigned char  H3_MIN;//目标最小色调
//    unsigned char  H3_MAX;//目标最大色调	
//    
//	unsigned char  S3_MIN;//目标最小饱和度  
//    unsigned char  S3_MAX;//目标最大饱和度
//	
//	unsigned char  L3_MIN;//目标最小亮度  
//    unsigned char  L3_MAX;//目标最大亮度
//	
//	unsigned int  WIDTH3_MIN;//目标最小宽度
//	unsigned int  HIGHT3_MIN;//目标最小高度

//	unsigned int  WIDTH3_MAX;//目标最大宽度
//	unsigned int  HIGHT3_MAX;//目标最大高度

//}TARGET_CONDI3;//判定为的目标条件


//typedef struct{
//    unsigned char  H4_MIN;//目标最小色调
//    unsigned char  H4_MAX;//目标最大色调	
//    
//	unsigned char  S4_MIN;//目标最小饱和度  
//    unsigned char  S4_MAX;//目标最大饱和度
//	
//	unsigned char  L4_MIN;//目标最小亮度  
//    unsigned char  L4_MAX;//目标最大亮度
//	
//	unsigned int  WIDTH4_MIN;//目标最小宽度
//	unsigned int  HIGHT4_MIN;//目标最小高度

//	unsigned int  WIDTH4_MAX;//目标最大宽度
//	unsigned int  HIGHT4_MAX;//目标最大高度

//}TARGET_CONDI4;//判定为的目标条件

//typedef struct{
//    unsigned char  H5_MIN;//目标最小色调
//    unsigned char  H5_MAX;//目标最大色调	
//    
//	unsigned char  S5_MIN;//目标最小饱和度  
//    unsigned char  S5_MAX;//目标最大饱和度
//	
//	unsigned char  L5_MIN;//目标最小亮度  
//    unsigned char  L5_MAX;//目标最大亮度
//	
//	unsigned int  WIDTH5_MIN;//目标最小宽度
//	unsigned int  HIGHT5_MIN;//目标最小高度

//	unsigned int  WIDTH5_MAX;//目标最大宽度
//	unsigned int  HIGHT5_MAX;//目标最大高度

//}TARGET_CONDI5;//判定为的目标条件

//typedef struct{
//	unsigned int x;//目标的x坐标
//	unsigned int y;//目标的y坐标
//	unsigned int w;//目标的宽度
//	unsigned int h;//目标的高度
//}RESULT;//识别结果

//typedef struct{
//	unsigned int x2;//目标的x坐标
//	unsigned int y2;//目标的y坐标
//	unsigned int w2;//目标的宽度
//	unsigned int h2;//目标的高度
//}RESULT2;//识别结果

//typedef struct{
//	unsigned int x3;//目标的x坐标
//	unsigned int y3;//目标的y坐标
//	unsigned int w3;//目标的宽度
//	unsigned int h3;//目标的高度
//}RESULT3;//识别结果


//typedef struct{
//	unsigned int x4;//目标的x坐标
//	unsigned int y4;//目标的y坐标
//	unsigned int w4;//目标的宽度
//	unsigned int h4;//目标的高度
//}RESULT4;//识别结果

//typedef struct{
//	unsigned int x5;//目标的x坐标
//	unsigned int y5;//目标的y坐标
//	unsigned int w5;//目标的宽度
//	unsigned int h5;//目标的高度
//}RESULT5;//识别结果

////唯一的API，用户将识别条件写入Condition指向的结构体中，该函数将返回目标的x，y坐标和长宽
////返回1识别成功，返回1识别失败
//int Trace(const TARGET_CONDI *Condition,RESULT *Resu);
//int Trace2(const TARGET_CONDI2 *Condition,RESULT2 *Resu);
//int Trace3(const TARGET_CONDI3 *Condition,RESULT3 *Resu);
//int Trace4(const TARGET_CONDI4 *Condition,RESULT4 *Resu);
//int Trace5(const TARGET_CONDI5 *Condition,RESULT5 *Resu);
//#endif
#ifndef EASY_TRACE_H
#define EASY_TRACE_H

#define IMG_X 0	  //图片x坐标
#define IMG_Y 0	  //图片y坐标
#define IMG_W 320 //图片宽度
#define IMG_H 240 //图片高度

#define IMG_X2 0	  //图片x坐标
#define IMG_Y2 0	  //图片y坐标
#define IMG_W2 320 //图片宽度
#define IMG_H2 240 //图片高度

#define IMG_X3 0	  //图片x坐标
#define IMG_Y3 0	  //图片y坐标
#define IMG_W3 320 //图片宽度
#define IMG_H3 240 //图片高度

#define IMG_X4 0	  //图片x坐标
#define IMG_Y4 0	  //图片y坐标
#define IMG_W4 320 //图片宽度
#define IMG_H4 240 //图片高度

#define IMG_X5 0	  //图片x坐标
#define IMG_Y5 0	  //图片y坐标
#define IMG_W5 320 //图片宽度
#define IMG_H5 240 //图片高度

#define ALLOW_FAIL_PER 3 //容错率，每1<<ALLOW_FAIL_PER个点允许出现一个错误点，容错率越大越容易识别，但错误率越大
#define ITERATE_NUM    8 //迭代次数，迭代次数越多识别越精确，但计算量越大

typedef struct{
    unsigned char  H_MIN;//目标最小色调
    unsigned char  H_MAX;//目标最大色调	
    
	unsigned char  S_MIN;//目标最小饱和度  
    unsigned char  S_MAX;//目标最大饱和度
	
	unsigned char  L_MIN;//目标最小亮度  
    unsigned char  L_MAX;//目标最大亮度
	
	unsigned int  WIDTH_MIN;//目标最小宽度
	unsigned int  HIGHT_MIN;//目标最小高度

	unsigned int  WIDTH_MAX;//目标最大宽度
	unsigned int  HIGHT_MAX;//目标最大高度

}TARGET_CONDI;//判定为的目标条件

typedef struct{
    unsigned char  H2_MIN;//目标最小色调
    unsigned char  H2_MAX;//目标最大色调	
    
	unsigned char  S2_MIN;//目标最小饱和度  
    unsigned char  S2_MAX;//目标最大饱和度
	
	unsigned char  L2_MIN;//目标最小亮度  
    unsigned char  L2_MAX;//目标最大亮度
	
	unsigned int  WIDTH2_MIN;//目标最小宽度
	unsigned int  HIGHT2_MIN;//目标最小高度

	unsigned int  WIDTH2_MAX;//目标最大宽度
	unsigned int  HIGHT2_MAX;//目标最大高度

}TARGET_CONDI2;//判定为的目标条件

typedef struct{
    unsigned char  H3_MIN;//目标最小色调
    unsigned char  H3_MAX;//目标最大色调	
    
	unsigned char  S3_MIN;//目标最小饱和度  
    unsigned char  S3_MAX;//目标最大饱和度
	
	unsigned char  L3_MIN;//目标最小亮度  
    unsigned char  L3_MAX;//目标最大亮度
	
	unsigned int  WIDTH3_MIN;//目标最小宽度
	unsigned int  HIGHT3_MIN;//目标最小高度

	unsigned int  WIDTH3_MAX;//目标最大宽度
	unsigned int  HIGHT3_MAX;//目标最大高度

}TARGET_CONDI3;//判定为的目标条件


typedef struct{
    unsigned char  H4_MIN;//目标最小色调
    unsigned char  H4_MAX;//目标最大色调	
    
	unsigned char  S4_MIN;//目标最小饱和度  
    unsigned char  S4_MAX;//目标最大饱和度
	
	unsigned char  L4_MIN;//目标最小亮度  
    unsigned char  L4_MAX;//目标最大亮度
	
	unsigned int  WIDTH4_MIN;//目标最小宽度
	unsigned int  HIGHT4_MIN;//目标最小高度

	unsigned int  WIDTH4_MAX;//目标最大宽度
	unsigned int  HIGHT4_MAX;//目标最大高度

}TARGET_CONDI4;//判定为的目标条件

typedef struct{
    unsigned char  H5_MIN;//目标最小色调
    unsigned char  H5_MAX;//目标最大色调	
    
	unsigned char  S5_MIN;//目标最小饱和度  
    unsigned char  S5_MAX;//目标最大饱和度
	
	unsigned char  L5_MIN;//目标最小亮度  
    unsigned char  L5_MAX;//目标最大亮度
	
	unsigned int  WIDTH5_MIN;//目标最小宽度
	unsigned int  HIGHT5_MIN;//目标最小高度

	unsigned int  WIDTH5_MAX;//目标最大宽度
	unsigned int  HIGHT5_MAX;//目标最大高度

}TARGET_CONDI5;//判定为的目标条件

typedef struct{
	unsigned int x;//目标的x坐标
	unsigned int y;//目标的y坐标
	unsigned int w;//目标的宽度
	unsigned int h;//目标的高度
}RESULT;//识别结果

typedef struct{
	unsigned int x2;//目标的x坐标
	unsigned int y2;//目标的y坐标
	unsigned int w2;//目标的宽度
	unsigned int h2;//目标的高度
}RESULT2;//识别结果

typedef struct{
	unsigned int x3;//目标的x坐标
	unsigned int y3;//目标的y坐标
	unsigned int w3;//目标的宽度
	unsigned int h3;//目标的高度
}RESULT3;//识别结果


typedef struct{
	unsigned int x4;//目标的x坐标
	unsigned int y4;//目标的y坐标
	unsigned int w4;//目标的宽度
	unsigned int h4;//目标的高度
}RESULT4;//识别结果

typedef struct{
	unsigned int x5;//目标的x坐标
	unsigned int y5;//目标的y坐标
	unsigned int w5;//目标的宽度
	unsigned int h5;//目标的高度
}RESULT5;//识别结果

//唯一的API，用户将识别条件写入Condition指向的结构体中，该函数将返回目标的x，y坐标和长宽
//返回1识别成功，返回1识别失败
int Trace(const TARGET_CONDI *Condition,RESULT *Resu);
int Trace2(const TARGET_CONDI2 *Condition,RESULT2 *Resu);
int Trace3(const TARGET_CONDI3 *Condition,RESULT3 *Resu);
int Trace4(const TARGET_CONDI4 *Condition,RESULT4 *Resu);
int Trace5(const TARGET_CONDI5 *Condition,RESULT5 *Resu);
#endif








