# Dory
3rd Sumo Robot for Project Neon. After Zumo and Nemo, comes Dory.

Repositório de desenvolvimento para a Dory em 2022.

Usamos o fluxo de trabalho apresentado [aqui pelo Gamen](https://github.com/project-neon/codestyleguide/blob/master/git.md). Também está apresentado no [github flow](https://docs.github.com/pt/get-started/quickstart/github-flow). O resumo seria este:


## Arquivos

  Neste repositório temos os principais arquivos que usamos para os 3 capítulos, Eletrônica, Mecânica e Software. Segue abaixo uma lista do que temos em cada uma das pastas:

  ### Electronics
    Na parte eletrônica, utilizamos o programa Kicad que é open source e permite a criação e edição de PCBs.
    Caso queira editar ou vizualizar o projeto, clone o diretório "Eletronics", pois nele está contido o esquemático 
    no formato PDF e sch,  a PCB no formato pcb e os arquivos pro e plr próprios do Kicad.
    
  ### Mechanics
    Na pasta da mecânica, há arquivos no formato step e stl para que possam ser utilizados para visualização 
    e manufatura 3D, juntamente com os arquivos pdf dos desenhos técnicos para melhor compreensão do projeto
    
  ### Software
    Nesta pasta deixamos todos os arquivos que formam o código do robô. Então .ino e .h são os principais arquivos.
    Usamos os .h's para segmentar o código e não ser um único bloco enorme, dividindo eles de acordo com sua funcionalidade.
    O .ino é onde fica a base de todo o código, como o setup() e o loop(). Temos os códigos de testes e o código autonomous
    que usamos durante as lutas oficiais.


## Fluxo Git
- Quando for acrescentar uma feature (um comportamento novo para o robô), crie uma brancha chamada `feat/nome-da-feature`
- Quando for corrir algum bug no código, crie uma brancha chamada `fix/nome-do-fix`
- Quando for adicionar novos arquivos na mecância ou eletrônica, crie uma brancha chamada `update/eletronics-<data>` ou `update/mechanis-<data>`, exemplo: `update/eletronics-01-04-2023`
- A partir da main: `git checkout -b nome-da-branch`, ex: `git checkout -b feat/novos-testes`

## Na hora de fazer o commit
- Nomeie o seu commit primeiro dizendo o que foi feito, ex: `fix: `, `feat: ` ou `update: `
- Você pode adicionar no assunto (comentário) ou na mensagem do commit também onde que a mudança foi feita.
- `git push`

Para saber mais de commits, você pode acessar esse [link](https://www.freecodecamp.org/news/how-to-write-better-git-commit-messages/)

## Na hora de fazer o merge
- Depois de subir o commit, crie um PR (Pull Request) e peça pro resto do pessoal da equipe dar uma conferida antes de ser aprovado

<img width="898" alt="image" src="https://user-images.githubusercontent.com/79096190/183220042-a89ff965-4950-49c7-a53b-bba7db6c3e32.png">
