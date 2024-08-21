#include <stdio.h>          /// MUHAMMED FURKAN AKYOL  21100011002
#include <stdlib.h>
#include <string.h>
#define TAB 9       ///  {
#define ENTER 13    ///      SIFRE KONTROLUNDE KULLANILIYOR
#define BCKSPC 8    ///  }
#define X 7000      /// MAAS HESAPLARKEN KULLANILIYOR
char ID[5]= {'a','d','m','i','n'},isim[10];                     /// KULLANICI ADI VE SIFRESI
int PASSWORD[4]= {1,2,3,4},h=0,pass,g=0,pas[10];
int idboyut = sizeof(ID);
struct adaykisisel
{
    char isim[20];
    char soyisim[20];
    int yas;
};
struct adaylar1
{
    struct adaykisisel x;
    char meslek[20];
    int id;
    int mulakatpuani;
    float diplomapuani;
    int tecrube;
    int maas;
    int belirtec;
    int puan;
};
int boyut = sizeof(struct adaylar1);
struct adaylar1 *p;
int n=0,a=100,m=0;   /// n=Kisi sayisi a=id m=personel sayisi
void hata()
{
    system("cls");
    system("color 0c");
    for(int t=0; t<2; t++)
    {
        for(int y=0; y<5; y++)
        {
            system("cls");
            printf("\n\n\n\n\n               ERROR");
        }
        for(int y=0; y<5; y++)
        {
            system("cls");
            printf("\n\n\n\n\n               ERROR!!");
        }
    }
}

void dogru()
{
    system("cls");
    system("color 0a");
    for(int t=0; t<2; t++)
    {
        for(int y=0; y<5; y++)
        {
            system("cls");
            printf("\n\n\n\n\n               CORRECT");
        }
        for(int y=0; y<5; y++)
        {
            system("cls");
            printf("\n\n\n\n\n               CORRECT!!");
        }
    }
    system("color 0f");
}

void listelemef()
{
    int j;
    system("cls");
    system("color 0f");
    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("| ID         1.AD            SOYAD        YAS         MULAKAT PUANI    TECRUBE(yil)   DIPLOMA NOTU      MESLEK |\n");
    printf("----------------------------------------------------------------------------------------------------------------\n");
    for(j=0; j<n; j++)
    {
        if((p+j)->belirtec==0)
        {
            printf("%5d\t%10s\t%10s    \t%5d    \t%5d     \t%5d         \t %5.2f   \t%s\n",(p+j)->id,(p+j)->x.isim,(p+j)->x.soyisim,(p+j)->x.yas,(p+j)->mulakatpuani,(p+j)->tecrube,(p+j)->diplomapuani,(p+j)->meslek);
        }
    }
    if(n==0)
    {
        system("cls");
        printf("\n\n\n     HERHANGI BIR KAYIT BULUNAMADI.");
    }
    getch();
}

void personellistelemef()
{
    int j;
    system("cls");
    system("color 0f");
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| ID         1.AD            SOYAD        YAS         MULAKAT PUANI    TECRUBE(yil)   DIPLOMA NOTU      MESLEK          MAAS |\n");
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    for(j=0; j<n; j++)
    {
        if((p+j)->belirtec!=0)
        {
            printf("%5d\t%10s\t%10s    \t%5d    \t%5d     \t%5d         \t %5.2f   \t%s\t %d\n",(p+j)->id,(p+j)->x.isim,(p+j)->x.soyisim,(p+j)->x.yas,(p+j)->mulakatpuani,(p+j)->tecrube,(p+j)->diplomapuani,(p+j)->meslek,(p+j)->maas);
        }
    }
    if(m==0)
    {
        system("cls");
        printf("\n\n\n     HERHANGI BIR PERSONEL BULUNAMADI.");
    }
    getch();
}

