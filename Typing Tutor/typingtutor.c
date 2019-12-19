#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void setcolor(int color) //function to change setcolor
{
	WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

                         //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

char name[30];
void test();
void practice();
void help();
void about();
void getscore(int speed,float accuracy);
void scorecard();

int main()
{
	int ch;

	time_t t;
	time(&t);

	system("cls");
	setcolor(15) ;//white
	printf("WELCOME TO TYPING TUTOR\n ");
	printf("%s",ctime(&t));

	printf("Enter your name::");
	gets(name);

	printf("\n..MAIN MENU..\n");
	printf("1. Practice\n");
	printf("2. Test\n");
	printf("3. Scorecard\n");
	printf("4. Help\n");
	printf("5. About Us\n");
	printf("6. Exit\n");

	printf("Enter your choice::");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:practice();break;
		case 2:test();break;
		case 3:scorecard();break;
		case 4:help();break;
		case 5:about();break;
		case 6:exit(1);
		default: printf("Sorry! Wrong input\nPlease choose a valid option\n");main();
	}
	return 0;
}
void practice()
{
	int i=1,ch,j,r,error,speed,len=0;
	float accuracy;
	clock_t begin,end;
	double cpu_time_used;
	char str2[100],str1[100];
	char lev1[100][100]={"A","B","C","D","a","b","c","d","E","F","G","H","e","f","g","h","I","J","L","K","i","j","k","l","M","N","O","P","m","n","o","p","Q","R","S","T","q","r","s","t","U","V","W","X","u","v","w","x","Y","Z","y","z"};
	char lev2[100][100]={"asdfg hjkl","asdfg hjkl","lkjh gfdsa asdfg hjkl","lkjh gfdsa","lkjh gfdsa","ah had lag slag ah had lag slag ah had ah had lag slag","hash flash ask has hash flash ask has hash hash flash ask hash","dash gash lash dash gash lash dash gash lash dash gash lash","lad sash flag lad sash flag lad sash flag lad sash flag lad sash","fall gall hall lass fall gall hall lass fall fall gall hall lass fall","glass alfalfa adds glass alfalfa adds glass alfalfa adds glass alfalfa","sad shall salad sad shall salad sad shall salad sad shall salad sad shall","sad shall salad sad shall salad sad shall salad sad shall salad sad shall","all flask half all flask half all flask half all flask half all flask half"};
	char lev3[100][100]={"qwert yuiop qwert yuiop","poiuy trewq poiuy trewq qwert yuiop qwert","till quail tight yell","will those feat lake hash till quail tight yell","will wire this flay queue","there rail sale gypsy is wire this flay queue","quash their light rash that usher wake yaw tide","the depth quest your these slit guide tale rage","take urge wages wake typist tale trash slide day","why fell its well peat two play rest jaw quail why","ogre rate quell paw yap use typed sure peep sill","quaff law stop lair gate here if do pit dug wary","fight tug quill day saw yippee go her with hit fight tug"};
    char lev4[100][100]={"zxcvb nm,./ zxcvb nm,./ /.,mn bvcxz /.","mn bvcxz zxcvb nm,./ zxcvb","by, zip wean trying","stump shrink rice ping/","mail by, zip wean trying","king fan crick, chill block.","back abbot. aflame/ mix king fan crick, chill","zest win, thump skunk. plain muffin, knight/ exit zest win, thump skunk.","daring. choke bishop. admit twine sultan, sing/ roman daring. choke","pink, nicest mate knit. groan flock, divide coop/ advice pink, nicest","vilest turbot, track snick scoot revoke. rein/ paving vilest turbot, track","Office. Meat. Lean. Hiking. Feline. Decay. Clash. Bright. Office. Meat.","Bump. Prank. Bate. Turnip. Bap. Aging. Aback. Wombat. Vine.","Vexing. Typing. Being. Sump. Faxing. Rink. Blot. Nice."};
    char lev6[400][400]={"Please take your dog, Cali, out for a walk,he really needs some exercise! Rex Quinfrey,a renowed scientist,created plans for an invisibility machine.","Hector quizzed Mr. Vexife for two hours,but he was unable to get any information. in order to keep up at that pace,Zack Squve would have to work all night","Anyone who feels thta if so many more students whom we haven't actually admitted are sitting in on the course than ones we have that the room had to be changed, then probably auditors will have to be excluded, is likely to agree that the curriculum needs revision","This exceeding trifling witling,considering ranting criticizing concerning adopting fitting wording being exhibiting transcending learning, was displaying notwithstanding ridiculing, surpassing boasting swelling reasoning, respecting correcting erring writing, and touching detecting deceiving arguiong during debating"};
    char lev5[500][500]={"I always make my homework as soon as I get home.","Who's bike was stolen from outside work yesterday?","Its about time we thought about buying a new laptop.","My parents asked me to look after there dog while they were on holiday.","When was the last times you went abroad?","Maybe we should'nt bother with the gardening right now.","She's not really interested of going for a drink with me.","Paul said me if he could borrow my lawnmover for the weekend.","You can ring your wet clothes out in the sink.","The advantages of her plan were plane to see."};

	printf("\nPress 1: Level 1");
	printf("\nPress 2: Level 2");
	printf("\nPress 3: Level 3");
	printf("\nPress 4: Level 4");
	printf("\nPress 5: Level 5");
	printf("\nPress 6: Level 6");

	setcolor(14);
	printf("\nEnter the level you want to practice\n");
	scanf("%d",&ch);

	while(i!=0)
	{
		srand(time(NULL));

		r=rand()%1000;
		fflush(stdin);
		r=r%10;
		switch(ch)
		{
			case 1:
				strcpy(str1,lev1[r]);
				break;
			case 2:
				strcpy(str1,lev2[r]);
				break;
			case 3:
				strcpy(str1,lev3[r]);
				break;
			case 4:
				strcpy(str1,lev4[r]);
				break;
			case 5:
				strcpy(str1,lev5[r]);
				break;
			case 6:
				strcpy(str1,lev6[r]);
				break;
			default: printf("Sorry wrong input");
			}
				
			printf("\nWelcome %s to level %d",name,ch);
		    printf("\n%s",str1);

			
			printf("\nStart typing....\n ");
				begin=clock();
			gets(str2);
			for(i=0;(str1[i]!='\0'||str2[i]!='\0');i++)
			{
				if(str1[i]!=str2[i])
				{
					error++;
				}
			}
			end=clock();
		
			setcolor(5);//purple
			
			cpu_time_used+=((double)(end-begin))/CLOCKS_PER_SEC;
			len+=strlen(str1);
			printf("Press any key to continue and 0 to exit \n");
			scanf("%d",&i);
	}
	setcolor(19);//light blue
	printf("\nTotal number of errors: %d",error);
	begin=0;
	printf("\nTotal time used %0.2f seconds",cpu_time_used);
	speed=(len*60)/cpu_time_used;
	accuracy=((len-error)*100.0)/len;
	printf("\nSpeed is %d wpm",speed);
	printf("\nAccuracy is %0.2f%",accuracy);
	
	getscore(speed,accuracy);
	
}

