```js
function minimax(position, depth, minimizingPlayer)
    if depth == 0 or game over in position
        return static evaluation of position
    
    if maximizingPlayer
        maxEval = -infinity
        for each child of position
            eval = minimax(child, depth - 1, false)
            maxEval = max(maxEval, eval)
        
        return maxEval
    else
        minEval = +infinity
        for each child of position
            eval = minimax(child, depth - 1, true)
            maxEval = max(maxEval, eval)
        
        return maxEval

function minimax(position, depth, alpha, beta, minimizingPlayer)
    if depth == 0 or game over in position
        return static evaluation of position
    
    if maximizingPlayer
        maxEval = -infinity
        for each child of position
            eval = minimax(child, depth - 1, alpha, beta, false)
            maxEval = max(maxEval, eval)
            alpha = max(alpha, eval)
            if beta <= alpha
                break
        return maxEval
    else
        minEval = +infinity
        for each child of position
            eval = minimax(child, depth - 1, alpha, beta, true)
            maxEval = min(maxEval, eval)
            alpha = min(alpha, eval)
            if beta <= alpha
                break
        
        return maxEval
```