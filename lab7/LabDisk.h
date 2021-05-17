#pragma once
#include <clocale>
#include <iostream>
#include <stdio.h>
typedef struct
{
	unsigned long int C : 10, H : 4, S : 6;
} tCHS;

typedef struct
{
	unsigned long int C : 10, H : 8, S : 6;
} tLARGE;

typedef struct
{
	unsigned long int C : 16, H : 4, S : 8;
} tIDECHS;

typedef unsigned long int tLBA;

typedef struct
{
	unsigned char active;
	tLARGE startCHS;
	unsigned char type;
	tLARGE endCHS;
	tLBA startLBA;
	unsigned int size;
} tPartition;

int g_lba2chs(tLBA g1, tCHS* g2);
int g_lba2large(tLBA g1, tLARGE* g2);
int g_lba2idechs(tLBA g1, tIDECHS* g2);
int g_chs2large(tCHS g1, tLARGE* g2);
int g_chs2lba(tCHS g1, tLBA* g2);
int g_chs2idechs(tCHS g1, tIDECHS* g2);
int g_large2chs(tLARGE g1, tCHS* g2);
int g_large2idechs(tLARGE g1, tIDECHS* g2);
int g_large2lba(tLARGE g1, tLBA* g2);
int g_idechs2chs(tIDECHS g1, tCHS* g2);
int g_idechs2lagre(tIDECHS g1, tLARGE* g2);
int g_idechs2lba(tIDECHS g1, tLBA* g2);
int a_lba2chs(tCHS g1, tLBA a1, tCHS* a2);
int a_lba2large(tLARGE g1, tLBA a1, tLARGE* a2);
int a_lba2idechs(tIDECHS g1, tLBA a1, tIDECHS* a2);
int a_chs2lba(tCHS g1, tCHS a1, tLBA* a2);
int a_large2lba(tLARGE g1, tLARGE a1, tLBA* a2);
int a_idechs2lba(tIDECHS g1, tIDECHS a1, tLBA* a2);
int a_large2chs(tLARGE g1, tCHS g2, tLARGE a1, tCHS* a2);
int a_large2idechs(tLARGE g1, tIDECHS g2, tLARGE a1, tIDECHS* a2);
int a_chs2large(tCHS g1, tLARGE g2, tCHS a1, tLARGE* a2);
int a_idechs2large(tIDECHS g1, tLARGE g2, tIDECHS a1, tLARGE* a2);
int a_chs2idechs(tCHS g1, tIDECHS g2, tCHS a1, tIDECHS* a2);
int a_idechs2chs(tIDECHS g1, tCHS g2, tIDECHS a1, tCHS* a2);