void yazmaf()
{
    int w=0;
    p = (struct adaylar1*)realloc(p,(n+1)*boyut);
    system("cls");
    system("color 0f");
    printf("\n\n     AD -> ");
    scanf(" %[^\n]s",&(p+n)->x.isim);
    printf("     SOYAD -> ");
    scanf(" %[^\n]s",&(p+n)->x.soyisim);
    printf("     MESLEK (Makine,Bilgisayar,Elektrik,Elektronik,Mekatronik) -> ");
    scanf(" %[^\n]s",&(p+n)->meslek);
    printf("     YAS -> ");
    scanf("%d",&(p+n)->x.yas);
    printf("     MULAKAT PUANI -> ");
    scanf("%d",&(p+n)->mulakatpuani);
    printf("     TECRUBE (yil) -> ");
    scanf("%d",&(p+n)->tecrube);
    printf("     DIPLOMA NOTU (X.xx) -> ");
    scanf("%f",&(p+n)->diplomapuani);
    if((p+n)->x.yas<25 && (p+n)->x.yas>=20)             /// ADAY PUANI KAYIT SIRASINDA BELIRLENIYOR
        w+=20;
    else if((p+n)->x.yas<30 && (p+n)->x.yas>=25)
        w+=15;
    else if((p+n)->x.yas<40 && (p+n)->x.yas>=30)
        w+=10;
    else if((p+n)->x.yas>=40)
        w+=5;
    if((p+n)->mulakatpuani>=50 && (p+n)->mulakatpuani<65)
        w+=15;
    else if((p+n)->mulakatpuani>=65 && (p+n)->mulakatpuani<80)
        w+=20;
    else if((p+n)->mulakatpuani>=80 && (p+n)->mulakatpuani<90)
        w+=25;
    else if((p+n)->mulakatpuani>=90 && (p+n)->mulakatpuani<=100)
        w+=30;
    if((p+n)->tecrube>=0 && (p+n)->tecrube<1)
        w+=15;
    else if((p+n)->tecrube>=1 && (p+n)->tecrube<3)
        w+=20;
    else if((p+n)->tecrube>=3 && (p+n)->tecrube<5)
        w+=25;
    else if((p+n)->tecrube>=5)
        w+=30;
    if((p+n)->diplomapuani<3 && (p+n)->diplomapuani>=2.5)
        w+=5;
    else if((p+n)->diplomapuani<3.3 && (p+n)->diplomapuani>=3)
        w+=10;
    else if((p+n)->diplomapuani<3.7 && (p+n)->diplomapuani>=3.3)
        w+=15;
    else if((p+n)->diplomapuani>=3.7 && (p+n)->diplomapuani<=4)
        w+=20;
    (p+n)->puan = w;
    (p+n)->id = a;
    (p+n)->belirtec = 0;        ///  ADAY VE PERSONELLER AYNI YERDE OLDUGU ICIN ADAYLAR = 0   ;   PERSONELLER = 1 OLACAK SEKILDE AYARLADIM
    (p+n)->maas = 0;
    n++;
    a++;
    dogru();

}

void silmef()
{
    system("cls");
    system("color 0f");
    int q,d=0,i,j;
    char b;
label:
    d=0;
    listelemef();
    if(n==0)
    {
        printf("\n\n\n     LISTE BOS...");
        getch();
        goto label1;
    }
    printf("\n\n\n     Silinecek kisinin ID numarasini giriniz -> ");
    scanf("%d",&q);
lab:
    printf("     Silmek istediginize emin misiniz? (e/h) -> ");
    scanf(" %c",&b);

    if(b=='E' || b=='e')
    {
        for(i=0; i<n; i++)
        {
            if((p+i)->id==q && (p+i)->belirtec==0)
            {
                for(j=i; j<n; j++)              ///  SILINECEK OLAN YERIN ALTINDAKILERI TEK TEK TEPEYE ATIP SON STRUCT SILINIYOR
                {
                    (p+j)->id=(p+(j+1))->id;
                    strcpy((p+j)->x.isim,(p+(j+1))->x.isim);
                    strcpy((p+j)->x.soyisim,(p+(j+1))->x.soyisim);
                    (p+j)->x.yas=(p+(j+1))->x.yas;
                    (p+j)->mulakatpuani=(p+(j+1))->mulakatpuani;
                    (p+j)->tecrube=(p+(j+1))->tecrube;
                    (p+j)->diplomapuani=(p+(j+1))->diplomapuani;
                    strcpy((p+j)->meslek,(p+(j+1))->meslek);
                    (p+j)->maas=(p+(j+1))->maas;
                }
                d=2;
                break;
            }
        }
    }
    else if(b=='H' || b=='h')
    {
        system("cls");
        printf("\n\n\n     Islem iptal edilmistir.");
        d++;
        getch();
    }
    else
    {
        goto lab;
    }
    if(d==0)
    {
        system("cls");
        printf("\n\n   ID BULUNAMADI");
        getch();
        system("cls");
        goto label;
    }
    dogru();
label1:
    if(d==2)
    {
        n=n-1;
        p = (struct adaylar1*)realloc(p,n*boyut);
    }
}

