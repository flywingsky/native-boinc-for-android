///////////////////////////////////////////////////////////////////////////////
// Name:		wxFlatNotebook.cpp
// Purpose:     generic implementation of flat style notebook class.
// Author:      Eran Ifrah <eranif@bezeqint.net>
// Modified by: Priyank Bolia <soft@priyank.in>
// Created:     30/12/2005
// Modified:    01/01/2006
// Copyright:   Eran Ifrah (c)
// Licence:     wxWindows license <http://www.wxwidgets.org/licence3.txt>
///////////////////////////////////////////////////////////////////////////////

#ifndef WXFLATNOTEBOOKIMAGES_H
#define WXFLATNOTEBOOKIMAGES_H


///////////////////////////////////////////////////////////////////////////////
// 
// XPM Images required by this control
//
///////////////////////////////////////////////////////////////////////////////

namespace FNB
{
	////////////////////////////////////////////////////////////
	// Images used by the control
	////////////////////////////////////////////////////////////
	/* XPM */
	static char *left_arrow_disabled_xpm[] = {
		/* width height num_colors chars_per_pixel */
		"    16    16        8            1",
			/* colors */
			"` c #008080",
			". c #555555",
			"# c #000000",
			"a c #000000",
			"b c #000000",
			"c c #000000",
			"d c #000000",
			"e c #000000",
			/* pixels */
			"````````````````",
			"````````````````",
			"````````````````",
			"````````.```````",
			"```````..```````",
			"``````.`.```````",
			"`````.``.```````",
			"````.```.```````",
			"`````.``.```````",
			"``````.`.```````",
			"```````..```````",
			"````````.```````",
			"````````````````",
			"````````````````",
			"````````````````",
			"````````````````"
	};

	/* XPM */
	static char *x_button_pressed_xpm[] = {
		/* width height num_colors chars_per_pixel */
		"    16    16        8            1",
			/* colors */
			"` c #008080",
			". c #4766e0",
			"# c #9e9ede",
			"a c #000000",
			"b c #000000",
			"c c #000000",
			"d c #000000",
			"e c #000000",
			/* pixels */
			"````````````````",
			"`..............`",
			"`.############.`",
			"`.############.`",
			"`.############.`",
			"`.###aa####aa#.`",
			"`.####aa##aa##.`",
			"`.#####aaaa###.`",
			"`.######aa####.`",
			"`.#####aaaa###.`",
			"`.####aa##aa##.`",
			"`.###aa####aa#.`",
			"`.############.`",
			"`..............`",
			"````````````````",
			"````````````````"
	};


	/* XPM */
	static char *left_arrow_xpm[] = {
		/* width height num_colors chars_per_pixel */
		"    16    16        8            1",
			/* colors */
			"` c #008080",
			". c #555555",
			"# c #000000",
			"a c #000000",
			"b c #000000",
			"c c #000000",
			"d c #000000",
			"e c #000000",
			/* pixels */
			"````````````````",
			"````````````````",
			"````````````````",
			"````````.```````",
			"```````..```````",
			"``````...```````",
			"`````....```````",
			"````.....```````",
			"`````....```````",
			"``````...```````",
			"```````..```````",
			"````````.```````",
			"````````````````",
			"````````````````",
			"````````````````",
			"````````````````"
	};

	/* XPM */
	static char *x_button_hilite_xpm[] = {
		/* width height num_colors chars_per_pixel */
		"    16    16        8            1",
			/* colors */
			"` c #008080",
			". c #4766e0",
			"# c #c9dafb",
			"a c #000000",
			"b c #000000",
			"c c #000000",
			"d c #000000",
			"e c #000000",
			/* pixels */
			"````````````````",
			"`..............`",
			"`.############.`",
			"`.############.`",
			"`.##aa####aa##.`",
			"`.###aa##aa###.`",
			"`.####aaaa####.`",
			"`.#####aa#####.`",
			"`.####aaaa####.`",
			"`.###aa##aa###.`",
			"`.##aa####aa##.`",
			"`.############.`",
			"`.############.`",
			"`..............`",
			"````````````````",
			"````````````````"
	};

