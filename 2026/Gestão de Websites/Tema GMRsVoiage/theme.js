(() => {
	const root = document.documentElement;
	const button = document.querySelector(".gmrs-theme-toggle");
	const label = button?.querySelector(".gmrs-theme-toggle__label");
	const icon = button?.querySelector(".gmrs-theme-toggle__icon");
	const preferenceKey = "gmrsvoiage-theme";

	if (!button || !label || !icon) {
		return;
	}

	const savedTheme = window.localStorage.getItem(preferenceKey);
	const currentHour = new Date().getHours();
	let theme = savedTheme === "aero" || savedTheme === "vaporwave"
		? savedTheme
		: currentHour >= 6 && currentHour < 18
			? "aero"
			: "vaporwave";

	const applyTheme = (nextTheme) => {
		theme = nextTheme;
		root.dataset.gmrsTheme = theme;
		const isAero = theme === "aero";
		label.textContent = isAero ? "Aero" : "Vaporwave";
		icon.textContent = isAero ? "☀" : "☾";
		button.setAttribute("aria-pressed", String(isAero));
		button.setAttribute(
			"aria-label",
			`Tema ${isAero ? "Aero" : "Vaporwave"} ativo. Alternar para ${isAero ? "Vaporwave" : "Aero"}.`
		);
	};

	applyTheme(theme);

	button.addEventListener("click", () => {
		const nextTheme = theme === "aero" ? "vaporwave" : "aero";
		window.localStorage.setItem(preferenceKey, nextTheme);
		applyTheme(nextTheme);
	});
})();
