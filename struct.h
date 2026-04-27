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
    long long saldo;
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
    long long stock;
    long long harga;
    material material;
};

#define maxadmin 1
#define maxuser 100
#define maxproduk 100

int adminIndex = 1;
int userIndex = 1;
int mabelIndex = 5;

dataAdmin admin[maxadmin];
pengguna user[maxuser];
produk mabel[maxproduk];

#endif