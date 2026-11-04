-- Crie ou selecione o banco antes de executar este arquivo.
-- Localmente: CREATE DATABASE monitor_oportunidades CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
-- No Azure Database for MySQL, importe este arquivo usando o banco já criado.
CREATE TABLE users(id INT AUTO_INCREMENT PRIMARY KEY,name VARCHAR(120) NOT NULL,email VARCHAR(190) UNIQUE NOT NULL,password_hash VARCHAR(255) NOT NULL);
CREATE TABLE categories(id INT AUTO_INCREMENT PRIMARY KEY,name VARCHAR(80) UNIQUE NOT NULL);
CREATE TABLE opportunities(id INT AUTO_INCREMENT PRIMARY KEY,title VARCHAR(200) NOT NULL,organization VARCHAR(160) NOT NULL,city VARCHAR(120) NOT NULL,description TEXT NOT NULL,deadline VARCHAR(30) NOT NULL,link VARCHAR(500) NOT NULL,status VARCHAR(30) NOT NULL DEFAULT 'aberto',category_id INT NOT NULL,FOREIGN KEY(category_id) REFERENCES categories(id));
CREATE TABLE favorites(user_id INT NOT NULL,opportunity_id INT NOT NULL,PRIMARY KEY(user_id,opportunity_id),FOREIGN KEY(user_id) REFERENCES users(id),FOREIGN KEY(opportunity_id) REFERENCES opportunities(id) ON DELETE CASCADE);
INSERT IGNORE INTO categories(name) VALUES ('Concurso'),('PSS'),('Bolsa'),('Curso');
INSERT INTO opportunities(title,organization,city,description,deadline,link,category_id) SELECT 'Processo Seletivo Simplificado 2026','IFPR','Telêmaco Borba/PR','Seleção para contratação temporária de profissionais.','20/12/2026','https://www.ifpr.edu.br/',id FROM categories WHERE name='PSS' AND NOT EXISTS (SELECT 1 FROM opportunities);
