#include <iostream>
#include<conio.h>
#include<windows.h>
#include <stdio.h>
using namespace std;

int pil;
void pilih();
void buat_baru();
void tambah_data1();
void tambah_data2();
void hapus_data1();
void hapus_data2();
void tampil();

struct simpul{
 char nim[8], nama[80];
 int umur;
 struct simpul *next;
}mhs, *baru, *awal=NULL, *akhir=NULL, *hapus, *bantu;

void clrscr(){
 system("cls");
}

int main(){
 do{
  clrscr();
  cout << "MENU SINGLE  LINKEDLIST" << endl;
  cout << "1. Tambah data1" << endl;
  cout << "2. Tambah data2" << endl;
  cout << "3. Hapus data1" << endl;
  cout << "4. Hapus data2" << endl;
  cout << "5. Tampil" << endl;
  cout << "6. Selesai" << endl;
  cout << "Pilihan anda: ";
  cin>>pil;
  pilih();
 }while (pil!=6);
 return 0;
}

void pilih()//fungsi "pilih" untuk pemrosesan
{
 if(pil==1){
  tambah_data1();
 }
 else if(pil==2){
  tambah_data2();
 }
 else if(pil==3){
  hapus_data1();
 }
 else if(pil==4){
  hapus_data2();
 }
 else if(pil==5){
  tampil();
 }
}

void buat_baru()//fungsi membuat data baru
{
 baru=(simpul*)malloc(sizeof(struct simpul));
 cout << "Input NIM : ";
 cin >> baru->nim;
 cout << "Input Nama : ";
 cin >>baru->nama;
 cout << "Input Umur : ";
 cin >> baru->umur;
 baru->next=NULL;
}

void tambah_data2()//fungsi membuat data2
{
 buat_baru();
 if(awal==NULL){
  awal=baru;
 }
 else{
  akhir->next=baru;
 }
 akhir=baru;
 akhir->next=NULL;
 cout << endl << endl;
 tampil();
}

void tambah_data1()//fungsi membuat data1
{
 buat_baru();
 if(awal==NULL){
  awal=baru;
  akhir=baru;
  akhir->next=NULL;
 }
 else{
  baru->next=awal;
  awal=baru;
 }
 cout << endl << endl;
 tampil();
}

void hapus_data1()//fungsi penghapusan data1
{
 if(awal==NULL){
  cout<<"kosong";
 }
 else{
  hapus = awal;
  awal=awal->next;
  free(hapus);
 }
 cout << endl << endl;
 tampil();
}

void hapus_data2()//fungsi penghapusan data2
{
 if(awal==NULL){
  cout << "Kosong";
 }
 else if(awal==akhir){
  hapus = awal;
  awal=awal->next;
  free(hapus);
 }
 else{
  hapus = awal;
  while(hapus->next != akhir){
   hapus = hapus->next;
   akhir=hapus;
   hapus=akhir->next;
   akhir->next=NULL;
   free(hapus);
  }
 }
 cout << endl << endl;
 tampil();
}

void tampil()//fungsi menampilkan data
{
{
 if(awal==NULL){
  cout << "Kosong";
 }
 else{
  bantu=awal;
  while(bantu!=NULL){
   cout << "NIM : " << bantu->nim << endl;
   cout << "NAMA : " << bantu->nama << endl;
   cout << "UMUR : " << bantu->umur << endl;


    bantu=bantu->next;
  }
 }
 getch();
}
