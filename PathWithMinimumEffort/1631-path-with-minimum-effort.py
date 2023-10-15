import heapq

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:

        # Pegando o numero de linhas e colunas.
        linhas, colunas = len(heights), len(heights[0])
        ultimaLinha, ultimaColuna = linhas-1, colunas-1

        nosVisitados = set()                                    # Criando o conjunto de nos visitados.
        custos = [ [10**6]*colunas for i in range(linhas)]      # Tabela de custos.
        
        # Criando a heap para percorrer o grafo.
        # [[linha, coluna, custo]]
        heap = [[0, 0, 0]] # Inicializando na posicao zero
        custos[0][0] = 0   # Marcando zero na posicao

        # Percorrendo a heap.
        while heap:
            lin, col, cost = heapq.heappop(heap)

            # Verificando se o no eh o ultimo.
            if lin == ultimaLinha and col == ultimaColuna: 
                return cost
            
            # Realizando uma BFS a partir do no.
            movimentos = [1, -1]
            for mov in movimentos:
                # Verificando os visinhos de cima e baixo.
                tempLinha = lin + mov
                if (tempLinha, col) not in nosVisitados and tempLinha in range(linhas):
                    maxDif = max(abs(heights[lin][col]-heights[tempLinha][col]), custos[lin][col])      # Pegando a diferenca maxima.
                    if (custos[tempLinha][col] > maxDif):                                               # Verificando se eh maior que o limite.
                        custos[tempLinha][col] = maxDif                                                 # Trocando caso sim.
                        heapq.heappush(heap, [tempLinha, col, custos[tempLinha][col]])                  # Colocando o no na heap.
                # Verificando os visinhos da esquerda e direita.
                tempCol = col + mov
                if (lin, tempCol) not in nosVisitados and tempCol in range(colunas):
                    maxDif = max(abs(heights[lin][col]-heights[lin][tempCol]), custos[lin][col])        # Pegando a diferenca maxima.
                    if (custos[lin][tempCol] > maxDif):                                                 # Verificando se eh maior que o limite.
                        custos[lin][tempCol] = maxDif                                                   # Trocando caso sim.
                        heapq.heappush(heap, [lin, tempCol, custos[lin][tempCol]])                      # Colocando o no na heap.
