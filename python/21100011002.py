# 21100011002 / Muhammed Furkan Akyol
# 486. SATIRDA IC ICE FONKSIYON VARDIR
import os
import time
sira = 1
per_sira = 1
aday_list = ["Adi", "Soyadi", "Meslegi", "Yasi", "Tecrube", "Diploma Notu", "Mulakat Notu", "ID'si"]
aday_list_2 = ["Adi", "Soyadi", "Meslegi\n        (Makine, Bilgisayar, Elektrik ve Elektronik, Mekatronik, Endüstri)", "Yasi", "Tecrube", "Diploma Notu (X.XX)", "Mulakat Notu", "ID'si"]
aday_list_boyut = [20, 10, 25, 4, 7, 12, 20, 8]
personel_list = ["Adi", "Soyadi", "Meslegi", "Yasi", "Tecrube", "Diploma Notu", "Gecmis Mulakat Notu", "ID'si", "Maasi"]
meslek_adlari = ["Makine", "Bilgisayar", "Elektrik ve Elektronik", "Mekatronik", "Endüstri"]
puan_dict = [{25: 20, 30: 15, 35: 10, 40: 5}, {1: 15, 3: 20, 5: 25, -1: 30}, {3: 5, 3.3: 10, 3.7: 15, 4: 20}, {65: 15, 80: 20, 90: 25, 100: 30}]
meslek_degiskeni = {"Bilgisayar": 1.40, "Makine": 1.15, "Elektrik ve Elektronik": 1.20, "Mekatronik": 1.30, "Endüstri": 1.10}
Maas = 7000


def giris():  # ILK EKRAN
    print("""
        [][][][][][][][][][][][][][][][][][]
        []          GIRIS EKRANI          []
        [][][][][][][][][][][][][][][][][][]""")
    kullanici_adi = input("\n        Kullanici Adi = ")
    sifre = input("                Sifre = ")
    with open("21100011002_2.txt", "r", encoding="utf-8") as dosya:
        degisken = dosya.readline()
        if kullanici_adi == degisken.split("/")[1] and sifre + "\n" == degisken.split("/")[2]:
            os.system("cls")
            loading()
            menu()
        else:
            print("\n\n        Hatali Giris Yaptiniz. Kapatiliyor...")
            time.sleep(2)


def aday_ekle():
    os.system("cls")
    print("""
        [][][][][][][][][][][][][][][][][][]
        []          ADAY  EKLEME          []
        [][][][][][][][][][][][][][][][][][]""", end="\n")
    string_1 = ""
    for i in range(len(aday_list) - 1):  # ADAY BILGILERINI ALIYOR
        degisken = input("\n        Adayin {} -> ".format(aday_list_2[i]))
        string_1 += (degisken + " " * (aday_list_boyut[i] - len(degisken))) + "#"
    with open("21100011002_2.txt", "a+", encoding="utf-8") as dosya_1:  # KULLANICIYA AIT ID DOSYADAN CEKILIYOR
        dosya_1.seek(0)
        degisken_1 = dosya_1.readlines()
        string_1 += degisken_1[0].split("/")[0] + "\n"
        degisken_2 = int(degisken_1[0].split("/")[0]) + 1
        degisken_1[0] = str(degisken_2) + "/" + degisken_1[0].split("/")[1] + "/" + degisken_1[0].split("/")[2]
        dosya_1.truncate(0)
        dosya_1.writelines(degisken_1)
    while True:
        cevap = input("\n        Kabul Ediyor Musunuz (e/h) -> ")
        if cevap == "E" or cevap == "e":
            with open("21100011002_1.txt", "a", encoding="utf-8") as dosya:
                dosya.write(string_1)
            break
        elif cevap == "H" or cevap == "h":
            print("        Kayit Yapilmamistir Menuye Yonlendiriliyorsunuz...")
            time.sleep(2)
            break
        else:
            print("        Lutfen Gecerli Bir Cevap Seciniz...")
            time.sleep(2)


