#include"Header.h"

bool rangBuoc_Ngay(int ngay, int thang, int nam) {
	// Kiểm tra năm nhuận
	bool namNhuan = (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);

	// Kiểm tra ngày tháng năm
	if (nam <= 2019 || thang <= 0 || thang > 12 || ngay <= 0 || ngay > 31) {
		return false;
	}
	else if ((thang == 4 || thang == 6 || thang == 9 || thang == 11) && ngay > 30) {
		return false;
	}
	else if (thang == 2) {
		if (namNhuan && ngay > 29) {
			return false;
		}
		else if (!namNhuan && ngay > 28) {
			return false;
		}
	}
	return true;
}


bool rangBuoc_NgayNhapHoc(int ngay, int thang, int nam) {
	// Kiểm tra năm nhuận
	bool namNhuan = (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);

	// Kiểm tra ngày tháng năm
	if (nam <= 2020 || thang <= 0 || thang > 12 || ngay <= 0 || ngay > 31) {
		return false;
	}
	else if ((thang == 4 || thang == 6 || thang == 9 || thang == 11) && ngay > 30) {
		return false;
	}
	else if (thang == 2) {
		if (namNhuan && ngay > 29) {
			return false;
		}
		else if (!namNhuan && ngay > 28) {
			return false;
		}
	}
	return true;
}
// Hàm xóa khoảng trắng ở đầu và cuối chuỗi
string xoaKhoangTrangTraiPhai(const string& str) {
	size_t trangDau = str.find_first_not_of(' ');
	if (string::npos == trangDau) {
		return str;
	}
	size_t trangCuoi = str.find_last_not_of(' ');
	return str.substr(trangDau, (trangCuoi - trangDau + 1));
}

// Hàm chuẩn hóa chuỗi (viết hoa chữ cái đầu)
string chuanHoaChuoi(const string& str) {
	string ketQuaCuoiCung = xoaKhoangTrangTraiPhai(str);
	if (!ketQuaCuoiCung.empty()) {
		ketQuaCuoiCung[0] = toupper(ketQuaCuoiCung[0]);
		for (size_t i = 1; i < ketQuaCuoiCung.length(); ++i) {
			if (ketQuaCuoiCung[i - 1] == ' ') {
				ketQuaCuoiCung[i] = toupper(ketQuaCuoiCung[i]);
			}
			else {
				ketQuaCuoiCung[i] = tolower(ketQuaCuoiCung[i]);
			}
		}
	}
	return ketQuaCuoiCung;
}

// Hàm chuẩn hóa hoTenTre và hoTenPhuHuynh của đối tượng TreMamNon
void chuanHoaTen(TMN& tre) {
	string hoTenTreChuanHoa = chuanHoaChuoi(tre.hoTenTre);
	string hoTenPhuHuynhChuanHoa = chuanHoaChuoi(tre.hoTenPhuHuynh);
	// Gán lại chuỗi đã chuẩn hóa vào cấu trúc TMN
	strcpy_s(tre.hoTenTre, hoTenTreChuanHoa.c_str());
	strcpy_s(tre.hoTenPhuHuynh, hoTenPhuHuynhChuanHoa.c_str());
}

void nhapThongTinTre(TMN& a, DSTre danhSach)
{
	//Viet them:
	bool trungMaTre = true;
	cout << "\nNhap ma so tre: ";
	cin.ignore();
	cin.getline(a.maTre, 15);
	while (trungMaTre)
	{
		if (kiemTraTrungMaTre(danhSach, a.maTre)) {
			cout << "\nMa so tre da ton tai trong danh sach (bi trung ma tre). Vui long nhap lai!.";
			cout << "\nNhap lai ma tre: ";
			cin.getline(a.maTre, 15);
		}
		else {
			trungMaTre = false;
		}
	}
	cout << "\nNhap ho ten cua tre:";
	cin.getline(a.hoTenTre, 50);
	do {
		cout << "Nhap thong tin (Ngay/Thang/Nam) sinh cua tre:" << endl;
		cout << "Ngay: ";
		cin >> a.ngaySinh.ngay;
		cout << "Thang: ";
		cin >> a.ngaySinh.thang;
		cout << "Nam(>2019): ";
		cin >> a.ngaySinh.nam;
	} while (rangBuoc_Ngay(a.ngaySinh.ngay, a.ngaySinh.thang, a.ngaySinh.nam) == false);
	a.tuoi = 2023 - a.ngaySinh.nam;
	cout << "Nhap gioi tinh(1:nam - 0:nu): ";
	cin >> a.gioiTinh;
	cout << "Nhap vao can nang cua tre (kg):";
	cin >> a.canNang;
	cin.ignore();
	do {
		cout << "Nhap thong tin (Ngay/Thang/Nam) nhap hoc cua tre:" << endl;
		cout << "Ngay: ";
		cin >> a.ngayNhapHoc.ngayNhapHoc;
		cout << "Thang: ";
		cin >> a.ngayNhapHoc.thangNhapHoc;
		cout << "Nam(>2020): ";
		cin >> a.ngayNhapHoc.namNhapHoc;
	} while (rangBuoc_NgayNhapHoc(a.ngayNhapHoc.ngayNhapHoc, a.ngayNhapHoc.thangNhapHoc, a.ngayNhapHoc.namNhapHoc) == false);
	cin.ignore();
	cout << "Nhap vao ho ten phu huynh cua tre:";
	cin.getline(a.hoTenPhuHuynh, 50);
	cout << "Nhap vao so dien thoai cua phu huynh:";
	cin.getline(a.soDienThoaiPhuHuynh, 15);
	//dòng gọi lại hàm chuẩn hóa:
	chuanHoaTen(a);
}

void nhapThongTinTreCapNhat(TMN& a, DSTre danhSach, char* c)
{
	//cin.ignore();
	//cout << "Nhap ma tre:";
	//cin.getline(a.maTre, 15);
	bool trungMaTre = true;
	strcpy_s(a.maTre, c);
	while (trungMaTre)
	{
		if (kiemTraTrungMaTre(danhSach, a.maTre)) {
			cout << "\nMa so tre da ton tai trong danh sach (bi trung ma tre). Vui long nhap lai!.";
			trungMaTre = true;
			cout << "\nNhap lai ma tre: ";
			cin.getline(a.maTre, 15);
		}
		else {
			trungMaTre = false;
		}
	}
	cout << "Nhap ho ten cua tre:";
	cin.getline(a.hoTenTre, 50);
	do {
		cout << "Nhap thong tin (Ngay/Thang/Nam) sinh cua tre:" << endl;
		cout << "Ngay: ";
		cin >> a.ngaySinh.ngay;
		cout << "Thang: ";
		cin >> a.ngaySinh.thang;
		cout << "Nam(>2019): ";
		cin >> a.ngaySinh.nam;
	} while (rangBuoc_Ngay(a.ngaySinh.ngay, a.ngaySinh.thang, a.ngaySinh.nam) == false);
	a.tuoi = 2023 - a.ngaySinh.nam;
	cout << "Nhap gioi tinh(1:nam - 0:nu): ";
	cin >> a.gioiTinh;
	cout << "Nhap vao can nang cua tre (kg):";
	cin >> a.canNang;
	cin.ignore();
	do {
		cout << "Nhap thong tin (Ngay/Thang/Nam) nhap hoc cua tre:" << endl;
		cout << "Ngay: ";
		cin >> a.ngayNhapHoc.ngayNhapHoc;
		cout << "Thang: ";
		cin >> a.ngayNhapHoc.thangNhapHoc;
		cout << "Nam(>2020): ";
		cin >> a.ngayNhapHoc.namNhapHoc;
	} while (rangBuoc_NgayNhapHoc(a.ngayNhapHoc.ngayNhapHoc, a.ngayNhapHoc.thangNhapHoc, a.ngayNhapHoc.namNhapHoc) == false);
	cin.ignore();
	cout << "Nhap vao ho ten phu huynh cua tre:";
	cin.getline(a.hoTenPhuHuynh, 50);
	cout << "Nhap vao so dien thoai cua phu huynh:";
	cin.getline(a.soDienThoaiPhuHuynh, 15);
	chuanHoaTen(a);
}

