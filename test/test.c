#include <stdio.h>
#include "SDL.h"
#include "SDL_ttf.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define _DATETIME_SIZE  32

int GetDateTime(char * psDateTime)
{
    time_t nSeconds;
    struct tm * pTM;
    
    time(&nSeconds);
    pTM = localtime(&nSeconds);
 
    /* 系统日期和时间,格式: yyyymmddHHMMSS */
    sprintf(psDateTime, "%04d-%02d-%02d %02d:%02d:%02d ",
            pTM->tm_year + 1900, pTM->tm_mon + 1, pTM->tm_mday,
            pTM->tm_hour, pTM->tm_min, pTM->tm_sec);
            
    return 0;
}

int main(int argc, const char *argv[])
{
    SDL_PixelFormat *fmt;
    TTF_Font *font;  
    SDL_Surface *text, *temp;  

    int ret;
    char DateTime[_DATETIME_SIZE];
    
    memset(DateTime, 0, sizeof(DateTime));
    /* 获取系统当前日期时间 */
    ret = GetDateTime(DateTime);
    if(ret == 0) 
        printf("The Local date and time is %s\n", DateTime);
    else 
        perror("GetDateTime error!");

    if (TTF_Init() < 0 ) 
    {  
        fprintf(stderr, "Couldn't initialize TTF: %s\n",SDL_GetError());  
        SDL_Quit();
    }  

    font = TTF_OpenFont("/user/font/wqy-microhei.ttc", 26); 
    if ( font == NULL ) 
    {  
        fprintf(stderr, "Couldn't load %d pt font from %s: %s\n", 20, "ptsize", SDL_GetError());  
    }  

    SDL_Color forecol = {  0xff, 0xff, 0xff, 0xff };  
    text = TTF_RenderUTF8_Solid(font, DateTime, forecol);

    fmt = (SDL_PixelFormat*)malloc(sizeof(SDL_PixelFormat));
    memset(fmt,0,sizeof(SDL_PixelFormat));
    fmt->BitsPerPixel = 16;
    fmt->BytesPerPixel = 2;
    fmt->colorkey = 0xffffffff;
    fmt->alpha = 0x8000;

    temp = SDL_ConvertSurface(text, fmt, 0);
    SDL_SaveBMP(temp, "save.bmp"); 

    SDL_FreeSurface(text);  
    SDL_FreeSurface(temp);
    TTF_CloseFont(font);  
    TTF_Quit();  

    return 0;
}




