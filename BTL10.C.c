#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

struct BenhNhan{
	char name[50];
	char ngaySinh[50];
	long long ID;
	char queQuan[100];
	long long soDienthoai;
	long long vienPhi;

    // void (*input)(struct BenhNhan*);
    // void (*display)(const struct BenhNhan*);
    // const char* (*getName)(const struct BenhNhan*);
    // long long (*getID)(const struct BenhNhan*);
    // void (*suaThongtin)(struct BenhNhan*, const char*, const char*, const char*, long long, long long);
    // long long (*get_vienPhi)(const struct BenhNhan*);
    // void (*suaVienphi)(struct BenhNhan*, long long);
};	

    void input(struct BenhNhan* bn){
		printf("Nhap ho ten: ");
		fgets(bn->name, 50, stdin);
		printf("\nNhap ngay sinh: ");
		fgets(bn->ngaySinh, 50, stdin);
		printf("\nNhap ID: ");
		scanf("%lld", &bn->ID);
		fflush(stdin);
		printf("\nNhap que quan: ");
		fgets(bn->queQuan, 100, stdin);
		printf("\nNhap so dien thoai: ");
		scanf("%lld", bn->soDienthoai);
        getchar();
};
	
    void display(const struct BenhNhan* bn){
		printf("\nHo ten: %-15s", bn->name);
		printf("\nNgay sinh: %-15s", bn->ngaySinh);
		printf("\nID: %-15lld", bn->ID);
		printf("\nQue quan: %-15s", bn->queQuan);
		printf("\nSo dien thoai: %-15lld", bn->soDienthoai);
	};
	
    const char* getName(const struct BenhNhan* bn){//dung con tro o char de co the tra ve duoc ten
		return bn->name;
	};
	long long getID(const struct BenhNhan* bn){
		return bn->ID;
	};
	
	//Ham sua thong tin benh nhan
	void suaThongtin(struct BenhNhan* bn, const char* _name, const char* _ngaySinh, const char* _queQuan, long long _tel, long long _vienPhi) {
    if (_name && strlen(_name) > 0) {
        strncpy(bn->name, _name, sizeof(bn->name) - 1);
        bn->name[sizeof(bn->name) - 1] = '\0';
    }
    if (_ngaySinh && strlen(_ngaySinh) > 0) {
        strncpy(bn->ngaySinh, _ngaySinh, sizeof(bn->ngaySinh) - 1);
        bn->ngaySinh[sizeof(bn->ngaySinh) - 1] = '\0';
    }
    if (_queQuan && strlen(_queQuan) > 0) {
        strncpy(bn->queQuan, _queQuan, sizeof(bn->queQuan) - 1);
        bn->queQuan[sizeof(bn->queQuan) - 1] = '\0';
    }
    if (_tel != 0) {
        bn->soDienthoai = _tel;
    }
    if (_vienPhi != 0) {
        bn->vienPhi = _vienPhi;
    }
}

	
	long long get_vienPhi(const struct BenhNhan* bn){
		return bn->vienPhi;
	}
	
	void suaVienPhi(struct BenhNhan* bn, long long _vienPhi){
		bn->vienPhi = _vienPhi;
	}

struct DichVu{
	char loaiDichVu[50];
	char loaiPhong[50];
	char ngayNhapVien[50]; 
	char ngayXuatVien[50];
	double tienTamUng; 
	double tongTien;
	