void help()
{
	system("cls");
	setcolor(15);
	printf("....INTRODUCTION TO TYPING TUTOR....\n");
	printf("There are altogether 6 levels in this tutor.\nFirst level helps you to learn to type uppercase and lowercase letters in English alphabet.\n");
	printf("Second level helps you to learn to type combination of letters and words in the home row.\n");
	printf("Third level helps you to learn to type combination of letters and words in the top row and home row.\n");
	printf("Fourth level helps you to learn to type combination of letters and words from all the three rows.\n");
	printf("Fifth level makes you practice typing single line sentences.\n");
	printf("Sixth level makes you practice typing paragraphs.\n");
	getch();
	main();
}
void about()
{
	system("cls");
	setcolor(15);
	printf("This typing tutor project is developed in C language by the following students of B.Tech CSE BAO,University of Petroleum and Energy Studies.\n");
	printf("Siddharta Mahanta\nVasavi Singh\nVashita  Agarwal\nPushpita Chattopadhyay");
	printf("\nThis project is done under the supervision of Mr.Kapil Tomar\n");
	getch();
	main();
    
}
void test()
{
	char arr1[100],arr2[100];
    char test1[300][300]={"qwert yuiop qwert yuiop","poiuy trewq poiuy trewq qwert yuiop qwert","till quail tight yell","will those feat lake hash till quail tight yell","will wire this flay queue","there rail sale gypsy is wire this flay queue","quash their light rash that usher wake yaw tide","the depth quest your these slit guide tale rage","take urge wages wake typist tale trash slide day","why fell its well peat two play rest jaw quail why","ogre rate quell paw yap use typed sure peep sill","quaff law stop lair gate here if do pit dug wary","fight tug quill day saw yippee go her with hit fight tug"};
    char test2[300][300]={"I always make my homework as soon as I get home.","Who's bike was stolen from outside work yesterday?","Its about time we thought about buying a new laptop.","My parents asked me to look after there dog while they were on holiday.","When was the last times you went abroad?","Maybe we should'nt bother with the gardening right now.","She's not really interested of going for a drink with me.","Paul said me if he could borrow my lawnmover for the weekend.","You can ring your wet clothes out in the sink.","The advantages of her plan were plane to see."};
	char test3[100][100]={"zxcvb nm,./ zxcvb nm,./ /.,mn bvcxz /.","mn bvcxz zxcvb nm,./ zxcvb","by, zip wean trying","stump shrink rice ping/","mail by, zip wean trying","king fan crick, chill block.","back abbot. aflame/ mix king fan crick, chill","zest win, thump skunk. plain muffin, knight/ exit zest win, thump skunk.","daring. choke bishop. admit twine sultan, sing/ roman daring. choke","pink, nicest mate knit. groan flock, divide coop/ advice pink, nicest","vilest turbot, track snick scoot revoke. rein/ paving vilest turbot, track","Office. Meat. Lean. Hiking. Feline. Decay. Clash. Bright. Office. Meat.","Bump. Prank. Bate. Turnip. Bap. Aging. Aback. Wombat. Vine.","Vexing. Typing. Being. Sump. Faxing. Rink. Blot. Nice."};
	int i=1,ch,j,r,error=0,speed,len=0;
	float accuracy1,accuracy2,speed1;
	float accuracy;
	clock_t begin,end;
	double cpu_time_used;
	
	setcolor(27);
	printf("TEST LEVEL 1\n");
	
	srand(time(NULL));
	r=rand()%1000;
	r=r%10;
	strcpy(arr1,test1[r]);
	
	label:
		srand(time(NULL));		
		r=rand()%1000;
		fflush(stdin);
		r=r%10;

		printf("\n%s",arr1);
		error=0,accuracy=0.0,len=0;		
		setcolor(16);
		printf("\nStart typing....\n ");
		
		setcolor(10);
		begin=clock();
		gets(arr2);
		for(i=0;(arr1[i]!='\0'||arr2[i]!='\0');i++)
		{
			if(arr1[i]!=arr2[i])
			{
				error++;
			}
		}
		end=clock();
		cpu_time_used+=((double)(end-begin))/CLOCKS_PER_SEC;
		len+=strlen(arr1);			
			
		printf("\nTotal number of errors: %d",error);
		begin=0;
		printf("\nTotal time used %0.2lf seconds",cpu_time_used);
		speed=(len*60)/cpu_time_used;
		accuracy=((len-error)*100.0)/len;
		printf("\nSpeed is %d",speed);
		printf("\nAccuracy is %0.2f %\n\n",accuracy);
		printf("------------------------------------------------------------------------------------------------------------\n");
	
	if(accuracy<75.0)
	{
		setcolor(27);
		printf("REPEAT LEVEL 1\n");
		goto label;
	}
	else if(accuracy>75.0)
	{
		setcolor(27);
		printf("CONRATULATIONS,YOU HAVE PASSED LEVEL 1\n\n");
		printf("---------------------------------------------------------------------------------------------\n");
		printf("ALL THE BEST FOR LEVEL 2 \n\n");
				
		srand(time(NULL));
		r=rand()%1000;
		r=r%10;
		strcpy(arr1,test2[r]);
		printf("\n%s",arr1);
		
		setcolor(16);
		printf("\nStart typing....\n ");
		
		setcolor(10);
		begin=clock();
		
		gets(arr2);
		error=0,accuracy1=0.0,len=0;
		for(i=0;(arr1[i]!='\0'||arr2[i]!='\0');i++)
		{
			if(arr1[i]!=arr2[i])
			{
				error++;
			}
		}
		end=clock();
		cpu_time_used+=((double)(end-begin))/CLOCKS_PER_SEC;
		len+=strlen(arr1);			
			
		printf("\nTotal number of errors: %d",error);
		begin=0;
		printf("\nTotal time used %0.2lf seconds",cpu_time_used);
		speed1=(len*60)/cpu_time_used;
		accuracy1=((len-error)*100.0)/len;
		printf("\nSpeed is %d",speed1);
		printf("\nAccuracy is %0.2f %\n\n",accuracy1);
		
		if(accuracy1>85)
		{
			setcolor(27);
			printf("YOU HAVE PASSED LEVEL 2\n");
			printf("-----------------------------------------------------------------------------------------------------\n");
			printf("ALL THE BEST FOR TEST LEVEL 3\n");		
					
			srand(time(NULL));
			r=rand()%1000;
			r=r%10;
			strcpy(arr1,test3[r]);
			printf("\n%s",arr1);
			
			setcolor(16);
			printf("\nStart typing....\n ");
			
			setcolor(10);
			begin=clock();
			
			gets(arr2);
			error=0,accuracy2=0.0,len=0;
			for(i=0;(arr1[i]!='\0'||arr2[i]!='\0');i++)
			{
				if(arr1[i]!=arr2[i])
				{
					error++;
				}
			}
			end=clock();
			cpu_time_used+=((double)(end-begin))/CLOCKS_PER_SEC;
			len+=strlen(arr1);			
				
			printf("\nTotal number of errors: %d",error);
			begin=0;
			printf("\nTotal time used %0.2lf seconds",cpu_time_used);
			speed1=(len*60)/cpu_time_used;
			accuracy2=((len-error)*100.0)/len;
			printf("\nSpeed is %d",speed1);
			printf("\nAccuracy is %0.2f %\n\n",accuracy2);
			
			if(accuracy2>95.0)
			{
				setcolor(23);
				printf("\nCONGRATULAIONS YOU HAVE SUCCESSFULLY COMPLETED ALL THE LEVELS!!\n");
				exit(1);
			}
			else
			{
				setcolor(27);
				printf("\nYOU HAVE FAILED LEVEL 3\n");
				printf("------------------------------------------------------------------------------------------------------\n");
				printf("START FROM LEVEL 1\n");
				strcpy(arr1,test1[r]);
				goto label;
			}
			
		}
		else
		{
			setcolor(27);
			printf("\nYOU HAVE FAILED LEVEL 2\n");
			printf("------------------------------------------------------------------------------------------------------\n");
			printf("START FROM LEVEL 1\n");
			strcpy(arr1,test1[r]);
			goto label;				
		}
	}	
}
void getscore(int speed,float accuracy)
{
	FILE *fp;
	fp=fopen("file.txt","a");

	if(fp==NULL)
	printf("Error in opening file");
	fprintf(fp,"\nName=%s\t\t\tSpeed=%d\t\t\tAccuracy %0.2f %\n",name,speed,accuracy);
	fclose(fp);

	printf("\nScorecard Updated ");
}
void scorecard()
{       
	int ch;
	FILE *fp;
	system("cls");
	
	printf("\t\t\t....The scores are...\n");

	fp=fopen("file.txt","r");
	
	while((ch=fgetc(fp))!=EOF)
	{	
		printf("%c",ch);
	}	
	
	getch();
	main();
}
