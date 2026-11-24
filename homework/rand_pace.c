#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 10

int main() {
    char grid[SIZE][SIZE];
    int i, j;

    // 1. 初始化数组
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = '.';
        }
    }

    // 2. 随机数种子
    srand(time(NULL));

    // 3. 初始位置（A 的位置）
    int row = 0, col = 0;
    grid[row][col] = 'A';
    char current_letter = 'A';

    // 4. 方向数组：上、下、左、右
    int dr[] = {-1, 1, 0, 0}; // 行变化
    int dc[] = {0, 0, -1, 1}; // 列变化

    // 5. 开始随机步法（从 B 到 Z）
    for (int step = 1; step < 26; step++) {
        current_letter++; // 下一个字母
        bool moved = false;
        int directions[4] = {0, 1, 2, 3}; // 四个方向索引

        // 打乱方向顺序，实现随机尝试
        for (int k = 0; k < 4; k++) {
            int r = rand() % (4 - k) + k; // 从 k 到 3 中随机选一个
            // 交换
            int temp = directions[k];
            directions[k] = directions[r];
            directions[r] = temp;
        }

        // 按随机顺序尝试四个方向
        for (int k = 0; k < 4; k++) {
            int dir = directions[k];
            int next_row = row + dr[dir];
            int next_col = col + dc[dir];

            // 检查边界
            if (next_row >= 0 && next_row < SIZE && next_col >= 0 && next_col < SIZE) {
                // 检查是否已访问
                if (grid[next_row][next_col] == '.') {
                    row = next_row;
                    col = next_col;
                    grid[row][col] = current_letter;
                    moved = true;
                    break; // 找到合法方向，跳出
                }
            }
        }

        if (moved==0) {
            // 四个方向都堵住了，提前结束
            break;
        }
    }

    // 6. 输出结果
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}