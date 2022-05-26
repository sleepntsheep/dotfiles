#include <X11/XF86keysym.h>

#define JBFONT "JetBrainsMono Nerd Font:size=13"

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const char *fonts[]          = { JBFONT, "monospace:size=13" }; /* index > 1 are fallback fonts */
static const char pangofont[]       = JBFONT;

static const unsigned int snap           = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const unsigned int gappx              = 10;
static const unsigned int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const unsigned int showsystray        = 1;     /* 0 means no systray */
static const unsigned int showbar            = 1;     /* 0 means no bar */
static const unsigned int topbar             = 1;     /* 0 means bottom bar */
static const unsigned int statusmarkup       = 1;     /* True means use pango markup in status message */

/* i use xinitrc instead but the patch is there*/
static const char *const autostart[] = {
//	"slstatus", NULL,
//    "sh", "-c", "setxkbmap -layout 'us,th' -variant ,ThaiMnc -option 'grp:alt_shift_toggle'", NULL,
//    "sh", "-c", "xrdb ~/.Xresources", NULL,
//    "xcompmgr", NULL,
//    "sh", "-c", "feh --bg-scale ~/d/pic/wall/momokuri_crop.png", NULL,
//    "redshift", NULL,
//    "mpd", NULL,
//    "picom --experimental-backends", NULL,
//	NULL /* terminate */
    NULL, NULL
};

/* tagging */
static char normbgcolor[]           = "#2b3339";
static char normbordercolor[]       = "#323c41";
static char normfgcolor[]           = "#d3c6aa";
static char selfgcolor[]            = "#d3c6aa";
static char selbordercolor[]        = "#445055";
static char selbgcolor[]            = "#445055";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
	   [SchemeUrgent]=	 { selfgcolor,  selbgcolor,  selbordercolor  },
};
 

/* Xresources preferences to load at startup */
ResourcePref resources[] = {0};
/* ResourcePref resources[] = {
		{ "font",               STRING,  &fonts[0] },
		{ "normbgcolor",        STRING,  &normbgcolor },
		{ "normbordercolor",    STRING,  &normbordercolor },
		{ "normfgcolor",        STRING,  &normfgcolor },
		{ "selbgcolor",         STRING,  &selbgcolor },
		{ "selbordercolor",     STRING,  &selbordercolor },
		{ "selfgcolor",         STRING,  &selfgcolor },
		{ "borderpx",          	INTEGER, &borderpx },
		{ "snap",          		INTEGER, &snap },
		{ "showbar",          	INTEGER, &showbar },
		{ "topbar",          	INTEGER, &topbar },
		{ "nmaster",          	INTEGER, &nmaster },
		{ "resizehints",       	INTEGER, &resizehints },
		{ "mfact",      	 	FLOAT,   &mfact },
}; */


static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	//{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define ALTKEY Mod1Mask
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL };
static const char *termcmd[]  = { "tabbed", "st", "-w", NULL };
static const char *chromecmd[] = { "google-chrome-unstable", NULL };
static const char *slockcmd[] = { "slock", NULL };
static const char *brupcmd[] = { "xbacklight", "-inc", "2", NULL };
static const char *brdowncmd[] = { "xbacklight", "-dec", "2", NULL };
static const char *mutecmd[] = { "volume", "mute", NULL };
static const char *volupcmd[] = { "volume", "+2", NULL };
static const char *voldowncmd[] = { "volume", "-2", NULL };
static const char *touchpadtogglecmd[] = { "touchpad_toggle.sh" , NULL };
static const char *scrshotcmd[] = { "scrot", "-s", "~/scrot/%b%d_%H%M%S.png", NULL };
static const char *flameshotcmd[] = { "flameshot", "gui", NULL };
static const char *pcmanfmcmd[] = { "pcmanfm", NULL };
static const char *xkillcmd[] = { "xkill", NULL };
static const char *powermenucmd[] = { "sudo", "powerdmenu", NULL };
static const char *emojipickcmd[] = { "emojipick", NULL };
static const char *surfcmd[] = { "tabbed", "surf", "-e", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_b,      spawn,          {.v = chromecmd } },
    { MODKEY,                       XK_b,      spawn,          {.v = surfcmd } },
	{ MODKEY,                       XK_Escape, spawn,          {.v = slockcmd } },
	{ MODKEY|ShiftMask,             XK_Escape, spawn,          {.v = powermenucmd } },
	{ ALTKEY,                       XK_Escape, spawn,          {.v = xkillcmd } },
    { ALTKEY|ShiftMask,             XK_s,      spawn,          {.v = scrshotcmd } },
    { ALTKEY,                       XK_s,      spawn,          {.v = flameshotcmd } },
    { MODKEY|ShiftMask,             XK_f,      spawn,          {.v = pcmanfmcmd } },
	{ ALTKEY,                       XK_b,      togglebar,      {0} },
	{ 0,                            XF86XK_AudioMute,          spawn, {.v = mutecmd } },
	{ 0,                            XF86XK_AudioLowerVolume,   spawn, {.v = voldowncmd } },
	{ 0,                            XF86XK_AudioRaiseVolume,   spawn, {.v = volupcmd } },
	{ 0,                            XF86XK_TouchpadToggle,     spawn, {.v = touchpadtogglecmd } },
	{ MODKEY,                       XK_q,      spawn,          {.v = voldowncmd } },
	{ MODKEY,                       XK_w,      spawn,          {.v = mutecmd } },
	{ MODKEY,                       XK_e,      spawn,          {.v = volupcmd } },
	{ MODKEY,                       XK_e,      spawn,          {.v = volupcmd } },
	{ MODKEY,                       XK_c,      spawn,          {.v = emojipickcmd } },
	{ 0,                            XF86XK_MonBrightnessUp,    spawn, {.v = brupcmd} },
	{ 0,                            XF86XK_MonBrightnessDown,  spawn, {.v = brdowncmd} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
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
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	/*{ MODKEY|ShiftMask,             XK_c,      quit,           {0} },*/
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	{ MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = gappx  } },
	{ MODKEY,                       XK_s,      togglesticky,   {0} },
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

