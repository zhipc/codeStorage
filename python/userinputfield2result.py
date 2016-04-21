##########
#
# 在无登录的网页输入框中批量键入用户输入，收集返回结果
#
##########
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from urllib import request
import re

list = [("chr7", 12910500, 12910800), ("chr13", 32910819, 32910939), ("chr3", 32910222, 32910666)]

def deal_url(url):
    req = request.Request(url)
    req.add_header("User-Agent", "Mozilla/5.0 (Windows NT 6.1; rv:2.0.1) Gecko/20100101 Firefox/4.0.1")
    #req.add_header('User-Agent', 'Mozilla/6.0 (iPhone; CPU iPhone OS 8_0 like Mac OS X) AppleWebKit/536.26 (KHTML, like Gecko) Version/8.0 Mobile/10A5376e Safari/8536.25')
    with request.urlopen(url) as f:
        data = f.read()
        content = data.decode("utf-8")
        #print("Data: ", content)
        pattern = re.compile(r'<PRE>(.*?)</PRE>', re.S)
        items = re.findall(pattern, content)
        for item in items:
            print(item)
            
def deal_list(list):
    for tiple in list:
        addr_chr = tiple[0]
        addr_start = tiple[1]
        addr_end = tiple[2]
        addr_all = addr_chr + "%3A" + str(addr_start) + "-" + str(addr_end)
        #notice: url should not be more lines
        url = "http://genome.ucsc.edu/cgi-bin/hgc?hgsid=490752709_2SCce73AfTrq0s3i1qQ96ZoPycyK&g=htcGetDna2&table=&i=mixed&o=32910818&l=32910818&r=32910819&getDnaPos=" + addr_all + "&db=hg19&hgSeq.cdsExon=1&hgSeq.padding5=0&hgSeq.padding3=0&hgSeq.casing=upper&boolshad.hgSeq.maskRepeats=0&hgSeq.repMasking=lower&boolshad.hgSeq.revComp=0&submit=get+DNA"
        deal_url(url)
            
if __name__ == "__main__":
    deal_list(list)