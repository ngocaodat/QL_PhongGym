#include<iostream> //thu vien nhap xap cout, cin
#include<conio.h> //getch()
#include<string.h> //char
#include<iomanip> //setw()
//Quan ly phong Gym
using namespace std;
//Lop qlkhach hang gym
class khachhang{
	private:
		int makh, sdt; //khai bao thuoc tinh
		string tenkh, ngaysinh, quequan;
	public:
		void input(){ //xay dung phuong thuc nhap
			cin.ignore(); // xoa bo nho dem
			cout<<" \nNhap ma khach hang: "; cin>>makh; fflush(stdin); //fflush xoa bo nho dem
			while(makh<0){ //kiem tra du lieu nhap vao dieu kien makh > 0.
				cout<<" \nVui long nhap ma khach hang >0: "; cin>>makh; fflush(stdin); //vi du: nhap makh -2 se phai nhap lai
			}
			cout<<" \nNhap ten khach hang: "; getline(cin,tenkh); fflush(stdin);
			cout<<" \nNhap ngay sinh: "; getline(cin,ngaysinh); fflush(stdin);
			cout<<" \nNhap que quan: "; getline(cin,quequan); fflush(stdin);
			cout<<" \nNhap so dien thoai: "; cin>>sdt; fflush(stdin);
		}
		void output(){ //xay dung phuong thuc xuat
			cout<<makh<<setw(13)<<tenkh<<setw(9)<<ngaysinh;
			cout<<setw(12)<<quequan<<setw(10)<<sdt;
		}
		string get_tenkh(){
			return tenkh;
		}
		int get_makh(){
			return makh;
		}
};
//Lop Quan ly goitap
class goitap{
	private:
		int handky, hoivien;
		string goidky, ngaydky;
		float phigoitap, phidichvu, tongtien;
	public:
		void input(){
			cout<<" \nNhap goi dang ky(Gym or Yoga): ";getline(cin,goidky);fflush(stdin);
			cout<<" \nNhap ngay dang ky: ";getline(cin,ngaydky);fflush(stdin);
			cout<<" \nThoi han dang ky(Year or month): ";cin>>handky;fflush(stdin);
			cout<<" \nNhap phi goi tap(1 month, 6 month or 1 year): ";cin>>phigoitap;fflush(stdin);
			while((phigoitap!=350) && (phigoitap!=2100) && (phigoitap!=3000)){ //3 muc do phigoitap
				cout<<" \nVui long nhap lai phi goi tap: ";cin>>phigoitap;fflush(stdin);
			}
			cout<<" \nNhap phi dich vu: ";cin>>phidichvu;fflush(stdin);
			tongtien=(phigoitap + phidichvu);
			//cout<<" \nTong tien goi tap: "<<tongtien;fflush(stdin);
		}
		void output(){
			cout<<setw(9)<<goidky<<setw(10)<<ngaydky<<setw(9)<<handky;
			cout<<setw(10)<<phigoitap<<setw(10)<<phidichvu<<setw(10)<<tongtien;
		}
		float get_tongtien(){
			return tongtien;
		}
};
// xay dung class quan ly thiet bi gym
class qlythietbi{
	public:
		int masp, soluong;
		string tenthietbi, tinhtrang;
	//public:
		void Input(){
			cin.ignore();// xoa bo nho dem
			cout<<" \nNhap ma san pham: ";cin>>masp;fflush(stdin);
			cout<<" \nNhap so luong ton kho: ";cin>>soluong;fflush(stdin);
			cout<<" \nNhap ten thiet bi: ";getline(cin,tenthietbi);fflush(stdin);
			cout<<" \nNhap tinh trang thiet bi (new or old): ";getline(cin,tinhtrang);fflush(stdin);
		}
		void Output(){
			cout<<"\nMaspham"<<setw(10)<<"Soluong"<<setw(13)<<"Tenthietbi"<<setw(13)<<"Tinhtrang"<<setw(10);
			cout<<setw(10)<<masp<<setw(10)<<soluong;
			cout<<setw(10)<<tenthietbi<<setw(10)<<tinhtrang;
		}
		int get_masp(){
			return masp;
		}
		void timkiemsp(){
			qlythietbi tb[100];
			int ma,n;
			int count=0;
			cout<<"\nNhap ma san pham can tim: ";cin>>ma;
			for(int i=0;i<n;i++){
				if(tb[i].get_masp()==ma){
					tb[i].Output();
					count++;
				}
			}
			if(count==0){
				cout<<"\nKhong tim thay ma san pham can tim";
			}
		}
		void qlthietbi(){
			int luachon;
			do{
				system("cls");
			cout<<" \tQuan Ly Thiet Bi Phong Gym\t"<<endl;
			cout<<" ******1.Nhap thiet bi******"<<endl;
			cout<<" ******2.Xuat thiet bi******"<<endl;
			cout<<" ******3.Tim kiem theo ma san pham******"<<endl;
			cout<<" ******4.Exit******"<<endl;
			cout<<"\tNhap lua chon cua ban: ";cin>>luachon;
			switch(luachon){
				case 1:
					Input();
					cout<<endl;
					system("pause");
					break;
				case 2:
					Output();
					cout<<endl;
					system("pause");
					break;
				case 3:
					timkiemsp();
					cout<<endl;
					system("pause");
					break;
				case 4:
					exit(0);
					break;					
			default:
				cout<<"Khong co du lieu ban nhap!";
				break;
			}
			}while(luachon!=0);
		}
};
// xay dung class chinh
class quanlyGym:public khachhang,goitap,qlythietbi{ //ke thua du lieu
	public:
		khachhang kh; goitap gt; //goi du lieu class ben tren xuong
		void nhap(){
			kh.input(); //goi phuong thuc nhap xuat class khachhang
			gt.input();
		}
		void xuat(){ //goi phuong thuc nhap xuat class goitap
		
			kh.output();
			gt.output();
		}
};
//nhap n khachhang dang ky goi tap
void nhapds(quanlyGym gym[], int n){
	int res=0;
	khachhang kh;
	for(int i=0;i<n;i++){
		do{
			res=0;//reset lai du lieu, ko co no du nhap # 1000 lan cung ko dc
			cout<<" \nKhach hang thu: "<<i+1<<"";
		    gym[i].nhap();
		    for(int j=0;j<i;j++){
		    	if(gym[j].kh.get_makh() == gym[i].kh.get_makh()){ // Kiem tra xem 2 ma khach hang co trung nhau khong
		    		cout<<"\n***Ma khach hang ko duoc trung nhau, Moi ban nhap lai!"<<endl; //neu trung thi nhap lai
		    		res++;
				}
			}
		}while(res!=0);	
	}
}
//xuat n khachhang dang ky goi tap
void xuatds(quanlyGym gym[], int n){
	cout<<"\nMaKH"<<setw(9)<<"TenKH"<<setw(11)<<"NgaySinh"<<setw(13)<<"QueQuan"<<setw(10)<<"SDT"<<setw(10);
	cout<<"Goidky"<<setw(10)<<"Ngaydky"<<setw(10)<<"Handky"<<setw(10);
	cout<<"Phigoitap"<<setw(10)<<"Phidichvu"<<setw(10)<<"Tongtien"<<setw(10);
	for(int i=0;i<n;i++){
		gym[i].xuat();
	}
}
// sap xep tong tien tang dan
void sapxep(quanlyGym gym[], int n){
	goitap gt;
	quanlyGym tg;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(gym[i].gt.get_tongtien()>gym[j].gt.get_tongtien())
				tg=gym[i];
				gym[i]=gym[j];
				gym[j]=tg;
		}
	}
	cout<<"\nTong tien tang dan khach hang:"<<endl;
	xuatds(gym,n);
}
//tim kiesm khach h�ng theo m�
void timkiem(quanlyGym gym[], int n){
	int x;
	khachhang kh;
	int count=0;
	//tieu de
	cout<<"\nNhap ma khach hang can tim: ";cin>>x;
	cout<<"\nMaKH"<<setw(9)<<"TenKH"<<setw(11)<<"NgaySinh"<<setw(13)<<"QueQuan"<<setw(10)<<"SDT"<<setw(10);
	cout<<"Goidky"<<setw(10)<<"Ngaydky"<<setw(10)<<"Handky"<<setw(10);
	cout<<"Phigoitap"<<setw(10)<<"Phidichvu"<<setw(10)<<"Tongtien"<<setw(10);
	for(int i=0;i<n;i++){
		if(gym[i].kh.get_makh()==x){//kiem tra ma khach hang co = ma khach hang nguoi dung nhap hay khong
			gym[i].xuat();//= thi xuat ra thong tin co makh()
			count++;
		}
	}
	if(count==0){//# thi xuat ra ben duoi
		cout<<"\nKhong tim thay du lieu ban nhap";
	}
}
//T�m kiem kh�ch h�ng theo t�n
void timkiemten(quanlyGym gym[], int n){
	string ten;
	khachhang kh;
	int count=0;
	//tieu de
	cout<<"\nNhap ten khach hang can tim: ";fflush(stdin);getline(cin,ten);
	cout<<"\nMaKH"<<setw(9)<<"TenKH"<<setw(11)<<"NgaySinh"<<setw(13)<<"QueQuan"<<setw(10)<<"SDT"<<setw(10);
	cout<<"Goidky"<<setw(10)<<"Ngaydky"<<setw(10)<<"Handky"<<setw(10);
	cout<<"Phigoitap"<<setw(10)<<"Phidichvu"<<setw(10)<<"Tongtien"<<setw(10);
	for(int i=0;i<n;i++){
		if(gym[i].kh.get_tenkh()==ten){//kiem tra ten khach hang co = ten nguoi dung nhap khong.
			gym[i].xuat();
			count++;
		}
	}
	if(count==0){
		cout<<"\nKhong tim thay du lieu ban nhap";
	}
}
//Tim kh�ch h�ng c� chi ph� cao nhat
void tongtienMax(quanlyGym gym[], int n){
	int max=0;
	goitap gt;
	for(int i=0;i<n;i++){
		if(gym[i].gt.get_tongtien()>max){
			max = gym[i].gt.get_tongtien();
		}
	}
	cout<<"\nKhach hang co chi phi cao nhat la:"<<max<<endl;
}
//Sua thong tin nhan vien
void suatt(quanlyGym gym[], int n){
	int sua;
	int count=0;
	khachhang kh; //lấy dư liệu makh lớp khachhang
	cout<<"Nhap ma khach hang can sua: ";cin>>sua;
	for(int i=0;i<n;i++){
		if(gym[i].kh.get_makh()==sua){ //Tim ma khach hang co trung voi du lieu ban nhap khong dể sửa
			gym[i].nhap(); //sua toan bo thong tin, sua tung thuoc tinh chiu kho dung swtich case lam nhu input()
			count++;
		}
	}
	if(count==0){// không trùng xuất ra thông báo bên dưới
		cout<<"Khong tim thay du lieu ban nhap!";
	}
}
//them khach hang, logic makh ko dc trung nhau.
void themkh(quanlyGym gym[], int &n){
	n++;
	int res=0;
	khachhang kh;//goi lop khachhang lay du lieu makh
	do{
		res=0;//reset lai du lieu
		cout<<"\nNhap thong tin sinh vien can them: ";
		gym[n-1].nhap();
		for(int i=0;i<n-1;i++){
			if(gym[i].kh.get_makh()==gym[n-1].kh.get_makh()){//tuong tu ben tren kiem tra makh co trung nhau khong
				cout<<"\nMa khach hang khong duoc trung nhau. Moi ban nhap lai!"<<endl;
				res++; //trung nhau thi nhap lai.
			}
		}
	}while(res!=0);
}
//xoa thong tin khach hang
void xoakh(quanlyGym gym[],int &n){
	int xoa;
	int res=0;
	khachhang kh;
	cout<<"\nNhap ma khach hang can xoa: ";cin>>xoa;
	for(int i=0;i<<n;i++){
		if(gym[i].kh.get_makh()==xoa){ //kiem tra makh co khop voi xoa hay khong
			res++;
			for(int j=i;j<n;j++){
				gym[j] = gym[j+1]; //day phan tu sau len truoc
			}
		}
	}
	if(res==0) //nhap ko dung makh=> ko ton tai
		cout<<"\nMa so khach hang ban nhap khong ton tai!";
	else // xoa di phan tu cuoi cung
		n--;
}