void xuatThongTinTre(TMN a) {
	cout << left << setw(8) << a.maTre;
	cout << setw(25) << a.hoTenTre;
	cout << setw(2) << a.ngaySinh.ngay << "/";
	cout << setw(2) << a.ngaySinh.thang << "/";
	cout << left << setw(7) << a.ngaySinh.nam;
	cout << setw(7) << a.tuoi;
	cout << setw(12) << (a.gioiTinh ? "Nam" : "Nu");
	cout << setw(2) << a.canNang;
	cout << setw(9) << " kg";
	cout << setw(2) << a.ngayNhapHoc.ngayNhapHoc << "/";
	cout << setw(2) << a.ngayNhapHoc.thangNhapHoc << "/";
	cout << setw(10) << a.ngayNhapHoc.namNhapHoc;
	cout << setw(26) << a.hoTenPhuHuynh;
	cout << setw(11) << a.soDienThoaiPhuHuynh;
}

// Hàm kiểm tra mã số trẻ có trùng hay không
bool kiemTraTrungMaTre(const DSTre& danhSach, const char* maTre) {
	for (int i = 0; i < danhSach.n; ++i) {
		if (strcmp(danhSach.ds[i].maTre, maTre) == 0) {
			return true; // Mã số trẻ đã tồn tại trong danh sách
		}
	}
	return false; // Mã số trẻ không tồn tại trong danh sách
}
// b) Hàm nhập, xuất một danh sách trẻ
void nhapDanhSachTre(DSTre& danhSach) {
	char chosen = 'y';
	int i = danhSach.n;
	do
	{
		danhSach.n++;
		cout << "Nhap thong tin cua tre thu [" << i + 1 << "]" << endl;
		cout << "=========================================" << endl;
		nhapThongTinTre(danhSach.ds[i], danhSach);
		cout << "=========================================" << endl;
		// Thêm thông tin trẻ vào danh sách
		do
		{
			cout << "Ban co muon nhap tiep (Y/N):  ";
			cin >> chosen;
			if (chosen == 'y' || chosen == 'Y') {
				i++;
			}
		} while (chosen != 'y' && chosen != 'Y' && chosen != 'N' && chosen != 'n');
	} while (chosen != 'n' && chosen != 'N');
}


void xuatDanhSachTre(DSTre a) {
	SET_COLOR(9);
	cout << "\n****************************************************************************************************************************************";
	cout << "\n|                                                         Danh Sach Tre                                                                |";
	cout << "\n****************************************************************************************************************************************\n";
	cout << left << setw(6) << "|STT";
	cout << setw(8) << "Ma Tre";
	cout << setw(25) << "Ten Tre";
	cout << setw(12) << "Ngay Sinh";
	cout << setw(6) << "Tuoi";
	cout << setw(14) << "Gioi Tinh";
	cout << setw(11) << "Can Nang";
	cout << setw(16) << "Ngay Nhap Hoc";
	cout << setw(24) << "Ten Phu Huynh";
	cout << setw(14) << "So Dien Thoai|";
	cout << "\n****************************************************************************************************************************************";
	for (int i = 0; i < a.n; ++i) {
		cout << endl;
		cout << "|";
		cout << " ";
		SET_COLOR(7);
		cout << left << setw(4) << i + 1;
		xuatThongTinTre(a.ds[i]);
		SET_COLOR(9);
		cout << "|";
	}
	cout << "\n****************************************************************************************************************************************";
	cout << endl;
}



bool rangBuoc_NgayHoatDong(int ngay, int thang, int nam) {
	// Kiểm tra năm nhuận
	bool namNhuan = (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);

	// Kiểm tra ngày tháng năm
	if (nam <= 2022 || thang <= 0 || thang > 12 || ngay <= 0 || ngay > 31) {
		return false;
	}
	else if ((thang == 4 || thang == 6 || thang == 9 || thang == 11) && ngay > 30) {
		return false;
	}
	else if (thang == 2) {
		if (namNhuan && ngay > 29) {
			return false;
		}
		else if (!namNhuan && ngay > 28) {
			return false;
		}
	}
	return true;
}

//kiem tra trùng mã giáo viên:
bool kiemTraTrungMaGiaoVien(const DSGiaoVien& danhSach, const char* maGiaoVien) {
	for (int i = 0; i < danhSach.n; ++i) {
		if (strcmp(danhSach.ds[i].maGiaoVien, maGiaoVien) == 0) {
			return true;
		}
	}
	return false;
}

void chuanHoaTenGiaoVien(GV& gv) {
	string hoTenGiaoVienChuanHoa = chuanHoaChuoi(gv.hoTenGiaoVien);
	string diaChiGiaoVienChuanHoa = chuanHoaChuoi(gv.diaChi);
	strcpy_s(gv.hoTenGiaoVien, hoTenGiaoVienChuanHoa.c_str());
	strcpy_s(gv.diaChi, diaChiGiaoVienChuanHoa.c_str());
}
// Hàm nhập, xuất Giáo Viên
void nhapThongTinGiaoVien(GV& a, DSGiaoVien danhSach) {
	bool trungMaGiaoVien = true;
	cout << "Nhap ma giao vien: ";
	cin.ignore();
	cin.getline(a.maGiaoVien, 15);
	while (trungMaGiaoVien)
	{
		if (kiemTraTrungMaGiaoVien(danhSach, a.maGiaoVien)) {
			cout << "\nMa giao vien da ton tai trong danh sach (bi trung ma giao vien). Vui long nhap lai!.";
			cout << "\nNhap lai ma giao vien: ";
			cin.getline(a.maGiaoVien, 15);
		}
		else {
			trungMaGiaoVien = false;
		}
	}
	cout << "Nhap ho ten giao vien: ";
	cin.getline(a.hoTenGiaoVien, 50);
	cout << "Nhap gioi tinh giao vien(1:nam - 0:nu): ";
	cin >> a.gioiTinh;
	cout << "Nhap dia chi:";
	cin.ignore();
	cin.getline(a.diaChi, 50);
	chuanHoaTenGiaoVien(a);
}
//
void nhapThongTinGiaoVien_CapNhat(GV& a, DSGiaoVien danhSach, char* c) {
	bool trungMaGiaoVien = true;
	//cout << "Nhap ma giao vien: ";
	//cin.ignore();
	//cin.getline(a.maGiaoVien, 15);
	strcpy_s(a.maGiaoVien, c);
	while (trungMaGiaoVien)
	{
		if (kiemTraTrungMaGiaoVien(danhSach, a.maGiaoVien)) {
			cout << "\nMa giao vien da ton tai trong danh sach (bi trung ma giao vien). Vui long nhap lai!.";
			cout << "\nNhap lai ma giao vien: ";
			cin.getline(a.maGiaoVien, 15);
		}
		else {
			trungMaGiaoVien = false;
		}
	}
	cout << "Nhap ho ten giao vien: ";
	cin.getline(a.hoTenGiaoVien, 50);
	cout << "Nhap gioi tinh giao vien(1:nam - 0:nu): ";
	cin >> a.gioiTinh;
	cout << "Nhap dia chi:";
	cin.ignore();
	cin.getline(a.diaChi, 50);
	chuanHoaTenGiaoVien(a);
}