void  personelsilmef()
{
    system("cls");
    system("color 0f");
    int q,d=0,i;
    char b;
label:
    if(m==0)
    {
        printf("\n\n\n     LISTE BOS...");
        getch();
        goto label1;
    }
    d=0;
    personellistelemef();
    printf("\n\n\n     Silinecek personelin ID numarasini giriniz -> ");
    scanf("%d",&q);
lab:
    printf("     Silmek istediginize emin misiniz? (e/h) -> ");
    scanf(" %c",&b);

    if(b=='E' || b=='e')
    {
        for(i=0; i<n; i++)
        {
            if((p+i)->id==q && (p+i)->belirtec!=0)          /// SONDAKINI SILINECEK OLAN YERE ATIP ALT STRUCT DINAMIC BELLEKLE IADE EDILIYOR
            {
                    (p+i)->id=(p+(n-1))->id;
                    strcpy((p+i)->x.isim,(p+(n-1))->x.isim);
                    strcpy((p+i)->x.soyisim,(p+(n-1))->x.soyisim);
                    (p+i)->x.yas=(p+(n-1))->x.yas;
                    (p+i)->mulakatpuani=(p+(n-1))->mulakatpuani;
                    (p+i)->tecrube=(p+(n-1))->tecrube;
                    (p+i)->diplomapuani=(p+(n-1))->diplomapuani;
                    strcpy((p+i)->meslek,(p+(n-1))->meslek);
                    (p+i)->maas=(p+(n-1))->maas;
                    (p+i)->belirtec=(p+(n-1))->belirtec;
                    m=m-1;
                d++;
                break;
            }
        }
    }
    else if(b=='H' || b=='h')
    {
        system("cls");
        printf("\n\n\n     Islem iptal edilmistir.");
        d++;
        getch();
        return 0;
    }
    else
    {
        goto lab;
    }
    if(d==0)
    {
        system("cls");
        printf("\n\n   ID BULUNAMADI");
        getch();
        system("cls");
        goto label;
    }
label1:
    if(d!=0)
    {
        n=n-1;
        p = (struct adaylar1*)realloc(p,n*boyut);
    }
    dogru();
}

