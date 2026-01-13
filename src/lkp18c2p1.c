/**
 * https://dmoj.ca/problem/lkp18c2p1
 */

#include "lkp18c2p1.h"
#include "type.h"
/**
 * @brief находит самую короткую очередь
 * retval индекс очереди с наименьшим количеством людей
 */
int shortest_index(int lines[], int n) {
  int shortest = 0;
  int i;

  for (i = 0; i < n; i++) {
    if (lines[i] < lines[shortest])
      shortest = i;
  }
  return shortest;
}

/**
 * @brief решает задачу с очередями в магазине
 * @param lines исходные данные
 * @param n количество очередей
 * @param m количество людей
 */
void solve_lines(int lines[], int n, int m) {
  int i, shortest;
  for (i = 0; i < m; i++) {
    shortest = shortest_index(lines, n);
    lines[shortest] += 1;
    LOG(% d, ++shortest);
  }
  // lines[shortest]-=1;
  LOG(Ответ[% d % d % d...] % d, lines[0], lines[1], lines[2], shortest + 1);
}
