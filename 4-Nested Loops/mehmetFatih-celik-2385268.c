//Name: Mehmet Fatih Celik
//ID: 2385268

#include <stdio.h>

int main(){
	int p1_match=0, p2_match=0, match_counter=1, p1_set_score, p2_set_score, i, p1_set=0, p2_set=0;
	printf("Tennis Championship!\n");
	while(p1_match<=2 && p2_match<=2){
		printf("Match %d starts!\n",match_counter);
		for(i=1;i<=3;i++){
			printf("Enter set %d score of player 1: ",i);
			scanf("%d",&p1_set_score);
			printf("Enter set %d score of player 2: ",i);
			scanf("%d",&p2_set_score);
			if (p1_set_score>p2_set_score){
				printf("Player 1 wins set %d\n",i);
				p1_set++;
			}
			else{
				printf("Player 2 wins set %d\n",i);
				p2_set++;
			}
		}
		if (p1_set>p2_set){
			printf("Player 1 is the winner of match %d\n\n",match_counter);
			p1_match++;
		}

		else{
			printf("Player 2 is the winner of match %d\n\n",match_counter);
			p2_match++;
		}
		p1_set= 0;
		p2_set= 0;
		match_counter++;
	}
	
	if(p2_match>p1_match)
		printf("At the end of 5 matches, Player 2 is the champion!");
	else
		printf("At the end of 5 matches, Player 1 is the champion!");
	
	return 0;
}
