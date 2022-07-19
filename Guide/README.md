# Guide

## minilibX

O minilibx é uma biblioteca usada básicamente dentro da 42, não tem muita documentação sobre ela então vc  vai acabar sempre nos mesmos links.
Desde já recomendo não insistir muito com ela, foca no que vc tem que entregar!

Para estudar sobre o minilibx você tem 2 links, o blog do Aurelien Brabant e o Docs do harm smith:
No blog basta ler o artigo: Getting started with the minilibx. Em seguida leia o capitulo Getting started do Smith (vai ser basicamente o mesmo conteudo do artigo anterior porém de outro ponto de vista), sério, não avance agora para os outros capitulo, não é necessário.
https://aurelienbrabant.fr/blog
https://harm-smits.github.io/42docs/libs/minilibx/introduction.html
No fim deste último vai ter alguns exercicios recomendo que faça eles paraexercitar o minilibx.
- Coloque um ponto na tela.
- Faça um quadrado.
- Faça um quadrado pintado.
- Mova esse quadrado pela tela (coloque no cando por exemplo)
- Faça triângulos.
- (Se você lembra de funções arrisque algumas formas, se não lembra não tem problema).
- Faça losangulos, pentagonos e outras formas. Se divirta :D.
- Faça um gradiente de cores.

## Mandelbrot

Primeiro você tem que aprender a fazer conversão de coordenadas e de escala do seu plano cartesiano.
Como aprender isso ?

Plota um circulo de raio = 2. Pinta todos os pontos fora do circulo de branco e os pontos dentro do circulo não mexe neles para ficar preto.
Caso não lembre a fórmula do circulo é essa aqui: x^2+Y^2 = 4. 
Para chegar no resultado acima vc pinta de branco todos os pontos onde: x^2+Y^2 => 4.
O que acontece aqui, se você não fizer conversão de escala ou de coordenadas esse circulo vai fica pequenininho e com o centro no canto esquerdo da janela.

Seu desafio é colocar ele centralizado na janela e de um tamanho que da para ver.

Obs.: Não tente mudar a fórmula para algo como (x + 200)^2 + (y + 200)^2 = 50^2.
Fazer isso vai funcionar porém vc não vai aprender a converter coordenadas ;).

Conseguiu fazer o circulo? Parabéns! Agora você vai plotar o fractol original:
https://pt.mathigon.org/course/fractals/mandelbrot
https://www.wikihow.com/Plot-the-Mandelbrot-Set-By-Hand
https://www.youtube.com/watch?v=eN8e6CJwdZU

Os dois primeiros links devem ser suficientes, se ficar alguma dúvida vai no terceiro.

## Hooks
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