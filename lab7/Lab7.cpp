#include "labDisk.h"
using namespace std;
struct partition_table
{
	tPartition table[4];
	struct partition_table* next;
} *first, * temp, * last;
tPartition tm;
tIDECHS geomet;
tLARGE geom, adr;
tLBA disk, adres = 1;

int main()
{
	setlocale(LC_ALL, "rus");
	int i, t, k = 0, b = 1, free_size, type_oc, bool_oc;
	char c;
	geom.C = 1023;
	geom.H = 255;
	geom.S = 63;
	first = new partition_table[sizeof(struct partition_table)];
	last = first;
	cout << "Введите IDECHS геометрию диска" << endl;
	do
	{
		cout << "C: ";
		cin >> t;
	} while (t > geom.C);
	geomet.C = t;

	do
	{
		cout << "H: ";
		cin >> t;
	} while (t > geom.H);
	geomet.H = t;

	do
	{
		cout << "S: ";
		cin >> t;
	} while (t > geom.S);
	geomet.S = t;

	g_idechs2lba(geomet, &disk);
	cout << "Размер диска " << (float)disk / (1024 * 2048) << " Гб" << endl;
	free_size = disk / 2;
	do
	{
		do
		{
			cout << "Свободного места: " << free_size << " Кб" << endl;
			cout << "Размер раздела (Кб): ";
			cin >> t;
		} while (t > free_size);
		if (t == 0)
			break;

		free_size -= t;
		tm.startLBA = adres;
		tm.size = t;
		adres += tm.size;
		if (a_lba2large(geom, tm.startLBA, &adr))
			tm.startCHS = adr;
		else
			tm.startCHS = geom;
		if (a_lba2large(geom, adres, &adr))
			tm.endCHS = adr;
		else
			tm.endCHS = geom;
		bool_oc = 1;
		while (bool_oc)
		{
			bool_oc = 0;
			cout << "Тип ОС:" << endl;
			cout << "1 - FAT16" << endl;
			cout << "2 - FAT32" << endl;
			cout << "3 - Linux swap" << endl;
			cout << "4 - Linux" << endl;
			cout << "5 - HPFS/NTFS" << endl;
			cin >> type_oc;
			switch (type_oc)
			{
			case 1:	tm.type = 0x04;	break;
			case 2:	tm.type = 0x0c;	break;
			case 3:	tm.type = 0x82;	break;
			case 4:	tm.type = 0x83;	break;
			case 5:	tm.type = 0x07;	break;
			default: bool_oc = 1;
			}
		}
		tm.active = 0;
		if (b)
		{
			cout << "Установить раздел активным (y/n)" << endl;
			do
			{
				cin >> c;
			} while ((c != 'n') && (c != 'y'));
			if ((c == 'y'))
			{
				tm.active = 0x80;
				b = 0;
			}
		}
		if (((tm.startCHS.C == geom.C) && (tm.startCHS.H == geom.H) && (tm.startCHS.S == geom.S)) || (k == 3))
		{
			last->table[k] = tm;
			last->table[k].type = 0x05;
			if (k != 3)
				last->table[k + 1].startLBA = 0;
			temp = new partition_table[sizeof(struct partition_table)];
			last->next = temp;
			last = temp;
			last->table[0] = tm;
			last->table[1].startLBA = 0;
			k = 1;
		}
		else
		{
			last->table[k] = tm;
			last->table[++k].startLBA = 0;
		}
	} while (free_size != 0);
	cout << "Актв | CHS нач | ОС |  CHS кон  |   LBA нач   |   Размер   |" << endl;
	temp = first;
	last->next = NULL;
	while (temp != NULL)
	{
		for (i = 0; i < 4; i++)
		{
			if (temp->table[i].startLBA == 0)
				break;
			printf("%2x%5d%4d%3d%4x%5d%4d%3d%13ld%13d\n", temp->table[i].active, temp->table[i].startCHS.C, temp->table[i].startCHS.H, temp->table[i].startCHS.S, temp->table[i].type, temp->table[i].endCHS.C, temp->table[i].endCHS.H, temp->table[i].endCHS.S, temp->table[i].startLBA, temp->table[i].size); // выводим все данные о разделе
		}
		temp = temp->next;
	}
	return 0;
}