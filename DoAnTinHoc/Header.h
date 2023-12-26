#pragma once
#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <string>
#include <cstring>
#include <Windows.h>
#include <cstring>
#include <cctype>
using namespace std;
const int N = 100;

struct NS {
	int ngay;
	int thang;
	int nam;
};

struct NNH {
	int ngayNhapHoc;
	int thangNhapHoc;
	int namNhapHoc;
};

typedef struct TreMamNon {
	char maTre[15];
	char hoTenTre[50];
	NS ngaySinh;
	int tuoi;
	bool gioiTinh;
	int canNang;
	NNH ngayNhapHoc;
	char hoTenPhuHuynh[50];
	char soDienThoaiPhuHuynh[15];
}TMN;

struct DSTre {
	int n;
	TMN ds[N];
};

typedef struct GiaoVien {
	char maGiaoVien[15];
	char hoTenGiaoVien[50];
	bool gioiTinh;
	char diaChi[50];

}GV;

struct DSGiaoVien
{
	int n;
	GV ds[N];
};

struct NHD {
	int ngayhoatdong;
	int thanghoatdong;
	int namhoatdong;
};
typedef struct HoatDong {
	char maSoHoatDong[15];
	char tenHoatDong[50];
	NHD ngayHoatDong;
	char maGiaoVienPhuTrach[15];
	char hoTenGiaoVienPhuTrach[50];
	char maTreHD[15];
	char hoTenTre[50];
	float diemSoTreDatDuoc;
}HD;

struct DSHoatDong {
	int n;
	HD ds[N];
};


//cac chuc nang cho du an://

//-----------Ràng buộc thuộc tính-----------------------
bool rangBuoc_Ngay(int ngay, int thang, int nam);
bool rangBuoc_NgayHoatDong(int ngay, int thang, int nam);
bool rangBuoc_NgayNhapHoc(int ngay, int thang, int nam);

//--------------------
void inRaKetQua(DSTre a, DSHoatDong c);
void danhGiaKQ(float c);
int soSanhChuoi(const char* str1, const char* str2);

//Các chức năng với trẻ:
bool kiemTraTrungMaTre(const DSTre& danhSach, const char* maTre);
void nhapThongTinTre(TMN& a, DSTre danhSach);
void xuatThongTinTre(TMN a);
void nhapDanhSachTre(DSTre& danhSach);
void xuatDanhSachTre(DSTre a);
void nhapThongTinTreCapNhat(TMN& a, DSTre danhSach, char* c);
//void themMotTre(DSTre &ds, const TreMamNon &tmn);
void themTreVaoDanhSach(DSTre& danhSach);
void xoaMotTreRaKhoiList(DSTre& ds, const char* maTre);
bool kiemTraTrungMaTreCapNhatLai(const DSTre& danhSach, const char* maTre);
void capNhatThongTinTre(DSTre& danhSach);

//void capNhatThongTinTre(DSTre &dsTre);
bool kiemTraTonTai_MaTre(DSTre ds, char* maTre);
TreMamNon timKiemThongTinTreTheo_MaSoTre(DSTre ds, char* maTre);
void sapXepDanhSach_MaCuaTre(DSTre& ds);
void docDanhSach_TreTuFile(const char* tenFile, DSTre& ds);
void ghiDanhSachTre_VaoFile(const char* tenFile, DSTre ds);
string xoaKhoangTrangTraiPhai(const string& str);
string chuanHoaChuoi(const string& str);
void chuanHoaTen(TMN& tre);
void menuTre();

//Các chức năng với giáo viên:
bool kiemTraTrungMaGiaoVien(const DSGiaoVien& danhSach, const char* maGiaoVien);
void nhapThongTinGiaoVien(GV& a, DSGiaoVien danhSach);
void xuatThongTinGiaoVien(GV a);
//void nhapDanhSachGiaoVien(DSGiaoVien& a);
void nhapDanhSachGiaoVien(DSGiaoVien& danhSach);
void xuatDanhSachGiaoVien(DSGiaoVien a);
void nhapThongTinGiaoVien_CapNhat(GV& a, DSGiaoVien danhSach, char* c);
//void themGiaoVien(DSGiaoVien &ds, const GiaoVien &gv);
void themGiaoVienVaoDanhSach(DSGiaoVien& danhSach);
void xoaMot_GiaoVien_RaKhoiList(DSGiaoVien& ds, const char* maGV);
bool kiemTraTrungMa_GiaoVien_CapNhatLai(const DSGiaoVien& danhSach, const char* maGV);
void capNhatThongTinGiaoVien(DSGiaoVien& danhSach);
bool kiemTraTonTai_MaGiaoVien(DSGiaoVien ds, char* maGV);
GiaoVien timKiemThongTinGiaoVienTheo_MaSoGiaoVien(DSGiaoVien ds, char* maGV);
void sapXepDanhSach_MaCuaGiaoVien(DSGiaoVien& ds);
void docDanhSach_GiaoVienTuFile(const char* tenFile, DSGiaoVien& ds);
void ghiDanhSachGiaoVien_VaoFile(const char* tenFile, DSGiaoVien ds);
void chuanHoaTenGiaoVien(GV& gv);
void menuGiaoVien();



//Các chức năng với hoat dong:

bool KiemTraTrungMaHoatDong(const DSHoatDong& danhSach, const char* maHoatDong);
void NhapThongTinHoatDong(HoatDong& hoatDong, const DSHoatDong& danhSach, DSGiaoVien b, const TreMamNon& tre, DSTre c);
void xuatThongTinHoatDong(HD a, DSTre b);
void nhapDanhSachHoatDong(DSHoatDong& danhSach, const GiaoVien& giaoVien, DSGiaoVien b, const TreMamNon& tre, DSTre c);
void xuatDanhSachHoatDong(DSHoatDong a, DSTre b);
void nhapThongTinHoatDong_CapNhat(HoatDong& a, DSGiaoVien b);
void themHoatDong(DSHoatDong& ds, const HoatDong& hd);
void xoaMot_HoatDong_RaKhoiList(DSHoatDong& ds, const char* maHD);
void xoa_HoatDong_RaKhoiList(DSHoatDong& ds, const char* maHD);
void capNhatThongTin_HoatDong(DSHoatDong& ds, DSGiaoVien b);
bool kiemTraTonTai_MaHoatDong(DSHoatDong ds, char* maHD);
HoatDong timKiemThongTinHoatDongTheo_MaSoHoatDong(DSHoatDong ds, char* maHD);
void sapXepDanhSach_MaCuaHoatDong(DSHoatDong& ds);
void docDanhSach_CacHoatDong_TuFile(const char* tenFile, DSHoatDong& ds);
void ghiDanhSachCacHoatDong_VaoFile(const char* tenFile, DSHoatDong ds);
void chuanHoaTenHoatDong(HoatDong& hd);
void menuHoatDong();

//
void menuCha();
void SET_COLOR(int color);
//void Xoa_Khoang_Trang_Thua_Dau_Va_Cuoi(string &str);
//void Viet_Hoa_Ki_Tu_Dau_Cach(string& str);
//void Xoa_Khoang_Trang_Thieu_Giua_Cac_Tu(string& str);
//void Chuan_Hoa_Chuoi(string& str);
//void Chuan_Hoa_Chuoi(char str[50]);

void timKiemDanhSachHoatDong(DSHoatDong dshd, DSTre a, char* b);