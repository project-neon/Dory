# Estratégias

  ### Conclusões: 
  - Se preocupar com a qualidade e não a quantidade
  - Ter certeza que o robô está sendo bem controlado
  300 RPM --- 600 RPM
    (Pra procurar o inimigo, é interessante + baixa, no ataque, quando de frente 600RPM)
  
  ### Estratégias preferidas:
  - Meia-Lua
  - Estratégia Clássica
  - Cabra-cega
  1. MEIA LUA  (- inteligente no começo + rápido no começo, + inteligente - rápido) 
    VANTAGENS:
    -Ao reposicionar o robô nos encontramos em uma situação familiar e colocamos o oponente em uma situação inesperada       
    -Maior chance de desviar dos sensores adversários       
    -Maior chance de atacar pelos flancos 
    -Mais rápido no começo, pois não precisa tormar decisões de acordo com os sensores
   DESVANTAGENS:       
   -Mais vulnerável a ataques iniciais caso seja detectado, ainda mais se o movimento de meia lua for já pré-programado e não possuir uma lógica para caso perceba que o inimigo está vindo ataar.    

  2. ESTRATÉGIA CLÁSSICA (+ inteligente - rápido)  
  VANTAGENS:       
  -Consistência em encontrar o robô inimigo       
  -Menos suscetível a ser atacado pelos flancos   
  DESVANTAGENS:       
  -Tempo maior de reação por estar sondando 360 graus, sempre verificando os valores dos sensores         
  3. CABRA-CEGA  (- -inteligente  ++rápido)
  VANTAGENS:       
  -Tempo menor de reação contra posições na trajetória do robô       
  -Sempre com grande quantidade de movimento (vantagem em confros diretos)   
  DESVANTAGENS:       
  -Suscetível a ataques pelos flancos
  -Controle mais difícil, ainda mais em garantir que ele não vai sair da borda

  ### Sensores
  ##### De distância: 
A ideia de usar três sensores é de o sensor central servir para alinhar a investida (não errar o oponente) e os dois outros ficarem como visão periférica, de forma a saber para qual sentido o robô adversário está ameaçando fugir ou para qual fugiu. Ele também é vesgo para fora, para aumentar o campo de visão.

   ##### De refletância: 
A ideia de colocá-los na frente é impedir que o robô saia da arena por conta própria. Possibilitando, de forma mais segura, estratégias que exijam reposicionamentos ou investidas mais intensas. Não colocamos na parte de trás do robô, pois provavelmente ele já perderia caso estivesse com a traseira encostada na borda, por estar perdendo algum confronto direto.
 
### Cronograma:
1. Atualizar os pinos novos no _config.h
2. Atualizar o Sensors.cpp/Sensors.h para o modelo VL53L0X
3. Atualizar o Motors.cpp/Motors.h para o modelo Brushless
4. Códigos para teste
    4.1 Motores
    4.2 Movimentos para frente/trás
    4.3 Sensores
5. Fazer o código para Rádio Controlável
6. Estudar a forma/valores que os sensores estão passando para nós
    5.1 Como funciona quando está perto da borda?
    5.2 Até que distância pega bem, até que distância pega mal
7. Aplicar as estratégias escolhidas
    6.1 -  Teste das estratégias separadamente
    6.2 - Afinal, rola ou n rola segmantar o código?
8. Fazer a documentação (+ final)

| Semana  | 
|---|
| 28/08 | 
 - Pedir o Pinout pra galera da eletronica
 - Atualizar o _config.h
 - Atualizar o Sensors.cpp/Sensors.h para o modelo VL53L0X
 
| Semana  | 
|---|
|  4/09  | 
 - Estudar o código do combate
 - Referenciar documentações sobre o motor
 - Atualizar o Motors.cpp/Motors.h para o modelo Brushless

| Semana  | 
|---|
|  11/09 |  
 - Códigos para teste

    1.Motores
    2.Sensores
   
(Possível que não precise pois os testes já estão feitos, dá pra puxar das tarefas da semana que vem se for mesmo o caso)

- Começar o código para Rádio Controlável, estender pras outras semanas conforme for necessário

| Semana  | 
|---|
|  18/09 |  
 - Estudar a forma/valores que os sensores estão passando para nós
    1. Como funciona quando está perto da borda?
    2. Até que distância pega bem, até que distância pega mal
    3. Como melhorar?

| Semana  | 
|---|
|  25/09  --- 02/10 |  

- Aplicar as estratégias escolhidas
    6.1 - Teste das estratégias separadamente
    6.2 - Escolher as estratégias, de acordo com os valores do controle
    6.3 - Iniciar o robô com o controle do Juiz
    6.4 - Afinal, rola ou n rola segmantar o código?

| Semana  | 
|---|
|  02/10  --- 14/10 | 

- Tempo de revisão, melhorias, fixes


### Extras da reunião:
 - VL53L0X - até 53 cm
 - Infravermelho rodando liso, valo tá chegando redondindo
 - Códigos testes já estão prontos (add eles no repositório)

### Coisas a fazer:
 - Montar o conograma do Nemo?
 - Rádio Controlável?
