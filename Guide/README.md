# Guide

Primeiro você tem que aprender a fazer conversão de coordenadas e de escala do seu plano cartesiano.
Como aprender isso ?

Plota um circulo de raio = 2. Pinta todos os pontos fora do circulo de branco e os pontos dentro do circulo não mexe neles para ficar preto.
Caso não lembre a fórmula do circulo é essa aqui: x^2+Y^2 = 4. 
Para chegar no resultado acima vc pinta de branco todos os pontos onde: x^2+Y^2 => 4.

O que acontece aqui, se você não fizer conversão de escala ou de coordenadas esse circulo vai fica pequenininho e com o centro no canto esquerdo da janela.

Seu desafio é colocar ele centralizado na janela e de um tamanho que da para ver.

Conseguiu fazer o circulo? Parabéns! Agora você vai plotar o fractol original:
https://pt.mathigon.org/course/fractals/mandelbrot
https://www.wikihow.com/Plot-the-Mandelbrot-Set-By-Hand
https://www.youtube.com/watch?v=eN8e6CJwdZU

Os dois primeiros links devem ser suficientes, se ficar alguma dúvida vai no terceiro.

Depois de plotar o Mandelbrot original recomendo começar a estudar hooks. Recomendo o artigo "Managing events with the minilibx" do Aurelien Brant e os tópicos Events e Hooks do Doc de Harm Smith. Segue os links.
https://aurelienbrabant.fr/blog/managing-events-with-the-minilibx
https://harm-smits.github.io/42docs/libs/minilibx/events.html
https://harm-smits.github.io/42docs/libs/minilibx/hooks.html

O segredo de aprender hooks é não se apegar nos detalhes, olhe outros repositórios entenda qual hook usar para cada operação.

É importante tbm conhecer os códigos das teclas que o minilibx usa. Existem muitas tabelas de keysym na internet por tentativa e erro me parece que o minilibx usa essa aqui:
https://api.arcade.academy/en/latest/arcade.key.html

Recomendo começar com os códigos para fechar a janela no esc, em seguida no x.

Depois faça hook para as outras teclas e sinais de mouse que deseja usar.
Uma dica é começar fazendo com que essas teclas exibam (com printf) no terminal alguma frase ou um caractere para testar o hook. Depois você faz o hook funcionar para seu objetivo final.