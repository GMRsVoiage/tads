# **Game Concept do Projeto Final: Aberratio Mentis** 

## **1. Identificação do Projeto** 

- **Nome provisório do jogo:** Aberratio Mentis 

- **Integrante da equipe:** Rafael Carneiro Fragoso (Desenvolvedor  Solo) 

- **Turma:** TADS6 

- **Data:** 10/09/2026 

## **2. Conceito Central**

_Aberratio Mentis_ é um walking simulator investigativo em primeira pessoa. O jogador atravessa o mesmo percurso urbano por três perspectivas individuais. A estrutura física permanece igual, mas controles, sons, iluminação, pistas e interações mudam conforme a experiência do personagem.

O jogo não pretende reproduzir universalmente depressão, TDAH ou qualquer outra condição. Cada rota apresenta uma experiência ficcional específica, baseada em pesquisa e em relatos, sem sugerir que dificuldades de saúde mental sejam resolvidas apenas por esforço.

## **3. Gênero, Plataforma e Tecnologia** 

- **Gênero principal:** _Walking Simulator_ em 1ª pessoa /  Puzzle Narrativo 

- **Gêneros secundários:** Simulação Psicológica / Minigames  Mecânicos 

- **Engine / Ferramenta:** Unity (3D) 

- **Plataforma-alvo:** PC (Windows) 

- **Forma de execução / publicação:** Executável (.exe)  / WebGL no itch.io 

## **4. Público-Alvo**

Jogadores a partir de 14 anos interessados em experiências narrativas, exploração e mecânicas sensoriais. Avisos de conteúdo e opções de conforto serão apresentados antes das rotas que usam distorção de câmera, ruído ou iluminação intensa.

## **5. Objetivo do Jogador**

O jogador deve cumprir uma rotina curta: sair do quarto, atravessar a casa, alcançar a praça e chegar ao ponto de ônibus. Durante o percurso, investiga objetos e encontra três pistas recorrentes que revelam como o mesmo evento foi percebido por cada personagem.

Não existe morte nem Game Over clássico. Uma falha reinicia somente a interação atual ou retorna ao último ponto de controle. Cada rota terá de 8 a 12 minutos e, na primeira versão, será composta por no máximo cinco interações obrigatórias.

## **6. Mecânica Principal**

Exploração em primeira pessoa integrada a minigames de resistência e investigação ambiental. O núcleo da jogabilidade é observar o espaço, compreender o objetivo, executar uma interação curta e interpretar suas consequências.

### 6.1 Primeira perspectiva: experiência depressiva

É a primeira rota a ser desenvolvida e validada integralmente. O personagem começa no quarto e precisa levantar, atravessar a casa e chegar à praça.

- **Mecânica:** Bed Resistance, uma sequência curta de comandos indicados na tela.
- **Comando:** pressionar a tecla mostrada no momento correto, usando teclado e espaço para confirmar ações simples.
- **Sucesso:** completar três sequências; o personagem se levanta e o controle de caminhada é liberado.
- **Falha:** a sequência é interrompida e o jogador retorna ao início da tentativa, sem perder o progresso da rota.
- **Percepção:** paleta dessaturada, ritmo mais lento, sons abafados e NPCs que demoram a desviar o olhar.

### 6.2 Segunda perspectiva: atenção fragmentada

Esta rota representa uma experiência ficcional de distração e dificuldade de manter o foco. Ela não pretende definir ou resumir o TDAH.

- **Mecânica:** pontos de interesse aplicam uma força leve que desloca a direção da câmera.
- **Comando:** usar o mouse para manter o marcador sobre o objetivo por períodos curtos.
- **Sucesso:** manter o foco em três objetivos e concluir o percurso.
- **Falha:** a câmera retorna gradualmente ao último objetivo confirmado; nunca há bloqueio indefinido.
- **Conforto:** intensidade configurável em `Desligada`, `Baixa` e `Padrão`; quando desligada, a distração aparece por som, marcador e mudança de foco visual, sem mover a câmera.

### 6.3 Terceira perspectiva: sobrecarga social

A terceira rota acompanha um personagem sem diagnóstico definido que interpreta a praça como um ambiente social difícil de ler. A proposta é abordar uma experiência particular de sobrecarga e vigilância social, sem transformá-la em uma categoria clínica.

- **Mecânica:** observar três situações da praça e escolher quais pistas são relevantes para a rotina.
- **Comando:** olhar para a situação, pressionar `E` para investigar e selecionar uma resposta simples.
- **Sucesso:** identificar as três pistas e chegar ao ponto de ônibus.
- **Falha:** a resposta é corrigida com uma indicação contextual; o jogador pode tentar novamente no mesmo local.
- **Percepção:** vozes sobrepostas, sinais visuais concorrentes e redução gradual desses estímulos após cada pista encontrada.

Essa perspectiva não exige um terceiro minigame de resistência. Sua função é ampliar o contraste entre leituras do mesmo espaço e fechar a investigação narrativa.

## **7. Diferencial Jogável**

