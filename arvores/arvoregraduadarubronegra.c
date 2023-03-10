// Em arvore binária de busca, os nós externos servem para indicar
// faixa de valores que representam "fracasso" na busca.

// Todo nó é rubro ou negro
// A raíz da árvore é sempre negra
// Todo nó nulo tem cor negra
// O pai de um nó rubro é sempre negro
// Qualquer caminho de um nó até um nó nulo tem sempre o mesmo numero de nós negros

// Diferença entre arvore avl e avr rubro negra
// Ambas possuem complexidade logaritmica
// Na avl a altura só pode ser até 1
// Na rubro negra pode ser até o dobro da altura da sua irmã
// Na avl a diferença das alturas das subarvores irmas é o fator de balanceamento dos nos
// Na rubro negra o fator de balanceamento é feito pelas cores dos nós

