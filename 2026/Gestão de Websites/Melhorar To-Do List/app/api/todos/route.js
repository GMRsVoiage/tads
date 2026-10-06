import { NextResponse } from "next/server";
import { pool } from "../../../lib/db";

function normalizeTodo(row) {
  return {
    id: Number(row.id),
    title: row.title,
    completed: Boolean(row.completed),
    createdAt: row.created_at,
  };
}

function parseId(value) {
  const id = Number(value);
  return Number.isInteger(id) && id > 0 ? id : null;
}

export async function GET() {
  try {
    const [rows] = await pool.query(
      "SELECT id, title, completed, created_at FROM todos ORDER BY id DESC"
    );

    return NextResponse.json({ todos: rows.map(normalizeTodo) });
  } catch (error) {
    console.error("GET /api/todos:", error);
    return NextResponse.json(
      { error: "Não foi possível carregar as tarefas." },
      { status: 500 }
    );
  }
}

export async function POST(request) {
  try {
    const body = await request.json();
    const title = typeof body.title === "string" ? body.title.trim() : "";

    if (!title) {
      return NextResponse.json(
        { error: "Informe o título da tarefa." },
        { status: 400 }
      );
    }

    const [result] = await pool.execute(
      "INSERT INTO todos (title, completed) VALUES (?, FALSE)",
      [title]
    );

    const [rows] = await pool.execute(
      "SELECT id, title, completed, created_at FROM todos WHERE id = ?",
      [result.insertId]
    );

    return NextResponse.json(
      { todo: normalizeTodo(rows[0]) },
      { status: 201 }
    );
  } catch (error) {
    console.error("POST /api/todos:", error);
    return NextResponse.json(
      { error: "Não foi possível criar a tarefa." },
      { status: 500 }
    );
  }
}

export async function PUT(request) {
  try {
    const body = await request.json();
    const id = parseId(body.id);

    if (!id) {
      return NextResponse.json(
        { error: "Informe um id válido." },
        { status: 400 }
      );
    }

    const updates = [];
    const values = [];

    if (body.title !== undefined) {
      const title = typeof body.title === "string" ? body.title.trim() : "";

      if (!title) {
        return NextResponse.json(
          { error: "O título não pode ficar vazio." },
          { status: 400 }
        );
      }

      updates.push("title = ?");
      values.push(title);
    }

    if (body.completed !== undefined) {
      if (typeof body.completed !== "boolean") {
        return NextResponse.json(
          { error: "completed deve ser true ou false." },
          { status: 400 }
        );
      }

      updates.push("completed = ?");
      values.push(body.completed);
    }

    if (updates.length === 0) {
      return NextResponse.json(
        { error: "Informe title e/ou completed para editar." },
        { status: 400 }
      );
    }

    values.push(id);

    const [result] = await pool.execute(
      `UPDATE todos SET ${updates.join(", ")} WHERE id = ?`,
      values
    );

    if (result.affectedRows === 0) {
      return NextResponse.json(
        { error: "Tarefa não encontrada." },
        { status: 404 }
      );
    }

    const [rows] = await pool.execute(
      "SELECT id, title, completed, created_at FROM todos WHERE id = ?",
      [id]
    );

    return NextResponse.json({ todo: normalizeTodo(rows[0]) });
  } catch (error) {
    console.error("PUT /api/todos:", error);
    return NextResponse.json(
      { error: "Não foi possível editar a tarefa." },
      { status: 500 }
    );
  }
}

export async function DELETE(request) {
  try {
    const id = parseId(new URL(request.url).searchParams.get("id"));

    if (!id) {
      return NextResponse.json(
        { error: "Informe um id válido." },
        { status: 400 }
      );
    }

    const [result] = await pool.execute("DELETE FROM todos WHERE id = ?", [id]);

    if (result.affectedRows === 0) {
      return NextResponse.json(
        { error: "Tarefa não encontrada." },
        { status: 404 }
      );
    }

    return NextResponse.json({ message: "Tarefa removida." });
  } catch (error) {
    console.error("DELETE /api/todos:", error);
    return NextResponse.json(
      { error: "Não foi possível excluir a tarefa." },
      { status: 500 }
    );
  }
}
