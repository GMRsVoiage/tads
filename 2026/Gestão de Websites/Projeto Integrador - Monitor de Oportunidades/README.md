# Monitor de Oportunidades

Projeto integrador de Gestão de Websites — IFPR, Prof. Melissa Cordeiro.

Aplicação web em Next.js com API REST, banco MySQL, cadastro de usuários, senha com hash, CRUD de oportunidades, relacionamento com categorias e relatório com filtros.

## Executar

```bash
npm install
npm run dev
```

Execute `database.sql`, configure `DB_HOST`, `DB_USER`, `DB_PASSWORD` e `DB_NAME=monitor_oportunidades`, depois acesse `http://localhost:3000`.

## API

- `GET /api/opportunities?q=&category=` — relatório filtrado
- `POST /api/opportunities` — cadastra oportunidade
- `PUT /api/opportunities` — edita oportunidade
- `DELETE /api/opportunities?id=1` — exclui oportunidade
- `POST /api/auth/register` — cadastra usuário com senha protegida por hash
- `POST /api/auth/login` — autentica credenciais
