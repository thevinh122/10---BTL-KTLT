#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BENH_NHAN 100
#define MAX_DICH_VU 100
#define MAX_TEN 100

typedef struct {
    char tenBenhNhan[MAX_TEN];
    char dichVuDaSuDung[MAX_DICH_VU][MAX_TEN];
    int soDichVu;
    float tongVienPhi;
} BenhNhan;

typedef struct {
    char tenDichVu[MAX_TEN];
    float giaDichVu;
} DichVu;

typedef struct {
    BenhNhan danhSachBenhNhan[MAX_BENH_NHAN];
    DichVu danhSachDichVu[MAX_DICH_VU];
    int soBenhNhan;
    int soDichVu;
    float bangGiaDichVu[3][2];
} QuanLyVienPhi;

void initQuanLy(QuanLyVienPhi *ql) {
    ql->soBenhNhan = 0;
    ql->soDichVu = 0;
    ql->bangGiaDichVu[0][0] = 100000; // Kham dich vu - Phòng đơn
    ql->bangGiaDichVu[0][1] = 200000; // Kham dich vu - Phòng đôi
    ql->bangGiaDichVu[1][0] = 50000;  // Cap cuu - Phòng đơn
    ql->bangGiaDichVu[1][1] = 100000; // Cap cuu - Phòng đôi
    ql->bangGiaDichVu[2][0] = 30000;  // Kham benh - Phòng đơn
    ql->bangGiaDichVu[2][1] = 50000;  // Kham benh - Phòng đôi
}

void nhapDanhSach(QuanLyVienPhi *ql) {
    printf("Nhap danh sach benh nhan:\n");
    while (1) {
        printf("Ten benh nhan (nhap 'x' de dung): ");
        fgets(ql->danhSachBenhNhan[ql->soBenhNhan].tenBenhNhan, MAX_TEN, stdin);
        ql->danhSachBenhNhan[ql->soBenhNhan].tenBenhNhan[strcspn(ql->danhSachBenhNhan[ql->soBenhNhan].tenBenhNhan, "\n")] = 0; // Remove newline
        if (strcmp(ql->danhSachBenhNhan[ql->soBenhNhan].tenBenhNhan, "x") == 0) break;
        ql->danhSachBenhNhan[ql->soBenhNhan].soDichVu = 0;
        ql->soBenhNhan++;
    }

    printf("Nhap danh sach dich vu:\n");
    while (1) {
        DichVu dv;
        printf("Ten dich vu (nhap 'x' de dung): ");
        fgets(dv.tenDichVu, MAX_TEN, stdin);
        dv.tenDichVu[strcspn(dv.tenDichVu, "\n")] = 0; // Remove newline
        if (strcmp(dv.tenDichVu, "x") == 0) break;
        printf("Gia dich vu: ");
        scanf("%f", &dv.giaDichVu);
        getchar(); // Clear newline
        ql->danhSachDichVu[ql->soDichVu++] = dv;
    }
}

void xuatDanhSach(QuanLyVienPhi *ql) {
    printf("Danh sach benh nhan:\n");
    for (int i = 0; i < ql->soBenhNhan; i++) {
        BenhNhan *bn = &ql->danhSachBenhNhan[i];
        printf("Ten benh nhan: %s\n", bn->tenBenhNhan);
        printf("Dich vu da su dung: ");
        for (int j = 0; j < bn->soDichVu; j++) {
            printf("%s, ", bn->dichVuDaSuDung[j]);
        }
        printf("\nTong vien phi: %.2f VND\n\n", bn->tongVienPhi);
    }

    printf("Danh sach dich vu:\n");
    for (int i = 0; i < ql->soDichVu; i++) {
        printf("Ten dich vu: %s\n", ql->danhSachDichVu[i].tenDichVu);
        printf("Gia dich vu: %.2f VND\n\n", ql->danhSachDichVu[i].giaDichVu);
    }
}

BenhNhan* timKiemBenhNhan(QuanLyVienPhi *ql, const char *ten) {
    for (int i = 0; i < ql->soBenhNhan; i++) {
        if (strcmp(ql->danhSachBenhNhan[i].tenBenhNhan, ten) == 0) {
            return &ql->danhSachBenhNhan[i];
        }
    }
    return NULL;
}

void sapXepBenhNhan(QuanLyVienPhi *ql) {
    for (int i = 0; i < ql->soBenhNhan - 1; i++) {
        for (int j = i + 1; j < ql->soBenhNhan; j++) {
            if (strcmp(ql->danhSachBenhNhan[i].tenBenhNhan, ql->danhSachBenhNhan[j].tenBenhNhan) > 0) {
                BenhNhan temp = ql->danhSachBenhNhan[i];
                ql->danhSachBenhNhan[i] = ql->danhSachBenhNhan[j];
                ql->danhSachBenhNhan[j] = temp;
            }
        }
    }
}

float thuVienPhi(QuanLyVienPhi *ql) {
    float tongVienPhi = 0;
    for (int i = 0; i < ql->soBenhNhan; i++) {
        tongVienPhi += ql->danhSachBenhNhan[i].tongVienPhi;
    }
    return tongVienPhi;
}

void hienThiBangGiaDichVu(QuanLyVienPhi *ql) {
    printf("Bang gia dich vu:\n");
    printf("Loai dich vu | Phòng đơn | Phòng đôi\n");
    printf("Kham dich vu | %.2f | %.2f\n", ql->bangGiaDichVu[0][0], ql->bangGiaDichVu[0][1]);
    printf("Cap cuu      | %.2f | %.2f\n", ql->bangGiaDichVu[1][0], ql->bangGiaDichVu[1][1]);
    printf("Kham benh    | %.2f | %.2f\n", ql->bangGiaDichVu[2][0], ql->bangGiaDichVu[2][1]);
}

void xuatHoaDon(QuanLyVienPhi *ql, const char *tenBenhNhan) {
    BenhNhan *bn = timKiemBenhNhan(ql, tenBenhNhan);
    if (bn) {
        printf("Hoa don dich vu cua benh nhan %s:\n", bn->tenBenhNhan);
        for (int j = 0; j < bn->soDichVu; j++) {
            printf("- %s\n", bn->dichVuDaSuDung[j]);
        }
        printf("Tong vien phi: %.2f VND\n", bn->tongVienPhi);
    } else {
        printf("Khong tim thay benh nhan voi ten: %s\n", tenBenhNhan);
    }
}

int tongSoBenhNhan(QuanLyVienPhi *ql) {
    return ql->soBenhNhan;
}

int main() {

    
    return 0;
}