void xuatThongTinGiaoVien(GV a) {
	cout << setw(15) << a.maGiaoVien;
	cout << setw(32) << a.hoTenGiaoVien;
	cout << setw(20) << (a.gioiTinh ? "Nam" : "Nu");
	cout << setw(42) << a.diaChi;
}

void nhapDanhSachGiaoVien(DSGiaoVien& danhSach) {
	char chosen = 'y';
	int i = danhSach.n;
	do
	{
		danhSach.n++;
		cout << "Nhap thong tin cua giao vien thu [" << i + 1 << "]" << endl;
		cout << "=============================================================================" << endl;
		nhapThongTinGiaoVien(danhSach.ds[i], danhSach);
		cout << "=============================================================================" << endl;
		// Thêm thông tin giao vien vào danh sách
		do
		{
			cout << "Ban co muon nhap tiep (Y/N):  ";
			cin >> chosen;
			if (chosen == 'y' || chosen == 'Y') {
				i++;
			}
		} while (chosen != 'y' && chosen != 'Y' && chosen != 'N' && chosen != 'n');
	} while (chosen != 'n' && chosen != 'N');
}

void xuatDanhSachGiaoVien(DSGiaoVien a) {
	SET_COLOR(11);
	cout << "\n********************************************************************************************************************";
	cout << "\n|                                             Danh Sach Giao Vien                                                  |";
	cout << "\n********************************************************************************************************************\n";
	cout << left << setw(6) << "|STT";
	cout << setw(15) << "Ma giao vien";
	cout << setw(30) << "Ho ten giao vien";
	cout << setw(20) << "Gioi tinh ";
	cout << setw(44) << "Dia chi thuong tru";
	cout << "|";
	cout << "\n********************************************************************************************************************";
	for (int i = 0; i < a.n; ++i) {
		cout << endl;
		cout << "|";
		SET_COLOR(7);
		cout << " ";
		cout << left << setw(4) << i + 1;
		xuatThongTinGiaoVien(a.ds[i]);
		SET_COLOR(11);
		cout << "|";
	}
	cout << "\n********************************************************************************************************************\n";
}

// Kiểm tra mã hoạt động có trùng không
bool KiemTraTrungMaHoatDong(const DSHoatDong& danhSach, const char* maHoatDong) {
	for (int i = 0; i < danhSach.n; ++i) {
		if (strcmp(danhSach.ds[i].maSoHoatDong, maHoatDong) == 0) {
			return true;
		}
	}
	return false;
}
void chuanHoaTenHoatDong(HoatDong& hd) {
	string tenHoatDongChuanHoa = chuanHoaChuoi(hd.tenHoatDong);
	strcpy_s(hd.tenHoatDong, tenHoatDongChuanHoa.c_str());
}
// Hàm nhập thông tin một hoạt động
void NhapThongTinHoatDong(HoatDong& hoatDong, const DSHoatDong& danhSach, DSGiaoVien b, const TreMamNon& tre, DSTre c) {
	bool tontaiMaGiaoVien = true;
	bool tonTaiMaTre = true;
	cout << "Nhap ma so hoat dong: ";
	cin.ignore();
	cin.getline(hoatDong.maSoHoatDong, 15);
	// Kiểm tra xem mã hoạt động có trùng không
	//while (KiemTraTrungMaHoatDong(danhSach, hoatDong.maSoHoatDong)) {
	//	cout << "Ma hoat dong bi trung. Vui long nhap lai ma so hoat dong! " << endl;
	//	cout << "Nhap ma so hoat dong:";
	//	//cin >> hoatDong.maSoHoatDong;
	//	cin.getline(hoatDong.maSoHoatDong, 15);
	//}
	cout << "Nhap ten hoat dong: ";
	cin.getline(hoatDong.tenHoatDong, 50);
	do {
		cout << "Nhap thong tin ngay hoat dong:" << endl;
		cout << "Ngay: ";
		cin >> hoatDong.ngayHoatDong.ngayhoatdong;
		cout << "Thang: ";
		cin >> hoatDong.ngayHoatDong.thanghoatdong;
		cout << "Nam (>2022): ";
		cin >> hoatDong.ngayHoatDong.namhoatdong;
	} while (rangBuoc_NgayHoatDong(hoatDong.ngayHoatDong.ngayhoatdong, hoatDong.ngayHoatDong.thanghoatdong, hoatDong.ngayHoatDong.namhoatdong) == false);
	cin.ignore();
	cout << "Nhap ma giao vien phu trach: ";
	cin.getline(hoatDong.maGiaoVienPhuTrach, 15);
	do
	{
		if (kiemTraTonTai_MaGiaoVien(b, hoatDong.maGiaoVienPhuTrach))
		{
			tontaiMaGiaoVien = false;
		}
		else
		{
			cout << "\nMa giao vien khong ton tai! Vui Long Nhap Ma Giao vien khac: ";
			cin.getline(hoatDong.maGiaoVienPhuTrach, 15);
		}
	} while (tontaiMaGiaoVien);
	for (int i = 0; i < b.n; i++)
	{
		char s1[15];
		char s2[15];
		strcpy_s(s1, hoatDong.maGiaoVienPhuTrach);
		strcpy_s(s2, b.ds[i].maGiaoVien);
		int kq = soSanhChuoi(s1, s2);
		if (kq == 0) {
			strcpy_s(hoatDong.hoTenGiaoVienPhuTrach, b.ds[i].hoTenGiaoVien);
			//cin.getline(a.hoTenGiaoVienPhuTrach, 50);
		}
	}
	cout << "Nhap ma tre tham gia hoat dong: ";
	cin.getline(hoatDong.maTreHD, 15);
	do
	{
		if (kiemTraTonTai_MaTre(c, hoatDong.maTreHD))
		{
			tonTaiMaTre = false;
		}
		else
		{
			cout << "\nMa tre khong ton tai! Vui Long Nhap tre khac: ";
			cin.getline(hoatDong.maTreHD, 15);
		}

	} while (tonTaiMaTre);
	cout << "Nhap diem so tre dat duoc: ";
	cin >> hoatDong.diemSoTreDatDuoc;
	bool kiemTraDiem = true;
	do
	{
		if (hoatDong.diemSoTreDatDuoc >= 0 && hoatDong.diemSoTreDatDuoc <= 10)
			kiemTraDiem = false;
		else {
			cout << "\nDiem khong hop le! Vui long nhap lai: ";
			cin >> hoatDong.diemSoTreDatDuoc;
		}
	} while (kiemTraDiem);
}


void nhapThongTinHoatDong_CapNhat(HoatDong& a, DSGiaoVien b)
{
	//cin.ignore();
	cout << "Nhap ma so hoat dong: ";
	cin.getline(a.maSoHoatDong, 15);
	cout << "Nhap ten hoat dong: ";
	cin.getline(a.tenHoatDong, 50);
	do {
		cout << "Nhap thong tin ngay hoat dong:" << endl;
		cout << "Ngay: ";
		cin >> a.ngayHoatDong.ngayhoatdong;
		cout << "Thang: ";
		cin >> a.ngayHoatDong.thanghoatdong;
		cout << "Nam (>2022): ";
		cin >> a.ngayHoatDong.namhoatdong;

	} while (rangBuoc_NgayHoatDong(a.ngayHoatDong.ngayhoatdong, a.ngayHoatDong.thanghoatdong, a.ngayHoatDong.namhoatdong) == false);
	cin.ignore();
	cout << "Nhap ma giao vien phu trach: ";
	cin.getline(a.maGiaoVienPhuTrach, 15);
	for (int i = 0; i < b.n; i++)
	{
		char s1[15];
		char s2[15];
		strcpy_s(s1, a.maGiaoVienPhuTrach);
		strcpy_s(s2, b.ds[i].maGiaoVien);
		int kq = soSanhChuoi(s1, s2);
		if (kq == 0) {
			strcpy_s(a.hoTenGiaoVienPhuTrach, b.ds[i].hoTenGiaoVien);
			//cin.getline(a.hoTenGiaoVienPhuTrach, 50);
		}
	}
	cout << "Nhap ma tre tham gia hoat dong: ";
	cin.getline(a.maTreHD, 15);
	cout << "Nhap diem so tre dat duoc: ";
	cin >> a.diemSoTreDatDuoc;
	chuanHoaTenHoatDong(a);
}



