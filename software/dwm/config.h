#define FONT "Ubuntu Nerd Font:size=13"
#define BROWSER "google-chrome"
#define TERM "st"
#define FILEMAN "pcmanfm"
#define S "/home/sheep/.scripts/"

/* See LICENSE file for copyright and license details. */

#include <X11/XF86keysym.h>

#ifndef uint
#define uint unsigned int
#endif /* uint */
#ifndef NULL
#define NULL (void*) 
#endif /* NULL */


/* appearance */
static uint borderpx                    = 1;        /* border pixel of windows */
static uint snap                        = 32;       /* snap pixel */
static int     systraypinning              = 0;
static int     systrayonleft               = 0;
static uint systrayspacing              = 3; 
static int     systraypinningfailfirst     = 1; 
/* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static int     showsystray                 = 1;
static int     showbar                     = 1;
static int     topbar                      = 1;

static const char *fonts[]          = { FONT };

/* layout(s) */
static const float mfact     = 0.55;
/* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;
/* number of clients in master area */
static const int resizehints = 1;
/* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1;
/* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

#include "catppuccin.h"
static const char *colors[][3]      = {
    /*                     fg       bg      border */
    [SchemeNorm]       = { textc,   black,  gray2 },
    [SchemeSel]        = { gray4,   blue,   blue  },
    { textc,   red,    red   },
    { textc,   black,  gray2 },
    { blue,    gray2,  black },
    { gray3,   black,  black },
    { gray3,   black,  black },
    { blue,    black,  black },
    { red,     black,  black },
    { orange,  black,  black },
    { green,   black,  black },
    { pink,    black,  black },
    { green,   black,  black },
    { green,   black,  black },
    { yellow,  black,  black },
    { red,     black,  black },
};

static const char *const autostart[] = {
    "xss-lock", "--", "slock", NULL,
    "sh", "-c", "feh --bg-scale ~/d/pic/background.png &", NULL,
    "sbar", NULL,
    "fcitx5", NULL,
    "wmname" "LG3D", NULL,
    "mpd", NULL,
    "xrandr", "--dpi", "141", NULL,
    "xrdb", "-load", "/home/sheep/.Xresources", NULL,
    "aw-qt", NULL,
    NULL, NULL /* terminate */
};

/* tagging */
//static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
    { "Gimp",     NULL,       NULL,       0,            1,           -1 },
    /* zero initing this will cause dwm to behave weird with multi monitor steup */
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