void guncellemef()
{
    system("cls");
    system("color 0f");
    int q,d=0,i,j,w=0;
    char b;
label:
    d=0;
    listelemef();
    printf("\n\n\n     Degistirmek istedigin kisinin ID numarasini giriniz -> ");
    scanf("%d",&q);
lab:
    printf("     Degistirmek istedginize emin misiniz? (e/h) -> ");
    scanf(" %c",&b);

    if(b=='E' || b=='e')
    {
        for(i=0; i<n; i++)
        {
            if((p+i)->id==q && (p+i)->belirtec==0)
            {
                printf("     %d  %s  %s",(p+i)->id,(p+i)->x.isim,(p+i)->x.soyisim);
                printf("\n\n     YAS -> ");
                scanf("%d",&(p+i)->x.yas);
                printf("     MULAKAT PUANI -> ");
                scanf("%d",&(p+i)->mulakatpuani);
                printf("     TECRUBE (yil) -> ");
                scanf("%d",&(p+i)->tecrube);
                printf("     DIPLOMA NOTU (X.xx) -> ");
                scanf("%f",&(p+i)->diplomapuani);
                printf("     MESLEK -> ");
                scanf(" %[^\n]s",&(p+i)->meslek);

                if((p+i)->x.yas<25 && (p+i)->x.yas>=20)
                    w+=20;
                else if((p+i)->x.yas<30 && (p+i)->x.yas>=25)
                    w+=15;
                else if((p+i)->x.yas<40 && (p+i)->x.yas>=30)
                    w+=10;
                else if((p+i)->x.yas>=40)
                    w+=5;
                if((p+i)->mulakatpuani>=50 && (p+i)->mulakatpuani<65)
                    w+=15;
                else if((p+i)->mulakatpuani>=65 && (p+i)->mulakatpuani<80)
                    w+=20;
                else if((p+i)->mulakatpuani>=80 && (p+i)->mulakatpuani<90)
                    w+=25;
                else if((p+i)->mulakatpuani>=90 && (p+i)->mulakatpuani<100)
                    w+=30;
                if((p+i)->tecrube>=0 && (p+i)->tecrube<1)
                    w+=15;
                else if((p+i)->tecrube>=1 && (p+i)->tecrube<3)
                    w+=20;
                else if((p+i)->tecrube>=3 && (p+i)->tecrube<5)
                    w+=25;
                else if((p+i)->tecrube>=5)
                    w+=30;
                if((p+i)->diplomapuani<3 && (p+i)->diplomapuani>=2.5)
                    w+=5;
                else if((p+i)->diplomapuani<3.3 && (p+i)->diplomapuani>=3)
                    w+=10;
                else if((p+i)->diplomapuani<3.7 && (p+i)->diplomapuani>=3.3)
                    w+=15;
                else if((p+i)->diplomapuani>=3.7 && (p+i)->diplomapuani<=4)
                    w+=20;
                (p+i)->puan = w;
                d++;
                break;
            }
        }
    }
    else if(b=='H' || b=='h')
    {
        system("cls");
        printf("\n\n\n     Islem iptal edilmistir.");
        d++;
        getch();
    }
    else
    {
        goto lab;
    }
    if(d==0)
    {
        system("cls");
        printf("\n\n   ID BULUNAMADI");
        getch();
        system("cls");
        goto label;
    }
    dogru();
}

void personelzam()      /// 1.FONK
{
    system("cls");
    system("color 0f");
    int q,d=0,i,j,k;
    char b;
label:
    d=0;
    personellistelemef();
    printf("\n\n\n     >|< Zam yapmak istediginiz personelin ID numarasini giriniz -> ");
    scanf("%d",&q);
lab:
    printf("     >|< Emin misiniz? (e/h) -> ");
    scanf(" %c",&b);

    if(b=='E' || b=='e')
    {
        for(i=0; i<n; i++)
        {
            if((p+i)->id==q && (p+i)->belirtec!=0)
            {
                printf("     %d  %s  %s",(p+i)->id,(p+i)->x.isim,(p+i)->x.soyisim);
                printf("\n\n     MEVCUT MAAS -> %d",(p+i)->maas);
                printf("     Zam oranini giriniz -> %%");
                scanf("%d",&k);
                (p+i)->maas = (p+i)->maas+(k*((p+i)->maas/100));
                d++;
                break;
            }
        }
    }
    else if(b=='H' || b=='h')
    {
        system("cls");
        printf("\n\n\n     Islem iptal edilmistir.");
        d++;
        getch();
    }
    else
    {
        goto lab;
    }
    if(d==0)
    {
        system("cls");
        printf("\n\n   ID BULUNAMADI");
        getch();
        system("cls");
        goto label;
    }
    dogru();
}

