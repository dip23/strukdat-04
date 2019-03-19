/*
Nama		: Difa Bagasputra M
NPM			: 140810180057
Nama Program: Program Manipulasi Data pegawai
Tahun		: 2019
*/
#include <iostream>

using namespace std;

struct ElementList{
	char nama[100];
	char bidang[20];
	long int gaji;
	ElementList* next;
};

typedef ElementList* pointer;
typedef pointer list;

void createList(list& first){
	first=NULL;
}

void createElement(pointer& pBaru){
	pBaru=new ElementList;
	cout<<"Nama\t: ";cin.ignore();cin.getline(pBaru->nama,100);
	cout<<"Bidang\t: ";cin.getline(pBaru->bidang,20);
	cout<<"Gaji\t: ";cin>>pBaru->gaji;
	pBaru->next=NULL;
}

void insertFirst(list& first, pointer pBaru){
	if(first==NULL){
		first=pBaru;
	}else{
		pBaru->next=first;
		first=pBaru;
	}
}

void insertLast(list& first, pointer pBaru){
	pointer last;
	if(first==NULL)
		first=pBaru;
	else{
		last=first;
		while (last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}

void traversal(list first){
	pointer pBantu;
	int i=1;
	
	if(first==NULL){
		cout<<"List Kosong"<<endl;
	}else{
		pBantu=first;
		while(pBantu!= NULL){
			cout<<i<<". "<<pBantu->nama<<" "<<pBantu->bidang<<" "<<pBantu->gaji<<endl;
			pBantu=pBantu->next;
			i++;
		}
	}
}

void deleteFirst(list& first, pointer& pHapus){
	if(first==NULL){
		pHapus=NULL;
		cout<<"List kosong"<<endl;
	}else if(first->next==NULL){
		pHapus=first;
		first=NULL;
	}else{
		pHapus=first;
		first=first->next;
		pHapus->next=NULL;
	}
}

void deleteLast(list& first, pointer& pHapus){
	pointer last,precLast;
	if(first==NULL){
		cout<<"List Kosong";
	}else if(first->next==NULL){
		pHapus=first;
		first=NULL;
	}else{
		last=first;
		precLast=NULL;
		while(last->next!=NULL){
			precLast=last;
			last=last->next;
		}
		pHapus=last;
		precLast->next=NULL;
	}
}

int main(){
	pointer p;
	list pgw;
	int pil;
	
	do{
		cout<<"Menu"<<endl;
		cout<<"1. Insert First"<<endl;
		cout<<"2. Insert Last"<<endl;
		cout<<"3. Delete First"<<endl;
		cout<<"4. Delete Last"<<endl;
		cout<<"5. Traversal"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Masukkan Pilihan   :";
		cin >> pil;
		switch(pil){
			case 1:
				createElement(p);
				insertFirst(pgw,p);
				cout<<"\nData berhasil dibuat!\n";
			break;
			case 2:
				createElement(p);
				insertLast(pgw,p);
				cout<<"\nData berhasil dibuat!\n";
				break;
			case 3:
				deleteFirst(pgw,p);
				cout<<"\nData berhasil dihapus!\n";
				break;
			case 4:
				deleteLast(pgw,p);
				cout<<"\nData berhasil dihapus!\n";
				break;
			case 5:
				traversal(pgw);
				break;
			case 6:
				break;
			default:
				cout<<"Input Salah, Coba lagi.."<<endl;
				break;
		}
	}while(pil!=6);
		
	return 0;
}
