class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:

        # Pegando o numero de linhas e colunas.
        linhas, colunas = len(heights), len(heights[0])
        ultimaLinha, ultimaColuna = linhas-1, colunas-1

        nosVisitados = set()    # Criando o conjunto de nos visitados.
        nosVisitados.add((0,0)) # Adicionando o primeiro no.
        
        # Criando a heap para percorrer o grafo.
        # [[linha, coluna, custo]]
        heap = [[0, 0, 0]] # Inicializando na posicao zero

        # Percorrendo a heap.
        while heap:
            lin, col, cost = heapq.heappop(heap)

            # Verificando se o no ja foi visitado.
            if (lin, col) in nosVisitados:
                # Se sim, vai para proximo na heap.
                continue
            else:
                nosVisitados.add((lin, col))    # Adicionando o no na heap.
            # Verificando se o no eh o ultimo.
            if lin == ultimaLinha and col == ultimaColuna: 
                return cost
            
            # Realizando uma BFS a partir do no.
            movimentos = [1, -1]
            for mov in movimentos:
                # Verificando os visinhos de cima e baixo
                tempLinha = lin + mov
                if (tempLinha, col) not in nosVisitados and tempLinha in range(linhas):
                    maxDif = max(abs(heights[lin][col]-heights[tempLinha][col]), maxDif)    # Pegando a diferenca maxima.
                    heapq.heappush(heap, [tempLinha, col, maxDif])                          # Colocando o no na heap.
                # Verificando os visinhos da esquerda e direita
                tempCol = col + mov
                if (lin, tempCol) not in nosVisitados and tempCol in range(colunas):
                    maxDif = max(abs(heights[lin][col]-heights[lin][tempCol]), maxDif)      # Pegando a diferenca maxima.
                    heapq.heappush(heap, [lin, tempCol, maxDif])                            # Colocando o no na heap.
