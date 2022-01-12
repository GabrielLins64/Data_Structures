<h1>Árvores</h1>

---

<h2>Índice</h2>

- [Árvore](#árvore)
  - [Definições básicas](#definições-básicas)
  - [Árvore binária](#árvore-binária)
  - [Árvore AVL](#árvore-avl)
  - [Árvore Rubro-Negra](#árvore-rubro-negra)

---

## Árvore

Uma árvore é uma [estrutura de dados](## "Uma estrutura de dados é uma coleção tanto de valores (e seus relacionamentos) quanto de operações (sobre os valores e estruturas decorrentes).") com um valor raiz e subárvores filhas com um nó pai.

Uma árvore pode ser definida recursivamente como uma coleção de nós, onde cada nó é uma estrutura de dados que consiste em um valor e uma lista de referências a nós.

<center>

![Tree](assets/tree.jpg)

</center>

### Definições básicas

**Árvore (Grafo)**: Um grafo conexo acíclico.

**Raiz**: O início da árvore é o "nó raiz". O que está no topo da árvore e pode dar origem a todos os outros nós.

**Nó folha (externo)**: Nó não-raiz que não possui nenhum outro filho (grau 0).

**Profundidade de um nó**: é a distância deste nó até a raiz.

**Nível**: Um conjunto de nós com a mesma profundidade é denominado **nível** da árvore. Sendo 0 o nível da raiz.

**Altura de uma árvore**: O maior dos níveis de seus nós externos (folhas). Ex.: Na árvore da imagem acima é 3.

**Árvore balanceada**: Uma árvore é considerada balanceada se, para qualquer nó, a altura de suas duas subárvores diferem de, no máximo, uma unidade.

---

### Árvore binária

Uma árvore binária é uma árvore caracterizada por:

- Ou não tem elemento algum (árvore vazia).
- Ou tem um elemento distinto, denominado raiz, com dois ponteiros para duas estruturas diferentes, denominadas subárvore esquerda e subárvore direita.

Os nós de uma árvore binária possuem graus zero, um ou dois. Um nó de grau zero é denominado folha.

> Em uma árvore binária, por definição, cada nó poderá ter **no máximo duas folhas**:

<center>

![Tree](assets/bintree.jpg)

</center>

> Uma árvore **estritamente binária**, ou **quase completa**, é uma árvore na qual todo nó tem zero ou duas folhas:

<center>

![Tree](assets/bintree1.jpg)

</center>

> Uma árvore binária **completa** é uma árvore em que todos os níveis têm o máximo número de elementos:

<center>

![Tree](assets/bintree2.jpg)

</center>

---

### Árvore AVL

Uma árvore AVL é uma árvore sempre balanceada. Isto é, as alturas das subárvores esquerda e direita de cada nó diferem no máximo por uma unidade.

Para isto ser possível, suas operações de inserção e exclusão são realizadas com rotinas de balanceamento.

**Fator de balanceamento (equilíbrio) de um nó**: É a altura da sub-árvore da esquerda h<sub>e</sub> subtraída da sub-árvore da direita h<sub>d</sub>. Ou seja: $ h_d - h_e $

---

### Árvore Rubro-Negra


