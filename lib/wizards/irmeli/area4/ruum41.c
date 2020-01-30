inherit "room/room";  
object monster;

reset(arg) {
  if(!present("guard")) {
    move_object(clone_object("/wizards/irmeli/area4/guard3.c"),
    this_object());
}

if(arg) return;

  add_exit("west","/wizards/irmeli/area4/ruum42.c");

  add_exit("east","/wizards/irmeli/area4/ruum44.c");

  add_exit("up","/wizards/irmeli/area4/ruum48.c");

  add_exit("south","/wizards/irmeli/area4/ruum46.c");

  add_exit("down","/wizards/irmeli/area4/ruum34.c");

  set_not_out(1);



  short_desc = "Floor five inside the Orthanc, tower of death";

  long_desc = "A huge hall opens in front your amazed eyes. High halls and rooms makes this\n"+

                "tower look domestic and beatiful and paintings, which are hanging on the\n"+

                "wall is great addition. Light crowds in from the big window on the\n"+

                "northern wall. There is a large crack in the middle of window.\n";

}

