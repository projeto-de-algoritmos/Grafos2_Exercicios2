# Exercicios2

**Número da Lista**: 2<br>
**Conteúdo da Disciplina**: Dijkstra, Prim, Kruskal<br>

## Alunos

| Matrícula  | Aluno                       |
| ---------- | --------------------------- |
| 21/1029147 | Arthur de Melo Viana        |
| 21/1029666 | Matheus Henrique Dos Santos |

## Sobre

Exercícios do Sphere Online Judge:

- [SHPATH - The Shortest Path](https://www.spoj.com/problems/SHPATH/)
- [MELE3 - MELE3](https://www.spoj.com/problems/MELE3/)

Exercícios do LeetCode:

- [1631 - Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/)
- [1368 - Minimum Cost to Make at Least One Valid Path in a Grid](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)

## Screenshots

As seções a seguir explicitam os exercícios resolvidos e apresentam uma breve explicação das resoluções. É possível observar o status de conclusão do problema e uma descrição do algoritmo utilizado. A dificuldadade dos exercícios do SPOJ, [de acordo com o próprio site](https://www.spoj.com/tutorials/USERS/#choose), é melhor analisada pela quantidade de usuários que solucionaram e pela taxa de aceitação das submissões, a qual ficou no título de cada seção entre parênteses da seguinte forma: Users - ACC%. Já a dificuldade do leetcode é dada de forma explícita na página do problema.

### SHPATH - The Shortest Path (5252 - 25.67%)

Utilização do algoritmo de Dijkstra com lista de adjacência e heap de mínimo da STL (Standard Template Library) do C++. Em uma lista de cidades, precisa encontrar a menor distância entre duas cidades dado o nome de ambas, sendo um grafo direcionado, a identificação das strings para o índice de cada cidade foi feita por meio de um map com chaves associativas do std::map.

![Imagem SHPATH1](assets/enunciadoSHPATH.png)

![Imagem SHPATH](assets/SHPATH.png)

### MELE3 - MELE3 (605 - 42.46%)

Utilização do algoritmo de Dijkstra com lista de adjacência e heap de mínimo da STL (Standard Template Library) do C++. Dada uma quantidade N de elevadores e K de pisos, o programa deve imprimir uma única linha com o menor caminho do primeiro andar até o último andar, sabendo que todos os elevadores param em apenas 2 pisos e que eles percorrem um andar em 5 segundos. Quando atingem o piso de destino, começam a descer. Caso o elevador esteja no mesmo piso no momento, pode-se trocar imediatamente de elevador.

![Imagem MELE31](assets/enunciadoMELE3.png)
![Imagem MELE3](assets/MELE3.png)

### 1631 - Path With Minimum Effort (Medium)

Utilização do algoritmo de Dijkstra com matriz e heap de mínimo em python. Em uma matriz 2D, cada célula possui um tamanho/altura e é desejado encontrar o caminho com o menor esforço, ou seja com a menor variação de altura, entre a célula (0,0) até a célula (quantLinha, quantColuna). O esforço é definido como sendo a diferença máxima absoluta entre as alturas das células.

![Imagem do enunciado 1631.](assets/enunciado1631.png)
![Imagem da página do problema 1631 com a submissão aceita.](assets/1631.png)

### 1368 - Minimum Cost to Make at Least One Valid Path in a Grid (Hard)

Utilização do algoritmo de Dijkstra com matriz e heap de mínimo em python. Em uma matriz 2D, cada célula possui uma direção, sendo possível mudar essa direção uma única vez com um custo 1 e é desejado encontrar o caminho com o menor custo entre a célula (0,0) até a célula (quantLinha, quantColuna).

![Imagem do enunciado 1368.](assets/enunciado1631.png)
![Imagem da página do problema 1368 com a submissão aceita.](assets/1368.png)

## Instalação

**Linguagem**: C++, Python<br>

Para rodar os arquivos em C++, é recomendado utilizar o WSL caso esteja no Windows. Nele, execute os comandos `sudo apt update` e `sudo apt install build-essential` para instalar o g++. O código em C++ também pode ser enviado no próprio [SPOJ](https://www.spoj.com/) ou compilado e executado no [Ideone](https://ideone.com/). Já para rodar os arquivos em Python, pode ser utilizado o interpretador online [GDB](https://www.onlinegdb.com/) ou instalar o Python na sua máquina (as instruções para instalação podem ser encontradas no [guia de instalação](https://wiki.python.org/moin/BeginnersGuide/Download)).

## Uso

Para os exercícios em C++, compile o código utilizando `g++ -o prog arquivo.cpp` e execute-o utilizando `./prog`, por fim, digite o input no terminal. Também pode ser utilizado o comando `./prog < entrada.txt` caso exista algum caso de teste válido no arquivo de texto. Os links para os problemas resolvidos estão na seção "Sobre", onde podem ser enviados para verificar se foram aceitos.

Para os exercícios em Python, basta digitar `python nome-do-arquivo.py` no terminal de preferência. Da mesma forma, a solução pode ser enviada na própria página do problema.

## Vídeo

Para acessar o vídeo explicativo sobre os exercícios, [clique aqui](https://www.youtube.com/embed/lNh9KVZmK5Y).
Para baixar o vídeo, [clique aqui](apresentacao.mp4).
