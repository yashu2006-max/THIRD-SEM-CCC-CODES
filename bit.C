#include <stdio.h>
#include <stdlib.h>

void printBinary(unsigned int x){
    for(int i=31;i>=0;i--){
        printf("%d",(x>>i)&1);
        if(i%8==0&&i!=0)printf(" ");
    }
    printf("\n");
}

int countSetBits(unsigned int x){
    int c=0;
    while(x){x&=(x-1);c++;}
    return c;
}
unsigned int setBit(unsigned int x,int k){return x|(1u<<k);}
unsigned int clearBit(unsigned int x,int k){return x&~(1u<<k);}
unsigned int toggleBit(unsigned int x,int k){return x^(1u<<k);}

void swapXor(unsigned int *a,unsigned int *b){
    if(a==b)return;
    *a^=*b;*b^=*a;*a^=*b;
}
unsigned int findUnique(unsigned int arr[],int n){
    unsigned int r=0;
    for(int i=0;i<n;i++)r^=arr[i];
    return r;
}

int main(){
    unsigned int val=0,a,b,x;
    int ch,k,n;
    unsigned int *arr;
    while(1){
        printf("\nValue: %u\nBinary: ",val);
        printBinary(val);
        printf("\n1.Set Value\n2.Even/Odd\n3.Set Bit\n4.Clear Bit\n5.Toggle Bit\n6.Count Set Bits\n7.XOR Swap\n8.Find Unique in Array\n9.Print Binary of Number\n0.Exit\nChoice: ");
        scanf("%d",&ch);
        if(ch==0)break;
        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%u",&val);
                break;
            case 2:
                printf(val&1?"Odd\n":"Even\n");
                break;
            case 3:
                printf("Bit pos (0-31): ");
                scanf("%d",&k);
                val=setBit(val,k);
                break;
            case 4:
                printf("Bit pos (0-31): ");
                scanf("%d",&k);
                val=clearBit(val,k);
                break;
            case 5:
                printf("Bit pos (0-31): ");
                scanf("%d",&k);
                val=toggleBit(val,k);
                break;
            case 6:
                printf("Set bits = %d\n",countSetBits(val));
                break;
            case 7:
                printf("Enter a b: ");
                scanf("%u %u",&a,&b);
                swapXor(&a,&b);
                printf("After swap: %u %u\n",a,b);
                break;
            case 8:
                printf("Enter n: ");
                scanf("%d",&n);
                arr=(unsigned int*)malloc(n*sizeof(unsigned int));
                for(int i=0;i<n;i++)scanf("%u",&arr[i]);
                printf("Unique = %u\n",findUnique(arr,n));
                free(arr);
                break;
            case 9:
                printf("Enter number: ");
                scanf("%u",&x);
                printBinary(x);
                break;
            default:
                printf("Invalid\n");
        }
    }
    return 0;
}