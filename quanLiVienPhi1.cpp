#include <iostream> 
#include <string>
#include <algorithm>
#include <limits>
#include <iomanip>

using namespace std;


// LOP BENH NHAN

class BenhNhan {
private:
	string name;
	string ngaySinh;
	long long ID;
	string queQuan;
	long long soDienThoai;
	long long vienPhi;
public:
	BenhNhan() : ID(0), soDienThoai(0), vienPhi(0) {}

	BenhNhan(string name, string ngaySinh, long long ID, string queQuan, long long soDienThoai, long long vienPhi)
		: name(name), ngaySinh(ngaySinh), ID(ID), queQuan(queQuan), soDienThoai(soDienThoai), vienPhi(vienPhi) {}

// Nhap thon tin benh nhan
	void input() {
		cout << "\nNhap ho va ten: ";
		getline(cin, name);
		cout << "\nNhap ngay sinh: ";
		getline(cin, ngaySinh);
		cout << "\nNhap ID: ";
		cin >> ID;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Lay gia tri lon nhat co the
		cout << "\nNhap que quan: ";
		getline(cin, queQuan);
		cout << "\nNhap so dien thoai: ";
		cin >> soDienThoai;
		getchar();
	}

// Hien thi thong tin benh nhan
	void hienThi() const {
		cout << "Ten: " << name << endl;
		cout << "Ngay sinh: " << ngaySinh << endl;
		cout << "ID: " << ID << endl;
		cout << "Que quan: " << queQuan << endl;
		cout << "So dien thoai: " << soDienThoai << endl;
		cout << "Vien phi: " << vienPhi << endl;
	}

	string getName() const {
		return name;
	}
	long long getID() const {
		return ID;
	}

// Ham sua thong tin benh nhan
	void suaThongTin(string name, string queQuan, string ngaySinh, long long soDienThoai, long long vienPhi) {
		if (!name.empty()) this->name = name;
		if (!ngaySinh.empty()) this->ngaySinh = ngaySinh;
		if (!queQuan.empty()) this->queQuan = queQuan;
		if (soDienThoai != 0) this->soDienThoai = soDienThoai;
		if (vienPhi != 0) this->vienPhi = vienPhi;
	}

	long long get_vienPhi() const {
		return vienPhi;
	}
	void suaVienPhi(long long vienPhi) {
		this->vienPhi = vienPhi;
	}
};


// LOP DICH VU

class DichVu {
private: 
	string loaiDichVu;
	string loaiPhong;
	string ngayNhapVien;
	string ngayXuatVien;
	double tienTamUng;
	double tongTien;

	double bangGiaDichVu[3] = { 500000, 1000000, 2000000 }; //Kham dich vu, kham benh, cap cuu
	double bangGiaPhong[2] = { 100000, 200000 }; // Phong don, phong doi

public:
	DichVu() : tienTamUng(0), tongTien(0) {}

	DichVu(string loaiDichVu, string loaiPhong, string ngayNhapVien, string ngayXuatVien, double tienTamUng, double tongTien) 
		: loaiDichVu(loaiDichVu), loaiPhong(loaiPhong), ngayNhapVien(ngayNhapVien), ngayXuatVien(ngayXuatVien), tienTamUng(tienTamUng), tongTien(tongTien) {}

// Ham nhap cac lua chon dich vu
	void input() {
		int chonDichVu, chonPhong;

		cout << "Chon loai dich vu (1.Kham dich vu, 2.Kham benh, 3.Cap cuu): ";
		cin >> chonDichVu;
		while (chonDichVu < 1 || chonDichVu > 3) {
			cout << "Loai dich vu khong hop le, vui long nhap lai !";
			cin >> chonDichVu;
		}
		cout << "CHon loai phong (1.Phong don, 2.Phong doi): ";
		cin >> chonPhong;
		while (chonPhong < 1 || chonPhong > 2) {
			cout << "Loai phong khong hop le, vui long chon lai !";
			cin >> chonPhong;
		}

		cout << "Nhap ngay nhap vien: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, ngayNhapVien);

		cout << "Nhap ngay xuat vien: ";
		getline(cin, ngayXuatVien);

		cout << "Nhap so tien tam ung: ";
		cin >> tienTamUng;

		loaiDichVu = (chonDichVu == 1) ? "Kham dich vu" : (chonDichVu == 2) ? "Kham benh" : "Cap cuu";
		loaiPhong = (chonPhong == 1) ? "Phong don" : "Phong doi";
		
		tongTien = bangGiaDichVu[chonDichVu - 1] + bangGiaPhong[chonPhong - 1] + tienTamUng;
	}

// Ham hien thi dich vu
	void hienThi() const {
		cout << fixed << setprecision(0); // Hien thi so tien khong co phan thap phan
		cout << "Loai dich vu: " << loaiDichVu << endl;
		cout << "Loai phong: " << loaiPhong << endl;
		cout << "Ngay nhap vien: " << ngayNhapVien << endl;
		cout << "Ngay xuat vien: " << ngayXuatVien << endl;
		cout << "Tien tam ung: " << tienTamUng << endl;
		cout << "Tong tien: " << tongTien << endl;
	}

