//#ifndef EASY_TRACE_H
//#define EASY_TRACE_H

//#define IMG_X 0	  //ͼƬx����
//#define IMG_Y 0	  //ͼƬy����
//#define IMG_W 320 //ͼƬ���
//#define IMG_H 240 //ͼƬ�߶�

//#define IMG_X2 0	  //ͼƬx����
//#define IMG_Y2 0	  //ͼƬy����
//#define IMG_W2 320 //ͼƬ���
//#define IMG_H2 240 //ͼƬ�߶�

//#define IMG_X3 0	  //ͼƬx����
//#define IMG_Y3 0	  //ͼƬy����
//#define IMG_W3 320 //ͼƬ���
//#define IMG_H3 240 //ͼƬ�߶�

//#define IMG_X4 0	  //ͼƬx����
//#define IMG_Y4 0	  //ͼƬy����
//#define IMG_W4 320 //ͼƬ���
//#define IMG_H4 240 //ͼƬ�߶�

//#define IMG_X5 0	  //ͼƬx����
//#define IMG_Y5 0	  //ͼƬy����
//#define IMG_W5 320 //ͼƬ���
//#define IMG_H5 240 //ͼƬ�߶�

//#define ALLOW_FAIL_PER 3 //�ݴ��ʣ�ÿ1<<ALLOW_FAIL_PER�����������һ������㣬�ݴ���Խ��Խ����ʶ�𣬵�������Խ��
//#define ITERATE_NUM    8 //������������������Խ��ʶ��Խ��ȷ����������Խ��

//typedef struct{
//    unsigned char  H_MIN;//Ŀ����Сɫ��
//    unsigned char  H_MAX;//Ŀ�����ɫ��	
//    
//	unsigned char  S_MIN;//Ŀ����С���Ͷ�  
//    unsigned char  S_MAX;//Ŀ����󱥺Ͷ�
//	
//	unsigned char  L_MIN;//Ŀ����С����  
//    unsigned char  L_MAX;//Ŀ���������
//	
//	unsigned int  WIDTH_MIN;//Ŀ����С���
//	unsigned int  HIGHT_MIN;//Ŀ����С�߶�

//	unsigned int  WIDTH_MAX;//Ŀ�������
//	unsigned int  HIGHT_MAX;//Ŀ�����߶�

//}TARGET_CONDI;//�ж�Ϊ��Ŀ������

//typedef struct{
//    unsigned char  H2_MIN;//Ŀ����Сɫ��
//    unsigned char  H2_MAX;//Ŀ�����ɫ��	
//    
//	unsigned char  S2_MIN;//Ŀ����С���Ͷ�  
//    unsigned char  S2_MAX;//Ŀ����󱥺Ͷ�
//	
//	unsigned char  L2_MIN;//Ŀ����С����  
//    unsigned char  L2_MAX;//Ŀ���������
//	
//	unsigned int  WIDTH2_MIN;//Ŀ����С���
//	unsigned int  HIGHT2_MIN;//Ŀ����С�߶�

//	unsigned int  WIDTH2_MAX;//Ŀ�������
//	unsigned int  HIGHT2_MAX;//Ŀ�����߶�

//}TARGET_CONDI2;//�ж�Ϊ��Ŀ������

//typedef struct{
//    unsigned char  H3_MIN;//Ŀ����Сɫ��
//    unsigned char  H3_MAX;//Ŀ�����ɫ��	
//    
//	unsigned char  S3_MIN;//Ŀ����С���Ͷ�  
//    unsigned char  S3_MAX;//Ŀ����󱥺Ͷ�
//	
//	unsigned char  L3_MIN;//Ŀ����С����  
//    unsigned char  L3_MAX;//Ŀ���������
//	
//	unsigned int  WIDTH3_MIN;//Ŀ����С���
//	unsigned int  HIGHT3_MIN;//Ŀ����С�߶�

//	unsigned int  WIDTH3_MAX;//Ŀ�������
//	unsigned int  HIGHT3_MAX;//Ŀ�����߶�

//}TARGET_CONDI3;//�ж�Ϊ��Ŀ������


//typedef struct{
//    unsigned char  H4_MIN;//Ŀ����Сɫ��
//    unsigned char  H4_MAX;//Ŀ�����ɫ��	
//    
//	unsigned char  S4_MIN;//Ŀ����С���Ͷ�  
//    unsigned char  S4_MAX;//Ŀ����󱥺Ͷ�
//	
//	unsigned char  L4_MIN;//Ŀ����С����  
//    unsigned char  L4_MAX;//Ŀ���������
//	
//	unsigned int  WIDTH4_MIN;//Ŀ����С���
//	unsigned int  HIGHT4_MIN;//Ŀ����С�߶�

//	unsigned int  WIDTH4_MAX;//Ŀ�������
//	unsigned int  HIGHT4_MAX;//Ŀ�����߶�

//}TARGET_CONDI4;//�ж�Ϊ��Ŀ������

