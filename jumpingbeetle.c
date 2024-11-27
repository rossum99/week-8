#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Position;

Position find_final_position(int M, long long A, long long B, Position board[M][M], Position start) {
    long long total_moves = A * B;  // Total number of moves the beetle will make
    Position current = start;
    Position visited[M][M];  
    int visited_count[M][M]; 

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            visited_count[i][j] = 0;
        }
    }

    while (total_moves > 0) {
       
        current = board[current.x][current.y];
        total_moves--;

        if (visited_count[current.x][current.y] > 0) {
            break;  
        } else {
            visited_count[current.x][current.y]++;
        }
    }
    return current;
}

int main() {
    int M;
    long long A, B;
    scanf("%d,%lld,%lld", &M, &A, &B);

    Position board[M][M];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            int x, y;
            scanf("%d,%d", &x, &y);
            board[i][j].x = x - 1;  
            board[i][j].y = y - 1; 
        }
    }

    Position start;
    scanf("%d,%d", &start.x, &start.y);
    start.x -= 1;  
    start.y -= 1;  

    Position final_position = find_final_position(M, A, B, board, start);

    printf("%d,%d\n", final_position.x + 1, final_position.y + 1);

    return 0;
}
