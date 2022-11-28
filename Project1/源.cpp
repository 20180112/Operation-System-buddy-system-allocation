#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define NumOfProc 8
int NumOfFreeBlock;
int NumOfUsedBlock;
int NumofBlockId;

struct Block
{
	int id;
	int sizeK;
	int startAddr;
	int status;
	int pid;
	struct Block *prev;
	struct Block* next;
};
struct PCB {
	int pid;
	int neededMem;
	int status;
	int blockID;
	struct PCB* next;
};

int Buddy1() {
	static int flag[10];//��¼��СΪ2^k��δ�����ڴ�����Ƿ����һ��Ԫ��
	static int flag2[10];//��¼��СΪ2^k�ı�ʹ�õ��ڴ�����Ƿ����һ��Ԫ��
	static int NumOfBlock[10];//��¼δ�����ڴ������ÿ����С���ڴ��ĸ���
	static int NumOfBlock2[10];//��¼��ʹ�õ��ڴ������ÿ����С���ڴ��ĸ���
	struct Block* Freeblock[10];//δ�����ڴ����ͷ���
	struct Block* Usedblock[10];//ʹ���е��ڴ����ͷ���
	srand((unsigned)time(NULL));
	//������Ŀ����PCB����
	struct PCB* PCBchain = (struct PCB*)malloc(sizeof(struct PCB));//�����б�ͷ���
	struct PCB* P1 = (struct PCB*)malloc(sizeof(struct PCB));
	struct PCB* P2 = (struct PCB*)malloc(sizeof(struct PCB));
	struct PCB* P3 = (struct PCB*)malloc(sizeof(struct PCB));
	PCBchain->next = P1; P1->next = P2; P2->next = P3; P3->next = NULL;//����PCB����
	P1->neededMem = pow(2, 7); P2->neededMem = pow(2, 4); P3->neededMem = pow(2, 8);//�����ڴ����
	P1->blockID = -1; P2->blockID = -1; P3->blockID = -1;
	P1->status = 0; P2->status = 0; P3->status = 0;
	P1->pid = 1; P2->pid = 2; P3->pid = 3;
	//������ʼ��
	NumOfFreeBlock = 0;
	NumofBlockId = 0;
	NumOfUsedBlock = 0;

	struct Block* FreeBlockchain0 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain1 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain2 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain3 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain4 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain5 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain6 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain7 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain8 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain9 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���

	FreeBlockchain0->next = NULL;
	FreeBlockchain1->next = NULL;
	FreeBlockchain2->next = NULL;
	FreeBlockchain3->next = NULL;
	FreeBlockchain4->next = NULL;
	FreeBlockchain5->next = NULL;
	FreeBlockchain6->next = NULL;
	FreeBlockchain7->next = NULL;
	FreeBlockchain8->next = NULL;
	FreeBlockchain9->next = NULL;

	Freeblock[0] = FreeBlockchain0;
	Freeblock[1] = FreeBlockchain1;
	Freeblock[2] = FreeBlockchain2;
	Freeblock[3] = FreeBlockchain3;
	Freeblock[4] = FreeBlockchain4;
	Freeblock[5] = FreeBlockchain5;
	Freeblock[6] = FreeBlockchain6;
	Freeblock[7] = FreeBlockchain7;
	Freeblock[8] = FreeBlockchain8;
	Freeblock[9] = FreeBlockchain9;

	struct Block* UsedBlockchain0 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* UsedBlockchain1 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* UsedBlockchain2 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* UsedBlockchain3 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* UsedBlockchain4 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* UsedBlockchain5 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* UsedBlockchain6 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* UsedBlockchain7 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* UsedBlockchain8 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* UsedBlockchain9 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���

	UsedBlockchain0->next = NULL;
	UsedBlockchain1->next = NULL;
	UsedBlockchain2->next = NULL;
	UsedBlockchain3->next = NULL;
	UsedBlockchain4->next = NULL;
	UsedBlockchain5->next = NULL;
	UsedBlockchain6->next = NULL;
	UsedBlockchain7->next = NULL;
	UsedBlockchain8->next = NULL;
	UsedBlockchain9->next = NULL;

	Usedblock[0] = UsedBlockchain0;
	Usedblock[1] = UsedBlockchain1;
	Usedblock[2] = UsedBlockchain2;
	Usedblock[3] = UsedBlockchain3;
	Usedblock[4] = UsedBlockchain4;
	Usedblock[5] = UsedBlockchain5;
	Usedblock[6] = UsedBlockchain6;
	Usedblock[7] = UsedBlockchain7;
	Usedblock[8] = UsedBlockchain8;
	Usedblock[9] = UsedBlockchain9;

	//��ʼ�ڴ��B1����ʼ�ڴ�1024����ʼλ��0
	NumOfFreeBlock++;
	NumofBlockId++;
	struct Block* B1 = (struct Block*)malloc(sizeof(struct Block));
	FreeBlockchain9->next = B1;
	B1->prev = FreeBlockchain9;
	B1->sizeK = pow(2, 10);
	B1->startAddr = 0;
	B1->id = NumofBlockId;
	B1->next = NULL;
	flag[int(log2(B1->sizeK) - 1)] = 1;
	NumOfBlock[int(log2(B1->sizeK) - 1)] ++;

	struct PCB* tmp_PCB = PCBchain;
	for (int i = 0; i < NumOfProc; i++)
	{//�������н���
		tmp_PCB = tmp_PCB->next;
		printf("Allocate free memory block for process %d of size %d\n", tmp_PCB->pid, tmp_PCB->neededMem);
		if (flag[int(log2(tmp_PCB->neededMem)) - 1] == 1)
		{//���б��д������PCB������ͬ���ڴ��,�����Ƚ�������Ŀ��ȱ�����ԭ��
			struct Block* tmp = Freeblock[int(log2(tmp_PCB->neededMem)) - 1]; tmp = tmp->next;
			if (tmp->next == NULL)
			{
				tmp->prev->next = NULL;
			}
			else
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
			//�����ڴ��������ǰ���̣����ҵ�����Ӧ�ڴ�������flag����
			tmp->pid = tmp_PCB->pid; tmp_PCB->blockID = tmp->id;
			tmp->status = 1; tmp_PCB->status = 1;
			NumOfBlock[int(log2(tmp_PCB->neededMem)) - 1]--;
			if (NumOfBlock[int(log2(tmp_PCB->neededMem)) - 1] == 0)
			{
				flag[int(log2(tmp_PCB->neededMem)) - 1] = 0;
			}
			//���ڴ���Ƶ�ʹ���е��ڴ���������ҵ�����Ӧ�ڴ�������flag����
			struct Block* tmp1 = Usedblock[int(log2(tmp_PCB->neededMem)) - 1];
			while (tmp1->next != NULL)
			{
				tmp1 = tmp1->next;
			}
			tmp1->next = tmp;
			tmp->prev = tmp1;
			tmp->next = NULL;
			NumOfFreeBlock--;
			NumOfUsedBlock++;
			NumOfBlock2[int(log2(tmp_PCB->neededMem)) - 1]++;
			flag2[int(log2(tmp_PCB->neededMem)) - 1] = 1;
			//���
			for (int i = 0; i < 10; i++)
			{
				struct Block* tmp = Freeblock[i]; tmp = tmp->next;
				while (tmp != NULL && tmp->next != NULL)
				{
					printf("free block id:%d,size:%d,startAddr:%d\n", tmp->id, tmp->sizeK, tmp->startAddr);
					tmp = tmp->next;
				}
				if (tmp != NULL)
				{
					printf("free block id:%d,size:%d,startAddr:%d\n", tmp->id, tmp->sizeK, tmp->startAddr);
				}
			}
			for (int i = 0; i < 10; i++)
			{
				struct Block* tmp = Usedblock[i]; tmp = tmp->next;
				while (tmp != NULL && tmp->next != NULL)
				{
					printf("uesd block id:%d,size:%d,startAddr:%d,pid:%d\n", tmp->id, tmp->sizeK, tmp->startAddr, tmp->pid);
					tmp = tmp->next;
				}
				if (tmp != NULL)
				{
					printf("uesd block id:%d,size:%d,startAddr:%d,pid:%d\n", tmp->id, tmp->sizeK, tmp->startAddr, tmp->pid);
				}
			}
		}
		else
		{//�ڴ���в����ڿɷ�����ڴ棬��Ҫ�и�
			int cut = 1;
			for (int i = int(log2(tmp_PCB->neededMem)); i < 10; i++)
			{//������һ������Ҫ���ڴ����ڴ��Ϳ����и�
				if (flag[i] == 1)
				{
					cut = 1;
				}
			}
			if (cut == 0) //��ʾ����Ҫ�����ڴ���δ����鲻���ڣ��������ʧ��
			{//�޷��и�����
				printf("process %d fail in allocation...\n", tmp_PCB->pid);
				continue;
			}
			else
			{//�����и�
				while (flag[int(log2(tmp_PCB->neededMem)) - 1] == 0)
				{//����Ҫ���ڴ����δ���и��������һֱ�ָ�
					for (int i = int(log2(tmp_PCB->neededMem)); i < 10; i++)
					{
						if (flag[i] == 1)
						{//�����б�ĩβ�Ŀ�ָ�
							struct Block* tmp = Freeblock[i];
							while (tmp->next != NULL)
							{
								tmp = tmp->next;
							}
							//�����С��С�����Ƴ���ǰ����
							tmp->sizeK = tmp->sizeK / 2;
							tmp->prev->next = tmp->next;
							if (tmp->next != NULL)
							{
								tmp->next->prev = tmp->prev;
							}
							
							struct Block* tmpnew = Freeblock[int(log2(tmp->sizeK)) - 1];
							while (tmpnew->next != NULL)
							{
								tmpnew = tmpnew->next;
							}
							tmpnew->next = tmp;
							tmp->next = NULL;
							tmp->prev = tmpnew;
							//����Ӧ����Ŀ����ı�
							NumOfBlock[int(log2(tmp->sizeK)) - 1] ++;
							flag[int(log2(tmp->sizeK)) - 1] = 1;
							NumOfBlock[int(log2(tmp->sizeK))] --;
							if (NumOfBlock[int(log2(tmp->sizeK))] == 0)
							{
								flag[int(log2(tmp->sizeK))] = 0;
							}
							//�ָ�������������п��1�����п�+1
							NumOfFreeBlock++;
							NumofBlockId++;
							//�Ƶ���Ӧ��С�Ŀ�����
							struct Block* newblock = (struct Block*)malloc(sizeof(struct Block));
							newblock->sizeK = tmp->sizeK;
							newblock->startAddr = tmp->startAddr + tmp->sizeK;
							newblock->id = NumofBlockId;
							struct Block* tmpnew1 = Freeblock[int(log2(newblock->sizeK)) - 1];
							while (tmpnew1->next != NULL)
							{
								tmpnew1 = tmpnew1->next;
							}
							tmpnew1->next = newblock;
							newblock->next = NULL;
							newblock->prev = tmpnew1;
							NumOfBlock[int(log2(newblock->sizeK)) - 1] ++;
							break;
						}
					}
				}
				if (flag[int(log2(tmp_PCB->neededMem)) - 1] == 1)
				{//���б��д������PCB������ͬ���ڴ��,�����Ƚ�������Ŀ��ȱ�����ԭ��������һ��
					struct Block* tmp = Freeblock[int(log2(tmp_PCB->neededMem)) - 1]; tmp = tmp->next;
					if (tmp->next == NULL)
					{
						tmp->prev->next = NULL;
					}
					else
					{
						tmp->prev->next = tmp->next;
						tmp->next->prev = tmp->prev;
					}
					tmp->pid = tmp_PCB->pid; tmp_PCB->blockID = tmp->id;
					tmp->status = 1; tmp_PCB->status = 1;
					NumOfBlock[int(log2(tmp_PCB->neededMem)) - 1]--;
					if (NumOfBlock[int(log2(tmp_PCB->neededMem)) - 1] == 0)
					{
						flag[int(log2(tmp_PCB->neededMem)) - 1] = 0;
					}
					NumOfBlock2[int(log2(tmp_PCB->neededMem)) - 1]++;
					flag2[int(log2(tmp_PCB->neededMem)) - 1] = 1;
					struct Block* tmp1 = Usedblock[int(log2(tmp_PCB->neededMem)) - 1];
					while (tmp1->next != NULL)
					{
						tmp1 = tmp1->next;
					}
					tmp1->next = tmp;
					tmp->prev = tmp1; tmp->next = NULL;
					NumOfFreeBlock--;
					NumOfUsedBlock++;
					for (int i = 0; i < 10; i++)
					{
						struct Block* tmp = Freeblock[i]; tmp = tmp->next;
						while (tmp != NULL && tmp->next != NULL)
						{
							printf("free block id:%d,size:%d,startAddr:%d\n", tmp->id, tmp->sizeK, tmp->startAddr);
							tmp = tmp->next;
						}
						if (tmp != NULL)
						{
							printf("free block id:%d,size:%d,startAddr:%d\n", tmp->id, tmp->sizeK, tmp->startAddr);
						}
					}
					for (int i = 0; i < 10; i++)
					{
						struct Block* tmp = Usedblock[i]; tmp = tmp->next;
						while (tmp != NULL && tmp->next != NULL)
						{
							printf("uesd block id:%d,size:%d,startAddr:%d,pid:%d\n", tmp->id, tmp->sizeK, tmp->startAddr, tmp->pid);
							tmp = tmp->next;
						}
						if (tmp != NULL)
						{
							printf("uesd block id:%d,size:%d,startAddr:%d,pid:%d\n", tmp->id, tmp->sizeK, tmp->startAddr, tmp->pid);
						}
					}
				}
			}
		}
	}
	//�ϲ��ڴ棺���ͷ�һ������ʹ�õ��ڴ�飬����δ�����ڴ�����Ƿ��п��Ժϲ����ڴ��
	for (int i = 0; i < 10; i++)
	{
		if (flag2[i] == 1)
		{//�����ͷ�����ʹ�õ��ڴ�飬ͨ����������ʹ�õ��ڴ����
			struct Block* tmp = Usedblock[i]->next;
			for (int j = 0; j < NumOfBlock2[i]; j++)
			{
				struct Block* tmp1 = tmp;
				//����i�Ż�freeblock��
				printf("Recycle used memory block for process %d of size %d\n", tmp->pid, tmp->sizeK);
				if (tmp->next == NULL)
				{
					tmp->prev->next = NULL;
					tmp = tmp1->next;
				}
				else
				{
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
					tmp = tmp1->next;
				}
				//���¿�����״̬�����ҽ���ؿ����ı�
				tmp1->status = 0;
				tmp1->pid = -1;
				tmp1->next = NULL;
				NumOfUsedBlock--;
				NumOfBlock2[i] --;
				if (NumOfBlock2[i] == 0)
				{
					flag2[i] = 0;
				}
				//������Ӧ��δ�������
				struct Block* tmp2 = Freeblock[int(log2(tmp1->sizeK) - 1)];
				while (tmp2->next != NULL)
				{
					tmp2 = tmp2->next;
				}
				tmp2->next = tmp1;
				tmp1->prev = tmp2;
				NumOfBlock[int(log2(tmp1->sizeK) - 1)]++;
				flag[int(log2(tmp1->sizeK) - 1)] = 1;
				NumOfFreeBlock++;
				j--;
				//�鿴�Ƿ��пɺϲ���
				for (int m = 0; m < 10; m++)
				{
					while (NumOfBlock[m] >= 2) {
						//���һ������������2���飬��ô���п��ܺϲ�
						struct Block* tmp1 = Freeblock[m]->next;
						int change = 0;
						for (int n = 0; n < NumOfBlock[m]; n++)
						{
							struct Block* tmp11 = tmp1;
							//������СΪ2^i+1�η��Ŀ������޿��Ժϲ����ӿ�
							//�Ƿ񾭹����б�����û�кϲ���û���������һ����
							int turn = 0;
							struct Block* tmp2 = tmp1->next;//��ʼtmp2ָ��tmp1����һ���飬���������ܷ�ϲ�
							struct Block* tmp22 = tmp2;
							if (tmp2 == NULL) break;
							//��������
							for (int k = 0; k < NumOfBlock[m]; k++)
							{//������ع�ʽ�ж��Ƿ��ܺϲ�
								if (tmp1->startAddr % (tmp1->sizeK * 2) == 0)
								{
									if (tmp2 != NULL && tmp2->startAddr == tmp1->startAddr + tmp1->sizeK) {
										//tmp2����tmp1�ϲ�������tmp1��tmp2������
										printf("Combine block %d and %d of size %d\n", tmp1->id, tmp2->id, tmp1->sizeK);
										turn = 1; change = 1;
										//�ҵ����
										//�ϲ�tmp11��tmp12
										tmp11->sizeK = tmp1->sizeK + tmp2->sizeK;
										//�Ƴ�tmp11��tmp22
										if (tmp1->next == NULL) { tmp1->prev->next = NULL; tmp1 = tmp11->next; }//tmp1ָ�������һ����
										else {
											tmp1->prev->next = tmp1->next; tmp1->next->prev = tmp1->prev; tmp1 = tmp11->prev->next;
										}
										if (tmp2->next == NULL) { tmp2->prev->next = NULL; tmp2 = tmp22->next; }//tmp2ָ�������һ����
										else {
											tmp2->prev->next = tmp2->next; tmp2->next->prev = tmp2->prev; tmp2 = tmp22->prev->next;
										}
										//��Ӧ�����еĿ�������
										NumOfBlock[m] = NumOfBlock[m] - 2;
										if (NumOfBlock[m] == 0) flag[m] = 0;
										NumOfFreeBlock--;
										//���ϲ���Ŀ�ת�Ƶ���Ӧ���ڴ��С������
										struct Block* tmp3 = Freeblock[m + 1];
										while (tmp3->next != NULL)
										{
											tmp3 = tmp3->next;
										}
										tmp3->next = tmp11;
										tmp11->next = NULL;
										tmp11->prev = tmp3;
										NumOfBlock[m + 1]++;
										flag[m + 1] = 1;
										//���
										for (int p = 0; p < 10; p++)
										{
											struct Block* tmp_print = Freeblock[p]->next;
											while (tmp_print != NULL && tmp_print->next != NULL)
											{
												printf("free block id:%d,size:%d,startAddr:%d\n", tmp_print->id, tmp_print->sizeK, tmp_print->startAddr);
												tmp_print = tmp_print->next;
											}
											if (tmp_print != NULL)
											{
												printf("free block id:%d,size:%d,startAddr:%d\n", tmp_print->id, tmp_print->sizeK, tmp_print->startAddr);
											}
										}
										for (int p = 0; p < 10; p++)
										{
											struct Block* tmp_print = Usedblock[p]->next;
											while (tmp_print != NULL && tmp_print->next != NULL)
											{
												printf("Used block id:%d,size:%d,startAddr:%d,pid:%d\n", tmp_print->id, tmp_print->sizeK, tmp_print->startAddr, tmp_print->pid);
												tmp_print = tmp_print->next;
											}
											if (tmp_print != NULL)
											{
												printf("Used block id:%d,size:%d,startAddr:%d,pid:%d\n", tmp_print->id, tmp_print->sizeK, tmp_print->startAddr, tmp_print->pid);
											}
										}
									}
								}
								else if (tmp1->startAddr % (tmp1->sizeK * 2) == tmp1->sizeK)
								{//����ϵ����һ�����
									if (tmp2 != NULL && tmp2->startAddr == tmp1->startAddr - tmp1->sizeK) {
										//tmp2����tmp1�ϲ�������tmp1��tmp2�����棬������ͬ��
										printf("Combine block %d and %d of size %d\n", tmp1->id, tmp2->id, tmp1->sizeK);
										turn = 1; change = 1;
										//�ҵ����
										//�ϲ�tmp1��tmp2
										tmp11->startAddr = tmp2->startAddr;
										tmp11->sizeK = tmp1->sizeK + tmp2->sizeK;
										//�Ƴ�tmp2��tmp1
										if (tmp1->next == NULL) { tmp1->prev->next = NULL; tmp1 = tmp11->next; }
										else {
											tmp1->prev->next = tmp1->next; tmp1->next->prev = tmp1->prev; tmp1 = tmp11->prev->next;
										}
										if (tmp2->next == NULL) { tmp2->prev->next = NULL; tmp2 = tmp22->next; }
										else {
											tmp2->prev->next = tmp2->next; tmp2->next->prev = tmp2->prev; tmp2 = tmp22->prev->next;
										}
										NumOfBlock[m] = NumOfBlock[m] - 2;
										if (NumOfBlock[m] == 0) flag[m] = 0;
										NumOfFreeBlock--;
										struct Block* tmp3 = Freeblock[m + 1];
										while (tmp3->next != NULL)
										{
											tmp3 = tmp3->next;
										}
										tmp3->next = tmp11;
										tmp11->next = NULL;
										tmp11->prev = tmp3;
										NumOfBlock[m + 1]++;
										flag[m + 1] = 1;
										//���
										for (int p = 0; p < 10; p++)
										{
											struct Block* tmp_print = Freeblock[p]->next;
											while (tmp_print != NULL && tmp_print->next != NULL)
											{
												printf("free block id:%d,size:%d,startAddr:%d\n", tmp_print->id, tmp_print->sizeK, tmp_print->startAddr);
												tmp_print = tmp_print->next;
											}
											if (tmp_print != NULL)
											{
												printf("free block id:%d,size:%d,startAddr:%d\n", tmp_print->id, tmp_print->sizeK, tmp_print->startAddr);
											}
										}
										for (int p = 0; p < 10; p++)
										{
											struct Block* tmp_print = Usedblock[p]->next;
											while (tmp_print != NULL && tmp_print->next != NULL)
											{
												printf("Used block id:%d,size:%d,startAddr:%d,pid:%d\n", tmp_print->id, tmp_print->sizeK, tmp_print->startAddr, tmp_print->pid);
												tmp_print = tmp_print->next;
											}
											if (tmp_print != NULL)
											{
												printf("Used block id:%d,size:%d,startAddr:%d,pid:%d\n", tmp_print->id, tmp_print->sizeK, tmp_print->startAddr, tmp_print->pid);
											}
										}
									}
								}
								//����tmp2���±����������Ϊ����û�з����ϲ�ʱtmp2�ı仯
								if (turn == 0)
								{
									if (tmp2 == NULL)
									{
										break;
									}
									tmp2 = tmp2->next;
								}
								//���¶���tmp11��tmp22�����������ʹ��
								struct Block* tmp22 = tmp2;
								struct Block* tmp11 = tmp1;
							}
							//�ж���һ�����ܷ�ϲ�����turnΪ0ʱ����ʾ�˿�����֮����κο鶼�޷��ϲ���������һ����
							if (turn == 0)
							{
								tmp1 = tmp1->next;
							}
							//�����ϲ��󣬴�ͷ����ٴα�������Ϊ�������˱仯
							else if (turn == 1)
							{
								n--;
							}
						}
						if (change == 0)
						{
							break;
						}
					}
				}
			}

		}

	}
	return 1;
}

