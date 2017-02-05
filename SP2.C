#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<string.h>
struct phon
{
	 char b[20];
	 char c[40];
	 char d[20];
}*start2=NULL,*tmp2,*cur2;
struct name
{
	char a[40];
	struct phon *right1;
	struct name *down1;
}*start1=NULL,*tmp1,*tmp11,*cur1;

typedef struct name nm;
typedef struct phon ph;
void process();
void save_data();
void add_();
void edit_();
void delete();
void empt();
void destroy();
void details_();
void search_();
void count1();

int i,p,n,email,fa,bs,pho,q,count=0,check=0,l1,l2,l3;
char s;
char str1[40], str2[40], str3[40];
FILE *fp1,*fp2,*fp3,*fp4;
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\bgi");
	cleardevice();
	setbkcolor(20);
	settextstyle(3,0,7);
	outtextxy(25,25,"DS PROJECT 2016");
	setcolor(4);
	settextstyle(3,0,5);
	outtextxy(150,100,"B.TECH - Sem III");
	setcolor(14);
	outtextxy(200,150,"PHONEBOOK");
	setcolor(1);
	settextstyle(8,0,4);
	outtextxy(25,250,"MADE BY:");
	setcolor(11);
	settextstyle(1,0,1);
	outtextxy(50,300,"1.VIBHAV GOEL-15103197");
	outtextxy(50,340,"2.RITIK JAIN-15103191");
	outtextxy(50,380,"3.HANU TYAGI-15103177");
	outtextxy(50,420,"4.PURU JAIN-15103190");
	setcolor(1);
	settextstyle(6,0,1);
	getch();
	fflush(stdin);
	//process();
stat1:  s='\0';
    while(p!=6)
    {
	cleardevice();
	setcolor(4);
	rectangle(0,0,639,479);
	setfillstyle(1,4);
	floodfill(100,100,4);
	setcolor(3);
	rectangle(20,20,619,459);
	setfillstyle(2,3);
	floodfill(10,10,3);
	setcolor(9);
	setbkcolor(4);
	settextstyle(1,0,2);
	outtextxy(160,40,"Actions that can be performed-");
	outtextxy(220,140,"1) Add a new contact.");
	outtextxy(220,160,"2) Edit a contact.");
	outtextxy(220,180,"3) Delete a contact.");
	outtextxy(220,200,"4) Search for a contact.");
	outtextxy(220,220,"5) Exit.");
//	outtextxy(220,240,"6) Exit");
	outtextxy(220,295,"Enter your choice ");
	gotoxy(54,20);
	scanf("%d",&p);
	//printf("%d",p);
	p++;
	switch(p)
	{
		case 2:
		add_();
		break;

		case 3:
		edit_();
		break;

		case 4:
		delete();
		break;

		case 5:
		search_();
		break;

		//case 5:
		//break;

		case 6:
		break;

		default:
		setcolor(1);
		outtextxy(240,400,"'Incorrect choice'");
		delay(3000);
		break;
	}
	}
	save_data();
fflush(stdin);
closegraph();
getch();
}


