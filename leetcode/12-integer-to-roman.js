/**
 * 12. Integer to Roman
 * https://leetcode.com/problems/integer-to-roman/
 */

/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    var n1 = num % 10,
        n2 = (num % 100 - n1) / 10,
        n3 = (num % 1000 - n1 - n2 * 10) / 100,
        n4 = ~~(num / 1000);
    return "M".repeat(n4) +
           ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"][n3] +
           ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"][n2] +
           ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"][n1];
};

for (var i = 1; i < 4000; i++) {
    console.log(i + "\t" + intToRoman(i));
}
