// 223. Rectangle Area
// https://leetcode.com/problems/rectangle-area/

class Solution {
    func computeArea(_ A: Int, _ B: Int, _ C: Int, _ D: Int, _ E: Int, _ F: Int, _ G: Int, _ H: Int) -> Int {
        let AC = C - A, BD = D - B, EG = G - E, FH = H - F
        let total = AC * BD + EG * FH
        let xIntersection = max(0, AC + EG - max(AC, EG, abs(G - A), abs(C - E)))
        let yIntersection = max(0, BD + FH - max(BD, FH, abs(H - B), abs(D - F)))
        print(xIntersection, yIntersection)
        return total - xIntersection * yIntersection
    }
}

print(Solution().computeArea(-3, 0, 3, 4, 0, -1, 9, 2))
print(Solution().computeArea(-2, -2, 2, 2, 3, 3, 4, 4))