void xuatThongTinHoatDong(HD a, DSTre b) {
	cout << setw(10) << a.maSoHoatDong;
	cout << setw(20) << a.tenHoatDong;
	cout << setw(2) << a.ngayHoatDong.ngayhoatdong << "/";
	cout << setw(2) << a.ngayHoatDong.thanghoatdong << "/";
	cout << setw(11) << a.ngayHoatDong.namhoatdong;
	cout << setw(17) << a.maGiaoVienPhuTrach;
	cout << setw(28) << a.hoTenGiaoVienPhuTrach;
	cout << setw(12) << a.maTreHD;
	for (int i = 0; i < b.n; i++) {
		char s1[15];
		char s2[15];
		strcpy_s(s1, a.maTreHD);
		strcpy_s(s2, b.ds[i].maTre);
		int kq = soSanhChuoi(s1, s2);
		if (kq == 0) {
			cout << setw(28) << b.ds[i].hoTenTre;
		}
	}
	cout << setw(6) << a.diemSoTreDatDuoc;
}


// Nhập danh sách các hoạt động
void nhapDanhSachHoatDong(DSHoatDong& danhSach, const GiaoVien& giaoVien, DSGiaoVien b, const TreMamNon& tre, DSTre c) {
	char chosen;
	int i = danhSach.n;
	do {
		cout << "Nhap thong tin cua hoat dong thu [" << i + 1 << "]" << endl;
		cout << "=============================================================================" << endl;
		HoatDong hoatDong;
		NhapThongTinHoatDong(hoatDong, danhSach, b, tre, c);
		danhSach.ds[danhSach.n++] = hoatDong;
		cout << "=============================================================================" << endl;
		do
		{
			cout << "Ban co muon nhap tiep (Y/N):  ";
			cin >> chosen;
			if (chosen == 'y' || chosen == 'Y') {
				i++;
			}
		} while (chosen != 'y' && chosen != 'Y' && chosen != 'N' && chosen != 'n');
	} while (chosen == 'Y' || chosen == 'y');
}

void xuatDanhSachHoatDong(DSHoatDong a, DSTre b) {
	SET_COLOR(19);
	cout << "\n============================================================================================================================================" << endl;
	cout << "|                                                              Hoat Dong Can Tim                                                           |";
	cout << "\n============================================================================================================================================" << endl;
	cout << left << setw(11) << "|Ma HD";
	cout << left << setw(20) << "Ten Hoat Dong";
	cout << left << setw(17) << "Ngay hoat dong";
	cout << left << setw(17) << "Ma Giao vien";
	cout << setw(28) << "Ten giao vien phu trach";
	cout << left << setw(12) << "Ma Tre";
	cout << left << setw(26) << "Ten tre";
	cout << left << setw(8) << "Diem so";
	cout << "|";
	cout << endl;
	cout << "============================================================================================================================================" << endl;
	for (int i = 0; i < a.n; ++i) {
		cout << "|";
		SET_COLOR(7);
		xuatThongTinHoatDong((a.ds[i]), b);
		SET_COLOR(19);
		cout << "|";
		cout << endl;
	}
	cout << "============================================================================================================================================" << endl;

}

void inRaKetQua(DSTre a, DSHoatDong c) {
	SET_COLOR(19);
	cout << "\n==================================================================================================================================================" << endl;
	cout << "|                                                                 KET QUA HOAT DONG                                                              |";
	cout << "\n==================================================================================================================================================" << endl;
	cout << left << setw(6) << "|STT";
	cout << left << setw(13) << "Ma So Tre";
	cout << left << setw(10) << "Ma HD";
	cout << left << setw(20) << "Ten tre";
	cout << left << setw(17) << "Ten hoat dong";
	cout << left << setw(17) << "Ngay hoat dong";
	cout << left << setw(11) << "Diem so";
	cout << left << setw(25) << "Ket qua";
	cout << setw(26) << "Ten giao vien phu trach";
	cout << "|";
	cout << endl;
	cout << "==================================================================================================================================================" << endl;

	for (int i = 0; i < c.n; i++) {
		for (int j = 0; j < a.n; j++) {
			char s1[15];
			char s2[15];
			strcpy_s(s1, c.ds[i].maTreHD);
			strcpy_s(s2, a.ds[j].maTre);
			int kq = soSanhChuoi(s1, s2);
			if (kq == 0) {
				cout << "|";
				SET_COLOR(7);
				cout << setw(6) << i + 1;
				cout << setw(12) << a.ds[j].maTre;
				cout << setw(10) << c.ds[i].maSoHoatDong;
				cout << setw(20) << a.ds[j].hoTenTre;
				cout << setw(17) << c.ds[i].tenHoatDong;
				cout << c.ds[i].ngayHoatDong.ngayhoatdong << "/";
				cout << c.ds[i].ngayHoatDong.thanghoatdong << "/";
				cout << setw(14) << c.ds[i].ngayHoatDong.namhoatdong;
				cout << setw(10) << c.ds[i].diemSoTreDatDuoc;
				danhGiaKQ(c.ds[i].diemSoTreDatDuoc);
				cout << setw(26) << c.ds[i].hoTenGiaoVienPhuTrach;
				SET_COLOR(19);
				cout << "|";
				cout << endl;
			}
		}
	}
	cout << "===================================================================================================================================================" << endl;
}

void danhGiaKQ(float c)
{
	if (c >= 9)
	{
		cout << setw(25) << "Xuat Sac";
	}
	else if (c >= 8 && c < 9)
	{
		cout << setw(25) << "Tot";
	}
	else if (c >= 6.5 && c < 8)
	{
		cout << setw(25) << "Tien Tien";
	}
	else
	{
		cout << setw(25) << "Chua Dat (can co gang)";
	}
}


void themTreVaoDanhSach(DSTre& danhSach) {
	TMN tre;
	nhapThongTinTre(tre, danhSach);

	// Thêm thông tin trẻ vào danh sách
	danhSach.ds[danhSach.n] = tre;
	danhSach.n++;
}
//Xoa:
void xoaMotTreRaKhoiList(DSTre& ds, const char* maTre) {
	int i;
	for (i = 0; i < ds.n; ++i) {
		if (strcmp(ds.ds[i].maTre, maTre) == 0) {
			break;
		}
	}

	if (i == ds.n) {
		cout << "Khong tim thay thong tin co ma " << maTre << endl;
	}
	else {
		for (int j = i; j < ds.n - 1; ++j) {
			ds.ds[j] = ds.ds[j + 1];
		}
		ds.n--;
		cout << "Da xoa thong tin cua tre co ma " << maTre << endl;
	}
}

//hàm mới:
bool kiemTraTrungMaTreCapNhatLai(const DSTre& danhSach, const char* maTre) {
	for (int i = 0; i < danhSach.n; ++i) {
		if (strcmp(danhSach.ds[i].maTre, maTre) == 0) {
			return true; // Mã trẻ đã tồn tại
		}
	}
	return false; // Mã trẻ chưa tồn tại
}

