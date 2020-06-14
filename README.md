# Release:
-Programos atliekami darbai:
  1) Skaičiuoja, kiek kartų kartojasi kiekvienas žodis tekste, kurį galima rasti text.txt faile:
      - Skaičiuojant žodžius atkreipiamas dėmesys į skyrybos ženklus - jie neįskaičiuojami į žodių sąrašą;
      - Žodžiai, kurie yra apsupti daugiau nei vieno skyrybos ženklo, pvz: ("kelias"), yra išvedami paprastai (t.y. be jokių skyrybos ženklų);
      - Jeigu žoduje yra didžiosios raidės, jos pakeičiamos mažosiomis, kad pradžioje sakinio esantys žodžiai būtų priskaitomi prie paprastų, pvz: "The" ir "the" yra skaitomas kaip vienas žodis.
  2) Renka eilutes, kuriose yra skaičiuojami žodžiai;
  3) Suranda tekste esančius url adresus.
  
  Visi šie duomenys yra išvedami į ekraną, o url adresai dar ir išvedami į failą "links.txt";

- Įdiegimo instrukcija:
  1) Atsisiūskite failų zip aplanką; 
  2) "extract"'inkite į kokį nors aplanką.

- Naudojimosi instrukcija:
  1) Atsidarę komandinę eilutę nueikite į aplanką, kuriame yra "extract"'intni atsisiųsti failai;
  2) Veskite norimas komandas iš žemiau esančio komadų sarašo (jos aprašytos Makefile faile).
 
- Komandinės eilutės komandos:

|Vardas     |Funkcija                                   |
|-----------|-------------------------------------------|
|app        |kompiliuoja ir linkina pagrindinį programos failą|
|clean      | ištrina sukompiliuotus failus             |
