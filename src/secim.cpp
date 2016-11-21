/**
* @file secim.cpp
* @description Açıklama ilgili başlık dosyasında yapılmıştır.
* @course 2A
* @assignment 2
* @date 19.11.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

#include "secim.h"

short Secim::yonTuslariSecimi(int secenek, int secenekSayisi, char geriye, char ileriye, char onay) {
    short fark = 0;
    char secim = (char) _getch();

    if (secim == geriye) {
        if (secenek > 0)
            fark = -1;
    } else if (secim == ileriye) {
        if (secenek < secenekSayisi - 1)
            fark = 1;
    } else if (secim == onay)
        fark = 2;

    return fark;
}

void Secim::dikeySecim(std::string *secenekler, short secenekSayisi, int &secenek) {
    short imlecY = Konsol::alImlecY() - (short) (secenekSayisi - secenek - 1);
    int fark = 0;
    secenek = 0;

    Konsol::imleciTasi(0, imlecY);
    for (int i = 0; i < secenekSayisi; i++) {
        if (i == secenek) {
            Konsol::yaziRengi(15);
            cout << "> " << secenekler[i];
            Konsol::yaziRengi();
        } else
            cout << "  " << secenekler[i];
        if (i < secenekSayisi - 1) cout << endl;
    }

    Konsol::imleciTasi(0, imlecY);
    do { // Seçim döngüsü
        fark = yonTuslariSecimi(secenek, secenekSayisi);
        if (fark == 2) break; // Onay karakteri basılmışsa döngü sonlandırılır.
        if (fark == 0) continue; // Eğer sınırlara ulaşılmış ve fark 0'a eşit olmuşsa döngü adımı sonlandırılır.
        secenek += fark;

//        İmleci bir önceki seçeneğin başına taşır, satırı boş karakter ile doldurur ve tekrar satır başına alır.
        Konsol::satiriDoldur(' ', 0, imlecY, true);
//        Yazma rengi varsayılan olarak ayarlanır.
        Konsol::yaziRengi();
//        Önceki seçenek işaret karakteri, '>' olmadan ve varsayılan renkte tekrar yazdırılır.
        cout << "  " << secenekler[secenek - fark];

//        İmleç konumu olarak sonraki, yeni seçeneğin konumu alınır.
        imlecY += fark;
        Konsol::satiriDoldur(' ', 0, imlecY, true);
//        Yazma rengini beyaz olarak ayarla, aktif seçenek görünümü için.
        Konsol::yaziRengi(15);
//        Mevcut seçenek işaret karakteri, '>' ile yazdırılır.
        cout << "> " << secenekler[secenek];
//        Yazma rengi tekrardan varsayılan renge ayarlanır.
        Konsol::yaziRengi();
    } while (true); // Seçim döngüsü sonu
}

bool Secim::onayMenusu(bool imleciGizle) {
    bool imleciTersle = Konsol::imlecGorunurMu() == imleciGizle;

//    Eğer imlecin mevcut görünürlük durumu ile parametre değeri eşleşmezse görünürlük durumu terslenir.
    if (imleciTersle) Konsol::imleciGoster(!imleciGizle);
    string secenekler[] = {"Evet", "Hayir"};
    int secenek = 0;
    dikeySecim(secenekler, 2, secenek);

//    Eğer başlangıçta imlecin görünürlük durumu terslenmişse tekrar eski haline döndürülür.
    if (imleciTersle) Konsol::imleciGoster(imleciGizle);

    return secenek == 0;
}