def aday_listele():
    os.system("cls")
    with open("21100011002_1.txt", "r", encoding="utf-8") as dosya_k:
        # EGER ADAY VEYA PERSONEL LISTEDE OLMAZSA PROGRAM TAKILI KALMAMASI ICIN HER FONKSIYON ICINE KOYDUM
        kontrol_degiskeni = dosya_k.readlines()
        if len(kontrol_degiskeni) == 0:
            print("""
        [][][][][][][][][][][][][][][][][][]
        []        Aday Bulunamadi.        []
        [][][][][][][][][][][][][][][][][][]""")
            time.sleep(2)
            exit(menu())
    global sira
    for i in range(len(aday_list)):  # TABLONUN BELİRTME KISMI
        if i == 0:
            print("|XX|", aday_list[i], " " * (aday_list_boyut[i] - len(aday_list[i])), sep="", end="")
        else:
            print("||", aday_list[i], " " * (aday_list_boyut[i] - len(aday_list[i])), sep="", end="")
    print("\n", "=" * (16 + sum(aday_list_boyut)), sep="")
    with open("21100011002_1.txt", "r", encoding="utf-8") as dosya:  # TABLODAKI VERILERIN YAZDIRILDIGI KISIM
        sira = 1
        for i in dosya:
            degisken = 0
            for j in i.split("#"):
                if degisken == 0:
                    print("|{:2}|".format(sira), j, sep="", end="")
                    sira += 1
                    degisken += 1
                else:
                    print("||", j, sep="", end="")
    input("\n\n\n        (Devam Etmek Icin Enter'a Basiniz...)")


def aday_silme():
    os.system("cls")
    with open("21100011002_1.txt", "r", encoding="utf-8") as dosya_k:
        kontrol_degiskeni = dosya_k.readlines()
        if len(kontrol_degiskeni) == 0:
            print("""
        [][][][][][][][][][][][][][][][][][]
        []        Aday Bulunamadi.        []
        [][][][][][][][][][][][][][][][][][]""")
            time.sleep(2)
            exit(menu())
    aday_listele()  # SILINECEK KISIYI GORMESI ICIN CAGIRTIYORUM
    degisken = 0
    print("""
    [][][][][][][][][][][][][][][][][][]
    []           ADAY SILME           []
    [][][][][][][][][][][][][][][][][][]""")
    while True:

        try:
            degisken_2 = int(input("\n        Aday Sira No Giriniz (exit = -1)-> "))
            if degisken_2 == -1:
                degisken = -1
                break
            if 0 < degisken_2 < sira:
                break
            print("        Lutfen Gecerli Bir Sira No Giriniz...")
        except ValueError:
            print("        Lutfen Gecerli Bir Sira No Giriniz...")
    if degisken == 0:
        with open("21100011002_1.txt", "a+", encoding="utf-8") as dosya:
            dosya.seek(0)
            degisken_1 = dosya.readlines()
            degisken_1.pop(degisken_2 - 1)
            dosya.truncate(0)
            dosya.writelines(degisken_1)
            print("        Kayit Silinmistir. Menuye Yonlendiriliyorsunuz...")
            time.sleep(2)
    else:
        print("        Menuye Yonlendiriliyorsunuz...")
        time.sleep(2)


