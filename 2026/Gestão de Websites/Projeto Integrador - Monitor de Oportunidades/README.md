# Monitor de Oportunidades

Projeto integrador de Gestão de Websites — IFPR, Prof. Melissa Cordeiro.

Aplicação web em Next.js com API REST, banco MySQL, cadastro de usuários, senha com hash, CRUD de oportunidades, relacionamento com categorias e relatório com filtros.

## Executar

```bash
npm install
npm run dev
```

Crie o banco `monitor_oportunidades`, execute `database.sql`, copie `.env.example` para `.env.local` e ajuste as credenciais. Depois acesse `http://localhost:3000`.

Para validar a conexão com o banco, acesse `http://localhost:3000/api/health`.

## Publicar no Azure

Use uma arquitetura com **Azure App Service (Node.js)** para a aplicação e
**Azure Database for MySQL - Flexible Server** para os dados.

1. Crie o servidor MySQL e um banco chamado `monitor_oportunidades`.
2. Libere no servidor MySQL o acesso do App Service e importe `database.sql`
   selecionando esse banco:

   ```bash
   mysql -h SEU_SERVIDOR.mysql.database.azure.com -u USUARIO -p monitor_oportunidades < database.sql
   ```

3. Crie um App Service Linux com Node 20 ou superior e configure as
   Application settings:

   ```text
   DB_HOST=SEU_SERVIDOR.mysql.database.azure.com
   DB_PORT=3306
   DB_USER=USUARIO
   DB_PASSWORD=SENHA
   DB_NAME=monitor_oportunidades
   DB_SSL=true
   DB_SSL_REJECT_UNAUTHORIZED=false
   ```

4. Configure o deploy pelo GitHub Actions, Deployment Center ou `az webapp
   deploy`. O App Service executará `npm install`, `npm run build` e `npm
   start`; a variável `PORT` do Azure é usada automaticamente pelo Next.js.
5. Teste `https://SEU_APP.azurewebsites.net/api/health`. O resultado esperado é
   `{"status":"ok","database":"ok"}`.

Não versionar `.env.local` nem as credenciais do Azure. O arquivo `.env.example`
contém somente os nomes das variáveis necessárias.

## API

- `GET /api/opportunities?q=&category=` — relatório filtrado
- `POST /api/opportunities` — cadastra oportunidade
- `PUT /api/opportunities` — edita oportunidade
- `DELETE /api/opportunities?id=1` — exclui oportunidade
- `POST /api/auth/register` — cadastra usuário com senha protegida por hash
- `POST /api/auth/login` — autentica credenciais
