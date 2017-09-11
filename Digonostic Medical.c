//list of header files
#include <windows.h>
#include<stdio.h>                   //contains printf,scanf etc
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<conio.h>
#include<ctype.h>
void gotoxy (int, int);
void mainmenu(void);
void Password(int);
void addpatient();

void addmedical(void);
////////////////////// add medical ////////////////////////////
    void bloodtestp();
    void pathologyp(void);
        //add pathology//
        void urinetest();
        void stooltest();
        void pregnencitest();
        //add pathology//
    void endoskopy();
    void ultrasonogramp();
    void xrayp();
    void vaccinationp();
    void doctorcheckup();
/////////////////////__add medical__///////////////////////////

void viewpatients();

void returnToMainMenu();
void returnToViewMedicalTest();

void viewmedical();
/////////////////////// View Medical ////////////////////
    void viewbloodtest();
    void viewpathology();
        //add pathology//
        void viewurinetest();
        void viewstooltest();
        void viewpregnencitest();
        //add pathology//
    void viewendoskopy();
    void viewultrasonogram();
    void viewxray();
    void viewvaccination();
    void viewdoctorcheckup();
//////////////////_______________////////////////////////


void deletepatient();
void searchpatient();

void searchmedical(void);
////////////////////// Search Medical ////////////////////////////
    void searchbloodtest();
    void searchpathology(void);
        //Search pathology//
        void searchurinetest();
        void searchstooltest();
        void pregnencitest();
        //search pathology//
    void searchendoskopy();
    void searchultrasonogram();
    void searchxray();
    void searchvaccination();
/////////////////////___ Search Medical ___//////////////////////

void editpatient();

void editmedical(void);
////////////////// Edit Medical Test ///////////////////
    void editbloodtest();
    void editpathology(void);
        //add pathology//
        void editurinetest();
        void editstooltest();
        //void editpregnencitest();
        //add pathology//
    void editendoskopy();
    void editultrasonogram();
    void editxray();
    void editvaccination();
    void editdoctorcheckup();
///////////////_____ Edit Medical Test _______////////////


int getdata();           /* Patint*/
int chekid (int);       /*patient*/

int mgetdata ();       /*medical*/
int mchekid (int);     /*medical*/

char password[10]={"project"};
COORD coord = {0, 0};
char pname[][20]={"Patient-Name"};
char mcatagories[][20]={"Blood test","Pathology","Endoscopy","Ultrasonogram","Echo-Cardiogram","X-Ray","Hormone Test","Urin RIE","Stool RIE","Madical Checkup"};
char btcatagories[][30]={"Add_Blood_Test"};

////pathology////
char urcatagories[][30]={"Add_Urin_test"}; //[][30]; // [][30]={"Volume","Reaction","Alubumin","Sugar","Blood","Calcium-Oxalet","Uric-Acid","Epithelial-Cell",};
char stcatagories[][30]={"Add_Stool_Test"}; //[][30];

//////////ENDOSCOPY/////////////
char eccatagories[][30]={"Add_Endoscopy"};

//////// ultrasonogra //////////
char ulcatagories[][30]={"Add_Ultrasonogram"};

/////// X ray /////////////////
char xrcatagories[][30]={"Add_Xray"};

/////// vaccination ///////////
char vccatagories[][30]={"Add_Vaccination"};


struct patients
{
    int id;
    //char stname[20];
    char f_name[35];
    char m_name[35];
    char l_name[35];
    char medical[50];
    float age;
    char sex[10];
    //int rackno;
    char *pat;
};
struct patients patient;
FILE *fp, *ft;
int s;
int m;  // addmedical//

// struct medical......
struct bloodtests
{
    int id;
    float sugerf;
    float sugerr;
    float blooduria;
    float totalprotin;
    char group[10];
    float cholestrol;
    char hbsag[10];
    float bilirubin;
    char *bdt;
};
struct bloodtests bloodtest;
FILE *fb, *fd;   ////FILE *fm
int bt;

/////////////////////Pathology////////////////

struct urins
{
    int id;
    float volume;
    char reaction[20];
    char alubumin[20];
    char sugar[20];
    char blad[20];
    char calsiamoxalet[20];
    char uricasid[20];
    char epithelialcell[20];
    char *urn;
};
struct urins urin;
FILE *fu, *fr;   ////FILE *fm
int ur;

struct stools
{
    int id;
    float volume;
    char reaction[20];
    char alubumin[20];
    char sugar[20];
    char blad[20];
    char calsiamoxalet[20];
    char uricasid[20];
    char epithelialcell[20];
    char *stl;
};
struct stools stool;
FILE *fs, *fso;   ////FILE *fm
int sso;
/////////////Pathology///////////////////////////////////

//////////////// Endoscopy //////////////////////////////
struct endoss
{
    int id;
    char  oesop[30];
    char stomac[30];
    char funds[30];
    char antrum[30];
    char duodenium[30];
    char dbulb[30];
    char biopsy[30];
    char comment[30];
    char *ends;
};
struct endoss endos;
FILE *fe, *fo;   ////FILE *fm
int eo;
////////////////// Endoscopy //////////////////////

///////////////// ultrasonogram //////////////////
struct ultrasonograms
{
    int id;
    char  liver[30];
    char kidney[30];
    char prostet[30];
    char spleen[30];
    char *ultra;
};
struct ultrasonograms ultrasonogram;
FILE *ful, fgm;
int ulgm;
///////////////////////////////////////////////

///////////////// x-RAY ///////////////////////
struct xrays
{
    int id;
    char  skull[30];
    char hand[20];
    char *xra;
};
struct xrays xray;
FILE *fx, fry;
int xry;
//////////////////////////////////////////////

///////////////// Vaccination///////////////
struct vaccinations
{
    int id;
    char  vaccin[30];
    char comment[20];
    char *vacin;
};
struct vaccinations vacination;
FILE *fv, fvc;
int vvc;
///////////////////////////////////////////////


