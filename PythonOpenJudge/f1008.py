"""
During his last sabbatical, professor M. A. Ya made a surprising discovery about the old Maya calendar. From an old knotted message, professor discovered that the Maya civilization used a 365 day long year, called Haab, which had 19 months. Each of the first 18 months was 20 days long, and the names of the months were pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu. Instead of having names, the days of the months were denoted by numbers starting from 0 to 19. The last month of Haab was called uayet and had 5 days denoted by numbers 0, 1, 2, 3, 4. The Maya believed that this month was unlucky, the court of justice was not in session, the trade stopped, people did not even sweep the floor. For religious purposes, the Maya used another calendar in which the year was called Tzolkin (holly year). The year was divided into thirteen periods, each 20 days long. Each day was denoted by a pair consisting of a number and the name of the day. They used 20 names: imix, ik, akbal, kan, chicchan, cimi, manik, lamat, muluk, ok, chuen, eb, ben, ix, mem, cib, caban, eznab, canac, ahau and 13 numbers; both in cycles. Notice that each day has an unambiguous description. For example, at the beginning of the year the days were described as follows: 1 imix, 2 ik, 3 akbal, 4 kan, 5 chicchan, 6 cimi, 7 manik, 8 lamat, 9 muluk, 10 ok, 11 chuen, 12 eb, 13 ben, 1 ix, 2 mem, 3 cib, 4 caban, 5 eznab, 6 canac, 7 ahau, and again in the next period 8 imix, 9 ik, 10 akbal . . . Years (both Haab and Tzolkin) were denoted by numbers 0, 1, . . . , where the number 0 was the beginning of the world. Thus, the first day was: Haab: 0. pop 0 Tzolkin: 1 imix 0 Help professor M. A. Ya and write a program for him to convert the dates from the Haab calendar to the Tzolkin calendar.

输入
The date in Haab is given in the following format:
NumberOfTheDay. Month Year

The first line of the input file contains the number of the input dates in the file. The next n lines contain n dates in the Haab calendar format, each in separate line. The year is smaller then 5000.
输出
The date in Tzolkin should be in the following format:
Number NameOfTheDay Year

The first line of the output file contains the number of the output dates. In the next n lines, there are dates in the Tzolkin calendar format, in the order corresponding to the input dates.
样例输入
3
10. zac 0
0. pop 0
10. zac 1995
样例输出
3
3 chuen 0
1 imix 0
9 cimi 2801
"""
HaabMouth={"pop":1, "no":2, "zip":3, "zotz":4, "tzec":5, "xul":6, "yoxkin":7, "mol":8, "chen":9, "yax":10, "zac":11, "ceh":12, "mac":13, "kankin":14, "muan":15, "pax":16, "koyab":17, "cumhu":18,"uayet":19}
TzolkinDay=['imix', 'ik', 'akbal', "kan", 'chicchan', 'cimi', 'manik', 'lamat', 'muluk', 'ok', 'chuen', 'eb', 'ben', 'ix', 'mem', 'cib', 'caban', 'eznab', 'canac', 'ahau']
count = int(input())
inputstr=list("0"*count)
for i in range(count):
    inputstr[i]=input()
print(count)
for j in range(count):
    splitedstr=str(inputstr[j]).split(" ")
    strtemp=str(splitedstr[0]).rstrip(".")
    numberofday = int(strtemp)
    mouth=splitedstr[1]
    year=int(splitedstr[2])
    days=year*365+(HaabMouth[mouth]-1)*20+numberofday
    year=int(days/260)
    nameoftheday=TzolkinDay[days%20]
    number=days%13+1
    print(str(number)+" "+nameoftheday+" "+str(year))

    
