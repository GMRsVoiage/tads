import { NextResponse } from "next/server";
import { db } from "../../../lib/db";

export async function GET() {
  try {
    await db.query("SELECT 1");
    return NextResponse.json({ status: "ok", database: "ok" });
  } catch (error) {
    console.error("Health check do banco falhou:", error);
    return NextResponse.json(
      { status: "error", database: "unavailable" },
      { status: 503 },
    );
  }
}
