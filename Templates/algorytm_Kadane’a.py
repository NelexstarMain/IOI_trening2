"""
To klasyczny i bardzo szybki algorytm służący
do znajdowania największej sumy spójnego (ciągłego) 
podciągu w tablicy liczb całkowitych.


Zadania:
    -Maximum Subarray Sum

"""

n = int(input())                      
a = list(map(int, input().split()))  

najlepsza_suma = a[0]              
obecna_suma = a[0]                   

for i in range(1, n):

    obecna_suma = max(a[i], obecna_suma + a[i])

    najlepsza_suma = max(najlepsza_suma, obecna_suma)

print(najlepsza_suma)


 