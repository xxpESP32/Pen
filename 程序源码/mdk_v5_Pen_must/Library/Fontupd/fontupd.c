#include "fontupd.h"
#include "at32f403a_407_board.h"
#include "at32f403a_407_clock.h"
#include "ws2812b.h"
#include "lcd.h"
//#include "led.h"

//所占用的flash扇区个数
//字库区域占用的总扇区大小(三个字库大小+unigbk表+字库信息=3238697(3238700)字节),总共占约791个扇区(3238700/4096)
#define SECTOR_NUM 664
#define FONT_NUM   2
//字库存放起始地址
#define FONTINFOADDR 171*1024   //Explorer STM32F4是从12M地址以后开始存放字库
																//前面12M区域给文件系统占用
																//12M以后紧跟着3个字库+unigbk表,总大小3.09M,被字库占用了,不能动
																//15.10M以后,用户可以自由使用.建议用最后的100K字节比较好.
u8 CP_Buff[1030];		
u32 Fontupd_Size;
//定义各个字库的大小
#define UNIGBK          2653*1024         //171KB
#define FONT_S          5*1024
/*#define GBK12_FONSIZE  562*1024        //562KB
#define GBK16_FONSIZE  749*1024		   //749KB
#define GBK24_FONSIZE  1684*1024       //1684KB
#define GBK32_FONSIZE  2993*1024       //2993KB
*/
_font_info ftinfo; //用来存放字库地址,大小,基本信息等													
int fintupd_Number;


word_font font_word;
//初始化字库
//返回值:0,字库完好
//      其它,字库丢失
int font_init(void)
{
	u8 t=0;
	
	printf("Start checking the font...\r\n");
	while(t<10)//连续读取10次,都是错误,说明真的有问题,需要更新字库
	{
		t++;
		W25QXX_Read((u8*)&ftinfo,FONTINFOADDR,sizeof(ftinfo)); //读取ftinfo结构体信息
		printf("ftinfo.fontok =0x%x\r\n",ftinfo.fontok);
		if(ftinfo.fontok == 0xAA) break;
		Delay_ms(20);
	}
	if(ftinfo.fontok!=0xAA)
	{
		printf("Character is missing...\r\n");
		return 1;
	}
	printf("A word stock...\r\n");
	return 0;
}

//显示当前字体更新进度
//x,y:坐标
//size:字体大小
//fsize:整个文件大小
//pos:当前文件指针位置
u32 font_prog(u16 x,u16 y,u8 size,u32 fsize,u32 pos)
{
	float prog;
	u8 flags;
	u8 t=0xFF;
	prog=(float)pos/fsize;
	prog*=100;
	if(t!=prog)
	{
		//LCD_ShowString(x+3*size/2,y,240,320,size,(u8*)"%");
		LCD_ShowString(x+3*size/2,y,(u8*)"%",RED,WHITE,12,0);
		t=prog;
		if(t>=100){
			t=100;
		//LCD_ShowNum(x,y,t,3,size); //显示数值
			LCD_ShowIntNum(x,y,t,3,RED,WHITE,size);
		//LCD_ShowIntNum(x,y,t,3,RED,WHITE,size);
		return flags=1;
		}
		//LCD_ShowIntNum(x,y,t,3,RED,WHITE,size); //显示数值
		LCD_ShowIntNum(x,y,t,3,RED,WHITE,size);
	}
	return 0;
}

