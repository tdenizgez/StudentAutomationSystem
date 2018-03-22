#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct liste{

char TcKimlik[12];
char isim[15];
char soyisim[15];
char telefon[13];
char departman[30];

};

int i,j;
int main()
{
    struct liste kayit[1000];

    int secim;
    tekrar:
    printf("\t\nPersonel Kayit Programi\n");
    printf("\t--------------------------\n");
    printf("\t1- Kayit Listele\n");
    printf("\t2- Kayit Ara\n");
    printf("\t3- Kayit Ekle\n");
    printf("\t4- Kayit Sil\n");
    printf("\t5- Kayit Guncellestir\n");
    printf("\t6- Programdan Cikis.\n");
    printf("\t--------------------------\n");
    printf("\tSeciminiz:");
    scanf("%d",&secim);

    printf("\n\n");


    FILE *fp = fopen("personel.txt","r");
        int sayac=0;
        for(i=0;!feof(fp);i++){
            fscanf(fp,"%s %s %s %s %s",&kayit[i].TcKimlik,&kayit[i].isim,&kayit[i].soyisim,&kayit[i].telefon,&kayit[i].departman);
            sayac++;
        }
        fclose(fp);

    if(secim == 1)///Kayit Listele
        listele(kayit,sayac);
    else if(secim==2)///Kayit Ara
        kayitAra(kayit,sayac);
    else if(secim==3)///Kayit Ekle
        kayitEkle(kayit,sayac);
    else if(secim == 4)///Kayit Sil
        kayitSil(kayit,sayac);
    else if(secim == 5)///Kayit Guncellestir
        kayitGuncellestir(kayit,sayac);
    else if(secim==6){
        printf("\tProgramdan Cikis Yaptiniz.");
        exit(1);}

        goto tekrar;

       return 0;
}

void kayitGuncellestir(struct liste kayit[1000],int sayac){
        int kimlik,yedek;
        printf("\tGuncellestirmek Istediginiz Kaydin TC Kimlik Numarasinini Giriniz:");
        scanf("%d",&kimlik);
        for(i=0;i<sayac;i++){
           if(atoi(kayit[i].TcKimlik)==kimlik){
                yedek=i;
                printf("Aradiginiz Kayit:\n");
            printf("\t%s\t%s\t%s\t%s\t%s\n",kayit[i].TcKimlik,kayit[i].isim,kayit[i].soyisim,kayit[i].telefon,kayit[i].departman);
            break;
           }
           else if(i==sayac-1){
                printf("\tAradiginiz Kayit Bulunmamaktadir.");
                exit(1);
           }
        }

        int sec;
        printf("Tc Kimlik Numarasini Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Kimlik Numarasini Giriniz:");
            scanf("%s",&kayit[yedek].TcKimlik);
        }

        printf("Ismi Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Ismi Giriniz:");
            scanf("%s",&kayit[yedek].isim);
        }

        printf("Soyismi Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Soyismi Giriniz:");
            scanf("%s",&kayit[yedek].soyisim);
        }

        printf("Telefon Numarasini Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Telefon Numarasini Giriniz:");
            scanf("%s",&kayit[yedek].telefon);
        }

        printf("Calisilan Bolumu Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Calisilan Bolumu Giriniz:");
            scanf("%s",&kayit[yedek].departman);
        }

        FILE *fp;
        fp=fopen("personel.txt","w");
        for(i=0;i<sayac-1;i++){
            fprintf(fp,"%15s\t%15s\t%15s\t%15s\t%15s\n",kayit[i].TcKimlik,kayit[i].isim,kayit[i].soyisim,kayit[i].telefon,kayit[i].departman);
        }
        fclose(fp);

}

void kayitSil(struct liste kayit[1000],int sayac){


        int kimlik,yedek=0;
        printf("\tSilmek Istediginiz Kaydin TC Kimlik Numarasinini Giriniz:");
        scanf("%d",&kimlik);
        for(i=0;i<sayac;i++){
           if(atoi(kayit[i].TcKimlik)==kimlik){
                yedek=i;
                printf("Aradiginiz Kayit:\n");
                printf("\t%s\t%s\t%s\t%s\t%s\n",kayit[i].TcKimlik,kayit[i].isim,kayit[i].soyisim,kayit[i].telefon,kayit[i].departman);
            break;
           }
           else if(yedek==0)
                printf("\tAradiginiz Kayit Bulunmamaktadir.");
                yedek=-1;
        }

        FILE *fp;
        fp=fopen("personel.txt","w");
        for(i=0;i<sayac-1;i++){
                if(i==yedek) continue;
            fprintf(fp,"%-15s\t%-15s\t%-15s\t%-15s\t%-15s\n",kayit[i].TcKimlik,kayit[i].isim,kayit[i].soyisim,kayit[i].telefon,kayit[i].departman);
        }
        fclose(fp);

}

void kayitEkle(struct liste kayit[1000],int sayac){
        printf("TC Kimlik Numarasini Giriniz:");
        scanf("%s",&kayit[sayac].TcKimlik);
        printf("Ismini Giriniz:");
        scanf("%s",&kayit[sayac].isim);
        printf("Soyismini Giriniz:");
        scanf("%s",&kayit[sayac].soyisim);
        printf("Telefon Numarasini Giriniz:");
        scanf("%s",&kayit[sayac].telefon);
        printf("Calistigi Bolumu Giriniz:");
        scanf("%s",&kayit[sayac].departman);

        FILE *fp;
        fp = fopen("personel.txt","a");
        fprintf(fp,"%-15s %-15s %-15s %-15s %-15s\n",kayit[sayac].TcKimlik,kayit[sayac].isim,kayit[sayac].soyisim,kayit[sayac].telefon,kayit[sayac].departman);
        fclose(fp);

}

void listele(struct liste kayit[1000],int sayac){

        printf("%-16s %-16s %-16s %-16s %-16s\n","TC Kimlik","Isim","Soyisim","Telefon Numarasi","Departman");
        for(i=0;i<sayac-1;i++){
            printf("%-16s %-16s %-16s %-16s %-16s\n",kayit[i].TcKimlik,kayit[i].isim,kayit[i].soyisim,kayit[i].telefon,kayit[i].departman);
        }


}

void kayitAra(struct liste kayit[1000],int sayac){

        int kimlik;
        printf("\tAramak Istediginiz Kaydin TC Kimlik Numarasinini Giriniz:");
        scanf("%d",&kimlik);
        for(i=0;i<sayac;i++){
           if(atoi(kayit[i].TcKimlik)==kimlik){
                printf("Aradiginiz Kayit:\n");
            printf("\t%s\t%s\t%s\t%s\t%s\n",kayit[i].TcKimlik,kayit[i].isim,kayit[i].soyisim,kayit[i].telefon,kayit[i].departman);
            break;
           }
           else if(i==sayac-1)
                printf("\tAradiginiz Kayit Bulunmamaktadir.");
        }

}
