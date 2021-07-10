class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)
        # number of question mark in alice's and bob's area respectively
        al = 0
        bo = 0
        # sum of other numbers 
        count1 = 0
        count2 = 0
        
        for i in range(n):
            if i<n//2:
                if num[i]=='?':
                    al=al+1
                else:
                    count1 += int(num[i])
            else:
                if num[i]=='?':
                    bo=bo+1
                else:
                    count2 += int(num[i])
        res = (count1+(al/2)*9) - (count2+(bo/2)*9)
        return res!=0
        
