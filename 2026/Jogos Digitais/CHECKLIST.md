# Checklist — Jogos Digitais

Projeto principal: **Aberratio Mentis**

## 1. Preparação do projeto

- [ ] Confirmar a versão do Unity que será mantida: `6000.3.19f1`.
- [ ] Instalar o Unity Hub com o módulo Web Build Support.
- [ ] Instalar e configurar o Git LFS.
- [ ] Clonar o repositório pelo GitHub Desktop.
- [ ] Abrir o projeto pelo Unity Hub.
- [ ] Aguardar a restauração dos pacotes e a importação dos assets.
- [ ] Confirmar que os arquivos `.meta` acompanham seus assets.
- [ ] Manter o conteúdo autoral em `Assets/_AberratioMentis`.
- [ ] Manter assets de terceiros em `Assets/ThirdParty`.
- [ ] Conferir que `Library`, `Temp`, `Logs`, `Obj` e builds não serão versionados.

## 2. Fundação técnica

- [ ] Criar a cena `Bootstrap`.
- [ ] Criar o assembly próprio do projeto.
- [ ] Implementar o controle de modos do jogo.
- [ ] Criar perfis de estado mental com `ScriptableObject`.
- [ ] Definir os mapas de input `Gameplay`, `Minigame` e `UI`.
- [ ] Criar a base de interação por raycast.
- [ ] Criar a base do controlador em primeira pessoa.
- [ ] Criar a base de áudio adaptativo.
- [ ] Criar sistema de checkpoints e reinício da interação.

## 3. Entrada e acessibilidade

- [ ] Criar a tela inicial com o botão `ENTRAR`.
- [ ] Desbloquear o áudio após o clique de entrada.
- [ ] Solicitar o cursor capturado após o clique de entrada.
- [ ] Iniciar o carregamento assíncrono da primeira cena.
- [ ] Exibir prompts claros para cada objetivo.
- [ ] Permitir remapeamento dos comandos principais.
- [ ] Permitir reduzir ou desligar efeitos de câmera, áudio e iluminação.
- [ ] Garantir que nenhuma falha impeça a conclusão indefinidamente.

## 4. Build 0.1: primeira rota completa

- [ ] Criar o greybox do quarto, corredor, sala e trecho inicial da praça.
- [ ] Implementar movimentação, câmera, colisão e interação.
- [ ] Criar o perfil `Depression` orientado por dados.
- [ ] Aplicar ritmo mais lento, paleta dessaturada e sons abafados.
- [ ] Implementar o minigame `Bed Resistance`.
- [ ] Mostrar o comando atual e o progresso da tentativa.
- [ ] Implementar sucesso após três sequências concluídas.
- [ ] Implementar falha com retorno ao início da tentativa.
- [ ] Liberar a caminhada depois do sucesso.
- [ ] Implementar a televisão interativa.
- [ ] Implementar o `TV Bullet Hell` com troca para o modo `Minigame`.
- [ ] Restaurar corretamente o modo `Gameplay` ao sair do minigame.
- [ ] Implementar o `Loading Mind` durante o carregamento assíncrono.
- [ ] Implementar a transição até a praça em um ponto narrativo adequado.
- [ ] Criar três pistas investigativas recorrentes.
- [ ] Criar o objetivo de chegar ao ponto de ônibus.
- [ ] Criar a tela de encerramento temporário.
- [ ] Permitir retorno ao menu.

## 5. Validação da primeira rota

