inherit "room/room";
object wiz;
object drunkard;
object pianist;
reset(arg) {
    if (arg) return;
    add_exit("west","/wizards/siggy/area/unseen/uu6.c");
    add_exit("south","/wizards/siggy/area/unseen/uu4.c");
    add_exit("northwest","/wizards/siggy/area/unseen/uu8.c");
    set_not_out(3);
    short_desc = "The pub";
    long_desc = 
        "This is the bar of Unseen University. Most of the wizards visit the bar atleast\n"
        + "once a week. There is a wooden piano and the drunkards are usually singing\n"
        + "karaoke in here. They say that you can have the best beer 'Lappari' in the\n"
        + "world from here. But who would imagine wizards drinking all day long. It should\n"
        + "be deadly combination, alcohol and spells, argh!\n";

    if(!wiz) {
    wiz = clone_object("/wizards/siggy/area/unseen/wiz.c");
    move_object(wiz, this_object());
    }
    if(!drunkard) {
    drunkard = clone_object("/wizards/siggy/area/unseen/wizdrunk.c");
    move_object(drunkard, this_object());
    }
    if(!pianist) {
    pianist = clone_object("/wizards/siggy/area/unseen/pianist.c");
    move_object(pianist, this_object());
    }
  } 





