#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define height 20
#define width 40
#define border '!'
#define gap ' '
#define deamon '&'
#define foodee  'o'
char board[height][width];
int pacman_x=0,pacman_y=0;
int food=0;
int curr=0;
int res=0;
int score=0;
char pacman='<';

void setup(){
	                         	 
	                           
	                              //outer border of the board
	
										for( int i=0;i<height;i++){
															for(int j=0;j<width;j++){
																				if(i==0||j==0||i==height-1||j==width-1)
																				  board[i][j]=border;
																				else
																					board[i][j]=gap;

															}
										}
										
	
	//printf("%c ",board[pacman_x][pacman_y]);
										
							//inside rand walls
								
								int count=20;
								while(count){
										int i=  rand()% (height+1);
									    int j=   rand()%(width+1);
								
								        if(board[i][j]!=border&&board[i][j]!=pacman){
	                                      board[i][j]=border;
	                                      count--;								        
								        }
								}	
								
								
								int val=10;
								while(val){
									 int row=rand()%(height+1);
									 for(int j=3;j<width-3;j++){
															if(board[row][j]!=border&&board[row][j]!=pacman){
															board[row][j]	= border;
															
															}									 
									 }
									 val--;
								}
								
				 count=20;
								while(count){
										int i=  rand()% (height+1);
									    int j=   rand()%(width+1);
								
								        if(board[i][j]!=border&&board[i][j]!=pacman){
	                                      board[i][j]=deamon;
	                                      						        
								        }
								        count--;		
								}			
							
						//pacman entered	
						
	
	//enter the food of pacman
	
	for(int i=0;i<height;i++){
				for(int j=0;j<width;j++){
				if(i % 2 == 0 && j % 2 == 0 &&board[i][j]!=border&&board[i][j]!=pacman&&board[i][j]!=deamon){
				board[i][j]=foodee;	
				food++;
				}	
				}	
	}		
	                    pacman_x=height/2;
	                    pacman_y=width/2;
	                    board[pacman_x][pacman_y]=pacman;
	
	
}


void draw(){
system("cls");
for(int i=0;i<height;i++){
	for(int j=0;j<width;j++){
	printf("%c",board[i][j]);	
	}
	printf("\n");
}
printf("Score :%d\n",score);
}


void move(int move_x,int move_y){
  
  int x=pacman_x+move_x;
  int y=pacman_y+move_y;
  if(board[x][y]!=border){
	if(board[x][y]==foodee){ 
	score++;	
	food--;
	curr++;
	if(food==0){
         	res=2;	
	         return ;
	     }
	} else if(board[x][y]==deamon){
		res=1;
	}
  
  board[pacman_x][pacman_y]=gap;
  pacman_x=x;
  pacman_y=y;
  board[pacman_x][pacman_y]=pacman;

  }


}
int main(){
char ch;
setup();
int totalfood=food;
printf("instructions  :   \n");
printf("use buttons as u(up),l(left),r(right) ,d(down)\n ");
printf("if want to quit to q\n");
printf("enter y to start......");
ch=getch();
if(ch!='y'&&ch!='Y'){
	printf("Exit game");
	return 1;
}

while(1){

               draw();
               printf("total found count :  %d\n",totalfood);
               printf("total food eaten   :    %d\n",curr);
               
               if(res==1){
	                       system("cls");   
	                       printf("game over!  dead by deamon your Score:  %d\n",score);
	                       return 1;            
               }
                if(res==2){
	                       system("cls");   
	                       printf("you win! your Score:  %d\n",score);
	                       return 1;            
               }
               ch=getch();
               
               switch(ch){
		          case 'u':{
		          	pacman='v';
		          	move(-1,0);
		          }
		          	break;
		          	case 'd':
		          		pacman=(char)94;
		          	move(1,0);
		          	break;
		          	case 'l':{
		          		pacman='>';
		          	move(0,-1);
		          	
		          	}
		          	break;
		          	case 'r':{
		          		pacman='<';
		          	move(0,1);
		          	}
		          	break;
			        case 'q':
	                          printf("game over! your score: %d\n",score);
	                          return 0;					
			   }
               
               
}



return 0;
}