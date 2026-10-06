"use client";

import { useEffect, useState } from "react";

export default function Home() {
  const [todos, setTodos] = useState([]);
  const [newTitle, setNewTitle] = useState("");
  const [editingId, setEditingId] = useState(null);
  const [editingTitle, setEditingTitle] = useState("");
  const [message, setMessage] = useState("Carregando tarefas...");
  const [busyId, setBusyId] = useState(null);

  async function readJson(response) {
    const data = await response.json();

    if (!response.ok) {
      throw new Error(data.error || "A operação falhou.");
    }

    return data;
  }

  async function loadTodos() {
    try {
      const response = await fetch("/api/todos", { cache: "no-store" });
      const data = await readJson(response);
      setTodos(data.todos);
      setMessage(data.todos.length ? "" : "Nenhuma tarefa cadastrada.");
    } catch (error) {
      setMessage(error.message);
    }
  }

  useEffect(() => {
    loadTodos();
  }, []);

  async function createTodo(event) {
    event.preventDefault();
    const title = newTitle.trim();

    if (!title) {
      setMessage("Digite uma tarefa antes de adicionar.");
      return;
    }

    setBusyId("new");
    setMessage("");

    try {
      const response = await fetch("/api/todos", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ title }),
      });

      const data = await readJson(response);
      setTodos((current) => [data.todo, ...current]);
      setNewTitle("");
    } catch (error) {
      setMessage(error.message);
    } finally {
      setBusyId(null);
    }
  }

  function beginEdit(todo) {
    setEditingId(todo.id);
    setEditingTitle(todo.title);
    setMessage("");
  }

  function cancelEdit() {
    setEditingId(null);
    setEditingTitle("");
  }

  async function updateTodo(todo, changes) {
    setBusyId(todo.id);
    setMessage("");

    try {
      const response = await fetch("/api/todos", {
        method: "PUT",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ id: todo.id, ...changes }),
      });

      const data = await readJson(response);

      setTodos((current) =>
        current.map((item) => (item.id === todo.id ? data.todo : item))
      );

      return true;
    } catch (error) {
      setMessage(error.message);
      return false;
    } finally {
      setBusyId(null);
    }
  }

  async function saveEdit(todo) {
    const title = editingTitle.trim();

    if (!title) {
      setMessage("O título não pode ficar vazio.");
      return;
    }

    const saved = await updateTodo(todo, { title });

    if (saved) {
      cancelEdit();
    }
  }

  async function removeTodo(todo) {
    setBusyId(todo.id);
    setMessage("");

    try {
      const response = await fetch(`/api/todos?id=${todo.id}`, {
        method: "DELETE",
      });

      await readJson(response);
      const next = todos.filter((item) => item.id !== todo.id);
      setTodos(next);
      setMessage(next.length ? "" : "Nenhuma tarefa cadastrada.");
    } catch (error) {
      setMessage(error.message);
    } finally {
      setBusyId(null);
    }
  }

  return (
    <main className="page">
      <section className="todo-card">
        <header>
          <p className="eyebrow">Gestão de Websites</p>
          <h1>To-Do List</h1>
          <p className="subtitle">
            CRUD com Next.js, MySQL e edição usando o método HTTP PUT.
          </p>
        </header>

        <form className="new-todo" onSubmit={createTodo}>
          <label htmlFor="new-title">Nova tarefa</label>
          <div className="input-row">
            <input
              id="new-title"
              value={newTitle}
              onChange={(event) => setNewTitle(event.target.value)}
              placeholder="Ex.: revisar a atividade"
              maxLength={255}
            />
            <button type="submit" disabled={busyId === "new"}>
              {busyId === "new" ? "Adicionando..." : "Adicionar"}
            </button>
          </div>
        </form>

        {message && <p className="message">{message}</p>}

        <ul className="todo-list">
          {todos.map((todo) => {
            const isEditing = editingId === todo.id;
            const isBusy = busyId === todo.id;

            return (
              <li key={todo.id} className={todo.completed ? "done" : ""}>
                {isEditing ? (
                  <div className="edit-row">
                    <label className="sr-only" htmlFor={`edit-${todo.id}`}>
                      Editar tarefa
                    </label>
                    <input
                      id={`edit-${todo.id}`}
                      value={editingTitle}
                      onChange={(event) => setEditingTitle(event.target.value)}
                      maxLength={255}
                      autoFocus
                    />
                    <button
                      type="button"
                      onClick={() => saveEdit(todo)}
                      disabled={isBusy}
                    >
                      Salvar
                    </button>
                    <button
                      type="button"
                      className="secondary"
                      onClick={cancelEdit}
                      disabled={isBusy}
                    >
                      Cancelar
                    </button>
                  </div>
                ) : (
                  <>
                    <label className="todo-main">
                      <input
                        type="checkbox"
                        checked={todo.completed}
                        onChange={() =>
                          updateTodo(todo, { completed: !todo.completed })
                        }
                        disabled={isBusy}
                      />
                      <span>{todo.title}</span>
                    </label>

                    <div className="actions">
                      <button
                        type="button"
                        className="secondary"
                        onClick={() => beginEdit(todo)}
                        disabled={isBusy}
                      >
                        Editar
                      </button>
                      <button
                        type="button"
                        className="danger"
                        onClick={() => removeTodo(todo)}
                        disabled={isBusy}
                      >
                        Excluir
                      </button>
                    </div>
                  </>
                )}
              </li>
            );
          })}
        </ul>

        <footer>
          <code>PUT /api/todos</code>
          <span>{todos.length} tarefa(s)</span>
        </footer>
      </section>
    </main>
  );
}