/*
void stack_count()
{
    printf("\n No. of elements in stack : %d", count);
}

*/
void add_()															//add=push
{

    cleardevice();
    setcolor(2);
    rectangle(1,1,638,478);
    setfillstyle(2,2);
    floodfill(100,100,2);
    setcolor(4);
    ellipse(320,240,0,360,200,100);
    setfillstyle(1,4);
    floodfill(300,240,4);
    setcolor(1);
    setbkcolor(4);
    outtextxy(240,200,"Enter the name ");
    tmp1 =(nm*)malloc(sizeof(nm));
    gotoxy(36,17);
    scanf("%s",tmp1->a);
    fflush(stdin);
    //gotoxy(40,25);
    //printf("%s",tmp1->a);
    //getch();
    if(start1==NULL)
    {
	tmp1->down1 = NULL;
	start1=tmp1;
	cur1=tmp1;
	details();														//calling the details function

    }
    else
    {
	tmp1->down1=start1;
	start1=tmp1;
	cur1=start1;
	details();
    }
    count++;
    save_data();													//counting the number of contacts
}
/////////////////////////////////////////////////////////////
 void details_()														//entering the details
 {
	 tmp2=(ph*)malloc(sizeof(ph));
	 strcpy(tmp2->b,"e");
	 strcpy(tmp2->c,"e");
	 strcpy(tmp2->d,"e");

stat2:	 cleardevice();
	 s='\0';
	 setcolor(2);
	 rectangle(0,0,639,479);
	 setfillstyle(6,2);
	 floodfill(1,1,2);
	 setcolor(1);
	 rectangle(30,30,609,449);
	 setfillstyle(1,1);
	 floodfill(320,240,1);
	 start1->right1=tmp2;
	 setcolor(6);
	 outtextxy(190,40,"Choices for details to enter");
	 outtextxy(220,140,"1) Enter phone no.");
	 outtextxy(220,170,"2) Enter email id.");
	 outtextxy(220,200,"3) Enter the fax no.");
	 outtextxy(220,280,"Enter your choice ");
	 gotoxy(53,19);
	 scanf("%d",&q);
	 cleardevice();
	 setcolor(1);
	 rectangle(0,0,639,479);
	 setfillstyle(7,1);
	 floodfill(1,1,1);
	 setcolor(2);
	 rectangle(40,40,599,439);
	 setfillstyle(1,2);
	 floodfill(320,240,2);
	 setcolor(8);
	 outtextxy(180,80,"Contact name - ");
	 gotoxy(50,6);
	 setcolor(7);
	 settextstyle(2,0,3);
	 printf("%s",cur1->a);
	 settextstyle(3,0,2);

	 switch(q)														//switch for entering details
	 {
		 case 1:
		 outtextxy(230,130,"Enter the phone no. ");
		 gotoxy(36,13);
		 scanf("%s",tmp2->b);
		 fflush(stdin);
		 //gotoxy(40,20);
		 //printf("%s",tmp2->b);
		 //getch();
		 setcolor(1);
		 outtextxy(220,320,"Press 'X' to go back and");
		 outtextxy(220,340,"enter other deatails");
		 outtextxy(220,360,"Press 'M' for main menu");
		 s=getch();
		 if(s=='m')
		 return ;
		 if(s=='x')
		 goto stat2;
		 break;

		 case 2:
		 outtextxy(230,130,"Enter the email id.");
		 gotoxy(36,13);
		 fflush(stdin);
		 scanf("%s",tmp2->c);
		 fflush(stdin);
		 setcolor(1);
		 outtextxy(220,320,"Press 'X' to go back and");
		 outtextxy(220,340,"enter other deatails");
		 outtextxy(220,360,"Press 'M' for main menu");
		 s=getch();
		 if(s=='m')
		 main();
		 if(s=='x')
		 goto stat2;
		 break;

		 case 3:
		 outtextxy(230,130,"Enter the fax no.");
		 gotoxy(36,13);
		 fflush(stdin);
		 scanf("%s",tmp2->d);
		 fflush(stdin);
		 setcolor(1);
		 outtextxy(220,320,"Press 'X' to go back and");
		 outtextxy(220,340,"enter other deatails");
		 outtextxy(220,360,"Press 'M' for main menu");
		 s=getch();
		 if(s=='m')
		 main();
		 if(s=='x')
		 goto stat2;
		 break;

		 default:
		 gotoxy(35,25);
		 setcolor(0);
		 outtextxy(280,400,"INVALID CHOICE");
		 delay(2000);
		 details_();
		 break;
	 }

 }
