/**
* @file konsol.h
* @description Konsol işlemlerini gerçekleştiren metotları barındırır. Bunlar imlecin konumunu, rengini değiştirmek
 * gibi işlevler olabilir.
* @course 2A
* @assignment 2
* @date 7.10.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

#ifndef KONSOL_H
#define KONSOL_H

#include <windows.h>

class Konsol {
private:
    static HANDLE konsol;
public:
    /**
     * Konsol genişliğinin kaç karakter boyutunda olduğunu belirler.
     * @return Karakter sayısını döndürür.
     */
    static short alKonsolGenisligi();

    /**
     * İmleci konsol penceresinde gösterilmesini veya gizlenmesini sağlar.
     * @param gorunur İmlecin gösterilip gösterilmeyeceğini belirtir.
     */
    static void imleciGoster(bool gorunur = true);

    static bool imlecGorunurMu();

    /**
     * İmleci verilen konuma taşır.
     * @param x İmlecin yataydaki konumu.
     * @param y İmlecin dikeydeki konumu.
     */
    static void imleciTasi(short x, short y);

    static short alImlecX();

    static short alImlecY();

    static bool alYaziRengi(short &renk);

    /**
     * Konsolun metin rengini ayarlamaya yarar.
     * @param renk Atanacak olan rengin tam sayı kodu. (Varsayılan = 7, gri renk)
     */
    static void yaziRengi(int renk = 7);

    /**
     * Konsolun metin rengini değiştirir ve parametre ile gelen metni yazdırır. Yazdırma işlemi bittikten sonra
     * konsolun metin rengi baştaki haline döndürülür.
     * @param yazi Renkli olarak yazdırılacak metin.
     * @param renk Metnin yazdırılacağı rengin kodu.
     */
    static void renkliYazdir(const char *yazi, int renk);

    /**
     * İmlecin şu anki yatay pozisyonundan satır sonuna kadar aynı karakteri basar.
     * @param karakter Basılacak olan karakter.
     * @param x [OPSİYONEL] Başlangıçtaki yatay konum. Eğer verilmezse o anki konumdan başlar.
     * @param y [OPSİYONEL] Gidilecek olan dikey konum. Eğer verilmezse o anki konum kabul edilir.
     * @param geriyeDon [OPSİYONEL] Satır doldurulduktan sonra tekrar başlangıç pozisyonuna dönülsün mü?
     * @param uzunluk [OPSİYONEL] Kaç adet karakter basılacağını belirtir. Varsayılan değerinde bırakılırsa satır sonuna
     * kadar basılır.
     */
    static void satiriDoldur(char karakter, short x = -1, short y = -1, bool geriyeDon = true, short uzunluk = -1);

    /**
     * Mevcut konumdan başlayarak sola doğru karakter siler.
     */
    static void sil();
};

#endif