void capNhatThongTinTre(DSTre& danhSach) {
	char maCu[15];
	char maMoi[15];

	cout << "Nhap ma tre muon cap nhat thong tin: ";
	cin.ignore();
	cin.getline(maCu, 15);

	int viTri = -1; // Giả sử mã trẻ không tồn tại trong danh sách
	for (int i = 0; i < danhSach.n; ++i) {
		if (strcmp(danhSach.ds[i].maTre, maCu) == 0) {
			viTri = i; // Lưu vị trí của mã trẻ trong danh sách
			break;
		}
	}

	if (viTri != -1) { // Mã trẻ tồn tại trong danh sách
		cout << "Nhap ma tre moi: ";
		cin.getline(maMoi, 15);

		if (!kiemTraTrungMaTreCapNhatLai(danhSach, maMoi) || strcmp(maCu, maMoi) == 0) {
			nhapThongTinTreCapNhat(danhSach.ds[viTri], danhSach, maMoi);
			cout << "Cap nhat thong tin thanh cong!" << endl;
		}
		else {
			cout << "Ma tre moi bi trung voi mot tre khac trong danh sach. Khong the cap nhat!" << endl;
		}
	}
	else {
		cout << "Ma tre khong ton tai trong danh sach!" << endl;
	}
}


//tìm kiếm:
bool kiemTraTonTai_MaTre(DSTre ds, char* maTre) {
	for (int i = 0; i < ds.n; i++) {
		if (strcmp(ds.ds[i].maTre, maTre) == 0) {
			return true;
		}
	}
	return false;
}
TreMamNon timKiemThongTinTreTheo_MaSoTre(DSTre ds, char* maTre) {
	for (int i = 0; i < ds.n; i++)
	{
		if (strcmp(ds.ds[i].maTre, maTre) == 0)
		{
			return ds.ds[i];
		}
	}
}
//Sap Xep theo ma tre:
void sapXepDanhSach_MaCuaTre(DSTre& ds) {
	for (int i = 0; i < ds.n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < ds.n; j++) {
			if (strcmp(ds.ds[j].maTre, ds.ds[min].maTre) < 0) {
				min = j;
			}
		}
		swap(ds.ds[i], ds.ds[min]);
	}
}
// Hàm đọc, ghi file danh sách tre
//template<typename T>
void docDanhSach_TreTuFile(const char* tenFile, DSTre& ds) {
	ifstream file(tenFile);
	if (!file.is_open()) {
		cout << "Khong mo duoc file." << endl;
		return;
	}

	file >> ds.n;
	file.ignore();

	for (int i = 0; i < ds.n; ++i) {
		file.getline(ds.ds[i].maTre, 15);
		file.getline(ds.ds[i].hoTenTre, 50);
		file >> ds.ds[i].ngaySinh.ngay;
		file.ignore();
		file >> ds.ds[i].ngaySinh.thang;
		file.ignore();
		file >> ds.ds[i].ngaySinh.nam;
		file >> ds.ds[i].gioiTinh;
		file >> ds.ds[i].tuoi;
		file >> ds.ds[i].canNang;
		file >> ds.ds[i].ngayNhapHoc.ngayNhapHoc;
		file.ignore();
		file >> ds.ds[i].ngayNhapHoc.thangNhapHoc;
		file.ignore();
		file >> ds.ds[i].ngayNhapHoc.namNhapHoc;
		file.ignore();
		file.getline(ds.ds[i].hoTenPhuHuynh, 50);
		file.getline(ds.ds[i].soDienThoaiPhuHuynh, 15);
	}

	file.close();
}

//template<typename T>
void ghiDanhSachTre_VaoFile(const char* tenFile, DSTre ds) {
	ofstream file(tenFile);
	if (!file.is_open()) {
		cout << "Khong mo duoc file." << endl;
		return;
	}

	file << ds.n << endl;

	for (int i = 0; i < ds.n; ++i) {
		file << ds.ds[i].maTre << endl;
		file << ds.ds[i].hoTenTre << endl;
		file << ds.ds[i].ngaySinh.ngay << "/" << ds.ds[i].ngaySinh.thang << "/" << ds.ds[i].ngaySinh.nam << endl;
		file << ds.ds[i].gioiTinh << endl;
		file << ds.ds[i].tuoi << endl;
		file << ds.ds[i].canNang << endl;
		file << ds.ds[i].ngayNhapHoc.ngayNhapHoc << "/" << ds.ds[i].ngayNhapHoc.thangNhapHoc << "/" << ds.ds[i].ngayNhapHoc.namNhapHoc << endl;
		file << ds.ds[i].hoTenPhuHuynh << endl;
		file << ds.ds[i].soDienThoaiPhuHuynh << endl;
	}

	file.close();
}
//Cac chuc nang voi giao vien:


//them gv:
void themGiaoVienVaoDanhSach(DSGiaoVien& danhSach) {
	GiaoVien gv;
	nhapThongTinGiaoVien(gv, danhSach);

	danhSach.ds[danhSach.n] = gv;
	danhSach.n++;
}
//Xoa:
void xoaMot_GiaoVien_RaKhoiList(DSGiaoVien& ds, const char* maGV) {
	int i;
	for (i = 0; i < ds.n; ++i) {
		if (strcmp(ds.ds[i].maGiaoVien, maGV) == 0) {
			break;
		}
	}

	if (i == ds.n) {
		cout << "Khong tim thay thong tin cua giao vien co ma " << maGV << endl;
	}
	else {
		for (int j = i; j < ds.n - 1; ++j) {
			ds.ds[j] = ds.ds[j + 1];
		}
		ds.n--;
		cout << "Da xoa thong tin cua giao vien co ma " << maGV << endl;
	}
}
//Cập nhật:
bool kiemTraTrungMa_GiaoVien_CapNhatLai(const DSGiaoVien& danhSach, const char* maGV) {
	for (int i = 0; i < danhSach.n; ++i) {
		if (strcmp(danhSach.ds[i].maGiaoVien, maGV) == 0) {
			return true;
		}
	}
	return false;
}

void capNhatThongTinGiaoVien(DSGiaoVien& danhSach) {
	char maCu[15];
	char maMoi[15];

	cout << "Nhap ma giao vien muon cap nhat thong tin: ";
	cin.ignore();
	cin.getline(maCu, 15);

	int viTri = -1;
	for (int i = 0; i < danhSach.n; ++i) {
		if (strcmp(danhSach.ds[i].maGiaoVien, maCu) == 0) {
			viTri = i;
			break;
		}
	}

	if (viTri != -1) {
		cout << "Nhap ma giao vien moi: ";
		cin.getline(maMoi, 15);

		if (!kiemTraTrungMa_GiaoVien_CapNhatLai(danhSach, maMoi) || strcmp(maCu, maMoi) == 0) {
			nhapThongTinGiaoVien_CapNhat(danhSach.ds[viTri], danhSach, maMoi);
			cout << "Cap nhat thong tin thanh cong!" << endl;
		}
		else {
			cout << "Ma giao vien moi bi trung voi ma cua mot giao vien khac trong danh sach. Khong the cap nhat!" << endl;
		}
	}
	else {
		cout << "Ma giao vien nay khong ton tai trong danh sach!" << endl;
	}
}