////////////////////////////////////////
 void edit_()
 {
	 check=0;
	 cleardevice();
	 setcolor(1);
	 rectangle(0,0,639,479);
	 setfillstyle(2,1);
	 floodfill(1,1,1);
	 setcolor(2);
	 rectangle(20,20,619,459);
	 setfillstyle(1,2);
	 floodfill(21,21,2);
	 setcolor(9);
	 settextstyle(1,0,3);
	 outtextxy(150,130,"Enter the name of the contact");
	 outtextxy(220,160, "you want to edit");
	 gotoxy(36,18);
	 scanf("%s",str1);
	 fp1=fopen("phone1.txt","r+w");
	 if(fp1==NULL)
	 {
	 check=-1;
	 }
	 if(check!=-1)
	 {
	 while(!feof(fp1))
	 {

		 fscanf(fp1,"%s",str2);
		 if(strcmpi(str1,str2)==0)
		 {
			 check=1;
		 }
	 }fclose(fp1);

		 if(check==1)
		 {
			 cleardevice();
			 setcolor(4);
			 rectangle(0,0,639,479);
			 setfillstyle(5,4);
			 floodfill(1,1,4);
			 setcolor(14);
			 ellipse(320,240,0,360,280,200);
			 setfillstyle(3,14);
			 floodfill(320,240,14);
			 setcolor(10);
			 rectangle(210,110,460,380);
			 setfillstyle(1,10);
			 floodfill(250,200,10);
			 setcolor(1);
			 settextstyle(1,0,2);
			 outtextxy(240,140,"What info you want");
			 outtextxy(300,165,"to edit?");
			 settextstyle(1,0,2);
			 outtextxy(280,220,"1) Name.");
			 outtextxy(280,240,"2) Phone no.");
			 outtextxy(280,260,"3) Email id.");
			 outtextxy(280,280,"4) Fax no.");
			 outtextxy(240,330,"Enter your choice ");
			 gotoxy(55,22);
			 scanf("%d",&s);
		 }

		if(s==1||s==2||s==3||s==4)
		 {
			cleardevice();
			setcolor(1);
			rectangle(0,0,639,479);
			setfillstyle(7,1);
			floodfill(1,1,1);
			setcolor(2);
			rectangle(40,40,599,439);
			setfillstyle(1,2);
			floodfill(320,240,2);
			settextstyle(3,0,2);
			setcolor(5);
		 }
		n=strlen(str1);
                n=40-n;
			 switch(s)
			 {
				 case 1:
				 outtextxy(210,130,"Enter the edited name ");
				 gotoxy(36,13);
				 scanf("%s",str3);
				 fp1=fopen("phone1.txt","r+");
				 while(!feof(fp1))
				 {
				 fscanf(fp1,"%s",str2);
				 l1=strlen(str2);
				 l2=strlen(str3);
				 l3=l1-l2;
				 if(strcmpi(str1,str2)==0)
				 {
					fseek(fp1,-l1,SEEK_CUR);
					fprintf(fp1,"%s",str3);
					if(l3>0)
					{
					for(i=1;i<=l3;i++)
					fprintf(fp1,"%s"," ");
					}
					break;
				 }
				 }	fclose(fp1);

				 fp2=fopen("phone2.txt","r+");
				 while(!feof(fp2))
				 {
				 fscanf(fp2,"%s",str2);
				 if(strcmpi(str1,str2)==0)
				 {
					fseek(fp2,-l1,SEEK_CUR);
					fprintf(fp2,"%s",str3);
					if(l3>0)
					{
					for(i=1;i<=l3;i++)
					fprintf(fp1,"%s"," ");
					}
                    break;
				 }
				 }	fclose(fp2);

				 fp3=fopen("phone3.txt","r+");
				 while(!feof(fp3))
				 {
				 fscanf(fp3,"%s",str2);
				 if(strcmpi(str1,str2)==0)
				 {
					fseek(fp3,-l1,SEEK_CUR);
					fprintf(fp3,"%s",str3);
					if(l3>0)
					{
					for(i=1;i<=l3;i++)
					fprintf(fp1,"%s"," ");
					}
					break;
				 }
				 }	fclose(fp3);

				 setcolor(1);
				 outtextxy(220,360,"Press 'M' for main menu");
				 s=getchar();
				 if(s=='m')
				 return ;
				 break;

				 case 2:
				 outtextxy(210,130,"Enter the edited phone no. ");
				 gotoxy(36,13);
				 scanf("%s",str3);
				 fp1=fopen("phone1.txt","r+");
				 while(!feof(fp1))
				 {
				 fscanf(fp1,"%s",str2);
				 l1=strlen(str3);
				 l2=strlen(str2);
				 l3=l2-l1;
				 if(strcmpi(str1,str2)==0)
				 {
					fseek(fp1,n,SEEK_CUR);
					fprintf(fp1,"%s",str3);
					pho=strlen(str3);
		    pho=20-pho;
                    for(i=0;i<pho;i++)
                    {
                        fprintf(fp1," ");
                    }
					break;
				 }
				 }fclose(fp1);
				 setcolor(1);
				 outtextxy(220,360,"Press 'M' for main menu");
				 s=getchar();
				 if(s=='m')
				 return ;
				 break;

				 case 3:
				 outtextxy(210,130,"Enter the edited email id");
				 gotoxy(36,13);
				 scanf("%s",str3);
				 fp2=fopen("phone2.txt","r+");
				 while(!feof(fp2))
				 {
				 fscanf(fp2,"%s",str2);
				 l1=strlen(str3);
				 l2=strlen(str2);
				 l3=l2-l1;
				 if(strcmpi(str1,str2)==0)
				 {
					fseek(fp2,n,SEEK_CUR);
					fprintf(fp2,"%s",str3);
					email=strlen(str3);
                    email=40-email;
                    for(i=0;i<email;i++)
                    {
                        fprintf(fp2," ");
                    }
					break;
				 }
				 }fclose(fp2);
				 setcolor(1);
				 outtextxy(220,360,"Press 'M' for main menu");
				 s=getchar();
				 if(s=='m')
				 return ;
				 break;

				 case 4:
				 outtextxy(210,130,"Enter the edited fax no.");
				 gotoxy(36,13);
				 scanf("%s",str3);
				 fp3=fopen("phone3.txt","r+");
				 while(!feof(fp3))
				 {
				 fscanf(fp3,"%s",str2);
				 l1=strlen(str3);
				 l2=strlen(str2);
				 l3=l2-l1;
				 if(strcmpi(str1,str2)==0)
				 {

					fseek(fp3,n,SEEK_CUR);

					fprintf(fp3,"%s",str3);
					fa=strlen(str3);
                    fa=20-fa;
		    for(i=0;i<fa;i++)
                    {
                        fprintf(fp3," ");
                    }
					break;
				 }
				 }fclose(fp3);
				 setcolor(1);
				 outtextxy(220,360,"Press 'M' for main menu");
				 s=getchar();
				 if(s=='m')
				 return ;
				 break;


				 default :
				 setcolor(15);
				 outtextxy(220,360,"'INCORRECT CHOICE'");
				 delay(2000);
				 return ;
				 break;
			 }
	  }

		if(check==-1)
		{
			 setcolor(0);
			 outtextxy(200,400,"'PHONEBOOK IS EMPTY'");
			 delay(2000);
			 return;
		}
		if(check==0)
		{
			 setcolor(0);
			 outtextxy(230,400,"'NO MATCH FOUND'");
			 delay(2000);
			 return;
		}

 }