//更新某一个
//x,y:坐标
//size:字体大小
//fx:更新的内容 0,ungbk;1,gbk12;2,gbk16;3,gbk24;
//返回值:0,成功;其他,失败.
u8 updata_fontx(u16 x,u16 y,u8 size,u8 fx)
{
	u32 flashaddr=0;
	u32 offx=0; //接收到的文件大小
	u32 fsize=0; //总文件大小

	u8 flags=0;
	u8 BACK=0;
	switch(fx)
	{
		case 0:       //更新UNIGBK.BIN文件
			ftinfo.ugbkaddr=FONTINFOADDR+sizeof(ftinfo); //信息头后紧跟UNIGBK码表
			fsize=ftinfo.ugbksize=UNIGBK;   //UNIGBK.BIN文件大小
		  flashaddr=ftinfo.ugbkaddr; //UNIGBK起始地址
			printf("Please Send UNIGBK.BIN SIZE=%d\r\n",fsize);
			break;
		/*case 1:
			ftinfo.f12addr=ftinfo.ugbkaddr+ftinfo.ugbksize; //UNIGBK后紧跟GBK12字库
		  fsize=ftinfo.gbk12size=GBK12_FONSIZE; //GBK12字库大小
		  flashaddr=ftinfo.f12addr;   //GBK12起始地址
		  printf("Please Send GBK12.FON\r\n");
		  break;
		case 2:
			ftinfo.f16addr=ftinfo.f12addr+ftinfo.gbk12size; //GBK12后紧跟GBK16字库
		  fsize=ftinfo.gbk16size=GBK16_FONSIZE;  //GBK16字库大小
		  flashaddr=ftinfo.f16addr;  //GBK16起始地址
		  printf("Please Send GBK16.FON\r\n"); 
			break;
		case 3:
			ftinfo.f24addr=ftinfo.f16addr+ftinfo.gbk16size; //GBK16后紧跟GBK24字库
		  fsize=ftinfo.gbk24size=GBK24_FONSIZE;  //GBK24字库大小
		  flashaddr=ftinfo.f24addr;  //GBK24起始地址
		  printf("Please Send GBK24.BIN\r\n");
		  break;
//		case 4:
//			ftinfo.f32addr=ftinfo.f24addr+ftinfo.gbk24size; //GBK24后紧跟GBK32字库
//		  fsize=ftinfo.gbk32size=GBK32_FONSIZE; //GBK32字库大小
//		  flashaddr=ftinfo.f32addr;  //GBK32起始地址
//		  break;*/
	}
	
	font_prog(x,y,size,fsize,offx); //显示更新进度
	//GBK_BUF_Flag=2; //清除标志等待下一次DMA中断
	//GBK_OVER_Flag=0; //停止计时

	LCD_ShowIntNum(0,35,offx,7,RED,WHITE,size);
	while(BACK==0)
	{
	
		if(GBK_BUF_Flag == 0){
			GBK_BUF_Flag=2; 
			W25QXX_Write(DMA_Buff,offx+flashaddr,1024);
			
			//W25QXX_Read(CP_Buff,);
			offx+=1024;
			//fintupd_Number+=1;
			printf("REX_Number_%d=%s\r\n",offx,DMA_Buff);
			//printf("下载的字节数量%d\r\n",offx);
			flags=font_prog(x,y,size,fsize,offx);  //进度显示
			//printf("Fontupd=%d\r\n",fintupd_Number);
			
		}
	
		
		LCD_ShowIntNum(0,35,offx,7,RED,WHITE,size);
		
		if(flags==1){
			flags=0;
			BACK =2;
		}
	}
	
	printf("This Font Updated Successfull!!!\r\n\r\n");
	//uart_init(BUND_RATE);
	
	return 0;
}

