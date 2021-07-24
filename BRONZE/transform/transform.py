def rotation_90(arr):
    ret_arr = []
    for row in range(len(arr)):
        appended = []
        for col in reversed(range(len(arr))):
            appended.append(arr[col][row])
        ret_arr.append(appended)
    return ret_arr

def check(arr1, arr2):
    for i in range(len(arr1)):
        for j in range(len(arr1)):
            if arr1[i][j] != arr2[i][j]:
                return False
    return True

def reflection(arr):
    ret_arr = []
    for row in range(len(arr)):
        appended = []
        for col in reversed(range(len(arr))):
            appended.append(arr[row][col])
        ret_arr.append(appended)
    return ret_arr
    
n = int(input(""))
arr = []

for row in range(n):
    arr.append([x for x in input("").strip()])
    
