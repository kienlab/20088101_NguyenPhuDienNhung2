#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>


struct Ngay {
	int ngay, thang, nam
};

struct SinhVien
{
	char maSV[8];
	char hoTen[50];
	int gioiTinh;
	Ngay ngaySinh;
	char diachi[100];
	char lop[12];
	char khoa[7];
};

struct Node
{
	SinhVien data;
	Node *link;
};

struct List
{
	Node *First, *Last;
};

void init(List &l)
{
	l.First=NULL;
	l.Last=NULL;
}

Node *getNode(SinhVien x) 
{
	Node *p=new Node;
	if(p==NULL) return NULL;
	p->data=x;
	p->link=NULL;
	return p;
}

Node *searchMaSV(List l, char *ma)
{
	for(Node *p=l.First; p!=NULL; p=p->link) {
		if(strcmp(p->data.maSV, ma)==0) return p;
	}
	return NULL;
}

void addLast(List &l, Node *new_ele)
{
	if(l.First==NULL) l.First=l.Last=new_ele;
	else {
		l.Last->link=new_ele;
		l.Last=new_ele;
	}
}

void insertLast(List &l, SinhVien x) 
{
	Node *new_ele=getNode(x);
	if(new_ele!=NULL) addLast(l, new_ele);
}

int nhapSinhVien(List l, SinhVien &x)
{
	char gt[4];
	while(1) {
		std::cout << "Ma so SV: ";
		fflush(stdin);
		gets(x.maSV);
		if(strcmp(x.maSV, "0")==0) return 0;
		if(searchMaSV(l, x.maSV)==NULL) break;
		else std::cout << "Trung ma!. Nhap lai\n";
	}
	std::cout << "Ho va ten: ";
	gets(x.hoTen);
	std::cout << "Gioi tinh: ";
	gets(gt);
	if(strcmp(strupr(gt),"NAM")==0) {
		x.gioiTinh=0;
	} else {
		x.gioiTinh=1;
	}
	std::cout << "Ngay thang nam sinh:";
	scanf("%d/%d/%d", &x.ngaySinh.ngay, &x.ngaySinh.thang, &x.ngaySinh.nam);
	std::cout << "Dia chi"	;
	fflush(stdin);
	gets(x.diachi);
	std::cout << "Lop: ";
	gets(x.lop);
	std::cout << "Khoa: ";
	gets(x.khoa);
	return 1;
}

void nhapDSSV(List &l)
{
	std::cout << "Bat dau nhap sinh vien. Nhap maSV=0 de dung\n";
	SinhVien x;
	while (nhapSinhVien(l,x)) {
		insertLast(l, x);
	}
	std::cout << "Ket thuc viec nhap DSSV\n";
}

void xuatSinhVien(SinhVien x)
{
	std::cout << x.maSV << " ";
	std::cout << x.hoTen << " ";
	std::cout << x.ngaySinh.ngay << "-";
	std::cout << x.ngaySinh.thang << "-";
	std::cout << x.ngaySinh.nam << " ";
	std::cout << x.diachi << " ";
	std::cout << x.lop << " ";
	std::cout << x.khoa << " ";
}

void intieude()
{
	std::cout << "MaSV" << " ";
	std::cout << "Ho va Ten" << " ";
	std::cout << "Gioi tinh" << " ";
	std::cout << "Ngay sinh" << " ";
	std::cout << "Dia chi" << " ";
	std::cout << "Lop" << " ";
	std::cout << "Khoa" << " ";
	std::cout << "\n------------------------------------------------------------------\n";
}

void xuatDSSV(List l) 
{
	intieude();
	for(Node *p=l.First; p!=NULL; p=p->link)
		xuatSinhVien(p->data);
}