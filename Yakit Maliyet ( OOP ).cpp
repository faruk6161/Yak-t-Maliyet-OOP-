//////////////////////////////////////////////////////
//    			     								//
//                Coded by Faruk OKSUZ				//
//                        2019      				//
//    			     								//
//////////////////////////////////////////////////////	
#include <iostream>
using namespace std;

class yktMaliyet
{
private:
    double kmBasinaYakit; // ml cinsinden
    double abArasiMesafe; // km cinsinden

public:
    yktMaliyet();               //parametresiz constructor
    yktMaliyet(double kmYakit); // tek parametreli yapıcı

    double getKmBasinaYakit(); //KmBasinaYakit geriye dondur
    double getabArasiMesafe(); //abArasiMesafe geriye dondur

    void setKmBasinaYakit(int kmYakit);  //KmBasinaYakit degisikligi icin
    void setAbArasiMesafe(int abMesafe); // AbArasiMesafe degiskligi icin

    friend double yktHesapla(yktMaliyet yakitMaliyet); //maliyet hesaplamak icin " friend function"

    yktMaliyet operator+(yktMaliyet const &obj); //operator overloading ->nesne toplami
    yktMaliyet operator=(yktMaliyet const &obj); //operator overloading -> nesne atama

    ~yktMaliyet() {} //destructor
};

yktMaliyet::yktMaliyet()
{ //parametresiz constructor
    cout << "Ruzgara karsi hareket etmek icin 1 ' e "
         << "Ruzgar yonunde hareket etmek icin 0 'a basiniz ?" << endl;
    int yon;
    abArasiMesafe = 100;
    cin >> yon;
    if (yon == 1){
        kmBasinaYakit = (80 * 115) / 100;
    }
    else if (yon == 0){
        kmBasinaYakit = (80 * 90) / 100;
    }
    else{
        cout << "Yanlis secim !!" << endl;
    }
}
yktMaliyet::yktMaliyet(double kmYakit)
{ // tek parametreli constructor
    cout << "Ruzgara karsi hareket etmek icin 1 ' e "
         << "Ruzgar yonunde hareket etmek icin 0 'a basiniz ?" << endl;
    int yon;
    abArasiMesafe = 100;
    cin >> yon;
    if (yon == 1){
        this->kmBasinaYakit = (kmYakit * 115) / 100;
    }
    else if (yon == 0){
        this->kmBasinaYakit = (kmYakit * 90) / 100;
    }
    else{
        cout << "Yanlis secim !!" << endl;
    }
}
double yktMaliyet::getKmBasinaYakit()
{ //get methodKmBasinaYakit
    return this->kmBasinaYakit;
}
double yktMaliyet::getabArasiMesafe()
{ //get method abArasiMesafe
    return this->abArasiMesafe;
}
void yktMaliyet::setKmBasinaYakit(int kmYakit)
{ //set method km basina yakit
    this->kmBasinaYakit = kmYakit;
}
void yktMaliyet::setAbArasiMesafe(int abMesafe)
{ //set method ab mesafe
    this->abArasiMesafe = abMesafe;
}
double yktHesapla(yktMaliyet yakitMaliyet)
{ //friend fonksiyon
    return (yakitMaliyet.getKmBasinaYakit() / 1000) * yakitMaliyet.getabArasiMesafe();
}
yktMaliyet yktMaliyet::operator+(yktMaliyet const &obj)
{ //nesne toplamı
    yktMaliyet nesne;
    nesne.kmBasinaYakit = kmBasinaYakit + obj.kmBasinaYakit;
    nesne.abArasiMesafe = abArasiMesafe + obj.abArasiMesafe;
    return nesne;
}
yktMaliyet yktMaliyet::operator=(yktMaliyet const &obj)
{ //nesne atama
    yktMaliyet nesne;
    nesne.kmBasinaYakit = obj.kmBasinaYakit;
    nesne.abArasiMesafe = obj.abArasiMesafe;
    return nesne;
}
int main()
{
    yktMaliyet gidis(98);
    gidis.setAbArasiMesafe(450);
    //gidis.setKmBasinaYakit(457);

    cout << "Bu yolculugun size maliyeti : " << yktHesapla(gidis) << " TL " << endl;

    /* 
    yktMaliyet gidis( 98 );
    yktMaliyet donus = gidis;
    yktMaliyet toplam = gidis + donus;
    */

    return 0;
}
