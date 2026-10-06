# [ATIVIDADE] Melhorar To-Do List

Implementação da atividade de **Gestão de Websites** que solicita a evolução do exemplo de To-Do List com o método HTTP `PUT`, permitindo editar elementos.

A implementação inclui o requisito obrigatório no `route.js` e também a edição pela interface.

> O ZIP-base disponibilizado pela disciplina não estava disponível neste repositório no momento da organização. Esta versão reproduz a estrutura necessária para executar e demonstrar a funcionalidade pedida.

## Tecnologias

- Next.js (App Router)
- React
- MySQL
- `mysql2/promise`
- API Route Handlers: `GET`, `POST`, `PUT` e `DELETE`

## Estrutura principal

```text
Melhorar To-Do List/
├── app/
│   ├── api/
│   │   └── todos/
│   │       └── route.js
│   ├── globals.css
│   ├── layout.js
│   └── page.js
├── lib/
│   └── db.js
├── database.sql
├── package.json
└── README.md
```

## Como executar

### 1. Criar o banco

Execute o arquivo `database.sql` no MySQL.

### 2. Configurar o ambiente

Crie um arquivo local chamado `.env.local` na raiz desta atividade. Ele não deve ser enviado ao GitHub.

Use estas variáveis e substitua os valores pelas credenciais do seu MySQL:

```text
DB_HOST=<host do MySQL>
DB_PORT=<porta do MySQL>
DB_USER=<usuário do MySQL>
DB_PASSWORD=<senha do MySQL>
DB_NAME=todo_app
```

### 3. Instalar e iniciar

```bash
npm install
npm run dev
```

Depois, abra `http://localhost:3000`.

## Método PUT

O requisito principal está em:

```text
app/api/todos/route.js
```

Exemplo de requisição:

```http
PUT /api/todos
Content-Type: application/json

{
  "id": 1,
  "title": "Tarefa editada",
  "completed": true
}
```

O `PUT` aceita atualização parcial de `title` e/ou `completed`, valida o identificador e devolve o registro atualizado.

## O que demonstrar na gravação

1. Aplicação aberta no navegador.
2. Criar uma tarefa.
3. Clicar em **Editar**, alterar o texto e salvar.
4. Marcar/desmarcar a tarefa como concluída.
5. Opcionalmente excluir uma tarefa.
6. Mostrar o terminal com o projeto executando.

Antes de gerar o ZIP de entrega, remova `node_modules` e não inclua `.env.local`.