int Buddy2() {
	static int flag[10];//��¼��СΪ2^k�Ŀ����Ƿ����һ��Ԫ��
	static int flag2[10];
	static int NumOfBlock[10];
	static int NumOfBlock2[10];
	struct Block* Freeblock[10];
	struct Block* Usedblock[10];
	srand((unsigned)time(NULL));

	struct PCB* PCBchain = (struct PCB*)malloc(sizeof(struct PCB));//�����б�ͷ���
	PCBchain->next = NULL;
	for (int i = 0; i < NumOfProc; i++)
	{
		struct PCB* P = (struct PCB*)malloc(sizeof(struct PCB));
		P->blockID = -1;
		P->neededMem = pow(2, rand() % 6 + 3);
		P->status = 0;
		P->pid = i + 1;
		struct PCB* tmp = PCBchain;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = P;
		P->next = NULL;
	}


	NumOfFreeBlock = 0;
	NumofBlockId = 0;
	NumOfUsedBlock = 0;

	struct Block* FreeBlockchain0 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain1 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain2 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain3 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain4 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain5 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain6 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain7 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain8 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���
	struct Block* FreeBlockchain9 = (struct Block*)malloc(sizeof(struct Block));//δ�����ڴ������ͷ���

	FreeBlockchain0->next = NULL;
	FreeBlockchain1->next = NULL;
	FreeBlockchain2->next = NULL;
	FreeBlockchain3->next = NULL;
	FreeBlockchain4->next = NULL;
	FreeBlockchain5->next = NULL;
	FreeBlockchain6->next = NULL;
	FreeBlockchain7->next = NULL;
	FreeBlockchain8->next = NULL;
	FreeBlockchain9->next = NULL;

	Freeblock[0] = FreeBlockchain0;
	Freeblock[1] = FreeBlockchain1;
	Freeblock[2] = FreeBlockchain2;
	Freeblock[3] = FreeBlockchain3;
	Freeblock[4] = FreeBlockchain4;
	Freeblock[5] = FreeBlockchain5;
	Freeblock[6] = FreeBlockchain6;
	Freeblock[7] = FreeBlockchain7;
	Freeblock[8] = FreeBlockchain8;
	Freeblock[9] = FreeBlockchain9;

	struct Block* UsedBlockchain0 = (struct Block*)malloc(sizeof(struct Block));//�ѷ����ڴ������ͷ���
	struct Block* UsedBlockchain1 = (struct Block*)malloc(sizeof(struct Block));//�ѷ����ڴ������ͷ���
	struct Block* UsedBlockchain2 = (struct Block*)malloc(sizeof(struct Block));//�ѷ����ڴ������ͷ���
	struct Block* UsedBlockchain3 = (struct Block*)malloc(sizeof(struct Block));//�ѷ����ڴ������ͷ���
	struct Block* UsedBlockchain4 = (struct Block*)malloc(sizeof(struct Block));//�ѷ����ڴ������ͷ���
	struct Block* UsedBlockchain5 = (struct Block*)malloc(sizeof(struct Block));//�ѷ����ڴ������ͷ���
	struct Block* UsedBlockchain6 = (struct Block*)malloc(sizeof(struct Block));//�ѷ����ڴ������ͷ���
	struct Block* UsedBlockchain7 = (struct Block*)malloc(sizeof(struct Block));//�ѷ����ڴ������ͷ���
	struct Block* UsedBlockchain8 = (struct Block*)malloc(sizeof(struct Block));//�ѷ����ڴ������ͷ���
	struct Block* UsedBlockchain9 = (struct Block*)malloc(sizeof(struct Block));//�ѷ����ڴ������ͷ���

	UsedBlockchain0->next = NULL;
	UsedBlockchain1->next = NULL;
	UsedBlockchain2->next = NULL;
	UsedBlockchain3->next = NULL;
	UsedBlockchain4->next = NULL;
	UsedBlockchain5->next = NULL;
	UsedBlockchain6->next = NULL;
	UsedBlockchain7->next = NULL;
	UsedBlockchain8->next = NULL;
	UsedBlockchain9->next = NULL;

	Usedblock[0] = UsedBlockchain0;
	Usedblock[1] = UsedBlockchain1;
	Usedblock[2] = UsedBlockchain2;
	Usedblock[3] = UsedBlockchain3;
	Usedblock[4] = UsedBlockchain4;
	Usedblock[5] = UsedBlockchain5;
	Usedblock[6] = UsedBlockchain6;
	Usedblock[7] = UsedBlockchain7;
	Usedblock[8] = UsedBlockchain8;
	Usedblock[9] = UsedBlockchain9;

	//��ʼ�ڴ��B1
	NumOfFreeBlock++;
	NumofBlockId++;
	struct Block* B1 = (struct Block*)malloc(sizeof(struct Block));
	FreeBlockchain9->next = B1;
	B1->prev = FreeBlockchain9;
	B1->sizeK = pow(2, 10);
	B1->startAddr = 0;
	B1->id = NumofBlockId;
	B1->next = NULL;
	flag[int(log2(B1->sizeK) - 1)] = 1;
	NumOfBlock[int(log2(B1->sizeK) - 1)] ++;

	struct PCB* tmp_PCB = PCBchain;
	for (int i = 0; i < NumOfProc; i++)
	{
		tmp_PCB = tmp_PCB->next;
		printf("Allocate free memory block for process %d of size %d\n", tmp_PCB->pid,tmp_PCB->neededMem);
		if (flag[int(log2(tmp_PCB->neededMem)) - 1] == 1)
		{//���б��д������PCB������ͬ���ڴ��,�����Ƚ�������Ŀ��ȱ�����ԭ��
			struct Block* tmp = Freeblock[int(log2(tmp_PCB->neededMem)) - 1]; tmp = tmp->next;
			if (tmp->next == NULL)
			{
				tmp->prev->next = NULL;
			}
			else
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
			tmp->pid = tmp_PCB->pid; tmp_PCB->blockID = tmp->id;
			tmp->status = 1; tmp_PCB->status = 1;
			NumOfBlock[int(log2(tmp_PCB->neededMem)) - 1]--;
			if (NumOfBlock[int(log2(tmp_PCB->neededMem)) - 1] == 0)
			{
				flag[int(log2(tmp_PCB->neededMem)) - 1] = 0;
			}
			struct Block* tmp1 = Usedblock[int(log2(tmp_PCB->neededMem)) - 1];
			while (tmp1->next != NULL)
			{
				tmp1 = tmp1->next;
			}
			tmp1->next = tmp;
			tmp->prev = tmp1; 
			tmp->next = NULL;
			NumOfFreeBlock--;
			NumOfUsedBlock++;
			NumOfBlock2[int(log2(tmp_PCB->neededMem)) - 1]++;
			flag2[int(log2(tmp_PCB->neededMem)) - 1] = 1;
			for (int i = 0; i < 10; i++)
			{
				struct Block* tmp = Freeblock[i]; tmp = tmp->next;
				while (tmp != NULL && tmp->next != NULL)
				{
					printf("free block id:%d,size:%d,startAddr:%d\n", tmp->id, tmp->sizeK, tmp->startAddr);
					tmp = tmp->next;
				}
				if (tmp != NULL)
				{
					printf("free block id:%d,size:%d,startAddr:%d\n", tmp->id, tmp->sizeK, tmp->startAddr);
				}
			}
			for (int i = 0; i < 10; i++)
			{
				struct Block* tmp = Usedblock[i]; tmp = tmp->next;
				while (tmp != NULL && tmp->next != NULL)
				{
					printf("uesd block id:%d,size:%d,startAddr:%d,pid:%d\n", tmp->id, tmp->sizeK, tmp->startAddr, tmp->pid);
					tmp = tmp->next;
				}
				if (tmp != NULL)
				{
					printf("uesd block id:%d,size:%d,startAddr:%d,pid:%d\n", tmp->id, tmp->sizeK, tmp->startAddr, tmp->pid);
				}
			}
		}
		else
		{
			int cut = 1;
			for (int i = int(log2(tmp_PCB->neededMem)); i < 10; i++)
			{
				if (flag[i] == 1)
				{
					cut = 1;
				}
			}
			if (cut == 0) //��ʾ����Ҫ�����ڴ���δ����鲻���ڣ��������ʧ��
			{
				printf("process %d fail in allocation...\n", tmp_PCB->pid);
				continue;
			}
			else
			{
				while (flag[int(log2(tmp_PCB->neededMem)) - 1] == 0)
				{
					for (int i = int(log2(tmp_PCB->neededMem)); i < 10; i++)
					{
						if (flag[i] == 1)
						{//�����б�ĩβ�Ŀ�ָ�
							struct Block* tmp = Freeblock[i];
							while (tmp->next != NULL)
							{
								tmp = tmp->next;
							}
							tmp->sizeK = tmp->sizeK / 2;
							tmp->prev->next = tmp->next;
							if (tmp->next != NULL)
							{
								tmp->next->prev = tmp->prev;
							}
							struct Block* tmpnew = Freeblock[int(log2(tmp->sizeK)) - 1];
							while (tmpnew->next != NULL)
							{
								tmpnew = tmpnew->next;
							}
							tmpnew->next = tmp;
							tmp->next = NULL;
							tmp->prev = tmpnew;

							NumOfBlock[int(log2(tmp->sizeK)) - 1] ++;
							flag[int(log2(tmp->sizeK)) - 1] = 1;
							NumOfBlock[int(log2(tmp->sizeK))] --;
							if (NumOfBlock[int(log2(tmp->sizeK))] == 0)
							{
								flag[int(log2(tmp->sizeK))] = 0;
							}

							NumOfFreeBlock++;
							NumofBlockId++;
							struct Block* newblock = (struct Block*)malloc(sizeof(struct Block));
							newblock->sizeK = tmp->sizeK;
							newblock->startAddr = tmp->startAddr + tmp->sizeK;
							newblock->id = NumofBlockId;
							struct Block* tmpnew1 = Freeblock[int(log2(newblock->sizeK)) - 1];
							while (tmpnew1->next != NULL)
							{
								tmpnew1 = tmpnew1->next;
							}
							tmpnew1->next = newblock;
							newblock->next = NULL;
							newblock->prev = tmpnew1;
							NumOfBlock[int(log2(newblock->sizeK)) - 1] ++;
							break;
						}
					}
				}
				if (flag[int(log2(tmp_PCB->neededMem)) - 1] == 1)
				{//���б��д������PCB������ͬ���ڴ��,�����Ƚ�������Ŀ��ȱ�����ԭ��
					struct Block* tmp = Freeblock[int(log2(tmp_PCB->neededMem)) - 1]; tmp = tmp->next;
					if (tmp->next == NULL)
					{
						tmp->prev->next = NULL;
					}
					else
					{
						tmp->prev->next = tmp->next;
						tmp->next->prev = tmp->prev;
					}
					tmp->pid = tmp_PCB->pid; tmp_PCB->blockID = tmp->id;
					tmp->status = 1; tmp_PCB->status = 1;
					NumOfBlock[int(log2(tmp_PCB->neededMem)) - 1]--;
					if (NumOfBlock[int(log2(tmp_PCB->neededMem)) - 1] == 0)
					{
						flag[int(log2(tmp_PCB->neededMem)) - 1] = 0;
					}
					NumOfBlock2[int(log2(tmp_PCB->neededMem)) - 1]++;
					flag2[int(log2(tmp_PCB->neededMem)) - 1] = 1;
					struct Block* tmp1 = Usedblock[int(log2(tmp_PCB->neededMem)) - 1];
					while (tmp1->next != NULL)
					{
						tmp1 = tmp1->next;
					}
					tmp1->next = tmp;
					tmp->prev = tmp1; tmp->next = NULL;
					NumOfFreeBlock--;
					NumOfUsedBlock++;
					for (int i = 0; i < 10; i++)
					{
						struct Block* tmp = Freeblock[i]; tmp = tmp->next;
						while (tmp != NULL && tmp->next != NULL)
						{
							printf("free block id:%d,size:%d,startAddr:%d\n", tmp->id, tmp->sizeK, tmp->startAddr);
							tmp = tmp->next;
						}
						if (tmp != NULL)
						{
							printf("free block id:%d,size:%d,startAddr:%d\n", tmp->id, tmp->sizeK, tmp->startAddr);
						}
					}
					for (int i = 0; i < 10; i++)
					{
						struct Block* tmp = Usedblock[i]; tmp = tmp->next;
						while (tmp != NULL && tmp->next != NULL)
						{
							printf("uesd block id:%d,size:%d,startAddr:%d,pid:%d\n", tmp->id, tmp->sizeK, tmp->startAddr, tmp->pid);
							tmp = tmp->next;
						}
						if (tmp != NULL)
						{
							printf("uesd block id:%d,size:%d,startAddr:%d,pid:%d\n", tmp->id, tmp->sizeK, tmp->startAddr, tmp->pid);
						}
					}
				}
			}
		}
	}
	//�ϲ��ڴ�
	for (int i = 0; i < 10; i++)
	{
		if (flag2[i] == 1)
		{
			struct Block* tmp = Usedblock[i]->next;
			for (int j = 0; j < NumOfBlock2[i]; j++)
			{
				struct Block* tmp1 = tmp;
				//����i�Ż�freeblock��
				printf("Recycle used memory block for process %d of size %d\n", tmp->pid,tmp->sizeK);
				if (tmp->next == NULL)
				{
					tmp->prev->next = NULL;
					tmp = tmp1->next;
				}
				else
				{
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
					tmp = tmp1->next;
				}
				tmp1->status = 0;
				tmp1->pid = -1;
				tmp1->next = NULL;
				NumOfUsedBlock--;
				NumOfBlock2[i] --;
				if (NumOfBlock2[i] == 0)
				{
					flag2[i] = 0;
				}
				struct Block* tmp2 = Freeblock[int(log2(tmp1->sizeK) - 1)];
				while (tmp2->next != NULL)
				{
					tmp2 = tmp2->next;
				}
				tmp2->next = tmp1;
				tmp1->prev = tmp2;
				NumOfBlock[int(log2(tmp1->sizeK) - 1)]++;
				flag[int(log2(tmp1->sizeK) - 1)] = 1;
				NumOfFreeBlock++;
				j--;
				//�鿴�Ƿ��пɺϲ���
				for (int m = 0; m < 10; m++)
				{
					while (NumOfBlock[m] >= 2) {
						struct Block* tmp1 = Freeblock[m]->next;
						int change = 0;
						for (int n = 0; n < NumOfBlock[m]; n++)
						{
							struct Block* tmp11 = tmp1;
							//������СΪ2^i+1�η��Ŀ������޿��Ժϲ����ӿ�
							//�Ƿ񾭹����б�����û�кϲ���û���������һ����
							int turn = 0;
							struct Block* tmp2 = tmp1->next;
							struct Block* tmp22 = tmp2;
							if (tmp2 == NULL) break;
							for (int k = 0; k < NumOfBlock[m]; k++)
							{
								if (tmp1->startAddr % (tmp1->sizeK * 2) == 0)
								{
									if (tmp2!= NULL && tmp2->startAddr == tmp1->startAddr + tmp1->sizeK) {
										printf("Combine block %d and %d of size %d\n", tmp1->id, tmp2->id, tmp1->sizeK);
										turn = 1; change = 1;
										//�ҵ����
										//�ϲ�tmp11��tmp12
										tmp11->sizeK = tmp1->sizeK + tmp2->sizeK;
										//�Ƴ�tmp11��tmp22
										if (tmp1->next == NULL) { tmp1->prev->next = NULL; tmp1 = tmp11->next; }
										else {
											tmp1->prev->next = tmp1->next; tmp1->next->prev = tmp1->prev; tmp1 = tmp11->prev->next;
										}
										if (tmp2->next == NULL) { tmp2->prev->next = NULL; tmp2 = tmp22->next; }
										else {
											tmp2->prev->next = tmp2->next; tmp2->next->prev = tmp2->prev; tmp2 = tmp22->prev->next;
										}
										NumOfBlock[m] = NumOfBlock[m] - 2;
										if (NumOfBlock[m] == 0) flag[m] = 0;
										NumOfFreeBlock--;
										struct Block* tmp3 = Freeblock[m + 1];
										while (tmp3->next != NULL)
										{
											tmp3 = tmp3->next;
										}
										tmp3->next = tmp11;
										tmp11->next = NULL;
										tmp11->prev = tmp3;
										NumOfBlock[m + 1]++;
										flag[m + 1] = 1;
										for (int p = 0; p < 10; p++)
										{
											struct Block* tmp_print = Freeblock[p]->next;
											while (tmp_print != NULL && tmp_print->next != NULL)
											{
												printf("free block id:%d,size:%d,startAddr:%d\n", tmp_print->id, tmp_print->sizeK, tmp_print->startAddr);
												tmp_print = tmp_print->next;
											}
											if (tmp_print != NULL)
											{
												printf("free block id:%d,size:%d,startAddr:%d\n", tmp_print->id, tmp_print->sizeK, tmp_print->startAddr);
											}
										}
										for (int p = 0; p < 10; p++)
										{
											struct Block* tmp_print = Usedblock[p]->next;
											while (tmp_print != NULL && tmp_print->next != NULL)
											{
												printf("Used block id:%d,size:%d,startAddr:%d,pid:%d\n", tmp_print->id, tmp_print->sizeK, tmp_print->startAddr, tmp_print->pid);
												tmp_print = tmp_print->next;
											}
											if (tmp_print != NULL)
											{
												printf("Used block id:%d,size:%d,startAddr:%d,pid:%d\n", tmp_print->id, tmp_print->sizeK, tmp_print->startAddr, tmp_print->pid);
											}
										}
									}
								}
								else if (tmp1->startAddr % (tmp1->sizeK * 2) == tmp1->sizeK)
								{
									if (tmp2!= NULL && tmp2->startAddr == tmp1->startAddr - tmp1->sizeK) {
										printf("Combine block %d and %d of size %d\n", tmp1->id, tmp2->id, tmp1->sizeK);
										turn = 1; change = 1;
										//�ҵ����
										//�ϲ�tmp1��tmp2
										tmp11->startAddr = tmp2->startAddr;
										tmp11->sizeK = tmp1->sizeK + tmp2->sizeK;
										//�Ƴ�tmp2��tmp1
										if (tmp1->next == NULL) { tmp1->prev->next = NULL; tmp1 = tmp11->next; }
										else {
											tmp1->prev->next = tmp1->next; tmp1->next->prev = tmp1->prev; tmp1 = tmp11->prev->next;
										}
										if (tmp2->next == NULL) { tmp2->prev->next = NULL; tmp2 = tmp22->next; }
										else {
											tmp2->prev->next = tmp2->next; tmp2->next->prev = tmp2->prev; tmp2 = tmp22->prev->next;
										}
										NumOfBlock[m] = NumOfBlock[m] - 2;
										if (NumOfBlock[m] == 0) flag[m] = 0;
										NumOfFreeBlock--;
										struct Block* tmp3 = Freeblock[m + 1];
										while (tmp3->next != NULL)
										{
											tmp3 = tmp3->next;
										}
										tmp3->next = tmp11;
										tmp11->next = NULL;
										tmp11->prev = tmp3;
										NumOfBlock[m + 1]++;
										flag[m + 1] = 1;
										for (int p = 0; p < 10; p++)
										{
											struct Block* tmp_print = Freeblock[p]->next;
											while (tmp_print != NULL && tmp_print->next != NULL)
											{
												printf("free block id:%d,size:%d,startAddr:%d\n", tmp_print->id, tmp_print->sizeK, tmp_print->startAddr);
												tmp_print = tmp_print->next;
											}
											if (tmp_print != NULL)
											{
												printf("free block id:%d,size:%d,startAddr:%d\n", tmp_print->id, tmp_print->sizeK, tmp_print->startAddr);
											}
										}
										for (int p = 0; p < 10; p++)
										{
											struct Block* tmp_print = Usedblock[p]->next;
											while (tmp_print != NULL && tmp_print->next != NULL)
											{
												printf("Used block id:%d,size:%d,startAddr:%d,pid:%d\n", tmp_print->id, tmp_print->sizeK, tmp_print->startAddr, tmp_print->pid);
												tmp_print = tmp_print->next;
											}
											if (tmp_print != NULL)
											{
												printf("Used block id:%d,size:%d,startAddr:%d,pid:%d\n", tmp_print->id, tmp_print->sizeK, tmp_print->startAddr, tmp_print->pid);
											}
										}
									}
								}
								if (turn == 0)
								{
									if (tmp2 == NULL)
									{
										break;
									}
									tmp2 = tmp2->next;
								}
								struct Block* tmp22 = tmp2;
								struct Block* tmp11 = tmp1;
							}
							if (turn == 0)
							{
								tmp1 = tmp1->next;
							}
							else if (turn == 1)
							{
								n--;
							}
						}
						if (change == 0)
						{
							break;
						}
					}
				}
			}
			
		}
		
	}
	return 1;
}

int main() {
	//Buddy1();
	//printf("****************************************************************");
	Buddy2();
	return 1;
}