import java.util.Scanner;
import java.io.File;

public class MazeTraversal {
    public static void main(String[] args) {
        File inFile = new File("sampleMaze.dat");

        char[][] maze = null;

        try (Scanner scan = new Scanner(inFile)) {
            int row = scan.nextInt();
            scan.nextLine();

            maze = new char[row][];

            int i = 0;
            while (scan.hasNext()) {
                maze[i] = scan.nextLine().toCharArray();
                ++i;
            }

        } catch (Exception e) {
            System.exit(0);
        }

        int startRowIndex = 0;
        int startColIndex = 0;
        int finishRowIndex = 0;
        int finishColIndex = 0;

        // Finds starting position & ending position
        for (int i = 0; i < maze.length; i++) {
            for (int j = 0; j < maze[i].length; j++) {
                if ((maze[i][j]) == '+') {
                    startRowIndex = i;
                    startColIndex = j;
                }
                if ((maze[i][j]) == '-') {
                    finishRowIndex = i;
                    finishColIndex = j;
                }
            }
        }

        if (solveMaze(maze, startRowIndex, startColIndex, startRowIndex, startColIndex, finishRowIndex,
                finishColIndex)) {
            System.out.println("MAZE SOLVED\n");
        } else {
            System.out.println("MAZE NOT SOLVED\n");
        }
        printMaze(maze);
    }

    // Prints the maze
    public static void printMaze(char[][] maze) {
        for (char[] row : maze) {
            for (char col : row) {
                System.out.print(col);
            }
            System.out.println();
        }
    }

    // Checks if spot is valid
    public static boolean isValid(char[][] maze, int row, int col, int rowstart, int colstart, int rowfinish,
            int colfinish) {
        if (row == rowfinish && col == colfinish) {
            return true;
        }

        if (!(row == rowstart && col == colstart)) {
            if (row >= 0 && row < maze.length && col >= 0 && col < maze[row].length) {
                return maze[row][col] == ' ';
            }
            return false;
        }
        return true;
    }

    public static boolean solveMaze(char[][] maze, int row, int col, int startRowIndex, int startColIndex,
            int finishRow, int finishCol) {

        if (isValid(maze, row, col, startRowIndex, startColIndex, finishRow, finishCol)) {
            // At the exit
            if (row == finishRow && col == finishCol)
                return true;
            maze[row][col] = '+';

            // North
            boolean mazeFlag = solveMaze(maze, row - 1, col, startRowIndex, startColIndex, finishRow, finishCol);

            // East
            if (!mazeFlag)
                mazeFlag = solveMaze(maze, row, col + 1, startRowIndex, startColIndex, finishRow, finishCol);

            // South
            if (!mazeFlag)
                mazeFlag = solveMaze(maze, row + 1, col, startRowIndex, startColIndex, finishRow, finishCol);

            // West
            if (!mazeFlag)
                mazeFlag = solveMaze(maze, row, col - 1, startRowIndex, startColIndex, finishRow, finishCol);

            if (mazeFlag) {
                return mazeFlag;
            } else {
                maze[row][col] = '.';
            }
        }
        return false;
    }
}