void menu(quanlyGym gym[], int n){
	int choice;
	qlythietbi tb; //lay du lieu ham o class qlythietbi
	do{
		system("cls");
		cout<<"\tCHUONG TRINH QUAN LY PHONG GYM.\t"<<endl;
		cout<<"========================MENU============================\n";
		cout<<"==                                                     ==\n";
		cout<<"==        1.Quan ly khach hang phong gym.              ==\n";
		cout<<"==        2.Xuat danh sach khach hang.                 ==\n";
		cout<<"==        3.Tim kiem theo ma khach hang.               ==\n";
		cout<<"==        4.Tim kiem ten khach hang.                   ==\n";
		cout<<"==        5.Tim khach hang co chi phi cao nhat.        ==\n";
		cout<<"==        6.Quan ly thiet bi phong Gym.                ==\n";
		cout<<"==        7.Sua thong tin khach hang.                  ==\n";
		cout<<"==        8.Xoa thong tin khach hang.                  ==\n";
		cout<<"==        9.Them thong tin khach hang.                 ==\n";
		cout<<"==        10.Sap xap tong tien khach hang tang dan.    ==\n";
		cout<<"==        11.Exit                                      ==\n";
		cout<<"=========================================================\n";
	    cout<<" \t Nhap lua chon cua ban: ";cin>>choice;
	    switch(choice){
	    	case 1:
	    		nhapds(gym,n);
	    		cout<<endl;
	    		system("pause");
	    		break;
	    	case 2:
	    		xuatds(gym,n);
	    		cout<<endl;
	    		system("pause");
	    		break;
	    	case 3:
	    		timkiem(gym,n);
	    		cout<<endl;
	    		system("pause");
	    		break;
	    	case 4:
	    		timkiemten(gym,n);
	    		cout<<endl;
	    		system("pause");
	    		break;	
	    	case 5:
	    		tongtienMax(gym,n);
	    		cout<<endl;
	    		system("pause");
	    		break;
	    	case 6:
	    		tb.qlthietbi();
	    		cout<<endl;
	    		system("pause");
	    		break;
			case 7:
			    suatt(gym,n);
				cout<<endl;
				system("pause");
				break;
			case 8:
	    		xoakh(gym,n);
	    		cout<<endl;
	    		system("pause");
	    		break;		
	    	case 9:
	    		themkh(gym,n);
	    		cout<<endl;
	    		system("pause");
	    		break;
	    	case 10:
	    		sapxep(gym,n);
	    		cout<<endl;
	    		system("pause");
	    		break;
	    	case 11:
	    		exit(0);
	    		break;
	    	default:
	    		cout<<"Khong co du lieu ban nhap!";
	    		break;
	    			
		}
	}while(choice!=0);
}

int main(){
	int n;
	system("color 9");
	cout<<"Nhap so luong khach hang phong GYM: ";cin>>n;
	quanlyGym *gym = new quanlyGym[n]; //mang dong voi con tro
	menu(gym,n);
	getch();
	return 0;
}