	double bangGiaDichVu[3]; //Kham dich vu, kham benh, cap cuu
    double bangGiaPhong[2];  //Phong don, phong doi
	
};

    void khoitao(struct DichVu* dv){
        double temp1BangGiaDichVu[3] = {500000, 1000000, 2000000};
        double temp2BangGiaPhong[2] = {100000, 200000};
        for (int i = 0; i < 3; i++){
            dv->bangGiaDichVu[i] = temp1BangGiaDichVu[i];
        }
        for (int i = 0; i < 2; i++){
            dv->bangGiaPhong[i] = temp2BangGiaPhong[i];
        }
    }
    //Ham nhap
	void intput1(struct DichVu* dv){
		int chooseSer, chooseRoom;
		
		//Chon loai dich vu
		printf("\nChon loai dich vu (1. Kham dich vu, 2. Kham benh, 3.Cap cuu): ");
		scanf("%d", &chooseSer);
		while (chooseSer < 1 || chooseSer > 3){
			printf("\nLoai dich vu khong hop le, vui long nhap lai! ");
			printf("\nChon loai dich vu: %d", &chooseSer);
		} 
		
		//Chon loai phong
		printf("\nChon loai phong (1. Phong don, 2. Phong doi): ");
		scanf("%d", &chooseRoom);
		while (chooseRoom < 1 || chooseRoom > 2 ){
			printf("\nLoai phong khong hop le, vui long nhap lai!");
			printf("\nChon loai phong: "); 
			scanf("%d", &chooseRoom);
		}
		
		printf("\nNgay nhap vien: ");
		fflush(stdin);
		fgets(dv->ngayNhapVien, 50, stdin);
		
		printf("\nNgay xuat vien: ");
		fflush(stdin);
		fgets(dv->ngayXuatVien, 50, stdin);
		
		printf("\nNhap so tien tam ung: ");
		scanf("%lf", &dv->tienTamUng );
		
		strcpy(dv->loaiDichVu, (chooseSer == 1))? "Kham dich vu" : (chooseSer == 2) ? "Kham benh": "Cap cuu";
		strcpy(dv->loaiPhong, (chooseRoom == 1)) ? "Phong don": "Phong doi";
		
		dv->tongTien = dv->bangGiaDichVu[chooseSer - 1 ] + dv->bangGiaPhong[chooseRoom - 1];
    }	
		//Hien thi
	void display1(const struct DichVu* dv){
			printf("\nLoai dich vu: %-15s", dv->loaiDichVu);
			printf("\nLoai phong: %-15s", dv->loaiPhong);
			printf("\nNgay nhap vien; %-15s", dv->ngayNhapVien);
			printf("\nNgay xuat vien: %-15s", dv->ngayXuatVien);
			printf("\nTien tam ung: %-15lf", dv->tienTamUng);
			printf("\nTong tien: %-15lf", dv->tongTien);
			
	}
		
		double getTongTien(const struct DichVu* dv){
			return dv->tongTien;
		}
		
		const char* getLoaiDichVu(const struct DichVu* dv){
			return dv->loaiDichVu;
		}
		
		const char* getLoaiphong(const struct DichVu* dv){
			return dv->loaiPhong;
		}
		
		void suaLoaiDichVu(struct DichVu* dv, const char* _loaidichvu, const char* _loaiphong, const char* _ngaynhap,const char* _ngayxuat, double _tientamung, double _tongtien ){
			
            if (_loaidichvu && strlen(_loaidichvu) > 0) {
                strncpy(dv->loaiDichVu, _loaidichvu, sizeof(dv->loaiDichVu) - 1);
                dv->loaiDichVu[sizeof(dv->loaiDichVu) - 1] = '\0';
            }
            if(_loaiphong && strlen(_loaiphong) > 0){
                strncpy(dv->loaiPhong, _loaiphong, sizeof(dv->loaiPhong)-1);
                dv->loaiPhong[sizeof(dv->loaiPhong)-1]='\0';
            }
            if(_ngaynhap &&strlen(_ngaynhap) > 0){
                strncpy(dv->ngayNhapVien, _ngaynhap, sizeof(dv->ngayNhapVien)-1);
                dv->ngayNhapVien[sizeof(dv->ngayNhapVien)-1] = '\0';
            }
            if(_ngayxuat &&strlen(_ngayxuat) > 0){
                strncpy(dv->ngayXuatVien, _ngayxuat, sizeof(dv->ngayXuatVien)-1);
                dv->ngayXuatVien[sizeof(dv->ngayXuatVien)-1] = '\0';
            }
            
            if (dv->tienTamUng != 0) dv->tienTamUng = _tientamung;
			if (dv->tongTien != 0) dv->tongTien = _tongtien;
		}
	
	

struct QuanLyVienPhi{
	struct BenhNhan benh_nhan[100];
	int soLuongBenhNhan;
	struct DichVu dich_vu[100];
	int soLuongDichVu;
};	

