p=open("testdata.txt","r")
a=p.read()
print(a)
dasturat=a.split('\n')
tedad_dasturat=len(dasturat)
iden={}
dict={}
def tashkhis (string1, string2,string3):
    test=list(string1)
    i=len(test)-1
    if test[i]==':':
        dict[string1]=string2+' '+string3
        print (string1+" "+dict[string1])
        if string2=="add":
            ad=string3.split(',')
            iden[ad[0]]=iden[ad[0]]+iden[ad[1]]
            print(iden[ad[0]])
        elif string2=="sub" :
            ad=string3.split(',')
            iden[ad[0]]=iden[ad[0]]-iden[ad[1]]
            print(iden[ad[0]])
        elif string2=="jmp" :
            string_temp=string3+':'
            temp=dict[string_temp].split()
            print("dasture paresh be khaneye "+string3
                  +" mibashad!")
            tashkhis(string_temp,temp[0],temp[1])
        elif string2=="mul" :
            ad=string3.split(',')
            iden[ad[0]]=iden[ad[0]]*iden[ad[1]]
            print(iden[ad[0]])
        elif string2=="div" :
            ad=string3.split(',')
            if iden[ad[1]]!=0 :
                iden[ad[0]]=iden[ad[0]]/iden[ad[1]]
                print(iden[ad[0]])
            else :
                print ("this is divide by zero!")
        elif string2=="out" :
            print(iden[string3])
        elif string2=="inp":
            iden[string3]=int(input("meghdar ra vared konid:"))
        elif string2=="mov":
            ad=string3.split(',')
            iden[ad[0]]=iden[ad[1]]
        elif string2=="cmp":
            ad=string3.split(',')
            if iden[ad[0]]==iden[ad[1]]:
                print("2 adad ba ham barabarand!")
            elif iden[ad[0]]<iden[ad[1]]:
                f1=str(iden[ad[0]])
                f2=str(iden[ad[1]])
                print (f1+"<"+f2)
            else :
                f1=str(iden[ad[0]])
                f2=str(iden[ad[1]])
                print (f1+">"+f2)
            
    else :
        iden[string1]=int(string3) 
    return
i=0
while i!=tedad_dasturat:
 x=[]*10
 x=dasturat[i].split()
 tashkhis(x[0],x[1],x[2])
 i=i+1
p.close()
var=input("enter the character to exit:")
