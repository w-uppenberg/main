def read_boards(file_path):
    boards = []
    with open(file_path, 'r') as file:
        lines = file.readlines()
        board = []
        for line in lines:
            if line.strip():
                board.append(list(map(int, line.strip().split())))
            else:
                if board:
                    boards.append(board)
                    board = []
        if board:
            boards.append(board)
    return boards

def validate_board(board):
    # Check rows
    for row in board:
        if len(set(row)) != len(row):
            return False

    # Check columns
    for col in range(len(board[0])):
        column = [board[row][col] for row in range(len(board))]
        if len(set(column)) != len(column):
            return False

    # Check sub-grids
    for i in range(0, len(board), 3):
        for j in range(0, len(board[0]), 3):
            subgrid = [board[row][col] for row in range(i, i+3) for col in range(j, j+3)]
            if len(set(subgrid)) != len(subgrid):
                return False

    # Check adjacent numbers horizontally and vertically
    for row in range(len(board)):
        for col in range(len(board[0])):
            if board[row][col] == 3 or board[row][col] == 5:
                if row > 0 and (board[row-1][col] == 3 or board[row-1][col] == 5):
                    return False
                if row < len(board)-1 and (board[row+1][col] == 3 or board[row+1][col] == 5):
                    return False
                if col > 0 and (board[row][col-1] == 3 or board[row][col-1] == 5):
                    return False
                if col < len(board[0])-1 and (board[row][col+1] == 3 or board[row][col+1] == 5):
                    return False

    return True

def validate_extra_rule(board):
    "extract the main diagonal (position 0,0 to 8,8) and check if it contains all the numbers 1-9"
    diagonal = [board[i][i] for i in range(len(board))]
    if len(set(diagonal)) != len(diagonal):
        return False
    diagonal2 = [board[i][8-i] for i in range(len(board))]
    if len(set(diagonal2)) != len(diagonal2):
        return False
    
    # Check adjacent numbers in diagonals
    for i in range(len(board)-1):
        if (board[i][i] == 3 or board[i][i] == 5) and (board[i+1][i+1] == 3 or board[i+1][i+1] == 5):
            return False
        if (board[i][8-i] == 3 or board[i][8-i] == 5) and (board[i+1][8-i-1] == 3 or board[i+1][8-i-1] == 5):
            return False
    
    return True


# Read the Sudoku boards from input.txt
boards = read_boards('input.txt')
valid_count = 0
invalid_count = 0


# Validate all boards
for board in boards:
    is_valid = validate_board(board) & validate_extra_rule(board)
    if is_valid: 
        valid_count += 1
    else:
        invalid_count += 1

print(f"The number of valid Sudoku boards is {valid_count}.")
print(f"The number of invalid Sudoku boards is {invalid_count}.")
