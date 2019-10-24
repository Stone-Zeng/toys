/**
 * 58. Length of Last Word
 * https://leetcode.com/problems/length-of-last-word/
 */

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    var x = s.trim();
    for (var i = 0; i < x.length; i++) {
        if (x[x.length - i - 1] === " ") return i;
    }
    return x.length;

    // A naive way.
    // var x = s.trim().split(/\W+/);
    // return x[x.length - 1].length;
};

console.log(lengthOfLastWord("Hello World"));
console.log(lengthOfLastWord("Hello   World"));
console.log(lengthOfLastWord("Hello World  "));
console.log(lengthOfLastWord("HelloWorld"));
console.log(lengthOfLastWord("  s s s"));
console.log(lengthOfLastWord(""));
