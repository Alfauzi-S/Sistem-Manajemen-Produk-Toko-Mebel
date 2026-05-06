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
    int idProduk;
    string namaProduk;
    string jenisProduk;
    int stock;
    int harga;
    material material;
};

struct keranjang {
    string nama;
    int idProduk;
    string namaProduk;
    int harga;
    int jumlah;
};

struct transaksi {
    int idTransaksi;
    keranjang keranjang;
};

#define maxadmin 1
#define maxuser 100
#define maxproduk 100
#define maxtransaksi 100
#define maxkeranjang 100

int adminIndex = 1;
int userIndex = 1;
int mabelIndex = 5;
int transaksiIndex = 0;
int keranjangIndex = 0;

dataAdmin admin[maxadmin];
pengguna user[maxuser];
produk mabel[maxproduk];
transaksi transaksiUser[maxtransaksi];
keranjang keranjangUser[maxkeranjang];

#endif