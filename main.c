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

Status Init_SqList(SqList *L);                       /*��ʼ������*/
Status Insert_SqList(SqList *L, int i, ELemType e);  /*��������*/
Status Delete_Locate_SqList(SqList *L,int x);        /*ɾ��ָ��λ�õ�Ԫ��*/
Status Delete_Date_SqList(SqList *L,int x);          /*ɾ��ָ��ֵ��Ԫ��*/
void Sort_SqList(SqList *L);                         /*ѡ������*/
void Clear_SqList(SqList *L);                        /*��ձ�*/
void DestoryByTable(SqList *L);                      /*���ٱ�*/
Status IfEmpty_SqList(SqList *L);                    /*�ж��Ƿ��ǿձ�*/
void PrintTable_SqList(SqList *L);                   /*���*/
int Length_SqList(SqList *L);                        /*�������L�ĳ���*/
void FindByDate_SqList(SqList *L, ELemType e);       /*��ֵ�������Ա��е�Ԫ��*/
void FindByLocate_SqList(SqList *L,int i);           /*��λ�ò������Ա��е�Ԫ��*/
void merge_SqList(SqList *L, SqList *M);             /*�ϲ����Ա�*/


/*������*/
int main()  /*�������Ӧ�÷��ڷ�������ǰ��*/
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

    printf("�����ʼ�����\n");

    PrintTable_SqList(&L);
    PrintTable_SqList(&M);

    do{
    printf("\n");
    printf("*****************\n");
    printf("���ܣ�\n");
    printf("1,�˳�\n");
    printf("2,��ձ�\n");
    printf("3,���ٱ�\n");
    printf("4,����\n");
    printf("5,ɾ������ָ��λ�õ�Ԫ��\n");
    printf("6,ɾ��ָ��ֵ��Ԫ��\n");
    printf("7,����Ԫ��\n");
    printf("8,��ֵ���ұ��е�Ԫ��\n");
    printf("9,��λ�ò��ұ��е�Ԫ��\n");
    printf("10,�ϲ����Ա�\n");
    printf("��ѡ��һ��ܣ�");
    scanf("%d",&op);  /*scanf�ġ����ﲻ�ܼ�\n������ᱨ��*/


    switch(op){
    case 1:
        flag = 1;
        break;
    case 2:
        Clear_SqList(&L);
        PrintTable_SqList(&L);
        printf("��ճɹ�!\n");
        break;
    case 3:
        DestoryByTable(&L);
        PrintTable_SqList(&L);
        printf("���ٳɹ���\n");
        break;
    case 4:
        Sort_SqList(&L);
        PrintTable_SqList(&L);
        break;
    case 5:
        printf("������Ҫɾ����Ԫ�ص�λ��:");
        scanf("%d",&i);
        Delete_Locate_SqList(&L, i);
        PrintTable_SqList(&L);
        break;
    case 6:
        printf("������Ҫɾ����Ԫ�ص�ֵ:");
        scanf("%d",&e);
        Delete_Date_SqList(&L, e);
        PrintTable_SqList(&L);
        break;
    case 7:
        printf("������Ҫ���������λ��:");
        scanf("%d",&i);
        printf("������Ҫ�������");
        scanf("%d",&e);
        Insert_SqList(&L,i,e);
        PrintTable_SqList(&L);
        break;
    case 8:
        printf("������Ҫ���ҵ�Ԫ�ص�ֵ��");
        scanf("%d",&e);
        FindByDate_SqList(&L,e);
        break;
    case 9:
        printf("������Ҫ����Ԫ�ص�λ�ã�");
        scanf("%d", &i);
        FindByLocate_SqList(&L,i);
        break;
    case 10:
        merge_SqList(&L,&M);
        PrintTable_SqList(&L);
        break;
    default:
        printf("�������������ѡ��\n");
    }
    }while(!flag);

    return 0;
}