static char dmenumon[] = "0";
/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL };
static const char *jdmenucmd[] = { "j4-dmenu-desktop", "--dmenu=\"/usr/local/bin/dmenu\"", "--term=" TERM };
static const char *termcmd[]  = { TERM, NULL };
static const char *browsercmd[] = { BROWSER, NULL };
static const char *lockcmd[] = { "slock", NULL };
static const char *brupcmd[] = { "xbacklight", "-inc", "2", NULL };
static const char *brdowncmd[] = { "xbacklight", "-dec", "2", NULL };
static const char *mutecmd[] = { S"volume", "mute", NULL };
static const char *volupcmd[] = { S"volume", "+2", NULL };
static const char *voldowncmd[] = { S"volume", "-2", NULL };
static const char *touchpadtogglecmd[] = { S"touchpad_toggle" , NULL };
static const char *flameshotcmd[] = { "flameshot", "gui", NULL };
static const char *filemancmd[] = { FILEMAN, NULL };
//static const char *powermenucmd[] = { "sudo", "powerdmenu", NULL };
static const char *emojipickcmd[] = { S"emojipick", NULL };
static const char *displaycmd[] = { S"display", NULL };
static const char *mainmenucmd[] = { S"mainmenu", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,  spawn,          {.v = mainmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_p,      spawn,          {.v = jdmenucmd } },
	{ MODKEY|ShiftMask,             XK_b,      spawn,          {.v = browsercmd } },
	{ MODKEY,                       XK_Escape, spawn,          {.v = lockcmd } },
	//{ MODKEY|ShiftMask,             XK_Escape, spawn,          {.v = powermenucmd } },
	{ MODKEY|ShiftMask,             XK_d, spawn,               {.v = displaycmd } },
    { ALTKEY,                       XK_s,      spawn,          {.v = flameshotcmd } },
    { MODKEY|ShiftMask,             XK_f,      spawn,          {.v = filemancmd } },
	{ ALTKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_q,      spawn,          {.v = voldowncmd } },
	{ MODKEY,                       XK_w,      spawn,          {.v = mutecmd } },
	{ MODKEY,                       XK_e,      spawn,          {.v = volupcmd } },
	{ MODKEY,                       XK_c,      spawn,          {.v = emojipickcmd } },
	{ 0,                            XF86XK_AudioMute,          spawn, {.v = mutecmd } },
	{ 0,                            XF86XK_AudioLowerVolume,   spawn, {.v = voldowncmd } },
	{ 0,                            XF86XK_AudioRaiseVolume,   spawn, {.v = volupcmd } },
	{ 0,                            XF86XK_TouchpadToggle,     spawn, {.v = touchpadtogglecmd } },
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
	//{ MODKEY,                       XK_space,  setlayout,      {0} },
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
	{ MODKEY|ShiftMask,             XK_c,      quit,           {0} },
	{ MODKEY,                       XK_s,      togglesticky,   {0} },
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
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

/* sticky indicator */
static const XPoint stickyicon[]    = { {0,0}, {4,0}, {4,8}, {2,6}, {0,8}, {0,0} }; /* represents the icon as an array of vertices */
static const XPoint stickyiconbb    = {4,8};	/* defines the bottom right corner of the polygon's bounding box (speeds up scaling) */




///* See LICENSE file for copyright and license details. */
//
///* appearance */
//static const uint int borderpx  = 1;        /* border pixel of windows */
//static const uint int snap      = 32;       /* snap pixel */
//static const int showbar            = 1;        /* 0 means no bar */
//static const int topbar             = 1;        /* 0 means bottom bar */
//static const char *fonts[]          = { "monospace:size=10" };
//static const char dmenufont[]       = "monospace:size=10";
//static const char col_gray1[]       = "#222222";
//static const char col_gray2[]       = "#444444";
//static const char col_gray3[]       = "#bbbbbb";
//static const char col_gray4[]       = "#eeeeee";
//static const char col_cyan[]        = "#005577";
//static const char *colors[][3]      = {
//	/*               fg         bg         border   */
//	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
//	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
//};
//
///* tagging */
//static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
//
//static const Rule rules[] = {
//	/* xprop(1):
//	 *	WM_CLASS(STRING) = instance, class
//	 *	WM_NAME(STRING) = title
//	 */
//	/* class      instance    title       tags mask     isfloating   monitor */
//	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
//	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
//};
//
///* layout(s) */
//static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
//static const int nmaster     = 1;    /* number of clients in master area */
//static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
//static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
//
//static const Layout layouts[] = {
//	/* symbol     arrange function */
//	{ "[]=",      tile },    /* first entry is default */
//	{ "><>",      NULL },    /* no layout function means floating behavior */
//	{ "[M]",      monocle },
//};
//
///* key definitions */
//#define MODKEY Mod1Mask
//#define TAGKEYS(KEY,TAG) \
//	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
//	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
//	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
//	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
//
///* helper for spawning shell commands in the pre dwm-5.0 fashion */
//#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
//
///* commands */
//static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
//static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
//static const char *termcmd[]  = { "st", NULL };
//
//static Key keys[] = {
//	/* modifier                     key        function        argument */
//	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
//	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
//	{ MODKEY,                       XK_b,      togglebar,      {0} },
//	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
//	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
//	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
//	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
//	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
//	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
//	{ MODKEY,                       XK_Return, zoom,           {0} },
//	{ MODKEY,                       XK_Tab,    view,           {0} },
//	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
//	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
//	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
//	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
//	{ MODKEY,                       XK_space,  setlayout,      {0} },
//	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
//	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
//	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
//	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
//	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
//	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
//	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
//	TAGKEYS(                        XK_1,                      0)
//	TAGKEYS(                        XK_2,                      1)
//	TAGKEYS(                        XK_3,                      2)
//	TAGKEYS(                        XK_4,                      3)
//	TAGKEYS(                        XK_5,                      4)
//	TAGKEYS(                        XK_6,                      5)
//	TAGKEYS(                        XK_7,                      6)
//	TAGKEYS(                        XK_8,                      7)
//	TAGKEYS(                        XK_9,                      8)
//	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
//};
//
///* button definitions */
///* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
//static Button buttons[] = {
//	/* click                event mask      button          function        argument */
//	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
//	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
//	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
//	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
//	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
//	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
//	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
//	{ ClkTagBar,            0,              Button1,        view,           {0} },
//	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
//	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
//	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
//};
//