//tìm kiếm:
bool kiemTraTonTai_MaGiaoVien(DSGiaoVien ds, char* maGV) {
	for (int i = 0; i < ds.n; i++) {
		if (strcmp(ds.ds[i].maGiaoVien, maGV) == 0) {
			return true;
		}
	}
	return false;
}
GiaoVien timKiemThongTinGiaoVienTheo_MaSoGiaoVien(DSGiaoVien ds, char* maGV) {
	for (int i = 0; i < ds.n; i++)
	{
		if (strcmp(ds.ds[i].maGiaoVien, maGV) == 0)
		{
			return ds.ds[i];
		}
	}
}
//Sap Xep theo ma tre:
void sapXepDanhSach_MaCuaGiaoVien(DSGiaoVien& ds) {
	for (int i = 0; i < ds.n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < ds.n; j++) {
			if (strcmp(ds.ds[j].maGiaoVien, ds.ds[min].maGiaoVien) < 0) {
				min = j;
			}
		}
		swap(ds.ds[i], ds.ds[min]);
	}
}
void docDanhSach_GiaoVienTuFile(const char* tenFile, DSGiaoVien& ds) {
	ifstream file(tenFile);
	if (!file.is_open()) {
		cout << "Khong mo duoc file." << endl;
		return;
	}

	file >> ds.n;
	file.ignore();

	for (int i = 0; i < ds.n; ++i) {
		file.getline(ds.ds[i].maGiaoVien, 15);
		file.getline(ds.ds[i].hoTenGiaoVien, 50);
		file >> ds.ds[i].gioiTinh;
		file.ignore();
		file.getline(ds.ds[i].diaChi, 50);
	}

	file.close();
}

//template<typename T>
void ghiDanhSachGiaoVien_VaoFile(const char* tenFile, DSGiaoVien ds) {
	ofstream file(tenFile);
	if (!file.is_open()) {
		cout << "Khong mo duoc file." << endl;
		return;
	}

	file << ds.n << endl;


	for (int i = 0; i < ds.n; ++i) {
		file << ds.ds[i].maGiaoVien << endl;
		file << ds.ds[i].hoTenGiaoVien << endl;
		file << ds.ds[i].gioiTinh << endl;
		file << ds.ds[i].diaChi << endl;
	}


	file.close();
}

//Các chuc nang hoat dong:
void themHoatDong(DSHoatDong& ds, const HoatDong& hd) {
	if (ds.n < N) {
		ds.ds[ds.n++] = hd;
		cout << "Them mot hoat dong thanh cong!" << endl;
	}
	else {
		cout << "Danh sach hoat dong da day, khong the them!" << endl;
	}
}

//Xoa:
void xoaMot_HoatDong_RaKhoiList(DSHoatDong& ds, const char* maHD) {
	int i;
	for (i = 0; i < ds.n; ++i) {
		if (strcmp(ds.ds[i].maSoHoatDong, maHD) == 0) {
			break;
		}
	}

	if (i == ds.n) {
		cout << "Khong tim thay thong tin cua hoat dong co ma hoat dong:" << maHD << endl;
	}
	else {
		for (int j = i; j < ds.n - 1; ++j) {
			ds.ds[j] = ds.ds[j + 1];
		}
		ds.n--;
		cout << "Da xoa thong tin cua hoat dong co ma hoat dong: " << maHD << endl;
	}
}


void xoa_HoatDong_RaKhoiList(DSHoatDong& ds, const char* maHD) {
	int count = 0;
	char c;
	char maTemp[15];
	for (int i = 0; i < ds.n; ++i) {
		if (strcmp(ds.ds[i].maSoHoatDong, maHD) == 0)
			count++;
	}
	if (count == 1) {
		xoaMot_HoatDong_RaKhoiList(ds, maHD);
	}
	else if (count > 1) {
		cout << "\nTim thay " << count << " tre tham gia hoat dong nay! Ban co muon xoa het tre (Y/N)";
		cin >> c;
		while (c != 'y' && c != 'Y' && c != 'N' && c != 'n')
		{
			cout << "\nKhong co lua chon nay vuilong nhap lai (Y/N): ";
			cin >> c;
		}
		if (c == 'Y' || c == 'y') {
			for (int i = 0; i < ds.n; i++) {
				xoaMot_HoatDong_RaKhoiList(ds, maHD);
			}
		}
		else {
			cout << "Vui long nhap ma tre muon xoa: ";
			cin.ignore();
			cin.getline(maTemp, 15);
			cout << maTemp;
			int i;
			for (i = 0; i < ds.n; ++i) {
				if (strcmp(ds.ds[i].maTreHD, maTemp) == 0) {
					break;
				}
			}
			if (i == ds.n) {
				cout << "Ma tre khong ton tai!";
			}
			else {
				for (int j = i; j < ds.n - 1; ++j) {
					ds.ds[j] = ds.ds[j + 1];
				}
				ds.n--;
			}
		}
	}
	else {
		cout << "\nMa hoat dong nay khong ton tai!";
	}
}

//cập nhật:
void capNhatThongTin_HoatDong(DSHoatDong& ds, DSGiaoVien b) {
	cout << "Nhap ma so cua hoat dong can cap nhat thong tin: ";
	char maHoatDong[15];
	cin.ignore();
	cin.getline(maHoatDong, 15);

	bool found = false;
	for (int i = 0; i < ds.n; ++i) {
		if (strcmp(ds.ds[i].maSoHoatDong, maHoatDong) == 0) {
			nhapThongTinHoatDong_CapNhat(ds.ds[i], b);
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "Khong tim thay thong tin cua hoat dong co ma so hoat dong: " << maHoatDong << endl;
	}
}


//tìm kiếm:
bool kiemTraTonTai_MaHoatDong(DSHoatDong ds, char* maHD) {
	for (int i = 0; i < ds.n; i++) {
		if (strcmp(ds.ds[i].maSoHoatDong, maHD) == 0) {
			return true;
		}
	}
	return false;
}
HoatDong timKiemThongTinHoatDongTheo_MaSoHoatDong(DSHoatDong ds, char* maHD) {
	for (int i = 0; i < ds.n; i++)
	{
		if (strcmp(ds.ds[i].maSoHoatDong, maHD) == 0)
		{
			return ds.ds[i];
		}
	}
}

void timKiemDanhSachHoatDong(DSHoatDong dshd, DSTre a, char* b) {
	if (kiemTraTonTai_MaHoatDong(dshd, b) == true) {
		SET_COLOR(19);
		cout << "\n============================================================================================================================================" << endl;
		cout << "|                                                              Hoat Dong Can Tim                                                           |";
		cout << "\n============================================================================================================================================" << endl;
		cout << left << setw(11) << "|Ma HD";
		cout << left << setw(20) << "Ten Hoat Dong";
		cout << left << setw(17) << "Ngay hoat dong";
		cout << left << setw(17) << "Ma Giao vien";
		cout << setw(28) << "Ten giao vien phu trach";
		cout << left << setw(12) << "Ma Tre";
		cout << left << setw(26) << "Ten tre";
		cout << left << setw(8) << "Diem so";
		cout << "|";
		cout << endl;
		cout << "============================================================================================================================================" << endl;
		for (int i = 0; i < dshd.n; i++) {
			int kq = soSanhChuoi(dshd.ds[i].maSoHoatDong, b);
			if (kq == 0) {
				cout << "|";
				SET_COLOR(7);
				xuatThongTinHoatDong(dshd.ds[i], a);
				SET_COLOR(19);
				cout << "|";
				cout << endl;
			}
		}
		cout << "\n============================================================================================================================================" << endl;
	}
	else {
		cout << "Ma so cua hoat dong khong ton tai!";
	}
}

//Sap Xep theo ma hoat dong:
void sapXepDanhSach_MaCuaHoatDong(DSHoatDong& ds) {
	for (int i = 0; i < ds.n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < ds.n; j++) {
			if (strcmp(ds.ds[j].maSoHoatDong, ds.ds[min].maSoHoatDong) < 0) {
				min = j;
			}
		}
		swap(ds.ds[i], ds.ds[min]);
	}
}
void docDanhSach_CacHoatDong_TuFile(const char* tenFile, DSHoatDong& ds) {
	ifstream file(tenFile);
	if (!file.is_open()) {
		cout << "Khong mo duoc file." << endl;
		return;
	}

	file >> ds.n;

	for (int i = 0; i < ds.n; ++i) {
		file.ignore();
		file.getline(ds.ds[i].maSoHoatDong, 15);
		file.getline(ds.ds[i].tenHoatDong, 50);
		file >> ds.ds[i].ngayHoatDong.ngayhoatdong;
		file.ignore();
		file >> ds.ds[i].ngayHoatDong.thanghoatdong;
		file.ignore();
		file >> ds.ds[i].ngayHoatDong.namhoatdong;
		file.ignore();
		file.getline(ds.ds[i].maGiaoVienPhuTrach, 15);
		file.getline(ds.ds[i].hoTenGiaoVienPhuTrach, 50);
		file.getline(ds.ds[i].maTreHD, 15);
		file >> ds.ds[i].diemSoTreDatDuoc;
	}

	file.close();
}

