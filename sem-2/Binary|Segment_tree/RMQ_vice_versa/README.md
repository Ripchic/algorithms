Пусть нам дан массив . Определим RMQ(i, j) как минимальное значение ak для k ∈ [i, j]. Вам даны некоторые запросы RMQ(i, j) и ответы на них, восстановите исходный массив ai.
Формат ввода

В первой строке входных данных записаны два числа n и m (1 ≤ n, m ≤ 100 000) — длина массива и количество запросов, для которых известны ответы, соответственно.
Далее следуют m строк, описывающих запросы. Каждая строка содержит три целых числа i, j и q (1 ≤ i ≤ j ≤ n, -231 ≤ q ≤ 231-1), означающих что RMQ(i, j) = q.
Формат вывода

Если подходящего массива не существует, то выведите «inconsistent» в единственной строке выходных данных.
В противном случае, в первой строке выходных данных должно быть записано слово «consistent». Во второй строке выведите соответствующий массив ai (-231 ≤ ai ≤ 231-1) длины n. Если правильных решений несколько, то разрешается вывести любое.