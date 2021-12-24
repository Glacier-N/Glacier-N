#include<stdio.h>
#include<string.h>

typedef struct{
    char id[30];
    char name[30];
    int year,month,day;
    int chinese,math,english;
    int sum;
}STU;
STU a[1000],t; 
int n;
int inputn;
void start(){
	printf("  ___________________________________\n");
	printf(" |Student Information Inquiry  System|\n");
	printf(" |-----------------------------------|\n");
	printf(" |                                   |\n");
	printf(" |     Choose the Items you need     |\n");
	printf(" |                                   |\n");
	printf(" |  1.Input    2.Output    3.Sort    |\n");
	printf(" |  4.Search   5.Insert    6.Delete  |\n");
	printf(" |  7.Change                         |\n");
	printf(" |                         0.Exit    |\n");
	printf(" |                                   |\n");
	printf(" |___________________________________|\n");
}

void input(){
    printf("\nNumber of Students:");
    scanf("%d",&inputn);
    int inputi;
    for(inputi=0;inputi<inputn;inputi++){
    printf("Please enter Details %d/%d\n",inputi+1,inputn); 
    printf("Student ID:");
    scanf("%s",&a[inputi].id);
    printf("Name:");
    scanf("%s",&a[inputi].name);
    printf("Date of Birth:");
    scanf("%d%d%d",&a[inputi].year,&a[inputi].month,&a[inputi].day);
    printf("Chinese Grade:");
    scanf("%d",&a[inputi].chinese);
	printf("Math Grade:");
	scanf("%d",&a[inputi].math);
	printf("English Grade:");
	scanf("%d",&a[inputi].english);
	a[inputi].sum=a[inputi].chinese+a[inputi].math+a[inputi].english;
	printf("\n");
    }
    return;
}
void output(){
	int outputi;
	for(outputi=0;outputi<inputn;outputi++){
		printf("\nStudent %d/%d:\n",outputi+1,inputn);
		printf("  ID:%s  Name:%s  Date of Birth:%04d-%02d-%02d",a[outputi].id,a[outputi].name,a[outputi].year,a[outputi].month,a[outputi].day);
		printf("  Score: Chinese:%d / Math:%d / English:%d / Total:%d\n",a[outputi].chinese,a[outputi].math,a[outputi].english,a[outputi].sum);
	}
}
void caidan(){
	printf("\nHaha.\n");
}
void search(){
    printf("Please enter:\n");
    getchar();
    char uid[30];
    gets(uid);
    int si;
    for(si=0;si<inputn;si++){
    if(strcmp(uid,a[si].id)==0){
        printf("  ID:%s  Name:%s  Date of Birth:%04d-%02d-%02d",a[si].id,a[si].name,a[si].year,a[si].month,a[si].day);
		printf("  Score: Chinese:%d / Math:%d / English:%d\n",a[si].chinese,a[si].math,a[si].english);
        return;
    }
    }
    printf("\nSorry,Can't Find the Object\n");
    return ;
}
void change(){
    printf("Please enter Target ID:\n");
    char c[30];
    scanf("%s",c);
    int i;
    for(i=0;i<inputn;i++){
        if(strcmp(c,a[i].id)==0){
            
                printf("Please Choose Information Type\n");
				printf("1.ID    2.Name\n3.Date of Borth    4.Score\n0.Exit\n");
                int t;
                char cc[30];
                printf("Please enter:\n");
                scanf("%d",&t);
                switch(t){
                	case 9:
                		caidan();return;
                	case 0:return;
                    case 1:
                    	printf("Enter a new ID:\n");
                        scanf("%s",cc);
                        strcpy(a[i].id,cc);
                        break;
                    case 2:
                    	printf("Enter a new Name:\n");
                        scanf("%s",cc);
                        strcpy(a[i].name,cc);
                        break;
                    case 3:
                        printf("Year,Month,or Day?\n");
                        printf("1.Year   2.Month   3.Day\n");
                        int iii;
                        int aaa;
                        scanf("%d",&iii);
                        switch(i){
                            case 1:
                                printf("Please enter Year:\n");
                                scanf("%d",&aaa);
                                a[i].year=aaa;
                                break;
                            case 2:
                                printf("Please enter Month:\n");
                                scanf("%d",&aaa);
                                a[i].month=aaa;
                                break;
                            case 3:
                                printf("Please enter Day:\n");
                                scanf("%d",&aaa);
                                a[i].day=aaa;
                                break;
                        }
                    case 4:
                        printf("Chinese,Math,or English\n");
                        printf("1.Chinese   2.Math   3.English\n");
                        int iiii;
                        int aaaa;
                        scanf("%d",&iiii);
                        switch(iiii){
                            case 1:
                                printf("Please enter Chinese score:\n");
                                scanf("%d",&aaaa);
                                a[i].chinese=aaaa;
                                break;
                            case 2:
                                printf("Please enter Math score:\n");
                                scanf("%d",&aaaa);
                                a[i].math=aaaa;
                                break;
                            case 3:
                                printf("Please enter English score:\n");
                                scanf("%d",&aaaa);
                                a[i].english=aaaa;
                                break;
                        }
                
            }
            return ;
        }
    }
    printf("Not Found.\n");
}
void sort(){
    STU t;
    int sorti=0;
    for(sorti=0;sorti<inputn;sorti++){
        int sortj=0;
        for(sortj=sorti;sortj<inputn;sortj++){
            if(a[sortj].sum>a[sorti].sum){
                t=*(a+sortj);
                *(a+sortj)=*(a+sorti);
                *(a+sorti)=t;
            }
        }
    }
    return ;
}
void insert(){
    printf("Please enter Details\n"); 
    printf("Student ID:");
    scanf("%s",&a[inputn].id);
    printf("Name:");
    scanf("%s",&a[inputn].name);
    printf("Date of Birth:");
    scanf("%d%d%d",&a[inputn].year,&a[inputn].month,&a[inputn].day);
    printf("Chinese Grade:");
    scanf("%d",&a[inputn].chinese);
	printf("Math Grade:");
	scanf("%d",&a[inputn].math);
	printf("English Grade:");
	scanf("%d",&a[inputn].english);
	a[inputn].sum=a[inputn].chinese+a[inputn].math+a[inputn].english;
	inputn++;
	return ;
}
void delete_(){
	printf("Please enter Target ID\n");
	char did[30];
	scanf("%s",did);
	int di=0,aaa=0;
	for(di;di<inputn;di++){
		if(strcmp(a[di].id,did)==0){
		aaa=1;
		break;
	}
	}
	if(!aaa)
	{
		printf("Not Found.\n");
		return ;
	}
	for(di;di<inputn-1;di++){
		a[di]=a[di+1];
	}
	inputn--;
	return ;
}
int main(){
	while(1){
	system("cls");
	start();
	scanf("%d",&n);
	if(n==0)
	return 0;
	switch(n){
		case 1:system("cls");input();break;
	 	case 2:system("cls");output();break;
		case 3:system("cls");sort();break;
		case 4:system("cls");search();break;
		case 5:system("cls");insert();break;
		case 6:system("cls");delete_();break;
		case 7:system("cls");change();break;
	}
	printf("\n*****All Done.*****\n\n");
	system("pause");
	}	
}
