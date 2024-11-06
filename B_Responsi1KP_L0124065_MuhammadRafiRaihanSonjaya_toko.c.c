#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//untuk setiap input yang dilakukan
int input;

// Counter untuk jumlah item di keranjang
int keranjangCount = 0; 

// Membuat struct untuk menyimpan nama dan harga
struct keranjang {
    char nama[30];
    int harga;
};

// Menyimpan maksimal 100 item di keranjang
struct keranjang listKeranjang[100]; 

 //menyimpan kategori barang yang dijual melalui array kategori
char kategori[3][20] = {"Handphone", "Laptop", "CPU"};

struct list {          
    char nama[30];
    int harga;      // membuat struct, jadi tiap barang itu mempunyai nama harga dan stock nya
    int stock;
};

//membuat array list Handphone dari struct list yang berisi nama harga dan stok
struct list listHandphone[3] = {
    {"IPHONE 15 PRO", 21, 5},
    {"SAMSUNG GALAXY S24 ULTRA", 20, 8},    
    {"HUAWEI MATE 60 PRO", 23, 11}
};

//membuat array list Laptop dari struct list yang berisi nama harga dan stok
struct list listLaptop[3] = {
    {"ASUS VIVOBOOK", 10, 3},
    {"HP PAVILION", 14, 7},                 
    {"THINKPAD", 7, 1}
};

//membuat array list CPU dari struct list yang berisi nama harga dan stok
struct list listCPU[3] = {
    {"INTEL CORE I9-7920X", 17, 6},
    {"INTEL CORE I7-14700K", 7, 3},         
    {"INTEL CORE I5-10400F", 2, 1}
};

//fungsi print barang untuk kategori yang diminta
void printList(struct list *point) {
    // print barang dalam masing-masing kategori
    printf("%s\n", point->nama);
    printf("   Harga         : %d juta\n", point->harga);   
    printf("   Stok tersedia : %d\n\n", point->stock);
}

//membuat fungsi untuk pengecekan keranjang
void printKeranjang() {
     //membuat pengkondisian jika keranjang masih kosong
    if (keranjangCount == 0) {
        printf("Keranjang Anda kosong.\n\n");  
    } else {
        printf("Keranjang Anda:\n");
        //nge list setiap keranjang setelah user memasukan barang kedalam keranjang
        for (int i = 0; i < keranjangCount; i++) {       
            printf("%d. %s - %d juta\n", i + 1, listKeranjang[i].nama, listKeranjang[i].harga); 
        }
        printf("\n");
    }
}

// Fungsi rekursif untuk menghitung total harga keranjang
int hitungTotal(int index) {
    if (index < 0) {
        // fungsinya akan berhenti jika index nya habis
        return 0; 
    }
//memanggil kembali fungsi, mengurangi parameter fungsi dengan 1
    return listKeranjang[index].harga + hitungTotal(index - 1); 
}

//membuat fungsi untuk checkout keranjang
void checkoutKeranjang() { 
    //membuat kondisi jika keranjangnya masih 0, maka print keranjang kosong
    if (keranjangCount == 0) {  
        printf("Keranjang Anda kosong.\n\n");
    } else {
        printf("Checkout Keranjang:\n");
        for (int i = 0; i < keranjangCount; i++) {
            printf("%d. %s - %d juta\n", i + 1, listKeranjang[i].nama, listKeranjang[i].harga);
        }
        // Menghitung total menggunakan fungsi rekursif
        int total = hitungTotal(keranjangCount - 1); 
        printf("=========================\n");
        printf("Total pembayaran: %d juta\n\n", total);
        printf("Terimakasih telah berbelanja di toko kami!\n\n");
        printf("Keranjang akan dikosongkan\n");
        keranjangCount = 0; // untuk mengosongkan keranjang setelah checkout
    }
}

//fungsi setelah pengguna memasukan barang ke dalam keranjang
void menambahkanKeDalamKeranjang(struct list item, char *kategori) {
    // Batas maksimal 100 barang di dalam keranjang
    if (keranjangCount < 100) { 
        system("cls");
        strcpy(listKeranjang[keranjangCount].nama, item.nama);
        listKeranjang[keranjangCount].harga = item.harga;
        keranjangCount++;
        printf("%s telah dimasukkan ke dalam keranjang.\n\n", item.nama);
        printf("Tekan apa saja untuk kembali\n");
        //berfungsi untuk menunngu pengguna menekan tombol, lalu kembali ke menu utama
        getch(); 
    } else {
        printf("Keranjang penuh, tidak dapat menambahkan item.\n\n");
    }
}