- [ ] Completar o fluxo quarto → casa → praça sem bloqueios.
- [ ] Confirmar que a rota dura aproximadamente 8 a 12 minutos.
- [ ] Confirmar que há no máximo cinco interações obrigatórias.
- [ ] Confirmar que cada minigame dura no máximo 30 segundos por tentativa.
- [ ] Confirmar que sucesso, falha e nova tentativa são compreensíveis.
- [ ] Confirmar que os controles retornam corretamente após cada minigame.
- [ ] Testar em teclado e mouse.
- [ ] Testar a opção de conforto com efeitos reduzidos e desligados.
- [ ] Fazer pelo menos um teste com outra pessoa.
- [ ] Registrar se o objetivo, os comandos e a intenção narrativa foram compreendidos.
- [ ] Registrar qualquer desconforto visual, sonoro ou de controle.
- [ ] Corrigir bloqueios antes de iniciar as outras perspectivas.

## 6. Expansão das perspectivas

- [ ] Definir o personagem e o objetivo da perspectiva de atenção fragmentada.
- [ ] Implementar a força de câmera configurável: `Desligada`, `Baixa` e `Padrão`.
- [ ] Criar uma apresentação alternativa quando a força de câmera estiver desligada.
- [ ] Definir o personagem e o objetivo da perspectiva de sobrecarga social.
- [ ] Implementar as três situações investigativas da praça.
- [ ] Garantir que a terceira perspectiva tenha função narrativa clara sem exigir outro minigame.
- [ ] Aplicar as variações sensoriais por perfil, sem duplicar as cenas.
- [ ] Reutilizar a casa, a praça, os NPCs, a música e os minigames por parâmetros.
- [ ] Revisar a linguagem para tratar cada personagem como uma experiência particular.
- [ ] Complementar o projeto com pesquisas e relatos relevantes.
- [ ] Adicionar avisos de conteúdo e opções de conforto antes das rotas sensíveis.

## 7. Otimização e publicação

- [ ] Configurar o perfil de build Web.
- [ ] Definir resolução inicial de 1280 × 720 ou template responsivo.
- [ ] Ativar Data Caching.
- [ ] Configurar Brotli quando o servidor fornecer os headers necessários.
- [ ] Manter Threads desligadas inicialmente.
- [ ] Desligar Development Build e Autoconnect Profiler em releases.
- [ ] Ativar Strip Engine Code.
- [ ] Verificar desempenho próximo de 60 FPS em computador modesto.
- [ ] Limitar luzes e preferir iluminação baked.
- [ ] Limitar texturas normalmente a 1024 px.
- [ ] Comprimir áudio e usar pooling para objetos repetidos.
- [ ] Evitar alocações por frame em `Update`.
- [ ] Medir o tamanho e o tempo de carregamento da build.
- [ ] Testar a build no Chrome e no Firefox.
- [ ] Confirmar que não há erros críticos no console do navegador.
- [ ] Criar ZIP do itch.io com `index.html`, `Build/` e `TemplateData/` na raiz.
- [ ] Testar a mesma saída no itch.io e na hospedagem própria.

## 8. Fechamento e documentação

- [ ] Atualizar o README da disciplina com o estado do projeto.
- [ ] Registrar a versão final do Unity usada na build.
- [ ] Documentar instalação, execução, controles e publicação.
- [ ] Registrar limitações conhecidas e decisões de redução de escopo.
- [ ] Fazer pull antes de abrir o Unity.
- [ ] Salvar ou fechar as cenas antes de commit e push.
- [ ] Revisar o diff e os arquivos gerados antes do commit.
- [ ] Confirmar que nenhum artefato de compilação foi incluído.

## Definition of Done

- [ ] O jogo inicia após uma ação consciente do usuário.
- [ ] O áudio funciona depois do clique de entrada.
- [ ] A primeira rota completa pode ser concluída.
- [ ] O estado de depressão altera percepção e controle por dados.
- [ ] `Bed Resistance`, `TV Bullet Hell` e `Loading Mind` são jogáveis.
- [ ] Os controles retornam corretamente depois de cada minigame.
- [ ] Os efeitos desconfortáveis podem ser reduzidos ou desligados.
- [ ] A build funciona no navegador sem erros críticos.
- [ ] O pacote do itch.io e a hospedagem própria usam a mesma saída.
