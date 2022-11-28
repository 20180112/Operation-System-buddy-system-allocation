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
	static int flag[10];//记录大小为2^k的未分配内存块链是否存在一个元素
	static int flag2[10];//记录大小为2^k的被使用的内存块链是否存在一个元素
	static int NumOfBlock[10];//记录未分配内存块链中每个大小的内存块的个数
	static int NumOfBlock2[10];//记录被使用的内存块链中每个大小的内存块的个数
	struct Block* Freeblock[10];//未分配内存块链头结点
	struct Block* Usedblock[10];//使用中的内存块链头结点
	srand((unsigned)time(NULL));
	//根据题目建立PCB链表
	struct PCB* PCBchain = (struct PCB*)malloc(sizeof(struct PCB));//进程列表头结点
	struct PCB* P1 = (struct PCB*)malloc(sizeof(struct PCB));
	struct PCB* P2 = (struct PCB*)malloc(sizeof(struct PCB));
	struct PCB* P3 = (struct PCB*)malloc(sizeof(struct PCB));
	PCBchain->next = P1; P1->next = P2; P2->next = P3; P3->next = NULL;//三个PCB连接
	P1->neededMem = pow(2, 7); P2->neededMem = pow(2, 4); P3->neededMem = pow(2, 8);//所需内存分配
	P1->blockID = -1; P2->blockID = -1; P3->blockID = -1;
	P1->status = 0; P2->status = 0; P3->status = 0;
	P1->pid = 1; P2->pid = 2; P3->pid = 3;
	//变量初始化
	NumOfFreeBlock = 0;
	NumofBlockId = 0;
	NumOfUsedBlock = 0;

	struct Block* FreeBlockchain0 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain1 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain2 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain3 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain4 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain5 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain6 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain7 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain8 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain9 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点

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

	struct Block* UsedBlockchain0 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* UsedBlockchain1 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* UsedBlockchain2 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* UsedBlockchain3 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* UsedBlockchain4 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* UsedBlockchain5 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* UsedBlockchain6 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* UsedBlockchain7 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* UsedBlockchain8 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* UsedBlockchain9 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点

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

	//初始内存块B1，初始内存1024，初始位置0
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
	{//遍历所有进程
		tmp_PCB = tmp_PCB->next;
		printf("Allocate free memory block for process %d of size %d\n", tmp_PCB->pid, tmp_PCB->neededMem);
		if (flag[int(log2(tmp_PCB->neededMem)) - 1] == 1)
		{//若列表中存在与此PCB容量相同的内存块,根据先进入链表的块先被分配原则
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
			//设置内存块分配给当前进程，并且调整对应内存块个数和flag数组
			tmp->pid = tmp_PCB->pid; tmp_PCB->blockID = tmp->id;
			tmp->status = 1; tmp_PCB->status = 1;
			NumOfBlock[int(log2(tmp_PCB->neededMem)) - 1]--;
			if (NumOfBlock[int(log2(tmp_PCB->neededMem)) - 1] == 0)
			{
				flag[int(log2(tmp_PCB->neededMem)) - 1] = 0;
			}
			//将内存块移到使用中的内存块链，并且调整对应内存块个数和flag数组
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
			//输出
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
		{//内存块中不存在可分配的内存，需要切割
			int cut = 1;
			for (int i = int(log2(tmp_PCB->neededMem)); i < 10; i++)
			{//当存在一个比需要的内存大的内存块就可以切割
				if (flag[i] == 1)
				{
					cut = 1;
				}
			}
			if (cut == 0) //表示比需要分配内存大的未分配块不存在，输出分配失败
			{//无法切割的情况
				printf("process %d fail in allocation...\n", tmp_PCB->pid);
				continue;
			}
			else
			{//进行切割
				while (flag[int(log2(tmp_PCB->neededMem)) - 1] == 0)
				{//当需要的内存块仍未被切割出来，就一直分割
					for (int i = int(log2(tmp_PCB->neededMem)); i < 10; i++)
					{
						if (flag[i] == 1)
						{//将此列表末尾的块分割
							struct Block* tmp = Freeblock[i];
							while (tmp->next != NULL)
							{
								tmp = tmp->next;
							}
							//将块大小减小，并移出当前链块
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
							//将相应链表的块数改变
							NumOfBlock[int(log2(tmp->sizeK)) - 1] ++;
							flag[int(log2(tmp->sizeK)) - 1] = 1;
							NumOfBlock[int(log2(tmp->sizeK))] --;
							if (NumOfBlock[int(log2(tmp->sizeK))] == 0)
							{
								flag[int(log2(tmp->sizeK))] = 0;
							}
							//分割成两块整个空闲块加1，所有块+1
							NumOfFreeBlock++;
							NumofBlockId++;
							//移到相应大小的块链中
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
				{//若列表中存在与此PCB容量相同的内存块,根据先进入链表的块先被分配原则，与上述一致
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
	//合并内存：先释放一个正在使用的内存块，看看未分配内存块中是否有可以合并的内存块
	for (int i = 0; i < 10; i++)
	{
		if (flag2[i] == 1)
		{//依次释放正在使用的内存块，通过遍历正在使用的内存块链
			struct Block* tmp = Usedblock[i]->next;
			for (int j = 0; j < NumOfBlock2[i]; j++)
			{
				struct Block* tmp1 = tmp;
				//将块i放回freeblock中
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
				//更新块的相关状态，并且将相关块数改变
				tmp1->status = 0;
				tmp1->pid = -1;
				tmp1->next = NULL;
				NumOfUsedBlock--;
				NumOfBlock2[i] --;
				if (NumOfBlock2[i] == 0)
				{
					flag2[i] = 0;
				}
				//插入相应的未分配块中
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
				//查看是否有可合并块
				for (int m = 0; m < 10; m++)
				{
					while (NumOfBlock[m] >= 2) {
						//如果一个链中至少有2个块，那么就有可能合并
						struct Block* tmp1 = Freeblock[m]->next;
						int change = 0;
						for (int n = 0; n < NumOfBlock[m]; n++)
						{
							struct Block* tmp11 = tmp1;
							//遍历大小为2^i+1次方的块中有无可以合并的子块
							//是否经过所有遍历后都没有合并，没有则遍历下一个块
							int turn = 0;
							struct Block* tmp2 = tmp1->next;//初始tmp2指向tmp1的下一个块，看两个块能否合并
							struct Block* tmp22 = tmp2;
							if (tmp2 == NULL) break;
							//遍历此链
							for (int k = 0; k < NumOfBlock[m]; k++)
							{//利用相关公式判断是否能合并
								if (tmp1->startAddr % (tmp1->sizeK * 2) == 0)
								{
									if (tmp2 != NULL && tmp2->startAddr == tmp1->startAddr + tmp1->sizeK) {
										//tmp2能与tmp1合并，并且tmp1在tmp2的上面
										printf("Combine block %d and %d of size %d\n", tmp1->id, tmp2->id, tmp1->sizeK);
										turn = 1; change = 1;
										//找到伙伴
										//合并tmp11和tmp12
										tmp11->sizeK = tmp1->sizeK + tmp2->sizeK;
										//移出tmp11和tmp22
										if (tmp1->next == NULL) { tmp1->prev->next = NULL; tmp1 = tmp11->next; }//tmp1指向此链下一个块
										else {
											tmp1->prev->next = tmp1->next; tmp1->next->prev = tmp1->prev; tmp1 = tmp11->prev->next;
										}
										if (tmp2->next == NULL) { tmp2->prev->next = NULL; tmp2 = tmp22->next; }//tmp2指向此链下一个块
										else {
											tmp2->prev->next = tmp2->next; tmp2->next->prev = tmp2->prev; tmp2 = tmp22->prev->next;
										}
										//相应链表中的块数减少
										NumOfBlock[m] = NumOfBlock[m] - 2;
										if (NumOfBlock[m] == 0) flag[m] = 0;
										NumOfFreeBlock--;
										//将合并后的块转移到对应的内存大小的链中
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
										//输出
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
								{//伙伴关系的另一种情况
									if (tmp2 != NULL && tmp2->startAddr == tmp1->startAddr - tmp1->sizeK) {
										//tmp2能与tmp1合并，并且tmp1在tmp2的下面，与上面同理
										printf("Combine block %d and %d of size %d\n", tmp1->id, tmp2->id, tmp1->sizeK);
										turn = 1; change = 1;
										//找到伙伴
										//合并tmp1和tmp2
										tmp11->startAddr = tmp2->startAddr;
										tmp11->sizeK = tmp1->sizeK + tmp2->sizeK;
										//移出tmp2和tmp1
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
										//输出
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
								//利用tmp2向下遍历，此情况为上面没有发生合并时tmp2的变化
								if (turn == 0)
								{
									if (tmp2 == NULL)
									{
										break;
									}
									tmp2 = tmp2->next;
								}
								//重新定义tmp11和tmp22，供上面代码使用
								struct Block* tmp22 = tmp2;
								struct Block* tmp11 = tmp1;
							}
							//判断下一个块能否合并，当turn为0时，表示此块与其之后的任何块都无法合并，遍历下一个块
							if (turn == 0)
							{
								tmp1 = tmp1->next;
							}
							//发生合并后，从头向后再次遍历，因为链表发生了变化
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
	static int flag[10];//记录大小为2^k的块链是否存在一个元素
	static int flag2[10];
	static int NumOfBlock[10];
	static int NumOfBlock2[10];
	struct Block* Freeblock[10];
	struct Block* Usedblock[10];
	srand((unsigned)time(NULL));

	struct PCB* PCBchain = (struct PCB*)malloc(sizeof(struct PCB));//进程列表头结点
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

	struct Block* FreeBlockchain0 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain1 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain2 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain3 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain4 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain5 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain6 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain7 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain8 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点
	struct Block* FreeBlockchain9 = (struct Block*)malloc(sizeof(struct Block));//未分配内存块链的头结点

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

	struct Block* UsedBlockchain0 = (struct Block*)malloc(sizeof(struct Block));//已分配内存块链的头结点
	struct Block* UsedBlockchain1 = (struct Block*)malloc(sizeof(struct Block));//已分配内存块链的头结点
	struct Block* UsedBlockchain2 = (struct Block*)malloc(sizeof(struct Block));//已分配内存块链的头结点
	struct Block* UsedBlockchain3 = (struct Block*)malloc(sizeof(struct Block));//已分配内存块链的头结点
	struct Block* UsedBlockchain4 = (struct Block*)malloc(sizeof(struct Block));//已分配内存块链的头结点
	struct Block* UsedBlockchain5 = (struct Block*)malloc(sizeof(struct Block));//已分配内存块链的头结点
	struct Block* UsedBlockchain6 = (struct Block*)malloc(sizeof(struct Block));//已分配内存块链的头结点
	struct Block* UsedBlockchain7 = (struct Block*)malloc(sizeof(struct Block));//已分配内存块链的头结点
	struct Block* UsedBlockchain8 = (struct Block*)malloc(sizeof(struct Block));//已分配内存块链的头结点
	struct Block* UsedBlockchain9 = (struct Block*)malloc(sizeof(struct Block));//已分配内存块链的头结点

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

	//初始内存块B1
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
		{//若列表中存在与此PCB容量相同的内存块,根据先进入链表的块先被分配原则
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
			if (cut == 0) //表示比需要分配内存大的未分配块不存在，输出分配失败
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
						{//将此列表末尾的块分割
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
				{//若列表中存在与此PCB容量相同的内存块,根据先进入链表的块先被分配原则
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
	//合并内存
	for (int i = 0; i < 10; i++)
	{
		if (flag2[i] == 1)
		{
			struct Block* tmp = Usedblock[i]->next;
			for (int j = 0; j < NumOfBlock2[i]; j++)
			{
				struct Block* tmp1 = tmp;
				//将块i放回freeblock中
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
				//查看是否有可合并块
				for (int m = 0; m < 10; m++)
				{
					while (NumOfBlock[m] >= 2) {
						struct Block* tmp1 = Freeblock[m]->next;
						int change = 0;
						for (int n = 0; n < NumOfBlock[m]; n++)
						{
							struct Block* tmp11 = tmp1;
							//遍历大小为2^i+1次方的块中有无可以合并的子块
							//是否经过所有遍历后都没有合并，没有则遍历下一个块
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
										//找到伙伴
										//合并tmp11和tmp12
										tmp11->sizeK = tmp1->sizeK + tmp2->sizeK;
										//移出tmp11和tmp22
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
										//找到伙伴
										//合并tmp1和tmp2
										tmp11->startAddr = tmp2->startAddr;
										tmp11->sizeK = tmp1->sizeK + tmp2->sizeK;
										//移出tmp2和tmp1
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