int giris()
{
    system("cls");
    system("color 0f");
    printf("   []======================================[]\n");
    printf("  []                                        []\n");
    printf("  []                  LOGIN                 []\n");
    printf("  []                                        []\n");
    printf("   []======================================[]\n");
    printf("     =>        ID = ");
    scanf("%s",&isim);
    printf("     =>        PASSWORD = ");
    pwdfonk();
    while(isim[h]!='\0')
    {
        h++;
    }
    for(int j=0; j<3; j++)
    {
        for(int i=0; i<3; i++)
        {
            system("cls");
            printf("\n\n\n\n\n               loading");
        }
        for(int i=0; i<3; i++)
        {
            system("cls");
            printf("\n\n\n\n\n               loading.");
        }
        for(int i=0; i<3; i++)
        {
            system("cls");
            printf("\n\n\n\n\n               loading..");
        }
        for(int i=0; i<3; i++)
        {
            system("cls");
            printf("\n\n\n\n\n               loading...");
        }
    }
    denetleme();
}

int denetleme() /// TEK TEK KONTROL EDILIYOR
{
    int i=0,j=0,k=0,l;
    while(pas[i]!='\0')
    {
        i++;
    }
    for(l=0 ; l<i ; l++)
    {
        if(pas[l]==PASSWORD[l])
        {
            l++;
        }
    }
    for(j=0; j<h; j++)
    {
        if(isim[j]==ID[j])
        {
            k++;
        }
    }
    if(i==sizeof(PASSWORD)/4 && sizeof(PASSWORD)/4==l && k==idboyut && h==k)
    {
        dogru();
        return 1;
    }
    else
    {
        hata();
        if(g==1)
        {
            g=0;
            return 0;
        }
        system("cls");
        g++;
        giris();
    }
}

void pwdfonk()
{

    int i=0,a;
    while(1)
    {
        a = getch();
        if(a == ENTER || a == TAB)      ///ENTER VEYA TAB TUSU ALT SATIRA GECMESI ICIN
        {
            pas[i]='\0';
            break;
        }
        else if(a == BCKSPC)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pas[i++]=a;
            printf("*");
        }
    }
}

int menu()
{

    char a;
    do
    {
        system("cls");
        system("color 0f");
        printf("   []======================================[]\n");
        printf("  []                                        []\n");
        printf(" []                   MENU                   []\n");
        printf("  []                                        []\n");
        printf("   []======================================[]\n");
        printf("   []                                      []\n");
        printf("   []   a-  Aday ekle                      []\n");
        printf("   []   b-  Aday sil                       []\n");
        printf("   []   c-  Tum adaylari goster            []\n");
        printf("   []   d-  Aday guncelle                  []\n");
        printf("   []   e-  Personel alimi yap             []\n");
        printf("   []   f-  Personelleri goster            []\n");
        printf("   []   g-  Personel sil                   []\n");
        printf("   []   h-  Personele zam yap              []\n");
        printf("   []   i-  Girise don                     []\n");
        printf("   []   x-  Exit                           []\n");
        printf("   []                                      []\n");
        printf("    []====================================[]\n\n\n");

        printf("      >|< Yapilacak islemi belirtiniz => ");
        scanf(" %c",&a);

        switch (a)
        {
        case 'a':
        {
            return 0;
        }

        break;

        case 'b':
        {
            return 1;
        }

        break;

        case 'c':
        {
            return 2;
        }

        break;

        case 'd':
        {
            return 3;
        }

        break;

        case 'e':
        {
            return 4;
        }

        break;

        case 'f':
        {
            return 5;
        }

        break;

        case 'g':
        {
            return 6;
        }

        break;

        case 'h':
        {
            return 7;
        }

        break;

        case 'i':
        {
            return 8;
        }

        break;

        case 'x':
        {
            return 9;
        }

        break;

        default:
        {
            hata();
            system("cls");
            printf("\n\n\n\n\n            YANLIS HARF GIRDINIZ\n            DEVAM ETMEK ICIN BIR TUSA BASINIZ");
            getch();
        }
        break;

        }

    }
    while (a!=0);

}