def aday_guncelleme():
    os.system("cls")
    with open("21100011002_1.txt", "r", encoding="utf-8") as dosya_k:
        kontrol_degiskeni = dosya_k.readlines()
        if len(kontrol_degiskeni) == 0:
            print("""
        [][][][][][][][][][][][][][][][][][]
        []        Aday Bulunamadi.        []
        [][][][][][][][][][][][][][][][][][]""")
            time.sleep(2)
            exit(menu())
    aday_listele()
    exit_1 = 1
    while True:
        print("""
        [][][][][][][][][][][][][][][][][][]
        []        ADAY  GUNCELLEME        []
        [][][][][][][][][][][][][][][][][][]""")
        try:
            degisken_2 = int(input("\n        Aday Sira No Giriniz (exit = -1) -> "))
            if 0 < degisken_2 < sira:
                break
            if degisken_2 == -1:
                print("        Menuye Yonlendiriliyorsunuz...")
                time.sleep(2)
                exit_1 = 0
                break
            print("        Lutfen Gecerli Bir Sira No Giriniz...")
        except ValueError:
            print("        Lutfen Gecerli Bir Sira No Giriniz...")
    if exit_1 == 1:
        os.system("cls")
        with open("21100011002_1.txt", "a+", encoding="utf-8") as dosya:
            dosya.seek(0)
            degisken_1 = dosya.readlines()
            print("\n\n")
            for i in range(len(aday_list)):
                print("        Adayin {} = {}".format(aday_list[i], ((degisken_1[degisken_2 - 1]).split("#"))[i]))
            string_1 = ""
            for i in range(len(aday_list) - 1):
                degisken = input("        Adayin Yeni {} ->".format(aday_list[i]))
                string_1 += (degisken + " " * (aday_list_boyut[i] - len(degisken))) + "#"
            cevap = input("\n        Kabul Ediyor Musunuz (e/h) -> ")
            if cevap == "E" or cevap == "e":
                string_1 += ((degisken_1[degisken_2 - 1]).split("#"))[-1]
                degisken_1[degisken_2 - 1] = string_1
                dosya.truncate(0)
                dosya.writelines(degisken_1)
            elif cevap == "H" or cevap == "h":
                print("        Degisiklik Yapilmamistir Menuye Yonlendiriliyorsunuz...")
                time.sleep(2)
            else:
                print("        Lutfen Gecerli Bir Cevap Seciniz...")
                time.sleep(2)


def personel_bulma():
    os.system("cls")
    with open("21100011002_2.txt", "r", encoding="utf-8") as dosya_k:
        kontrol_degiskeni = dosya_k.readlines()
        if len(kontrol_degiskeni) < 2:
            print("""
        [][][][][][][][][][][][][][][][][][]
        []      Personel Bulunamadi.      []
        [][][][][][][][][][][][][][][][][][]""")
            time.sleep(2)
            exit(menu())
    while True:
        a = 0
        break_degiskeni = 0
        soru = input("""
        [][][][][][][][][][][][][][][][][][]
        []         PERSONEL BULMA         []
        [][][][][][][][][][][][][][][][][][]
        []                                []
        []  1 - ID ile arama              []
        []  2 - Meslek adi ile adama      []
        []  3 - exit                      []
        []                                []
        [][][][][][][][][][][][][][][][][][]
           
           -> """)
        if soru == "1":
            while True:
                os.system("cls")
                degisken = input("\n\n        Personel ID Giriniz (exit = X) -> ")
                if degisken == "X":
                    print("        Menuye Yonlendiriliyorsunuz...")
                    time.sleep(2)
                    break_degiskeni = 1
                    break
                with open("21100011002_2.txt", "r+", encoding="utf-8") as dosya:
                    for i in dosya:
                        if len(i.split("#")) < 4:
                            continue
                        if i.split("#")[-2].strip(" ") == degisken:
                            print("\n\n")
                            for j in range(len(personel_list)):
                                print("        Personel {} = {}".format(personel_list[j], i.split("#")[j]))
                                a = 1
                    if a == 1:
                        input("\n\n\n        (Devam Etmek Icin Enter'a Basiniz...)")
                        break
                print("        Lutfen Gecerli Bir ID Seciniz...")
                time.sleep(2)
        elif soru == "2":
            while True:
                os.system("cls")
                degisken = input("        Meslek Adi Giriniz (exit = X) -> ")
                if degisken == "X":
                    print("        Menuye Yonlendiriliyorsunuz...")
                    time.sleep(2)
                    break_degiskeni = 1
                    break
                with open("21100011002_2.txt", "r+", encoding="utf-8") as dosya:
                    for i in dosya:
                        if degisken in i:
                            for j in range(len(personel_list)):
                                print("        Personel {} = {}".format(personel_list[j], i.split("#")[j]))
                                a = 1
                            print("\n")
                    if a == 1:
                        input("\n\n\n        (Devam Etmek Icin Enter'a Basiniz...)")
                        os.system("cls")
                        break
                    print("        Lutfen Gecerli Bir Meslek Seciniz...")
                    time.sleep(2)
        elif soru == "3":
            print("        Menuye Yonlendiriliyorsunuz...")
            time.sleep(2)
            break
        else:
            print("        Lutfen Gecerli Bir Cevap Seciniz...")
            time.sleep(2)
        if break_degiskeni == 1:
            break
        os.system("cls")