void delete()
{
	 check=0;
	 cleardevice();
	 setcolor(1);
	 rectangle(0,0,639,479);
	 setfillstyle(2,1);
	 floodfill(1,1,1);
	 setcolor(2);
	 rectangle(20,20,619,459);
	 setfillstyle(1,2);
	 floodfill(21,21,2);
	 setcolor(9);
	 settextstyle(1,0,3);
	 outtextxy(150,130,"Enter the name of the contact");
	 outtextxy(210,160, "you want to delete");
	 gotoxy(36,18);
	 scanf("%s",str1);
	 strcpy(str3,str1);
	 fp1=fopen("phone1.txt","r+w");
	 if(fp1==NULL)
	 {
	 check=-1;
	 }
	 if(check!=-1)
	 {

	 while(!feof(fp1))
	 {
	    // printf("132");
		 fscanf(fp1,"%s",str2);
		 if(strcmpi(str1,str2)==0)
		 {
		     //printf("132");
			 check=1;
		 }


	 }fclose(fp1);

		 if(check==1)
		 {
            //printf("%d",check);
            //delay(1000);
			/*outtextxy(240,340,"Are you sure you want to");
			outtextxy(260,360,"delete the contact?");
			outtextxy(260,380," yES OR nO");
			s=getchar();
*/
			    //outtextxy(200,340,"A132654");
                //delay(10000);
			fp1=fopen("phone1.txt","r+w");
			strcpy(str1,str3);
			while(!feof(fp1))
			{

			fscanf(fp1,"%s",str2);
                //gotoxy(150,340);
                //printf("%s",str1);
                //delay(1000);
			if(strcmpi(str1,str2)==0)
			{
			    /*l1=strlen(str3);
			    l1=62-l1;
			    fseek(fp1,l1,SEEK_CUR);
			    //fprintf(fp1,"Ch");
			    tmp1 =(nm*)malloc(sizeof(nm));
			    start1=tmp1;
			    cur1=start1;
			    tmp2=(ph*)malloc(sizeof(ph));
			    start2=tmp2;
			    cur2=tmp2;

			    while(!feof(fp1))
                {
                    fscanf(fp1,"%s",str2);
                    strcpy(cur1->a,str2);
                    l2=strlen(str2);
                    fseek(fp1,-l2+41,SEEK_CUR);
                    fscanf(fp1,"%s",str2);
                    strcpy(cur2->b,str2);
                    tmp1 =(nm*)malloc(sizeof(nm));
                    cur1->down1=tmp1;
                    cur1->right1=cur2;
                    tmp2=(ph*)malloc(sizeof(ph));
                    cur2=tmp2;
		    cur1=tmp1;
                }*/


                //gotoxy(150,340);
                //printf("%s %s",str1,str2);
                //delay(1000);
				l1=strlen(str3);
				fseek(fp1,-l1,SEEK_CUR);
				for(i=1;i<=61;i++)
				fprintf(fp1," ");
				/*fscanf(fp1,"%s",str2);
				l2=strlen(str2);
				fseek(fp1,-l2,1);
				for(i=1;i<=l2;i++)
				fprintf(fp1,"%s"," ");*/
				break;

			}
			}
			/*fclose(fp1);
			fp1=fopen("phone1.txt","r+w");
			strcpy(str1,str3);
			while(!feof(fp1))
			{
			fscanf(fp1,"%s",str2);
			if(strcmpi(str1,str2)==0)
			{
			    l1=strlen(str3);
			    fseek(fp1,-l1,SEEK_CUR);

			    while(!feof(fp1))
                {
                    fprintf(fp1,"\b");
                }

				break;

			}
			}*/
			fclose(fp1);

			//in file 2
			fp2=fopen("phone2.txt","r+w");
			strcpy(str1,str3);
			while(!feof(fp2))
			{
			fscanf(fp2,"%s",str2);
			if(strcmpi(str1,str2)==0)
			{

			    /*l1=strlen(str3);
			    fseek(fp1,-l1+82,SEEK_CUR);
			    cur1=start1;
			    cur2=start2;

			    while(!feof(fp2))
                {
                    fscanf(fp2,"%s",str2);
		    strcpy(cur1->a,str2);
		    l2=strlen(str2);
                    fseek(fp2,-l2+41,SEEK_CUR);
                    fscanf(fp2,"%s",str2);
		    strcpy(cur2->c,str2);
		    tmp1 =(nm*)malloc(sizeof(nm));
		    cur1->down1=tmp1;
                    cur1->right1=cur2;
                    tmp2=(ph*)malloc(sizeof(ph));
                    cur2=tmp2;
                    cur1=tmp1;
                }*/




				l1=strlen(str3);
				fseek(fp2,-l1,SEEK_CUR);
				for(i=1;i<=81;i++)
				fprintf(fp2," ");

				break;

			}
			}
			/*strcpy(str1,str3);
			while(!feof(fp2))
			{
			fscanf(fp2,"%s",str2);
			if(strcmpi(str1,str2)==0)
			{
			    l1=strlen(str3);
			    fseek(fp2,-l1+82,SEEK_CUR);

			    while(!feof(fp2))
                {
                    fprintf(fp2,"\b");
                }

				break;

			}
			}*/
			fclose(fp2);

			//in file 3
			fp3=fopen("phone3.txt","r+w");
			while(!feof(fp3))
			{
			fscanf(fp3,"%s",str2);
			if(strcmpi(str1,str2)==0)
			{
			    /*l1=strlen(str3);
			    fseek(fp3,-l1+62,SEEK_CUR);
			    cur1=start1;
			    cur2=start2;

			    while(!feof(fp3))
		{
                    fscanf(fp1,"%s",str2);
		    strcpy(cur1->a,str2);
		    l2=strlen(str2);
                    fseek(fp3,-l2+41,SEEK_CUR);
                    fscanf(fp3,"%s",str2);
		    strcpy(cur2->d,str2);
                    tmp1 =(nm*)malloc(sizeof(nm));
                    cur1->down1=tmp1;
                    cur1->right1=cur2;
                    tmp2=(ph*)malloc(sizeof(ph));
                    cur2=tmp2;
                    cur1=tmp1;
		}*/




				l1=strlen(str3);
				fseek(fp3,-l1,SEEK_CUR);
				for(i=1;i<=61;i++)
				fprintf(fp3," ");

				break;
			}
			}
			/*strcpy(str1,str3);
			while(!feof(fp3))
			{
			fscanf(fp3,"%s",str2);
			if(strcmpi(str1,str2)==0)
			{
			    l1=strlen(str3);
			    fseek(fp3,-l1+62,SEEK_CUR);

			    while(!feof(fp3))
                {
                    fprintf(fp3,"\b");
                }

				break;

			}
			}*/
			fclose(fp3);
            //save_data();
			setcolor(1);
			outtextxy(220,360,"Press 'M' for main menu");
			s=getch();
			if(s=='m')
			return ;

	  }

		if(check==-1)
		{
			 setcolor(0);
			 outtextxy(200,400,"'PHONEBOOK IS EMPTY'");
			 delay(2000);
			 return;
		}
		if(check==0)
		{
			 setcolor(0);
			 outtextxy(230,400,"'NO MATCH FOUND'");
			 delay(2000);
			 return;
		}

 }
}