//更新字体文件,UNIGBK,GBK12,GBK16,GBK24一起更新
//x,y:提示信息的显示地址
//size:字体大小
//提示信息字体大小										  
//返回值:0,更新成功;
//		 其他,错误代码.	
u8 update_font(u8 x,u8 y,u8 size)
{
	int i,j;
  u32 flag;
	
	printf("正在擦拭扇区...\r\n\r\n");
	//LCD_ShowString(x,y,240,320,size,(u8*)"Erasing sectors... ");//提示正在擦除扇区
	LCD_ShowString(0,y,(u8*)"Erasing sectors... ",RED,WHITE,12,0);
	for(i=0 ; i<SECTOR_NUM ; i++)
	{
		font_prog(x+20*size/2,y,size,SECTOR_NUM,i); //显示进度
		W25QXX_Read((u8*)DMA_Buff_1,((FONTINFOADDR/4096)+i)*4096,4096); //读取整个扇区的内容(借用Usart_Rec_Buf1数组)
		for(j=0 ; j<4096 ; j++) //校验数据
		{
			if(DMA_Buff_1[j]!=0xFF) break; //需要擦除
		} 
		if(j!=4096) W25QXX_Erase_Sector((FONTINFOADDR/4096)+i); //需要擦除的扇区
	}
	Delay_ms(100); //延时100ms
	
	printf("1.下一个,请发送UNIGBK.BIN文件...\r\n");
	//LCD_ShowString(x,y,240,320,size,(u8*)"Updating UNIGBK.BIN   "); //更新UNIGBK.BIN
	LCD_ShowString(0,y,(u8*)"Updating UNIGBK.BIN",RED,WHITE,12,0);
  updata_fontx(x+20*size/2,y,size,0);
	
	
//	printf("5.下一个,请发送GBK32.FON文件...\r\n");
//	LCD_ShowString(x,y,240,320,size,(u8*)"Updating GBK32.FON   "); //更新UNIGBK.BIN
//  updata_fontx(x+20*size/2,y,size,4);
	
	//全部更新完成
	ftinfo.fontok=0xAA;  //写更新完成标志
	W25QXX_Write((u8*)&ftinfo,FONTINFOADDR,sizeof(ftinfo));  //保存字库信息
	printf("字库已经更新完成!!!\r\n");
	LCD_Fill(0,0,160,80,WHITE);
	
	return 0;
}

//******************************************************
//
//                  更新时间2022.11.29
//                  更新串口单词
//******************************************************

int font_word_init(void)
{
	u8 t=0;
	
	printf("Start checking the font...\r\n");
	while(t<10)//连续读取10次,都是错误,说明真的有问题,需要更新字库
	{
		t++;
		W25QXX_Read((u8*)&font_word,1024*1024*144,sizeof(font_word)); //读取ftinfo结构体信息
		printf("font_word.font_flag =0x%x\r\n",font_word.font_flag);
		if(font_word.font_flag == 0xBB) break;
		Delay_ms(20);
	}
	if(font_word.font_flag!=0xBB)
	{
		printf("Character is missing...\r\n");
		return 1;
	}
	printf("A word stock...\r\n");
	return 0;
}