	/* XPM */
	static char *x_button_xpm[] = {
		/* width height num_colors chars_per_pixel */
		"    16    16        8            1",
			/* colors */
			"` c #008080",
			". c #555555",
			"# c #000000",
			"a c #000000",
			"b c #000000",
			"c c #000000",
			"d c #000000",
			"e c #000000",
			/* pixels */
			"````````````````",
			"````````````````",
			"````````````````",
			"````````````````",
			"````..````..````",
			"`````..``..`````",
			"``````....``````",
			"```````..```````",
			"``````....``````",
			"`````..``..`````",
			"````..````..````",
			"````````````````",
			"````````````````",
			"````````````````",
			"````````````````",
			"````````````````"
	};

	/* XPM */
	static char *left_arrow_pressed_xpm[] = {
		/* width height num_colors chars_per_pixel */
		"    16    16        8            1",
			/* colors */
			"` c #008080",
			". c #4766e0",
			"# c #9e9ede",
			"a c #000000",
			"b c #000000",
			"c c #000000",
			"d c #000000",
			"e c #000000",
			/* pixels */
			"````````````````",
			"`..............`",
			"`.############.`",
			"`.############.`",
			"`.#######a####.`",
			"`.######aa####.`",
			"`.#####aaa####.`",
			"`.####aaaa####.`",
			"`.###aaaaa####.`",
			"`.####aaaa####.`",
			"`.#####aaa####.`",
			"`.######aa####.`",
			"`.#######a####.`",
			"`..............`",
			"````````````````",
			"````````````````"
	};

	/* XPM */
	static char *left_arrow_hilite_xpm[] = {
		/* width height num_colors chars_per_pixel */
		"    16    16        8            1",
			/* colors */
			"` c #008080",
			". c #4766e0",
			"# c #c9dafb",
			"a c #000000",
			"b c #000000",
			"c c #000000",
			"d c #000000",
			"e c #000000",
			/* pixels */
			"````````````````",
			"`..............`",
			"`.############.`",
			"`.######a#####.`",
			"`.#####aa#####.`",
			"`.####aaa#####.`",
			"`.###aaaa#####.`",
			"`.##aaaaa#####.`",
			"`.###aaaa#####.`",
			"`.####aaa#####.`",
			"`.#####aa#####.`",
			"`.######a#####.`",
			"`.############.`",
			"`..............`",
			"````````````````",
			"````````````````"
	};

	/* XPM */
	static char *right_arrow_disabled_xpm[] = {
		/* width height num_colors chars_per_pixel */
		"    16    16        8            1",
			/* colors */
			"` c #008080",
			". c #555555",
			"# c #000000",
			"a c #000000",
			"b c #000000",
			"c c #000000",
			"d c #000000",
			"e c #000000",
			/* pixels */
			"````````````````",
			"````````````````",
			"````````````````",
			"```````.````````",
			"```````..```````",
			"```````.`.``````",
			"```````.``.`````",
			"```````.```.````",
			"```````.``.`````",
			"```````.`.``````",
			"```````..```````",
			"```````.````````",
			"````````````````",
			"````````````````",
			"````````````````",
			"````````````````"
	};

	/* XPM */
	static char *right_arrow_hilite_xpm[] = {
		/* width height num_colors chars_per_pixel */
		"    16    16        8            1",
			/* colors */
			"` c #008080",
			". c #4766e0",
			"# c #c9dafb",
			"a c #000000",
			"b c #000000",
			"c c #000000",
			"d c #000000",
			"e c #000000",
			/* pixels */
			"````````````````",
			"`..............`",
			"`.############.`",
			"`.####a#######.`",
			"`.####aa######.`",
			"`.####aaa#####.`",
			"`.####aaaa####.`",
			"`.####aaaaa###.`",
			"`.####aaaa####.`",
			"`.####aaa#####.`",
			"`.####aa######.`",
			"`.####a#######.`",
			"`.############.`",
			"`..............`",
			"````````````````",
			"````````````````"
	};