void search_()
{
	 check=0;
	 cleardevice();
	 setcolor(1);
	 rectangle(0,0,639,479);
	 setfillstyle(2,1);
	 floodfill(1,1,1);
	 setcolor(2);
	 rectangle(20,20,619,459);
	 setfillstyle(1,2);
	 floodfill(21,21,2);
	 setcolor(9);
	 setbkcolor(2);
	 settextstyle(1,0,3);
	 outtextxy(150,130,"Enter the name of the contact");
	 outtextxy(200,160, "you want to get info");
	 setbkcolor(2);
	 gotoxy(36,18);
	 scanf("%s",str1);
	 fp1=fopen("phone1.txt","r");
	 while(!feof(fp1))
	 {
		 fscanf(fp1,"%s",str2);
		 if(strcmpi(str1,str2)==0)
		 {
			 check=1;
			 cleardevice();
			 setcolor(4);
			 rectangle(0,0,639,479);
			 setfillstyle(9,4);
			 floodfill(1,1,4);
			 setcolor(1);
			 rectangle(50,50,589,429);
			 setfillstyle(1,1);
			 floodfill(100,100,1);
			 setbkcolor(1);
			 setcolor(14);
			 outtextxy(200,100,"Details of the contact");
			 settextstyle(1,0,2);
			 outtextxy(200,220,"1) Name      - ");
			 gotoxy(48,15);
			 printf("%s",str1);

			 outtextxy(200,250,"2) Phone no  - ");
			 gotoxy(48,17);
			 fscanf(fp1,"%s",str3);
			 if(strcmpi(str3,"e")==0)
			 printf("Empty\t");
			 else
			 printf("%s",str3);

			 outtextxy(200,280,"3) Email id   - ");
			 outtextxy(200,310,"4) Fax no     - ");
		 }
	 }
	 fclose(fp1);


	 if(check==1)
	 {
	 fp2=fopen("phone2.txt","r");
	 while(!feof(fp2))
	 {
		fscanf(fp2,"%s",str2);
		if(strcmpi(str1,str2)==0)
		{
			 gotoxy(48,19);
			 fscanf(fp2,"%s",str3);
			 if(strcmpi(str3,"e")==0)
			 printf("Empty\t");
			 else
			 printf("%s",str3);
		}
	 }
	 fclose(fp2);

	 fp3=fopen("phone3.txt","r");
	 while(!feof(fp3))
	 {
		fscanf(fp3,"%s",str2);
		if(strcmpi(str1,str2)==0)
		{
			 gotoxy(48,21);
			 fscanf(fp3,"%s",str3);
			 if(strcmpi(str3,"e")==0)
			 printf("Empty\t");
			 else
			 printf("%s",str3);
		}
	 }
	 fclose(fp3);
	 setcolor(2);
	 outtextxy(180,440,"Press any key for Main Menu");
	 getch();
	 return;
	 }

	 if(check==-1)
		{
			 setcolor(0);
			 outtextxy(200,400,"'PHONEBOOK IS EMPTY'");
			 delay(2000);
			 main();
		}
		if(check==0)
		{
			 setcolor(0);
			 outtextxy(230,400,"'NO MATCH FOUND'");
			 delay(2000);
			 main();
		}
}



