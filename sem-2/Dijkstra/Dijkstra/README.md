Дан ориентированный взвешенный граф. Найдите кратчайшее расстояние от одной заданной вершины до другой.
Формат ввода

В первой строке содержатся три числа: N, S и F (1≤ N≤ 100, 1≤ S, F≤ N), где N – количество вершин графа, S – начальная вершина, а F – конечная. В следующих N строках вводится по N чисел, не превосходящих 100, – матрица смежности графа, где -1 означает отсутствие ребра между вершинами, а любое неотрицательное число – присутствие ребра данного веса. На главной диагонали матрицы записаны нули.
Формат вывода

Требуется вывести искомое расстояние или -1, если пути между указанными вершинами не существует.