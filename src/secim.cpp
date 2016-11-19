#include "secim.h"

int Secim::yonTuslariSecimi(int secenek, int secenekSayisi, char geriye, char ileriye, char onay) {
    int fark = 0;
    char secim = (char) _getch();

    if (secim == geriye) { // Yukarı ok tuşu
        if (secenek > 0)
            fark = -1;
    } else if (secim == ileriye) { // Aşağı ok tuşu
        if (secenek < secenekSayisi - 1)
            fark = 1;
    } else if (secim == onay) // CR karakteri, Enter tuşunu yakalamak için.
        fark = 2;

    return fark;
}

void Secim::dikeySecim(std::string *secenekler, int secenekSayisi, int &secenek) {
    int imlecY = Konsol::alImlecY() - (secenekSayisi - secenek - 1);
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
        if (fark == 2) break;
        if (fark == 0) continue;
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

bool Secim::onayMenusu() {
    string secenekler[] = {"Evet", "Hayir"};
    int secenek = 0;
    dikeySecim(secenekler, 2, secenek);
    return secenek == 0;
}
