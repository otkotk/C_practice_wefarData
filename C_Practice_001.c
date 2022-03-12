#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 装置報告データ定義 */
#define MC_DATA1    "WAF_01,20220101010100,050,15000,123.4500"
#define MC_DATA2    "WAF_02,20220202020200,100,20000,23.12300"
#define MC_DATA3    "   ,20220101010000,100,25000,34.56780"
#define MC_DATA4    "WAF_04,20220202020300,110,30000,200.1234"
#define MC_DATA5    "WAF_05,20220101020400,120,35000,500.0120"
#define ARR_SIZE    5

int main(void)
{
    // char dataArr[] = {MC_DATA1, MC_DATA2, MC_DATA3, MC_DATA4, MC_DATA5};
    char wefar[6];          //ウェハーID取得用配列
    char time[14];          //日時取得用配列
    char corrNumChar[3];    //補正回数取得用配列
    char rotateNumChar[5];  //回転数取得用配列
    char corrValueChar[8];  //補正値
    int corrNum;            //補正回転数
    int rotateNum;          //回転数
    double corrValue;       //補正値
    int i;                  //定数判定用
    int j;                  //文字列操作用(データ)
    int k;                  //文字列操作用(格納先)
    int commaCnt;           //カンマ区切りごとにカウントアップする
    char *dataPoint;



    for(i = 0; i < ARR_SIZE; i++)
    {
        // printf("dataPoint[%d] = %c\n", i, dataPoint[i]);
        switch (i)
        {
        case 0:
            dataPoint = MC_DATA1;
            break;
        case 1:
            dataPoint = MC_DATA2;
            break;
        case 2:
            dataPoint = MC_DATA3;
            break;
        case 3:
            dataPoint = MC_DATA4;
            break;
        case 4:
            dataPoint = MC_DATA5;
            break;
        }

        j = 0;
        k = 0;
        commaCnt = 0;
        while (commaCnt < 5)
        {
            if (dataPoint[j] == '\0' || dataPoint[j] == ',')
            {
                commaCnt++;
                j++;
                k = 0;
                // printf("\n");
            }
            else
            {
                switch (commaCnt)
                {
                case 0:
                    // printf("%c", dataPoint[j]);
                    strcat(wefar, dataPoint[j]);
                    // wefar[k] = dataPoint[j];
                    j++;
                    k++;
                    break;
                case 1:
                    strcat(time, dataPoint[j]);
                    // time[k] = dataPoint[j];
                    j++;
                    k++;
                    break;
                case 2:
                    strcat(corrNumChar, dataPoint[j]);
                    // corrNumChar[k] = dataPoint[j];
                    j++;
                    k++;
                    break;
                case 3:
                    strcat(rotateNumChar, dataPoint[j]);
                    // rotateNumChar[k] = dataPoint[j];
                    j++;
                    k++;
                    break;
                case 4:
                    strcat(corrValueChar, dataPoint[j]);
                    // corrValueChar[k] = dataPoint[j];
                    j++;
                    k++;
                    break;
                }
            }
        }
        corrNum = (int)corrNumChar;
        rotateNum = (int)rotateNumChar;
        corrValue = atof(corrValueChar);
        // corrValue = corrValueChar;
        printf("ウェハーID: %s, 日時: %s, 補正回数: %d, 回転数: %d, 補正値: %f\n", wefar, time, corrNum, rotateNum, corrValue);
        char wefar[6] = {0};
        char time[14] = {0};
        int corrNumChar[3] = {0};
        int rotateNumChar[5] = {0};
        double corrValueChar[8] = {0};
    }
    
    return 0;
}

