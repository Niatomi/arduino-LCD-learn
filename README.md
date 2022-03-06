# Arduino LCD learn

1. Подключение LCD к плате arduinoUNO установка библиотеки.

   - Написать скетч программы для вывода на экран 2 строк. На первой «Первое подключение», на вторую «LCD k arduino». Посмотреть результаты вывода на экран.
   - Исправить на вариант который будет правильно отображаться на экране.

2. Вывод своих символов на LCD
   Вывод на экран 1 строки из 1 задания с помощью создания своих символов (букв русской раскладки). Для этого нам потребуется использовать в скетче переменную `byte` и функцию
   `lcd.createChar()`.<br/>
   Пример создания символа заглавной буквы П:

   ```c++
   byte P1[8] =
   {
   B 11111,
   B 10001,
   B 10001,
   B 10001,
   B 10001,
   B 10001,
   B 10001,
   B 00000,
   };
   ```

Бегущая строка на LCD
Модернизировать код из 2 задания, в связи с тем что на первой строке не умещаются слова, сделать бегущую строку двумя способами:

3. С помощью встроенной функции `LCD.scrollDisplayLeft()` или `LCD.scrollDisplayRight()`

4. С помощью цикла `for( ; ; )`, только для первой строки, т.к. в первом варианте с помощью встроенной функции перемещаются обе строки, а нужно только 1.

5. Подключение кнопки и потенциометра к LCD
   Подключить к 1 заданию потенциометр и кнопку, на 1 строку экрана выводить информацию нажата ли кнопка, а на 2 значение с потенциометра в вольтах, значение 1023 с потенциометра соответствует 5 В.

6. Вывод значения потенциометра на LCD в виде гистограммы
   Сделать гистограмму значения напряжения на экране. Для этого потребуется свои символы в виде строк заполнения 1 ячейки LCD. Провести три варианта работы:

   - Вывод значения в виде гистограммы на первый столбец обеих строк.
   - Вывод значения в виде гистограммы на все столбцы экрана синхронно.
   - Вывод значения напряжения на потенциометре последовательно на столбцы, то есть заполненные все 16 столбцов это 5 В, а 8 столбцов это 2.5 В

7. Подключение светофора из 1 лабораторной работы.
   Подключение экрана к 7Б заданию из 1 лабораторной работы, на 1 строку экрана выводить на первую строку надпись соответствующую цвету: Стой! , Приготовься! , Можно ехать. На вторую строку экрана выводить значение оставшихся секунд зеленого и красного света.
