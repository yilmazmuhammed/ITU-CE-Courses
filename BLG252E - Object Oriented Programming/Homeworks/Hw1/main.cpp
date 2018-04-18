/* @Author
 * Muhammed YILMAZ
 * yilmazmu15@gmail.com
 * Spring 2018
 */

#include <iostream>
#include <cstring>
#include "CivilRegistry.h"
#include "Citizen.h"
#include "Time.h"
#include <list>

using namespace std;

void read_input_file();

CivilRegistry civilRegistry;

int main()
{
    read_input_file();

    cout << "Citizens with an appointment:" << endl;
    while(civilRegistry.removeCitizen(1) == 1);
    cout << endl << "Citizens without an appointment:" << endl;
    while(civilRegistry.removeCitizen(2) == 1);

    return 0;
}

// Dosyadan vatandaş bilgilerini okur, ilgili listeye ekler.
void read_input_file()
{
    FILE *inputFile = fopen("input.txt","r");
    if(inputFile == NULL)
        return;

    char tempIdNo[50], tempName[50], tempSurname[50], tempAppSlot[20],
            tempHasAppChar[10];
    int tempDay, tempMonth, tempYear, tempHour, tempMinute;
    bool tempHasApp;

    Citizen *newCitizen;
    Time *tempAppTime;
    for(int i = 0; !feof(inputFile); ++i){
        // İlk satırı okumaz
        if(i==0){
            char temp[1024];
            fgets(temp, 1024, inputFile);
            continue;
        }
        // İkinci satırdan itibaren satırları okur
        fscanf(inputFile, "%s %s %s %s %d-%d-%d %s %d.%d\n",
             tempIdNo, tempName, tempSurname, tempHasAppChar, &tempDay,
             &tempMonth, &tempYear, tempAppSlot, &tempHour, &tempMinute);

        /* randevulu olup olmamasını ayarlar.
         * (Randevusuz olanlara NULL ataması consturactor'da gerçekleşecek.)
         */
        if(strcmp("FALSE",tempHasAppChar)==0)
            tempHasApp = false;
        else if(strcmp("TRUE",tempHasAppChar)==0)
            tempHasApp = true;

        // Time oluşturulur.
        tempAppTime = new Time(tempDay, tempMonth, tempYear, tempHour, tempMinute);

        //Vatandaş oluşturulur.
        newCitizen = new Citizen(tempIdNo, tempName, tempSurname,
                         tempHasApp, *tempAppTime, tempAppSlot);

        //Vatandaşı ilgili listeye ekler
        civilRegistry.insertCitizen(newCitizen);
        delete newCitizen;
        delete tempAppTime;
    }

    fclose(inputFile);
}
