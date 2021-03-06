#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 100
#define COL 4
#define DATA_FILE_NAME "Data.txt" // tem file chua thong tin hoc sinh
#define Best_FILE_NAME "BestStudent.txt"
#define NoVan_FILE_NAME "NoVan.txt" 
#define NoToan_FILE_NAME "NoToan.txt"
struct Student
{
	long mssv; // 19110***
	float DiemT; // diem toan  ma mon la T
	float DiemV; // diem van ma mon la V
	float DiemTB; 
};
// Lay tong so sinh vien
int LaySoLuongSV();
// Sua so sinh vien
void SuaSoSV(int x);
// Lay 1 mang chua toan bo sinh vien
void LayToanBoSV(Student a[]);
// nhap sinh vien tu ban phim va tinh diem trung binh
void NhapSV();
// xoa sinh vien bang ma so sinh vien
void XoaSV(int mssv);
// sua thong tin sinh vien bang ma so sinh vien
void SuaSV(int mssv);
// xuat tat ca xinh vien
void XuatToanBoSV();
// tim sinh vien gioi nhat
Student BestStudent();
// Tim sinh vien co hoc bong
void HocBong();
// Tim no mon
void NoMon();

int main()
{
	char choice;
	do {
		cout << "\n\n\n\n\n\t\t\t\t\t        --------MENU--------";
		cout << "\n\n\t\t\t\t\t  |---   1. Lay so luong      ---|";
		cout << "\n\n\t\t\t\t\t  |---   2. Nhap sinh vien    ---|";
		cout << "\n\n\t\t\t\t\t  |---   3. Xoa sinh vien     ---|";
		cout << "\n\n\t\t\t\t\t  |---   4. Sua sinh vien     ---|";
		cout << "\n\n\t\t\t\t\t  |---   5. Xem toan bo       ---|";
		cout << "\n\n\t\t\t\t\t  |---   6. Hoc sinh gioi nhat---|";
		cout << "\n\n\t\t\t\t\t  |---   7. SV co hoc bong    ---|";
		cout << "\n\n\t\t\t\t\t  |---   8. SV no mon         ---|";
		cout << "\n\n\t\t\t\t\t  |---   9. Exit!             ---|";
		cout << "\n\n\t\t\t\t\t         Enter your choice: ";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case '1':
			
			break;
		case '2':
			store->InputEmployee();
			store->OutputEmployee();
			break;
		case '3':
			store->Display();
			break;
		case '4':
			store->SearchNameProduct();
			break;
		case '5':
			store->SearchNameEmployee();
			break;
		case '6':
			store->RemoveProduct();
			break;
		case '7':
			store->RemoveEmployee();
			break;
		case '8':
			store->SortingPriceProduct();
			break;
		case '9':
			break;
		default:
			cout << "\nThe your choice ERROR! Please choice again.";
			break;
		}

	} while (choice != '9');
	return 1;
}

