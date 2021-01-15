// 766. Toeplitz Matrix
// https://leetcode.com/problems/toeplitz-matrix/

function isToeplitzMatrix(matrix: number[][]): boolean {
    const m = matrix.length;
    const n = matrix[0].length;
    for (let i = 1; i < m; i++) {
        let first = matrix[m - 1 - i][0];
        for (let j = 1; j < Math.min(i + 1, m, n); j++)
            if (matrix[m - 1 - i + j][j] !== first) return false;
    }
    for (let i = 1; i < n - 1; i++) {
        let first = matrix[0][n - 1 - i];
        for (let j = 0; j < Math.min(i + 1, m, n); j++)
            if (matrix[j][n - 1 - i + j] !== first) return false;
    }
    return true;
};

console.log(isToeplitzMatrix([[1,2,3,4],[5,1,2,3],[9,5,1,2]]))
console.log(isToeplitzMatrix([[1]]))
console.log(isToeplitzMatrix([[1, 2], [2, 2]]))
console.log(isToeplitzMatrix([[1, 2], [2, 1]]))