//typedef struct{
//    unsigned char  H5_MIN;//Ŀ����Сɫ��
//    unsigned char  H5_MAX;//Ŀ�����ɫ��	
//    
//	unsigned char  S5_MIN;//Ŀ����С���Ͷ�  
//    unsigned char  S5_MAX;//Ŀ����󱥺Ͷ�
//	
//	unsigned char  L5_MIN;//Ŀ����С����  
//    unsigned char  L5_MAX;//Ŀ���������
//	
//	unsigned int  WIDTH5_MIN;//Ŀ����С���
//	unsigned int  HIGHT5_MIN;//Ŀ����С�߶�

//	unsigned int  WIDTH5_MAX;//Ŀ�������
//	unsigned int  HIGHT5_MAX;//Ŀ�����߶�

//}TARGET_CONDI5;//�ж�Ϊ��Ŀ������

//typedef struct{
//	unsigned int x;//Ŀ���x����
//	unsigned int y;//Ŀ���y����
//	unsigned int w;//Ŀ��Ŀ��
//	unsigned int h;//Ŀ��ĸ߶�
//}RESULT;//ʶ����

//typedef struct{
//	unsigned int x2;//Ŀ���x����
//	unsigned int y2;//Ŀ���y����
//	unsigned int w2;//Ŀ��Ŀ��
//	unsigned int h2;//Ŀ��ĸ߶�
//}RESULT2;//ʶ����

//typedef struct{
//	unsigned int x3;//Ŀ���x����
//	unsigned int y3;//Ŀ���y����
//	unsigned int w3;//Ŀ��Ŀ��
//	unsigned int h3;//Ŀ��ĸ߶�
//}RESULT3;//ʶ����


//typedef struct{
//	unsigned int x4;//Ŀ���x����
//	unsigned int y4;//Ŀ���y����
//	unsigned int w4;//Ŀ��Ŀ��
//	unsigned int h4;//Ŀ��ĸ߶�
//}RESULT4;//ʶ����

//typedef struct{
//	unsigned int x5;//Ŀ���x����
//	unsigned int y5;//Ŀ���y����
//	unsigned int w5;//Ŀ��Ŀ��
//	unsigned int h5;//Ŀ��ĸ߶�
//}RESULT5;//ʶ����

////Ψһ��API���û���ʶ������д��Conditionָ��Ľṹ���У��ú���������Ŀ���x��y����ͳ���
////����1ʶ��ɹ�������1ʶ��ʧ��
//int Trace(const TARGET_CONDI *Condition,RESULT *Resu);
//int Trace2(const TARGET_CONDI2 *Condition,RESULT2 *Resu);
//int Trace3(const TARGET_CONDI3 *Condition,RESULT3 *Resu);
//int Trace4(const TARGET_CONDI4 *Condition,RESULT4 *Resu);
//int Trace5(const TARGET_CONDI5 *Condition,RESULT5 *Resu);
//#endif
#ifndef EASY_TRACE_H
#define EASY_TRACE_H

#define IMG_X 0	  //ͼƬx����
#define IMG_Y 0	  //ͼƬy����
#define IMG_W 320 //ͼƬ���
#define IMG_H 240 //ͼƬ�߶�

#define IMG_X2 0	  //ͼƬx����
#define IMG_Y2 0	  //ͼƬy����
#define IMG_W2 320 //ͼƬ���
#define IMG_H2 240 //ͼƬ�߶�

#define IMG_X3 0	  //ͼƬx����
#define IMG_Y3 0	  //ͼƬy����
#define IMG_W3 320 //ͼƬ���
#define IMG_H3 240 //ͼƬ�߶�

#define IMG_X4 0	  //ͼƬx����
#define IMG_Y4 0	  //ͼƬy����
#define IMG_W4 320 //ͼƬ���
#define IMG_H4 240 //ͼƬ�߶�

#define IMG_X5 0	  //ͼƬx����
#define IMG_Y5 0	  //ͼƬy����
#define IMG_W5 320 //ͼƬ���
#define IMG_H5 240 //ͼƬ�߶�

#define ALLOW_FAIL_PER 3 //�ݴ��ʣ�ÿ1<<ALLOW_FAIL_PER�����������һ������㣬�ݴ���Խ��Խ����ʶ�𣬵�������Խ��
#define ITERATE_NUM    8 //������������������Խ��ʶ��Խ��ȷ����������Խ��

typedef struct{
    unsigned char  H_MIN;//Ŀ����Сɫ��
    unsigned char  H_MAX;//Ŀ�����ɫ��	
    
	unsigned char  S_MIN;//Ŀ����С���Ͷ�  
    unsigned char  S_MAX;//Ŀ����󱥺Ͷ�
	
	unsigned char  L_MIN;//Ŀ����С����  
    unsigned char  L_MAX;//Ŀ���������
	
	unsigned int  WIDTH_MIN;//Ŀ����С���
	unsigned int  HIGHT_MIN;//Ŀ����С�߶�

	unsigned int  WIDTH_MAX;//Ŀ�������
	unsigned int  HIGHT_MAX;//Ŀ�����߶�

}TARGET_CONDI;//�ж�Ϊ��Ŀ������

