package 숫자야구;

import java.lang.String;

class Solution {
    public int solution(int[][] baseball) {
        int answer = 0;
        int number_size = baseball.length;
        for(int i = 123; i <= 987; i ++){
            int hundred = i / 100;
            int ten = (i / 10) % 10;
            int one =  i % 10;

            if((hundred == ten) || (hundred == one) || (ten == one))
                continue;

            if((hundred == 0) || (ten == 0) || (one == 0))
                continue;
            
            for(int j = 0 ; j < number_size; j++){
                int strike = 0;
                int ball = 0;
                int number = baseball[j][0];
                int number_h = number / 100;
                int number_t = (number / 10) % 10;
                int number_o = number  % 10;

                if(number_h == hundred) strike ++;
                if(number_t == ten) strike++;
                if(number_o == one) strike++;
                if(strike != baseball[j][1])
                    break;

                if((number_h == ten) || (number_h == one)) ball++;
                if((number_t == hundred) || (number_t == one)) ball++;
                if((number_o == hundred) || (number_o == ten)) ball++;
                if(ball != baseball[j][2])
                    break;

                if(j == number_size -1) answer++;
            }
        }

        return answer;
    }
    public static void main(String args[]) {
        int[][] Problem = {
            {123, 1, 1}, 
            {356, 1, 0}, 
            {327, 2, 0}, 
            {489, 0, 1}
        };
        Solution problem = new Solution();
        int result = problem.solution(Problem);
        System.out.println(Integer.toString(result));
    }
}