/*�Ա���г�ʼ��*/
Status Init_SqList(SqList *L){

    L->Elem_array = (ELemType *)malloc(MAX_SIZE*sizeof(ELemType));
    if(!L->Elem_array)
        return ERROR;
    else{
        L->length=0;
        return OK;
    }

}

/*��ʼ����������*/
Status Insert_SqList(SqList *L, int i, ELemType e){
    int j;
    if(i<1||i>L->length+1)
        return ERROR;
    i--;  /*�±��0��ʼ*/
    if(L->length>=MAX_SIZE){
        printf("���Ա����!\n");
        return ERROR;
    }
    for(j=L->length;j>i;j--)
        L->Elem_array[j]=L->Elem_array[j-1];
    L->Elem_array[i]=e;
    L->length++;
    return OK;
}

/*ɾ��ָ��ֵ��Ԫ��*/
Status Delete_Date_SqList(SqList *L,ELemType e){
    int i,k;
    for(i = 0; i < L -> length-1; i++){
        if(L->Elem_array[i]==e){
            for(k = i+1;k<L->length;k++){
                L->Elem_array[k-1]=L->Elem_array[k];
            }
            L->length--;      /*�����ﵽbreakҪ����ѭ����*/
            printf("ɾ���ɹ���\n");
            break;
            return OK;
        }
    }
    return ERROR;
}

/*ɾ��ָ��λ�õ�Ԫ��*/
Status Delete_Locate_SqList(SqList *L,int x){
    int i,k;
    if(x<1||x>L->length){
        printf("��Ԫ�ز��ڱ��У����������롣\n");
        return ERROR;
    }
    x--;
    for(i = 0; i<L->length;i++){
        if(i==x){
                for(k = i+1;k<L->length;k++){
                L->Elem_array[k-1]=L->Elem_array[k];
                }
                L->length--;
                printf("ɾ���ɹ�\n");
                break;

        }
    }
    return OK;
}

/*ѡ������*/
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

/*��ձ�*/
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

/*���ٱ�*/
void DestoryByTable(SqList *L){
    free(L);
    L->length = 0;
}

/*�ж��Ƿ��ǿձ�*/
Status IfEmpty_SqList(SqList *L){
    if(L->length==0)
        return OK;
    else
        return ERROR;
}

/*�����Ա�ĳ���*/
int Length_SqList(SqList *L){
    int i = L->length;
    return i;
}

/*��ֵ����*/
void FindByDate_SqList(SqList *L, ELemType e){
    int i;
    int flag = 0;
    for(i = 0;i < L->length-1;i++){
        if(L->Elem_array[i]==e){
            flag=1;
            printf("��Ԫ��λ�ڵ�%d��λ�á�\n", i);
        }
    }
    if(flag == 0){
        printf("�����Ա��в����ڸ�Ԫ�ء�\n");
    }
}

/*��λ�ò���*/
void FindByLocate_SqList(SqList *L,int i){
    ELemType e;
    if(i<0||i>L->length-1){
        printf("�����ݲ������Ա��С�\n");
    }else{
        i--;
        e = L->Elem_array[i];
        printf("��λ��Ԫ��Ϊ%d��\n",e);
    }

}

/*�ϲ����Ա�*/
void merge_SqList(SqList *L, SqList *M){
    int i = 0;
    int j;
    int k;
    if(M->length==0){
        printf("�ñ�Ϊ�գ����úϲ�\n");
    }else{
        if(M->length+L->length>MAX_SIZE){
            L->Elem_array = (ELemType *)malloc((MAX_SIZE+M->length)*sizeof(ELemType));/*���ռ䲻���������·���ռ�*/
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

/*���*/
void PrintTable_SqList(SqList *L){
    int i;
    for(i = 0;i<L->length; i++){
        printf("%4d",L->Elem_array[i]);
        if((i+1)%3==0)
            printf("\n");
    }
    printf("\n");
}
