# �������� ������� �� �������� Intern C++ Programmer


## ������� 1


<details>
  <summary>������� �������</summary>

�� ����� �/�++, �������� �������� (�������) ����������� �������� ������ �����, ������� ����� ���������� ���������������� �� ����������������, �� ������� �� ����� ����.

��������� ����� � ������ ����� ����������.

C/C++ example:

bool isEven(int value){return value%2==0;}

</details>

1. �������� ���: [������](https://github.com/Razred/Lesta_Game_test_task/blob/master/src/Task_1/IsEven.cpp)



**���������**

������� ������������ �������� �� ����� ������.
������ ������� ������������� ����� ��������� ���������� ���� ����� � ��������,
��� ��� ������ � �������� ����� ��������� ��� ����� ���� ����� 1.

**���������**

1. ```cpp
   bool isEven(int value)
   {
      return value % 2 == 0;
   }
   ```

2. ```cpp
   bool IsEven(int value) 
   {
      return (value & 1) == 0;
   }
   ```

���� ���������� ��� ������� � ��������:
isEven(int value){return value%2==0;}
� ������ ��� ������� ������ �������� �������, ��� ��� ��� ��������� ����� ���� �������� ��������,
��� � ������������� ���������� ������ �������� �������.
�� �� ���� ���� ������������, ��� ���������� �����������  ��� ��� ������� � ����������� ����,
� �� ����� ������� �������.


## ������� 2

<details>
  <summary>������� �������</summary>

�� ����� �++, �������� ������� �� 2 ������ ��������������� ����������� �����.

��������� ����� � ������ ������ ����������.

</details>

� ���������� ��� �������� ������������ ������, ���� �������� �� ����������� �������, � ������ � ������� �������� ������.

**���������**
��� ��� ��� ���������� �������� ������������ ��������, �� ������ � ��������� ���������� �� O(1) �� �������.

����� ������������ �������� ������ ���������, ���� � �� �������. � ��������� �������� ������������ ��������� ���������� �� 4 �� 8 ���� � ����������� �� �������.

**����������**

1. �������� ���: ����������� ����� �� ������� [������](https://github.com/Razred/Lesta_Game_test_task/blob/master/src/Task_2/https://github.com/Razred/Lesta_Game_test_task/blob/master/src/Task_2/circle_buffer_array.h)
2. �������� ���: ����������� ����� �� ������� ������ [������](https://github.com/Razred/Lesta_Game_test_task/blob/master/src/Task_2/circle_buffer_list.h)



## ������� 3

<details>
  <summary>������� �������</summary>

�� ����� �/�++, �������� �������, ������� ������� ����� (�� ������������ �����) ����������� ������ �� ������ �����.

������ ����� ���� ������ ������� �� ��������� �������� ����� (� ��� ����� � ���������������).

��������� ������ �� ��������, ��� ������� ������������� �������� ���������.

</details>

**�����������**

����� ��������� ����������, ������� ����� �������� ����������� �� ������������ �����, ������� �� ��������� ��������, ����� ��� ������ �������, ������������� ������ � ����������� ����������. ������, ���� ������������, ��� � ������� �������� ����� �� ����� ������� ���������� ����� ������� ����������.

� ���������� ������� ���������� ��� ������� �� STL.

**������� ���������**
� ������� ������� ���������� ����� ��������� ��������� O(n log n)

**�� ������** 
������� ���������� �� ������� �������������� ������, ����� ���������� ����� ��������.
������ O(1) �� ������

**�����**
������� ���������� ����� ���� ������������ � ������ �������� ���������� �������� ��������. �� ��� ����� �������� ��������� ��������� ��������� ������, ����� ��� ������� ���� ��� ��������� �����.
����� ����, ��� ����� ��������� �������� ����� ���� ����� ���������� ���������� ���������.

���:

1. �������� ���: [������](https://github.com/Razred/Lesta_Game_test_task/blob/master/src/Task_2/https://github.com/Razred/Lesta_Game_test_task/blob/master/src/Task_3/Quick_sort.h)
