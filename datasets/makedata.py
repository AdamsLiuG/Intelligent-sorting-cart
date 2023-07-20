import os
import random

trainval_percent = 0.1  # 可自行进行调节
train_percent = 1
xmlfilepath = 'F:/dataset/Annotations'
txtsavepath = 'F:/dataset/imageset'
total_xml = os.listdir(xmlfilepath)

num = len(total_xml)
list = range(num)
tv = int(num * trainval_percent)
tr = int(tv * train_percent)
trainval = random.sample(list, tv)
train = random.sample(trainval, tr)

# ftrainval = open('ImageSets/Main/trainval.txt', 'w')
ftest = open('F:/dataset/ImageSets/test.txt', 'w')
ftrain = open('F:/dataset/ImageSets/train.txt', 'w')
# fval = open('ImageSets/Main/val.txt', 'w')

for i in list:
    name = total_xml[i][:-4] + '\n'
    if i in trainval:
        # ftrainval.write(name)
        if i in train:
            ftest.write(name)
        # else:
        # fval.write(name)
    else:
        ftrain.write(name)

# ftrainval.close()
ftrain.close()
# fval.close()
ftest.close()