u8 update_font_word(u8 x,u8 y,u8 size)
{
	int i,j;
  u32 flag;
	
	printf("output sectors...\r\n\r\n");
	//LCD_ShowString(x,y,240,320,size,(u8*)"Erasing sectors... ");//提示正在擦除扇区
	LCD_ShowString(0,y,(u8*)"Erasing sectors... ",RED,WHITE,12,0);
	for(i=0 ; i<1 ; i++)
	{
		font_prog(x+20*size/2,y,size,1,i); //显示进度
		W25QXX_Read((u8*)DMA_Buff_1,((1024*1024*144/4096)+i)*4096,4096); //读取整个扇区的内容(借用Usart_Rec_Buf1数组)
		for(j=0 ; j<4096 ; j++) //校验数据
		{
			if(DMA_Buff_1[j]!=0xFF) break; //需要擦除
		} 
		if(j!=4096) W25QXX_Erase_Sector((1024*1024*144/4096)+i); //需要擦除的扇区
	}
	Delay_ms(100); //延时100ms
	
	printf("1.下一个,请发送UNIGBK.BIN文件...\r\n");
	//LCD_ShowString(x,y,240,320,size,(u8*)"Updating UNIGBK.BIN   "); //更新UNIGBK.BIN
	LCD_ShowString(0,y,(u8*)"Updating Word.txt",RED,WHITE,12,0);
	
	//下载函数
  updata_fontx_word(x+20*size/2,y,size,0); //更改
	
	
//	printf("5.下一个,请发送GBK32.FON文件...\r\n");
//	LCD_ShowString(x,y,240,320,size,(u8*)"Updating GBK32.FON   "); //更新UNIGBK.BIN
//  updata_fontx(x+20*size/2,y,size,4);
	
	//全部更新完成
	font_word.font_flag=0xBB;  //写更新完成标志
	printf("ftinfo.fontok =0x%x\r\n",font_word.font_flag);
	W25QXX_Write((u8*)&font_word,1024*1024*144,sizeof(font_word));  //保存字库信息
	printf("字库已经更新完成!!!\r\n");
	LCD_Fill(0,0,160,80,WHITE);
	
	return 0;
}
//更新某一个
//x,y:坐标
//size:字体大小
//fx:更新的内容 0,ungbk;1,gbk12;2,gbk16;3,gbk24;
//返回值:0,成功;其他,失败.
u8 updata_fontx_word(u16 x,u16 y,u8 size,u8 fx)
{
	u32 flashaddr=0;
	u32 offx=0; //接收到的文件大小
	u32 fsize=0; //总文件大小

	u8 flags=0;
	u8 BACK=0;
	switch(fx)
	{
		case 0:       //更新UNIGBK.BIN文件
			font_word.txtaddr=1024*1024*144+sizeof(font_word); //信息头后紧跟UNIGBK码表
			fsize=font_word.txtsize=1024*1;   //UNIGBK.BIN文件大小
		  flashaddr=font_word.txtaddr; //UNIGBK起始地址
			printf("Please Send UNIGBK.BIN SIZE=%d\r\n",fsize);
			break;
		/*case 1:
			ftinfo.f12addr=ftinfo.ugbkaddr+ftinfo.ugbksize; //UNIGBK后紧跟GBK12字库
		  fsize=ftinfo.gbk12size=GBK12_FONSIZE; //GBK12字库大小
		  flashaddr=ftinfo.f12addr;   //GBK12起始地址
		  printf("Please Send GBK12.FON\r\n");
		  break;
		case 2:
			ftinfo.f16addr=ftinfo.f12addr+ftinfo.gbk12size; //GBK12后紧跟GBK16字库
		  fsize=ftinfo.gbk16size=GBK16_FONSIZE;  //GBK16字库大小
		  flashaddr=ftinfo.f16addr;  //GBK16起始地址
		  printf("Please Send GBK16.FON\r\n"); 
			break;
		case 3:
			ftinfo.f24addr=ftinfo.f16addr+ftinfo.gbk16size; //GBK16后紧跟GBK24字库
		  fsize=ftinfo.gbk24size=GBK24_FONSIZE;  //GBK24字库大小
		  flashaddr=ftinfo.f24addr;  //GBK24起始地址
		  printf("Please Send GBK24.BIN\r\n");
		  break;
//		case 4:
//			ftinfo.f32addr=ftinfo.f24addr+ftinfo.gbk24size; //GBK24后紧跟GBK32字库
//		  fsize=ftinfo.gbk32size=GBK32_FONSIZE; //GBK32字库大小
//		  flashaddr=ftinfo.f32addr;  //GBK32起始地址
//		  break;*/
	}
	
	font_prog(x,y,size,fsize,offx); //显示更新进度
	//GBK_BUF_Flag=2; //清除标志等待下一次DMA中断
	//GBK_OVER_Flag=0; //停止计时

	LCD_ShowIntNum(0,35,offx,7,RED,WHITE,size);
	while(BACK==0)
	{
	
		if(GBK_BUF_Flag == 0){
			GBK_BUF_Flag=2; 
			W25QXX_Write(DMA_Buff,offx+flashaddr,1024);
			
			//W25QXX_Read(CP_Buff,);
			offx+=1024;
			//fintupd_Number+=1;
			printf("REX_Number_%d=%s\r\n",offx,DMA_Buff);
			//printf("下载的字节数量%d\r\n",offx);
			flags=font_prog(x,y,size,fsize,offx);  //进度显示
			//printf("Fontupd=%d\r\n",fintupd_Number);
			
		}
	
		
		LCD_ShowIntNum(0,35,offx,7,RED,WHITE,size);
		
		if(flags==1){
			flags=0;
			BACK =2;
		}
	}
	
	printf("This Font Updated Successfull!!!\r\n\r\n");
	//uart_init(BUND_RATE);
	
	return 0;
}