	double getTongTien() const {
		return tongTien;
	}

	string getLoaiDichVu() const {
		return loaiDichVu;
	}

// Ham sua loai dich vu
	void suaLoaiDichVu(string loaiDichVu, string loaiPhong, string ngayNhapVien, string ngayXuatVien, double tienTamUng, double tong_tien) {
		if (!loaiDichVu.empty()) this->loaiDichVu = loaiDichVu;
		if (!loaiPhong.empty()) this->loaiPhong = loaiPhong;
		if (!ngayNhapVien.empty()) this->ngayNhapVien = ngayNhapVien;
		if (!ngayXuatVien.empty()) this->ngayXuatVien = ngayXuatVien;
		if (tienTamUng != 0) this->tienTamUng = tienTamUng;
		if (tongTien != 0) this->tongTien = tongTien;
	}
};


// LOP QUAN LY VIEN PHI

class QuanLyVienPhi {
private:
	BenhNhan benh_nhan[100];
	int soLuongBenhNhan;
	DichVu dich_vu[100];
	int soLuongDichVu;
public:
	QuanLyVienPhi() : soLuongBenhNhan(0), soLuongDichVu(0) {}

// Ham nhap danh sach benh nhan
	void nhapDanhSachBenhNhan() {
		int soLuong;
		cout << "Nhap so luong benh nhan: ";
		cin >> soLuong;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		for (int i = 0; i < soLuong; i++) {
			BenhNhan b;
			cout << "\nBenh nhan thu " << i + 1 << ": ";
			b.input();
			benh_nhan[soLuongBenhNhan++] = b;
		}
	}

// Hien thi danh sach benh nhan
	void hienThiDanhSach() const {
		for (int i = 0; i < soLuongBenhNhan; i++) {
			benh_nhan[i].hienThi();
			cout << endl;
		}
	}

// Tim kiem benh nhan theo ten
	void tiemKiemBenhNhan(const string& name) const {
		for (int i = 0; i < soLuongBenhNhan; i++) {
			if (benh_nhan[i].getName() == name) {
				benh_nhan[i].hienThi();
				return;
			}
		}
		cout << "Khong tim thay benh nhan!" << endl;
	}

// Sua thong tin benh nhan
	void suaThongTinBenhNhan(const string& name) {
		for (int i = 0; i < soLuongBenhNhan; i++) {
			if (benh_nhan[i].getName() == name) {
				string _name, _ngaySinh, _queQuan;
				long long _soDienThoai;
				long long _vienPhi;

				cout << "Nhap thong tin moi (de trong neu khong muon thay doi): \n";
				cout << "Nhap ten: ";
				getline(cin, _name);
				cout << "Nhap ngay sinh: ";
				getline(cin, _ngaySinh);
				cout << "Nhap que quan: ";
				getline(cin, _queQuan);
				cout << "Nhap so dien thoai: ";
				cin >> _soDienThoai;
				cout << "Nhap vien phi: ";
				cin >> _vienPhi;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				benh_nhan[i].suaThongTin(_name, _ngaySinh, _queQuan, _soDienThoai, _vienPhi);
				return;
			}
		}
		cout << "Khong tim thay benh nhan! " << endl;
	}

// Sap xep benh nhan theo vien phi tang dan
	void sapXepTheoVienPhi(bool tang_dan = true) {
		sort(benh_nhan, benh_nhan + soLuongBenhNhan, [tang_dan](const BenhNhan& a, const BenhNhan& b) {
			return tang_dan ? a.get_vienPhi() < b.get_vienPhi() : a.get_vienPhi() > b.get_vienPhi();
			});
	}

// Tim benh nhan co vien phi cao nhat 
	void timMax() const {
		if (soLuongBenhNhan == 0) {
			cout << "Danh sach benh nhan trong !" << endl;
			return;
		}
		const BenhNhan* max_benhNhan = &benh_nhan[0];
		for (int i = 1; i < soLuongBenhNhan; i++) {
			if (benh_nhan[i].get_vienPhi() > max_benhNhan->get_vienPhi()) {
				max_benhNhan = &benh_nhan[i];
			}
		}
		cout << "Benh nhan co vien phi cao nhat la:\n";
		max_benhNhan->hienThi();
	}

// Lua chon dich vu
	void nhapDanhSachDichVu() {
		int soLuong;
		cout << "\nNhap so luong dich vu: ";
		cin >> soLuong;
		//cin.ignore(numeric_limits<streamsize>::max, '\n');

		for (int i = 0; i < soLuong; i++) {
			DichVu dv;
			cout << "Dich vu thu" << i + 1 << ": ";
			dv.input();
			dich_vu[soLuongDichVu++] = dv;
		}
	}

// Hien thi danh sach dich da chon
	void hienThiDanhSachDV() const {
		for (int i = 0; i < soLuongDichVu; i++) {
			dich_vu[i].hienThi();
			cout << endl;
		}
	}

// Tim kiem dich vu theo ten
	void timKiemTheoTen(const string& name) const {
		for (int i = 0; i < soLuongDichVu; i++) {
			if (dich_vu[i].getTongTien() == stod(name)) {
				dich_vu[i].hienThi();
				return;
			}
		}
		cout << "Khong tim thay dich vu! " << endl;
	}

// Tinh tong so tien 
	double tinhTongTienDichVu() const {
		double tongTien = 0;
		for (int i = 0; i < soLuongDichVu; i++) {
			tongTien += dich_vu[i].getTongTien();
		}
		return tongTien;
	}
// Hien thi tong tien
	void hienThiTongTien() const {
		double tongTienDichVu = tinhTongTienDichVu();
		cout << "Tong tien cua dich vu la: " << tongTienDichVu << endl;
	}

// Sua loai dich vu
	void suaDichVu(const string& loaiDichVu) {
		for (int i = 0; i < soLuongDichVu; i++) {
			if (dich_vu[i].getLoaiDichVu() == loaiDichVu) {
				string _loaiDichVu, _loaiPhong, _ngayNhapVien, _ngayXuatVien;
				double _tienTamUng, _tongTien;

				cout << "Nhap thong tin moi (de trong neu khong muon thay doi): \n";
				cout << "Nhap loai dich vu: ";
				getline(cin, _loaiDichVu);
				cout << "Nhap loai phong: ";
				getline(cin, _loaiPhong);
				cout << "Nhap ngay nhap vien: ";
				getline(cin, _ngayNhapVien);
				cout << "Nhap ngay xuat vien: ";
				getline(cin, _ngayXuatVien);
				cout << "Nhap tien tam ung: ";
				cin >> _tienTamUng;
				cout << "Nhap tong tien: ";
				cin >> _tongTien;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				dich_vu[i].suaLoaiDichVu(_loaiDichVu, _loaiPhong, _ngayNhapVien, _ngayXuatVien, _tienTamUng, _tongTien);
				return;
			}
		}
		cout << "Khong tim thay dich vu! " << endl;
	}
};


