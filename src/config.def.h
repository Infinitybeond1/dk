/* In order to customize settings in this file, copy it to config.h and edit it
 *
 * see license file for copyright and license details */


static int gap[] = {
	[Width] = 0, /* gap width in pixels */
	[Smart] = 1, /* disable gaps in layouts with only one visible window */
};

static int border[] = {
	[Width] = 1,          /* border width in pixels */
	[Smart] = 1,          /* disable borders in layouts with only one visible window */
	[Focus] = 0x6699cc,   /* focused window border colours */
	[Unfocus] = 0x000000, /* unfocused window border colours */
	[Urgent] = 0xee5555,  /* urgent window border colours */
};

static int globalcfg[] = {
	[SizeHints] = 0,   /* respect size hints in tiled layouts */
	[FocusMouse] = 1,  /* enable focus follows mouse */
	[FocusUrgent] = 1, /* enable focus urgent windows */
	[NumWs] = 0,       /* number of workspaces currently allocated */
	[MinXY] = 10,      /* minimum window area allowed inside the screen when moving */
	[MinWH] = 50,      /* minimum window size allowed when resizing */
};

static const char *cursors[] = {
	[Move] = "fleur",
	[Normal] = "arrow",
	[Resize] = "sizing"
};

static void albumart(Client *c, int closed)
{ /* example of a simple callback for album art windows */
	if (closed)
		c->ws->padr = 0; /* remove padding */
	else {
		c->ws->padr = c->w + (2 * c->ws->gappx); /* padding to the right */
		gravitate(c, Right, Center, 1); /* right center of the screen */
		focus(c->snext); /* don't take focus */
	}
	layoutws(c->ws);
}


/* "callback" names recognized for use with rules.
 * Callback functions have the following prototype: void function(Client *, int); */
static Callback callbacks[] = {
	{ "albumart", albumart },
};


/* "layout" names used by cmdlayout() to parse arguments.
 * Layout functions have the following prototype: int function(Workspace *); */
static Layout layouts[] = {
	{ "tile", tile }, /* first is initial default */
	{ "mono", mono },
	{ "none", NULL },
};


static WsDefault wsdef = { /* settings for newly created workspaces */
	1,           /* nmaster */
	3,           /* nstack */
	0,           /* gappx */
	0,           /* padl */
	0,           /* padr */
	0,           /* padt */
	0,           /* padb */
	0.55,        /* split */
	0.55,        /* ssplit */
	&layouts[0]  /* layout */
};

/* default bindings for mouse move/resize */
static xcb_mod_mask_t mousemod = XCB_MOD_MASK_4;
static xcb_button_t mousemove = XCB_BUTTON_INDEX_1;
static xcb_button_t mouseresize = XCB_BUTTON_INDEX_3;