void empt()
{
	fp1=fopen("phone1.txt","w");
		while(!feof(fp1))
	    {
		fprintf(fp1,"\b");
            }
        fclose(fp1);

        fp2=fopen("phone2.txt","w");
		while(!feof(fp2))
            {
                fprintf(fp2,"\b");
            }
        fclose(fp2);

        fp3=fopen("phone3.txt","w");
		while(!feof(fp3))
            {
                fprintf(fp3,"\b");
            }
        fclose(fp3);
}
/*

void destroy()
{
    cur = start;

    while (cur != NULL)
    {
	cur = start->ptr;
	free(start);
	start = cur;
	cur = cur->ptr;
    }
    free(cur);
    start = NULL;

    printf("\n All stack elements destroyed");
    count = 0;
}


}
*/

void save_data()
{
    nm *q1;
    ph *q2;
    int i;

    //now write file phone1
    fp1=fopen("phone1.txt","a+");
    q1=start1;
    q2=q1->right1;

    while(q1!=NULL)
    {
	n=strlen(q1->a);
	n=40-n;

    fprintf(fp1,"%s",q1->a);
    for(i=0;i<n;i++)
    {
	fprintf(fp1," ");
    }
    if(strlen(q2->b)!=0)
    fprintf(fp1,"%s",q2->b);
    pho=strlen(q2->b);
    pho=20-pho;
    for(i=0;i<pho;i++)
    {
	fprintf(fp1," ");
    }
    fprintf(fp1,"\n");
    q1=q1->down1;
    q2=q1->right1;
    }
    fclose(fp1);

    //now write file phone2
    fp2=fopen("phone2.txt","a+");
    q1=start1;
    q2=q1->right1;
    while(q1!=NULL)
    {
	fprintf(fp2,"%s",q1->a);
	n=strlen(q1->a);
	n=40-n;
    for(i=0;i<n;i++)
    {
	fprintf(fp2," ");
    }
	if(strlen(q2->b)!=0)
	fprintf(fp2,"%s",q2->c);
    email =strlen(q2->c);
    email=40-email;
    for(i=0;i<email;i++)
    {
        fprintf(fp2," ");
    }
    fprintf(fp2,"\n");
	q1=q1->down1;
	q2=q1->right1;
    }
    fclose(fp2);

    //now write file phone3

    fp3=fopen("phone3.txt","a+");
    q1=start1;
    q2=q1->right1;
    while(q1!=NULL)
    {
	fprintf(fp3,"%s",q1->a);
	n=strlen(q1->a);
	n=40-n;
    for(i=0;i<n;i++)
    {
        fprintf(fp3," ");
    }
    //fprintf(fp2,"\n");
	if(strlen(q2->d)!=0)
	fprintf(fp3,"%s",q2->d);
	fa=strlen(q2->d);
	fa=20-fa;
	for(i=0;i<fa;i++)
    {
	fprintf(fp3," ");
    }
    fprintf(fp3,"\n");
	q1=q1->down1;
	q2=q1->right1;
    }
    fclose(fp3);

    //assign null value to start
    start1=NULL;
}