// Lay tong so sinh vien
int LaySoLuongSV() {
	FILE* fp;
	fopen_s(&fp, DATA_FILE_NAME, "rt");
	if (fp == NULL) {
		cout << "Khong mo duoc tap tin Data.txt" << '\n';
		return 0;
	}
	int n;
	fscanf_s(fp, "%d", &n);
	fclose(fp);
	return n;
}
// Sua so sinh vien
void SuaSoSV(int x) {
	int n = LaySoLuongSV();
	FILE* fp;
	fopen_s(&fp, DATA_FILE_NAME, "r+");
	if (fp == NULL) {
		cout << "Khong mo duoc tap tin Data.txt" << '\n';
		return;
	}
	fprintf_s(fp, "%d\n", n + x);
	fclose(fp);
}
// Lay 1 mang chua toan bo sinh vien
void LayToanBoSV(Student a[]) {
	FILE* fp;
	fopen_s(&fp, DATA_FILE_NAME, "rt");
	if (fp == NULL) {
		cout << "Khong mo duoc tap tin Data.txt" << '\n';
		return;
	}
	int n;
	fscanf_s(fp, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf_s(fp, "%d", &a[i].mssv);
		fscanf_s(fp, "%g", &a[i].DiemT);
		fscanf_s(fp, "%g", &a[i].DiemV);
		fscanf_s(fp, "%g", &a[i].DiemTB);
	}
	fclose(fp);
}
// nhap sinh vien tu ban phim va tinh diem trung binh
void NhapSV() {
	cout << "So luong sinh vien muon nhap: ";
	int x; 
	cin >> x;
	
	SuaSoSV(x);

	FILE* fp;
	fopen_s(&fp, DATA_FILE_NAME, "a");
	if (fp == NULL) {
		cout << "Khong mo duoc tap tin Data.txt" << '\n';
		return;
	}

	for (int i = 0; i < x; i++)
	{
		Student st;
		cout << "Nhap sinh vien thu " << (i + 1) << '\n';
		cout << "MSSV: ";
		cin >> st.mssv;
		fprintf_s(fp, "%d\t", st.mssv);
		cout << "Diem Toan: ";
		cin >> st.DiemT;
		fprintf_s(fp, "%g\t", st.DiemT);
		cout << "Diem Van: ";
		cin >> st.DiemV;
		fprintf_s(fp, "%g\t", st.DiemV);
		st.DiemTB = (st.DiemT + st.DiemV) / 2;
		fprintf_s(fp, "%g\n", st.DiemTB);
	}
	fclose(fp);
}
// xoa sinh vien bang ma so sinh vien
void XoaSV(int mssv) {
	Student st[MAX];
	LayToanBoSV(st);
	int n = LaySoLuongSV();
	int k;
	for (int i = 0; i < n; i++)
	{
		if (st[i].mssv == mssv) {
			k = i;
		}
	}
	FILE* fp;
	fopen_s(&fp, DATA_FILE_NAME, "wt");
	if (fp == NULL) {
		cout << "Khong mo duoc tap tin Data.txt" << '\n';
		return;
	}
	fprintf_s(fp, "%d\n", n);
	for (int i = 0; i < n && i != k; i++)
	{
		fprintf_s(fp, "%d\t", st[i].mssv);
		fprintf_s(fp, "%g\t", st[i].DiemT);
		fprintf_s(fp, "%g\t", st[i].DiemV);
		fprintf_s(fp, "%g\n", st[i].DiemTB);
	}
	fclose(fp);
}
// sua thong tin sinh vien bang ma so sinh vien
void SuaSV(int mssv) {
	Student st[MAX];
	LayToanBoSV(st);
	int n = LaySoLuongSV();
	int k;
	for (int i = 0; i < n; i++)
	{
		if (st[i].mssv == mssv) {
			k = i;
		}
	}
	Student newSt;
	cout << "MSSV: ";
	cin >> newSt.mssv;
	cout << "Diem Toan: ";
	cin >> newSt.DiemT;
	cout << "Diem Van: ";
	cin >> newSt.DiemV;
	newSt.DiemTB = (newSt.DiemT + newSt.DiemV) / 2;

	FILE* fp;
	fopen_s(&fp, DATA_FILE_NAME, "wt");
	if (fp == NULL) {
		cout << "Khong mo duoc tap tin Data.txt" << '\n';
		return;
	}
	fprintf_s(fp, "%d\n", n);
	for (int i = 0; i < n; i++)
	{
		if (i == k) {
			fprintf_s(fp, "%d\t", newSt.mssv);
			fprintf_s(fp, "%g\t", newSt.DiemT);
			fprintf_s(fp, "%g\t", newSt.DiemV);
			fprintf_s(fp, "%g\n", newSt.DiemTB);
		}
		else {
			fprintf_s(fp, "%d\t", st[i].mssv);
			fprintf_s(fp, "%g\t", st[i].DiemT);
			fprintf_s(fp, "%g\t", st[i].DiemV);
			fprintf_s(fp, "%g\n", st[i].DiemTB);
		}
		
	}
	fclose(fp);
}
// xuat tat ca sinh vien
void XuatToanBoSV(Student a[], int& n) {
	Student st[MAX];
	LayToanBoSV(st);
	int n = LaySoLuongSV();
	for (int i = 0; i < n; i++)
	{
		cout << "Sinh vien thu " << i + 1 << '\n';
		cout << "Mssv: " << st[i].mssv << '\n';
		cout << "Diem Toan: " << st[i].DiemT << '\n';
		cout << "Diem Van: " << st[i].DiemV << '\n';
		cout << "Diem Trung Binh: " << st[i].DiemTB << '\n';
	}
}
// tim sinh vien gioi nhat
Student BestStudent() {
	Student st[MAX];
	LayToanBoSV(st);
	int n = LaySoLuongSV();
	Student best = st[0];
	for (int i = 1; i < n; i++)
	{
		if (best.DiemTB < st[i].DiemTB) {
			swap(best, st[i]);
		}
	}
	cout << "Sinh vien gioi nhat la ";
	cout << "Mssv: " << best.mssv << '\n';
	cout << "Diem Toan: " << best.DiemT << '\n';
	cout << "Diem Van: " << best.DiemV << '\n';
	cout << "Diem Trung Binh: " << best.DiemTB << '\n';

	FILE* fp;
	fopen_s(&fp, Best_FILE_NAME, "wt");
	if (fp == NULL) {
		cout << "Khong mo duoc tap tin Data.txt" << '\n';
		return;
	}

	fprintf_s(fp, "%d\t", best.mssv);
	fprintf_s(fp, "%g\t", best.DiemT);
	fprintf_s(fp, "%g\t", best.DiemV);
	fprintf_s(fp, "%g\n", best.DiemTB);

	fclose(fp);
}
// Tim sinh vien co hoc bong
void HocBong(Student sts[], int n) {
	Student st[MAX];
	LayToanBoSV(st);
	int n = LaySoLuongSV();
	int soHocBong = 0;
	Student SvCoHocBong[MAX];
	for (int i = 1; i < n; i++)
	{
		if (st[i].DiemTB > 7 && st[i].DiemT >= 5 && st[i].DiemV >= 5) {
			SvCoHocBong[soHocBong] = st[i];
			soHocBong++;
		}
	}

	FILE* fp;
	fopen_s(&fp, Best_FILE_NAME, "wt");
	if (fp == NULL) {
		cout << "Khong mo duoc tap tin Data.txt" << '\n';
		return;
	}
	fprintf_s(fp, "%d\n", soHocBong);
	for (int i = 0; i < soHocBong; i++)
	{
		fprintf_s(fp, "%d\t", SvCoHocBong[i].mssv);
		fprintf_s(fp, "%g\t", SvCoHocBong[i].DiemT);
		fprintf_s(fp, "%g\t", SvCoHocBong[i].DiemV);
		fprintf_s(fp, "%g\n", SvCoHocBong[i].DiemTB);
	}

	fclose(fp);
}
// Tim no mon
void NoMon() {
	cout << "Nhap ma mon: ";
	string maMon;
	cin.ignore();
	getLine
	Student st[MAX];
	LayToanBoSV(st);
	int n = LaySoLuongSV();
	int soNoMon = 0;
	Student SvNoMon[MAX];
	for (int i = 1; i < n; i++)
	{
		if (maMon == "V" && st[i].DiemV < 5) {
			SvNoMon[soNoMon] = st[i];
			soNoMon++;
		}
		else if (maMon == "T" && st[i].DiemT < 5) {
			SvNoMon[soNoMon] = st[i];
			soNoMon++;
		}
	}

	FILE* fp;
	if (maMon == "V") {
		fopen_s(&fp, NoVan_FILE_NAME, "wt");
	}
	else if (maMon == "T") {
		fopen_s(&fp, NoToan_FILE_NAME, "wt");
	}
	if (fp == NULL) {
		cout << "Khong mo duoc tap tin Data.txt" << '\n';
		return;
	}
	fprintf_s(fp, "%d\n", soNoMon);
	for (int i = 0; i < soNoMon; i++)
	{
		fprintf_s(fp, "%d\t", SvNoMon[i].mssv);
		fprintf_s(fp, "%g\t", SvNoMon[i].DiemT);
		fprintf_s(fp, "%g\t", SvNoMon[i].DiemV);
		fprintf_s(fp, "%g\n", SvNoMon[i].DiemTB);
	}

	fclose(fp);
}

