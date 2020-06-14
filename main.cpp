#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include <algorithm>
struct data
{
    int line[100];
    int times;
};

const char DUOM[] = "text.txt";
const char REZ[] = "links.txt";

int main()
{
    char symbols[10] = {'.', '!', ':', ';', '-', '(', ')', '/', ',', '"'};
    std::string links[100];  //surastu linku masyvas
    std::string w = "www";
    std::string http = "http";
    std::map<std::string, data> s; //map tipo kintamasis sudeti zodzius
    std::ifstream duom (DUOM);
    int o = 0; //kelintas zodis is viso teksto
    int row = 0; //kurioj eilutej nuskaitomi zodziai
    int link_count = 0; //surastu linku skaiciuoklis masyvo indeksui
    while (!duom.eof()) //kol nesibaige duomenu failas
    {
        if (o % 12 == 0) row++; //kiekvienoj eilutej yra po 12 zodziu, jeigu % is 12 be liekanos, reiskia, kad prasideda kita eilute
        std::string word;
        duom >> word;
        for (int i = 0; i < 10; i++) //jeigu pradzioj ar pabaigoj zodzio yra simboliai, juos istrina
        {
            if (word[0] == symbols[i]) word.erase(0,1);
            if (word[0] == symbols[i]) word.erase(0,1); //patikrina ir antra simboli, reikalinga pvz atveju: ("masina")
            if (word[word.size()-1] == symbols[i]) word.erase(word.size()-1, 1);
            if (word[word.size()-2] == symbols[i]) word.erase(word.size()-2, 1);
            //jeigu yra didziuju raidziu, pavercia i mazasias, kad The ir the neskaiciuotu kaip skirtingo zodzio
            transform(word.begin(), word.end(), word.begin(), ::tolower);
        }
        if (word.find(w) != std::string::npos || word.find(http) != std::string::npos) //jeigu zodi suranda string "www" arba "http", ideda i linku masyva
            {
                links[link_count] = word;
                link_count++;
            }
        if (s.find(word) == s.end()) //jeigu tokio zodzio nera map'se, ji prideda ir priskaiciuoja, kad kartojasi 1 karta ir iraso, kurioj eilutej
        {
            s[word].times = 1;
            int var = s[word].times - 1;
            s[word].line[var] = row;
        }
        else // jeigu toks zodis jau yra, tik priskaiciuoja +1 prie pasikartojimu ir iraso, kurioj eilutej
        {
            s[word].times++;
            int var = s[word].times - 1;
            s[word].line[var] = row;
        }
        o++;
    }
    duom.close();
    std::ofstream rez (REZ);
    std::cout << "Word            ||Times||Lines in which word can be found" << std::endl;
    std::cout << std::endl;
    std::map<std::string, data>::iterator it =s.begin(); //map'so iteratorius
    for (; it!=s.end();it++) //kol nesibaige map'so reiksmes, jas visas isveda
    {
        std::cout << std::setw(19) << std::left<< it->first<<" " <<std::setw(5)<<std::left<< it->second.times << " ";
        for (int i = 0; i < 100; i++) //isveda eilutes, kuriose yra zodis
        {
         int number = it->second.line[i];
         if (number != 0) std::cout<< it->second.line[i]<<" ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < 100; i++) //isveda linkus i ekrana ir juos iraso i faila
    {
        if (links[i].size() > 0)
        {
            std::cout << links[i] << " ";
            rez << links[i] << std::endl;
            std::cout << std::endl;
        }

    }
    std::cout << std::endl;
    rez.close();
}
