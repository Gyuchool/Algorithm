import java.util.*;

class Main {
    public static void main(String[] args) {
        int result = 0;
        Scanner scanner = new Scanner(System.in);
        Map<Integer, Integer> board = new LinkedHashMap<>();
        Map<Integer, Integer> reverse = new LinkedHashMap<>();
        for (int i = 0; i < 25; i++) {
            int value = scanner.nextInt();
            board.put(i, value);
            reverse.put(value, i);
        }

        List<Integer> answer = new ArrayList<>();
        for (int i = 0; i < 25; i++) {
            answer.add(scanner.nextInt());
        }
        for (int i = 0; i < answer.size(); i++) {
            Integer ans = answer.get(i);
            if (board.containsValue(ans)) {
                board.put(reverse.get(ans), 0);
            }
            int value = horizontalCal(board) + verticalCal(board) + diagonalCal(board);
            if (3 <= value) {
                result = i + 1;
                break;
            }
        }
        System.out.println(result);
    }

    private static int diagonalCal(Map<Integer, Integer> board) {
        int total = 0;
        if (board.get(0) + board.get(6) + board.get(12) + board.get(18) + board.get(24) == 0) {
            total++;
        }
        if (board.get(4) + board.get(8) + board.get(12) + board.get(16) + board.get(20) == 0) {
            total++;
        }
        return total;
    }

    private static int verticalCal(Map<Integer, Integer> board) {
        int total = 0;
        total = getVertical(0, board, total);
        total = getVertical(1, board, total);
        total = getVertical(2, board, total);
        total = getVertical(3, board, total);
        total = getVertical(4, board, total);
        return total;
    }

    private static int getVertical(int k, Map<Integer, Integer> board, int total) {
        int sum = 0;
        for (int i = k; i <= 20 + k; i += 5) {
            sum += board.get(i);
        }
        if (sum == 0) {
            total++;
        }
        return total;
    }

    private static int horizontalCal(Map<Integer, Integer> board) {

        int total = 0;
        total = getHorizontal(0, board, total);
        total = getHorizontal(5, board, total);
        total = getHorizontal(10, board, total);
        total = getHorizontal(15, board, total);
        total = getHorizontal(20, board, total);
        return total;
    }

    private static int getHorizontal(int k, Map<Integer, Integer> board, int total) {
        int sum = 0;
        for (int i = k; i < 5 + k; i++) {
            sum += board.get(i);
        }
        if (sum == 0) {
            total++;
        }
        return total;
    }
}
