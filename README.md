Распределенное приложение, включающее клиентскую и серверную части, взаимодействующие посредством сетевого обмена сообщениями.  
Клиентские и серверные части представляют собой приложения, реализующие интерфейс для матрицы.
Клиентская часть модифицируется таким образом, что реализованные функции матриц могут исполняться по желанию пользователя на областях определения: вещественная комплексная и рациональная.  
# Класс  TMatrix  
## Атрибуты:  
matrix – переменная для хранения матрицы.  
sizex	– переменная для хранения количества строк матрицы.  
sizey	– переменная для хранения количества строк матрицы.  

## Методы:  
TMatrix() – конструктор класса.  
TMatrix(vector<vector<number>>) – конструктор класса.  
TMatrix(QByteArray) – конструктор класса.  
transpose() – транспонирует матрицу.  
count_underscores(string s, char ch) – считает количество заданных символов в строке   
operator<< - оператор вывода  
operator<< - оператор вывода  
Тип возвращаемого значения: ostream  
operator>> - оператор ввода  

# Класс STMatrix
## Атрибуты:
size – переменная для хранения размера матрицы.   
rank – переменная для хранения ранга матрицы.  
det – переменная для хранения определителя матрицы.  
## Методы: 
STMatrix() – конструктор класса.  
GetDet() – возвращает определитель матрицы.  
GetRank() – возвращает ранг матрицы.  
GaussElim() –  метод Гаусса для вычисления определителя  
## Перегруженные операторы:  
operator<< - оператор вывода  
operator>> - оператор ввода  


# Класс Trational  
## Атрибуты:  
num – переменная для хранения числителя.  
denom – переменная для хранения знаменателя.   
## Методы:
Trational() – конструктор класса.  
Trational() – конструктор класса по умолчанию.  
Trational() – конструктор класса.  
Trational() – конструктор копирования класса.  
## Перегруженные операторы:  
operator<< - оператор вывода  
operator>> - оператор ввода   
operator+  - оператор сложения  
operator-  - оператор вычитания  
operator*  - оператор умножения  
operator/  - оператор деления  
operator=  - оператор присваивания  
operator=  - оператор присваивания
operator+=  - оператор сложения с присваиванием  
operator-  - оператор перевода в отрицательное число  
operator*=  - оператор умножения с присваиванием  
operator==  - двоичный оператор равно  
operator!=  - двоичный оператор равно  

# Класс TComplex  
## Атрибуты:   
real – переменная для хранения действительной части числа.  
image – переменная для хранения мнимой части числа.   

# Клиентская часть    
# Класс MainWindow   
## Атрибуты:  
*rat, *doub, *comp   
Тип: QRadioButton    
*n_l, *output_l    
Тип: QLabel  
*n_v  
Тип: QLineEdit    
Область видимости: private
*tempBut, *readBut, *detBut, *rankBut,  *transBut– виджеты-командные кнопки для запуска функций.  
Тип: QPushButton  
Область видимости: private  
*output – виджеты для отображения результата выполнения команд.   
Тип: QLabel  
Область видимости: private  
## Слоты:   
answer (QString) – слот получения ответа серверного приложения и вывода ответа в виджет для отображения результата.   
Тип возвращаемого значения: не возвращает значения  
Параметры на входе: QString   
Область видимости: public  
formRequest () – слот для отправки данных на серверное приложение.   
Тип возвращаемого значения: не возвращает значения  
Параметры на входе: не принимает значений  
Область видимости: private  
makeTemplate() –Создает шаблон матрицы для заполнения клиентом.  
Тип возвращаемого значения: не возвращает значения  
Параметры на входе: не принимает значений  
Область видимости: private  