O mesmo cenário é reutilizado com alterações sensoriais e mecânicas controladas por dados. A praça e a casa permanecem fisicamente iguais, enquanto iluminação, mixagem sonora, pistas, comportamento de NPCs e resposta dos controles mudam por perspectiva.

Nenhuma alteração sensorial deve impedir a conclusão. A intensidade da câmera, do áudio e da iluminação poderá ser reduzida ou desativada.

## **8. Escopo Mínimo**

A Build 0.1 terá uma rota completa da primeira perspectiva, do quarto até a praça, e um trecho compartilhado preparado para as outras rotas.

### Obrigatório na Build 0.1

- movimentação em primeira pessoa, câmera, colisão e interação;
- quarto, corredor, sala e trecho inicial da praça em greybox;
- Bed Resistance funcional;
- três pistas investigativas e uma tela de conclusão;
- checkpoints, prompts e reinício da interação;
- opção de conforto para efeitos de câmera, áudio e iluminação;
- build Windows testável e documentação de execução.

### Depois da validação da primeira rota

- rota de atenção fragmentada;
- rota de sobrecarga social;
- efeitos visuais e áudio reativo específicos;
- NPCs com comportamento de olhar e diálogos curtos;
- build WebGL e publicação no itch.io.

## **9. Priorização das Funcionalidades (MoSCoW)**

| Prioridade | Funcionalidade |
|---|---|
| **MUST** | Uma rota completa: quarto, casa, praça e conclusão. |
| **MUST** | Movimento, câmera, colisão, interação e prompts. |
| **MUST** | Bed Resistance com sucesso, falha, retomada e checkpoint. |
| **MUST** | Três pistas investigativas do percurso. |
| **MUST** | Opções de conforto e redução dos efeitos sensoriais. |
| **SHOULD** | Segunda rota de atenção fragmentada. |
| **SHOULD** | Terceira rota de sobrecarga social. |
| **SHOULD** | Áudio reativo por perspectiva. |
| **COULD** | Diálogos em estilo visual novel e variações de horário. |
| **COULD** | WebGL otimizado para publicação no itch.io. |



## **10. Ciclo dos minigames e interação**

1. O jogador olha para um objeto ou área destacada.
2. Um prompt informa o objetivo e os comandos necessários.
3. A tentativa dura no máximo 30 segundos.
4. Um indicador visual e sonoro informa progresso, sucesso ou falha.
5. Em caso de falha, o jogador retorna ao início da interação, com nova tentativa imediata.
6. Após o sucesso, um checkpoint libera a próxima área.

Nenhuma mecânica impede a conclusão indefinidamente. Os comandos podem ser remapeados e os efeitos sensoriais podem ser reduzidos ou desativados.

## **11. Restrições e redução de escopo**

- O projeto será desenvolvido por uma pessoa.
- O ambiente usa assets prontos e greybox antes de acabamento artístico.
- A primeira rota será testada e concluída antes da expansão para as outras duas.
- O cenário compartilhado será mantido em uma única cena sempre que possível.
- Efeitos complexos serão removidos antes de reduzir a clareza do objetivo ou o conforto do jogador.

## **12. Testes e critérios de validação**

Cada teste deve verificar se o jogador consegue:

1. entender o objetivo sem explicação externa;
2. reconhecer o comando e o resultado da interação;
3. recuperar-se de uma falha sem ficar preso;
4. concluir a rota em até 12 minutos;
5. reduzir ou desligar efeitos desconfortáveis.

Antes de ampliar o projeto, pelo menos uma pessoa além do desenvolvedor deve testar a primeira rota e responder se compreendeu a mecânica, se identificou a intenção narrativa e se sentiu desconforto.

## **13. Riscos e respostas**

| Risco | Resposta |
|---|---|
| Distorção de câmera causar enjoo ou confusão. | Intensidade configurável, modo sem movimento automático e teste com jogadores. |
| Escopo grande para desenvolvimento solo. | Validar uma rota completa antes de criar as outras. |
| Minigame parecer uma punição arbitrária. | Prompt, feedback de progresso, limite de 30 segundos e retomada imediata. |
| Representação simplificar experiências reais. | Pesquisar relatos, usar personagens ficcionais específicos e revisar a linguagem do projeto. |
| Build Web ficar pesada. | Greybox inicial, texturas limitadas, áudio comprimido e efeitos opcionais. |



## **14. Responsabilidades**

Rafael Carneiro Fragoso será responsável pela programação da movimentação, interação e minigames, montagem do level design com assets prontos, integração de áudio e efeitos, testes e publicação.



## **15. Referências e pesquisa**

- **When The Darkness Comes:** referência para desconforto visual e presença de NPCs.
- **What Remains of Edith Finch:** referência para integrar mecânicas narrativas à exploração.
- **Hellblade: Senua's Sacrifice:** referência para alterações visuais e sonoras, sem copiar sua representação.
- Relatos e materiais de organizações e pessoas com experiências de depressão, TDAH e sobrecarga social serão consultados antes de finalizar cada rota.

As referências de jogos orientam linguagem e interação; elas não substituem pesquisa sobre as experiências representadas.

