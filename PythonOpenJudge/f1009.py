def findvalue(values, counts, index):
    currentcount = 0
    length = len(counts)
    for i in range(length):
        currentcount += counts[i]
        if index < currentcount:
            return values[i]


class picdata:

    def __init__(self, width, values, counts):
        self.width = width
        self.values = values
        self.counts = counts

    def print(self):
        print(self.width)
        for i in range(len(self.values)):
            print(self.values[i], self.counts[i])
        print("0 0")

pics = list()
while True:
    width = int(input())
    if width == 0:
        break
    valuelist = list()
    countlist = list()
    totalcount = 0
    while True:
        datain = input()
        if datain == "0 0":
            break
        datapre = str(datain).split(" ")
        valuelist.append(int(datapre[0]))
        countlist.append(int(datapre[1]))
        totalcount += int(datapre[1])
    processedval = list()
    processedcount = list()
    j = 0
    i = 0
    x = 0
    currentcount = 0
    while True:
        if j>=len(countlist):
            break
        x=valuelist[j]
        if countlist[j] > 2 * width+2:
            minvalue = 0
            for z in range(width+1):
                minvalue = 0 
                if i - width - 1 >= 0 and i % width != 0:
                    val=abs(findvalue(valuelist,countlist,i - width - 1) - x)
                    minvalue = max(minvalue, val)
                if i - width >= 0:
                    val=abs(findvalue(valuelist,countlist,i - width) - x)
                    minvalue = max(minvalue, val)
                if i - width + 1 > 0 and i % width != width - 1:
                    val=abs(findvalue(valuelist,countlist,i - width + 1) - x)
                    minvalue = max(minvalue, val)
                if i % width != 0:
                    val=abs(findvalue(valuelist,countlist,i - 1) - x)
                    minvalue = max(minvalue, val)
                if i % width != width - 1:
                    val=abs(findvalue(valuelist,countlist,i + 1) - x)
                    minvalue = max(minvalue, val)
                if i + width - 1 < totalcount and i % width != 0:
                    val=abs(findvalue(valuelist,countlist,i + width - 1) - x)
                    minvalue = max(minvalue, val)
                if i + width < totalcount:
                    val=abs(findvalue(valuelist,countlist,i + width) - x)           
                    minvalue = max(minvalue, val)
                if i + width + 1 < totalcount and i % width != width - 1:
                    val=abs(findvalue(valuelist,countlist,i + width + 1) - x)
                    minvalue = max(minvalue, val)
                if len(processedval) == 0:
                    processedval.append(minvalue)
                    processedcount.append(1)
                else:
                    if processedval[len(processedval) - 1] == minvalue:
                        processedcount[len(processedcount) - 1] += 1
                    else:
                        processedval.append(minvalue)
                        processedcount.append(1)
                i += 1
            if processedval[len(processedval) - 1] == 0:
                processedcount[len(processedcount) -1] += countlist[j] - 2 * width-2
                i += countlist[j] - 2 * width-2
            else:
                processedval.append(0)
                processedcount.append(countlist[j] - 2 * width-2)
                i += countlist[j] - 2 * width-2
            for z in range(width+1):
                minvalue = 0
                if i - width - 1 >= 0 and i % width != 0:
                    val=abs(findvalue(valuelist,countlist,i - width - 1) - x)
                    minvalue = max(minvalue, val)
                if i - width >= 0:
                    val=abs(findvalue(valuelist,countlist,i - width) - x)
                    minvalue = max(minvalue, val)
                if i - width + 1 > 0 and i % width != width - 1:
                    val=abs(findvalue(valuelist,countlist,i - width + 1) - x)
                    minvalue = max(minvalue, val)
                if i % width != 0:
                    val=abs(findvalue(valuelist,countlist,i - 1) - x)
                    minvalue = max(minvalue, val)
                if i % width != width - 1:
                    val=abs(findvalue(valuelist,countlist,i + 1) - x)
                    minvalue = max(minvalue, val)
                if i + width - 1 < totalcount and i % width != 0:
                    val=abs(findvalue(valuelist,countlist,i + width - 1) - x)
                    minvalue = max(minvalue, val)
                if i + width < totalcount:
                    val=abs(findvalue(valuelist,countlist,i + width) - x)           
                    minvalue = max(minvalue, val)
                if i + width + 1 < totalcount and i % width != width - 1:
                    val=abs(findvalue(valuelist,countlist,i + width + 1) - x)
                    minvalue = max(minvalue, val)
                if len(processedval) == 0:
                    processedval.append(minvalue)
                    processedcount.append(1)
                else:
                    if processedval[len(processedval) - 1] == minvalue:
                        processedcount[len(processedcount) - 1] += 1
                    else:
                        processedval.append(minvalue)
                        processedcount.append(1)
                i+=1
            j+=1
        else:
            minvalue = 0
            for z in range(countlist[j]):
                minvalue = 0
                if i - width - 1 >= 0 and i % width != 0:
                    val=abs(findvalue(valuelist,countlist,i - width - 1) - x)
                    minvalue = max(minvalue, val)
                if i - width >= 0:
                    val=abs(findvalue(valuelist,countlist,i - width) - x)
                    minvalue = max(minvalue, val)
                if i - width + 1 > 0 and i % width != width - 1:
                    val=abs(findvalue(valuelist,countlist,i - width + 1) - x)
                    minvalue = max(minvalue, val)
                if i % width != 0:
                    val=abs(findvalue(valuelist,countlist,i - 1) - x)
                    minvalue = max(minvalue, val)
                if i % width != width - 1:
                    val=abs(findvalue(valuelist,countlist,i + 1) - x)
                    minvalue = max(minvalue, val)
                if i + width - 1 < totalcount and i % width != 0:
                    val=abs(findvalue(valuelist,countlist,i + width - 1) - x)
                    minvalue = max(minvalue, val)
                if i + width < totalcount:
                    val=abs(findvalue(valuelist,countlist,i + width) - x)           
                    minvalue = max(minvalue, val)
                if i + width + 1 < totalcount and i % width != width - 1:
                    val=abs(findvalue(valuelist,countlist,i + width + 1) - x)
                    minvalue = max(minvalue, val)
                if len(processedval) == 0:
                    processedval.append(minvalue)
                    processedcount.append(1)
                else:
                    if processedval[len(processedval) - 1] == minvalue:
                        processedcount[len(processedcount) - 1] += 1
                    else:
                        processedval.append(minvalue)
                        processedcount.append(1)
                i+=1
            j+=1
    pic = picdata(width, processedval, processedcount)
    pics.append(pic)
for pic in pics:
    pic.print()
print("0")