typedef struct{
    unsigned char  H2_MIN;//Ŀ����Сɫ��
    unsigned char  H2_MAX;//Ŀ�����ɫ��	
    
	unsigned char  S2_MIN;//Ŀ����С���Ͷ�  
    unsigned char  S2_MAX;//Ŀ����󱥺Ͷ�
	
	unsigned char  L2_MIN;//Ŀ����С����  
    unsigned char  L2_MAX;//Ŀ���������
	
	unsigned int  WIDTH2_MIN;//Ŀ����С���
	unsigned int  HIGHT2_MIN;//Ŀ����С�߶�

	unsigned int  WIDTH2_MAX;//Ŀ�������
	unsigned int  HIGHT2_MAX;//Ŀ�����߶�

}TARGET_CONDI2;//�ж�Ϊ��Ŀ������

typedef struct{
    unsigned char  H3_MIN;//Ŀ����Сɫ��
    unsigned char  H3_MAX;//Ŀ�����ɫ��	
    
	unsigned char  S3_MIN;//Ŀ����С���Ͷ�  
    unsigned char  S3_MAX;//Ŀ����󱥺Ͷ�
	
	unsigned char  L3_MIN;//Ŀ����С����  
    unsigned char  L3_MAX;//Ŀ���������
	
	unsigned int  WIDTH3_MIN;//Ŀ����С���
	unsigned int  HIGHT3_MIN;//Ŀ����С�߶�

	unsigned int  WIDTH3_MAX;//Ŀ�������
	unsigned int  HIGHT3_MAX;//Ŀ�����߶�

}TARGET_CONDI3;//�ж�Ϊ��Ŀ������


typedef struct{
    unsigned char  H4_MIN;//Ŀ����Сɫ��
    unsigned char  H4_MAX;//Ŀ�����ɫ��	
    
	unsigned char  S4_MIN;//Ŀ����С���Ͷ�  
    unsigned char  S4_MAX;//Ŀ����󱥺Ͷ�
	
	unsigned char  L4_MIN;//Ŀ����С����  
    unsigned char  L4_MAX;//Ŀ���������
	
	unsigned int  WIDTH4_MIN;//Ŀ����С���
	unsigned int  HIGHT4_MIN;//Ŀ����С�߶�

	unsigned int  WIDTH4_MAX;//Ŀ�������
	unsigned int  HIGHT4_MAX;//Ŀ�����߶�

}TARGET_CONDI4;//�ж�Ϊ��Ŀ������

typedef struct{
    unsigned char  H5_MIN;//Ŀ����Сɫ��
    unsigned char  H5_MAX;//Ŀ�����ɫ��	
    
	unsigned char  S5_MIN;//Ŀ����С���Ͷ�  
    unsigned char  S5_MAX;//Ŀ����󱥺Ͷ�
	
	unsigned char  L5_MIN;//Ŀ����С����  
    unsigned char  L5_MAX;//Ŀ���������
	
	unsigned int  WIDTH5_MIN;//Ŀ����С���
	unsigned int  HIGHT5_MIN;//Ŀ����С�߶�

	unsigned int  WIDTH5_MAX;//Ŀ�������
	unsigned int  HIGHT5_MAX;//Ŀ�����߶�

}TARGET_CONDI5;//�ж�Ϊ��Ŀ������

typedef struct{
	unsigned int x;//Ŀ���x����
	unsigned int y;//Ŀ���y����
	unsigned int w;//Ŀ��Ŀ��
	unsigned int h;//Ŀ��ĸ߶�
}RESULT;//ʶ����

typedef struct{
	unsigned int x2;//Ŀ���x����
	unsigned int y2;//Ŀ���y����
	unsigned int w2;//Ŀ��Ŀ��
	unsigned int h2;//Ŀ��ĸ߶�
}RESULT2;//ʶ����

typedef struct{
	unsigned int x3;//Ŀ���x����
	unsigned int y3;//Ŀ���y����
	unsigned int w3;//Ŀ��Ŀ��
	unsigned int h3;//Ŀ��ĸ߶�
}RESULT3;//ʶ����


typedef struct{
	unsigned int x4;//Ŀ���x����
	unsigned int y4;//Ŀ���y����
	unsigned int w4;//Ŀ��Ŀ��
	unsigned int h4;//Ŀ��ĸ߶�
}RESULT4;//ʶ����

typedef struct{
	unsigned int x5;//Ŀ���x����
	unsigned int y5;//Ŀ���y����
	unsigned int w5;//Ŀ��Ŀ��
	unsigned int h5;//Ŀ��ĸ߶�
}RESULT5;//ʶ����

//Ψһ��API���û���ʶ������д��Conditionָ��Ľṹ���У��ú���������Ŀ���x��y����ͳ���
//����1ʶ��ɹ�������1ʶ��ʧ��
int Trace(const TARGET_CONDI *Condition,RESULT *Resu);
int Trace2(const TARGET_CONDI2 *Condition,RESULT2 *Resu);
int Trace3(const TARGET_CONDI3 *Condition,RESULT3 *Resu);
int Trace4(const TARGET_CONDI4 *Condition,RESULT4 *Resu);
int Trace5(const TARGET_CONDI5 *Condition,RESULT5 *Resu);
#endif