//Ham khoi tao gia tri
void khoitao1(struct QuanLyVienPhi* qlvp ){
    qlvp->soLuongBenhNhan = 0;
    qlvp->soLuongDichVu = 0;
}   
void nhapDanhSachBenhNhan(struct QuanLyVienPhi* qlvp){
	int SoLuong;
	printf("\nNhap so luong benh nhan: ");
	scanf("%d", &SoLuong);
	fflush(stdin);

	for (int i = 0; i < SoLuong; i++){
        printf("Nhap thong tin benh nhan thu %d:\n", i + 1);
        input(&qlvp->benh_nhan[qlvp->soLuongBenhNhan++]);
	}
}
	
	void hienThiDanhSach(const struct QuanLyVienPhi* qlvp){
		for (int i = 0; i < qlvp->soLuongBenhNhan; i++){
			display(&qlvp->benh_nhan[i]);
			printf("\n");
		}
	}
	
	void timKiemTheoTen(const char* _name, const struct QuanLyVienPhi* qlvp){
		for (int i = 0; i < qlvp->soLuongBenhNhan; i++){
			if (strcpy(getName(&qlvp->benh_nhan[i]), _name) == 0){
				display(&qlvp->benh_nhan[i]);
				return ;
			}
		}
		printf("\nKhong tim thay benh nhan! ");
		
	}
	
	void suaThongTinBenhNhan(const char* name, const struct QuanLyVienPhi* qlvp){
		for (int i = 0; i < qlvp->soLuongBenhNhan; i++){
			if (getName(&qlvp->benh_nhan[i]) == name){
				char _name, _ngaySinh, _queQuan;
				long long _tel;
				long long _vienPhi;
				
				printf("\nNhap thong tin moi(de trong neu khong muon thay doi): ");
				printf("\nNhap ten: ");
				fgets(_name, 50, stdin);
				printf("\nNhap ngay sinh: ");
				fgets(_ngaySinh, 50, stdin);
				printf("\nNhap que quan: ");
				fgets(_queQuan, 50, stdin);
				printf("\nNhap so dien thoai: ");
				scanf("%lld", &_tel);
				printf("\nNhap vien phi: ");
				scanf("%lld", &_vienPhi);
				fflush(stdin);
				
				suaThongtin(&qlvp->benh_nhan[i],_name, _ngaySinh, _queQuan, _tel, _vienPhi);
				return;
			}
		}
		printf("\nKhong tim thay benh nhan! ");
	}
	

    //Tao ham so sanh
    int compareBenhNhan(const void* a, const void* b) {
    const struct BenhNhan* bn1 = *(const struct BenhNhan**)a;
    const struct BenhNhan* bn2 = *(const struct BenhNhan**)b;
    
    float vienPhi1 = get_VienPhi(bn1);
    float vienPhi2 = get_VienPhi(bn2);

    return (vienPhi1 > vienPhi2) - (vienPhi1 < vienPhi2);
    }

	// void sapXepTheoVienPhi(const struct QuanLyVienPhi* qlvp){
    //     bool tang_dan = true;
	// 	sort(qlvp->benh_nhan, qlvp->benh_nhan + qlvp->soLuongBenhNhan, [tang_dan](const struct BenhNhan* a, const struct BenhNhan* b){
	// 		return tang_dan? a.get_VienPhi() < b.get_VienPhi() : a.get_VienPhi()>b.get_VienPhi();
	// 	});	
	// }
	
    //Ham so sanh vien phi
    void sapXepTheoVienPhi(struct QuanLyVienPhi* qlvp) {
    struct BenhNhan* benhNhanPtrs[100];  
    for (int i = 0; i < qlvp->soLuongBenhNhan; i++) {
        benhNhanPtrs[i] = &qlvp->benh_nhan[i];
    }

    qsort(benhNhanPtrs, qlvp->soLuongBenhNhan, sizeof(struct BenhNhan*), compareBenhNhan);
    for (int i = 0; i < qlvp->soLuongBenhNhan; i++) {
        qlvp->benh_nhan[i] = *benhNhanPtrs[i];
    }
    }

	//hien thi benh nhan co vien phi cao nhat
	void timMax(const struct QuanLyVienPhi *qlvp){
		if(qlvp->soLuongBenhNhan == 0){
			printf("\nDanh sach benh nhan trong!");
			return;
		}
		const struct Benhnhan* max_benhNhan = &qlvp->benh_nhan[0];
        
		for (int i = 1; i < qlvp->soLuongBenhNhan; i++){
			if(get_VienPhi(&qlvp->benh_nhan[i]) > get_VienPhi(&max_benhNhan)){
				max_benhNhan = &qlvp->benh_nhan[i];
			}
		}
		printf("\nBenh nhan co vien phi cao nhat la: ");
		display(&max_benhNhan);
	}
	
	void nhapDanhSachDichVu(struct QuanLyVienPhi* qlvp){
		int soLuong;
		printf("\nNhap so luong dich vu: ");
		scanf("%d", &soLuong);
		
		for(int i = 0; i < soLuong; i++){
			struct DichVu dv;
			input1(&dv);
			qlvp->dich_vu[qlvp->soLuongDichVu++]= dv;
		}
	}
	
	//hien thi danh sach dich
	void hienThiDanhSachDV(const struct QuanLyVienPhi* qlvp){
		for (int i = 0; i < qlvp->soLuongDichVu; i++){
			display(&qlvp->dich_vu[i]);
			printf("\n");
		}
	}
	
	//Tim kiem dich vu theo ten
	void timKiemTheoTen(const char* name, const struct QuanLyVienPhi* qlvp){
		for (int i = 0; i < qlvp->soLuongDichVu; i++){
			if (getTongTien(&qlvp->dich_vu[i]) == stod(name)){
				display(&qlvp->dich_vu[i]);
				return;
			}
		}
		printf("\nKhong tim thay dich vu!");
	}
	
	//Tinh tong tien dich vu
	double tinhTongTienDichVu(const struct QuanLyVienPhi* qlvp){
		double tongTien = 0;
		for(int i = 0; i < qlvp->soLuongDichVu; i++){
			tongTien +=getTongTien(&qlvp->dich_vu[i]);
		}
		return tongTien;
	}
	
	//Hien thi tong tien
	void hienThiTongTien(const struct QuanLyVienPhi* qlvp){
		double tongTienDichVu = tinhTongTienDichVu(&qlvp);
		printf("\nTong tien cua dich vu la: %lf", tongTienDichVu);
	}
	
	//Sua loai dich vu
	void suaDichVu(const char* loaiDichVu, struct QuanLyVienPhi* qlvp){
		for(int i = 0; i< qlvp->soLuongDichVu; i++){
			if (getLoaiDichVu(&qlvp->dich_vu[i]) == loaiDichVu){
				char _loaidichvu, _loaiphong, _ngaynhapvien, _ngayxuatvien;
				double _tientamung, _tongtien;
				
				printf("\nNhap thong tin moi(de trong neu khong muon thay doi)");
				printf("\nNhap loai dich vu: ");
				fgets(_loaidichvu, 50, stdin);
				printf("\nNhap loai phong: ");
				fgets(_loaiphong, 50, stdin);
				printf("\nNhap ngay nhap vien: ");
				fgets(_ngaynhapvien, 50, stdin);
				printf("\nNgay xuat vien: ");
				fgets(_ngayxuatvien, 50, stdin);
				printf("\nNhap tien tam ung: ");
				scanf("%lf", &_tientamung);
				printf("\nNhap tong tien: ");
				scanf("%lf", &_tongtien);
				
				flfush(stdin);
				
			    suaLoaiDichVu(&qlvp->dich_vu[i],_loaidichvu, _loaiphong, _ngaynhapvien, _ngayxuatvien, _tientamung, _tongtien);
				return;
			}
		}
		printf("\nKhong tim thay dich vu!");
	}


