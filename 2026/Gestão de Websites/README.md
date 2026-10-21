# Gestão de Websites

Materiais da disciplina **Gestão de Websites** do curso de TADS — IFPR, turma TADS6 2026.

**Professora:** Melissa Silva de Oliveira Cordeiro

## Atividades e conteúdos

A disciplina aborda criação e gestão de websites, incluindo WordPress, temas e plugins. Também há atividades de desenvolvimento web com aplicações, APIs, métodos HTTP, persistência de dados e integração entre interface e backend.

| Atividade | Conteúdo |
| --- | --- |
| **[Presença Assíncrona] Pesquisa e Vídeo sobre Temas e Plugins** | **Prioridade:** pesquisar temas e plugins, preparar um blog demonstrativo e gravar uma apresentação de 10 a 15 minutos |
| Download e Configuração do WordPress | Baixar e executar o WordPress conforme o passo a passo e entregar um print da tela inicial |
| Meu Primeiro Blog | Criar um blog com pelo menos 5 posts, 3 páginas e um tema diferente do padrão |
| [Melhorar To-Do List](./Melhorar%20To-Do%20List/) | Next.js, MySQL e implementação do método HTTP `PUT` |

## Prioridade: pesquisa e vídeo sobre temas e plugins

O enunciado pede uma apresentação em vídeo feita em grupo de até 6 pessoas. O blog usado para a demonstração deve ter **10 posts e 5 páginas**. O vídeo deve durar aproximadamente **10 a 15 minutos**; não é necessário mostrar o rosto.

### O que preparar

- [ ] Confirmar os integrantes do grupo, até 6 pessoas, e quem fará a entrega.
- [x] Completar o blog de demonstração para 10 posts e 5 páginas (10 posts e 5 páginas publicados no WordPress local).
- [x] Explicar com suas palavras:
  - **Tema:** controla a aparência e a organização visual do site, como layout, tipografia, cores, menus, cabeçalho e rodapé.
  - **Plugin:** extensão que adiciona ou modifica funções, por exemplo formulários, SEO, loja virtual, backup ou segurança.
- [x] Pesquisar e selecionar 3 exemplos populares de temas e 3 de plugins. As referências estão no roteiro e nas páginas do blog.
- [x] Escolher e ativar o tema personalizado GMRsVoiage para a demonstração.
- [x] Escolher, instalar e ativar o plugin Classic Editor para a demonstração.
- [ ] Confirmar os nomes dos integrantes e preencher os espaços da apresentação e do roteiro.
- [ ] Gravar a tela mostrando a instalação/ativação do tema e do plugin e o uso de suas funcionalidades.
- [x] Pesquisar as referências; falta confirmar se estão visíveis no vídeo final.
- [ ] Conferir as instruções de entrega no Google Sala de Aula, gravar/exportar o vídeo e fazer o envio (uma pessoa do grupo entrega).

Materiais prontos para a gravação:

- [Apresentação navegável](./Apresentacao-temas-plugins.html) — use as setas do teclado para avançar/voltar, `F` para tela cheia e abra “Fala sugerida” em cada slide se precisar de apoio.
- [Roteiro de vídeo](./Roteiro-video-temas-plugins.md) — falas sugeridas, sequência de gravação, links e referências.
- [Temas populares no blog local](http://127.0.0.1/wordpress/temas-populares-wordpress/) e [plugins populares no blog local](http://127.0.0.1/wordpress/plugins-populares-wordpress/).

### Roteiro sugerido para o vídeo

Uma divisão possível, que totaliza cerca de 12 minutos:

1. **Abertura e objetivo** — 30 segundos.
2. **O que são temas e plugins** — 1 minuto e 30 segundos.
3. **Três exemplos de temas e três de plugins** — 2 minutos; dizer brevemente para que servem e citar as fontes.
4. **Demonstração do tema** — 3 minutos; mostrar instalação, ativação e algumas opções/funcionalidades.
5. **Demonstração do plugin** — 3 minutos; mostrar instalação, ativação e como usar algumas funcionalidades.
6. **Blog pronto, nomes do grupo e referências** — 2 minutos.

### Slides disponíveis

- [Slides — Sistemas de Gerenciamento de Conteúdo (CMS)](./Slides%20-%20Sistemas%20de%20Gerenciamento%20de%20Conte%C3%BAdo%20_%20CMS.pdf): trazem as definições de tema e plugin e exemplos de funcionalidades de plugins.
- [WordPress — passo a passo de download](./WORDPRESS%20-%20PASSO%20A%20PASSO%20DOWNLOAD%20%281%29.pdf): orienta a instalação local do WordPress com XAMPP.
- [Tema GMRsVoiage](./Tema%20GMRsVoiage/): tema filho do Twenty Twenty-Two, com estilos Vaporwave e Frutiger Aero e botão para alternar entre eles.

Os slides de CMS ajudam com as definições. Os exemplos e links oficiais pesquisados também estão nas páginas de temas e plugins do blog local.

**Compatibilidade da demonstração:** o plugin Contact Form 7 foi pesquisado, mas a versão atual exige PHP 8.3; este XAMPP usa PHP 8.2.12. Por isso, o plugin ativado para a demonstração é o Classic Editor, que funciona nesta instalação.

## Outras atividades de WordPress

As atividades abaixo são distintas da presença assíncrona: não confundir o blog de demonstração de **10 posts e 5 páginas** com o blog individual de **5 posts e 3 páginas**.

### Download e Configuração do WordPress

- [x] Seguir o PDF de passo a passo: baixar o WordPress, extrair os arquivos para `htdocs` do XAMPP, iniciar Apache e MySQL e criar um banco pelo phpMyAdmin.
- [x] Abrir o endereço local do site, concluir a configuração e tirar um print legível da tela inicial.
- [x] Conferir no Google Sala de Aula como enviar o print.

### Meu Primeiro Blog

- [x] Criar pelo menos 5 posts (10 publicados no blog de demonstração).
- [x] Criar pelo menos 3 páginas (5 publicadas no blog de demonstração).
- [x] Instalar e ativar um tema diferente do padrão: GMRsVoiage.
- [x] Conferir no site que o tema, os posts e as páginas estão visíveis.
- [x] Entregar conforme a orientação da professora.

> **Situação informada pelo aluno:** Download e Configuração do WordPress e Meu Primeiro Blog estão concluídas. A única atividade pendente é a Presença Assíncrona. O conjunto foi informado como referente ao dia 09/10; confirme no Google Sala de Aula ou com a professora o prazo e a forma de entrega da presença assíncrona, pois as datas informadas já passaram.

## Materiais registrados

A pasta da atividade de To-Do List preserva o nome utilizado no Google Sala de Aula e contém apenas código-fonte e arquivos necessários para reproduzir o exercício. Dependências instaladas localmente e credenciais de banco de dados não são versionadas. Os PDFs de apoio de WordPress estão na pasta desta disciplina, listados acima.
