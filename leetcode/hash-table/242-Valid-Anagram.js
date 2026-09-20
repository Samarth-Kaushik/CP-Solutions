/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    let count1 = new Array(26).fill(0)
    let count2 = new Array(26).fill(0)
    let n1 = s.length;
    let n2 = t.length;
    if(n1 != n2) return false;
    for(let i = 0; i < n1; i++){
        count1[s.charCodeAt(i) - 97]++;
        count2[t.charCodeAt(i) - 97]++;
    }
    for(let i = 0; i < 26; i++){
        if(count1[i] != count2[i]) return false;
    }
    return true;
};