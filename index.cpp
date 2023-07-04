#include<iostream>
using namespace std;

struct Tugas{
	string judul;
	bool status;
	string deskripsi;
	string deadline;
	Tugas *next;
};

Tugas *head = NULL;
Tugas *tail = NULL;

void buatTugas(string judul, string deskripsi, string deadline, bool status){
	Tugas *newNode = new Tugas();
	newNode->judul = judul;
	newNode->deskripsi = deskripsi;
	newNode->deadline = deadline;
	newNode->status = status;
	newNode->next = NULL;
	
	if (head == NULL) {
		head = newNode;
		tail = newNode;
	} else {
		tail->next = newNode;
		tail = newNode;
	}
}

int hitungJumlahTugas(){
	Tugas *cur = head;
	int jumlah = 0;
	while (cur != NULL){
		jumlah++;
		cur = cur->next;
	}
	return jumlah;
}

void tambahDiAwal(string judul, string deskripsi, string deadline, bool status){
	Tugas *newNode = new Tugas();
	newNode->judul = judul;
	newNode->deskripsi = deskripsi;
	newNode->deadline = deadline;
	newNode->status = status;
	newNode->next = head;
	head = newNode;
}

void tambahDiAkhir(string judul, string deskripsi, string deadline, bool status){
	Tugas *newNode = new Tugas();
	newNode->judul = judul;
	newNode->deskripsi = deskripsi;
	newNode->deadline = deadline;
	newNode->status = status;
	newNode->next = NULL;
	
	if (head == NULL) {
		head = newNode;
		tail = newNode;
	} else {
		tail->next = newNode;
		tail = newNode;
	}
}

void tambahTengah(string judul, string deskripsi, string deadline, bool status, int posisi){
	if (posisi < 1 || posisi > hitungJumlahTugas()){
		cout << "posisi diluar jangkauan" << endl;
	} else if (posisi == 1){
		tambahDiAwal(judul, deskripsi, deadline, status);
	} else if (posisi == hitungJumlahTugas()){
		tambahDiAkhir(judul, deskripsi, deadline, status);
	} else {
		Tugas *newNode = new Tugas();
		newNode->judul = judul;
		newNode->deskripsi = deskripsi;
		newNode->deadline = deadline;
		newNode->status = status;
		
		Tugas *cur = head;
		int nomor = 1;
		while (nomor < posisi-1){
			cur = cur->next;
			nomor++;
		}
		newNode->next = cur->next;
		cur->next = newNode;
	}
}

void hapusDiAwal(){
	if (head == NULL){
		cout << "Tidak ada tugas yang bisa dihapus" << endl;
	} else {
		Tugas *del = head;
		head = head->next;
		delete del;
	}
}

void hapusDiAkhir(){
	if (head == NULL){
		cout << "Tidak ada tugas yang bisa dihapus" << endl;
	} else {
		Tugas *cur = head;
		Tugas *del = tail;
		while (cur->next != tail){
			cur = cur->next;
		}
		tail = cur;
		tail->next = NULL;
		delete del;
	}
}

void hapusTengah(int posisi){
	if (posisi < 1 || posisi > hitungJumlahTugas()){
		cout << "posisi diluar jangkauan" << endl;
	} else if (posisi == 1){
		hapusDiAwal();
	} else if (posisi == hitungJumlahTugas()){
		hapusDiAkhir();
	} else {
		Tugas *before = NULL;
		Tugas *cur = head;
		int nomor = 1;
		while (nomor <= posisi){
			if (nomor == posisi-1){
				before = cur;
			}
			if (nomor == posisi){
				Tugas *del = cur;
				before->next = cur->next;
				delete del;
				break;
			}
			cur = cur->next;
			nomor++;
		}
	}
}

void ubahDiAwal(string judul, string deskripsi, string deadline, bool status){
	if (head != NULL){
		head->judul = judul;
		head->deskripsi = deskripsi;
		head->deadline = deadline;
		head->status = status;
	}
}

void ubahDiAkhir(string judul, string deskripsi, string deadline, bool status){
	if (head != NULL){
		tail->judul = judul;
		tail->deskripsi = deskripsi;
		tail->deadline = deadline;
		tail->status = status;
	}
}

void ubahTengah(string judul, string deskripsi, string deadline, bool status, int posisi){
	if (posisi < 1 || posisi > hitungJumlahTugas()){
		cout << "posisi diluar jangkauan" << endl;
	} else if (posisi == 1){
		ubahDiAwal(judul, deskripsi, deadline, status);
	} else if (posisi == hitungJumlahTugas()){
		ubahDiAkhir(judul, deskripsi, deadline, status);
	} else {
		Tugas *cur = head;
		int nomor = 1;
		while (nomor < posisi){
			cur = cur->next;
			nomor++;
		}
		cur->judul = judul;
		cur->deskripsi = deskripsi;
		cur->deadline = deadline;
		cur->status = status;
	}
}

