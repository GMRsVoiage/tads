# Tecnologias Web

Materiais da disciplina **Tecnologias Web** do curso de TADS.

A referência principal da turma é o Google Classroom de mesmo nome:

- Classroom: https://classroom.google.com/c/ODcxMTc5MzExMTUx
- Professor: [Paulo Ricardo de Souza](https://github.com/pauloricardosouza)

## Organização

Os arquivos foram organizados em uma sequência de conteúdos para facilitar a relação entre o GitHub e o que foi trabalhado na disciplina.

```text
Tecnologias Web/
├── 01-html-basico/
│   └── aula1.html
├── 02-links-e-navegacao/
│   ├── links.html
│   └── cores/
│       ├── amarelo.html
│       ├── azul.html
│       ├── preto.html
│       ├── rosa.html
│       ├── verde.html
│       └── vermelho.html
├── 03-listas-e-tabelas/
│   ├── listas.html
│   └── tabelas.html
├── 04-midias-e-iframes/
│   ├── midias.html
│   ├── iframe.html
│   └── assets/
│       ├── audio/
│       └── images/
├── 05-formularios/
│   ├── forms.html
│   └── forms2.html
└── 06-semantica/
    └── semantica.html
```

## Conteúdos

### 01 — HTML básico

Primeiros exemplos de estrutura HTML, títulos e parágrafos.

### 02 — Links e navegação

Exercícios de links e navegação entre páginas, incluindo o conjunto de páginas de cores.

### 03 — Listas e tabelas

Exercícios com listas ordenadas/desordenadas e tabelas HTML.

### 04 — Mídias e iframes

Exercícios com imagem, áudio, vídeo e `iframe`. As mídias que estão versionadas ficam dentro de `assets/`.

### 05 — Formulários

Exercícios com tipos de `input`, formulários e campos adicionais.

### 06 — Semântica

Exercício com elementos semânticos como `header`, `nav`, `main`, `section`, `article`, `aside` e `footer`.

## Relação com o Classroom

O Classroom deve ser considerado a fonte de contexto para nomes de atividades, materiais, datas e instruções do professor. O GitHub funciona como organização e histórico dos arquivos produzidos durante a disciplina.

Ao adicionar novas atividades, prefira:

1. identificar primeiro a atividade/material correspondente no Classroom;
2. colocar o arquivo na pasta do conteúdo relacionado;
3. criar uma nova pasta numerada apenas quando começar um novo bloco de conteúdo;
4. preservar o nome original da atividade quando isso ajudar a relacioná-la ao Classroom.

## Referências ausentes no repositório

Alguns HTMLs já referenciavam arquivos que não estavam versionados antes desta reorganização. Essas referências foram mantidas, sem inventar substitutos:

- `02-links-e-navegacao/links.html` referencia `img/Sailormoongoogle.jpg`;
- as páginas em `02-links-e-navegacao/cores/` referenciam imagens em `img/botoes/img/`;
- `04-midias-e-iframes/midias.html` referencia os vídeos `video/aesthetic.mp4` e `video/aaesthetic.mp4`;
- `05-formularios/forms2.html` utiliza `processamento.php` como destino do formulário, mas esse arquivo não está versionado.

## Licença

O arquivo `LICENSE` existente nesta pasta foi preservado. Mídias de terceiros permanecem sujeitas aos direitos de seus respectivos autores.
