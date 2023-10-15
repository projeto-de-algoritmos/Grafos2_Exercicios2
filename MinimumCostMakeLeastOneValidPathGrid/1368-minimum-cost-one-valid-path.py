import heapq

class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        
        # Pegando o numero de linhas e colunas.
        linhas, colunas = len(grid), len(grid[0])
        ultimaLinha, ultimaColuna = linhas-1, colunas-1

        # Criando e inicializando o vetor de custos.
        custos = [[1000]*colunas for i in range(linhas)]
        custos[0][0] = 0

        # Inicializando a heap.
        # [(linha, coluna, custo)]
        heap = [[0, 0, 0]]

        while heap:
            lin, col, cost = heapq.heappop(heap)

            # Verificando se o no eh o ultimo.
            if lin == ultimaLinha and col == ultimaColuna: 
                return cost
            
            # Percorrendo a matriz.
            # 1 = Direita  (grid[i][j] to grid[i][j + 1])
            # 2 = Esquerda (grid[i][j] to grid[i][j - 1])
            # 3 = Baixo    (grid[i][j] to grid[i + 1][j])
            # 4 = Cima     (grid[i][j] to grid[i - 1][j])
            movimentos = [[1, lin, col+1], [2, lin, col-1], [3, lin+1, col], [4, lin-1, col]]
            for mov in movimentos:
                tipoMovimento, tempLinha, tempColuna = mov[0], mov[1], mov[2]

                # Verificando os limites.
                if tempLinha not in range(linhas) or tempColuna not in range(colunas):
                    continue

                # Comparando os movimentos.
                if grid[lin][col] != tipoMovimento:
                    punicao = 1                                                 # Muda a direcao.
                else:
                    punicao = 0                                                 # Mantem a direcao.

                # Atualiza o custo.    
                novoCusto = cost + punicao                                      
                # Compara e salva na heap o menor custo.
                if novoCusto < custos[tempLinha][tempColuna]:                 
                    custos[tempLinha][tempColuna] = novoCusto
                    heapq.heappush(heap, [tempLinha, tempColuna, novoCusto])
