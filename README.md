# sdist241
Neste trabalho vamos desenvolver dois programas em C/C++ para envio e recebimento de sinais.
Os dois executáveis disponibilizados aqui foram compilados e testados em máquina Ubuntu 20.04 x64.

Conforme o enunciado do TP1:
O primeiro programa deve ser capaz de enviar um sinal a qualquer outro processo. Este
programa recebe como parâmetros o número do processo destino e o sinal que deve ser
enviado. O programa deve verificar se o processo indicado pelo parâmetro existe, e
retornar um erro caso negativo. Caso positivo, o programa deve enviar o sinal
indicado.

O segundo programa deve ser capaz de receber alguns sinais específicos. Para isto, você
precisa definir signal handlers. O programa deve capturar e reagir a três sinais diferentes
(de sua escolha), ou mais, imprimindo no terminal uma mensagem diferente para cada
sinal. Além disso, um dos sinais sendo capturados deve terminar a execução do programa,
ou seja, sua signal handler deve terminar o processo. Repare que após estipular as signal
handlers o programa fica aguardando a chegada de sinais. Você deve implementar duas
formas de esperar, busy wait e blocking wait (passado como parâmetro para o programa).
Descubra como implementar cada uma destas formas de fazer um processo esperar!

Testes para os programas fazendo com que um envie sinais para o outro. Uso também do
programa kill para enviar sinais para o segundo programa.

## Testes
Para testar os programas vamos nos manter simples e fazer casos de uso típicos:

Compilar os programas:

gcc -o enviar_sinal enviar_sinal.c
gcc -o receber_sinal receber_sinal.c
Executar o programa de recepção de sinais:

./receber_sinal
./receber_sinal blocking
Em outro terminal, enviar sinais para o programa de recepção de sinais usando o programa de envio de sinais:

./enviar_sinal <pid_do_programa_receber_sinal> <numero_do_sinal>
Também é possível usar o comando kill para enviar sinais diretamente para o programa de recepção de sinais.

kill -s SIGINT <pid_do_programa_receber_sinal>
