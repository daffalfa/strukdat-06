#include<iostream>
#include<string.h>
using namespace std;
struct kontak
{
	char nama[10];
	char nomor[12];
	kontak* nextkontak;
};
struct indeks
{
	char info[5];
	kontak* FirstKontak;
	indeks* next;
};
typedef indeks* pointerindeks;
typedef kontak* pointerKontak;
typedef pointerindeks list;

void createList(list& First){
	First=NULL;
}
void createElmtindeks(pointerindeks& pBaru)
{
	pBaru = new indeks;
	cout<<"Masukkan indeks :"; cin>>pBaru->info;
	pBaru->next=NULL;
	pBaru->FirstKontak=NULL;

}
void createElmtKontak(pointerKontak& pBaru)
{
	pBaru= new kontak;
	cout<<"Masukkan nama kontak:"; cin>>pBaru->nama;
	cout<<"Masukkan nomor:"; cin>>pBaru->nomor;
	pBaru->nextkontak=NULL;
}
void insertFirstindeks(list& First,pointerindeks pBaru)
{
	if(First==NULL)
    {
		First=pBaru;
	}
	else{
		pBaru->next=First;
		First=pBaru;
	}
}
void traversalindeks(list First)
{
	pointerindeks pBantu;
	pBantu=First;
	while(pBantu!=NULL){
		cout<<"indeks :"<<pBantu->info<<",";
		pBantu=pBantu->next;
	}
}
void linearSearch(list First,char key[5],int& status,pointerindeks& pCari)
{
	status=0;
	pCari=First;
	while(status==0 && pCari!=NULL)
    {
		if(strcmp(pCari->info,key)==0)
		{
			status=1;
		}
		else
		{
			pCari=pCari->next;
		}
	}
}
void insertFirstKontak(list& First,char key[5],pointerKontak pBaru)
{

	pointerindeks pIn;
	int ketemu;
	cout<<"Masukkan indeks yang di cari: "; cin>>key;
	linearSearch(First,key,ketemu,pIn);
	if(ketemu)
    {
		cout<<"Ditemukan dengan indeks :"<<pIn->info<<endl;
		if(pIn->FirstKontak==NULL)
		{
			pIn->FirstKontak=pBaru;
		}
		else
		{
			pBaru->nextkontak=pIn->FirstKontak;
			pIn->FirstKontak=pBaru;
		}
	}
	else{
		cout<<"indeks  tidak di temukan"<<endl;
	}
}
void deleteFirstKontak(list& First,char key[5],pointerKontak& pHapus )
{
	int ketemu;
	pointerindeks pIn;
	cout<<"Masukkan indeks yang di cari: "; cin>>key;
	linearSearch(First,key,ketemu,pIn);
		if(ketemu){
		cout<<"Ditemukan dengan indeks :"<<pIn->info;
		if(pIn->FirstKontak==NULL)
        {
			cout<<"Tidak ada yang di hapus"<<endl;
		}
		else if(pIn->FirstKontak->nextkontak==NULL)
		{
			pHapus=pIn->FirstKontak;
			pIn->FirstKontak=NULL;
		}
		else{
			pHapus=pIn->FirstKontak;
			pIn->FirstKontak=pIn->FirstKontak->nextkontak;
			pHapus->nextkontak=NULL;

		}
	}
	else{
		cout<<"indeks tidak di temukan"<<endl;
	}

}
void traversalindeksKontak(list First)
{
	pointerindeks pBantuindeks;
	pointerKontak pBantuKontak;
	cout<<"Traversal Divisi"<<endl;
	pBantuindeks=First;
	while (pBantuindeks!=NULL)
    {
	cout<<"indeks ="<<pBantuindeks->info <<endl;
	pBantuKontak=pBantuindeks->FirstKontak;
	while (pBantuKontak!=NULL)
	{
	cout<<pBantuKontak->nama<<" / "<<pBantuKontak->nomor<<endl;
	pBantuKontak=pBantuKontak->nextkontak;
	}
	pBantuindeks=pBantuindeks->next;
	}
}
void updateKontak(list First,char key[10],int& status,pointerindeks& pindeks)
{
	status=0;

	pointerKontak pK,pb;
	pindeks=First;
	pK=pindeks->FirstKontak;
	cout<<"Masukkan nama kontak :"; cin>>key;
	while(pindeks!=NULL)
    {
		while(status== 0 && pK!=NULL)
        {
			if(strcmp(pK->nama,key)==0)
			{
				cout<<"Masukkan Nama :"; cin>>pK->nama;
				cout<<"Masukkan Nomor :"; cin>>pK->nomor;
			status=1;
			}
			else if(pK->nextkontak==NULL)
			{
				status=1;
			}
			else {
				pK=pK->nextkontak;
			}

		}
			pindeks=pindeks->next;
    }
}


main()
{
	pointerindeks pI;
	pointerKontak pK,phk;
	list q;
	char key[5],nama[10];
	int ni,nk,ketemu;
	createList(q);
	cout<<"Masukkan Banyak indeks :"; cin>>ni;
	for(int i=0;i<ni;i++){
		createElmtindeks(pI);
		insertFirstindeks(q,pI);
	}
	cout<<"Masukkan banyak kontak :"; cin>>nk;
	for(int i=0;i<nk;i++){
		createElmtKontak(pK);
		insertFirstKontak(q,key,pK);
	}
		traversalindeksKontak(q);

	updateKontak(q,nama,ketemu,pI);
	traversalindeksKontak(q);


}

