## Description of DFAs

#### 1. Finite Automata that accepts strings containing even number of occurrences of each alphabet

Acceptable strings in the language: \
L = {ε, "aa", "bb", "abba", ... , "babbab", ...}

M = (Q,∑,δ,Q<sub>0</sub>,F)

Where:\
Q = {q<sub>0</sub>, q<sub>1</sub>, q<sub>2</sub>, q<sub>3</sub>} \
∑ = {a, b} \
Q<sub>0</sub> = q<sub>0</sub> \
F = {q<sub>0</sub>}

<img src="https://user-images.githubusercontent.com/88186541/127736063-055ee2b0-6348-4df6-962e-9c1d23a8eebd.png" width="40%"/>

---

#### 2. Finite Automata that accepts strings ending with same two alphabets

Acceptable strings in the language:\
L = {"aa", "bb", "aaa", "bbb", "abb", "baa", ... , "ababaa", "baababb", ...}

M = (Q,∑,δ,Q<sub>0</sub>,F)

Where:\
Q = {q<sub>0</sub>, q<sub>1</sub>, q<sub>2</sub>, q<sub>3</sub>, q<sub>4</sub>} \
∑ = {a, b} \
Q<sub>0</sub> = q<sub>0</sub> \
F = {q<sub>3</sub>, q<sub>4</sub>}

<img src="https://user-images.githubusercontent.com/88186541/127735976-08474dc8-7e34-484a-8f43-a96aeebb8804.png" alt="dfa2-transition-diagram" width="55%"/>
