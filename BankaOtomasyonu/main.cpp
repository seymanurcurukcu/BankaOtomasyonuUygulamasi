  #include<iostream>
    #include<string>

    using namespace std;

    class Banka{
        string isim;
        string soyisim;
        int HesapNo;
        string MusteriTipi;
        int Bakiye;
        int Cekilenpara;
        int Yatirilanpara;

        public:
            void HesapBilgileri(string ad,string soyad,int Hesapnumarasi,string MTipi,int bakiye,int eksilenPara,int artanPara);
            void ParaYatirma(int paraYatir);
            void ParaCekme(int paraCek);
            void HesapOzeti();
    };

    void Banka:: HesapBilgileri(string MusteriAdi,string MusteriSoyadi,int MusteriHesapNo,string Musteritipi,int MusteriBakiye,int cekilenpara,int yatirilanpara){
        isim=MusteriAdi;
        soyisim=MusteriSoyadi;
        HesapNo=MusteriHesapNo;
        MusteriTipi=Musteritipi;
        Bakiye=MusteriBakiye;
        Cekilenpara=cekilenpara;
        Yatirilanpara=yatirilanpara;
    }

    void Banka::ParaYatirma(int paraYatir){
    	Yatirilanpara=paraYatir;
        Bakiye+=paraYatir;
    }

    void Banka::ParaCekme(int paraCek){
        if(paraCek>Bakiye){
            cout<<"\nUzgunuz.. Yeterli bakiye yok..";
        }
        else{
        	Cekilenpara=paraCek;
            Bakiye-=paraCek;
            cout<<"\nIsleminiz basarili bir sekilde gerceklesmistir.... ";
        }
    }

    void Banka:: HesapOzeti(){
    	
    	cout<<"\n----------------------------------------- ";
        cout<<"\n********** Hesap Ozeti ************";
        cout<<"\n---------------------------------------";
        cout<<"\n Ad :  "<<isim<<endl;
        cout<<" Soyadi :  "<<soyisim<<endl;
        cout<<" Hesap Numarasi : "<<HesapNo<<endl;
        cout<<" Hesap Turu: "<<MusteriTipi<<endl;
        cout<<" Bakiye : "<<Bakiye<<endl;
        cout<<" Hesaptan cekilen para miktari : "<<Cekilenpara<<endl;
        cout<<" Hesaba yatirilan para miktari : "<<Yatirilanpara<<endl;
    }

    int main()
    {
        int i,n;
        int secim,x,y,paracek,parayatir;
        string ad,hesapTuru,soyad,FaturaAdi;
        cout<<"\n----------------------------------------- ";
        cout<<"\n********** Banka Hesap Acma************";
        cout<<"\n---------------------------------------";
        cout<<" \nKayit yapilacaginiz musteri sayisini giriniz..";
        cin>>n;
        Banka musteri[n];
        cout<<"\n Musteri Bilgilerini giriniz. ";
        for(i=0;i<n;i++){
        	cout<<"\n========================================== ";
            cout<<"\nMusteri : "<<i+1<<endl;
            cout<<"Adi Girin:";
            cin>>ad;
            cout<<"Soyadini Girin:";
            cin>>soyad;
            cout<<"Hesap turunu girin (Bireysel/Kurumsal):";
            cin>>hesapTuru;
            cout<<"**Hesap Numaraniz:"<<i+1<<endl;
           cout<<"\n========================================== ";
            musteri[i].HesapBilgileri(ad,soyad,i+1,hesapTuru,0,0,0);
        }

        cout<<"\n--------------------------------------------------------- ";
        cout<<"\n********** Banka Bilgi Merkezine Hos Geldiniz************";
         cout<<"\n--------------------------------------------------------- ";
        cout<<"\n Secim : \n 1) Hesap Ozeti. \n 2) Para Yatirma. \n 3) Para Cekme.\n 4) Havale Islemi.\n 5) Odeme Yapma. \n 6) Cikis ";
        while(1){
            cout<<"\n\nSeciminizi giriniz..";
            cin>>secim;
            if(secim==1){
                cout<<"\nHesap Numaranizi Girin.. ";
                cin>>x;
                musteri[x-1].HesapOzeti();
            }
            else if(secim==2){
                cout<<"\n----------------------------------------- ";
                cout<<"\n********** Para Yatirma************";
                cout<<"\n---------------------------------------";
                cout<<"\nHesap Numaranizi giriniz..";
                cin>>x;
                cout<<"\nYatirmak istediginiz para miktarini giriniz..";
                cin>>parayatir;
                musteri[x-1].ParaYatirma(parayatir);
                cout<<"\n Para yatirma isleminiz basarili.... ";
                cout<<"\n---------------------------------------";
            }
            else if(secim==3){
            	 cout<<"\n----------------------------------------- ";
                cout<<"\n********** Para Cekme************";
                cout<<"\n---------------------------------------";
                cout<<"\nHesap Numaranizi giriniz..";
                cin>>x;
                cout<<"\nCekmek istediginiz para miktarini giriniz..";
                cin>>paracek;
                musteri[x-1].ParaCekme(paracek);
                cout<<"\n---------------------------------------";
            }
             else if(secim==4){
            	cout<<"\n----------------------------------------- ";
                cout<<"\n********** Havale Islemi************";
                cout<<"\n---------------------------------------";
                cout<<"\nHesap Numaranizi giriniz..";
                cin>>x;
                cout<<"\nHavale yapacaginiz hesabin hesap numarasini giriniz..";
                cin>>y;
                cout<<"\n Havale yapilacak tutari giriniz..";
                cin>>paracek;
                musteri[x-1].ParaCekme(paracek);
                musteri[y-1].ParaYatirma(paracek);
                cout<<"\n---------------------------------------";
            }
             else if(secim==5){
            	cout<<"\n----------------------------------------- ";
                cout<<"\n********** Odeme Yapma************";
                cout<<"\n---------------------------------------";
                cout<<"\nHesap Numaranizi giriniz..";
                cin>>x;
                cout<<"\nFatura Adini giriniz..";
                cin>>FaturaAdi;
                cout<<"\n Fatura Tutarini giriniz..";
                cin>>paracek;
                musteri[x-1].ParaCekme(paracek);
                cout<<"\n---------------------------------------";
            }
            else{
                break;
            }
        }
        return 0;
    }