//fungsi untuk menampilkan barang sesaui dengan kategori yang dipilih   
void displayKategori(struct list items[], int size, char *kategori) {
    system("cls");
    for (int i = 0; i < size; i++) {
        printf("%d. ", i + 1);
        printList(&items[i]);
    }
    printf("=============================================================\n");
    printf("Masukkan angka (1-%d) jika ingin memasukkan ke dalam keranjang\n", size);
    printf("0. Kembali\n");
    //membuat pilihan pengguna ingin kembali, atau memasukan barang ke dalam keranjang
    scanf("%d", &input); 

    if (input == 0) {
        system("cls");
    } else if (input >= 1 && input <= size) {
        menambahkanKeDalamKeranjang(items[input - 1], kategori);
    }
}

//fungsi untuk menampilkan kategori barang yang dijual
void tampilkanMenuKategori() {
    system("cls");
    printf("Kategori barang yang kami jual\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, kategori[i]);
    }
    printf("0. Kembali\n");
    //meminta input untuk menanyakan ingin melihat barang apa
    scanf("%d", &input);
    
    if (input == 1) {
        displayKategori(listHandphone, 3, "Handphone");
    } else if (input == 2) {
        displayKategori(listLaptop, 3, "Laptop");
    } else if (input == 3) {
        displayKategori(listCPU, 3, "CPU");
    }
}

//fungsi untuk fitur melihat keranjang
void lihatKeranjang() {
    system("cls");
    printKeranjang();
    printf("tekan tombol apa saja untuk kembali\n");
    getch();
}

//fungsi untuk fitur checkout
void checkout() {
    system("cls");
    checkoutKeranjang();
    printf("\ntekan tombol apa saja untuk kembali\n");
    getch();
}

//fungsi untuk menu utama
void tampilkanMenuUtama() {
    system("cls");
    printf(" ##::::::::::'###::::'########:::::'###::::'##:::'##:'########:::::'###::::'########:'####:\n");
    printf(" ##:::::::::'## ##::: ##.... ##:::'## ##::: ##::'##:: ##.... ##:::'## ##::: ##.....::. ##::\n");
    printf(" ##::::::::'##:. ##:: ##:::: ##::'##:. ##:: ##:'##::: ##:::: ##::'##:. ##:: ##:::::::: ##::\n");
    printf(" ##:::::::'##:::. ##: ########::'##:::. ##: #####:::: ########::'##:::. ##: ######:::: ##::\n");
    printf(" ##::::::: #########: ##.....::: #########: ##. ##::: ##.. ##::: #########: ##...::::: ##::\n");
    printf(" ##::::::: ##.... ##: ##:::::::: ##.... ##: ##:. ##:: ##::. ##:: ##.... ##: ##:::::::: ##::\n");
    printf(" ########: ##:::: ##: ##:::::::: ##:::: ##: ##::. ##: ##:::. ##: ##:::: ##: ##:::::::'####:\n");
    printf("Selamat datang di lapak rafi\n");
    printf("1. Melihat list barang\n");
    printf("2. Exit\n");
    printf("3. Lihat keranjang\n");
    printf("4. Checkout keranjang\n");
    scanf("%d", &input);
}

