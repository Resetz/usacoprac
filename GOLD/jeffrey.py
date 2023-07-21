T = int(input(""))
def total_path(n, k , board):
    if k == 1:
        total = 2
        for i in range(n):
            if board[0][i] == "H" or board[i][n-1]=="H":
                total = total -1
                break
        for i in range(n):
            if board[i][0] == "H" or board[n-1][i]=="H":
                total = total -1
                break
        return(total)
    if k == 2:
        # === x direction ===
        total = 0
        for c in range(1, n):
            if board[0][c] == "H":
                break
            flag = 1
            for r in range(1, n):
                if board[r][c] == "H":
                    flag=0
                    break
            for cc in range(c, n):
                if board[n-1][cc] == "H":
                    flag=0
                    break
            total = total + flag
        # === y direction ===
        for r in range(1, n):
            if board[r][0] == "H":
                break
            flag = 1
            for c in range(1, n):
                if board[r][c] == "H":
                    flag=0
                    break
            for rr in range(r, n):
                if board[rr][n-1] == "H":
                    flag=0
                    break
            total = total + flag
        return(total)
    if k==3:
    # ================= x direction ===========
        x = [0]*n
        for c in range(1,n-1): # go through 0th row except last element
            if board[0][c] == "H": #if there are H in 0th row, then no solution for k=1 for row direction
                break
            for r in range(1,n):
                if board[r][c] == "H":
                    break
                flag = 1
                for cc in range(c+1,n):
                    if board[r][cc] == "H":
                        flag = 0
                        break
                if flag == 1:
                    for rr in range(r+1, n):
                        if board[rr][n-1] == "H":
                            flag = 0
                            break
                x[c] = x[c] + flag
    #=========== y direction =======
        y = [0] * n
        for r in range(1, n - 1):  # go through 0th col except last element
            if board[r][0] == "H":  # if there are H in 0th col, then no solution for k=1 for row direction
                break
            for c in range(1, n):
                if board[r][c] == "H":
                    break
                flag = 1
                for rr in range(r+1, n):
                    if board[rr][c] == "H":
                        flag = 0
                        break
                if flag == 1:
                    for cc in range(c+1, n):
                        if board[n - 1][cc] == "H":
                            flag = 0
                            break
                y[r] = y[r] + flag
        total = 0
        for i in range(n-1):
            total = total + x[i] +y[i]
        total = total + total_path(n, 1, board) #add the solution for 1 turn
        return(total)

ans = [0]*T
for i in range(T):
    n,k = [int(x) for x in input("").split(" ")]
    board = []
    for x in range(n):
        board.append(input("").strip())
    ans[i] = total_path(n, k, board)
for i in range(T):
    print( ans[i] )