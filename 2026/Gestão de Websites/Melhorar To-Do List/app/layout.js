import "./globals.css";

export const metadata = {
  title: "To-Do List",
  description: "Atividade de Gestão de Websites com CRUD e método PUT",
};

export default function RootLayout({ children }) {
  return (
    <html lang="pt-BR">
      <body>{children}</body>
    </html>
  );
}
