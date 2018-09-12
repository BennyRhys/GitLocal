#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR -1
#define MAX_SIZE 200
typedef int Status;
typedef int ELemType;

typedef struct sqlist{
    ELemType *Elem_array;
    int length;
}SqList;

Status Init_SqList(SqList *L);                       /*初始化数组*/
Status Insert_SqList(SqList *L, int i, ELemType e);  /*插入数据*/
Status Delete_Locate_SqList(SqList *L,int x);        /*删除指定位置的元素*/
Status Delete_Date_SqList(SqList *L,int x);          /*删除指定值的元素*/
void Sort_SqList(SqList *L);                         /*选择排序*/
void Clear_SqList(SqList *L);                        /*清空表*/
void DestoryByTable(SqList *L);                      /*销毁表*/
Status IfEmpty_SqList(SqList *L);                    /*判断是否是空表*/
void PrintTable_SqList(SqList *L);                   /*输出*/
int Length_SqList(SqList *L);                        /*输出数组L的长度*/
void FindByDate_SqList(SqList *L, ELemType e);       /*按值查找线性表中的元素*/
void FindByLocate_SqList(SqList *L,int i);           /*按位置查找线性表中的元素*/
void merge_SqList(SqList *L, SqList *M);             /*合并线性表*/


/*主方法*/
int main()  /*定义变量应该放在方法的最前边*/
{
    SqList L;
    SqList M;
    int i;
    int op;
    int flag = 0;
    ELemType e;

    Init_SqList(&L);
    Init_SqList(&M);
    Insert_SqList(&L,1,0);
    Insert_SqList(&L,2,10);
    Insert_SqList(&L,3,31);
    Insert_SqList(&L,4,4);
    Insert_SqList(&L,5,54);
    Insert_SqList(&L,6,6);
    Insert_SqList(&L,7,7);
    Insert_SqList(&L,8,8);
    Insert_SqList(&L,9,8);
    Insert_SqList(&L,10,10);
    Insert_SqList(&L,11,11);
    Insert_SqList(&L,12,12);
    Insert_SqList(&L,13,13);
    Insert_SqList(&L,14,14);
    Insert_SqList(&L,15,15);

    Insert_SqList(&M,1,18);
    Insert_SqList(&M,2,99);
    Insert_SqList(&M,3,44);
    Insert_SqList(&M,4,66);
    Insert_SqList(&M,5,-1);
    Insert_SqList(&M,6,102);

    printf("数组初始化完成\n");

    PrintTable_SqList(&L);
    PrintTable_SqList(&M);

    do{
    printf("\n");
    printf("*****************\n");
    printf("功能：\n");
    printf("1,退出\n");
    printf("2,清空表\n");
    printf("3,销毁表\n");
    printf("4,排序\n");
    printf("5,删除表中指定位置的元素\n");
    printf("6,删除指定值的元素\n");
    printf("7,插入元素\n");
    printf("8,按值查找表中的元素\n");
    printf("9,按位置查找表中的元素\n");
    printf("10,合并线性表\n");
    printf("请选择一项功能：");
    scanf("%d",&op);  /*scanf的“”里不能加\n，否则会报错*/


    switch(op){
    case 1:
        flag = 1;
        break;
    case 2:
        Clear_SqList(&L);
        PrintTable_SqList(&L);
        printf("清空成功!\n");
        break;
    case 3:
        DestoryByTable(&L);
        PrintTable_SqList(&L);
        printf("销毁成功！\n");
        break;
    case 4:
        Sort_SqList(&L);
        PrintTable_SqList(&L);
        break;
    case 5:
        printf("请输入要删除的元素的位置:");
        scanf("%d",&i);
        Delete_Locate_SqList(&L, i);
        PrintTable_SqList(&L);
        break;
    case 6:
        printf("请输入要删除的元素的值:");
        scanf("%d",&e);
        Delete_Date_SqList(&L, e);
        PrintTable_SqList(&L);
        break;
    case 7:
        printf("请输入要插入的数的位置:");
        scanf("%d",&i);
        printf("请输入要插入的数");
        scanf("%d",&e);
        Insert_SqList(&L,i,e);
        PrintTable_SqList(&L);
        break;
    case 8:
        printf("请输入要查找的元素的值：");
        scanf("%d",&e);
        FindByDate_SqList(&L,e);
        break;
    case 9:
        printf("请输入要查找元素的位置：");
        scanf("%d", &i);
        FindByLocate_SqList(&L,i);
        break;
    case 10:
        merge_SqList(&L,&M);
        PrintTable_SqList(&L);
        break;
    default:
        printf("输入错误，请重新选择。\n");
    }
    }while(!flag);

    return 0;
}