int main()
{
    Password(1);
    return 0;
}
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Password(int isFirstTime)
{

   system("cls");
   system("COLOR B1");
   if(isFirstTime == 0)
   {
     gotoxy(15,30);
	 printf("Incorrect Password !!!!!!!!. Input the password again !!!!!!!!!!");
   }

   char d[30]="  LIFE DIAGNOSTIC CENTRE LTD.";

   char ch,pass[10];
   int i=0,j;
    gotoxy(10,3);
    for(j=0;j<16;j++)
    {
        printf("\xDB");
    }
    for(j=0;j<30;j++)
    {
        printf("%c",d[j]);
    }
   for(j=0;j<16;j++)
   {
        printf("\xB2");
   }
   gotoxy(15,3.5);
   printf("\n\n                                      C-Project \n");
   gotoxy(15,5);
   printf("\n\n                                      Software Of \n");
   gotoxy(5,8);
   printf("\n\n                       Diagnostic's Medical Test Information System\n ");
   gotoxy(15,10);
   printf("\n\n                                          By \n");
   gotoxy(5,13);
   printf("\n\n                               S. Rayhan Kabir (133-35-561)");
   gotoxy(15,17);
   printf("\n\n                               Jewel Rana (ID: 133-35-558)\n");
   gotoxy(15,19);
   printf("\n\n                                      12th Batch\n");
   gotoxy(15,21);
   printf("\n\n                       Department of B.Sc. in Software Engineering\n");
   gotoxy(15,24);
   printf("\n\n                          Daffodil International University(DIU)\n");
   gotoxy(15,34);
   printf("Enter Password For Go To Main Menu:");


   while(ch!=13)
   {
	ch=getch();

	if(ch!=13 && ch!=8){
	putch('#');
	pass[i] = ch;
	i++;
	}
   }
   pass[i] = '\0';
   if(strcmp(pass,password)==0)
   {

	gotoxy(15,38);
	printf("Password match");
	gotoxy(17,41);
	printf("Press any key to go to the main menu.");
	if(getch())
    {
     mainmenu();
    }
   }
   else
   {
	 Password(0);
   }
}
///////////////////////////////// Main Menu //////////////////////////////////////////////////////////////
void mainmenu()
{

    char c;
   system("cls");
   gotoxy(20, 4);
   printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
   gotoxy(20, 6);
   printf("***************** MAIN MANUE ********************");
   gotoxy(28,8);
   printf(" 1. Add Patient ");
   gotoxy(28,10);
   printf(" 2. Add Medical-Test ");
   gotoxy(28,12);
   printf(" 3. View Patients ");
   gotoxy(28,14);
   printf(" 4. View Medical-Test ");
   gotoxy(28,16);
   printf(" 5. Search Patient ");
   gotoxy(28,18);
   printf(" 6. Search Medical-Test ");
   gotoxy(28,20);
   printf(" 7. Edit Patient ");
   gotoxy(28,22);
   printf(" 8. Edit Medical-Test ");
   gotoxy(28,24);
   printf(" 9. Delete Option ");
   gotoxy(28,26);
   printf(" Enter 0 (Zero) for Exist ");
   gotoxy(20, 27);
   printf("******************************************************");

   InputOption:
   gotoxy(28,28);
   printf(" Enter Your Choise: ");
   c = getchar();
   switch(c)
   {
       case '1':
       addpatient();
       break;
       case '2':
       addmedical();
       break;
       case '3':
       viewpatients();
       break;
       case '4':
       viewmedical();
       break;
       case'5':
       searchpatient();
       break;
       case '6':
       searchmedical();
       break;
       case '7':
       editpatient();
       break;
       case '8':
       editmedical();
       break;
       case '9':
       deletepatient();
       break;
       case'0':
            system("cls");
            exit(0);
        default:
        {
            gotoxy(20, 31);
            printf("Please Re-Enter Which You can See In This  Option");
            goto InputOption;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////// Add Patient //////////////////////////////////////////////////////////////
void addpatient()
  {
      //system("cls");
     //printf("This is Add Medical Test");


      system("cls");
      int i;
      gotoxy(20, 4);
      printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
      gotoxy(20,7);
      printf("****************** Add Patient *****************");
      gotoxy(25,10);
      printf("1. Add Patient");
      gotoxy(25,14);
      printf("2. Back to Main Menu ");
      gotoxy(20,21);
	  printf("************************************************");
      gotoxy(25,18);
      printf("Enter Your Choice:");
	  scanf("%d",&s);
	  if(s==2)
      mainmenu();
	  fp=fopen("parves.dat","ab+");        ////////////// //  fp open //////////////////
      if(getdata()==1)
	{
	    patient.pat=pname[s-1];
	    fseek (fp,0,SEEK_END);
	    fwrite(&patient,sizeof(patient),1,fp);
	    fclose(fp);
	    gotoxy(19,20);
	    printf("The record is sucessfully saved");
	    gotoxy(19,22);
	    printf("Save any more?(Y/N):");
	    if(getch()=='n')
	    mainmenu();
	    else
	    system("cls");
	    addpatient();

	}
}
int getdata()
{
    system("cls");
    int t;
    gotoxy(20,3);
    printf("Enter The Patient Information Below:");
    gotoxy(15,5);
    printf("****************************************");
    gotoxy(15,25);
    printf("****************************************");
    gotoxy(28,6);
    printf("Add Patient");
    gotoxy(35,6);
    printf("%s",pname[s-1]);
    gotoxy(19,8);
    printf("PatientID:   \t");
    InputData:
    gotoxy(31,8);
    scanf("%d",&t);
    if(checkid(t)==0)
    {
        gotoxy(15,24);
        printf("\aThe Patient id already exists. Input again...\a");
        goto InputData;
        return 0;

    }
    patient.id=t;
    gotoxy(19,9);
    printf("First Name:");
    gotoxy(33,9);
    scanf("%s",patient.f_name);
    gotoxy(19,10);
    printf("Middle Name:");
    gotoxy(33,10);
    scanf("%s",patient.m_name);
    gotoxy(19,11);
    printf("Last Name:");
    gotoxy(33,11);
    scanf("%s",patient.l_name);
    gotoxy(19,12);
    printf("Age:");
    gotoxy(33,12);
    scanf("%f",&patient.age);
    gotoxy(19,13);
    printf("SEX:");
    gotoxy(33,13);
    scanf("%s",&patient.sex);
    gotoxy(19,14);
    printf("Which Medical Test He or She Checkup:");
    gotoxy(33,16);
    scanf("%s",&patient.medical);
    return 1;


}
int checkid(int t)
{
    rewind(fp);
    while(fread(&patient,sizeof(patient),1,fp)==1)
    if(patient.id==t)
    return 0;
    return 1;
}

 void addmedical()
  {
        //system("cls");
        //printf("This is Add Medical Test");

    system("cls");
    int m;
    gotoxy(20, 3);
    printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
    gotoxy(20,5);
    printf("************** SELECT MEDICAL TEST **************");
    gotoxy(28,7);
    printf(" 1. BLOOD TEST");
    gotoxy(28,9);
    printf(" 2. PATHOLOGY");
    gotoxy(28,11);
	printf(" 3. ENDOSCOPY");
	gotoxy(28,13);
	printf(" 4. ULTRASONOGRAM");
	gotoxy(28,15);
	printf(" 5. X-RAY");
	gotoxy(28,17);
	printf(" 6. VACCINATION");
	gotoxy(28,19);
	printf(" 7. Back to main menu");
	gotoxy(20,22);
	printf("************************************************");
	gotoxy(20,25);
	printf("Enter your choice:");
    scanf("%d",&m);
    if(m==1)
    {
        bloodtestp();
    }

    else if(m==2)
    {
        pathologyp();
    }
    else if(m==3)
    {
        endoskopy();
    }
    else if(m==4)
    {
        ultrasonogramp();
    }
    else if(m==5)
    {
        xrayp();
    }
    else if(m==6)
    {
        vaccinationp();
    }
    else if(m==7)
    {
        mainmenu();
    }
    else
    {
        mainmenu();
    }


}
// //////////////////////////////////////add medical///////////////////

/////////////////////////ADD Blood Test //////////////////////////////////////
void bloodtestp()
{
       /* system("cls");
        printf("This is blood test");*/

      system("cls");
      int b;
      gotoxy(20, 4);
      printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
      gotoxy(20,7);
      printf("****************** Add Blood Test *****************");
      gotoxy(25,10);
      printf("1. Add Blood Test");
      gotoxy(25,14);
      printf("2. Go Back");
      gotoxy(25,18);
      printf("3. Back to Main Menu ");
      gotoxy(20,25);
	  printf("************************************************");
      gotoxy(25,22);
      printf("Enter Your Choice:");
      scanf("%d",&bt);
	  if(bt==3)
	  mainmenu();
	  else if(bt==2)
      addmedical();
	  fb=fopen("bloodtest.dat","ab+");
	  if(getblood()==1)
	  {
	    bloodtest.bdt=btcatagories[bt-1];
	    fseek (fb,0,SEEK_END);
	    fwrite(&bloodtest,sizeof(bloodtest),1,fb);
	    fclose(fb);
	    gotoxy(21,20);
	    printf("The record is sucessfully saved");
	    gotoxy(21,22);
	    printf("Save any more?(Y/N):");
	    if(getch()=='n')
	    mainmenu();
	    else
	    system("cls");
	    bloodtestp();

	}

}
int getblood()
{
    system("cls");
    int d;
    gotoxy(20,2);
    printf("Enter The Blood Test Result In  Below");
    gotoxy(12,3);
    printf("****************************************************************");
    gotoxy(15,24);
    gotoxy(12,26);
    printf("****************************************************************");
    gotoxy(32,4);
    printf("Add Blood Test");
    gotoxy(38,6);
    //printf("%s",btcatagories[bt-1]);
    gotoxy(15,8);
    printf("PatientID:  \t");
    InputData:
    gotoxy(42,8);
    scanf("%d",&d);
    /////////////////////////////////
    fp=fopen("parves.dat","ab+");
   // fread(&patient,sizeof(patient),1,fp);
   //    if(patient.id == d)
   if(checkpatbloodid(d)==2)
    {
        fclose(fp);
        gotoxy(15,6);
        printf("Patient ID is Right                             ");
        gotoxy(15,25);
        printf("\a                                                         \a");


   ////////////////////////

      if(checkbid(d)==0)
      {
        gotoxy(15,25);
        printf("\aThe patient ID is already exists. Input again........\a");
        goto InputData;
        return 0;

      }
    bloodtest.id=d;
    gotoxy(15,9);
    printf("Blood Group:                ");
    gotoxy(42,9);
    scanf("%s",&bloodtest.group);
    gotoxy(15,10);
    printf("Suger Fasting ? mmol/l. :  ");
    gotoxy(42,10);
    scanf("%f",&bloodtest.sugerf);
    gotoxy(15,11);
    printf("Sugar Random ? mmol/l. :   ");
    gotoxy(42,11);
    scanf("%f",&bloodtest.sugerr);
    gotoxy(15,12);
    printf("Blood Urea   ? mg/dl.:      ");
    gotoxy(42,12);
    scanf("%f",&bloodtest.blooduria);
    gotoxy(15,13);
    printf("S.  Protin   ? gm/L. :      ");
    gotoxy(42,13);
    scanf("%f",&bloodtest.totalprotin);
    gotoxy(15,14);
    printf("S.Cholestrol ? mg/dl. :     ");
    gotoxy(42,14);
    scanf("%f",&bloodtest.cholestrol);
    gotoxy(15,15);
    printf("S. Bilirubin ? mg/dl. :     ");
    gotoxy(42,15);
    scanf("%f",&bloodtest.bilirubin);
    gotoxy(15,16);
    printf("HBsAG Negative/Positive :   ");
    gotoxy(42,16);
    scanf("%s",&bloodtest.hbsag);
    return 1;
    return 2;
    }
    else
    {
        fclose(fp);
        gotoxy(15,6);
        printf("Patient ID Is Wrong or Not Add");
        gotoxy(15,25);
        printf("\a Please Enter A Right Patient Id & Add Blood Test.\a");
        //printf("\a The patient ID is already exists. Input again...\a");
        goto InputData;

    }
}
int checkpatbloodid(int d)
{
    rewind(fp);
    while(fread(&patient,sizeof(patient),1,fp)==1)
    if(patient.id==d)
    return 2;
}
int checkbid(int d)
{
    rewind(fb);
    while(fread(&bloodtest,sizeof(bloodtest),1,fb)==1)
    if(bloodtest.id==d)
    return 0;
    return 1;
}
///////////////////////////////Add Blood Test ////////////////////////////////


////////////////////////////// add Patholpgy ////////////////////////////////
void pathologyp()
    {
        /*system("cls");
        printf("This is pathology");*/

    system("cls");
    int lg;
    gotoxy(20, 3);
    printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
    gotoxy(20,5);
    printf("************** SELECT FOR ADD PATHOLOGY TEST **************");
    gotoxy(29,7);
    printf(" 1. Urin Test");
    gotoxy(29,9);
    printf(" 2. Stool Test");
    gotoxy(28,11);
	printf("  3. Go Back");
	gotoxy(28,13);
	printf("  4. Back to main menu");
	gotoxy(20,16);
	printf("************************************************");
	gotoxy(20,18);
	printf("Enter your choice:");
    scanf("%d",&lg);
    if(lg==1)
    {
        urinetest();
    }

    else if(lg==2)
    {
        stooltest();
    }
    else if(lg==3)
    {
        addmedical();
    }
    else if(lg==4)
    {
        mainmenu();
    }
    else
    {
        mainmenu();
    }
}


/////////////////////// Urin /////////////////
void urinetest()
{

      system("cls");
      int u;
      //int iu;
      gotoxy(20, 4);
      printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
      gotoxy(20,7);
      printf("****************** Add Urin Test *****************");
      gotoxy(25,10);
      printf("1. Add Urin Test");
      gotoxy(25,14);
      printf("2. Go Back");
      gotoxy(25,18);
      printf("3. Back to Main Menu ");
      gotoxy(20,25);
	  printf("************************************************");
      gotoxy(25,22);
      printf("Enter Your Choice:");
      scanf("%d",&ur);
	  if(ur==3)
	  mainmenu();
	  else if(ur==2)
      pathologyp();
	  fu=fopen("urin.dat","ab+");
	  if(geturin()==1)
	  {
	    urin.urn=urcatagories[ur-1];//[ur-1];
	    fseek (fu,0,SEEK_END);
	    fwrite(&urin,sizeof(urin),1,fu);
	    fclose(fu);
	    gotoxy(21,20);
	    printf("The record is sucessfully saved");
	    gotoxy(21,22);
	    printf("Save any more?(Y/N):");
	    if(getch()=='n')
	    mainmenu();
	    else
	    system("cls");
	    pathologyp();
	}
}
int geturin()
{
    system("cls");
    int r, pu;
    gotoxy(20,2);
    printf("Enter The Urin Test Result In  Below");
    gotoxy(12,3);
    printf("****************************************************************");
    gotoxy(12,26);
    printf("****************************************************************");
    gotoxy(33,4);
    printf("Add Urin Test");
    gotoxy(16,8);
    printf("PatientID:  \t");
    InputData:
    gotoxy(35,8);
    scanf("%d",&r);
         /*________*/
    /////////////////////////////////
    fp=fopen("parves.dat","ab+");
    fread(&patient,sizeof(patient),1,fp);
    ////////////////////////////////
    //if(patient.id = r  )
    if(checkpaturinid(r)==2)  /*___________*/
      {
        fclose(fp);
        gotoxy(35,6);
        printf("Patient ID is Right              ");
        gotoxy(16,25);
        printf("\a                                                    \a");

   ////////////////////////

      if(checkuid(r)==0)
      {
        gotoxy(16,25);
        printf("\aThe patient ID is already exists. Input again......\a");
        goto InputData;
        return 3;

      }
    urin.id=r;
    gotoxy(16,9);
    printf("Valume(c.c):");
    gotoxy(35,9);
    scanf("%f",&urin.volume);
    gotoxy(16,10);
    printf("Reaction:  ");
    gotoxy(35,10);
    scanf("%s",&urin.reaction);
    gotoxy(16,11);
    printf("Alubumin: ");
    gotoxy(35,11);
    scanf("%s",&urin.alubumin);
    gotoxy(16,12);
    printf("Sugar:      ");
    gotoxy(35,12);
    scanf("%s",&urin.sugar);
    gotoxy(16,13);
    printf("Blood:      ");
    gotoxy(35,13);
    scanf("%s",&urin.blad);
    gotoxy(16,14);
    printf("Calcium Oxalet:     ");
    gotoxy(35,14);
    scanf("%s",&urin.calsiamoxalet);
    gotoxy(16,15);
    printf("Uric Asid:     ");
    gotoxy(35,15);
    scanf("%s",&urin.uricasid);
    gotoxy(16,16);
    printf("Epithelial Cells :   ");
    gotoxy(35,16);
    scanf("%s",&urin.epithelialcell);
    return 1;
    return 2;
    }
    else
    {
        fclose(fp);
        gotoxy(35,6);
        printf("Patient ID Is Wrong or Not Add");
        gotoxy(15,25);
        printf("\a Please Enter A Right Patient Id & Add Urin Test.\a");
        //printf("\a The patient ID is already exists. Input again...\a");
        goto InputData;

    }
    //return 2;
}
int checkpaturinid(int r)
{
    rewind(fp);
    while(fread(&patient,sizeof(patient),1,fp)==1)
    if(patient.id==r)
    return 2;
    //return 3;
}
int checkuid(int r)
{
    rewind(fu);
    while(fread(&urin,sizeof(urin),1,fu)==1)
    if(urin.id==r)
    return 0;
    return 1;
}//////////////////////////


/////////////  Stool //////////////////////
void stooltest()
{
       /* system("cls");
        printf("This is stool test");*/

      system("cls");
      int s;
      gotoxy(20, 4);
      printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
      gotoxy(20,7);
      printf("****************** Add Stool Test *****************");
      gotoxy(25,10);
      printf("1. Add Stool Test");
      gotoxy(25,14);
      printf("2. Go Back");
      gotoxy(25,18);
      printf("3. Back to Add Medical Test ");
      gotoxy(20,25);
	  printf("************************************************");
      gotoxy(25,22);
      printf("Enter Your Choice:");
      scanf("%d",&sso);
	  if(sso==3)
	  addmedical();
	  else if(sso==2)
      pathologyp();

	  fs=fopen("stool.dat","ab+");
	  if(getstool()==1)
	  {
	    stool.stl=stcatagories[sso-1];
	    fseek (fs,0,SEEK_END);
	    fwrite(&stool,sizeof(stool),1,fs);
	    fclose(fs);
	    gotoxy(21,20);
	    printf("The record is sucessfully saved");
	    gotoxy(21,22);
	    printf("Save any more?(Y/N):");
	    if(getch()=='n')
	    mainmenu();
	    else
	    system("cls");
	    pathologyp();
	}
}
int getstool()
{
    system("cls");
    int so ;
    gotoxy(20,2);
    printf("Enter The Stool Test Result In  Below");
    gotoxy(12,3);
    printf("****************************************************************");
    gotoxy(12,26);
    printf("****************************************************************");
    gotoxy(33,4);
    printf("Add Stool Test");
    gotoxy(16,8);
    printf("PatientID:  \t");
    InputData:
    gotoxy(35,8);
    scanf("%d",&so);
    /////////////////////////////////
    fp=fopen("parves.dat","ab+");
    fread(&patient,sizeof(patient),1,fp);
    ////////////////////////////////
    //if(patient.id = so)
    if(checkpatstoolid(so)==2)
    {
        fclose(fp);
        gotoxy(35,6);
        printf("Patient ID is Right              ");
        gotoxy(16,25);
        printf("\a                                                     \a");
   ////////////////////////

      if(checkstid(so)==0)
      {
        gotoxy(16,25);
        printf("\aThe patient ID is already exists. Input again.....\a");
        goto InputData;
        return 0;

      }
    stool.id=so;
    gotoxy(16,9);
    printf("Valume(c.c):");
    gotoxy(35,9);
    scanf("%f",&stool.volume);
    gotoxy(16,10);
    printf("Reaction:  ");
    gotoxy(35,10);
    scanf("%s",&stool.reaction);
    gotoxy(16,11);
    printf("Alubumin: ");
    gotoxy(35,11);
    scanf("%s",&stool.alubumin);
    gotoxy(16,12);
    printf("Sugar:      ");
    gotoxy(35,12);
    scanf("%s",&stool.sugar);
    gotoxy(16,13);
    printf("Blood:      ");
    gotoxy(35,13);
    scanf("%s",&stool.blad);
    gotoxy(16,14);
    printf("Calcium Oxalet:     ");
    gotoxy(35,14);
    scanf("%s",&stool.calsiamoxalet);
    gotoxy(16,15);
    printf("Uric Asid:     ");
    gotoxy(35,15);
    scanf("%s",&stool.uricasid);
    gotoxy(16,16);
    printf("Epithelial Cells :   ");
    gotoxy(35,16);
    scanf("%s",&stool.epithelialcell);
    return 1;
    return 2;

    }
    else
    {
        fclose(fp);
        gotoxy(35,6);
        printf("Patient ID Is Wrong or Not Add");
        gotoxy(15,25);
        printf("\a Please Enter A Right Patient Id & Add Stool Test.\a");
        //printf("\a The patient ID is already exists. Input again...\a");
        goto InputData;

    }
}
int checkpatstoolid(int so)
{
    rewind(fp);
    while(fread(&patient,sizeof(patient),1,fp)==1)
    if(patient.id==so)
    return 2;
}
int checkstid(int so)
{
    rewind(fs);
    while(fread(&stool,sizeof(stool),1,fs)==1)
    if(stool.id==so)
    return 0;
    return 1;
}




/////////////////////////////////////// Pregnenci ////////////////


void pregnencitest()
    {
        system("cls");
        printf("This is Pregnenci ");
    }

//////////////////////////////pathology///////////////////////////////////

/////////////////////////////// Endoskopy ///////////////////////////
void endoskopy()
{
      system("cls");
      int e;
      gotoxy(20, 4);
      printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
      gotoxy(20,7);
      printf("****************** Add  Endoscopy *****************");
      gotoxy(25,10);
      printf("1. Add Endoscopy");
      gotoxy(25,14);
      printf("2. Go Back");
      gotoxy(25,18);
      printf("3. Back to Main Menu ");
      gotoxy(20,25);
	  printf("************************************************");
      gotoxy(25,22);
      printf("Enter Your Choice:");
      scanf("%d",&eo);
	  if(eo==3)
	  mainmenu();
	  else if(eo==2)
      addmedical();

      fe=fopen("endoscopy.dat","ab+");
	  if(getendos()==1)
	  {
	    endos.ends=eccatagories[eo-1];
	    fseek (fe,0,SEEK_END);
	    fwrite(&endos,sizeof(endos),1,fe);
	    fclose(fe);
	    gotoxy(21,20);
	    printf("The record is sucessfully saved");
	    gotoxy(21,22);
	    printf("Save any more?(Y/N):");
	    if(getch()=='n')
	    mainmenu();
	    else
	    system("cls");
	    addmedical();
     }

}
int getendos()
{
    system("cls");
    int o ;
    gotoxy(20,2);
    printf("Enter The Endoscopy Result In  Below");
    gotoxy(12,3);
    printf("****************************************************************");
    gotoxy(12,26);
    printf("****************************************************************");
    gotoxy(33,4);
    printf("Add Endoscopy Test");
    gotoxy(16,8);
    printf("PatientID:  \t");
    InputData:
    gotoxy(35,8);
    scanf("%d",&o);
    /////////////////////////////////
    fp=fopen("parves.dat","ab+");
    fread(&patient,sizeof(patient),1,fp);
    ////////////////////////////////
    //if(patient.id = o)
    if(checkpatendosid(o)==2)
    {
        fclose(fp);
        gotoxy(35,6);
        printf("Patient ID is Right              ");
        gotoxy(16,25);
        printf("\a                                                        ");

   ////////////////////////

      if(checkendosid(o)==0)
      {
        gotoxy(16,25);
        printf("\aThe patient ID is already exists. Input again...\a");
        goto InputData;
        return 0;

      }
    endos.id=o;
    gotoxy(16,9);
    printf("OESOPHAGUS:");
    gotoxy(35,9);
    scanf("%s",&endos.oesop);
    gotoxy(16,10);
    printf("STOMAC:  ");
    gotoxy(35,10);
    scanf("%s",&endos.stomac);
    gotoxy(16,11);
    printf("FUNDS: ");
    gotoxy(35,11);
    scanf("%s",&endos.funds);
    gotoxy(16,12);
    printf("ANTRUM:      ");
    gotoxy(35,12);
    scanf("%s",&endos.antrum);
    gotoxy(16,13);
    printf("DUODENUM:      ");
    gotoxy(35,13);
    scanf("%s",&endos.duodenium);
    gotoxy(16,14);
    printf("D-BULB:     ");
    gotoxy(35,14);
    scanf("%s",&endos.dbulb);
    gotoxy(16,15);
    printf("Need BIOPSY:     ");
    gotoxy(35,15);
    scanf("%s",&endos.biopsy);
    gotoxy(16,16);
    printf("COMMENT :   ");
    gotoxy(35,16);
    scanf("%s",&endos.comment);
    return 1;
    return 2;
    }
    else
    {
        fclose(fp);
        gotoxy(35,6);
        printf("Patient ID Is Wrong or Not Add");
        gotoxy(15,25);
        printf("\a Please Enter A Right Patient Id & Add Endoscopy.\a");
        //printf("\a The patient ID is already exists. Input again...\a");
        goto InputData;

    }
}
int checkpatendosid(int o)
{
    rewind(fp);
    while(fread(&patient,sizeof(patient),1,fp)==1)
    if(patient.id==o)
    return 2;
}
int checkendosid(int o)
{
    rewind(fe);
    while(fread(&endos,sizeof(endos),1,fe)==1)
    if(endos.id==o)
    return 0;
    return 1;
}


/////////////////////////////////  Ultrasonagram  ////////////////////////////
void ultrasonogramp()
{
        /*system("cls");
        printf("This is ultra......");*/
      system("cls");
      int ul;
      gotoxy(20, 4);
      printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
      gotoxy(20,7);
      printf("****************** Add Ultrasonogram *****************");
      gotoxy(25,10);
      printf("1. Add Ultrasonogram");
      gotoxy(25,14);
      printf("2. Go Back");
      gotoxy(25,18);
      printf("3. Back to Main Menu ");
      gotoxy(20,25);
	  printf("************************************************");
      gotoxy(25,22);
      printf("Enter Your Choice:");
      scanf("%d",&ulgm);
	  if(ulgm==3)
	  mainmenu();
	  else if(ulgm==2)
      addmedical();
	  ful=fopen("ultrasonogram.dat","ab+");
	  if(getultra()==1)
	  {
	    ultrasonogram.ultra=ulcatagories[ulgm-1];
	    fseek (ful,0,SEEK_END);
	    fwrite(&ultrasonogram,sizeof(ultrasonogram),1,ful);
	    fclose(ful);
	    gotoxy(21,20);
	    printf("The record is sucessfully saved");
	    gotoxy(21,22);
	    printf("Save any more?(Y/N):");
	    if(getch()=='n')
	    mainmenu();
	    else
	    system("cls");
	    ultrasonogramp();

	}
}
int getultra()
{
    system("cls");
    int gm;
    gotoxy(20,2);
    printf("Enter The Ultrasonogram Result In  Below");
    gotoxy(12,3);
    printf("****************************************************************");
    gotoxy(12,26);
    printf("****************************************************************");
    gotoxy(32,4);
    printf("Add Ultrasonogram");
    gotoxy(38,6);
    //printf("%s",btcatagories[bt-1]);
    gotoxy(15,8);
    printf("PatientID:  \t");
    InputData:
    gotoxy(42,8);
    scanf("%d",&gm);
    /////////////////////////////////
    fp=fopen("parves.dat","ab+");
    fread(&patient,sizeof(patient),1,fp);
    ////////////////////////////////
    //if(patient.id = gm)
    if(checkpatultraid(gm)==2)
    {
        fclose(fp);
        gotoxy(15,6);
        printf("Patient ID is Right                        ");
        gotoxy(15,25);
        printf("\a                                                        \a");

   ////////////////////////

      if(checkultraid(gm)==0)
      {
        gotoxy(15,25);
        printf("\aThe patient ID is already exists. Input again...      \a");
        goto InputData;
        return 0;

      }
    ultrasonogram.id=gm;
    gotoxy(15,9);
    printf("LIVER:                ");
    gotoxy(42,9);
    scanf("%s",&ultrasonogram.liver);
    gotoxy(15,10);
    printf("KIDNEY:  ");
    gotoxy(42,10);
    scanf("%s",&ultrasonogram.kidney);
    gotoxy(15,11);
    printf("PROSTET:   ");
    gotoxy(42,11);
    scanf("%s",&ultrasonogram.prostet);
    gotoxy(15,12);
    printf("SPLEEN:      ");
    gotoxy(42,12);
    scanf("%s",&ultrasonogram.spleen);
    return 1;
    return 2;
    }
    else
    {
        gotoxy(15,6);
        printf("Patient ID Is Wrong or Not Add");
        gotoxy(15,25);
        printf("\a Please Enter A Right Patient Id & Input again...        \a");
        fclose(fp);
        goto InputData;

    }
}
int checkpatultraid(int gm)
{
    rewind(fp);
    while(fread(&patient,sizeof(patient),1,fp)==1)
    if(patient.id==gm)
    return 2;
}
int checkultraid(int gm)
{
    rewind(ful);
    while(fread(&ultrasonogram,sizeof(ultrasonogram),1,ful)==1)
    if(ultrasonogram.id==gm)
    return 0;
    return 1;
}
/////////////////////////////////////////////////////////////////

/////////////////////// Vaccination ///////////////////////////////
void vaccinationp()
{
        /*system("cls");
        printf("This is ultra......");*/
      system("cls");
      int v;
      gotoxy(20, 4);
      printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
      gotoxy(20,7);
      printf("****************** Add Vaccination *****************");
      gotoxy(25,10);
      printf("1. Add Vaccination ");
      gotoxy(25,14);
      printf("2. Go Back");
      gotoxy(25,18);
      printf("3. Back to Main Menu ");
      gotoxy(20,25);
	  printf("************************************************");
      gotoxy(25,22);
      printf("Enter Your Choice:");
      scanf("%d",&vvc);
	  if(vvc==3)
	  mainmenu();
	  else if(vvc==2)
      addmedical();
	  fv=fopen("vaccination.dat","ab+");
	  if(getvacctination()==1)
	  {
	    vacination.vacin=vccatagories[vvc-1];
	    fseek (fv,0,SEEK_END);
	    fwrite(&vacination,sizeof(vacination),1,fv);
	    fclose(fv);
	    gotoxy(21,20);
	    printf("The record is sucessfully saved");
	    gotoxy(21,22);
	    printf("Save any more?(Y/N):");
	    if(getch()=='n')
	    mainmenu();
	    else
	    system("cls");
	    vaccinationp();

	}
}
int getvacctination()
{
    system("cls");
    int vc;
    gotoxy(20,2);
    printf("Enter The Vaccination In  Below");
    gotoxy(12,3);
    printf("****************************************************************");
    gotoxy(12,26);
    printf("****************************************************************");
    gotoxy(32,4);
    printf("Add Vaccination");
    gotoxy(38,6);
    //printf("%s",btcatagories[bt-1]);
    gotoxy(15,8);
    printf("PatientID:  \t");
    InputData:
    gotoxy(42,8);
    scanf("%d",&vc);
    /////////////////////////////////
    fp=fopen("parves.dat","ab+");
    fread(&patient,sizeof(patient),1,fp);
    ////////////////////////////////
    //if(patient.id = vc)
    if(checkpatvaccinid(vc)==2)
    {
        gotoxy(15,6);
        printf("Patient ID is Right                                   ");
        gotoxy(15,25);
        printf("\a                                                            \a");
        fclose(fp);
   ////////////////////////

      if(checkvaccinationid(vc)==0)
      {
        gotoxy(15,25);
        printf("\aThe patient ID is already exists. Input again...    \a");
        goto InputData;
        return 0;

      }
    vacination.id=vc;
    gotoxy(15,9);
    printf("Which Vaccin he or she use:                ");
    gotoxy(42,9);
    scanf("%s",&vacination.vaccin);
    gotoxy(15,10);
    printf("Comment:");
    gotoxy(42,10);
    scanf("%s",&vacination.comment);
    return 1;
    return 2;
    }
    else
    {
        gotoxy(15,6);
        printf("Patient ID Is Wrong or Not Add");
        gotoxy(15,25);
        printf("\a Please Enter A Right Patient Id & Input again...   \a");
        fclose(fp);
        goto InputData;

    }
}
int checkpatvaccinid(int vc)
{
    rewind(fp);
    while(fread(&patient,sizeof(patient),1,fp)==1)
    if(patient.id==vc)
    return 2;
}
int checkvaccinationid(int vc)
{
    rewind(fv);
    while(fread(&vacination,sizeof(vacination),1,fv)==1)
    if(vacination.id==vc)
    return 0;
    return 1;
}
////////////////////////////////////////////////////////////


//////////////////// X ray //////////////////////////

void xrayp()
{
        /*system("cls");
        printf("This is ultra......");*/
      system("cls");
      int x;
      gotoxy(20, 4);
      printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
      gotoxy(20,7);
      printf("********************** Add X-Ray ********************");
      gotoxy(25,10);
      printf("1. Add X-Ray ");
      gotoxy(25,14);
      printf("2. Go Back");
      gotoxy(25,18);
      printf("3. Back to Main Menu ");
      gotoxy(20,25);
	  printf("************************************************");
      gotoxy(25,22);
      printf("Enter Your Choice:");
      scanf("%d",&xry);
	  if(xry==3)
	  mainmenu();
	  else if(xry==2)
      addmedical();
	  fx=fopen("xray.dat","ab+");
	  if(getxray()==1)
	  {
	    xray.xra=xrcatagories[xry-1];
	    fseek (fx,0,SEEK_END);
	    fwrite(&xray,sizeof(xray),1,fx);
	    fclose(fx);
	    gotoxy(21,20);
	    printf("The record is sucessfully saved");
	    gotoxy(21,22);
	    printf("Save any more?(Y/N):");
	    if(getch()=='n')
	    mainmenu();
	    else
	    system("cls");
	    xrayp();

	}
}
int getxray()
{
    system("cls");
    int ry;
    gotoxy(20,2);
    printf("Enter The X-ray Result In  Below");
    gotoxy(12,3);
    printf("****************************************************************");
    gotoxy(12,26);
    printf("****************************************************************");
    gotoxy(32,4);
    printf("Add X-ray");
    gotoxy(38,6);
    //printf("%s",btcatagories[bt-1]);
    gotoxy(15,8);
    printf("PatientID:  \t");
    InputData:
    gotoxy(42,8);
    scanf("%d",&ry);
    /////////////////////////////////
    fp=fopen("parves.dat","ab+");
    fread(&patient,sizeof(patient),1,fp);
    ////////////////////////////////
    //if(patient.id = ry)
    if(checkpatxrayid(ry)==2)
    {
        gotoxy(15,6);
        printf("Patient ID is Right                ");
        gotoxy(15,25);
        printf("\a                                                             \a");
        fclose(fp);
   ////////////////////////

      if(checkxrayid(ry)==0)
      {
        gotoxy(15,25);
        printf("\aThe patient ID is already exists. Input again...      \a");
        goto InputData;
        return 0;

      }
    xray.id=ry;
    gotoxy(15,9);
    printf("Which X-ray he or she do:                ");
    gotoxy(42,9);
    scanf("%s",&xray.skull);
    gotoxy(15,10);
    printf("Comment:");
    gotoxy(42,10);
    scanf("%s",&xray.hand);
    return 1;
    return 2;
    }
    else
    {
        gotoxy(15,6);
        printf("Patient ID Is Wrong or Not Add");
        gotoxy(15,25);
        printf("\a Please Enter A Right Patient Id & Input again...\a");
        fclose(fp);
        goto InputData;

    }
}
int checkpatxrayid(int ry)
{
    rewind(fp);
    while(fread(&patient,sizeof(patient),1,fp)==1)
    if(patient.id==ry)
    return 2;
}
int checkxrayid(int ry)
{
    rewind(fx);
    while(fread(&xray,sizeof(xray),1,fx)==1)
    if(xray.id==ry)
    return 0;
    return 1;
}
////////////////////////////////////////////////////////////

///////////////////////////////////**************************************///////////////////////////////////////////////////////////////////

/////////////////////////////////// Vew Patient //////////////////////////////////////////
 void viewpatients()
    {
       /* system("cls");
        printf("This is View Patient");*/
    int i = 0, j;
    system("cls");
    gotoxy(1,1);
    printf("********************************* View Patient ********************************");
    gotoxy(1,2);
    printf("ID            NAME                  AGE   SEX           MEDICAL TEST        ");
    j=4;
    fp=fopen("parves.dat","rb");
    while(fread(&patient,sizeof(patient),1,fp)==1)
    {
	gotoxy(1,j);
	printf("%d",patient.id);
	gotoxy(5,j);
	//printf("%s",patient.pat);
	gotoxy(8,j);
	printf("%s\t",patient.f_name);
	gotoxy(15,j);
	printf("%s",patient.m_name);
	gotoxy(25,j);
	printf("%s",patient.l_name);
	gotoxy(37,j);
	printf("%.f",patient.age);
	gotoxy(43,j);
	printf("%s",patient.sex);
	gotoxy(53,j);
	printf("%s",patient.medical);
	printf("\n\n");
	j++;
	//i = i + book.;
      }
     /* gotoxy(3,25);
      printf("Total Books =%d",i);*/
     fclose(fp);
     gotoxy(35,25);
     returnToMainMenu();
}
void returnToMainMenu()
{
    {
        printf(" Press Enter To Return Main Menu");
    }
    a:
    if(getch()==13)
    mainmenu();
    else
    goto a;
}
//////////////////////////////////////////// view________________________________patient ///////////////////////////////////////////////////////


/////////////////////////////////////////// View Medical Test ///////////////////////////////////////////////////////////////////

void viewmedical()
{
      /*  system("cls");
        printf("This is View Medical Test");*/

      system("cls");
    int vm;
    gotoxy(20, 3);
    printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
    gotoxy(20,5);
    printf("************** SELECT VIEW MEDICAL TEST **************");
    gotoxy(28,7);
    printf(" 1. View Blood Test");
    gotoxy(28,9);
    printf(" 2. VIEW PATHOLOGY");
    gotoxy(28,11);
	printf(" 3. VIEW ENDOSCOPY");
	gotoxy(28,13);
	printf(" 4. VIEW ULTRASONOGRAM");
	gotoxy(28,15);
	printf(" 5. VIEW X-RAY");
	gotoxy(28,17);
	printf(" 6. VIEW VACCINATION");
	gotoxy(28,19);
	printf(" 7. Back to main menu");
	gotoxy(20,22);
	printf("************************************************");
	gotoxy(20,25);
	printf("Enter your choice:");
    scanf("%d",&vm);
    if(vm==1)
    {
        viewbloodtest();
    }

    else if(vm==2)
    {
        viewpathology();
    }
    else if(vm==3)
    {
        viewendoskopy();
    }
    else if(vm==4)
    {
        viewultrasonogram();
    }
    else if(vm==5)
    {
        viewxray();
    }
    else if(vm==6)
    {
        viewvaccination();
    }
    else if(vm==7)
    {
        mainmenu();
    }
    else
    {
        viewmedical();
    }

}
void viewbloodtest()
{
    int i = 0, j;
    system ("cls");
    gotoxy(1,1);
    printf("***************************Blood Test List**********************************");
    gotoxy(2,2);
    printf("ID   B.Group   SugarF   SugarR  Urea   Protin  Cholestrol   Bilirubin   HBsAG");
    j=4;
    fb=fopen("bloodtest.dat","rb");
    while(fread(&bloodtest,sizeof(bloodtest),1,fb)==1)
    {
       // gotoxy(1,j);
        //printf("%s",bloodtest.bdt)
        gotoxy(1,j);
        printf("%d",bloodtest.id);
        gotoxy(9,j);
        printf("%s",bloodtest.group);
        gotoxy(18,j);
        printf("%.2f",bloodtest.sugerf);
        gotoxy(26,j);
        printf("%.2f",bloodtest.sugerr);
        gotoxy(34,j);
        printf("%.2f",bloodtest.blooduria);
        gotoxy(42,j);
        printf("%.2f",bloodtest.totalprotin);
        gotoxy(52,j);
        printf("%.2f",bloodtest.cholestrol);
        gotoxy(64,j);
        printf("%.2f",bloodtest.bilirubin);
        gotoxy(74,j);
        printf("%s",bloodtest.hbsag);
        printf("\n\n");
        j++;
       // i=i+book.quantity;
    }
   // gotoxy(3,25);
   //printf("Total Booka =%d",i);
      fclose(fb);
      gotoxy(35,25);
      returnToMainMenu();
}

void viewpathology()
{
      char c;
   system("cls");
   gotoxy(20, 4);
   printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
   gotoxy(20, 6);
   printf("***************** View Pathology ********************");
   gotoxy(28,8);
   printf(" 1. View Urin Test ");
   gotoxy(28,12);
   printf(" 2. View Stool Test ");
   gotoxy(28,16);
   printf(" 3. Go Back ");
   gotoxy(28,20);
   printf(" 4. Main Menu ");
   gotoxy(20, 26);
   printf("******************************************************");

   InputOption:
   gotoxy(28,28);
   printf(" Enter Your Choise: ");
   c = getchar();
   switch(c)
   {
       case '1':
       viewurinetest();
       break;
       case '2':
       viewstooltest();
       break;
       case '3':
       viewmedical();
       break;
       case '4':
       mainmenu();
       break;
      /* case'9':
            system("cls");
            exit(0);*/
        default:
        {
            gotoxy(20, 31);
            printf("Please Re-Enter Which You can See In This  Option");
            goto InputOption;
        }
    }
}
        //add pathology//
   void viewurinetest()
   {
    int i = 0, j;
    system ("cls");
    gotoxy(1,1);
    printf("*************************** Urin Test List ***********************************");
    gotoxy(2,2);
    printf("ID   Valume   Reaction   Alubumin  Suger   Blood   Calcium   Uric   Epithelial");
    gotoxy(3,3);
    printf("                                                  Oxalate   Asid    Cells  ");
    j=5;
    fu=fopen("urin.dat","rb");
    while(fread(&urin,sizeof(urin),1,fu)==1)
    {
       // gotoxy(1,j);
        //printf("%s",bloodtest.bdt)
        gotoxy(0.5,j);
        printf("%d",urin.id);
        gotoxy(7,j);
        printf("%.2f",urin.volume);
        gotoxy(17,j);
        printf("%s",urin.reaction);
        gotoxy(28,j);
        printf("%s",urin.alubumin);
        gotoxy(38,j);
        printf("%s",urin.sugar);
        gotoxy(45,j);
        printf("%s",urin.blad);
        gotoxy(54,j);
        printf("%s",urin.calsiamoxalet);
        gotoxy(63,j);
        printf("%s",urin.uricasid);
        gotoxy(71.5,j);
        printf("%s",urin.epithelialcell);
        printf("\n\n");
        j++;
      }
      fclose(fu);
      gotoxy(35,25);
      returnToViewMedicalTest();
}
void returnToViewMedicalTest()
{
    {
        printf("Press Enter To Return To View Medical Test");
    }
    a:
    if(getch()==13)
    viewmedical();
    else
    goto a;
}

   void viewstooltest()
   {
    int i = 0, j;
    system ("cls");
    gotoxy(1,1);
    printf("**************************** Stool Test List *********************************");
    gotoxy(2,2);
    printf("ID   Valume   Reaction   Alubumin  Suger   Blood   Calcium   Uric   Epithelial");
    gotoxy(3,3);
    printf("                                                  Oxalate   Asid    Cells  ");
    j=5;
    fs=fopen("stool.dat","rb");
    while(fread(&stool,sizeof(stool),1,fs)==1)
    {
        gotoxy(0.5,j);
        printf("%d",stool.id);
        gotoxy(7,j);
        printf("%.2f",stool.volume);
        gotoxy(17,j);
        printf("%s",stool.reaction);
        gotoxy(28,j);
        printf("%s",stool.alubumin);
        gotoxy(38,j);
        printf("%s",stool.sugar);
        gotoxy(45,j);
        printf("%s",stool.blad);
        gotoxy(54,j);
        printf("%s",stool.calsiamoxalet);
        gotoxy(63,j);
        printf("%s",stool.uricasid);
        gotoxy(71.5,j);
        printf("%s",stool.epithelialcell);
        printf("\n\n");
        j++;
      }
      fclose(fs);
      gotoxy(35,25);
      returnToViewMedicalTest();
   }

        //add pathology//

void viewendoskopy()
{

    int i = 0, j;
    system ("cls");
    gotoxy(1,1);
    printf("*************************** Endoscopy  Report ********************************* ");
    gotoxy(0,2);
    printf("ID    Oesophagus  Stomac   Funds    Antrum   Duodenium   D-bulb   Need   Comment");
    gotoxy(3,3);
    printf("                                                              Biopsy      ");
    j=5;
    fe=fopen("endoscopy.dat","rb");
    while(fread(&endos,sizeof(endos),1,fe)==1)
    {
        gotoxy(0.5,j);
        printf("%d",endos.id);
        gotoxy(7,j);
        printf("%s",endos.oesop);
        gotoxy(19,j);
        printf("%s",endos.stomac);
        gotoxy(27,j);
        printf("%s",endos.funds);
        gotoxy(37,j);
        printf("%s",endos.antrum);
        gotoxy(46,j);
        printf("%s",endos.duodenium);
        gotoxy(57,j);
        printf("%s",endos.dbulb);
        gotoxy(66,j);
        printf("%s",endos.biopsy);
        gotoxy(73.5,j);
        printf("%s",endos.comment);
        printf("\n\n\n");
        j++;
      }
      fclose(fe);
      gotoxy(35,25);
      returnToViewMedicalTest();

}
void viewultrasonogram()
{
   /* system("cls");
        printf("This is Delet Medical Test");*/

    int i = 0, j;
    system("cls");
    gotoxy(1,1);
    printf("******************************* View Ultrasonogram ***************************\n");
    gotoxy(1,2);
    printf("ID            Liver              Kidney           Prostet          Spleen      ");
    j=4;
    ful=fopen("ultrasonogram.dat","rb");
    while(fread(&ultrasonogram,sizeof(ultrasonogram),1,ful)==1)
    {
	gotoxy(1,j);
	printf("%d",ultrasonogram.id);
	gotoxy(5,j);
	//printf("%s",patient.pat);
	gotoxy(14,j);
	printf("%s\t",ultrasonogram.liver);
	gotoxy(33,j);
	printf("%s",ultrasonogram.kidney);
	gotoxy(50,j);
	printf("%s",ultrasonogram.prostet);
	gotoxy(67,j);
	printf("%s",ultrasonogram.spleen);
	printf("\n\n\n");
	j++;
	//i = i + book.;
      }
     /* gotoxy(3,25);
      printf("Total Books =%d",i);*/
     fclose(ful);
     gotoxy(33,25);
     returnToViewMedicalTest();


}
void viewxray()
{
    /*system("cls");
        printf("This is Delet Medical Test");*/

        int i = 0, j;
    system("cls");
    gotoxy(1,1);
    printf("******************************* View X-Ray Report ***************************\n");
    gotoxy(1,2);
    printf(" ID                    Which X-ray He or She Do                    Comment     ");
    j=4;
    fx=fopen("xray.dat","rb");
    while(fread(&xray,sizeof(xray),1,fx)==1)
    {
	gotoxy(1,j);
	printf("%d",xray.id);
	gotoxy(5,j);
	//printf("%s",patient.pat);
	gotoxy(25,j);
	printf("%s\t",xray.skull);
	gotoxy(65,j);
	printf("%s",xray.hand);
	/*gotoxy(50,j);
	printf("%s",ultrasonogram.prostet);
	gotoxy(67,j);
	printf("%s",ultrasonogram.spleen);*/
	printf("\n\n\n");
	j++;
	//i = i + book.;
      }
     /* gotoxy(3,25);
      printf("Total Books =%d",i);*/
     fclose(fx);
     gotoxy(33,25);
     returnToViewMedicalTest();

}
void viewvaccination()
{
    /*system("cls");
        printf("This is Delet Medical Test");*/

         int i = 0, j;
    system("cls");
    gotoxy(1,1);
    printf("************************* View Vaccination Report ***************************\n");
    gotoxy(1,2);
    printf(" ID                   Which Vaccin He or She Use                    Comment     ");
    j=4;
    fv=fopen("vaccination.dat","rb");
    while(fread(&vacination,sizeof(vacination),1,fv)==1)
    {
	gotoxy(1,j);
	printf("%d",vacination.id);
	gotoxy(5,j);
	//printf("%s",patient.pat);
	gotoxy(22,j);
	printf("%s\t",vacination.vaccin);
	gotoxy(65,j);
	printf("%s",vacination.comment);
	/*gotoxy(50,j);
	printf("%s",ultrasonogram.prostet);
	gotoxy(67,j);
	printf("%s",ultrasonogram.spleen);*/
	printf("\n\n\n");
	j++;
	//i = i + book.;
      }
     /* gotoxy(3,25);
      printf("Total Books =%d",i);*/
     fclose(fx);
     gotoxy(33,25);
     returnToViewMedicalTest();
}

///////////////////view_________________________________________medical////////////////////////////////////////////////////////


//////////////////////////////////////////////    EDIT PATIENT   ///////////////////////////////////////////////////////////////
void editpatient()
    {
      /*  system("cls");
        printf("This is Edit Patient");*/

        system("cls");
	int c=0;
	int pd,e;
	gotoxy(20,4);
	printf("******** Edit Patient *********");
	char another='y';
	while(another=='y')
	{
		system("cls");
		gotoxy(15,6);
		printf("Enter Patient ID To Be Edited:");
		scanf("%d",&pd);
		fp=fopen("parves.dat","rb+");
		while(fread(&patient,sizeof(patient),1,fp)==1)
		{
			if(checkid(pd)==0)
			{
				gotoxy(15,7);
				printf("The Patient ID is availble");
				gotoxy(15,8);
				printf("The patient ID:%d",patient.id);
				gotoxy(15,9);
				printf("Enter first name:");scanf("%s",patient.f_name);
				gotoxy(15,10);
				printf("Enter middle name:");scanf("%s",patient.m_name);
				gotoxy(15,11);
				printf("Enter last name:");scanf("%s",&patient.l_name);
				gotoxy(15,12);
				printf("Enter age:");scanf("%f",&patient.age);
				gotoxy(15,13);
				printf("Enter sex:");scanf("%s",&patient.sex);
				gotoxy(15,14);
				printf("Which Medical Test He or She Checkup:");scanf("%s",&patient.medical);
				gotoxy(15,15);
				printf("The record is modified");
				fseek(fp,ftell(fp)-sizeof(patient),0);
				fwrite(&patient,sizeof(patient),1,fp);
				fclose(fp);
				c=1;
			}
			if(c==0)
			{
				gotoxy(15,9);
				printf("Patient ID not found");
			}
		}
		gotoxy(15,16);
		printf("Modify another Record?(Y/N)");
		fflush(stdin);
		another=getch() ;
	}
		returnToMainMenu();

    }
 ////////////////////////////////////////////_______________ Edit Patient___________________/////////////////////////////////////////////////

 ///////////////////////////////////////////////////   EDIT MADICAL TEST  /////////////////////////////////////////////////////////////////
 void editmedical()
{
        /*system("cls");
        printf("This is Edit Medical Test");*/

          system("cls");
    int vm;
    gotoxy(20, 3);
    printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
    gotoxy(20,5);
    printf("************** SELECT EDIT MEDICAL TEST **************");
    gotoxy(28,7);
    printf(" 1. Edit Blood Test");
    gotoxy(28,9);
    printf(" 2. Edit Pathology");
    gotoxy(28,11);
	printf(" 3. Edit Endoscopy");
	gotoxy(28,13);
	printf(" 4. Edit Ulatrasonogram");
	gotoxy(28,15);
	printf(" 5. Edit X-ray");
	gotoxy(28,17);
	printf(" 6. Edit Vaccination");
	gotoxy(28,19);
	printf(" 7. Back to main menu");
	gotoxy(20,22);
	printf("************************************************");
	gotoxy(20,25);
	printf("Enter your choice:");
    scanf("%d",&vm);
    if(vm==1)
    {
        editbloodtest();
    }

    else if(vm==2)
    {
        editpathology();
    }
    else if(vm==3)
    {
        editendoskopy();
    }
    else if(vm==4)
    {
        editultrasonogram();
    }
    else if(vm==5)
    {
        editxray();
    }
    else if(vm==6)
    {
        editvaccination();
    }
    else if(vm==7)
    {
        mainmenu();
    }
    else
    {
        editmedical();
    }



}
//////////////////////////// Edit Blood Test /////////////////////////////
    void editbloodtest()
    {
       /* system("cls");
        printf("This is Delet Medical Test");*/
        system("cls");
	int c=0;
	int ebd,e;
	gotoxy(20,4);
	printf("***** Edit Blood Test *****");
	char another='y';
	while(another=='y')
	 {
		system("cls");
		gotoxy(15,6);
		printf("Enter Patient ID For Blood Test Edit:");
		scanf("%d",&ebd);
		fb=fopen("bloodtest.dat","rb+");
		while(fread(&bloodtest,sizeof(bloodtest),1,fb)==1)
		{
			if(checkbid(ebd)==0)
			{
				gotoxy(15,7);
				printf("The patient ID is availble");
				gotoxy(15,9);
				printf("The Patient ID:%d",bloodtest.id);
				gotoxy(15,11);
				printf("Enter group:");scanf("%s",bloodtest.group);
				gotoxy(15,13);
				printf("Enter Suger Fasting (mmol/l.):");scanf("%f",&bloodtest.sugerf);
				/*gotoxy(15,14);
				scanf("%f.2",bloodtest.sugerf);*/
				gotoxy(15,14);
				printf("Enter Sugar Random (mmol/l.):");scanf("%f",&bloodtest.sugerr);
				/*gotoxy(15,16);
				scanf("%f",&bloodtest.sugerr);*/
				gotoxy(15,15);
				printf("Enter Blood Urea (mg/dl.):");scanf("%f",&bloodtest.blooduria);
				gotoxy(15,16);
				printf("Enter S.  Protin (gm/L.):");scanf("%f",&bloodtest.totalprotin);
				gotoxy(15,17);
				printf("Enter S.Cholestrol (mg/dl.):");scanf("%f",&bloodtest.cholestrol);
				gotoxy(15,18);
				printf("Enter S. Bilirubin (mg/dl.):");scanf("%f",&bloodtest.bilirubin);
				gotoxy(15,19);
				printf("Enter HBsAG Negative/Positive:");scanf("%s",bloodtest.hbsag);
				gotoxy(15,21);
				printf("The record is modified");
				//return 0;
				fseek(fb,ftell(fb)-sizeof(bloodtest),0); ///////////////
				fwrite(&bloodtest,sizeof(bloodtest),1,fb);
				fclose(fb);
				c=1;
				//return 0;
			}


			if(c==0)
			{
				gotoxy(15,8);
				printf("No record found");
			}
		}
		gotoxy(15,23);
		printf("Modify another Record?(Y/N)");
		fflush(stdin);
		another=getch() ;
	 }
		returnToMainMenu();
    }
     /////////////////________Edit Blood Test _________//////////////////

    ///////////////////////////  Edit Pathology     ////////////////////////
    void editpathology()
    {
       /* system("cls");
        printf("This is Delet Medical Test");*/
        system("cls");
    int lg;
    gotoxy(20, 3);
    printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
    gotoxy(20,5);
    printf("************** SELECT FOR EDIT PATHOLOGY TEST **************");
    gotoxy(29,7);
    printf("1. Edit Urin Test");
    gotoxy(29,9);
    printf("2. Edit Stool Test");
    gotoxy(28,11);
	printf(" 3. Go Back");
	gotoxy(28,13);
	printf(" 4. Back to main menu");
	gotoxy(20,16);
	printf("************************************************");
	gotoxy(20,18);
	printf("Enter your choice:");
    scanf("%d",&lg);
    if(lg==1)
    {
        editurinetest();
    }

    else if(lg==2)
    {
        editstooltest();
    }
    else if(lg==3)
    {
        editmedical();
    }
    else if(lg==4)
    {
        mainmenu();
    }
    else
    {
        mainmenu();
    }

   }

    /////////////////////// Edit Urin Test ////////////////////////////////
    void editurinetest()
    {
        /*system("cls");
        printf("This is Delet Medical Test");*/
            system("cls");
	int c=0;
	int eud,e;
	gotoxy(20,4);
	printf("**** Edit Urin Test ****");
	char another='y';
	while(another=='y')
	 {
		system("cls");
		gotoxy(15,6);
		printf("Enter Patient Id For Edit Urin Test:");
		scanf("%d",&eud);
		fu=fopen("urin.dat","rb+");
		while(fread(&urin,sizeof(urin),1,fu)==1)
		{
			if(checkuid(eud)==0)
			{
				gotoxy(15,7);
				printf("The patient ID is availble");
				gotoxy(15,8);
				printf("The Patient ID:%d",urin.id);
				gotoxy(15,9);
				printf("Enter Valume (c.c):");scanf("%f",&urin.volume);
				gotoxy(15,10);
				printf("Enter Reaction:");scanf("%s",&urin.reaction);
				gotoxy(15,11);
				printf("Enter Alubumin:");scanf("%s",&urin.alubumin);
				gotoxy(15,12);
				printf("Enter Sugar:");scanf("%s",&urin.sugar);
				gotoxy(15,13);
				printf("Enter Blood:");scanf("%s",&urin.blad);
				gotoxy(15,14);
				printf("Enter Calcium Oxalet:");scanf("%s",&urin.calsiamoxalet);
				gotoxy(15,15);
				printf("Enter Uric Asid:");scanf("%s",&urin.uricasid);
				gotoxy(15,16);
				printf("Enter Epithelial Cells:");scanf("%s",urin.epithelialcell);
				gotoxy(15,17);
				printf("The record is modified");
				fseek(fu,ftell(fu)-sizeof(urin),0);
				fwrite(&urin,sizeof(urin),1,fu);
				fclose(fu);
				c=1;
			}
			if(c==0)
			{
				gotoxy(15,10);
				printf("No record found");
			}
		}
		gotoxy(15,19);
		printf("Modify another Record?(Y/N)");
		fflush(stdin);
		another=getch() ;
     }
		returnToMainMenu();

    }
    /////////////////_____ Edit Urin Test _________///////////////////////

    /////////////////////// Edit Stool Tast /////////////////////////////
    void editstooltest()
    {
        /*system("cls");
        printf("This is Delet Medical Test");*/
           system("cls");
	int c=0;
	int esd,e;
	gotoxy(20,4);
	printf("**** Edit Urin Test ****");
	char another='y';
	while(another=='y')
	  {
		system("cls");
		gotoxy(15,6);
		printf("Enter Patient Id For Edit Urin Test:");
		scanf("%d",&esd);
		fs=fopen("stool.dat","rb+");
		while(fread(&stool,sizeof(stool),1,fs)==1)
		{
			if(checkstid(esd)==0)
			{
				gotoxy(15,7);
				printf("The patient ID is availble");
				gotoxy(15,8);
				printf("The Patient ID:%d",stool.id);
				gotoxy(15,9);
				printf("Enter Valume (c.c):");scanf("%f",&stool.volume);
				gotoxy(15,10);
				printf("Enter Reaction:");scanf("%s",stool.reaction);
				gotoxy(15,11);
				printf("Enter Alubumin:");scanf("%s",stool.alubumin);
				gotoxy(15,12);
				printf("Enter Sugar:");scanf("%s",stool.sugar);
				gotoxy(15,13);
				printf("Enter Blood:");scanf("%s",stool.blad);
				gotoxy(15,14);
				printf("Enter Calcium Oxalet:");scanf("%s",stool.calsiamoxalet);
				gotoxy(15,15);
				printf("Enter Uric Asid:");scanf("%s",stool.uricasid);
				gotoxy(15,16);
				printf("Enter Epithelial Cells:");scanf("%s",stool.epithelialcell);
				gotoxy(15,17);
				printf("The record is modified");
				fseek(fs,ftell(fs)-sizeof(stool),0);
				fwrite(&stool,sizeof(stool),1,fs);
				fclose(fs);
				c=1;
			}
			if(c==0)
			{
				gotoxy(15,10);
				printf("No Record Found");
			}
		}
		gotoxy(15,19);
		printf("Modify Another Record?(Y/N)");
		fflush(stdin);
		another=getch() ;
      }
		returnToMainMenu();
    }
    ///////////////________ Edit Stool Test _______//////////////////////

//////////////////////_______________Edit pathology____________////////////////////////////

////////////////////////////////////////// Edit Endoscopy /////////////////////////////////
    void editendoskopy()
    {
              system("cls");
	int c=0;
	int eend,e;
	gotoxy(20,4);
	printf("****** Edit Endoscopy ******");
	char another='y';
	while(another=='y')
	  {
		system("cls");
		gotoxy(15,6);
		printf("Enter Patient Id For Edit Endoscopy:");
		scanf("%d",&eend);
		fe=fopen("endoscopy.dat","rb+");
		while(fread(&endos,sizeof(endos),1,fe)==1)
		{
			if(checkendosid(eend)==0)
			{
				gotoxy(15,7);
				printf("The patient ID is availble");
				gotoxy(15,8);
				printf("The Patient ID :%d",endos.id);
				gotoxy(15,9);
				printf("Enter OESOPHAGUS :");scanf("%s",endos.oesop);
				gotoxy(15,10);
				printf("Enter STOMAC :");scanf("%s",endos.stomac);
				gotoxy(15,11);
				printf("Enter FUNDS :");scanf("%s",endos.funds);
				gotoxy(15,12);
				printf("Enter ANTRUM :");scanf("%s",endos.antrum);
				gotoxy(15,13);
				printf("Enter DUODENUM :");scanf("%s",endos.duodenium);
				gotoxy(15,14);
				printf("Enter D-BULB :");scanf("%s",endos.dbulb);
				gotoxy(15,15);
				printf("Enter Need BIOPSY :");scanf("%s",endos.biopsy);
				gotoxy(15,16);
				printf("Enter COMMENT :");scanf("%s",endos.comment);
				gotoxy(15,18);
				printf("The record is modified");
				fseek(fe,ftell(fe)-sizeof(endos),0);
				fwrite(&endos,sizeof(endos),1,fe);
				fclose(fe);
				c=1;
			}
			if(c==0)
			{
				gotoxy(15,10);
				printf("No Record Found");
			}
		}
		gotoxy(15,20);
		printf("Modify Another Record?(Y/N)");
		fflush(stdin);
		another=getch() ;
      }
		returnToMainMenu();
    }
/////////////////////______________Edit Endoscopy____________//////////////////////////////

    void editultrasonogram()
    {
        system("cls");
	int c=0;
	int ultd,e;
	gotoxy(20,4);
	printf("**** Edit Ultrasonogram ****");
	char another='y';
	while(another=='y')
	  {
		system("cls");
		gotoxy(15,6);
		printf("Enter Patient ID to be edited:");
		scanf("%d",&ultd);
		ful=fopen("ultrasonogram.dat","rb+");
		while(fread(&ultrasonogram,sizeof(ultrasonogram),1,ful)==1)
		{
			if(checkultraid(ultd)==0)
			{
				gotoxy(15,7);
				printf("The Ptient ID is availble");
				gotoxy(15,8);
				printf("The Patient ID:%d",ultrasonogram.id);
				gotoxy(15,9);
				printf("Enter Liver:");scanf("%s",ultrasonogram.liver);
				gotoxy(15,10);
				printf("Enter Kidney:");scanf("%s",ultrasonogram.kidney);
				gotoxy(15,11);
				printf("Enter Prostet:");scanf("%s",ultrasonogram.prostet);
				gotoxy(15,12);
				printf("Enter Spleen:");scanf("%s",ultrasonogram.spleen);
				/*gotoxy(15,13);
				printf("Enter new rackno:");scanf("%d",&ultrasonogram.rackno);*/
				gotoxy(15,14);
				printf("The record is modified");
				fseek(ful,ftell(ful)-sizeof(ultrasonogram),0);
				fwrite(&ultrasonogram,sizeof(ultrasonogram),1,ful);
				fclose(ful);
				c=1;
			}
			if(c==0)
			{
				gotoxy(15,9);
				printf("No record found");
			}
        }
		gotoxy(15,16);
		printf("Modify another Record?(Y/N)");
		fflush(stdin);
		another=getch() ;
	  }
		returnToMainMenu();
    }

    void editxray()
    {
        system("cls");
	int c=0;
	int xryd,e;
	gotoxy(20,4);
	printf("**** Edit X-ray ****");
	char another='y';
	while(another=='y')
	{
		system("cls");
		gotoxy(15,6);
		printf("Enter Patient ID to be edited:");
		scanf("%d",&xryd);
		fx=fopen("xray.dat","rb+");
		while(fread(&xray,sizeof(xray),1,fx)==1)
		{
			if(checkxrayid(xryd)==0)
			{
				gotoxy(15,7);
				printf("The Patient ID is availble");
				gotoxy(15,8);
				printf("The Book ID:%d",xray.id);
				gotoxy(15,9);
				printf("Enter X-ray name:");scanf("%s",xray.skull);
				gotoxy(15,10);
				printf("Enter Comment:");scanf("%s",xray.hand);
				/*gotoxy(15,11);
				printf("Enter new quantity:");scanf("%d",&xray.quantity);*/
				/*gotoxy(15,12);
				printf("Enter new price:");scanf("%f",&xray.Price);
				gotoxy(15,13);
				printf("Enter new rackno:");scanf("%d",&xray.rackno);*/
				gotoxy(15,14);
				printf("The record is modified");
				fseek(fx,ftell(fx)-sizeof(xray),0);
				fwrite(&xray,sizeof(xray),1,fx);
				fclose(fx);
				c=1;
			}
			if(c==0)
			{
				gotoxy(15,9);
				printf("No record found");
			}
		}
		gotoxy(15,16);
		printf("Modify another Record?(Y/N)");
		fflush(stdin);
		another=getch() ;
	}
		returnToMainMenu();
    }

    void editvaccination()
    {
       system("cls");
	int c=0;
	int vcd,e;
	gotoxy(20,4);
	printf("**** Edit X-ray ****");
	char another='y';
	while(another=='y')
	{
		system("cls");
		gotoxy(15,6);
		printf("Enter Patient ID to be edited:");
		scanf("%d",&vcd);
		fv=fopen("vaccination.dat","rb+");
		while(fread(&vacination,sizeof(vacination),1,fv)==1)
		{
			if(checkvaccinationid(vcd)==0)
			{
				gotoxy(15,7);
				printf("The Patient ID is availble");
				gotoxy(15,8);
				printf("The Patient ID:%d",vacination.id);
				gotoxy(15,9);
				printf("Enter Vaccin name:");scanf("%s",vacination.vaccin);
				gotoxy(15,10);
				printf("Enter Comment:");scanf("%s",vacination.comment);
				/*gotoxy(15,11);
				printf("Enter new quantity:");scanf("%d",&xray.quantity);*/
				/*gotoxy(15,12);
				printf("Enter new price:");scanf("%f",&xray.Price);
				gotoxy(15,13);
				printf("Enter new rackno:");scanf("%d",&xray.rackno);*/
				gotoxy(15,14);
				printf("The record is modified");
				fseek(fv,ftell(fv)-sizeof(vacination),0);
				fwrite(&vacination,sizeof(vacination),1,fv);
				fclose(fv);
				c=1;
			}
			if(c==0)
			{
				gotoxy(15,9);
				printf("No record found");
			}
		}
		gotoxy(15,16);
		printf("Modify another Record?(Y/N)");
		fflush(stdin);
		another=getch() ;
	}
		returnToMainMenu();
    }

//////////////////////////////////////_______________ EDIT MEDICAL TEST ___________________//////////////////////////////////////////////////


////////////////////////////////////////////////  SEARCH PATIENT  //////////////////////////////////////////////////////////////////////////////
void searchpatient()
    {
       /* system("cls");
        printf("This is Search Patient");*/
        system("cls");
    int findpatient = 0;
    gotoxy(20,6);
    int patientId;
    printf("*************** Search Patient ****************");
    gotoxy(30,10);
    printf(" 1. Search By ID");
    gotoxy(30,12);
    printf(" 2. Search By Name");
    gotoxy( 20,14);
    printf("Enter Your Choice");
    fp=fopen("parves.dat","rb"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
    switch(getch())
    {
	  case '1':
	{
	    system("cls");
	    gotoxy(25,3);
	    printf("**** Search Patient By ID ****");
	    gotoxy(20,5);
	    printf("Enter the patient ID:");
	    scanf("%d",&patientId);
	    while(fread(&patient,sizeof(patient),1,fp)==1)
	    {
		if(patient.id==patientId)
		{
		    gotoxy(20,7);
		    printf("The patient ID is available");
		    gotoxy(20,8);
		    printf("*****************************");
		    gotoxy(20,9);
		    printf(" ID:%d",patient.id);
		    gotoxy(20,10);
		    printf(" First Name:%s",patient.f_name);
		    gotoxy(20,11);
		    printf(" Middle Name:%s ",patient.m_name);
		    gotoxy(20,12);
		    printf(" Last Name:%s ",patient.l_name);
		    gotoxy(20,13);
		    printf(" Age:%f",patient.age);
		    gotoxy(20,14);
		    printf(" Sex:%s ",patient.sex);
		    gotoxy(20,15);
		    printf(" Which Medical Test He or She Checkup:%s ",patient.medical);
		    gotoxy(20,16);
		    printf("*****************************************");
		    findpatient=1;
		}
	    }
	    if(findpatient!=1)  //checks whether conditiion enters inside loop or not
	    {
	    gotoxy(22,9);
	    printf("\aNo Record Found");
	    }
	    gotoxy(20,18);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    searchpatient();
	    else
	    mainmenu();
	    break;
	}
	case '2':
	{
	    char patientNameFromUser[50];
	    system("cls");
	    gotoxy(25,3);
	    printf("**** Search Patient By Name ****");
	    gotoxy(20,5);
	    printf("Enter Patient First Name:");
	    scanf("%s",patientNameFromUser);
	    int d=0;
	    while(fread(&patient,sizeof(patient),1,fp)==1)
	    {
		if(strcmp(patient.f_name, patientNameFromUser)==0) //checks whether a.name is equal to s or not
		{
		    gotoxy(20,7);
		    printf("The Patient is available");
		    gotoxy(20,8);
		    printf("******************************");
		    gotoxy(20,9);
		    printf(" ID:%d",patient.id);
		    gotoxy(20,10);
		    printf(" First Name:%s",patient.f_name);
		    gotoxy(20,11);
		    printf(" Middle Name:%s ",patient.m_name);
		    gotoxy(20,12);
		    printf(" Last Name:%s ",patient.l_name);
		    gotoxy(20,13);
		    printf(" Age:%f",patient.age);
		    gotoxy(20,14);
		    printf(" Sex:%s ",patient.sex);
		    gotoxy(20,15);
		    printf(" Which Medical Test He or She Checkup:%s ",patient.medical);
		    gotoxy(20,16);
		    printf("******************************");
		    d++;
		}

	    }
	    if(d==0)
	    {
	    gotoxy(22,9);
	    printf("\aNo Record Found");
	    }
	    gotoxy(20,18);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    searchpatient();
	    else
	    mainmenu();
	    break;
	}
	default :
	getch();
	searchpatient();
    }
    fclose(fp);

    }

////////////////////////////////_______________________ SEARCH PATIENT ______________________///////////////////////////////////////////////


////////////////////////////////////////////////// SEARCH  MEDICAL TEST  ///////////////////////////////////////////////////
void searchmedical()
{
   /* system("cls");
        printf("This is Search Medical Test");*/
    system("cls");
    int sm;
    gotoxy(20, 3);
    printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
    gotoxy(20,5);
    printf("************ SELECT FOR SEARCH MEDICAL TEST ************");
    gotoxy(28,7);
    printf(" 1. Search Blood Test");
    gotoxy(28,9);
    printf(" 2. Search Pathology");
    gotoxy(28,11);
	printf(" 3. Search Endoscopy");
	gotoxy(28,13);
	printf(" 4. Search Ultrasonogram");
	gotoxy(28,15);
	printf(" 5. Search X-ray");
	gotoxy(28,17);
	printf(" 6. Search Vaccination");
	gotoxy(28,19);
	printf(" 7. Back to main menu");
	gotoxy(20,22);
	printf("************************************************");
	gotoxy(20,25);
	printf("Enter your choice:");
    scanf("%d",&sm);
    if(sm==1)
    {
        searchbloodtest();
    }

    else if(sm==2)
    {
        searchpathology();
    }
    else if(sm==3)
    {
        searchendoskopy();
    }
    else if(sm==4)
    {
        searchultrasonogram();
    }
    else if(sm==5)
    {
        searchxray();
    }
    else if(sm==6)
    {
        searchvaccination();
    }
    else if(sm==7)
    {
        mainmenu();
    }
    else
    {
        mainmenu();
    }
}
////////////////////////////////////////////////// Search Blood Test ///////////////////////////////
     void searchbloodtest()
     {
         system("cls");

        	//////////

        int findblood = 0;

         int bloodId;

         fb=fopen("bloodtest.dat","rb"); //open file for reading propose
         rewind(fb);   //move pointer at the begining of file

           /////////

	    gotoxy(25,3);
	    printf("**** Search Blood Test By ID ****");
	    gotoxy(20,5);
	    printf("Enter the Patient ID:");
	    scanf("%d",&bloodId);
	    while(fread(&bloodtest,sizeof(bloodtest),1,fb)==1)
	    {
		if(bloodtest.id==bloodId)
		{
		    gotoxy(20,7);
		    printf("The Patient ID is available");
		    gotoxy(20,8);
		    printf("*****************************");
		    gotoxy(20,9);
		    printf(" ID:%d",bloodtest.id);
		    gotoxy(20,10);
		    printf(" Blood Group : %s",bloodtest.group);
		    gotoxy(20,11);
		    printf(" Suger Fasting ? mmol/l.: %.2f ",bloodtest.sugerf);
		    gotoxy(20,12);
		    printf(" Sugar Random ? mmol/l. : %.2f ",bloodtest.sugerr);
		    gotoxy(20,13);
		    printf(" Blood Urea   ? mg/dl.  : %.2f",bloodtest.blooduria);
		    gotoxy(20,14);
		    printf(" S.  Protin   ? gm/L.   : %.2f ",bloodtest.totalprotin);
		    gotoxy(20,15);
		    printf(" S.Cholestrol ? mg/dl.  : %.2f",bloodtest.cholestrol);
		    gotoxy(20,16);
		    printf(" S. Bilirubin ? mg/dl.  : %.2f ",bloodtest.bilirubin);
		    gotoxy(20,17);
		    printf(" HBsAG Negative/Positive:%s ",bloodtest.hbsag);
		    gotoxy(20,18);
		    printf("*****************************");
		    findblood=1;
		}
	    }
	    if(findblood!=1)  //checks whether conditiion enters inside loop or not
	    {
	    gotoxy(22,11);
	    printf("\aNo Record Found");
	    }
	    gotoxy(20,20);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    searchbloodtest();
	    else
	    searchmedical();
	   // break;

	    ////////////////
	    fclose(fb);
	    ///////////////


     }
////////////////////////////////////////________ Search Blood Test ______//////////////////////////

////////////////////////////////////   Search Pathology   //////////////////////////////
    void searchpathology()
    {
        /*system("cls");
        printf("This is Search Medical Test");*/
        system("cls");
    int slg;
    gotoxy(20, 3);
    printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 LIFE DIAGNOSTIC CENTRE LTD. \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
    gotoxy(20,5);
    printf("************ SELECT FOR SEARCH PATHOLOGY TEST ************");
    gotoxy(29,7);
    printf("1. Search Urin Test");
    gotoxy(29,9);
    printf("2. Search Stool Test");
	gotoxy(28,12);
	printf(" 3. Go Back");
	gotoxy(20,16);
	printf("************************************************");
	gotoxy(20,18);
	printf("Enter your choice:");
    scanf("%d",&slg);
    if(slg==1)
    {
        searchurinetest();
    }

    else if(slg==2)
    {
        searchstooltest();
    }
    else if(slg==3)
    {
        searchmedical();
    }
    else
    {
        mainmenu();
    }
    }

/////////////////////// Search Urin Test /////////////////////
        void searchurinetest()
        {
            system("cls");

        	//////////

         int findurin = 0;

         int urinId;

         fu=fopen("urin.dat","rb"); //open file for reading propose
         rewind(fu);   //move pointer at the begining of file

           /////////

	    gotoxy(25,3);
	    printf("**** Search Urin Test By ID ****");
	    gotoxy(20,5);
	    printf("Enter the Patient ID:");
	    scanf("%d",&urinId);
	    while(fread(&urin,sizeof(urin),1,fu)==1)
	    {
		if(urin.id==urinId)
		{
		    gotoxy(20,7);
		    printf("The Patient ID is available");
		    gotoxy(20,8);
		    printf("*****************************");
		    gotoxy(20,9);
		    printf(" ID:%d",urin.id);
		    gotoxy(20,10);
		    printf(" Valume (c.c) : %.2f",urin.volume);
		    gotoxy(20,11);
		    printf(" Reaction : %s ",urin.reaction);
		    gotoxy(20,12);
		    printf(" Alubumin : %s ",urin.alubumin);
		    gotoxy(20,13);
		    printf(" Sugar    : %s ",urin.sugar);
		    gotoxy(20,14);
		    printf(" Blood    : %s ",urin.blad);
		    gotoxy(20,15);
		    printf(" Calcium Oxalet : %s ",urin.calsiamoxalet);
		    gotoxy(20,16);
		    printf(" Uric Asid : %s ",urin.uricasid);
		    gotoxy(20,17);
		    printf(" Epithelial Cells :%s ",urin.epithelialcell);
		    gotoxy(20,18);
		    printf("*****************************");
		    findurin=1;
		}
	    }
	    if(findurin!=1)  //checks whether conditiion enters inside loop or not
	    {
	    gotoxy(22,11);
	    printf("\aNo Record Found");
	    }
	    gotoxy(20,20);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    searchurinetest();
	    else
	    searchmedical();
	   // break;

	    ////////////////
	    fclose(fu);
	    ///////////////
        }
//////////////____ Search Urin Test ______//////////////////

//////////////////// Search Stool Test ///////////////////
        void searchstooltest()
        {
            system("cls");

        	//////////

         int findstool = 0;

         int stoolId;

         fs=fopen("stool.dat","rb"); //open file for reading propose
         rewind(fs);   //move pointer at the begining of file

           /////////

	    gotoxy(25,3);
	    printf("**** Search Stool Test By ID ****");
	    gotoxy(20,5);
	    printf("Enter the Patient ID:");
	    scanf("%d",&stoolId);
	    while(fread(&stool,sizeof(stool),1,fs)==1)
	    {
		if(stool.id==stoolId)
		{
		    gotoxy(20,7);
		    printf("The Patient ID is available");
		    gotoxy(20,8);
		    printf("*****************************");
		    gotoxy(20,9);
		    printf(" ID:%d",stool.id);
		    gotoxy(20,10);
		    printf(" Valume (c.c) : %.2f",stool.volume);
		    gotoxy(20,11);
		    printf(" Reaction : %s ",stool.reaction);
		    gotoxy(20,12);
		    printf(" Alubumin : %s ",stool.alubumin);
		    gotoxy(20,13);
		    printf(" Sugar    : %s ",stool.sugar);
		    gotoxy(20,14);
		    printf(" Blood    : %s ",stool.blad);
		    gotoxy(20,15);
		    printf(" Calcium Oxalet : %s ",stool.calsiamoxalet);
		    gotoxy(20,16);
		    printf(" Uric Asid : %s ",stool.uricasid);
		    gotoxy(20,17);
		    printf(" Epithelial Cells :%s ",stool.epithelialcell);
		    gotoxy(20,18);
		    printf("*****************************");
		    findstool=1;
		}
	    }
	    if(findstool!=1)  //checks whether conditiion enters inside loop or not
	    {
	    gotoxy(22,11);
	    printf("\aNo Record Found");
	    }
	    gotoxy(20,20);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    searchstooltest();
	    else
	    searchmedical();
	   // break;

	    ////////////////
	    fclose(fs);
	    //////////////
        }
//////////////_____ Search Stool Test _____/////////////

///////////////////////////  Search Endoscopy  ///////////////////////////////
    void searchendoskopy()
    {
        system("cls");

        	//////////

         int findendos = 0;

         int endosId;

         fe=fopen("endoscopy.dat","rb"); //open file for reading propose
         rewind(fe);   //move pointer at the begining of file

           /////////

	    gotoxy(25,3);
	    printf("*********** Search Endoscopy  By ID ***********");
	    gotoxy(20,5);
	    printf("Enter the Patient ID:");
	    scanf("%d",&endosId);
	    while(fread(&endos,sizeof(endos),1,fe)==1)
	    {
		if(endos.id==endosId)
		{
		    gotoxy(20,7);
		    printf("The Patient ID is available");
		    gotoxy(20,8);
		    printf("*****************************");
		    gotoxy(20,9);
		    printf(" ID:%d",endos.id);
		    gotoxy(20,10);
		    printf(" OESOPHAGUS : %s",endos.oesop);
		    gotoxy(20,11);
		    printf(" STOMAC : %s ",endos.stomac);
		    gotoxy(20,12);
		    printf(" FUNDS : %s ",endos.funds);
		    gotoxy(20,13);
		    printf(" ANTRUM : %s ",endos.antrum);
		    gotoxy(20,14);
		    printf(" DUODENUM : %s ",endos.duodenium);
		    gotoxy(20,15);
		    printf(" D-BULB : %s ",endos.dbulb);
		    gotoxy(20,16);
		    printf(" Need BIOPSY : %s ",endos.biopsy);
		    gotoxy(20,17);
		    printf(" COMMENT :%s ",endos.comment);
		    gotoxy(20,18);
		    printf("*****************************");
		    findendos=1;
		}
	    }
	    if(findendos!=1)  //checks whether conditiion enters inside loop or not
	    {
	    gotoxy(22,11);
	    printf("\aNo Record Found");
	    }
	    gotoxy(20,20);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    searchendoskopy();
	    else
	    searchmedical();
	   // break;

	    ////////////////
	    fclose(fe);
	    //////////////
    }
////////////////////////_______ Search Endoscopy ________////////////////////////

////////////////////////  Search Ultrasonogram  ////////////////////////////////
    void searchultrasonogram()
    {
        system("cls");

        	//////////

         int findultra = 0;

         int ultraId;

         ful=fopen("ultrasonogram.dat","rb"); //open file for reading propose
         rewind(ful);   //move pointer at the begining of file

           /////////

	    gotoxy(25,3);
	    printf("*********** Search Ultrasonogram  By ID ************");
	    gotoxy(20,5);
	    printf("Enter the Patient ID:");
	    scanf("%d",&ultraId);
	    while(fread(&ultrasonogram,sizeof(ultrasonogram),1,ful)==1)
	    {
		if(ultrasonogram.id==ultraId)
		{
		    gotoxy(20,7);
		    printf("The Patient ID is available");
		    gotoxy(20,8);
		    printf("*****************************");
		    gotoxy(20,9);
		    printf(" ID:%d",ultrasonogram.id);
		    gotoxy(20,10);
		    printf(" LIVER : %s",ultrasonogram.liver);
		    gotoxy(20,12);
		    printf(" KIDNEY : %s ",ultrasonogram.kidney);
		    gotoxy(20,14);
		    printf(" PROSTET : %s ",ultrasonogram.prostet);
		    gotoxy(20,16);
		    printf(" SPLEEN : %s ",ultrasonogram.spleen);

		    gotoxy(20,18);
		    printf("*****************************");
		    findultra=1;
		}
	    }
	    if(findultra!=1)  //checks whether conditiion enters inside loop or not
	    {
	    gotoxy(22,11);
	    printf("\aNo Record Found");
	    }
	    gotoxy(20,20);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    searchultrasonogram();
	    else
	    searchmedical();
	   // break;

	    ////////////////
	    fclose(ful);
	    //////////////
    }
///////////////////_______ Search Ultrasonogram ______///////////////////////

/////////////////////////  Search  X-ray     ///////////////////////////////
    void searchxray()
    {
        system("cls");

        	//////////

         int findxray = 0;

         int xrayId;

         fx=fopen("xray.dat","rb"); //open file for reading propose
         rewind(fx);   //move pointer at the begining of file

           /////////

	    gotoxy(25,3);
	    printf("*********** Search X-ray  By ID ************");
	    gotoxy(20,5);
	    printf("Enter the Patient ID:");
	    scanf("%d",&xrayId);
	    while(fread(&xray,sizeof(xray),1,fx)==1)
	    {
		if(xray.id==xrayId)
		{
		    gotoxy(20,7);
		    printf("The Patient ID is available");
		    gotoxy(20,8);
		    printf("*****************************");
		    gotoxy(20,10);
		    printf(" ID:%d",xray.id);
		    gotoxy(20,13);
		    printf(" Which X-ray he or she do : %s",xray.skull);
		    gotoxy(20,16);
		    printf(" Comment : %s ",xray.hand);

		    gotoxy(20,18);
		    printf("*****************************");
		    findxray=1;
		}
	    }
	    if(findxray!=1)  //checks whether conditiion enters inside loop or not
	    {
	    gotoxy(22,11);
	    printf("\aNo Record Found");
	    }
	    gotoxy(20,20);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    searchxray();
	    else
	    searchmedical();
	   // break;

	    ////////////////
	    fclose(fx);
	    //////////////
    }
//////////////////////////////__________ Search  X-ray ________________//////////////////////////////

/////////////////////////////  Search Vaccination ///////////////////////////////////////
    void searchvaccination()
    {
      system("cls");

        	//////////

         int findvaccin = 0;

         int vaccinId;

         fv=fopen("vaccination.dat","rb"); //open file for reading propose
         rewind(fv);   //move pointer at the begining of file

           /////////

	    gotoxy(25,3);
	    printf("*********** Search Vaccination  By ID ************");
	    gotoxy(20,5);
	    printf("Enter the Patient ID:");
	    scanf("%d",&vaccinId);
	    while(fread(&vacination,sizeof(vacination),1,fv)==1)
	    {
		if(vacination.id==vaccinId)
		{
		    gotoxy(20,7);
		    printf("The Patient ID is available");
		    gotoxy(20,8);
		    printf("*****************************");
		    gotoxy(20,10);
		    printf(" ID:%d",vacination.id);
		    gotoxy(20,13);
		    printf(" Which Vaccin he or she use : %s",vacination.vaccin);
		    gotoxy(20,16);
		    printf(" Comment : %s ",vacination.comment);

		    gotoxy(20,18);
		    printf("*****************************");
		    findvaccin=1;
		}
	    }
	    if(findvaccin!=1)  //checks whether conditiion enters inside loop or not
	    {
	    gotoxy(22,11);
	    printf("\aNo Record Found");
	    }
	    gotoxy(20,20);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    searchvaccination();
	    else
	    searchmedical();
	   // break;

	    ////////////////
	    fclose(fv);
	    //////////////
    }
//////////////////______________ Search Vaccination _____________////////////////////////


//////////////////////////////////__________________________ Search Medical _________________________///////////////////////////////////////////


//////////////////////////////////////////      DELETE   /////////////////////////////////////////////////////////////
void deletepatient()
    {
       /* system("cls");
        printf("This is Delete Patient");*/

    char findpatient;
    system("cls");
    int dd;
    char another='y';
    while(another=='y')  //infinite loop
    {
	system("cls");
	gotoxy(10,5);
	printf("Enter the Patient ID to  delete:");
	scanf("%d",&dd);
	fp=fopen("parves.dat","rb");
	rewind(fp);
	while(fread(&patient,sizeof(patient),1,fp)==1)
	{
	    if(patient.id==dd)
	    {
		gotoxy(10,7);
		printf("The patient ID is available");
		gotoxy(10,8);
		printf("First name : %s",patient.f_name);
		gotoxy(10,9);
		printf("Middle name: %s",patient.m_name);
		gotoxy(10,10);
		printf("Last name  : %s",patient.l_name);
		gotoxy(10,11);
		printf("Age        : %f",patient.age);
		gotoxy(10,12);
		printf("Sex        : %s",patient.sex);

		findpatient='t';
	    }
	}
	if(findpatient=='t' )
	{
	    gotoxy(10,14);
	    printf("Do you want to delete it?(Y/N):");
	    if(getch()=='y')
	    {
		ft=fopen("test.dat","wb");  //temporary file for delete
		rewind(fp);
		while(fread(&patient,sizeof(patient),1,fp)==1)
		{
		    if(patient.id!=dd)
		    {
			fseek(ft,0,SEEK_CUR);
			fwrite(&patient,sizeof(patient),1,ft); //write all in tempory file except that
		    }                              //we want to delete
		}
		fclose(ft);
		fclose(fp);
		int a=1;

		a=remove("parves.dat");
		//printf("%d", a);
		rename("test.dat","parves.dat");
		if(a==0)
		{
		    gotoxy(10,16);
		    printf("The record is sucessfully deleted");
		    gotoxy(10,18);
		    printf("Delete another record?(Y/N)");
		}
	    }
	else
	mainmenu();
	fflush(stdin);
	another=getch();
	}
	else
    {
        gotoxy(10,13);
	    printf("No record is found.");
	    if(getch())
	    mainmenu();
    }
	}
	mainmenu();

    }

////////////////////////////______________ DELETE  ___________________________/////////////////////////////////////////////
