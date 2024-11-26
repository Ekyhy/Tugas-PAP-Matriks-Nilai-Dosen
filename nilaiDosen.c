#include <stdio.h>
#include <string.h>

struct dosen {
    char id[25];
    char name[100];
    char jabatan[30];
};

int tambah(struct dosen *p, char id[], char name[], char jabatan[]) {
    strcpy(p->id, id);
    strcpy(p->name, name);
    strcpy(p->jabatan, jabatan);
    return 0;
}

int hapus_dosen(int *count, struct dosen dataDosen[], char id[]) {
    int found = 0;

    for (int i = 0; i < *count; i++) {
        if (strcmp(dataDosen[i].id, id) == 0) {
            for (int j = i; j < *count - 1; j++) {
                dataDosen[j] = dataDosen[j + 1];
            }
            (*count)--; // Kurangi nilai count
            printf("Dosen dengan ID: %s telah dihapus\n", id);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Dosen dengan ID: %s tidak ditemukan\n", id);
    }

    return 0;
}

int main() {
    struct dosen dataDosen[100];
    int count = 0;
    int chooise;


    do {
        printf("\n###############################################");
        printf("\n== Selamat Datang di Matriks Penilaian Dosen ==\n");
        printf("###############################################\n");
        printf("1. Data Dosen\n");
        printf("2. Penilaian Dosen\n");
        printf("3. Persentase Guru Besar Lektor Kepala\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan anda: ");
        scanf("%d", &chooise);
        getchar(); 

        if (chooise == 1) {
            int pilihan;
            printf("\n===================\n");
            printf("Data Dosen");
            printf("\n===================\n");
            printf("1. Tambah Dosen\n");
            printf("2. Hapus Dosen\n");
            printf("3. Tampilkan Data Dosen Keseluruhan\n");
            printf("Masukkan pilihan Anda: ");
            scanf("%d", &pilihan);
            getchar(); 

            switch (pilihan) {
            case 1: {
                char id[25], name[100], jabatan[30];
                int pilihanJabatan;
                printf("-------------------------------------\n");
                printf("Masukkan ID Dosen: ");
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = 0; 

                printf("Masukkan Nama Dosen: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; 

                printf("-------------------------------------\n");
                printf("Pilih Jabatan Dosen\n");
                printf("-------------------------------------\n");
                printf("1.Dosen Tetap Program Studi\n");
                printf("2.Dosen Tetap Guru Besar\n");
                printf("3.Dosen Tetap Lektor Kepala \n");
                printf("Masukkan Jabatan Dosen : ");
                scanf("%d",&pilihanJabatan);
                if (pilihanJabatan == 1)
                {
                    // strncpy (destination,source,n)
                    strncpy(jabatan,"Dosen Tetap Program Studi", sizeof(jabatan)-1); //sizeof(jabatan)-1 digunakan untuk membatasi karakter yang akan di salin
                } else if (pilihanJabatan == 2)
                {
                    // strncpy (destination,source,n)
                    strncpy(jabatan,"Dosen Tetap Guru Besar", sizeof(jabatan)-1);//sizeof(jabatan)-1 digunakan untuk membatasi karakter yang akan di salin
                } else if (pilihanJabatan == 3)
                {
                    // strncpy (destination,source,n)
                    strncpy(jabatan,"Dosen tetap Lektor Kepala", sizeof(jabatan)-1);//sizeof(jabatan)-1 digunakan untuk membatasi karakter yang akan di salin
                } else
                {
                    printf("Pilihan tidak valid");
                }
                
                tambah(&dataDosen[count], id, name, jabatan);
                count++;
                printf("===========================\n");
                printf("Dosen berhasil ditambahkan!\n");
                printf("===========================\n");
                break;
            }
            case 2: {
                char id_delete[25];
                printf("========================================\n");
                printf("Masukkan ID Dosen yang akan dihapus: ");
                printf("========================================\n");
                fgets(id_delete, sizeof(id_delete), stdin);
                id_delete[strcspn(id_delete, "\n")] = 0; 

                hapus_dosen(&count, dataDosen, id_delete);
                break;
            }
            case 3:
                if (count == 0) {
                    printf("Data Dosen belum ada!\n");
                } else {
                    printf("-------------------------------------\n");
                    for (int i = 0; i < count; i++) {
                  
                        printf("ID: %s\n", dataDosen[i].id);
                        printf("Nama Dosen: %s\n", dataDosen[i].name);
                        printf("Jabatan: %s\n", dataDosen[i].jabatan);
                        printf("-------------------------------------\n");
                    }
                }
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
            }
        } else if (chooise == 2) {
            int result;
            printf("\n === Penilaian Dosen Matakuliah ===\n");

            if (count > 6)
            {
               printf("Skor = 4\n");
            } else if (count >= 3 && count <= 6)
            {
             result = (count*2)/3;
             printf("Skor = %d ", result);   
            } else
            {
                printf("Jumlah Dosen Terlalu Sedikit, Silahkan Input Kembali!");
            }

             printf("\n===============================\n");
        } 
        else if (chooise == 3)
        {
           float pgblk;
            int ndgb, ndlk;

            printf("Masukkan Jumlah Dosen Tetap Guru Besar : \n");
            scanf("%d",&ndgb);
            printf("Masukkan Jumlah Dosen Tetap Letor Kepala : \n");
            scanf("%d",&ndlk);
            if (count == 0)
            {
                printf("Data dosen kosong!,Tambahkan dosen terlebih dahulu\n");
            } else
            pgblk = ((ndgb + ndlk) * 100.0) / count;
            printf("Hasil Presentase Guru Besar dan Lektor Kepala : %f%%\n", pgblk);
            {
                if (pgblk >= 70.0)
                {
                    printf("Skor : 4");
                }
                else if (pgblk < 70.0)
                {
                    float hasil = 2.0 + ((0.20*pgblk)/7);
                    printf("Skor : %.2f\n",hasil);
                }else {
                    printf("Tidak ada skor kurang dari 2");
                }
            }
            
            
        }
        
         else if (chooise == 4)
        {
           printf("Terima kasih telah menggunakan program ini.\n");
           break;
        }
        else {
            printf("Pilihan tidak valid, coba lagi.\n");
            break;
        }
    } while (1);

    return 0;
}