def personel_zam_yapma():
    os.system("cls")
    with open("21100011002_2.txt", "r", encoding="utf-8") as dosya_k:
        kontrol_degiskeni = dosya_k.readlines()
        if len(kontrol_degiskeni) < 2:
            print("""
        [][][][][][][][][][][][][][][][][][]
        []      Personel Bulunamadi.      []
        [][][][][][][][][][][][][][][][][][]""")
            time.sleep(2)
            exit(menu())
    break_degisken = 0
    while True:
        os.system("cls")
        print("""
        [][][][][][][][][][][][][][][][][][]
        []       PERSONEL ZAM YAPMA       []
        [][][][][][][][][][][][][][][][][][]""")
        degisken = input("\n        Personel ID Giriniz (exit = X) -> ")
        if degisken == "X":
            print("        Menuye Yonlendiriliyorsunuz...")
            time.sleep(2)
            break
        with open("21100011002_2.txt", "a+", encoding="utf-8") as dosya:
            dosya.seek(0)
            degisken_1 = dosya.readlines()
            for i in degisken_1:
                if len(i.split("#")) < 3:
                    continue
                if i.split("#")[-2].strip(" ") == degisken:
                    while True:
                        try:
                            zam_orani = int(input("        Zam orani giriniz -> %"))
                            degisken_2 = i.split("#")
                            degisken_2[-1] = str(float(degisken_1[degisken_1.index(i)].split("#")[-1].rstrip("\n").strip(" ")) * (1.0 + (zam_orani / 100))) + "\n"
                            # UST SATIRDA ZAM YAPILACAK ERSONELIN ONCE MAAS BOLUMUNE ERISIYORUM ARDINDAN DA MAASINI ISTENILEN ORANDA ARTTIRIP STR DEGERLE ESKI MAAS KISMINA ESITLIYORUM
                            degisken_3 = ""
                            for j in degisken_2:
                                degisken_3 += j + "#"
                            degisken_3 = degisken_3[:-1]  # SON "#" IFADESINI ALMAMASI ICIN
                            degisken_1[degisken_1.index(i)] = degisken_3  # MAASI ARTTIRILAN ELEMAN DEGISTIRILIYOR
                            dosya.truncate(0)
                            dosya.writelines(degisken_1)
                            break_degisken = 1
                            break
                        except ValueError:
                            print("        Lutfen Sayi Giriniz...")
                            time.sleep(2)
        if break_degisken == 1:
            break
        print("        Lutfen Gecerli Bir ID Giriniz...")
        time.sleep(2)


