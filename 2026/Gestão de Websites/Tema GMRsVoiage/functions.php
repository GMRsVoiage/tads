<?php
/**
 * Theme functions for the GMRsVoiage child theme.
 */

function gmrsvoiage_enqueue_assets() {
	$theme = wp_get_theme();
	$parent_theme = wp_get_theme(get_template());
	$stylesheet_version = filemtime(get_stylesheet_directory() . '/style.css') ?: $theme->get('Version');
	$script_version = filemtime(get_stylesheet_directory() . '/theme.js') ?: $theme->get('Version');

	wp_enqueue_style(
		'gmrsvoiage-parent',
		get_template_directory_uri() . '/style.css',
		array(),
		$parent_theme->get('Version')
	);

	wp_enqueue_style(
		'gmrsvoiage-style',
		get_stylesheet_uri(),
		array('gmrsvoiage-parent'),
		$stylesheet_version
	);

	wp_enqueue_script(
		'gmrsvoiage-theme-toggle',
		get_stylesheet_directory_uri() . '/theme.js',
		array(),
		$script_version,
		true
	);
}
add_action('wp_enqueue_scripts', 'gmrsvoiage_enqueue_assets');

function gmrsvoiage_add_home_intro($block_content, $block) {
	if (
		!is_array($block)
		|| !isset($block['attrs']['slug'])
		|| 'header-small-dark' !== $block['attrs']['slug']
		|| (!is_front_page() && !is_home())
	) {
		return $block_content;
	}

	$intro = '<section class="gmrs-home-intro" aria-labelledby="gmrs-home-title">'
		. '<p class="gmrs-home-intro__eyebrow">CÓDIGO · ARTE · CURIOSIDADE</p>'
		. '<h2 id="gmrs-home-title">Um cantinho para criar, explorar e compartilhar.</h2>'
		. '<p class="gmrs-home-intro__copy">Bem-vindo ao meu universo digital. Projetos, ideias e experiências conectadas por uma vontade: fazer acontecer.</p>'
		. '</section>';

	return $block_content . $intro;
}
add_filter('render_block', 'gmrsvoiage_add_home_intro', 10, 2);

function gmrsvoiage_add_theme_toggle() {
	?>
	<button class="gmrs-theme-toggle" type="button" aria-label="Alternar tema visual" aria-pressed="false">
		<span class="gmrs-theme-toggle__icon" aria-hidden="true">◐</span>
		<span class="gmrs-theme-toggle__label">Tema</span>
	</button>
	<?php
}
add_action('wp_footer', 'gmrsvoiage_add_theme_toggle');
