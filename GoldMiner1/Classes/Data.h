//
//  Data.h
//  DVGoldMiner
//
//  Created by user on 13-5-30.
//
//

#ifndef DVGoldMiner_Data_h
#define DVGoldMiner_Data_h

bool backMusic = true;
int Level = 0; //级数
int ToTalLevel = 3;//总关数3
int TotalSocre = 0;//总分数
int TotalSocre2 = 0;//总分数备份

int ExplosiveNumber = 0;//炸药数量
bool PowerRinse = false;//强力水数量

int TotalTime[] = {10, 40, 50};//每关的时间
int NeedTotalScore[] = {300, 1000, 2000};//每关的分数

int ItemStoneNumber[] = {5, 8, 10};//每关添加的物品的数量-石头
int ItemGoldNumber[] = {5, 8, 10};//-黄金
int ItemDiamondNumber[] = {0, 1, 2};//-钻石
int ItemSecretNumber[] = {0, 0, 2};//-神秘物品

#endif