def personel_guncelleme():
    os.system("cls")
    with open("21100011002_2.txt", "r", encoding="utf-8") as dosya_k:
        kontrol_degiskeni = dosya_k.readlines()
        if len(kontrol_degiskeni) < 2:
            print("""
        [][][][][][][][][][][][][][][][][][]
        []      Personel Bulunamadi.      []
        [][][][][][][][][][][][][][][][][][]""")
            time.sleep(2)
            exit(menu())
    degisken_3 = 0
    while True:
        print("""
        [][][][][][][][][][][][][][][][][][]
        []      PERSONEL  GUNCELLEME      []
        [][][][][][][][][][][][][][][][][][]""")
        degisken = input("\n        Personel ID Giriniz (exit = X) -> ")
        if degisken == "X":
            print("        Menuye Yonlendiriliyorsunuz...")
            time.sleep(2)
            break
        with open("21100011002_2.txt", "a+", encoding="utf-8") as dosya:
            dosya.seek(0)
            degisken_1 = dosya.readlines()
            degisken_2 = 0
            for i in degisken_1:
                if degisken_2 == 0:
                    degisken_2 += 1
                    continue
                if i.split("#")[-2].strip(" ") == degisken:
                    for j in range(len(personel_list)):
                        print("        Personel {} = {}".format(personel_list[j], i.split("#")[j]))
                    print("\n\n")
                    bos_str = ""
                    for j in range(5):
                        degisken_3 = input("        Personel Yeni {} = ".format(personel_list[j])) + " "
                        bos_str += degisken_3 + " " * (aday_list_boyut[j] - len(degisken_3)) + "#"
                    for j in range(5, 9):
                        bos_str += i.split("#")[j] + "#"
                    bos_str = bos_str[:-1]
                    degisken_1[degisken_1.index(i)] = bos_str
                    dosya.truncate(0)
                    dosya.writelines(degisken_1)
                    degisken_3 = 1
                    break
        if degisken_3 == 1:
            break
        print("        Lutfen Gecerli Bir ID Seciniz...")
        time.sleep(2)


def personel_silme():
    os.system("cls")
    with open("21100011002_2.txt", "r", encoding="utf-8") as dosya_k:
        kontrol_degiskeni = dosya_k.readlines()
        if len(kontrol_degiskeni) < 2:
            print("""
        [][][][][][][][][][][][][][][][][][]
        []      Personel Bulunamadi.      []
        [][][][][][][][][][][][][][][][][][]""")
            time.sleep(2)
            exit(menu())

    degisken_3 = 0
    while True:
        print("""
        [][][][][][][][][][][][][][][][][][]
        []         PERSONEL SILME         []
        [][][][][][][][][][][][][][][][][][]""")
        degisken = input("\n        Personel ID Giriniz (exit = X) -> ")
        if degisken == "X":
            print("        Menuye Yonlendiriliyorsunuz...")
            time.sleep(2)
            break
        with open("21100011002_2.txt", "a+", encoding="utf-8") as dosya:
            dosya.seek(0)
            degisken_1 = dosya.readlines()
            degisken_2 = 0
            for i in degisken_1:
                if degisken_2 == 0:
                    degisken_2 += 1
                    continue
                if i.split("#")[-2].strip(" ") == degisken:
                    degisken_1.remove(i)
                    dosya.truncate(0)
                    dosya.writelines(degisken_1)
                    print("        Kayit Silinmistir. Menuye Yonlendiriliyorsunuz...")
                    time.sleep(2)
                    degisken_3 = 1
        if degisken_3 == 1:
            break
        print("        Lutfen Gecerli Bir ID Seciniz...")
        time.sleep(2)