//template<typename T>
void ghiDanhSachCacHoatDong_VaoFile(const char* tenFile, DSHoatDong ds) {
	ofstream file(tenFile);
	if (!file.is_open()) {
		cout << "Khong mo duoc file." << endl;
		return;
	}

	file << ds.n << endl;

	for (int i = 0; i < ds.n; ++i) {
		file << ds.ds[i].maSoHoatDong << endl;
		file << ds.ds[i].tenHoatDong << endl;
		file << ds.ds[i].ngayHoatDong.ngayhoatdong << "/" << ds.ds[i].ngayHoatDong.thanghoatdong << "/" << ds.ds[i].ngayHoatDong.namhoatdong << endl;
		file << ds.ds[i].maGiaoVienPhuTrach << endl;
		file << ds.ds[i].hoTenGiaoVienPhuTrach << endl;
		file << ds.ds[i].maTreHD << endl;
		file << ds.ds[i].diemSoTreDatDuoc << endl;
	}

	file.close();
}

//menu hoat dong:

void menuHoatDong()
{
	TreMamNon tre;
	GiaoVien gv;
	DSTre dst;
	HoatDong hd, temp;
	DSHoatDong ds;
	DSGiaoVien dsgv;
	ds.n = 0;
	int choice;
	int pos;
	char maHoatDong[15];
	char tenHoatDong[50];
	docDanhSach_CacHoatDong_TuFile("Danh sach Hoat Dong.txt", ds);
	docDanhSach_GiaoVienTuFile("Danh sach Giao Vien.txt", dsgv);
	docDanhSach_TreTuFile("Danh sach Tre.txt", dst);

	do {
		SET_COLOR(4);
		cout << "\n\n================== MENU QUAN LY THONG TIN HOAT DONG TRE ==================" << endl;
		cout << "| 1. Nhap danh sach cac hoat dong                                        |" << endl;
		cout << "| 2. Xuat danh sach cac hoat dong                                        |" << endl;
		cout << "| 3. Them mot hoat dong vao danh sach                                    |" << endl;
		cout << "| 4. Xoa mot hoat dong ra khoi danh sach                                 |" << endl;
		cout << "| 5. Cap nhat thong tin cua hoat dong                                    |" << endl;
		cout << "| 6. Tim kiem thong tin cua hoat dong-(theo ma so hoat dong)             |" << endl;
		cout << "| 7. Sap xep danh sach cua hoat dong-(theo ma so hoat dong)              |" << endl;
		cout << "| 0. Thoat                                                               |" << endl;
		cout << "==========================================================================" << endl;
		SET_COLOR(7);
		//nhap lua chon
		cout << "Vui long Nhap lua chon cua ban (nhap 0 de thoat): ";
		cin >> choice;

		switch (choice) {
		case 1:
			nhapDanhSachHoatDong(ds, gv, dsgv, tre, dst);
			ghiDanhSachCacHoatDong_VaoFile("Danh sach Hoat Dong.txt", ds);
			break;
		case 2:
			cout << "Thong tin ket qua cuoi cung la:" << endl;
			inRaKetQua(dst, ds);
			break;
		case 3:
			//cin.ignore();
			NhapThongTinHoatDong(hd, ds, dsgv, tre, dst);
			themHoatDong(ds, hd);
			xuatDanhSachHoatDong(ds, dst);
			break;
		case 4:
			char maHoatDong[15];
			cout << "Nhap vao ma cua hoat dong can xoa: ";
			cin >> maHoatDong;
			xoa_HoatDong_RaKhoiList(ds, maHoatDong);
			xuatDanhSachHoatDong(ds, dst);
			ghiDanhSachCacHoatDong_VaoFile("Danh sach Hoat Dong.txt", ds);
			break;
		case 5:
			capNhatThongTin_HoatDong(ds, dsgv);
			xuatDanhSachHoatDong(ds, dst);
			ghiDanhSachCacHoatDong_VaoFile("Danh sach Hoat Dong.txt", ds);
			break;
		case 6:
			cin.ignore();
			cout << "\nNhap vao ma cua hoat dong can tim kiem thong tin: ";
			cin.getline(maHoatDong, 15);
			timKiemDanhSachHoatDong(ds, dst, maHoatDong);
			break;
		case 7:
			sapXepDanhSach_MaCuaHoatDong(ds);
			xuatDanhSachHoatDong(ds, dst);
			break;
		case 0:
			ghiDanhSachCacHoatDong_VaoFile("Danh sach Hoat Dong.txt", ds);
			cout << "Ket thuc chuong trinh!" << endl;
			break;
		default:
			cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
			break;
		}
	} while (choice != 0);
}


