public class Minimax {
    public static int minimax(Position position, int depth, boolean minimizingPlayer) {
        if (depth == 0 || position.isGameOver()) {
            return position.evaluate();
        }

        if (!minimizingPlayer) {
            int maxEval = Integer.MIN_VALUE;
            for (Position child : position.getChildren()) {
                int eval = minimax(child, depth - 1, true);
                maxEval = Math.max(maxEval, eval);
            }
            return maxEval;
        } else {
            int minEval = Integer.MAX_VALUE;
            for (Position child : position.getChildren()) {
                int eval = minimax(child, depth - 1, false);
                minEval = Math.min(minEval, eval);
            }
            return minEval;
        }
    }

    public static int minimax(Position position, int depth, int alpha, int beta, boolean minimizingPlayer) {
        if (depth == 0 || position.isGameOver()) {
            return position.evaluate();
        }

        if (!minimizingPlayer) {
            int maxEval = Integer.MIN_VALUE;
            for (Position child : position.getChildren()) {
                int eval = minimax(child, depth - 1, alpha, beta, true);
                maxEval = Math.max(maxEval, eval);
                alpha = Math.max(alpha, eval);
                if (beta <= alpha) {
                    break;
                }
            }
            return maxEval;
        } else {
            int minEval = Integer.MAX_VALUE;
            for (Position child : position.getChildren()) {
                int eval = minimax(child, depth - 1, alpha, beta, false);
                minEval = Math.min(minEval, eval);
                beta = Math.min(beta, eval);
                if (beta <= alpha) {
                    break;
                }
            }
            return minEval;
        }
    }
}