//fungsi untuk memulai program
void jalankanProgram() {
    //dikasih tanda 1 untuk menandakan program masih berjalan
    int menjalankanProgram = 1;
    while (menjalankanProgram == 1) {
        tampilkanMenuUtama();
        
        if (input == 1) {
            tampilkanMenuKategori();
        } else if (input == 2) {
            system("cls");
            printf("TTTTTTTTTTTTTTTTTTTTTTT                                     iiii                                            KKKKKKKKK    KKKKKKK                                    iiii hhhhhhh             \n");
            printf("T:::::::::::::::::::::T                                    i::::i                                           K:::::::K    K:::::K                                   i::::ih:::::h             \n");
            printf("T:::::::::::::::::::::T                                     iiii                                            K:::::::K    K:::::K                                    iiii h:::::h             \n");
            printf("T:::::TT:::::::TT:::::T                                                                                     K:::::::K   K::::::K                                         h:::::h             \n");
            printf("TTTTTT  T:::::T  TTTTTTeeeeeeeeeeee    rrrrr   rrrrrrrrr  iiiiiii    mmmmmmm    mmmmmmm     aaaaaaaaaaaaa   KK::::::K  K:::::KKK  aaaaaaaaaaaaa      ssssssssss   iiiiiii h::::h hhhhh       \n");
            printf("        T:::::T      ee::::::::::::ee  r::::rrr:::::::::r i:::::i  mm:::::::m  m:::::::mm   a::::::::::::a    K:::::K K:::::K     a::::::::::::a   ss::::::::::s  i:::::i h::::hh:::::hhh    \n");
            printf("        T:::::T     e::::::eeeee:::::eer:::::::::::::::::r i::::i m::::::::::mm::::::::::m  aaaaaaaaa:::::a   K::::::K:::::K      aaaaaaaaa:::::ass:::::::::::::s  i::::i h::::::::::::::hh  \n");
            printf("        T:::::T    e::::::e     e:::::err::::::rrrrr::::::ri::::i m::::::::::::::::::::::m           a::::a   K:::::::::::K                a::::as::::::ssss:::::s i::::i h:::::::hhh::::::h \n");
            printf("        T:::::T    e:::::::eeeee::::::e r:::::r     r:::::ri::::i m:::::mmm::::::mmm:::::m    aaaaaaa:::::a   K:::::::::::K         aaaaaaa:::::a s:::::s  ssssss  i::::i h::::::h   h::::::h\n");
            printf("        T:::::T    e:::::::::::::::::e  r:::::r     rrrrrrri::::i m::::m   m::::m   m::::m  aa::::::::::::a   K::::::K:::::K      aa::::::::::::a   s::::::s       i::::i h:::::h     h:::::h\n");
            printf("        T:::::T    e::::::eeeeeeeeeee   r:::::r            i::::i m::::m   m::::m   m::::m a::::aaaa::::::a   K:::::K K:::::K    a::::aaaa::::::a      s::::::s    i::::i h:::::h     h:::::h\n");
            printf("        T:::::T    e:::::::e            r:::::r            i::::i m::::m   m::::m   m::::ma::::a    a:::::a KK::::::K  K:::::KKKa::::a    a:::::assssss   s:::::s  i::::i h:::::h     h:::::h\n");
            printf("      TT:::::::TT  e::::::::e           r:::::r           i::::::im::::m   m::::m   m::::ma::::a    a:::::a K:::::::K   K::::::Ka::::a    a:::::as:::::ssss::::::si::::::ih:::::h     h:::::h\n");
            printf("      T:::::::::T   e::::::::eeeeeeee   r:::::r           i::::::im::::m   m::::m   m::::ma:::::aaaa::::::a K:::::::K    K:::::Ka:::::aaaa::::::as::::::::::::::s i::::::ih:::::h     h:::::h\n");
            printf("      T:::::::::T    ee:::::::::::::e   r:::::r           i::::::im::::m   m::::m   m::::m a::::::::::aa:::aK:::::::K    K:::::K a::::::::::aa:::as:::::::::::ss  i::::::ih:::::h     h:::::h\n");
            printf("      TTTTTTTTTTT      eeeeeeeeeeeeee   rrrrrrr           iiiiiiiimmmmmm   mmmmmm   mmmmmm  aaaaaaaaaa  aaaaKKKKKKKKK    KKKKKKK  aaaaaaaaaa  aaaa sssssssssss    iiiiiiiihhhhhhh     hhhhhhh\n");
            printf("\n");
            //diubah menjadi 0 agar program berhenti
            menjalankanProgram = 0;
        } else if (input == 3) {
            lihatKeranjang();
        } else if (input == 4) {
            checkout();
        } else {
            printf("Pilihan tidak valid\n");
        }
    }
}

int main() {
    //memanggil fungsi untuk menjalankan program
    jalankanProgram();
    return 0;
}
