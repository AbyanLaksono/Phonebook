/*Membuat program phone book
    by: Muhammad Abyan Laksono 2304127 Pendidikan Ilmu Komputer B
    Menu di dalam program terdapat

    dengan referensi dari Youtube dan Google untuk mencari syntax yang diinginkan
    */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct orang{
    char nama[30];
    char mble_no[20];
    char mail[100];

};
/*membuat struct cupaya lebih mudah untuk menampung beberapa tipe data
biar ga deklarasiin tipe data satu satu*/

typedef struct orang orang; 
/*Typdef: digunakan untuk meng-aliaskan sebuah tipedata
yang sudah ada ke isinya sendiri, jadi kita tidak perlu lagi membuat struktur baru
sebenarnya ga begitu beguna, karena sudah ada struct orang
*/

//pendeklarasian fungsi
void hapus_semua();
void hapus();
void tambah_nama();
void tampilkan_semua();
void cari_nama();
void update_data();
void masukan_data(orang *p);
void menu();
void mulai_tampilin();
void sortKontak();


void start(){
    int pilih;

    while (1)
    {
        menu();

        scanf("%d",&pilih);
        switch (pilih)
        {
        case 1:
            mulai_tampilin();
            getchar();

            break;
        case 2:
            tambah_nama();
            getchar();

            break;
        case 3:
            cari_nama();
            getchar();

            break;
        case 4:
            hapus();
            getchar();

            break;
        case 5:
            update_data();
            getchar();
            
            break;
        case 6:
            hapus_semua();
            getchar();

            break;
        default:
            system("cls");
            printf("========================================================\n");
            printf("====== TERIMAKASIH TELAH MENGGUNAKAN APLIKASI INI ======\n");
            printf("========================================================");

            printf("\n\nProgrammed By:                    Muhammad Abyan Laksono\n\n\n\n\n");
            getchar();
            system("pause");
            exit(1);
        }
    }
}



//menu
void menu(){
    system("cls");
    printf("========================================================================\n");
    printf("\n================== Selamat datang di Program AbyAPP ==================\n");
    printf("\n========================MUHAMMAD ABYAN LAKSONO========================\n");
    printf("\n[1] Menampilkan semua Kontak");
    printf("\n\n[2] Menambahkan Kontak");
    printf("\n\n[3] Mencari kontak");
    printf("\n\n[4] Menghapus kontak");
    printf("\n\n[5] mengubah data dalam Kontak");
    printf("\n\n[6] Menghapus Semua kontak");
    printf("\n\n[7] Keluar");

    printf("\n\nMasukan pilihan Anda: ");
}


//remove all
void hapus_semua(){
    char pilih;
    system("cls");

    //menghapus data file format txt
    remove("./datakontak.txt");

    printf("Semua data telah dihapus");
    printf("\nTekan apapun untuk melanjutkan program....");
    getchar();
} 

//remove person
void hapus(){

    char ponsel[20];
    printf("Masukan nomor (detail): ");
    getchar();
    fgets(ponsel, 20, stdin);

    FILE *fp,*tmpfile;
    fp = fopen("datakontak.txt","r");
    tmpfile = fopen("temp","w+");

    if (fp == NULL)
    {
        printf("=============");
        printf("\n!!!ERROR!!!\n");
        printf("=============");
        return;
    }
    else
    {
        orang p;
        int flag = 0;

        while(fread(&p,sizeof(orang),1,fp))
        {
            if (strcmp(ponsel,p.mble_no)==0)
            {
                system("cls");
                printf("SUKSES NGAB!!!! \n");
                flag = 1;
            }
                else fwrite(&p, sizeof(p),1,tmpfile);
                fflush(stdin);
        }
        if (flag == 0)
        {
            system("cls");
            printf("Tidak ada data yang tersedia untuk No. %s\n",ponsel);
        }
            fclose(fp);
            fclose(tmpfile);
            remove("datakontak.txt");
            rename("temp","datakontak.txt");
//menghapus file "datakontak.txt", dan mengganti file "temp" dengan nama "datakontak.txt".
            fflush(stdin);
    }
}



void update_data(){
    system("cls");

    mulai_tampilin();
    printf("==========================================================\n");
    printf("Berikut data yang tersedia\n\n");
    printf("MENGUBAH NAMA DAN NOMOR BERDASARKAN INPUTAN NOMOR USER....\n");

    char ponsel[20];
    printf("Masukan nomor (detail): ");
    getchar();
    fgets(ponsel, 20, stdin);

    FILE *fp,*tmpfile;
    fp = fopen("datakontak.txt","r");
    tmpfile = fopen("temp","w+");

    if (fp == NULL)
    {
        printf("=============");
        printf("\n!!!ERROR!!!\n");
        printf("=============");
        return;
    }
    else
    
    {
        orang p;
        int flag = 0;

        while(fread(&p,sizeof(orang),1,fp))
        {
            if (strcmp(ponsel,p.mble_no)==0)
            {
                system("cls");
                tambah_nama();
                flag = 1;
            }
                else fwrite(&p, sizeof(p),1,tmpfile);
                fflush(stdin);
        }
        if (flag == 0)
        {
            system("cls");
            printf("Tidak ada data yang tersedia untuk Nomor %s\n",ponsel);
        }
            fclose(fp);
            fclose(tmpfile);
            remove("datakontak.txt");
            rename("temp","datakontak.txt");
            fflush(stdin);
    }
//=====================space code
    printf("\n\nTekan apapun untuk kembali");
    getchar();

}


