Напишите программу, которая будет содержать реализацию структуры данных для совокупности непересекающихся подмножеств (disjoint sets) и обрабатывать запросы таких видов:
RESET n — создать новую серию подмножеств: множество из одного только элемента 0, из одного только элемента 1, и так до множества из одного только элемента n–1 включительно. Если структура уже содержала какую-то другую совокупность непересекающихся подмножеств, вся соответствующая информация утрачивается. На стандартный выход (экран) при этом следует вывести два слова через пробел «RESET DONE».
JOIN j k — объединить подмножества, которым принадлежат элемент j и элемент k. Если элементы и так принадлежали одному подмножеству, вывести на стандартный выход (экран) слово «ALREADY», после него через пробелы те же числа j и k в том же порядке. Если элементы до сих пор принадлежали разным подмножествам, то действие происходит только с данными в памяти, на экран ничего не выводится.
CHECK j k — проверить, одному ли подмножеству принадлежат элемент j и элемент k; вывести на стандартный выход (экран) слово «YES» (если одному) или слово «NO» (если разным).
Формат ввода

Во входных данных содержится последовательность запросов RESET, JOIN и CHECK — каждый в отдельной строке, согласно вышеописанному формату. Гарантированно, что первая строка содержит запрос RESET, а общее количество запросов RESET не превышает 5. Общее количество всех запросов не превышает 200000. Значение n в каждом запросе RESET не превышает 100000. В каждом запросе JOIN и в каждом запросе CHECK оба числа будут в диапазоне от 0 до n–1, где n — параметр последнего выполненного запроса RESET.
Формат вывода

Для запросов RESET, CHECK и тех запросов JOIN, где элементы и так принадлежат одному подмножеству, выводить на стандартный выход (экран) соответствующий результат (в отдельной строке).
