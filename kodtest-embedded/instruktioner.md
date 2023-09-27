# Hemtest embedded

Du har fått i uppgift att skriva en applikation som kan visa text på den lite udda displaymodellen CS0202. I bifogat material hittar du ett utdrag ur användarmanualen för den mikrokontroller som valts för projektet. Den har en modul som heter pd9982 som stödjer att skicka data till just den här displaymodellen (yay!). Eftersom hårdvaru-teamet är aningen försenade i projektet så kommer du att behöva testa din kod mot en emulator som länkas in som ett statiskt lib mot din kod (bifogat lib för linux och windows). *För mac se not nedan*. Emulatorn skriver output till en file-descriptor istället för att skriva ut den på en display.

Bifogat finner du en exempel-fil (exampleInput_utf8.txt) som du kan testa med (men det är fritt fram att hitta på egna exempel). Då emulator lib:et kan skriva det som skall hamna på displayen till en fil bör det vara enkelt att jämföra exempel-filen med lib:ets output-fil (de skall vara identiska) vilket betyder att din applikation fungerar som den skall. **notera att modulen tar UTF16 som input och ej UTF8 och använder sig av pthreads** Vid rättning används filer som innehåller alla möjliga UTF-8 teckenvarianter. 

Din leverans i den här uppgiften kommer att bestå av koden för din applikation, ev byggskript och annan data som behövs för att bygga och köra dina tester samt en README som förklarar hur din applikation kan byggas, testas och köras.

Om du inte hinner implementera allt "from scratch", så går det bra
att använda externa bibliotek för vissa delar om du kan beskriva hur du använder dem och motivera dina val.

# Utveckling på Mac
Om du vill utveckla och testa din applikation på Mac så rekommenderar vi att bygga och köra i docker. Här är ett exempel som bygger med gcc och kör som kan användas som en grund (tänk på att du behöver länka in lib)
`docker run -v $(pwd):/src --user=$(id -u) --workdir="/src" gcc bash -c "gcc YOUR_FILE -o myapp; ./myapp"`

# Användbara länkar
* http://www.sunshine2k.de/articles/coding/crc/understanding_crc.html
* https://en.wikipedia.org/wiki/UTF-16
* https://en.wikipedia.org/wiki/UTF-8
* https://pubs.opengroup.org/onlinepubs/7908799/xsh/iconv.h.html
* https://reveng.sourceforge.io/crc-catalogue/all.htm#crc.cat.crc-8-lte