// fungsi untuk mencari nama kontak
void cari_nama()
{
    system("cls");

    char nama[40];
    printf("Masukan nama (detail) yang ingin dicari: ");
    getchar();
    fgets(nama,40,stdin);

    FILE *fp;
    fp= fopen ("datakontak.txt", "r");
    if (fp == NULL)
    {
        printf("\n\nError in file opening!\n");
        system("PAUSE");
        return;
    }
    else
    {
        int flag = 0;
        orang p;
        while (fread (&p, sizeof(p),1 , fp) == 1)
        {
            if (strcmp(nama,p.nama) == 0)
            {   
                printf("\n\t\t========================================================\n");
                printf("\t\tNAMA\t\t\t\t   NOMOR\t\t    \n");
                int len1 = 40;
                int len2 = 15;
                printf("\t\t%s",p.nama);

                for (int i = 0; i < len1; i++) printf(" ");

                printf("\t\t%s",p.mble_no);
                for (int j = 0; j < len2; j++) printf(" ");
                printf("\n");

                flag = 1;
                getchar();
                break;
            }
            else continue;
        }
        if (flag == 0)
        {
            system("cls");
            printf("Nama data tidak ada di pendataan");
        }
        fflush(stdin);
        fclose(fp);

        printf("\n\nKetik apapun untuk kembali ke Menu utama....");
    }
}


//take input
void masukan_data(orang *p)
{
    system("cls");
    
    getchar();
    printf("Masukan nama:  ");
    fgets(p->nama, 30, stdin);
/* menyimpan input pengguna dalam variabel p->nama, 
yang merupakan bagian dari struktur data.*/

    printf("Masukan Nomor: ");
    fgets(p->mble_no, 20, stdin);

} 

// Fungsi untuk menambahkan kontak data nama
void tambah_nama(){
    FILE *fp;
    fp = fopen("datakontak.txt", "a+");
    //+: artinya akan membuka file dalam mode baca dan tulis.
    //a: artinya akan melakukan penambahan

    if (fp == NULL)
    {
    printf("Error in file opening, Ulang kembali!");
    system("pause");
        return;
    }
    else
    {
        orang p;
        masukan_data(&p);
        fwrite(&p,sizeof(p), 1, fp);
        fflush(stdin);
        fclose(fp);
        printf("Pendataan Sukses...\n");
        system("PAUSE");
    }
}

//list record
void tampilkan_semua(orang kontak[], int n){
    system("cls");
    orang p;
    printf("\t\t****************************************************************\n");
    printf("\t\t**           SELAMAT DATANG DI ABY.APK by ABY COMPANY         **\n");
    printf("\t\t**                     APLIKASI KONTAK DATA                   **\n");
    printf("\t\t****************************************************************\n\n");
    printf("\t\tNAMA\t\t\t\t                 NOMOR KONTAK\t\t\t\n\n");
    for (int i = 0; i < n; i++){
        int len1 = 50;
        int len2 = 35;

        printf("\t\t%d. %s",i+1, kontak[i].nama);
        for (int j = 0; j < len1; j++) printf(" ");

        printf("\t\t  %s", kontak[i].mble_no);
        for (int j = 0; j < len2; j++) printf(" ");      
        printf("\n");
    }
    system("pause");
}


void mulai_tampilin(){
    int n, i;
    orang kontak[100];
    FILE *file = fopen("datakontak.txt", "r");
    if (file == NULL){
        printf("GAK ADA CUY DATANYA\n");
        printf("Masukin data dengan tekan [2]\n\n");
        printf("Tekan apapun untuk kembali ke laman utama...");
        getchar();
    }
    else{

    n = 0;
    while (fread(&kontak[n], sizeof(orang), 1, file) == 1){
        n++;
    }
    fclose(file);

    sortKontak(kontak, n);

    system("cls");
    tampilkan_semua(kontak, n);
    }
}
//Fungsi swap(orang *a, orang *b) digunakan untuk menukar isi dua variabel.
//Menggunakan bubble sorting
void swap(orang *xp, orang *yp){
    orang temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void sortKontak(orang kontak[], int n){
    int i, j;
    /*fungsi melakukan loop bertingkat selama i kurang dari n-1. 
    Di dalam loop ini, variabel j melakukan loop dari 0 hingga n-i-1.*/

    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (strcmp(kontak[j].nama, kontak[j+1].nama) > 0){
                swap(&kontak[j], &kontak[j+1]);
            }
        }
    }
}


//memulai program
int main()
{
    char nama[20];

    printf("\t\tMasukan nama Anda: ");
    fgets(nama,20,stdin);

    printf("\n\n\t\tSELAMAT DATANG %s\n",nama);
    getchar();
    start();
    system("PAUSE");
    return 0;
}