int cikis()
{
    system("cls");
    system("color 0c");
    printf("\n\n\n\n       ==============================\n");
    printf("        ||       System Exit       ||\n");
    printf("       ==============================\n\n\n\n");
    exit(EXIT_SUCCESS);
}

void personelalimi()    /// 2.FONK
{
    system("cls");
    system("color 0f");
    int b,f,t,j,k,u,o,temp,y,w;
    char e,r;
    char *bolumadi=(char*)calloc(10,sizeof(bolumadi));
    int *degiskentutucu=(int*)calloc((n-m),sizeof(degiskentutucu));
label20:
    printf("   []======================================[]\n");
    printf("  []                                        []\n");
    printf(" []               ALIM EKRANI                []\n");
    printf("  []                                        []\n");
    printf("   []======================================[]\n");
    printf("\n     a-Makine Muhendisligi");
    printf("\n     b-Mekatronik Muhendisligi");
    printf("\n     c-Elektrik Muhendisligi");
    printf("\n     d-Mekatronik Muhendisligi");
    printf("\n     e-Bilgisayar Muhendisligi");
    printf("\n     ALIM YAPILACAK BOLUMU SECINIZ  => ");
    scanf(" %c",&e);
    if(e=='A' || e=='a')
    {
        strcpy(bolumadi,"Makine");
        w=115;
    }
    else if(e=='B' || e=='b')
    {
        strcpy(bolumadi,"Elektronik");
        w=120;
    }
    else if(e=='C' || e=='c')
    {
        strcpy(bolumadi,"Elektrik");
        w=110;
    }
    else if(e=='D' || e=='d')
    {
        strcpy(bolumadi,"Mekatronik");
        w=130;
    }
    else if(e=='E' || e=='e')
    {
        strcpy(bolumadi,"Bilgisayar");
        w=185;
    }
    else
    {
        hata();
        system("color 0f");
        system("cls");
        printf("\n\n\n     Hatali secim yaptiniz\n     Lutfen tekrar deneyiniz.");
        getch();
        system("cls");
        goto label20;
    }
    j=0;
    for(t=0; t<=n; t++)
    {
        if(!(f = strcmp((p+t)->meslek,bolumadi)) && (p+t)->belirtec==0)
        {
            *(degiskentutucu+j)=t;
            j++;
        }
    }
    printf("\n\n     Istediginiz bolume aday kisi sayisi -> %d",j);
    getch();
    if(j==0)
    {
        system("cls");
        printf("\n\n\n     Alim yapilacak bolumde kimse aday degildir.\n      Menuye donuyorsunuz...");
        goto label77;

    }
    for(t=0; t<j; t++)
    {
        for(o=0; o<j-1; o++)
        {
            if((p+*(degiskentutucu+o))->puan < (p+*(degiskentutucu+(o+1)))->puan)
            {
                temp = *(degiskentutucu+o);
                *(degiskentutucu+o) = *(degiskentutucu+(o+1));
                *(degiskentutucu+(o+1)) = temp;
            }
        }
    }
    system("cls");
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");
    printf("| ID            AD           SOYAD        YAS         MULAKAT PUANI    TECRUBE(yil)   DIPLOMA NOTU      MESLEK         PUAN |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");
    for(t=0; t<j; t++)
    {
        k=*(degiskentutucu+t);
        printf("%5d\t%10s\t%10s    \t%5d    \t%5d     \t%5d         \t %5.2f   \t%s   %5d\n",(p+k)->id,(p+k)->x.isim,(p+k)->x.soyisim,(p+k)->x.yas,(p+k)->mulakatpuani,(p+k)->tecrube,(p+k)->diplomapuani,(p+k)->meslek,(p+k)->puan);
    }
label88:
    printf("\n\n     Bolume kac kisi almak istiyorsunuz ?   -> ");
    scanf("%d",&u);
leb9:
    printf("\n     Emin misiniz? (e/h) -> ");
    scanf(" %c",&r);
    if(r=='h' || r=='H')
    {
        system("cls");
        printf("\n\n\n     Isleminiz iptal edilmistir...");
        getch();
    }
    else if(u>j)
    {
        system("cls");
        printf("\n\n\n     O kadar aday basvurusu olmamistir.\n     Lutfen tekrar yaziniz.");
        getch();
        goto label88;
    }
    else if(r=='e' || r=='E')
    {
        for(t=0; t<u; t++)
        {
            k=*(degiskentutucu+t);
            (p+k)->belirtec=1;
            if((p+k)->tecrube<1 && (p+k)->tecrube>=0)
            {
                (p+k)->maas = (X/100)*w;
                (p+k)->maas = (p+k)->maas - (((p+k)->maas/100)*5);
            }
            else if((p+k)->tecrube<3 && (p+k)->tecrube>=1)
            {
                (p+k)->maas=(X/100)*w;
                (p+k)->maas = (p+k)->maas - (((p+k)->maas/100)*6);
            }
            else if((p+k)->tecrube<5 && (p+k)->tecrube>=3)
            {
                (p+k)->maas=(X/100)*w;
                (p+k)->maas = (p+k)->maas - (((p+k)->maas/100)*7);
            }
            else if((p+k)->tecrube>=5)
            {
                y=(p+k)->tecrube;
                y=y-5;
                (p+k)->maas=(X/100)*(w+(y*2));
                (p+k)->maas = (p+k)->maas - (((p+k)->maas/100)*8);
            }
        }
        for(t=u; t<j; t++)
        {
            k=*(degiskentutucu+t);
            (p+k)->id=(p+(n-1))->id;
            strcpy((p+k)->x.isim,(p+(n-1))->x.isim);
            strcpy((p+k)->x.soyisim,(p+(n-1))->x.soyisim);
            (p+k)->x.yas=(p+(n-1))->x.yas;
            (p+k)->mulakatpuani=(p+(n-1))->mulakatpuani;
            (p+k)->tecrube=(p+(n-1))->tecrube;
            (p+k)->diplomapuani=(p+(n-1))->diplomapuani;
            strcpy((p+k)->meslek,(p+(n-1))->meslek);
            (p+k)->maas=(p+(n-1))->maas;
            (p+k)->belirtec=(p+(n-1))->belirtec;
            n--;

        }
        m=m+u;
        p = (struct adaylar1*)realloc(p,n*boyut);
    }
    else
    {
        hata();
        printf("\n\n\n     Hatali secim yaptiniz\n     Lutfen tekrar deneyiniz.");
        getch();
        system("cls");
        goto leb9;
    }
label77:

    free(degiskentutucu);
    free(bolumadi);
    dogru();


}

int main()      /// MENU DEGER DONDURUYOR BURDAN GIRIS SAGLANIYOR
{
    p = (struct adaylar1*)malloc(sizeof(struct adaylar1));
    int t=-1;
    int l=-1;
gir:
    t = giris();
    if(t==1)
    {
        t=-1;
        goto liste;
    }
    else if(t==0)
    {
        t=-1;
        cikis();
    }
    while(1)
    {
liste:
        l = menu();
        if(l==0)
        {
            l=-1;
            yazmaf();
        }
        else if(l==1)
        {
            l=-1;
            silmef();
        }
        else if(l==2)
        {
            l=-1;
            listelemef();
        }
        else if(l==3)
        {
            l=-1;
            guncellemef();
        }
        else if(l==4)
        {
            l=-1;
            personelalimi();
        }
        else if(l==5)
        {
            l=-1;
            personellistelemef();
        }
        else if(l==6)
        {
            l=-1;
            personelsilmef();
        }
        else if(l==7)
        {
            l=-1;
            personelzam();
        }
        else if(l==8)
        {
            l=-1;
            g=0;
            goto gir;
        }
        else if(l==9)
        {
            l=-1;
            cikis();
        }

    }
}