void lihatTugas(int posisi){
	if (posisi < 1 || posisi > hitungJumlahTugas()){
		cout << "posisi diluar jangkauan" << endl;
	} else {
		Tugas *cur = head;
		int nomor = 1;
		while (nomor < posisi){
			cur = cur->next;
			nomor++;
		}
		cout << "judul     : " << cur->judul << endl;
		cout << "deskripsi : " << cur->deskripsi << endl;
		cout << "deadline  : " << cur->deadline << endl;
		cout << "status    : " << cur->status << endl;
	}
}

void printTugas(){
	Tugas *cur = head;
	while (cur != NULL){
		cout << "judul     : " << cur->judul << endl;
		cout << "deskripsi : " << cur->deskripsi << endl;
		cout << "deadline  : " << cur->deadline << endl;
		cout << "status    : " << cur->status << endl;
		cur = cur->next;
	}
}

int main(){
	int pil1, pil2;
	string judul, deskripsi, deadline;
	bool status;
	
	start:
	cout << "============Pilihan menu==============" << endl;
	cout << "1. Tambah tugas" << endl;
	cout << "2. Hapus tugas" << endl;
	cout << "3. Ubah tugas" << endl;
	cout << "4. Lihat tugas" << endl;
	cout << "Masukkan pilihan Anda di sini: ";
	cin >> pil1;

	switch (pil1){
		case 1:
			cout << "Pilih 1/2/3: ";
			cin >> pil2;
			if (pil2 == 1){
				cout << "Masukkan judul tugas: ";
				cin >> judul;
				cout << "Masukkan deskripsi tugas: ";
				cin >> deskripsi;
				cout << "Masukkan deadline: ";
				cin >> deadline;
				cout << "Masukkan status: ";
				cin >> status;
				tambahDiAwal(judul, deskripsi, deadline, status);
				printTugas();
				goto start;
			} else if (pil2 == 2){
				cout << "Masukkan judul tugas: ";
				cin >> judul;
				cout << "Masukkan deskripsi tugas: ";
				cin >> deskripsi;
				cout << "Masukkan deadline: ";
				cin >> deadline;
				cout << "Masukkan status: ";
				cin >> status;
				tambahDiAkhir(judul, deskripsi, deadline, status);
				printTugas();
				goto start;
			} else if (pil2 == 3){
				int posisi;
				cout << "Masukkan posisi tugas: ";
				cin >> posisi;
				cout << "Masukkan judul tugas: ";
				cin >> judul;
				cout << "Masukkan deskripsi tugas: ";
				cin >> deskripsi;
				cout << "Masukkan deadline: ";
				cin >> deadline;
				cout << "Masukkan status: ";
				cin >> status;
				tambahTengah(judul, deskripsi, deadline, status, posisi);
				printTugas();
				goto start;
			} else {
				cout << "Pilihan tidak valid" << endl;
				goto start;
			}
			break;
			
		case 2:
			cout << "Pilih 1/2/3: ";
			cin >> pil2;
			if (pil2 == 1){
				hapusDiAwal();
				printTugas();
				goto start;
			} else if (pil2 == 2){
				hapusDiAkhir();
				printTugas();
				goto start;
			} else if (pil2 == 3){
				int posisi;
				cout << "Masukkan posisi tugas: ";
				cin >> posisi;
				hapusTengah(posisi);
				printTugas();
				goto start;
			} else {
				cout << "Pilihan tidak valid" << endl;
				goto start;
			}
			break;
			
		case 3:
			cout << "Pilih 1/2/3: ";
			cin >> pil2;
			if (pil2 == 1){
				cout << "Masukkan judul tugas: ";
				cin >> judul;
				cout << "Masukkan deskripsi tugas: ";
				cin >> deskripsi;
				cout << "Masukkan deadline: ";
				cin >> deadline;
				cout << "Masukkan status: ";
				cin >> status;
				ubahDiAwal(judul, deskripsi, deadline, status);
				printTugas();
				goto start;
			} else if (pil2 == 2){
				cout << "Masukkan judul tugas: ";
				cin >> judul;
				cout << "Masukkan deskripsi tugas: ";
				cin >> deskripsi;
				cout << "Masukkan deadline: ";
				cin >> deadline;
				cout << "Masukkan status: ";
				cin >> status;
				ubahDiAkhir(judul, deskripsi, deadline, status);
				printTugas();
				goto start;
			} else if (pil2 == 3){
				int posisi;
				cout << "Masukkan posisi tugas: ";
				cin >> posisi;
				cout << "Masukkan judul tugas: ";
				cin >> judul;
				cout << "Masukkan deskripsi tugas: ";
				cin >> deskripsi;
				cout << "Masukkan deadline: ";
				cin >> deadline;
				cout << "Masukkan status: ";
				cin >> status;
				ubahTengah(judul, deskripsi, deadline, status, posisi);
				printTugas();
				goto start;
			} else {
				cout << "Pilihan tidak valid" << endl;
				goto start;
			}
			break;
			
		case 4:
			int posisi;
			cout << "Masukkan posisi tugas: ";
			cin >> posisi;
			lihatTugas(posisi);
			goto start;
			break;
			
		default:
			cout << "Pilihan tidak valid" << endl;
			goto start;
			break;
	}

	return 0;
}