int main() {
	QuanLyVienPhi qlvp;
	int choice;
	do {
		cout << "\n--------------------MENU-------------------\n";
		cout << "| 1. Quan ly thong tin benh nhan           |\n";
		cout << "| 2. Hien thi thong tin benh nhan          |\n";
		cout << "| 3. Tim kiem benh nhan theo ten           |\n";
		cout << "| 4. Sua thong tin cua benh nhan           |\n";
		cout << "| 5. Lua chon dich vu                      |\n";
		cout << "| 6. Hien thi danh sach dich vu da chon    |\n";
		cout << "| 7. Tim dich vu theo ten                  |\n";
		cout << "| 8. Sua dich vu                           |\n";
		cout << "| 9. Hien thi tong vien phi                |\n";
		cout << "| 10. Sap xep benh nhan theo vien phi tang |\n";
		cout << "| 11. Tim benh nhan co vien phi lon nhat   |\n";
		cout << "| 12. Thoat chuong trinh!                  |\n";
		cout << "--------------------------------------------\n";
		cout << "\nNhap lua chon: ";
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (choice) {
		case 1:
			qlvp.nhapDanhSachBenhNhan();
			break;
		case 2:
			qlvp.hienThiDanhSach();
			break;
		case 3: {
			string name;
			cout << "Nhap ten benh nhan can tim: ";
			getline(cin, name);
			qlvp.tiemKiemBenhNhan(name);
			break;
		}
		case 4: {
			string name;
			cout << "Nhap thong tin benh nhan can sua: ";
			getline(cin, name);
			qlvp.suaThongTinBenhNhan(name);
			break;
		}
		case 5:
			qlvp.nhapDanhSachDichVu();
			break;
		case 6:
			qlvp.hienThiDanhSachDV();
			break;
		case 7: {
			string name;
			cout << "Nhap ten dich vu can tim: ";
			getline(cin, name);
			qlvp.timKiemTheoTen(name);
			break;
		}
		case 8: {
			string name;
			cout << "Nhap thong ten dich vu can sua: ";
			getline(cin, name);
			qlvp.suaDichVu(name);
			break;
		}
		case 9:
			qlvp.hienThiTongTien();
			break;
		case 10:
			qlvp.sapXepTheoVienPhi(false);
			qlvp.hienThiDanhSach();
			break;
		case 11:
			qlvp.timMax();
			break;
		case 12:
			cout << "Thoat chuong trinh! ";
			break;
		default:
			cout << "Lua chon khong hop le, vui long chon lai!\n";
			break;
		}
	} while (choice != 12);

	return 0;
}