/*对表进行初始化*/
Status Init_SqList(SqList *L){

    L->Elem_array = (ELemType *)malloc(MAX_SIZE*sizeof(ELemType));
    if(!L->Elem_array)
        return ERROR;
    else{
        L->length=0;
        return OK;
    }

}

/*初始化插入数据*/
Status Insert_SqList(SqList *L, int i, ELemType e){
    int j;
    if(i<1||i>L->length+1)
        return ERROR;
    i--;  /*下标从0开始*/
    if(L->length>=MAX_SIZE){
        printf("线性表溢出!\n");
        return ERROR;
    }
    for(j=L->length;j>i;j--)
        L->Elem_array[j]=L->Elem_array[j-1];
    L->Elem_array[i]=e;
    L->length++;
    return OK;
}

/*删除指定值的元素*/
Status Delete_Date_SqList(SqList *L,ELemType e){
    int i,k;
    for(i = 0; i < L -> length-1; i++){
        if(L->Elem_array[i]==e){
            for(k = i+1;k<L->length;k++){
                L->Elem_array[k-1]=L->Elem_array[k];
            }
            L->length--;      /*从这里到break要放在循环外*/
            printf("删除成功！\n");
            break;
            return OK;
        }
    }
    return ERROR;
}

/*删除指定位置的元素*/
Status Delete_Locate_SqList(SqList *L,int x){
    int i,k;
    if(x<1||x>L->length){
        printf("该元素不在表中，请重新输入。\n");
        return ERROR;
    }
    x--;
    for(i = 0; i<L->length;i++){
        if(i==x){
                for(k = i+1;k<L->length;k++){
                L->Elem_array[k-1]=L->Elem_array[k];
                }
                L->length--;
                printf("删除成功\n");
                break;

        }
    }
    return OK;
}

/*选择排序*/
void Sort_SqList(SqList *L){
    int i,j;
    for(i = 0; i <= L->length;i++){
        for(j = i; j <= L ->length-1;j++){
            if(L->Elem_array[i]>L->Elem_array[j]){
                int temp;
                temp = L->Elem_array[i];
                L->Elem_array[i] = L->Elem_array[j];
                L->Elem_array[j] = temp;
            }
        }
    }

}

/*清空表*/
void Clear_SqList(SqList *L){
    int i,k;
    for(i = 0; i<L->length;i++){
        for(k = i+1;k<L->length;k++){
            L->Elem_array[k-1]=L->Elem_array[k];
            break;
        }
    }
    L->length = 0;
}

/*销毁表*/
void DestoryByTable(SqList *L){
    free(L);
    L->length = 0;
}

/*判断是否是空表*/
Status IfEmpty_SqList(SqList *L){
    if(L->length==0)
        return OK;
    else
        return ERROR;
}

/*求线性表的长度*/
int Length_SqList(SqList *L){
    int i = L->length;
    return i;
}

/*按值查找*/
void FindByDate_SqList(SqList *L, ELemType e){
    int i;
    int flag = 0;
    for(i = 0;i < L->length-1;i++){
        if(L->Elem_array[i]==e){
            flag=1;
            printf("该元素位于第%d个位置。\n", i);
        }
    }
    if(flag == 0){
        printf("该线性表中不存在该元素。\n");
    }
}

/*按位置查找*/
void FindByLocate_SqList(SqList *L,int i){
    ELemType e;
    if(i<0||i>L->length-1){
        printf("该数据不在线性表中。\n");
    }else{
        i--;
        e = L->Elem_array[i];
        printf("该位置元素为%d。\n",e);
    }

}

/*合并线性表*/
void merge_SqList(SqList *L, SqList *M){
    int i = 0;
    int j;
    int k;
    if(M->length==0){
        printf("该表为空，不用合并\n");
    }else{
        if(M->length+L->length>MAX_SIZE){
            L->Elem_array = (ELemType *)malloc((MAX_SIZE+M->length)*sizeof(ELemType));/*若空间不够，则重新分配空间*/
        }
        for(k = 0;k < M->length;k++){
        for(j=L->length+M->length;j>L->length-1;j--)
        L->Elem_array[j]=L->Elem_array[j-1];
        L->Elem_array[j]=M->Elem_array[k];
        i++;
        L->length++;
        }
    }
    int m,n;
    for(m = 0; m <= L->length;m++){
        for(n = m; n <= L ->length-1;n++){
            if(L->Elem_array[m]>L->Elem_array[n]){
                int temp;
                temp = L->Elem_array[m];
                L->Elem_array[m] = L->Elem_array[n];
                L->Elem_array[n] = temp;
            }
        }
    }

}

/*输出*/
void PrintTable_SqList(SqList *L){
    int i;
    for(i = 0;i<L->length; i++){
        printf("%4d",L->Elem_array[i]);
        if((i+1)%3==0)
            printf("\n");
    }
    printf("\n");
}
