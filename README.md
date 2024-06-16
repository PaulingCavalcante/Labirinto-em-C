# Labirinto

O projeto consiste na implementação de um jogo de labirinto, onde o objetivo é manobrar um personagem do início até a saída do labirinto, percorrendo o menor caminho possível.

## Breve Apresentação

Este projeto consiste na implementação de um jogo de labirinto desenvolvido como parte de um trabalho acadêmico no Instituto Federal de Educação, Ciência e Tecnologia de São Paulo, Campus Bragança Paulista.

## Descrição do Projeto

Um labirinto é constituído por um conjunto de percursos criados com a intenção de desorientar quem os percorre. O objetivo deste jogo é fazer com que o jogador manobre um caractere qualquer para a saída do labirinto, percorrendo o menor caminho possível.

O jogo representa o desenho de um caminho (semelhante aos passatempos de jornais ou revistas) e um objeto que deverá ser movimentado pelo jogador para a saída do labirinto. Os jogadores que conseguirem deslocar o objeto com a menor movimentação possível devem ter as maiores pontuações no jogo.

## Especificações do Projeto

- **Dimensões dos Caminhos**: Os caminhos possuem dimensões de 100 x 25 caracteres e devem apresentar mais de um caminho possível para a saída.
- **Opções de Caminhos**: O jogo possui no mínimo 5 opções de caminhos, com níveis de dificuldades distintos.
- **Exibição e Navegação**: 
  - Utilizamos matrizes e padrões para representação do labirinto na tela do usuário.
  - Para navegação, use as teclas: 
    - `D` (mover para a direita)
    - `A` (mover para a esquerda)
    - `W` (mover para cima)
    - `S` (mover para baixo)

- **Elementos:**
  - **`O`:** Representa o jogador dentro do labirinto.
  - **`|`:** Representa as paredes do labirinto, limitando o espaço onde o jogador pode se movimentar.
  - **` `:** (espaço em branco): Indica áreas livres dentro do labirinto, onde o jogador pode se mover.
- **Sistema de Pontuação**: 
  - Cada movimento reduz 1 ponto do score inicial.
- **Registro de Jogador**: 
  - O jogador deve iniciar informando seu nome.
  - Ao final de cada nível, o jogador será perguntado se deseja prosseguir para o próximo nível.
  - O jogador pode desistir do jogo a qualquer momento.
- **Exibição de Pontuação**:
  - Ao final do jogo, será revelada a pontuação do jogador.
  - Será exibida uma lista com as 10 maiores pontuações.

## Estrutura do Projeto

1. **[main.c](https://github.com/PaulingCavalcante/Labirinto-em-C/blob/main/main.c)**: Arquivo principal do código que contém a lógica do jogo.
2. **[image.png](https://i.ibb.co/TMVjChY/image.png)**: Imagem de exemplo do labirinto. <br>
   <img src="https://i.ibb.co/TMVjChY/image.png" alt="Labirinto" border="0" height="50%">

## Como Executar

Para compilar e executar o programa, siga os seguintes passos:

1. Clone o repositório:
   ```bash
   git clone <https://github.com/PaulingCavalcante/Labirinto-em-C.git>
   cd <NOME_DO_REPOSITORIO>
   ```
   
2. Clone o repositório:
   ```bash
   gcc main.c -o labirinto
   ```

2. Execute o programa:
   ```bash
   ./labirinto
   ```

Ou baixe e execute o **main.exe**, localizado dentro do diretorio **output**.

## Contribuidores

- [Keila Alves](https://github.com/Keilaalves1803)
- [Matheus Lopes](https://github.com/Mathlps)
- [Talia Moura](https://github.com/TahMoura)

## Licença

Este projeto está licenciado sob a licença MIT. Veja o arquivo [LICENSE](./LICENSE) para mais detalhes.