//Menu giao vien:
void menuGiaoVien()
{
	GiaoVien gv, temp;
	DSGiaoVien ds;
	ds.n = 0;
	int choice;
	int pos;
	char maGV[15];
	char hoTenGiaoVien[50];

	docDanhSach_GiaoVienTuFile("Danh sach Giao Vien.txt", ds);
	do {
		SET_COLOR(2);
		cout << "\n\n=================== MENU QUAN LY THONG TIN GIAO VIEN ===================" << endl;
		cout << "| 1. Nhap danh sach cac giao vien                                      |" << endl;
		cout << "| 2. Xuat danh sach cac giao vien                                      |" << endl;
		cout << "| 3. Them mot giao vien vao danh sach                                  |" << endl;
		cout << "| 4. Xoa mot giao vien ra khoi danh sach                               |" << endl;
		cout << "| 5. Cap nhat thong tin cua giao vien                                  |" << endl;
		cout << "| 6. Tim kiem thong tin cua giao vien-(theo ma so giao vien)           |" << endl;
		cout << "| 7. Sap xep danh sach cua giao vien-(theo ma so giao vien)            |" << endl;
		cout << "| 0. Thoat                                                             |" << endl;
		cout << "========================================================================" << endl;
		SET_COLOR(7);
		//nhap lua chon
		cout << "Vui long Nhap lua chon cua ban (nhap 0 de thoat): ";
		cin >> choice;

		switch (choice) {
		case 1:
			nhapDanhSachGiaoVien(ds);
			ghiDanhSachGiaoVien_VaoFile("Danh sach Giao Vien.txt", ds);
			break;
		case 2:
			xuatDanhSachGiaoVien(ds);
			break;
		case 3:
			//cin.ignore();
			themGiaoVienVaoDanhSach(ds);
			xuatDanhSachGiaoVien(ds);
			ghiDanhSachGiaoVien_VaoFile("Danh sach Giao Vien.txt", ds);
			break;
		case 4:
			char maGiaoVien[15];
			cout << "Nhap vao ma cua giao vien can xoa: ";
			cin >> maGiaoVien;
			xoaMot_GiaoVien_RaKhoiList(ds, maGiaoVien);
			xuatDanhSachGiaoVien(ds);
			ghiDanhSachGiaoVien_VaoFile("Danh sach Giao Vien.txt", ds);
			break;
		case 5:
			capNhatThongTinGiaoVien(ds);
			ghiDanhSachGiaoVien_VaoFile("Danh sach Giao Vien.txt", ds);
			xuatDanhSachGiaoVien(ds);
			break;
		case 6:
			char maGV[15];
			cin.ignore();
			cout << "\nNhap vao ma cua giao vien can tim kiem thong tin: ";
			cin.getline(maGV, 15);
			if (kiemTraTonTai_MaGiaoVien(ds, maGV) == true) {
				temp = timKiemThongTinGiaoVienTheo_MaSoGiaoVien(ds, maGV);
				SET_COLOR(11);
				cout << "\n***************************************************************************************************************";
				cout << "\n|                                              Giao Vien Can Tim                                              |";
				cout << "\n***************************************************************************************************************\n";
				cout << left << setw(15) << "|Ma giao vien";
				cout << setw(30) << "Ho ten giao vien";
				cout << setw(22) << "Gioi tinh ";
				cout << setw(43) << "Dia chi thuong tru";
				cout << "|";
				cout << "\n***************************************************************************************************************";
				cout << endl;
				cout << "|";
				SET_COLOR(7);
				xuatThongTinGiaoVien(temp);
				SET_COLOR(11);
				cout << "|";
				cout << "\n***************************************************************************************************************\n";
			}
			else {
				cout << "Ma so cua giao vien nay khong ton tai!";
			}
			break;
		case 7:
			sapXepDanhSach_MaCuaGiaoVien(ds);
			xuatDanhSachGiaoVien(ds);
			break;
		case 0:
			ghiDanhSachGiaoVien_VaoFile("Danh sach Giao Vien.txt", ds);
			cout << "Ket thuc chuong trinh!" << endl;
			break;
		default:
			cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
			break;
		}
	} while (choice != 0);
}


//----------------------------------------------
void menuTre()
{
	TreMamNon tmn, temp;
	DSTre ds;
	ds.n = 0;
	int choice;
	int pos;
	char maTre[15];
	char hoTenTre[50];
	docDanhSach_TreTuFile("Danh sach Tre.txt", ds);

	do {
		SET_COLOR(3);
		cout << "\n\n=========================== MENU QUAN LY TRE ===========================" << endl;
		cout << "| 1. Nhap danh sach cac tre                                            |" << endl;
		cout << "| 2. Xuat danh sach cac tre                                            |" << endl;
		cout << "| 3. Them mot tre vao danh sach                                        |" << endl;
		cout << "| 4. Xoa mot tre ra khoi danh sach                                     |" << endl;
		cout << "| 5. Cap nhat thong tin cua tre                                        |" << endl;
		cout << "| 6. Tim kiem thong tin cua tre-(theo ma so tre)                       |" << endl;
		cout << "| 7. Sap xep danh sach cua tre-(theo ma so tre)                        |" << endl;
		cout << "| 0. Thoat                                                             |" << endl;
		cout << "========================================================================" << endl;
		SET_COLOR(7);
		//nhap lua chon
		cout << "Vui long Nhap lua chon cua ban (nhap 0 de thoat): ";
		cin >> choice;

		switch (choice) {
		case 1:
			nhapDanhSachTre(ds);
			ghiDanhSachTre_VaoFile("Danh sach Tre.txt", ds);
			break;
		case 2:
			xuatDanhSachTre(ds);
			break;
		case 3:
			themTreVaoDanhSach(ds);
			xuatDanhSachTre(ds);
			break;
		case 4:
			char maTre[15];
			cout << "Nhap vao ma cua tre can xoa: ";
			cin >> maTre;
			xoaMotTreRaKhoiList(ds, maTre);
			xuatDanhSachTre(ds);
			ghiDanhSachTre_VaoFile("Danh sach Tre.txt", ds);
			break;
		case 5:
			//cin.ignore();
			capNhatThongTinTre(ds);
			xuatDanhSachTre(ds);
			ghiDanhSachTre_VaoFile("Danh sach Tre.txt", ds);

			break;
		case 6:
			cin.ignore();
			cout << "\nNhap vao ma cua tre can tim kiem thong tin: ";
			cin.getline(maTre, 15);
			if (kiemTraTonTai_MaTre(ds, maTre) == true) {
				temp = timKiemThongTinTreTheo_MaSoTre(ds, maTre);
				cout << "\n************************************************************************************************************************************";
				cout << "\n|                                                      ===THONG TIN TRE MA BAN CAN TIM LA===                                       |";
				cout << "\n************************************************************************************************************************************\n";
				cout << left << setw(9) << "|Ma Tre";
				cout << setw(25) << "Ten Tre";
				cout << setw(12) << "Ngay Sinh";
				cout << setw(7) << "Tuoi";
				cout << setw(12) << "Gioi Tinh";
				cout << setw(11) << "Can Nang";
				cout << setw(17) << "Ngay Nhap Hoc";
				cout << setw(25) << "Ten Phu Huynh";
				cout << setw(14) << "So Dien Thoai|";
				cout << "\n************************************************************************************************************************************";
				cout << endl;
				cout << "|";
				xuatThongTinTre(temp);
				cout << " |";
				cout << "\n************************************************************************************************************************************";

			}
			else {
				cout << "Ma so cua tre khong ton tai!";
			}
			break;
		case 7:
			sapXepDanhSach_MaCuaTre(ds);
			xuatDanhSachTre(ds);
			break;
		case 0:
			ghiDanhSachTre_VaoFile("Danh sach Tre.txt", ds);
			cout << "Ket thuc chuong trinh!" << endl;
			break;
		default:
			cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
			break;
		}
	} while (choice != 0);
}

//Menu Cha:
void menuCha()
{
	/*TreMamNon tmn, temp;
	DSTre ds;
	ds.n = 0;*/
	int choice;
	/*int pos;*/

	do {
		SET_COLOR(6);
		cout << "\n\n================== MENU QUAN LY TAT CA THONG TIN HE THONG ===================" << endl;
		cout << "| 1. Cac thao tac quan ly voi doi tuong (tre)                               |" << endl;
		cout << "| 2. Cac thao tac quan ly voi doi tuong (giao vien)                         |" << endl;
		cout << "| 3. Cac thao tac quan ly voi doi tuong (cac hoat dong)                     |" << endl;
		cout << "| 0. Thoat                                                                  |" << endl;
		cout << "=============================================================================" << endl;
		SET_COLOR(7);
		cout << "Vui long Nhap lua chon cua ban (nhap 0 de thoat): ";
		cin >> choice;

		switch (choice) {
		case 1:
			menuTre();
			break;
		case 2:
			menuGiaoVien();
			break;
		case 3:
			menuHoatDong();
			break;
		case 0:
			cout << "Ket thuc chuong trinh!" << endl;
			break;
		default:
			cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
			break;
		}
	} while (choice != 0);
}

int soSanhChuoi(const char* str1, const char* str2) {
	int i;
	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
		if (str1[i] != str2[i]) {
			return str1[i] - str2[i];
		}
	}
	return str1[i] - str2[i];
}

//Set mau chu 
void SET_COLOR(int color)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

