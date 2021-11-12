## Week 6 :  Implementation of Recursive Descent Parser

#### 1. Implementing Recursive Descent Parser for the Expression Grammar given below:

E → TE’         \
E’→ +TE’ | ε    \
T → FT’         \
T’→ *FT’ | ε    \
F → (E)  | i    

<br>

##### Testcase 1

<img src="RDP_1_test1.png" alt="RDP_1_test1" width="70%"/>

##### Testcase 2

<img src="RDP_1_test2.png" alt="RDP_1_test2" width="70%"/>

##### Testcase 3

<img src="RDP_1_test3.png" alt="RDP_1_test3" width="70%"/>

##### Testcase 4

<img src="RDP_1_test4.png" alt="RDP_1_test4" width="70%"/>

##### Testcase 5

<img src="RDP_1_test5.png" alt="RDP_1_test5" width="70%"/>


--------------------------------------

<br>

#### 2. Constructing Recursive Descent Parser for the Grammar given below:

S → (L) | a     \
L → L,S | S

##### CFG With Left Recursions removed:

S → (L) | a     \
L → SL'         \
L'→ ,SL' | ε

<br>

##### Testcase 1

<img src="RDP_2_test1.png" alt="RDP_2_test1" width="70%"/>

##### Testcase 2

<img src="RDP_2_test2.png" alt="RDP_2_test2" width="70%"/>