int main(){
	struct QuanLyVienPhi* qlvp;
	int choice;
	do{
		printf("\n---------------------MENU------------------\n");
		printf("- 1. Quan ly thong tin benh nhan           -\n");
		pritnf("- 2. Hien thi thong tin benh nhan          -\n") ;
		printf("- 3. Tim kiem benh nhan theo ten           -\n") ;
		printf("- 4. Sua thong tin cua benh nhan           -\n") ;
		printf("- 5. Sap xep benh nhan theo vien phi tang  -\n") ;
		printf("- 6. Lua chon dich vu                      -\n") ;
		printf("- 7. Hien thi danh sach dich vu da chon    -\n");
		printf("- 8. Tinh tong vien phi                    -\n") ;
		printf("- 9. Tim benh nhan co vien phi cao nhat    -\n") ;
		printf("- 10. Thoat                                -\n") ;
		printf("--------------------------------------------\n") ;
		printf("Nhap lua chon: ") ;
		scanf("%d", &choice);
		fflush(stdin);
		
		switch(choice){
			case 1:
				nhapDanhSachBenhNhan(&qlvp);
				break;
			case 2:
				hienThiDanhSach(&qlvp);
				break;
			case 3: {
				break;
				char name;
				printf("\nNhap ten benh nhan can tim: ");
				fgets(name, 50, stdin);
				timKiemTheoTen(name, &qlvp);
				break;
			}
			case 4:{
				char name;
				printf("\nNhap thong tin benh nhan can sua: ");
				fgets(name, 50, stdin);
				suaThongTinBenhNhan(name, &qlvp);
				break;
			}
			case 5:{
				sapXepTheoVienPhi(&qlvp);
				hienThiDanhSach(&qlvp);
				break;
			}
			case 6:{
				nhapDanhSachDichVu(&qlvp);
				break;
			}
			case 7:{
				hienThiDanhSachDV(&qlvp);
				break;
			}
			case 8: {
				hienThiTongTien(&qlvp);
				break;
			}
			case 9: {
				timMax(&qlvp);
				break;
			}
			case 10: {
				printf("\nThoat chuong trinh!");
				break;
			}
			default:
				printf("\nLua chon khong hop le, vui long chon lai!");
				break;				
		}
	} while (choice != 10);
	return 0;
}