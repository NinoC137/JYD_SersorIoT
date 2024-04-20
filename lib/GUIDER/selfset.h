#ifndef selfset_h
#define selfset_h
#include <lvgl.h>
extern int    wificonnect;//wifi连接被按下的标志
extern char   wifinane[20];//WIFI名字
extern char   wifipassward[20];//WIFI密码
extern char  SETdata[10];
/**设置界面设置的电机参数**/
extern char M1popair[10], M2popair[10];
extern char M1AP[10],M1AI[10],M1AD[10],M0AP[10],M0AI[10],M0AD[10],M0VP[10],M0VI[10],M0VD[10],M0VP[10],M0VI[10],M0VD[10];
extern char M1VLimit[10],M0VLimit[10],M0CLimit[10],M0CLimit[10];
extern char    M1CtMod,M2CtMod;//电机12的控制模式

/***设置界面输入数据参数***/
extern int *setdata;//设置模式下最终输入的数据，整型
extern int flo;//小数点位数=10-flo
extern int data;//过程中的参数
extern double realtime;//设置模式下，实时输入的数据已转为浮点型
extern char *setchardata;//设置模式下最终输入的数据，字符串型
extern int SAVE;//设置模式下，按下保存键的标志位


extern char options[2];
extern char mottor[2];
extern char paraments;

/*要在标签显示的电机和驱动数据***数据类型使用的时候再改*/
extern int M0labe;
extern int M1labe;
extern int DRlabe;

/***显示状态的电机参数***/
extern float M1TARGET;
extern float M1I;
extern float M1V;
extern float M1POSITION;

extern float M0TARGET;
extern float M0I;
extern float M0V;
extern float M0POSITION;

extern float DRTARGET;
extern float DRI;
extern float DRV;
extern float DRPOSITION;

#endif