	/* XPM */
	static char *right_arrow_pressed_xpm[] = {
		/* width height num_colors chars_per_pixel */
		"    16    16        8            1",
			/* colors */
			"` c #008080",
			". c #4766e0",
			"# c #9e9ede",
			"a c #000000",
			"b c #000000",
			"c c #000000",
			"d c #000000",
			"e c #000000",
			/* pixels */
			"````````````````",
			"`..............`",
			"`.############.`",
			"`.############.`",
			"`.#####a######.`",
			"`.#####aa#####.`",
			"`.#####aaa####.`",
			"`.#####aaaa###.`",
			"`.#####aaaaa##.`",
			"`.#####aaaa###.`",
			"`.#####aaa####.`",
			"`.#####aa#####.`",
			"`.#####a######.`",
			"`..............`",
			"````````````````",
			"````````````````"
	};


	/* XPM */
	static char *right_arrow_xpm[] = {
		/* width height num_colors chars_per_pixel */
		"    16    16        8            1",
			/* colors */
			"` c #008080",
			". c #555555",
			"# c #000000",
			"a c #000000",
			"b c #000000",
			"c c #000000",
			"d c #000000",
			"e c #000000",
			/* pixels */
			"````````````````",
			"````````````````",
			"````````````````",
			"```````.````````",
			"```````..```````",
			"```````...``````",
			"```````....`````",
			"```````.....````",
			"```````....`````",
			"```````...``````",
			"```````..```````",
			"```````.````````",
			"````````````````",
			"````````````````",
			"````````````````",
			"````````````````"
	};

	const int tab_x_size = 9;

	/* XPM */
	static char *tab_x_button_pressed_xpm[] = {
		/* width height num_colors chars_per_pixel */
		"     9     9        8            1",
			/* colors */
			"` c #4766e0",
			". c #9e9ede",
			"# c #555555",
			"a c #000000",
			"b c #000000",
			"c c #000000",
			"d c #000000",
			"e c #000000",
			/* pixels */
			"`````````",
			"`.......`",
			"`.......`",
			"`..#...#`",
			"`...#.#.`",
			"`....#..`",
			"`...#.#.`",
			"`..#...#`",
			"`````````"
	};

	/* XPM */
	static char *tab_x_button_xpm[] = {
		/* width height num_colors chars_per_pixel */
		"     9     9        8            1",
			/* colors */
			"` c #555555",
			". c #FFFFFF",
			"# c #000000",
			"a c #000000",
			"b c #000000",
			"c c #000000",
			"d c #000000",
			"e c #000000",
			/* pixels */
			"`````````",
			"`.......`",
			"`.`...`.`",
			"`..`.`..`",
			"`...`...`",
			"`..`.`..`",
			"`.`...`.`",
			"`.......`",
			"`````````"
	};

	/* XPM */
	static char *tab_x_button_hilite_xpm[] = {
		/* width height num_colors chars_per_pixel */
		"     9     9        8            1",
			/* colors */
			"` c #4766e0",
			". c #c9dafb",
			"# c #000000",
			"a c #000000",
			"b c #000000",
			"c c #000000",
			"d c #000000",
			"e c #000000",
			/* pixels */
			"`````````",
			"`.......`",
			"`.#...#.`",
			"`..#.#..`",
			"`...#...`",
			"`..#.#..`",
			"`.#...#.`",
			"`.......`",
			"`````````"
	};
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// End of XPM Images
//
//////////////////////////////////////////////////////////////////////////////////////////////////


#endif // WXFLATNOTEBOOKIMAGES_H