def personel_ekleme():
    os.system("cls")
    with open("21100011002_1.txt", "r", encoding="utf-8") as dosya_k:
        kontrol_degiskeni = dosya_k.readlines()
        if len(kontrol_degiskeni) == 0:
            print("""
        [][][][][][][][][][][][][][][][][][]
        []        Aday Bulunamadi.        []
        [][][][][][][][][][][][][][][][][][]""")
            time.sleep(2)
            exit(menu())
    degisken_2 = 0
    while True:
        print("""
        [][][][][][][][][][][][][][][][][][]
        []        PERSONEL  EKLEME        []
        [][][][][][][][][][][][][][][][][][]""")
        a = 0
        degisken_1 = input("\n        (Makine, Bilgisayar, Elektrik ve Elektronik, Mekatronik, Endüstri)\n        Meslek Adi Giriniz -> ")
        if degisken_1 not in meslek_adlari:
            print("        Lutfen Gecerli Bir Meslek Adi Giriniz...")
            time.sleep(2)
            continue
        sayac = 0
        with open("21100011002_1.txt", "r", encoding="utf-8") as dosya:
            for i in dosya:
                if degisken_1 in i:
                    sayac += 1
        if sayac == 0:
            print("        Bu Meslege Ait Aday Bulunmamaktadir...")
            time.sleep(2)
            a = 1
            break
        degisken_2 = input("        Adet Giriniz (Meslege Ait Aday Sayisi = {}) -> ".format(sayac))
        if 0 < len(degisken_2) <= sayac:
            break
        print("        Gecersiz Aday Sayisi...")
        time.sleep(2)
    if a == 0:
        degisken_4 = list()
        with open("21100011002_1.txt", "a+", encoding="utf-8") as dosya_1:
            dosya_1.seek(0)
            degisken_3 = dosya_1.readlines()
            for i in degisken_3:
                if degisken_1 in i:
                    degisken_4.append(i)
            for i in degisken_4:
                degisken_3.remove(i)
            dosya_1.truncate(0)
            dosya_1.writelines(degisken_3)
            personel_puani = [0 for i in range(len(degisken_4))]

        def personel_ise_alma(degisken_21, personel_puani1, degisken_41, degisken_11):  # IC ICE FONKSIYON
            global puan_dict
            global meslek_degiskeni
            global Maas
            global aday_list_boyut
            sayac_1 = 0
            for s in degisken_41:
                personel_data = s.split("#")
                for j in range(3, 7):
                    for k in puan_dict[j - 3].keys():
                        if float(personel_data[j].strip(" ")) <= k or k == -1:
                            personel_puani1[sayac_1] += puan_dict[j - 3][k]
                            break
                sayac_1 += 1
            for d in range(len(degisken_41)):
                for j in range(len(degisken_41)):
                    if personel_puani1[d] < personel_puani1[j]:
                        personel_puani1[d], personel_puani1[j] = personel_puani1[j], personel_puani1[d]
                        degisken_41[d], degisken_41[j] = degisken_41[j], degisken_41[d]
            for x in range(int(degisken_21)):
                maas_degiskeni = degisken_41[x].split("#")
                tec_deg = int(maas_degiskeni[4].strip(" "))
                if tec_deg <= 1:
                    per_maas = float(Maas) * meslek_degiskeni[degisken_11]
                    per_maas -= float(per_maas) * 0.05
                elif tec_deg <= 3:
                    per_maas = float(Maas) * (meslek_degiskeni[degisken_11] + 0.5)
                    per_maas -= float(per_maas) * 0.06
                elif tec_deg <= 5:
                    per_maas = float(Maas) * (meslek_degiskeni[degisken_11] + 0.75)
                    per_maas -= float(per_maas) * 0.07
                else:
                    per_maas = float(Maas) * (meslek_degiskeni[degisken_11] + 1.0 + ((tec_deg - 5) * 0.5))
                    per_maas -= float(per_maas) * 0.08
                degisken_41[x] = degisken_41[x].rstrip("\n")
                degisken_41[x] += " " * (aday_list_boyut[-1]) + "#" + str(per_maas) + "\n"
            with open("21100011002_2.txt", "a", encoding="utf-8") as dosya_2:
                dosya_2.writelines([degisken_41[f] for f in range(int(degisken_21))])
        personel_ise_alma(degisken_2, personel_puani, degisken_4, degisken_1)


