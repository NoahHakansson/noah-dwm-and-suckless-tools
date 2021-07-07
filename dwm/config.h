/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 3;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int barPadding = 2;       /* padding of topbar font height */
static const unsigned int systraypinning = 1;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 0;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=11", "JetBrainsMono Nerd Font Regular:size=11" };
static const char dmenufont[]       = "monospace:size=11";
static const char col_gray1[]       = "#1d2021"; // background color
static const char col_gray2[]       = "#7c6f64"; // inactive window border color
static const char col_gray3[]       = "#ebdbb2"; // font color
static const char col_gray4[]       = "#ebdbb2"; // current tag and window font color
static const char col_cyan[]        = "#458588"; // top bar second "color" and active window border color
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeInv]  = { col_gray3, col_gray2, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
// Volume control constants
static const char *upvol[]   = { "/home/noah/suckless/scripts/vol_up.sh",        NULL };
static const char *downvol[] = { "/home/noah/suckless/scripts/vol_down.sh",      NULL };
static const char *mutevol[] = { "/home/noah/suckless/scripts/vol_mute.sh",      NULL };
// Scripts
static const char *scrotShot[] = { "/home/noah/suckless/scripts/scrotShot.sh",       NULL };
// Screen brightness
static const char *brightnessUp[] = { "/home/noah/suckless/scripts/brightness_up.sh",       NULL };
static const char *brightnessDown[] = { "/home/noah/suckless/scripts/brightness_down.sh",       NULL };

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                instance  title                 tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",                NULL,     NULL,                   0,         1,          0,           1,        -1 },
	{ "Wireshark",           NULL,     NULL,                   0,         0,          0,           1,        -1 },
	{ "qalculate-gtk",       NULL,     NULL,                   0,         1,          0,           1,        -1 },
	{ "Blueman-manager",     NULL,     NULL,                   0,         1,          0,           1,        -1 },
	{  NULL,                 "zoom",   "Chat",                 0,         1,          0,           1,        -1 },
	{ "Tilix",               "tilix",  "Tilix: pulsemixer",    0,         1,          0,           1,        -1 },
	{ "Mail",                NULL,     NULL,                   0,         1,          0,           1,        -1 },
	{ "Pavucontrol",         NULL,     NULL,                   0,         1,          0,           0,        -1 },
	{ "discord",             NULL,     NULL,                   1 << 7,    0,          0,          -1,         0 },
	{ "Alacritty",           NULL,     NULL,                   0,         0,          1,           0,        -1 },
	{ "Tilix",               NULL,     NULL,                   0,         0,          1,           0,        -1 },
	{ "St",                  NULL,     NULL,                   0,         0,          1,           0,        -1 },
	{ NULL,                  NULL,     "Event Tester",         0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.6; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const char dmenuWidth[4] = "500";
static const char dmenuXoffset[4] = "288";
static const char dmenuYoffset[3] = "0";

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4,
	"-z", dmenuWidth, "-x", dmenuXoffset, "-y", dmenuYoffset, NULL };
static const char *roficmd[]  = { "rofi", "-show", "run", NULL }; // rofi run launcher
static const char *termcmd[]  = { "alacritty", NULL }; // terminal
static const char *browsercmd[]  = { "brave-browser", NULL }; // browser
static const char *volumecmd[]  = { "pavucontrol", NULL }; // audio control panel
static const char *filescmd[]  = { "pcmanfm", NULL }; // file manager
static const char *lockAndsuspendcmd[]  = { "slock", "systemctl", "suspend", NULL }; // lock screen + suspend
static const char *screenLockcmd[]  = { "slock", NULL }; // lock screen

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_r,      spawn,          {.v = roficmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          {.v = browsercmd } },
	{ MODKEY|ShiftMask,             XK_v,      spawn,          {.v = volumecmd } }, // start volumecontrol
	{ MODKEY|ShiftMask,             XK_f,      spawn,          {.v = filescmd } }, // start volumecontrol
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = lockAndsuspendcmd } }, // lock and suspend
	{ MODKEY,                       XK_s,      spawn,          {.v = screenLockcmd } }, // lock screen
	{ MODKEY,                       XK_Up,     spawn,          {.v = upvol   } }, // volume up
	{ MODKEY,                       XK_Down,   spawn,          {.v = downvol } }, // volume down
	{ MODKEY|ShiftMask,             XK_End,    spawn,          {.v = mutevol } }, // volume toggle mute
	{ MODKEY|ShiftMask,             XK_Up,     spawn,          {.v = brightnessUp } }, // Screen brightness up
	{ MODKEY|ShiftMask,             XK_Down,   spawn,          {.v = brightnessDown } }, // Screen brightness down
	{ MODKEY|ControlMask,           XK_p,      spawn,          {.v = scrotShot } }, // screenshot area to clipboard
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_h,      focusstack,     {.i = -1 } },        // move down in stack
	{ MODKEY,                       XK_l,      focusstack,     {.i = +1 } },        // move up in stack
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_j,      setmfact,       {.f = -0.05} }, // decrease master size
	{ MODKEY,                       XK_k,      setmfact,       {.f = +0.05} }, // Increase master size
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY|ControlMask,           XK_h,      focusmon,       {.i = -1 } }, // Move focus to monitor left
	{ MODKEY|ControlMask,           XK_l,      focusmon,       {.i = +1 } }, // Move focus to monitor right
	{ MODKEY|ShiftMask,             XK_h,      tagmon,         {.i = -1 } }, // Move window to monitor left
	{ MODKEY|ShiftMask,             XK_l,      tagmon,         {.i = +1 } }, // Move window to monitor right
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_Delete,      quit,           {0} }, // Exit dwm
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

