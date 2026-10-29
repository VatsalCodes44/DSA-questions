public class NQueen {
    boolean isSafe(char [][] board, int r, int c) {
        // checking <-
        for (int i = c; i >= 0 ; i--) {
            if (board[r][i] == 'Q') return false;
        }

        // checking upper diagonal
        int i = r, j = c;
        while ( i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') return false;
            i--;
            j--;
        }

        i = r;
        j = c;
        while (i < board.length && j >= 0) {
            if (board[i][j] == 'Q') return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(char[][] board, int c) {
        if (c == board.length) {
            printBoard(board);
            return;
        }

        for (int i = 0; i < board.length; i++) {
            if (isSafe(board, i, c)) {
                board[i][c] = 'Q';
                solve(board, c+1);
                board[i][c] = '.';
            }
        }
    }

    void printBoard(char[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                System.out.print(board[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println();
    }
    void nQueen(int n) {
        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                board[i][j] = '.';
                board[i][j] = '.';
            }
        }

        solve(board, 0);
    }
    public static void main(String[] args) {
        NQueen x = new NQueen();
        x.nQueen(4);
    }
}
