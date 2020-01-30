inherit "room/room";
object monster,monster2;



reset(arg) {
 if(!present("mummy")) {
    move_object(clone_object("/wizards/devil/area/mobit/mummy.c"), this_object());
    move_object(clone_object("/wizards/devil/area/mobit/mummy.c"), this_object());
}

  if(arg) return;

add_exit("stairs","/wizards/devil/area/huoneet/r53.c"); 
add_exit("east","/wizards/devil/area/huoneet/r51.c");

short_desc = "Under the huge temple";
long_desc = "You are now certain that you are right under the huge temple. There are\n"+
                "stairs on the western wall leading up to the temple. Small amount\n"+
                "light is coming from the top of the stairs.\n";

}
