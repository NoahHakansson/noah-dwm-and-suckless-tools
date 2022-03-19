/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static int colorprompt = 1;                /* -p  option; if 1, prompt uses SchemeSel, otherwise SchemeNorm */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"monospace:size=11"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	               /*     fg         bg       */
	[SchemeNorm] = { "#abb2bf", "#1f2227" },
	[SchemeSel] = { "#1f2227", "#61afef" },
	[SchemeSelHighlight] = { "#ffffff", "#61afef" },
	[SchemeNormHighlight] = { "#ffffff", "#1f2227" },
	[SchemeOut] = { "#1f2227", "#00ffff" },
	[SchemeMid] = { "#abb2bf", "#1f2227" },
};
/* -l and -g options; controls number of lines and columns in grid if > 0 */
static unsigned int lines      = 8;
static unsigned int columns    = 1;
/* -h option; minimum height of a menu line */
static unsigned int lineheight = 0;
static unsigned int min_lineheight = 24;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static const unsigned int border_width = 2;