def personel_listeleme():
    os.system("cls")
    with open("21100011002_2.txt", "r", encoding="utf-8") as dosya_k:
        kontrol_degiskeni = dosya_k.readlines()
        if len(kontrol_degiskeni) < 2:
            print("""
        [][][][][][][][][][][][][][][][][][]
        []      Personel Bulunamadi.      []
        [][][][][][][][][][][][][][][][][][]""")
            time.sleep(2)
            exit(menu())
    for i in range(len(aday_list) + 1):
        if i == len(personel_list) - 1:
            print("||", personel_list[i], " " * (8 - len(personel_list[i])), sep="", end="")
            break
        print("||", personel_list[i], " " * (aday_list_boyut[i] - len(personel_list[i])), sep="", end="")
        if i == len(personel_list) - 2:
            print("   ", end="")
    print("\n", "=" * (28 + sum(aday_list_boyut)), sep="")
    with open("21100011002_2.txt", "r", encoding="utf-8") as dosya:
        degisken = 0
        for i in dosya:
            if degisken == 0:
                degisken += 1
                continue
            for j in i.split("#"):
                print("||", j, sep="", end="")
    input("\n\n\n        (Devam Etmek Icin Enter'a Basiniz...)")


def giris_degistirme():
    while True:
        os.system("cls")
        print("""
        [][][][][][][][][][][][][][][][][][]
        []        GIRIS DEGISTIRME        []
        [][][][][][][][][][][][][][][][][][]""")
        yeni_kullanici_adi = input("\n        Yeni Kullanici Adi -> ")
        yeni_sifre = input("                Yeni Sifre -> ")
        if "/" not in yeni_sifre and "/" not in yeni_kullanici_adi:
            with open("21100011002_2.txt", "a+", encoding="utf-8") as dosya:
                dosya.seek(0)
                degisken = dosya.readlines()
                degisken_1 = degisken[0].split("/")
                degisken[0] = degisken_1[0] + "/" + yeni_kullanici_adi + "/" + yeni_sifre + "\n"
                dosya.truncate(0)
                dosya.writelines(degisken)
                break
        else:
            print("\n\n        Lutfen '/' isaretini kullanmadan olusturunuz...")
            time.sleep(2)


def loading():
    yukleme_list = [" " for i in range(8)]
    degisken = 0
    while True:
        print("""\n\n\n
             [[][][][][][][][][][][][]]
             [       YUKLENIYOR       ]
             [[][][][][][][][][][][][]]
             
              [{}][{}][{}][{}][{}][{}][{}][{}]""".format(yukleme_list[0], yukleme_list[1], yukleme_list[2], yukleme_list[3], yukleme_list[4], yukleme_list[5], yukleme_list[6], yukleme_list[7]))
        time.sleep(0.1)
        if degisken == 8:
            break
        yukleme_list[degisken] = "#"
        degisken += 1
        os.system("cls")


def menu():
    fonk_adlari = {0: aday_ekle, 1: aday_listele, 2: aday_silme, 3: aday_guncelleme, 4: personel_ekleme, 5: personel_listeleme, 6: personel_silme, 7: personel_guncelleme, 8: personel_bulma, 9: personel_zam_yapma, 10: giris_degistirme}
    # ALT ALTA IF ELIF BLOKLARI YERINE SOZLUKTEN FONKSIYONLARA ULASIYORUM
    while True:
        os.system("cls")
        degisken = input("""
        [][][][][][][][][][][][][][][][][][]
        []                                []
        []   1 - Aday Ekleme              []
        []   2 - Aday Listeleme           []
        []   3 - Aday Silme               []
        []   4 - Aday Guncelleme          []
        []   5 - Personel Ekleme          []
        []   6 - Personel Listeleme       []
        []   7 - Personel Silme           []
        []   8 - Personel Guncelleme      []
        []   9 - Personel Bulma           []
        []  10 - Personel Zam Yapma       []
        []  11 - Giris Degistirme         []
        []   X - Exit                     []
        []                                []
        [][][][][][][][][][][][][][][][][][]
        
           -> """)
        if degisken == "X":
            break
        try:
            fonk_adlari[int(degisken) - 1]()

        except ValueError:
            print("Lutfen Gecerli Bir Islem Seciniz...")
            time.sleep(2)
            os.system("cls")

giris()
