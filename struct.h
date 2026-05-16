// Done
#ifndef STRUCT_H
#define STRUCT_H

#include "library.h"

struct alamat {
    string jalan;
    string kota;
    string provinsi;
};

struct pengguna {
    string nama;
    string password;
    string email;
    int saldo;
    alamat alamat;
};

struct dataAdmin {
    string nama;
    string password;
};

struct material {
    string idMaterial;
    string namaMaterial;
    string jenisMaterial;
};

struct produk {
    string idProduk;
    string namaProduk;
    string jenisProduk;
    int stock;
    int harga;
    material material;
};

struct keranjang {
    string nama;
    string idProduk;
    string namaProduk;
    int harga;
    int jumlah;
};

#define maxadmin 100
#define maxuser 100
#define maxproduk 100
#define maxmaterial 100
#define maxkeranjang 100

int adminIndex = 1;
int userIndex = 3;
int mabelIndex = 5;
int materialIndex = 4;
int keranjangIndex = 0;

dataAdmin admin[maxadmin];
pengguna user[maxuser];
produk mabel[maxproduk];
material materialDb[maxmaterial];
keranjang keranjangUser[maxkeranjang];

#endif