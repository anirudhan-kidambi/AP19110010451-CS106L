## Week 7 : Implementation of LL(1) Parser

#### 1. Implementing Non-recursive Predictive Parser for the grammar:

S -> aBa        \
B -> bB | ε

<br>

##### Testcase 1

<img src="output/LL(1)_1_test1.png" alt="LL(1)_1_test1" width="50%"/>

##### Testcase 2

<img src="output/LL(1)_1_test2.png" alt="LL(1)_1_test2" width="50%"/>


--------------------------------------

<br>

#### 2. Implementing Non-recursive Predictive Parser for the Expression Grammar:

E → TE’         \
E’→ +TE’ | ε    \
T → FT’         \
T’→ *FT’ | ε    \
F → (E)  | d

<br>

##### Testcase 1

<img src="output/LL(1)_2_test1.png" alt="LL(1)_2_test1" width="50%"/>

##### Testcase 2

<img src="output/LL(1)_2_test2.png" alt="LL(1)_2_test2" width="50%"/>
