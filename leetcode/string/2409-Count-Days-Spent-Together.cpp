class Solution {
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dateToDays(string date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int totalDays = 0;
        for (int i = 0; i < month - 1; i++) {
            totalDays += daysInMonth[i];
        }
        return totalDays + day;
    }
    
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startA = dateToDays(arriveAlice);
        int endA = dateToDays(leaveAlice);
        int startB = dateToDays(arriveBob);
        int endB = dateToDays(leaveBob);
        int overlapStart = max(startA, startB);
        int overlapEnd = min(endA, endB);
        return max(0, overlapEnd - overlapStart + 1);
    }
};